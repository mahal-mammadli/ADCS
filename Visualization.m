% Init

run('MASTERinit.m')
%% Simulation 

sim('TST_RWSWV2.mdl')

%%
%x1 = simout_DYN_TRA.Data(:,4);
%y1 = simout_DYN_TRA.Data(:,5);
%z1 = simout_DYN_TRA.Data(:,6);

x1 = pos_ECI.signals.values(:,1);
y1 = pos_ECI.signals.values(:,2);
z1 = pos_ECI.signals.values(:,3);

t = pos_ECI.time(:,1);
t_max = tout(end);

Re = 6.37e6;
figure(1);
load('earth_topo.mat');
[x,y,z] = sphere(50);
view(3) % set dim=3 for 3-D plot 
hold on;
p = plot3(x1,y1,z1,'r');
s = surf(Re*x,Re*y,Re*z); % create a sphere
s.CData = topo;                % set color data to topographic data
s.FaceColor = 'texturemap';    % use texture mapping
s.EdgeColor = 'none';          % remove edges
s.FaceLighting = 'gouraud';    % preferred lighting for curved surfaces
s.SpecularStrength = 0.4;      % change the strength of the reflected light
grid on; box on; axis equal;
xlabel('x (10^6 m)'); ylabel('y (10^6 m)'); zlabel('z (10^6 m)'); title('Earth');
set(gca,'LineWidth',1,'FontSize',14, ...
      'Xtick',[-8:4:10],'Ytick',[-8:4:10],'Ztick',[-8:4:8]);
hold off;

%% Earth Position relative to Sun

earth_pos_sun = simout_earth_pos_sun.Data;
% Extracting coordinates
xe = earth_pos_sun(:,1);
ye = earth_pos_sun(:,2);
ze = earth_pos_sun(:,3);

%% 
% Attitude position visualization

t = pos_ECI.time(:,1);
%quat = simout_DYN_ATT.Data;
quat = BOFq_ECI.signals.values;
rotm = quat2rotm(quat);
Fb = rotm;


vel_ECI_data = vel_ECI.signals.values;

%Cv = quat2rotm(OCFq_ECI.Data);
Fv = [];

for j=1:1:size(t,1)
F(:,:,j) = [0 0 0;Fb(:,1,j)';0 0 0;Fb(:,2,j)';0 0 0;Fb(:,3,j)'];
%Fv(:,:,j) = [0 0 0;Cv(:,1,j)';0 0 0;Cv(:,2,j)';0 0 0;Cv(:,3,j)'];
end
Fi_plot = [0 0 0;1 0 0;0 0 0;0 1 0;0 0 0;0 0 1];
% Bounds of plot
xmin = -1;ymin = -1;zmin= -1;
xmax = 1;ymax = 1;zmax = 1;
% Axis type used during simulation
axis_type = 'man'; % man or auto
% Simulation
for j=1:1:size(t,1)
    pl = plot3(Fi_plot(:,1),Fi_plot(:,2),Fi_plot(:,3),'--',...
        F(:,1,j),F(:,2,j),F(:,3,j),'r');%,...
        %Fv(:,1,j),Fv(:,2,j),Fv(:,3,j),'g');
    pl(1).LineWidth = 2;
    pl(2).LineWidth = 2;   
    grid on;
    title('Attitude Control System Simulation');
    switch axis_type
        case 'man'
            axis([xmin xmax ymin ymax zmin zmax]);
        case 'auto'
            axis square;
    end
    pause(0.0000001);
end

%% 
pos_ECI_data = pos_ECI.signals.values;
vel_ECI_data = vel_ECI.signals.values;
t = pos_ECI.time(:,1);
t_max = tout(end);
for j=1:1:t_max
[a(j),ecc(j),incl(j),RAAN(j),argp(j),nu(j),truelon,arglat,lonper] = ijk2keplerian(pos_ECI_data(j,:),vel_ECI_data(j,:));
end
mu = CONSTANTS_par.mu_earth;
n = quatrotate(BOFq_ECI.signals.values,aerofor_ECI.signals.values) + ...
    grvfor_BOF.signals.values;
fr = n(:,1);
fth = n(:,2);
fz = n(:,3);
fr(end,:) = [];
fth(end,:) = [];

dE_dt = sqrt(mu./(a'.*(1-ecc'.^2))).*(ecc'.*sin(nu').*fr + (1 + ecc'.*cos(nu')).*fth);
t = pos_ECI.time(:,1);
t(end,:) = [];
plot(t,dE_dt)

