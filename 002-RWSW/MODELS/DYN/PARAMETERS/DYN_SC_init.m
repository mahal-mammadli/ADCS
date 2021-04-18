%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialize the Spacecraft Parameters
%
% Description:
%  Parameter initilization for the Spacecraft parameters
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% DYN_SC_par.inertia = [2.541e-4, 0, 4.9370e-05;
%                       0, 4.725e-4, 0;
%                       4.9370e-05, 0, 4.937e-4];

                   
DYN_SC_par.mass = 3.5; %kg

DYN_SC_par.d = 0.1; %m
DYN_SC_par.h = 0.1; %m
DYN_SC_par.w = 0.34; %m

DYN_SC_par.inertia = 1/12*DYN_SC_par.mass*...
    [ DYN_SC_par.h^2+DYN_SC_par.d^2 0 0;
    0 DYN_SC_par.w^2+DYN_SC_par.d^2 0;
    0 0 DYN_SC_par.w^2+DYN_SC_par.h^2];
 
DYN_SC_par.dh = 2; %m
DYN_SC_par.db = 2; %m 
DYN_SC_par.Drag_sail_mass = 0.8; %kg 22% of total mass
DYN_SC_par.Drag_sail_inertia = 1/12*DYN_SC_par.Drag_sail_mass*...
    [DYN_SC_par.dh^2+DYN_SC_par.db^2 0 0;
    0 DYN_SC_par.dh^2 0;
    0 0 DYN_SC_par.db^2];
% drag sail is assumed to be 2 x 2 meters

DYN_SC_par.inertia_deployed = DYN_SC_par.inertia + DYN_SC_par.Drag_sail_inertia;

