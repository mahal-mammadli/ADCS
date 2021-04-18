%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% interperolates a quaternions using a similar structure as interp1
%
% Description:
%  interpolates quaternions from a reference set
%
% Inputs:
%  time_refset:  points in 'time' coresponding to quaternions states (5 or more)
%  Bq_A_ref:  a vector of 5 or more quaternions
%  time_interp : point in 'time' to interpolate quaternion for
%
% Outputs
%  q_interp: quaternions
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-26Jul16: initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Bq_A_interp] = qinterp(time_start, time_step, Bq_A_ref, time_interp)
  %#codegen
  
  % Check quaternion reference set is equal in length to num_refs 
  % also algo assumes  shape is [num_refs x 4]
  [m, n]= size(Bq_A_ref);
  if (n ~= 4)
    Bq_A_refset_checked=Bq_A_ref';
    numrefpnts = n;
  else
    Bq_A_refset_checked=Bq_A_ref;
    numrefpnts = m;
  end
  assert(numrefpnts > 5)
  assert(m == numrefpnts)
  %%
  idx_prev = floor((time_interp - time_start)/time_step);
  idx_next = idx_prev + 1;
 
  if ((idx_prev >= 0) && (idx_next < numrefpnts))
    time_prev = time_step * idx_prev;
    time_next = time_step * idx_next;
    Bq_A_prev = Bq_A_refset_checked(idx_prev + 1,:);
    Bq_A_next = Bq_A_refset_checked(idx_next + 1,:);
  elseif (idx_prev < 0)
    % extrapolate into the past using inital slope
    time_prev = time_step * 1;
    time_next = time_step * 2;   
    Bq_A_prev = Bq_A_refset_checked(1,:);
    Bq_A_next = Bq_A_refset_checked(2,:);
  else
    % extrapolate into future past using last slope
    time_prev = time_step * (numrefpnts-1);
    time_next = time_step * numrefpnts;
    Bq_A_prev = Bq_A_refset_checked((numrefpnts-1),:);
    Bq_A_next = Bq_A_refset_checked((numrefpnts),:);
  end
  fraction = (time_interp - time_prev) / (time_next - time_prev);
  Bq_A_interp = qslerp(Bq_A_prev(:), Bq_A_next(:), fraction);
  
end
