%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Rotates a vector by the rotation defined by a quaternion
%
% Discription:
%  This function rotates a vector by the supplied rotation described by
%  Aq_B i.e. vec_A = Aq_B x vec_B.
%  this function follows the reuslt shown in section 5.8 of Kuiperss 1999.
%
% Inputs
% Aq_B: quaternion representing the rotation from frame B to frame A
% vec_B: vector expressed in frame B
%
% Outputs
% vec_A vector expressed in frame A
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [vec_A] = qvecprod(Aq_B, vec_B )
  %#codegen
  % Break out scalar and vector components
  % (done this way if there is a need to support different quaternion orderings)
  q_scalar = Aq_B(1);
  q_vector = Aq_B(2:4);
  q = [q_scalar;q_vector(:)];
  v = [0;vec_B(:)];
  
  % eq 5.5 (rotating a vector by q)
  w = qprod(qprod(q,v),qtrans(q));
  
  % Preserve vector size from first input
  vec_A = zeros (size(vec_B));
  vec_A(1)= w(2);
  vec_A(2)= w(3);
  vec_A(3)= w(4);
  
end

