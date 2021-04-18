%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Converts axis angle to quaterion representation
%
% Description:
%  Computes quaternion from a axis angle pair
%
% Inputs:
%  vec_B: vector expressing axis of rotation in frame B
%  theta: angle of rotation about vec B (rad)
%
% Outputs
%  Aq_B: Quaternion representing rotation of frame B to frame A using
%  equations found in sec 7.5 of Kuipers
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ Aq_B ] = aa2q( vec_B, theta )
  %#codegen
  Aq_Bscalar = cos(theta./2);
  
  Aq_Bvector = vec_B .* (sin(theta./2));
   
  Aq_B = [Aq_Bscalar; Aq_Bvector(:)];
end

