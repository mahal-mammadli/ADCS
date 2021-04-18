%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Converts a direction cosine matrix to a quaterion representation
%
% Description:
%  Converts a dcm to quaterion using one of the 4 possible methods outlined
%  on euclideanspace.com website. this function will select the method that
%  should produce the least amount of numerical error by using the method
%  with the denominator value furthest from zero. 
%
% Inputs
% A_B: direction cosine matrix that discribes rotation from B to A
%
% Outputs
% A_qB quaternion that discribes rotation from B to A
%
% References:
%  http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [Aq_B] = dcm2q(A_B)
  %#codegen
  % Compute squared versions of denominators used by 4 solutions
  qw_sq = 0.25*(1 + trace(A_B));
  qx_sq = 0.25*(1 + A_B(1,1) - A_B(2,2) - A_B(3,3));
  qy_sq = 0.25*(1 + A_B(2,2) - A_B(1,1) - A_B(3,3));
  qz_sq = 0.25*(1 + A_B(3,3) - A_B(1,1) - A_B(2,2));
  
  % Select case with largest denominator to reduce compuational errors
  [~,ind] = max([qw_sq, qx_sq, qy_sq, qz_sq]);
  
  % Preallocate space for results
  Aq_Bvector = zeros(3,1);
  Aq_Bscalar = 0;
  
  if ind == 1
    % Normal case: Find sqrt equation to solve for scalar component
    Aq_Bscalar    = sqrt(qw_sq);
    Aq_Bvector(1) = 0.25 * (A_B(2,3) - A_B(3,2)) / Aq_Bscalar;
    Aq_Bvector(2) = 0.25 * (A_B(3,1) - A_B(1,3)) / Aq_Bscalar;
    Aq_Bvector(3) = 0.25 * (A_B(1,2) - A_B(2,1)) / Aq_Bscalar;
    
  elseif ind == 2
    % Find sqrt equation to solve for qx 
    Aq_Bvector(1) = sqrt(qx_sq);
    Aq_Bscalar    = 0.25 * (A_B(2,3)-A_B(3,2)) / Aq_Bvector(1);
    Aq_Bvector(2) = 0.25 * (A_B(1,2)+A_B(2,1)) / Aq_Bvector(1);
    Aq_Bvector(3) = 0.25 * (A_B(3,1)+A_B(1,3)) / Aq_Bvector(1);
    
  elseif ind == 3
    % Find sqrt equation to solve for qy
    Aq_Bvector(2) = sqrt(qy_sq);
    Aq_Bscalar    = 0.25 * (A_B(3,1) - A_B(1,3)) / Aq_Bvector(2);
    Aq_Bvector(1) = 0.25 * (A_B(1,2) + A_B(2,1)) / Aq_Bvector(2);
    Aq_Bvector(3) = 0.25 * (A_B(2,3) + A_B(3,2)) / Aq_Bvector(2);
    
  elseif ind == 4
    % Find sqrt equation to solve for qz
    Aq_Bvector(3) = sqrt(qz_sq);
    Aq_Bscalar    = 0.25*(A_B(1,2) - A_B(2,1)) / Aq_Bvector(3);
    Aq_Bvector(1) = 0.25*(A_B(3,1) + A_B(1,3)) / Aq_Bvector(3);
    Aq_Bvector(2) = 0.25*(A_B(2,3) + A_B(3,2)) / Aq_Bvector(3);
    
  end
  
  % Package result into column vector
  Aq_B = [Aq_Bscalar; Aq_Bvector];
  
end

