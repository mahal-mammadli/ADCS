%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialize the Trajectory Parameters
%
% Description:
%  Parameter initilization for DYN_TRA block
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% Orbital Elements
% Default values based on: ISS, but can be adjusted

% DYN_SC_par.inertia = [2.541e-4, 0, 4.9370e-05;
%                       0, 4.725e-4, 0;
%                       4.9370e-05, 0, 4.937e-4];

% CANX-7
DYN_SC_par.mass = 3.5; %kg
DYN_SC_par.d = 0.1; %m
DYN_SC_par.h = 0.1; %m
DYN_SC_par.w = 0.34; %m

DYN_SC_par.inertia = 1/12*DYN_SC_par.mass*...
    [ DYN_SC_par.h^2+DYN_SC_par.d^2 0 0;
    0 DYN_SC_par.w^2+DYN_SC_par.d^2 0;
    0 0 DYN_SC_par.w^2+DYN_SC_par.h^2];


DYN_TRA_par.Mdot = 0.0001875951;
DYN_TRA_par.Mdot_revperday = 14.60; %[rev/day]
DYN_TRA_par.ecc = 0.0;         % [-]
DYN_TRA_par.incl =  51.6453 * (pi/180); % [rad]
DYN_TRA_par.raan =  288.0416 * (pi/180); % [rad]
DYN_TRA_par.argp =  55.3972 * (pi/180); % [rad]
DYN_TRA_par.tano =  0* (pi/180); % [rad]% adjust to vary location in orbit

% DYN_TRA_par.Mdot = 0.0001875951;
% DYN_TRA_par.Mdot_revperday = 14.60; %[rev/day]
% DYN_TRA_par.ecc = 0.0;
% DYN_TRA_par.incl =  0 * (pi/180); % [rad]
% DYN_TRA_par.raan =  0 * (pi/180); % [rad]
% DYN_TRA_par.argp =  0 * (pi/180); % [rad]
% DYN_TRA_par.tano =  0* (pi/180); % [rad]% adjust to vary location in orbit

DYN_TRA_par.sma = CONSTANTS_par.mu_earth^(1/3)/((2*DYN_TRA_par.Mdot_revperday*pi)/(3600*24))^(2/3);
DYN_TRA_par.T_orbit = 2*pi/sqrt(CONSTANTS_par.mu_earth)*DYN_TRA_par.sma^(3/2); % Period
DYN_TRA_par.T_orbit_inv = 1/DYN_TRA_par.T_orbit; %rev/sec

%% Calculate Position and Velocity 

[DYN_TRA_par.pos_ECI_ini,DYN_TRA_par.vel_ECI_ini]= kep2rv(...
  DYN_TRA_par.sma,        ...
  DYN_TRA_par.ecc,        ...
  DYN_TRA_par.incl,       ...
  DYN_TRA_par.raan,       ...
  DYN_TRA_par.argp,       ...
  DYN_TRA_par.tano,       ...
  CONSTANTS_par.mu_earth, ...
  0);

%%
