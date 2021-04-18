%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Checks that a singluar scalar value is withn some bounds 
%
% Description:
%  limits a value to those within discribed bounds 
%
% Inputs:
%  value_in: Quaternion representing rotation of frame B to frame A using
%  upperlim: upper limit on value 
%  lowerlim: lower limit on value 
%
% Outputs
%  value_out: scalar value out limited 
%  fdi_abovelim: flag to indicate upper limit reached (or error with limits if both fdi flags set)
%  fdi_belowlim: flag to indicate lower limit reached (or error with limits if both fdi flags set)
%
% Modifications:
%  MA-21Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ value_out, fdi_abovelim, fdi_belowlim] = checkbounds(value_in, upperlim, lowerlim)
  %#codegen
  % Intialize  outputs 
  fdi_abovelim = 0;
  fdi_belowlim = 0;
  value_out = value_in;
  
  % check that bounds are sane
  if upperlim < lowerlim
    % limits confused set both limit flags and return nonsensical value
    % that will likely cause errors
    fdi_abovelim =1;
    fdi_belowlim =1;
    value_out = -42; 
  end
  
  %check bounds and modify outputs as required
  if value_in > upperlim
    value_out = upperlim;
    fdi_abovelim= 1;
  elseif value_in < lowerlim
    value_out = lowerlim;
    fdi_belowlim= 1;
  end
end

