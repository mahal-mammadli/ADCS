%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Gravitational Perturbations using a Spherical Harmonics Model
%
% Description:
%   Calculates the non-spherical portion of gravitational acceleration
%   from a non-spherical body. Notes:
%   1) Function currently can only handle an order and degree of 40x40 due
%      to numerical stability issues.
%   2) Use readgrvcoeff_EGM96 and "egm96_to360.ascii" to generate Cnm
%      and Snm coefficients for Earth.
%   3) Use readgrvcoeff_PDS and a ".tab" file to generate Cnm and Snm
%      coefficents for planet gravity models managed by JPL's PDS service
%      found at: "http://naif.jpl.nasa.gov/naif/data.html".
%
% Inputs:
%   pos_BCBF[3]       position of the spacecraft in the body fixed frame (m)
%   mu_cst[1]         body's Gravitational constant used to generate Cnm
%                     and Snm data (m³/s²)
%   re_cst[1]         mean radius associated with Cnm and Snm data
%   maxDegree[1]      maximum spherical degree to use
%                     (must not exceed size of Cnm and Snm and is fixed to
%                     be < 40 for Simulink/numerical reasons)) [-]
%   maxOrder[1]       maximum spherical order to use
%                     must not exceed size of Cnm and Snm and is fixed to
%                     be < 40 for Simulink/numerical reasons) [-]
%   Cnm[40, 40](max)  non normalized spherical harmonic data
%                     (Zonal components)
%   Snm[40, 40](max)  non normalized spherical harmonic data
%                     (Tesseral/Sectorial components)
%
% Outputs:
%   grvpert_BCBF[3]   perturbations from spherical model expressed in body
%                     centered body fixed frame (m/s²)
%
% Reference:
%   Carlos M. Roithmayr, "Contributions of Spherical Harmonics to Magnetic
%   and Gravitational Fields, " NASA Langley Research Center, Hampton,
%   Virginia, Technical Memorandum NASA/TM-2004-213007, 2004.
%
% Modifications:
%   MA-18Jul16- initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [grvpert_BCBF] = envgrvpert_spharm(pos_BCBF,   ...
    mu_cst,     ...
    re_cst,     ...
    maxDegree,  ...
    maxOrder,   ...
    Cnm,        ...
    Snm)
  
  %#codegen
  
  % Pre-allocate variables to allow eml to properly build this function
  grvpert_BCBF = zeros(size(pos_BCBF));
  % Cnm Snm values start to produce Nans without an approximate method to de-normalize them
  assert(maxDegree <= 40)
  % This implementation run out of numerical precision to calculate beyond 45 x 45
  assert(maxOrder <= maxDegree)
  
  % Procedure
  % Get elements of position vector (in case user passes something weird in)
  rx_BCBF = pos_BCBF(1);
  ry_BCBF = pos_BCBF(2);
  rz_BCBF = pos_BCBF(3);
  
  % Determining geocentric Lat and Lon from pos vector
  rnorm = sqrt(rx_BCBF*rx_BCBF + ry_BCBF*ry_BCBF + rz_BCBF*rz_BCBF);
  
  % Rebuild unit vector to ensure its always a column vector
  rUnit = [rx_BCBF; ry_BCBF; rz_BCBF]/rnorm;
  slat  = (rz_BCBF/rnorm);
  
  % Solve for Anm, Sm and Cm tables
  Anm      = derivedLegend(maxDegree, slat);
  [Sm, Cm] = recursiveCmSm(maxDegree, rx_BCBF, ry_BCBF);
  
  % Pre-allocate/calculate re_cst^n
  % a = zeros(maxDegree+3, 1);
  a   = zeros(43, 1); % Hardcoding value to work with Simulink 2008b
  a(1)= 1;
  a(2)= re_cst;
  for i = 3:1:maxDegree+3
    a(i) = a(i-1)*re_cst;
  end
  
  % Pre-allocate/calculate rnorm^n
  % R=zeros(maxDegree+maxDegree+2, 1);
  R   = zeros(82, 1); % Hardcoding value to work with Simulink 2008b
  R(1)= 1;
  R(2)= rnorm;
  for i = 3:1:maxDegree + maxDegree + 2
    R(i) = R(i-1)*rnorm;
  end
  
  % Pre allocating memory for components of gravity field
  % e1 = zeros(maxDegree+1);
  % e2 = zeros(maxDegree+1);
  % e3 = zeros(maxDegree+1);
  % r0 = zeros(maxDegree+1);
  e1 = zeros(41); % Hardcoding value to work with Simulink 2008b
  e2 = zeros(41);
  e3 = zeros(41);
  r0 = zeros(41);
  
  % Compute grvpert_BCBF using Legendre polynomials
  for n = 1:1:maxDegree
    n_end=min(n, maxOrder);
    for m = 0:1:n_end
      factor =  mu_cst * a((n)+1) / R( (n+m+1)+1 );    % Add + 1 for the tables as they originally assumed zero addressing in C-code
      
      if m == 0
        e1(n+1, m+1) = 0.0;
        e2(n+1, m+1) = 0.0;
      else
        e1(n+1, m+1) =  factor*m*Anm(n+1, m+1)*( Cnm(n+1, m+1)*Cm(m) + Snm(n+1, m+1)*Sm(m) );
        e2(n+1, m+1) =  factor*m*Anm(n+1, m+1)*( Snm(n+1, m+1)*Cm(m) - Cnm(n+1, m+1)*Sm(m) );
      end
      
      factor       =   factor/rnorm*( Cnm(n+1, m+1)*Cm(m+1) + Snm(n+1, m+1)*Sm(m+1) );
      e3(n+1, m+1) =   factor*Anm(n+1, m+2);
      r0(n+1, m+1) =  -factor*( slat*Anm(n+1, m+2)  + (n+m+1)*Anm(n+1, m+1) );
      
      % Sum the magnetic field components together here
      grvpert_BCBF(1) = grvpert_BCBF(1) + e1(n+1, m+1) + r0(n+1, m+1) * rUnit(1);
      grvpert_BCBF(2) = grvpert_BCBF(2) + e2(n+1, m+1) + r0(n+1, m+1) * rUnit(2);
      grvpert_BCBF(3) = grvpert_BCBF(3) + e3(n+1, m+1) + r0(n+1, m+1) * rUnit(3);
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% derivedLegend
% Build  Derived Legendre polynomials (Anm) as per Ref document
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Anm] = derivedLegend(nmax,  x)
  
  %Anm      = zeros(nmax+2);% provide padding for m+1 operation (or m+2 if in matlab)
  % Hardcoding value to work with Simulink 2008b
  Anm       = zeros(42);
  Anm(1, 1) = 1;
  Anm(1, 1) = 1;
  
  %/*---------------- Seed values ------------------*/
  Anm(1, 1) = 1.0;
  Anm(2, 2) = 1.0;
  for i=1:1:nmax
    Anm(i+1, i+1) = (2*i-1) *  Anm(i, i);
  end
  
  %/*--------- Calculate based on x ----------------*/
  Anm(2, 1) = x;
  for i = 2:1:nmax
    for j = 0:1:i-1
      Anm(i+1, j+1) = ( (2*i-1)*x*Anm(i, j+1) - (i+j-1)*Anm(i-1, j+1) ) / (i-j);
    end
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% recursiveCmSm
% Calculate Sm and Cm arguments as defined in ref document
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Sm, Cm] = recursiveCmSm(maxOrder, rx_BCBF, ry_BCBF)
  % Sm = zeros(maxOrder+1, 1);
  % Cm = zeros(maxOrder+1, 1);
  % Hardcoding value to work with Simulink 2008b
  Sm = zeros(42, 1);
  Cm = zeros(42, 1);
  
  Sm(1) = 0;
  Cm(1) = 1;
  
  Sm(2) = ry_BCBF;
  Cm(2) = rx_BCBF;
  
  for i = 3:1:maxOrder+1
    Sm(i) = Sm(2)*Cm(i-1) + Cm(2)*Sm(i-1);
    Cm(i) = Cm(2)*Cm(i-1) - Sm(2)*Sm(i-1);
  end
end
