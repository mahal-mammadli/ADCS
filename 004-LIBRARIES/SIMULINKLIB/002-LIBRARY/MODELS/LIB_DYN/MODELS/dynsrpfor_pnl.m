%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Solar Radiation Pressure Force on a Spacecraft Panel
%
% Description:
%   Computes the force created by solar radiation pressure on a plate.
%
% Inputs:
%   solar_flux    Solar flux at panel location in the BOF frame (W/m²)
%   SUNuvec_BOF   Unit vector from panel to Sun expressed in BOF frame
%   PNLuvec_BOF   Unit vector of the panel normal vector in BOF frame
%   eclipseflg_i  Flag to indicate whether or not the S/C is eclipsed
%                   	0: exposed to sun
%                   	1: eclipsed (umbra)
%                   	2: partially eclipsed (pen-umbra)
%   C_cst         Speed of light (m/s)
%   PNLarea       Area of the panel (m^2)
%   PNLcrdiffuse  Panel diffuse reflection coefficent (0 to 1)
%   PNLcrspecular Panel specular reflection coefficent (0 to 1)
%                 (Note: 1-(diffuse+specular) gives the absorbed coefficent)
%
% Outputs:
%   srpfor_BOF    Force due to Solar radiation pressure in BOF frame (N)
%
% References:
%   David A. Vallado, Fundamentals of Astrodynamics and Applications, 2nd ed.
%   Norrwall, MA, USA: Kluwer Academic Publishers, 2001,
%   Section 8.6.4.
%
%   J.A. Marshall, S.B. Luthcke, P.G. Atreasian and G.W. Rosborough
%   Modeling Radiation Forces Acting on TOPEX/Poseidon for Precision Orbit
%   Determination, NASA Techical Memorandum 104564  
%
% Modifications:
%   MA- 07Oct16 - intial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [srpfor_BOF] = dynsrpfor_pnl(solar_flux,      ...
    SUNuvec_BOF,     ...
    PNLuvec_BOF,     ...
    eclipseflg_i,    ...
    C,           ...
    PNLarea,         ...
    PNLcrdiffuse,    ...
    PNLcrspecular)
  %#codegen
  % Initialise output
  srpfor_BOF   = 0 .* SUNuvec_BOF;
  
  % Check if S/C is eclipsed
  if(eclipseflg_i == 0)
    % Compute solar radiation pressure from solar flux
    srp = solar_flux / C;
    
    % Ensure inputs are column vectors. r_hat is direction of source from panel.
    s_hat_BOF = SUNuvec_BOF(:);
    n_hat_BOF = PNLuvec_BOF(:);
    
    % Compute cos_inc = dot(s_hat, n_hat) and check if S/C is eclipsed
    if (srp > 0)
      cos_inc = dot(s_hat_BOF, n_hat_BOF);
    else
      cos_inc = 0.0;
    end
    
    % Apply pressure on panel if exposed to the sun (i.e. -90deg <= inc <= 90deg)
    if cos_inc > 0
      npart        = (2 * (PNLcrdiffuse / 3 + PNLcrspecular * cos_inc)) * n_hat_BOF;
      spart        = (1 - PNLcrspecular) * s_hat_BOF;
      sprfac       = -srp * PNLarea * cos_inc;
      srpfor_BOF   = sprfac * (npart + spart);
    end
  end
end
