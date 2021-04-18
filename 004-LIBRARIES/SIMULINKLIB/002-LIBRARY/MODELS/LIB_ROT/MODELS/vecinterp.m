function [ vec_interp ] = vecinterp(time_start, time_step, vec_refset, time_interp)
  %#codegen
  vec_interp=[0;0;0];
  for i = 1:1:3 
    vec_interp(i)= cubicspline(time_start, time_step, vec_refset(:,i), time_interp);
  end
  
end

function [y] =cubicspline(x_ini, dx, yi, x)
  %#codegen
 
  % Compute idx_prev
  idx_prev = floor((x - x_ini)/dx)+1;
  
  % Compute data points range to use
  numrefpnts      = length(yi);
  if idx_prev > numrefpnts-2
    %   Compute range using last available index
    idx1    = max([1, numrefpnts-3]);
  else
    %   Compute range from first index
    idx1    = max([1, idx_prev-1]);
  end
  
  % Retrieve y1 to y4
  data    = zeros(4,1);
  data(1) = yi(idx1+0);
  data(2) = yi(idx1+1);
  data(3) = yi(idx1+2);
  data(4) = yi(idx1+3);
  
  % Compute the derivative matrix
  yMat    = [0;0];
  yMat(1) = data(1)-2*data(2)+data(3);
  yMat(2) = data(2)-2*data(3)+data(4);
  
  % Solve the linear equations system
  Mmat    = [5/24 -1/24; -1/24 5/24] * 6/dx^2 * yMat;
  M       = [Mmat(1); Mmat(1); Mmat(2); Mmat(2)];
  
  % Choose which function to use depending on x value wrt xi's
  if idx_prev < 2
    %   Use the first polynomial (extrapolation or interpolation in the
    %   points interval 1:2)
    i  = 1;
    xi = x_ini;
  elseif idx_prev > numrefpnts-2
    %   Use the last polynomial (extrapolation or interpolation in the
    %   points interval 3:4)
    xi = (numrefpnts-2)*dx + x_ini;
    i  = 3;
  else
    %   Regular case, use the i = 2:3 interval.
    xi = (idx_prev-1)*dx + x_ini;
    i  = 2;
  end
  
  % Derive the polynomial coefficients for the function between xi and xi+1
  a       = (M(i+1) - M(i))/6/dx;
  b       = M(i)/2;
  c       = (data(i+1)-data(i))/dx - (M(i+1) + 2*M(i))/6*dx;
  d       = data(i);
  
  % Evaluate the function at x
  xmxi    = x - xi;
  y       = a*(xmxi)^3 + b*(xmxi)^2 + c*(xmxi) + d;
  
end