function plotTST_RWSW(simOut, T_orbit_inv, resultsdir)


%% Attitude Representation
fig_name = 'Attitude RPY Representation (BOFq\_ECI)';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (3,1,1);
plot(simOut.BOFw_relECI_BOF.time*T_orbit_inv, simOut.BOFw_relECI_BOF.signals.values,'-')
ylabel('deg')
title('BOFq\_ECI')
legend ('Roll (x)', 'Pitch (y)', 'Yaw (z)')

ax(2)=subplot (3,1,2);
plot(simOut.BOFw_relECI_BOF_degpersec.time* T_orbit_inv, simOut.BOFw_relECI_BOF_degpersec.signals.values)
ylabel('[deg/s]')
title(' BOFw\_relECI\_BOF')

ax(3)=subplot (3,1,3);
plot(simOut.h_tot_BOF.time* T_orbit_inv, simOut.h_tot_BOF.signals.values)
ylabel('[m^2/s]')
title('Angular Momentum (h)')


%set(fighandle,'renderer','painters')
saveas(fighandle, [resultsdir, '/', fig_name, '.fig'])
close (fighandle)


%% Trajectory Dynamics

fig_name = 'Trajectory Dynamics';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (3,1,1);
plot(simOut.acc_ECI.time*T_orbit_inv, simOut.acc_ECI.signals.values,'-')
ylabel('[m/s^2]')
title('Acceleration (ECI)')
legend ('x_E_C_I','y_E_C_I','z_E_C_I')

ax(2)=subplot (3,1,2);
plot(simOut.vel_ECI.time* T_orbit_inv, simOut.vel_ECI.signals.values)
ylabel('[m/s]')
title('Velocity (ECI)')

ax(3)=subplot (3,1,3);
plot(simOut.pos_ECI.time* T_orbit_inv, simOut.pos_ECI.signals.values)
ylabel('[m]')
title('Position (ECI)')
xlabel('Orbits [-]')
linkaxes(ax, 'x')

%set(fighandle,'renderer','painters')
saveas(fighandle, [resultsdir, '/', fig_name, '.fig'])
close (fighandle)

%% Magnetic Dynamics

fig_name = 'Magnetic Dynamics';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (3,1,1);
plot(simOut.magfld_ECI.time*T_orbit_inv, simOut.magfld_ECI.signals.values,'-')
ylabel('[T]')
title('Magnetic Field (ECI)')
legend ('x_E_C_I','y_E_C_I','z_E_C_I')

ax(2)=subplot (3,1,2);
plot(simOut.magfld_magnitude.time* T_orbit_inv, simOut.magfld_magnitude.signals.values)
ylabel('[T]')
title('Magnitude of Magnetic Field (ECI)')

ax(3)=subplot (3,1,3);
plot(simOut.magtor_app_BOF.time* T_orbit_inv, simOut.magtor_app_BOF.signals.values)
ylabel('[Nm]')
title('Magnetic Torque Applied (BOF)')
xlabel('Orbits [-]')
linkaxes(ax, 'x')

%% Sum of Forces and Torques

fig_name = 'Sum of Forces and Torques';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (2,1,1);
plot(simOut.extfor_ECI.time*T_orbit_inv, simOut.extfor_ECI.signals.values,'-')
ylabel('[m/s^2]')
title('Sum of Forces (ECI)')
legend ('x_E_C_I','y_E_C_I','z_E_C_I')

ax(2)=subplot (2,1,2);
plot(simOut.exttor_BOF.time* T_orbit_inv, simOut.exttor_BOF.signals.values)
ylabel('[Nm]')
title('Sum of Torques (BOF)')
xlabel('Orbits [-]')
linkaxes(ax, 'x')

%set(fighandle,'renderer','painters')
saveas(fighandle, [resultsdir, '/', fig_name, '.fig'])
close (fighandle)


end