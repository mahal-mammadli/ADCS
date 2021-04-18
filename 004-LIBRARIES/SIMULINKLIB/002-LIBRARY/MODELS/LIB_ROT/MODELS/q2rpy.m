%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Converts quaterion to axis angle representation
%
% Description:
%  Computes axis angle pair from a quaternion
%
% Inputs:
%  Aq_B: Quaternion representing rotation of frame B to frame A using
%  equations found in sec 7.5 of Kuipers
%
% Outputs
%  Arpy_B: 321 RPY sequence representing rotation of frame B to frame A
%
% References:
%   SpinCalcVis Rotational Visualization Tool  V1.0
%   Author: John Fuller imaginationdirect@gmail.com
%
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ Arpy_B ] = q2rpy( Aq_B )
  %#codegen
    
  q_w=Aq_B(1);
  q_x=Aq_B(2);
  q_y=Aq_B(3);
  q_z=Aq_B(4);
  
  yaw   = atan2(2.*(q_x.*q_y+q_z.*q_w),(q_w.^2+q_x.^2-q_y.^2-q_z.^2));
  pitch = asin(2.*(q_y.*q_w-q_x.*q_z));
  roll  = atan2(2.*(q_x.*q_w+q_z.*q_y),(q_w.^2-q_x.^2-q_y.^2+q_z.^2));
  
  Arpy_B=[roll; pitch; yaw];
  
end

