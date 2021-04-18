%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Converts quaterion to axis angle representation
%
% Description:
%  Computes axis angle pair from a quaternion
%
% Inputs:
%  Aq_B: Quaternion representing rotation of frame B to frame A using
%  equations found in sec 7.5 of Kuipers
%
% Outputs
%  vec_B: vector expressing axis of rotation in frame B
%  theta: angle of rotation about vec B (rad)
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ vec_B, theta, fdi ] = q2aa( Aq_B , tol )
  %#codegen
  if nargin <2
    tol = 10e-9;
  end
  
  fdi=0;
  Aq_B_scalar = Aq_B(1);
  Aq_B_vector = Aq_B(2:4);
  
  % Check bounds of Aq_B_scalar  to ensure acos works
  if Aq_B_scalar > 1
    Aq_B_scalar = 1;
    fdi= 1;
  elseif Aq_B_scalar < -1
    Aq_B_scalar = -1;
    fdi= 1;
  end
  
  theta= 2* acos(Aq_B_scalar);
  sintheta = sin(theta/2);
  if abs(sintheta) < tol
    vec_B =[1;0;0];
  else
    vec_B = Aq_B_vector(:)/(sintheta);
    
  end
  
end

