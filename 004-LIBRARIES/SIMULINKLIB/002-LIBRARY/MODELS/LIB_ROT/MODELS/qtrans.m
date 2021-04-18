%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computes the conjugate of a quaternion (similar to transpose of DCM)
%
% Description:
%  This function computes the conjugate of a quaternion using method
%  outlined in section 5.5. of Kuipers 1999
%
% Inputs:
%  Aq_B: Quaternion representing rotation of frame B to frame A
%
% Outputs
%  Bq_A: Quaternion representing rotation of frame A to frame B
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ Bq_A ] = qtrans(Aq_B)
  %#codegen
  % Break out scalar and vector components
  % (done this way if there is a need to support different quaternion orderings)
  q_scalar = Aq_B(1);
  q_vector = Aq_B(2:4);
  
  % From section 5.5
  q_trans =[q_scalar; -q_vector(:)];
  
  % Preserve vector size from first input
  Bq_A = zeros (size(Aq_B));
  Bq_A(1)= q_trans(1);
  Bq_A(2)= q_trans(2);
  Bq_A(3)= q_trans(3);
  Bq_A(4)= q_trans(4);
  
end

