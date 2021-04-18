%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes Paths for SIMULINKLIB
%
% Description:
%  This script finds location of SIMULINKLIB root and adds the required paths
%  to the main Matlab paths.
%  Obtained libraries from below reference, All credit for each library is
%  within.
%  Reference: CETDE_ADCS-TNO-004, modified for capstone application.
%
% Modifications:
%  WT-12MAR18 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SIMULINKrootdir = fileparts( mfilename('fullpath'));

% % Set the path of the version of MICE to use based on computer arch type
archstr= computer('arch');
if strcmp(archstr,'glnxa64')
  warning('slCharacterEncoding set to "Windows-1252" to maintain compatibility with SIMULINKLIB')
  slCharacterEncoding('Windows-1252')
end

%% Add paths to required spice parts and minimum kernel sets.
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS'));
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_ACT',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_DYN',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_ENV',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_FDI',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_MTH',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_ORB',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_ROT',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_SEN',  'MODELS'))
addpath(fullfile(SIMULINKrootdir, '002-LIBRARY', 'MODELS', 'LIB_TIME', 'MODELS'))


clear archstr SIMULINKrootdir