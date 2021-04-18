%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert position expressed in ECEF to WGS latitude longitude and altitude
%
% DESCRIPTION:
%   Converts postion expressed in  BCBF to WGS coordinates, accounting for
%   earth flatting.
%
%
% Inputs:
%   pos_BCBF: position in body centred body fixed frame [m]
%   f: flattening constat i.e. 1/298.257223563 [-]
%   r_body: equatorial radius of the body [m]
%   zero_tol: zero tolerance to use to check convergence of solution
%   maxitterations: maximum number of itterations to limit solution to.
%
% Outputs:
%   lat: latitude of position [rad]
%   lon: longitude of postion [rad]
%   alt: altitude [m]
%
% References:
%  Fundamentals of Astrodynamics,  Bate Mueller & White 1971
%  Orbital Coordinate Systems, Part III  T.S. Kelso,  https://celestrak.com/columns/v02n03/
%
% Modifications:
%   MA-18Jul16: inital draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ lat, lon, alt] = ter2wgs(pos_BCBF, f, r_body, zero_tol ,maxitterations)
  %#codegen
  
  % Break pos_BCBF into x y z components
  x = pos_BCBF(1);
  y = pos_BCBF(2);
  z = pos_BCBF(3);
  
  % Compute longitude from tan(lon)= y/x relationship
  lon = atan2(y,x);
  
  % Compute e^2 from f and length of vector in plane of longitude
  eccsq = 2 * f - f^2;
  R = sqrt(x^2 + y^2);
  
  % Intialize lat_i with reduced latitude
  lat_reduced =  atan2(z,R);
  lat_i_last = lat_reduced;
  
  % intialize loop
  lat_i = lat_i_last;
  sin_lat_i = sin(lat_i);
  C = 1 / (sqrt(1 - eccsq * sin_lat_i * sin_lat_i));
  for i= 1:1:maxitterations
    num = z + r_body * C .* eccsq * sin_lat_i;
    lat_i = atan2(num, R);
    check = abs(lat_i_last - lat_i);
    lat_i_last = lat_i;
    if all(check < zero_tol)
      % exit loop if tolerence met
      break
    end
    % prepare for next cycle
    lat_i = lat_i_last;
    sin_lat_i = sin(lat_i);
    C = 1 / (sqrt(1 - eccsq * sin_lat_i * sin_lat_i));
  end
  lat = lat_i_last;
  alt = R/cos(lat)- r_body * C; 
end

