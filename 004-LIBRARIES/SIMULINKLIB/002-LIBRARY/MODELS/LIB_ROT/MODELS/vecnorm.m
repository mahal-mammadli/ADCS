function [norm, fdi] = vecnorm(vec, zero_tol)
  %#codegen
  if nargin < 2
    zero_tol = 1e-16;
  end
  
  fdi = 0;
% vec_sq = dot(vec, vec);
  vec_sq = vec(:)' * vec(:);
  
  if vec_sq > zero_tol
    norm = sqrt(vec_sq);
  else
    norm = 0;
    fdi  = 1;
  end
end

