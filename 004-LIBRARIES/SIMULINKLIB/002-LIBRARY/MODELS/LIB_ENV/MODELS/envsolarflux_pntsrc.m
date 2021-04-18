%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Solar Flux at a Given Position in Space
%
% Description:
%   Computes solar flux using a point source approximation for the Sun
%   (inverse square law). This approximation is valid for positions
%    at least 5 Sun diameters away from the Sun.
%
% Inputs:
%   PNTpos_CEL      point to calculate the solar flux and Sun direction for expressed in CEL frame (m)
%   SUNpos_CEL      position in CEL frame (m)
%   solar_flux_ref  reference value to use for the average solar flux (W/m^2)
%   solar_dist_ref  distance used to calculate the reference value (m)
%   zero_tol        zero tolerence to use on norm (m)
%
% Outputs:
%   PNTsolar_flux       solar flux from the Sun at this point (W/m^2)
%   SUNuvec_relPNT_CEL  unit vector describing the direction between the satellite and the Sun in CEL frame
%   fditst              0 if no fault 1 if position of sun and point is cooincident          
%
% References:
%   A. Ryer, The Light Measurement Handbook, 2nd printing ed.,
%   Newburyport, MA, International Light, 1998, p.26.
%
% Modifications:
%   MA- 07Oct16 - intial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [...
    PNTsolar_flux, ...
    SUNuvec_relPNT_CEL,...
    fditst] = envsolarflux_pntsrc(PNTpos_CEL, ... 
                                             SUNpos_CEL, ...
                                             solar_flux_ref,...
                                             solar_dist_ref, ... 
                                             zero_tol)
  %#codegen
  fditst = 0; 
  % Compute current distance / direction to Sun at PNT
  SUN_relPNT_CEL      = SUNpos_CEL - PNTpos_CEL;
  SUN_relPNT_CEL_norm = vecnorm(SUN_relPNT_CEL);
  if (SUN_relPNT_CEL_norm < zero_tol)
    fditst              = 1;
    SUNuvec_relPNT_CEL = [0; 0; 0];
    PNTsolar_flux       = 0; 
  else
    SUNuvec_relPNT_CEL = SUN_relPNT_CEL / SUN_relPNT_CEL_norm;
    % Use inverse square law to calculate flux at PNT
    PNTsolar_flux = (solar_flux_ref * solar_dist_ref^2) / SUN_relPNT_CEL_norm^2;
  end
end


