%% Clean Start
% Before Running this script, run the initalization since I can't make the
% path trick work.


% close all
% clc
% do_not_clear_flg=1;
% run('../../../../../MASTERinit.m')
scriptStart = now;
%% Ensure test runs in test folder (fewer slprj dirs spread about)
currdir = pwd;
simsetdir = [currdir, '/[Simulation Set]'];
mkdir(simsetdir)
testdir = fileparts( mfilename('fullpath')); 
cd (testdir)

%% Constants
% Simulation Time Selection
% sim_par.t_end           = DYN_TRA_par.T_orbit %[s] ~ 1 orbit
sim_par.t_end           = DYN_TRA_par.T_orbit * 10;%[s] % ~10 orbits

T_orbit_inv = 1/DYN_TRA_par.T_orbit; % To plot wrt num orbits
%% Parsim Load and Sweep
% Back to Proper Directory and Open Model
cd(currdir)
mdl = 'TST_RWSWV2';

% Number of Simulations set
numSims = 2;

% Rapid Accelerator Target Building
rtp = Simulink.BlockDiagram.buildRapidAcceleratorTarget(mdl);

%% Create Input Objects
ACT_DYN.par.mag= 1e-5; % Quick access to mag stength tweaking

for i=1:numSims
%Input Model
simIn(i) = Simulink.SimulationInput('TST_RWSWV2');

%Vary Magnet Strength 

simIn(i) = simIn(i).setVariable('ACT_DYN.par.mag',ACT_DYN.par.mag);
ACT_DYN.par.mag= ACT_DYN.par.mag*1.01; %Iterate through mag strengths

end


%% Simulations on parallel workers
disp ('Starting Simulation')
tic
simOut = parsim(simIn, 'ShowProgress', 'on','TransferBaseWorkspaceVariables','on');
time2execute = toc

%% Save and Plot results
tic
for i=1:numSims
    % Results Folder
    resultsdir = [simsetdir, '/run',num2str(i)];
    mkdir(resultsdir)
  
  % Plot notable data
  plotTST_RWSW(simOut(i), T_orbit_inv, resultsdir)
end
plottime =toc
close
%% Close MATLAB Workers

delete(gcp('nocreate'));
scriptEnd = now;
tot_runtime = (scriptEnd - scriptStart)*86400