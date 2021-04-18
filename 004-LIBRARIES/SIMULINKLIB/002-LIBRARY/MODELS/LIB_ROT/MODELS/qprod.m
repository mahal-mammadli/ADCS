%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computes the product of two quaternions
%
% Description:
%  This function computes the resulting quaternion product for two
%  quaternions i.e. Aq_C = Aq_B x Bq_C, this follows equation 5.3 in the
%  reference.
%
% Inputs:
%  Aq_B: Quaternion representing rotation of frame B to frame A
%  Bq_C: Quaternion representing rotation of frame C to frame B
%
% Outputs
%  Aq_C: Quaternion representing rotation of frame C to frame A
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ Aq_C ] = qprod(Aq_B, Bq_C )
  %#codegen
  % Break out scalar and vector components
  % (done this way if there is a need to support different quaternion
  % orderings in the future)
  p_scalar = Aq_B(1);
  P_vector = Aq_B(2:4);
  q_scalar = Bq_C(1);
  q_vector = Bq_C(2:4);
  
    % eq 7.4 (matrix notation) r = qp to match nomencalture rules 
    p_mat = [p_scalar,    -P_vector(1), -P_vector(2), -P_vector(3);
             P_vector(1),  p_scalar,     P_vector(3), -P_vector(2);
             P_vector(2), -P_vector(3),  p_scalar,     P_vector(1);
             P_vector(3),  P_vector(2), -P_vector(1),  p_scalar];
    q = [q_scalar;q_vector(:)];
    r = p_mat * q;
    % Preserve vector size from first input
  
    Aq_C = zeros (size(Aq_B));
    Aq_C(1)= r(1);
    Aq_C(2)= r(2);
    Aq_C(3)= r(3);
    Aq_C(4)= r(4);
    
end

