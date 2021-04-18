%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialize the Aerodynamic Parameters
%
% Description:
%  Parameter initilization for DYN_AERO block
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Modifiable parameters 

DYN_AERO_par.Drag_Coefficient = 0.001; %May be changed, assumed Drag coefficient of 2
DYN_AERO_par.Drag_Coefficient_Deployed = 0.405;                                                                  
DYN_AERO_par.CG_BOF = [0 0 0]; %Center of gravity, still TBD
DYN_AERO_par.CP_BOF = [0 0 0]; %Center of pressure, still TBD
DYN_AERO_par.Area = 1; %m^2
DYN_AERO_par.Area_Deployed = 2; %m^2