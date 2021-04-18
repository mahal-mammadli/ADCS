%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert ORB_BCI to QRB_BCI
%
% Description:
%   Performs the conversion of rotation matrix ORB_BCI to rotation matrix
%   QRB_BCI. the QRB frame when converted to a 3-2-1 rpy sequence is
%   similar to typical roll pitch and yaw. 
%
%   The QRB frame is defined as:
%   QRB frame x-axis is the same as the orbit tangential
%   QRB frame y-axis is the negative of the orbit normal 
%   QRB frame z-axis is the negative of the orbit radial 
%
% Inputs: 
%   ORB_BCI  Rotation Matrix ORB_BCI
%
% Outputs:
%   QRB_BCI  Rotation Matrix QRB_BCI
%
% Modifications
%   MA-07Jul16 inital draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [QRB_BCI] = orb2qrb(ORB_BCI)
  %#codegen
  
  % Compute rotation matrix ORB_BCI
  QRB_BCI = [ ORB_BCI(2,:);
             -ORB_BCI(3,:);
             -ORB_BCI(1,:)];
end