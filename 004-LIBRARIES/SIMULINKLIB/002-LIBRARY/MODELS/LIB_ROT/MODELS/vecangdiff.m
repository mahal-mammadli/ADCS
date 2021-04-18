function [theta, fdi_norm_i] = vecangdiff(vecA, vecB, zero_tol)
  
  if nargin < 3
    zero_tol = 1e-16;
  end
  
  % Compute unit vectors, exit if any norm is below tolerance
  [vecA_unit, fdi_norm_i] = vecunit(vecA, zero_tol);
  if fdi_norm_i
    theta = 0;
    return;
  end
  
  [vecB_unit, fdi_norm_i] = vecunit(vecB, zero_tol);
  if fdi_norm_i
    theta = 0;
    return;
  end
  
  
  %   cosangle = dot(vecA_unit, vecB_unit);
  cosangle = vecA_unit(:)' * vecB_unit(:);
  
  theta = acos(min(max(cosangle, -1), 1));
end

