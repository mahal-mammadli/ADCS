%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% interperolates a rotation between two known rotations and a known fraction
%
% Description:
%  interpolates a quaternion from two known quaternions and a fraction by
%  finding the rotation between the two quaternions converting it to axis
%  angle representation and rotating by a fraction of the angle and
%  computing this back to a quaternion
%
% Inputs:
%  Bq_A_prev: first known quaternion
%  Bq_A_next: second knownn quaternion
%  fract:     fraction to interpolate by (0 to 1) or extrapolate from (<1 or >1)
%
% Outputs
%  q_interp: second Quaternion representing rotation of frame B to frame A
%
% References:
%  Quaternions and Rotation Sequences, Jack B. Kuipers, 1999, Princeton
%  Press.
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ Bq_A_interp ] = qslerp(Bq_A_prev, Bq_A_next, fract)
  %#codegen
  % Compute difference between q_next and q_prev
  Aq_B_prev = qtrans(Bq_A_prev);
  Bnextq_Bprev = qprod(Bq_A_next, Aq_B_prev);
  
  % Convert to axis angle
  [axis_Bprev, ang] = q2aa(Bnextq_Bprev);
  
  % Compute delta rotation from prev
  ang_fract = ang * fract;
  q_delta = aa2q(axis_Bprev, ang_fract);
  
  % Apply delta rotation to Bq_A_prev
  Bq_A_interp = qprod(q_delta, Bq_A_prev);
  
end

