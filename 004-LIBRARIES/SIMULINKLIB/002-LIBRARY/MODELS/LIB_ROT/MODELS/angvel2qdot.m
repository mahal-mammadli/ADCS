%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute quaternion deriviative from angular velocity
%
% Description:
%   Compute quaternion derivative.
%
% Inputs:
%   Aw_relB_A  Angular velocity of frame A, relative to B, expressed in
%              A (rad/s).
%   Aq_B       Current attitude of A relative to B in quaternion.
%
% Outputs:
%   Aq_B_dot   Quaternion derivative of frame A in frame B.
%
% References:
%   GEI720 Course Notes chapter 5 eq 4-55 and 4-56
%   Spacecraft Attitude Dynamics P. C. Hughes, 2004 pg 31
%
% Modifications:
%   MA-06Jul16: first draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function Aq_B_dot = angvel2qdot(Aw_relB_A, Aq_B)
  %#codegen

  % Separate the quaternion
  q_vector = Aq_B(2:4);
  q_vector = q_vector(:);
  q_scalar = Aq_B(1);
  
  % Construct the Q matrix
  Q = 0.5*[-q_vector'; (q_scalar * eye(3)) + crossmat(q_vector)];
  
  Aq_B_dot = Q * Aw_relB_A(:);
end
