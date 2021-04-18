function [ vec_unit ] = vecunit(vec, zero_tol)
  if nargin < 2
    zero_tol = 1e-16;
  end
  
%   [vec_norm, fdi] = vecnorm(vec, zero_tol);
%   
%   if fdi==0
%     vec_unit = vec ./ vec_norm;
%   else
%     vec_unit = vec .* 0;
    
    vec_norm = vecnorm(vec, zero_tol);
    vec_unit = vec ./ vec_norm;
  %end
end

