%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computation of gravity-gradient torques
%
% Description:
%   Computes gravity torque using a SC inertia matrix and point mass approximation of earth.
%
% Inputs:
%   pos_BOF        : Postion of celestial body in BOF frame (m)
%   mu_cst         : gravitational constant                 (m^3/s^2)
%   SCinertia_par  : spacecraft inertia  matrix             (Kg/m^2)
%
% Outputs:
%   grvtor_B       : torque due to gravity gradient         (Nm)
%
% References:
%  Fundamentals of Astrodynamics Bate Mueller & White
%  Spacecraft Attitude Dynamics Huges
%
% Modifications:
%   MA- 07Jul16 - intial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function grvtor_B   = envgrvtor(pos_BOF,  SCinertia_par, mu_cst)
  %#codegen
  
  pos_BOF_norm = vecnorm(pos_BOF);
%   pos_BOF_norm = pos_BOF(:)'*pos_BOF(:);
  pos_BOF_unit = pos_BOF ./ pos_BOF_norm;
    
  grvtor_B = 3 * mu_cst / (pos_BOF_norm * pos_BOF_norm * pos_BOF_norm) * crossmat(pos_BOF_unit) * SCinertia_par * pos_BOF_unit;
end