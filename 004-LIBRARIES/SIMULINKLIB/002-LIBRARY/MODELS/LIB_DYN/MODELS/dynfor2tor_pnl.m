%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Compute Generated Torque on Panel
%
% Description:
%   Computes torque generated by applying a force on a panel center of
%   pressure.
%
% Inputs:
%   for_BOF   force applied on panel (N)
%   com_BOF   spacecraft center of mass position in BOF (m)
%   cop_BOF   panel center of pressure position in BOF (m)
%
% Outputs:
%   tor_BOF   torque applied (N*m)
% 
%  References:
%   Physics 101 notes on Torques and forces
%
%  Modifications:
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [tor_BOF] = dynfor2tor_pnl(for_BOF, com_BOF, cop_BOF)
  %#codegen

  % Compute body center of mass to center of pressure vector
  cop_relcom_BOF = cop_BOF - com_BOF;
  
  % Torque is generated by lever arm * force on application point
  tor_BOF = crossmat(cop_relcom_BOF)* for_BOF;
  
end