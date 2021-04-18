%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes Paths for Entire Simulator
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Clean Start
restoredefaultpath
clear all
close all
clc

rootdir = fileparts( mfilename('fullpath'));
%Compatable for windows and mac/unix
archstr= computer('arch');

%Disable vecnorm warning
warning('off','MATLAB:dispatcher:nameConflict')
% [a, MSGID] = lastwarn();
% warning('off', MSGID)

disp('Workspace Cleared and Initialization Ready')
disp('----------------------')
disp('Initializing Libraries')

if strcmp(archstr,'win64')
  addpath([rootdir,'\004-LIBRARIES'])
elseif strcmp(archstr,'maci64')
  addpath([rootdir,'/004-LIBRARIES']) % For MAC/Unix
end

run('LIBinit.m')
disp('----------------------')
disp('Libraries Configured')
disp('----------------------')
disp('Initializing RWSW')

archstr= computer('arch');
if strcmp(archstr,'win64')
  addpath([rootdir,'\002-RWSW'])
elseif strcmp(archstr,'maci64')
  addpath([rootdir,'/002-RWSW']) % For MAC/Unix
end

run('RWSW_init.m')
disp('----------------------')
disp('RWSW Configured')
disp('----------------------')
disp('Workspace Configured')

% ephemerisdata
addpath('C:\ProgramData\MATLAB\SupportPackages\R2020a\toolbox\aero\aerodata\aeroephemerisdata') 
% ijk2keplerian
addpath('C:\ProgramData\MATLAB\SupportPackages\R2020a\toolbox\aeroblks\supportpackages\cubesat\CoordinateTransformFcns')
% plot earth
addpath('C:\Users\m_mam\Documents\AerospaceEng\MEngProject\ADCS\PlotEarth\');
disp('----------------------')
disp('Add-ons Configured')

clear MSGID ans a archstr

