%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Computes Matrix inverse 
%
% DESCRIPTION:
%   Inverses a matrix if invertible using builtin inverse function from
%   matlab. Sets an FDI flag if the matrix is not invertable with a given
%   tolerance. 
%
% INPUTS: 
%   C       Matrix to be inverted.
%   tol     Near-zero tolerance.
%
% OUTPUTS:
%   C_inv   Matrix inverse.
%   fdi_i   FDI flag  0: No fault 
%                     1: Non-invertible matrix
%
% UPDATES:
%   MA-06Jul16: First draft.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [C_inv, fdi_i] = matinv(C, tol)
  %#codegen
  if nargin < 2
    tol = 0;
  end

  if abs(det(C)) <= tol
    C_inv = zeros(size(C));
    fdi_i = 1;
  else
    C_inv = inv(C);
    fdi_i = 0;
  end
end
