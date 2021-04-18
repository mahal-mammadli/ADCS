%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute accleration due to gravity using a point mass approximation
%
% Description:
%   Calculates the gravitational acceleration caused by a point mass at a
%   given location.
%
% Inputs:
%  pos_BCBF:      position of the spacecraft in the body centred fixed frame (m)
%  mu_cst         body's gravitational parameter (m^3/s^2)
%
% Outputs:
%   acc_BCBF[3]   acceleration due to gravity expressed in body centered
%                 body fixed frame (m/s^2) 
%
% References:
%   David A. Vallado, Fundamentals of Astrodynamics and Applications,
%   2nd ed. Norrwall, MA, USA: Kluwer Academic Publishers, 2001, p.135.
%
% Modifications:
%  MA-06Jul16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ acc_BCBF ] = envgrv_pointmass( pos_BCBF, mu_cst )
  
  rnorm = vecnorm(pos_BCBF);
  
  % Acceleration due to gravity
  acc_BCBF = -mu_cst / (rnorm * rnorm * rnorm) * pos_BCBF;
end 

