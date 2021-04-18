%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert position expressed in WGS latitude longitude and altitude to ECEF 
% 
% DESCRIPTION:
%   Converts postion expressed in WGS to BCBF coordinates, accounting for
%   earth flatting. 
%
% 
% Inputs:
%   lat: latitude of position [rad]
%   lon: longitude of postion [rad] 
%   alt: altitude [m]
%   f: flattening constat i.e. 1/298.257223563 [-]
%   r_body: equatorial radius of the body [m]
%
% Outputs:
%  pos_BCBF: position in body centred body fixed frame [m]
%
% References:
%  Fundamentals of Astrodynamics,  Bate Mueller & White 1971
%
% Modifications:
%   MA-18Jul16: inital draft
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ pos_BCBF ] = wgs2ter(lat, lon, alt,  f, r_body)
  
  % ensure everything is in columm format
  lat_geo = lat(:);
  lon_geo = lon(:);
  alt_geo = alt(:);
  
  % compute e from f
  eccsq = 2*f-f^2;
  
  % eqn 2.8-7 from BMW
  slat_geo = sin(lat_geo);
  clat_geo = cos(lat_geo);
  denom = sqrt(1 - eccsq .* slat_geo .* slat_geo);
  x = (            r_body ./ denom + alt_geo).* clat_geo;
  z = ((1-eccsq) * r_body ./ denom + alt_geo).* slat_geo;
  % eqn 2.8-8
  pos_BCBF = [x.*cos(lon_geo), x.*sin(lon_geo),z];
end

