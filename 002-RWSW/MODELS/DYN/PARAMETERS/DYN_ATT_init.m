%%%
% Initialize the Dynamic Attitude Parameters
%%%

%% Modifiable  Parameters

%Inital Angle and rate
DYN_ATT_par.ang_ini = 45*pi/180;
DYN_ATT_par.BOFw_relORB_BOF_ini = [0;0;0]; [-0.075;-0.075;+0.075]*pi/180;

%Construct Orbtial Frame
DYN_ATT_par.BOFx_ORB_nom = [1 0 0];
DYN_ATT_par.BOFz_ORB_nom = [ 0 0 1];
DYN_ATT_par.BOFy_ORB_nom = cross(DYN_ATT_par.BOFz_ORB_nom, DYN_ATT_par.BOFx_ORB_nom);
DYN_ATT_par.BOF_ORB_nom  = [DYN_ATT_par.BOFx_ORB_nom; DYN_ATT_par.BOFy_ORB_nom; DYN_ATT_par.BOFz_ORB_nom];

DYN_ATT_par.BOF_ORB_ini  = DYN_ATT_par.BOF_ORB_nom * dcm_rot3(DYN_ATT_par.ang_ini);


% Convert ORB to ECI (and convert to quaterion)
DYN_ATT_par.ORB_ECI_ini  = rv2orb(DYN_TRA_par.pos_ECI_ini, DYN_TRA_par.vel_ECI_ini, CONSTANTS_par.zero_tol);
DYN_ATT_par.BOF_ECI_ini  = DYN_ATT_par.BOF_ORB_ini * DYN_ATT_par.ORB_ECI_ini;
DYN_ATT_par.BOFq_ECI_ini = dcm2q (DYN_ATT_par.BOF_ECI_ini);

% Compute intitial angular rates (ideally just a adding a delta to the orbital rate)
DYN_ATT_par.BOFw_ECI_BOF_ini = DYN_ATT_par.BOFw_relORB_BOF_ini + DYN_ATT_par.BOF_ORB_ini * [0; 0; DYN_TRA_par.Mdot];
DYN_ATT_par.h_BOF_ini        = DYN_SC_par.inertia * DYN_ATT_par.BOFw_ECI_BOF_ini;