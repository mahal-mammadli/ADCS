%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computes DCM describig a rotation about the z axis of theta 
%
% Description:
%  This function computes the DCM of a rotation about the z axis of the A
%  frame(one without prime in figure 2.15 of reference).
%
% Inputs: 
%  theta: angle of rotation about axis (rad)
%
% Outputs 
%  B_A: DCM describing rotation about x axis of frame A, also represents
%  the relationship between frame A and frame B i.e. vec_B = B_A *vec_A;
%
% References:
%  Spacecraft Attitude Dynamics Peter Hughes 2004
%
% Modifications:
%  MA-22Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [B_A] = dcm_rot3(theta)
  %#codegen
  s = sin(theta);
  c = cos(theta);
  B_A = [ c,  s,  0;
         -s,  c,  0;
          0,  0,  1];

end

