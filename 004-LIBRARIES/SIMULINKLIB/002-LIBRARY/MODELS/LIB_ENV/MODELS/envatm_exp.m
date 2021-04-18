%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Density of Atmosphere at a Given Height
%
% Description:
%   Calculates the density of the atmosphere at a given location based on
%   an exponential model of the atmosphere. 
%
% Inputs:
%   pos_BCBF    position vector to calculate density for (m)
%   rho_ref     reference density at a given height (kg/m^3)
%   height_ref  reference distance from Earth center (m)
%   scale_ref   reference scale height with respect to BCBF frame origin (m) 
%
% Outputs:
%   density[1]        density at a given location (kg/m^3)
%
% References:
%   Vallado, Fundamentals of Astrodynamics and Applications, pages 535-537
%
% Modifications:
%   MA-28Sep16 Initial draft 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [density] = envatm_exp(pos_BCBF, rho_ref, height_ref,  scale_ref)
  %#codegen
  pos_norm = vecnorm(pos_BCBF);
  density  = rho_ref * exp( -(pos_norm - height_ref) / scale_ref);
  
end
