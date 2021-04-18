%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Read Gravitational Spherical Harmonics Coefficents from EGM96 File
%
% Description:
%   Reads the gravitational coefficients contained in a EGM96 file.
%   Reverses coefficients normalization from data.
%
% Inputs:
%   filename    The file to read coefficients from 
%               (ex: 'egm96_to360.ascii')
%
% Outputs:
%   Cnm         Table of non-normalized zonal coefficents [degree, order]
%   Snm         Table of non-normalized sectorial coefficents [degree, order]
%
% Modifications:
%  MA- 18Jul16
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Cnm, Snm] = readgrvcoeff_EGM96(filename)
  [fid, err] = fopen(filename, 'r');
  if ( fid == -1 )
    disp(err);
  end

  % Data is stored in file as:
  % [Degree Order, Cnm_norm, Snm_norm, Cnm_stdev, Snm_stdev]
  A = fscanf(fid, '%g %g %g %g %g %g');
  fclose(fid);

 %find the number of lines in the file and extract n, m, Cnm, Snm from each line.
  nlines = length(A)/6;

  % Set Cnm and Snm to zeros (degree and order of MaxDegree)
  max_deg = max(A(1:6:end));
  Snm = zeros(max_deg+1, max_deg+1);
  Cnm = zeros(max_deg+1, max_deg+1);

  for i = 1:nlines,
    ioff = (i-1)*6;
    n = A(ioff+1);
    m = A(ioff+2);

    if m == 0
      k = 1;
    else
      k = 2;
    end
    norm_fac = sqrt(factorial(n + m) / (factorial(n - m) * k * (2 * n + 1)));

    Cnm(n+1,m+1) = (A(ioff+3))/norm_fac;
    Snm(n+1,m+1) = (A(ioff+4))/norm_fac;
  end
  [r,c] = find(~(isnan(Snm)|Snm==0));
  Cnm   = Cnm(1:max(r), 1:max(c));
  Snm   = Snm(1:max(r), 1:max(c));
end

