%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes Paths for external libraries
%
% Description:
%  Adding library initialization scripts to the current path.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
LIBrootdir = fileparts( mfilename('fullpath'));

addpath(fullfile(LIBrootdir,'SIMULINKLIB'))
addpath(fullfile(LIBrootdir,'SPICELIB'))

run('iniSIMULINKLIB.m')
run('iniSPICELIB.m')

clear LIBrootdir


