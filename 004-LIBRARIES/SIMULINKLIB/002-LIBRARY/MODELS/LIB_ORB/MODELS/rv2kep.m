%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert Inertial Position and Velocity to Equinoctial Orbital Elements
%
% DESCRIPTION:
%   Transformation from Cartesian position, velocity inertial variables to
%   equinoctial orbital elements.
%
% INPUTS:
%   pos_BCI(3)  Position in Body Centerered Inertial frame (m) (typically ECI could be moon could be some planet)
%   vel_BCI(3)  Velocity in Body Centerered Inertial frame (m/s)(typically ECI)
%   mu_cst      Standard gravitational parameter of the primary body (m^3*s-2) (3.9860e+014 m^3*s-2 for Earth)
%   zero_tol    Zero tolerance                                       (-)
%
% OUTPUTS:
%   sma         Semi-major axis                              [m]
%   ecc         eccentricity of orbit        (-)
%   incl        Inclination                                  (rad)
%   raan        Right-ascension of the ascending node        (rad)
%   argp        Argument of periapis                         (rad)
%   tano        true anonmoly                                (rad)
%   fdi_hmod_i  Mathematical exception due to hmod = 0        (1/0)
%   fdi_rmod_i  Mathematical exception due to rmod = 0        (1/0)
%   fdi_raan_i  Mathematical exception in computation of RAAN (1/0)
%   fdi_alat_i  Mathematical exception in computation of alat (1/0)
%   fdi_mu_i    Mathematical exception due to invalid mu_cst  (1/0)
%   fdi_sma_i   Mathematical exception in compuattion of sma  (1/0)
%
% REFERENCES:
%  Fundamentals of Astrodynamics,  Bate Mueller & White 1971
%
% UPDATES:
%   MA-06Jul16
%   MM-27Jan21
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [sma, ecc, incl, raan, argp, tano, alat,    ...
    fdi_hnorm, fdi_rnorm, fdi_raan,   ...
    fdi_alat, fdi_mu,   fdi_sma]        ...
    = rv2kep(SCpos_BCI, SCvel_BCI, mu_cst, zero_tol)
  %#codegen
  
  fdi_rnorm = 0;
  fdi_hnorm = 0;
  fdi_raan = 0;
  fdi_alat = 0;
  fdi_mu   = 0;
  fdi_sma  = 0;
  
  
  %% find vectors describing the orbit to BCI frame
  h_BCI = cross(SCpos_BCI(:), SCvel_BCI(:));
  N_BCI = cross([0 ; 0 ;1], h_BCI(:));
  
  %% Check inputs/vectors for mathmatical exceptions
  [SCposuvec_BCI] = vecunit(SCpos_BCI,  zero_tol);
  SCpos_norm                 = vecnorm(SCpos_BCI,zero_tol);
  %[h_norm, fdi_hnorm]        = vecnorm(h_BCI,      zero_tol);
  h_norm                     = vecnorm(h_BCI,      zero_tol);
  %[N_norm, fdi_raan]        = vecnorm(N_BCI,      zero_tol);
  N_norm                     = vecnorm(N_BCI,      zero_tol);
  
  
  %% Solve for ecc eq 1.5-10
  if abs(mu_cst)< zero_tol
    fdi_mu =1;
    ecc   = 0;
    e_BCI = [0;0;1];
  else
    e_BCI = (cross(SCvel_BCI(:), h_BCI(:)) / mu_cst) - SCposuvec_BCI;
    ecc = vecnorm(e_BCI, zero_tol);
  end
  %% Use semi-latus rectum to solve for semi-major axis rearange 1.5-6
  slr = h_norm^2/mu_cst;
  if (1-ecc^2) < zero_tol
    sma       = 0;
    fdi_sma   = 1;
  else
    sma = slr/(1-ecc^2);
  end
  %% Solve for incl eqn 2.4-7
  if abs(h_norm) < zero_tol
    incl = 0; 
  else
    incl = acos(h_BCI(3)/h_norm);
  end
  %% Solve for raan eqn 2.4-8
  if abs(N_norm) < zero_tol
    raan = 0;
  else
    raan = acos(N_BCI(1)/N_norm);
    if N_BCI(2)<0
      raan = 2 * pi - raan;
    end
  end
  %% solve for argp 2.4-9
  if (abs(N_norm) < zero_tol) || (abs(ecc) < zero_tol)
    argp = 0;
  else
    argp = acos((N_BCI(:)'* e_BCI(:)) / (N_norm * ecc));
    if e_BCI(3) < 0
      argp = 2 * pi -argp;
    end
  end
  %% solve for tano 2.4-10
  if (abs(N_norm) < zero_tol) || (abs(ecc) < zero_tol)
    tano =0;
  else
    tano = acos((e_BCI(:)' * SCpos_BCI) / (ecc * SCpos_norm));
    if ((SCpos_BCI(:)' * SCvel_BCI) < 0)
      tano= 2*pi-tano;
    end
  end
  
  %% Solve for argument of latitude 2.4-11
  if (N_norm < zero_tol) || (abs(SCpos_norm) < zero_tol)
    alat = 0; 
    fdi_alat =1;
  else
    alat = acos((N_BCI(:)' * SCpos_BCI) / (N_norm * SCpos_norm));
    if SCpos_BCI(3) < 0
      alat = 2 * pi - alat;
    end
  end
end