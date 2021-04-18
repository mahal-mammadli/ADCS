%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Aerodynamic Drag Force on panel
%
% Description:
%   Computes the aerodynamic drag force acting on an panel based on its
%   drag coefficient.
%
% Inputs:
%   atmdensity   Atmospheric density (kg/m^3)
%   vrelatm_BOF  Spacecraft speed relative to atmosphere it is traveling
%                through expressed in BOF (m/s)
%   PNLuvec_BOF  Unit vector of the panel normal vector expressed in BOF
%   PNLarea      Area of the panel (m^2)
%   PNLcd        Panel coefficent of drag
%
% Outputs:
%   drgfor_BOF   Force due to aerodynamic drag in BOF (N)
%
% References:
%
%   J.A. Marshall, S.B. Luthcke, P.G. Atreasian and G.W. Rosborough
%   Modeling Radiation Forces Acting on TOPEX/Poseidon for Precision Orbit
%   Determination, NASA Techical Memorandum 104564
%
% Modifications:
%   MA-28Sep16: intial draft.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function drgfor_BOF = dyndrgfor_pnl(atmdensity,         ...
                                    ATMvel_relBOF_BOF,  ...
                                    PNLuvec_BOF,        ...
                                    PNLarea,            ...
                                    PNLcd)
  
  %#codegen
  drgfor_BOF  = [0;0;0];
  
  % Compute projection of atmosphere relative velocity on panel direction
  ATMvel_relPNLnorm = ATMvel_relBOF_BOF(:)'* PNLuvec_BOF(:);
  ATMvel_relBOF_uvec = vecunit(ATMvel_relBOF_BOF);
  % Compute drag factor: [-1/2 * rho * CD * area * vrel^2] if exposed.
  if ATMvel_relPNLnorm > 0.0
    drgfac     = -0.5* atmdensity * PNLcd * PNLarea * ATMvel_relPNLnorm^2;
    drgfor_BOF = drgfac * ATMvel_relBOF_uvec;
  end
end
