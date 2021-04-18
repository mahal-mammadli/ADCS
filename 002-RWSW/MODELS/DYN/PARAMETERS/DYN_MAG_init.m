%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialize the Magnetic Parameters
%
% Description:
%  Parameter initilization for DYN_MAG block
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% Modifiable parameters 


DYN_MAG_par.m = [2.5300; 2.5450; 2.2350]*1e-3; %spacecraft residual magnetic fields (s/c magnetic...
%moments, eddy currents, and hysteresis )
% Based on SEAM sattelite estimates https://www.diva-portal.org/smash/get/diva2:1136121/FULLTEXT01.pdf

coder.extrinsic('call_decyear')
coder.extrinsic('decyear')
 