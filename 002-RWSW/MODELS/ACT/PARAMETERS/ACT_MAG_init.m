%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initialize the passive magnetic actuator parameters
%
% Description:
%  Parameter initilization for ACT_MAG block
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Modifiable parameters 

ACT_DYN.par.mag= 1e-5*1.15; % Vs/Am 3 magnets , assumed that they have identical strengths 
%1e-4 is too much magnet

ACT_MAG.par.mag1=[ACT_DYN.par.mag;0;0]; %magnet strength 
ACT_MAG.par.mag2=[ACT_DYN.par.mag;0;0];
ACT_MAG.par.mag3=[ACT_DYN.par.mag;0;0];


ACT_MAG.par.BOF_MAG1= dcm_rot3(pi/2); %Assumed to be coincident with BOF
ACT_MAG.par.BOF_MAG2= dcm_rot2(pi/2);
ACT_MAG.par.BOF_MAG3= dcm_rot3(pi/2);