%%
% Plot of r_ECI vs time in seconds


t_max = tout(end);
t = pos_ECI.time(:,1);
r_ECI = sqrt(pos_ECI.signals.values(:,1).^2+pos_ECI.signals.values(:,2).^2+...
    pos_ECI.signals.values(:,3).^2);
r_ECI(end,:) = [];

% Plot of all points
figure();
plot(t(1:t_max)*DYN_TRA_par.T_orbit_inv,r_ECI)
grid on;
xlabel('Orbits');
ylabel('Orbital Radius, r_{ECI} [m]');
title('Simulated deorbit profile for CanX-7 Spacecraft');

% Plot of mean points within ~10 orbits LEO
r_ECI_mean = movmean(r_ECI,100000);
figure();
plot(t(1:t_max),r_ECI_mean)
grid on;
xlabel('Time [s]');
ylabel('Orbital Radius, r_{ECI} [m]');
title('Simulated deorbit profile for CanX-7 Spacecraft');

% Plot of mean points within ~10 orbits LEO
r_ECI_mean = (movmean(r_ECI,100000)-CONSTANTS_par.r_earth)/1000;
figure();
plot(t(1:t_max),r_ECI_mean)
grid on;
xlabel('Time [s]');
ylabel('Orbital Altitude [km]');
title('Simulated deorbit profile for CanX-7 Spacecraft');


figure();
plot(t(1:t_max)*DYN_TRA_par.T_orbit_inv,r_ECI_mean)
grid on;
xlabel('Orbits');
ylabel('Mean Orbital Altitude [km]');
title('Simulated deorbit profile for CanX-7 Spacecraft');



%%

pos_ECI_data = pos_ECI.signals.values;
t = pos_ECI.time(:,1);
t_max = tout(end);
% for i=1:1:t_max
% lla(i,:) = eci2lla(pos_ECI_data(i,:),simout_utc.data(i,:));
% end
% plot(t(1:t_max),lla(:,3))
lla = eci2lla(pos_ECI_data,simout_utc.Data);
plot(t, lla(:,3))

%%

fig_name = 'Attitude RPY Representation (BOFq\_ECI)';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (3,1,1);
plot(BOFq_ECI.time*DYN_TRA_par.T_orbit_inv, BOFq_ECI.signals.values,'-')
title('BOFq\_ECI')

ax(2)=subplot (3,1,2);
plot(BOFw_relECI_BOF_degpersec.time*DYN_TRA_par.T_orbit_inv, BOFw_relECI_BOF_degpersec.signals.values)
ylabel('[deg/s]')
title(' BOFw\_relECI\_BOF')
legend ('(x)', '(y)', '(z)')
ax(3)=subplot (3,1,3);
plot(h_tot_BOF.time*DYN_TRA_par.T_orbit_inv, h_tot_BOF.signals.values)
ylabel('[m^2/s]')
title('Angular Momentum (h)')
xlabel('Orbits [-]')
linkaxes(ax, 'x')
%%

%% Sum of Forces and Torques

fig_name = 'Sum of Forces and Torques';
fighandle = figure('Name', fig_name);
clear ax
ax(1)=subplot (2,1,1);
plot(extfor_ECI.time*DYN_TRA_par.T_orbit_inv, extfor_ECI.signals.values,'-')
ylabel('[m/s^2]')
title('Sum of Forces (ECI)')
legend ('x_E_C_I','y_E_C_I','z_E_C_I')

ax(2)=subplot (2,1,2);
plot(exttor_BOF.time* DYN_TRA_par.T_orbit_inv, exttor_BOF.signals.values)
ylabel('[Nm]')
title('Sum of Torques (BOF)')
xlabel('Orbits [-]')
linkaxes(ax, 'x')

