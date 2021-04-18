%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Read Magnetic Field Spherical Harmonics Coefficients from IRGF or WMM
% Models
%
% Description:
%   Reads in Magnetic coefficients from  IRGF**.COF/WMM****.COF files and
%   calculates Hdot/Gdot parameters. Invalid output for start date prior to
%   the last data set in the file e.g. simulating something in the past.
%   Data is padded so the value of G_2_2 is the value found in position (3, 3)
%   of the Gnm array (MATLAB base 0 array addressing vs. C 0 based addressing)
%   The data is usually provided by http://www.ngdc.noaa.gov/IAGA/vmod/igrf.html
%
% Inputs:
%   filename[string]  the file to read coefficients from
%   min_date[1]  minimum date to be used in the simulation (common era years)
%
% Outputs:
%   Gnm[14,14]    zonal harmonic coefficients at a given basedate
%   Hnm[14,14]    sectorial/tesseral harmonic coefficients at a given basedate
%   GnmDot[14,14] rate of change of zonal harmonic coefficients per year
%   HnmDot[14,14] rate of change of sectorial/tesseral harmonic coefficients per year
%   basedate[1]   date for which Gnm and Hnm are most valid for should be <= min_date (years)
%
% Modifications:
%  MA- 04Aug16: modified to use newer file format found on igrf website
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Gnm, Hnm, GnmDot, HnmDot, basedate] = readIGRF12coeff(filename, min_date)
 
  % open file
  fid = fopen(filename, 'r');
  %% read in 4 lines of header material
  textlines  = textscan(fid,'%s',4,'delimiter','\n');
  headertext = [textlines{1}{1},textlines{1}{2}];
  maxdegree= 13;
  %% read in type and start of valid year
  
  temp = textscan(textlines{1}{3}, '%s');
  temp = temp{1};
  for i=4:1:numel(temp)
    model(i-3).type = temp{i};
  end
  temp = textscan(textlines{1}{4}, '%s');
  temp = temp{1};
  for i=4:1:numel(temp)
    year = str2num(temp{i});
    model(i-3).year = year;
    valid_years_start(i-3) =  year;
    if strcmp(model(i-3).type,'SV' )
      model(i-3).year =model(i-4).year+5;
      valid_years_start(i-3) = model(i-4).year+5;
    end
    
    model(i-3).Gnm = zeros(maxdegree+1);
    model(i-3).Hnm = zeros(maxdegree+1);
  end
  
  %% Read in coefficents from file
  dataarray=textscan(fid,'%s','delimiter','\n');
  fclose(fid);
  for linenum=1:1:numel(dataarray{1})
    line = [dataarray{1}{linenum}];
    
    % read in g/h deg and order
    temparray = textscan(line(1:8),'%s %f %f', 1);
    varname = temparray{1};
    m = temparray{2};
    n = temparray{3};
    
    % read in numerical values
    temparray = textscan(line(9:end),'%f');
    if numel(model)~=numel(temparray{1})
      error('readIGRF12coeffs:incorrectformat','number of  entries does not match number of parameters found ')
    end
    for i=1:1:numel(temparray{1})
      if strcmp(varname,'g')
        model(i).Gnm(m+1,n+1) = temparray{1}(i);
      else
        model(i).Hnm(m+1,n+1) = temparray{1}(i);
      end
      
    end
  end
  
  %% Select proper data set and calculate  GnmDot, HnmDot if necessary
  if min_date >= valid_years_start(end-1)
    
    % Minimum date is later than last data set in file
    % Use the published SV data for GnmDot/HnmDot
    %   maxindx  = max_deg(end) + 1;
    basedate = valid_years_start(end-1);
    Gnm      = model(end-1).Gnm;
    Hnm      = model(end-1).Hnm;
    GnmDot   = model(end).Gnm;
    HnmDot   = model(end).Hnm;
    
  elseif(min_date >= valid_years_start(1))
    % Two sets of data exist somewhere in this file that can be interpolated
    % Determine GnmDot/HnmDot using linear interpolation between two date ranges
    
    % Get total number of data sets
    num_models = numel(model);
    
    % Determine which date sets to use for interpolation
    for i = 1:1:num_models
      if (min_date < valid_years_start(i))
        idx1 = i-1;
        idx2 = i;
        break;
      end
    end
    
    % Set outputs based on idx found
    %   maxindx  = max_deg(idx1) + 1;
    basedate = valid_years_start(idx1);
    Gnm      = model(idx1).Gnm;
    Hnm      = model(idx1).Hnm;
    
    % Calculate GnmDot and HnmDot
    deltaT   = (valid_years_start(idx2) - valid_years_start(idx1));
    GnmDot   = (model(idx2).Gnm - model(idx1).Gnm) / deltaT;
    HnmDot   = (model(idx2).Hnm - model(idx1).Hnm) / deltaT;
    
  else
    % Date requested is not in the file and data cannot be interpolated
    % Maybe extrapolate in reverse in the future but this requires investigation
    error('LIB_ENV:readmagcoeff', '!! Data file :"%s" !!\n!! does not contain valid data for the time period starting at year %f!!', filename, min_date);
  end
  
end