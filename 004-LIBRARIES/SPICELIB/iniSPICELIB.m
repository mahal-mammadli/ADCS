%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializes Paths for SPICELIB
%
% Description:
%  This script finds location of SPICELIB root and adds the required paths
%  to the main Matlab paths.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SPICELIBrootdir = fileparts( mfilename('fullpath'));

% Set the path of the version of MICE to use based on computer arch type
% configured for Windows and MacOS
archstr= computer('arch');
if strcmp(archstr,'win64')
  MICEPATH = '002-MICE_win64';
elseif strcmp(archstr,'maci64')
  MICEPATH = '003-MICE_mac64';
 end

%% Add paths to required spice parts and minimum kernel sets.
addpath(fullfile(SPICELIBrootdir,'001-MinimumKernels'))
addpath(fullfile(SPICELIBrootdir, MICEPATH, 'src/mice'))
addpath(fullfile(SPICELIBrootdir, MICEPATH, 'lib'))

clear SPICELIBrootdir MICEPATH archstr