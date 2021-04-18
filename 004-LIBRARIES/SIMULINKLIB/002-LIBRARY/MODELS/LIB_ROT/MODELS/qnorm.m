%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computes a unit quaternion from a quaternion
%
% Description:
%  This function computes the norm of a quaternion using method
%  outlined in section 5.6. of Kuipers 1999
%
% Inputs:
%  Aq_B: Quaternion representing rotation of frame B to frame A
%  tol:  tolerance to use on quaternion unit length if not specified 10e-9
%        is used
%
% Outputs
%  Aq_B_unit: unit quaternion of Aq_B
%  fdi: 1 indicates that unit length computed is less than tolerance
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Aq_B_unit, fdi] = qnorm(Aq_B, tol)
  %#codegen
  
  % Check if tolerance is specficied
  if nargin < 2
    tol = 10e-9;
  end
  
  % intialize outputs
  Aq_B_unit = Aq_B;
  fdi = 0;
  
  % Compute "unit length" of quaternion
  n = sqrt(Aq_B(1)^2 + Aq_B(2)^2 + Aq_B(3)^2 + Aq_B(4)^2);
  
  % Check that unit length is > than tol
  if n < tol
    Aq_B_unit(1) = 1;
    Aq_B_unit(2) = 0;
    Aq_B_unit(3) = 0;
    Aq_B_unit(4) = 0;
    fdi = 1;
  else
    
    % Normalize quaternion based on unitlength
    Aq_B_unit = Aq_B ./ n;
  end
end

