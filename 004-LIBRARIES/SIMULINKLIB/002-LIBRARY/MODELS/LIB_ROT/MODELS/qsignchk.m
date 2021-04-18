%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Ensures quaterion has a positive scalar component. 
%
% Description:
%  This function checks if the quaternion has a positive scalar component
%  and returns the positive equivalent quaternion if it is not. 
%
% Inputs:
%  q_in: input quaternion
%
% Outputs
%  q_out: output quaternion; 
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [q_out] = qsignchk(q_in)
  %#codegen
  q_scalar = q_in(1);
  
  if (q_scalar < 0)
    q_out = -q_in;
  else
    q_out = q_in;
  end
  
end

