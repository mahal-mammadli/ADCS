%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Orbital (ORB) Frame from Position and Velocity Vectors in BCI
%
% Description:
%  Computes Orbitial frame from position and velocity
%  The orbital frame is defined as:
%   ORB frame x-axis is the orbit radial unit vector)          
%   ORB frame y-axis is the orbit tangential unit vector)      
%   ORB frame z-axis is the orbit normal unit vector)          
%
% Inputs: 
%  pos_BCI: position expressed in a Body Centered Inertial frame  [m]
%  vel_BCI: velocity expressed in a Body Centered Inertial frame [m/s]
%
% Outputs:
%  ORB_BCI: rotation matrix relating frame in BCI to ORB 
%  fdi_pos:  fdi indicating norm of pos_BCI is less than zero tolerance 
%  fdi_vel:  fdi indicating norm of pos_BCI is less than zero tolerance 
%
% References:
%   Bate, Mueller & White, Fundamentals of Astrodynamics
%
% Modifications
%   MA-07Jul16 inital draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ORB_BCI, fdi_pos, fdi_vel] = rv2orb(pos_BCI, vel_BCI, zero_tol)
  %#codegen
  
  % from definition
  [ORBx_BCI] = vecunit(pos_BCI(:), zero_tol);
  
  % Compute orbit normal i.e. same direction as orbit angular momentum
  [vel_BCI_unit] = vecunit(vel_BCI(:), zero_tol);
  ORBz_BCI = cross(ORBx_BCI(:), vel_BCI_unit(:));
  
  % use k x i= j identity to get last vector
  ORBy_BCI = cross(ORBz_BCI(:), ORBx_BCI(:));
  
  % assemble rotation matrix from unit vectors
  ORB_BCI = [ORBx_BCI';ORBy_BCI';ORBz_BCI'];
  
end

