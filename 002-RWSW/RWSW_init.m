%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes paths for RWSW part of project
%
% Discription:
%  This script calls initalization scripts for lower level components. This
%  script allows for each lower level script to be added to the matlab
%  path. Following the standards outlined in the below reference.
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Add paths for MODELS and PARAMETERS folders
RWSWrootdir = fileparts( mfilename('fullpath'));
addpath(fullfile(RWSWrootdir,'MODELS'))
% addpath(fullfile(RWSWrootdir,'PARAMETERS'))

% Intialize parameters at this level  
% run(fullfile(RWSWrootdir,'PARAMETERS','RWSW_init.m'))
run(fullfile(RWSWrootdir,'PARAMETERS','CONSTANTS_init.m'))

% Add root paths of sub modules 
% addpath(fullfile(RWSWrootdir,'MODELS', 'ACT'))
addpath(fullfile(RWSWrootdir,'MODELS', 'DYN'))
% addpath(fullfile(RWSWrootdir,'MODELS', 'SEN'))
addpath(fullfile(RWSWrootdir,'TESTS','TST_RWSW'))

% Call submodule level ini files
run(fullfile(RWSWrootdir, 'MODELS', 'ACT', 'ACTini.m'))
run(fullfile(RWSWrootdir, 'MODELS', 'DYN', 'DYNini.m'))
% run(fullfile(RWSWrootdir, 'MODELS', 'SEN', 'SENini.m'))
clear RWSWrootdir