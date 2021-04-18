%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes paths for ACT part of project
%
% Discription:
%  This script calls initalization scripts for lower level components. This
%  script allows for each lower level script to be added to the matlab
%  path.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Add paths for MODELS and PARAMETERS folders
ACTrootdir = fileparts( mfilename('fullpath'));
addpath(fullfile(ACTrootdir,'MODELS'))
addpath(fullfile(ACTrootdir,'PARAMETERS'))

% Intialize parameters at this level  
run(fullfile(ACTrootdir, 'PARAMETERS', 'ACT_MAG_init.m'))
run(fullfile(ACTrootdir, 'PARAMETERS', 'ACT_ATT_init.m'))
% run(fullfile(ACTrootdir, 'PARAMETERS', 'ACT_MTR_init.m'))

clear ACTrootdir