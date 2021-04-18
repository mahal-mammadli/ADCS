%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes paths for DYN
%
% Discription:
%  This script calls initalization scripts for lower level components. This
%  script allows for each lower level script to be added to the matlab
%  path.
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Add paths for MODELS and PARAMETERS folders
DYNrootdir = fileparts( mfilename('fullpath'));
addpath(fullfile(DYNrootdir,'MODELS'))
addpath(fullfile(DYNrootdir,'PARAMETERS'))

% Intialize parameters at this level  
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_init.m'))
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_TRA_init.m'))
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_ATT_init.m'))
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_MAG_init.m'))
% run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_GRAV_init.m'))
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_AERO_init.m'))
run(fullfile(DYNrootdir, 'PARAMETERS', 'DYN_SC_init.m'))

clear DYNrootdir
