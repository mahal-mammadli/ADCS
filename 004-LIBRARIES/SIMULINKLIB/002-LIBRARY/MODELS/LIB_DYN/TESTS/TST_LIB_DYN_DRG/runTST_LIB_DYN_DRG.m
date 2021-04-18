%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Test Aerodynamic Drag Force on panel
%
% Description:
%   Computes the aerodynamic drag force acting on an panel based on its
%   drag coefficient.
%
%
% Modifications:
%   MA-28Sep16: intial draft.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% cubesat
x = 0.1;
y = 0.1;
z = 0.1;

SCcom_MEC = [0; 0 ; 0]; % also MECorigin_relMECorigin_MEC
% assume MEC and MEC are cooincident to make this test simpler to
% interpret
PNLcop_MEC_array = [ +0.05, 0.0,   0.0;  ... +X face
                     -0.05, 0.0,   0.0;  ... -X face
                      0.0, +0.05,  0.0;  ... +Y face
                      0.0, -0.05,  0.0;  ... -Y face
                      0.0,  0.0,  +0.05; ... +Z face
                      0.0,  0.0,  -0.05]; ... -Z face
PNLuvec_MEC_array = [ 1,   0,   0;  ... +X face
                     -1,   0,   0;  ... -X face
                      0,   1,   0;  ... +Y face
                      0,  -1,   0;  ... -Y face
                      0,   0,  +1;  ... +Z face
                      0,   0,  -1]; ... -Z face
PNLarea_array = [ y * z; ... +X face
  y * z; ... -X face
  x * z; ... +Y face
  x * z; ... -Y face
  x * y; ... +Z face
  x * y];% -Z face

PNLcd_array=ones(6,1)*2;% 2.0 is a typical value for cd for spacecraft 1.28 for a flat plate ~2 for a rectanglular box
% its all a blind guess without actual testing and its likely that cd 

atmdensity = 1.5e-12 %ref densisty at 450 km 

%% compute  drag for and torques for each face
ATMvel_relMEC_MEC = [7000;-1000; -2000];
ATMvel_relMEC_uvec = vecunit(ATMvel_relMEC_MEC);
numpanels= numel(PNLarea_array);
for i=1:1:numpanels
  drgfor_MEC(:,i) = dyndrgfor_pnl(atmdensity,             ...
    ATMvel_relMEC_MEC,      ...
    PNLuvec_MEC_array(i,:), ...
    PNLarea_array(i),       ...
    PNLcd_array(i));
end

netdragfor_MEC = sum(drgfor_MEC, 2);
%% plot velocity axes and net drag unit vectors
figure
plot3([0,ATMvel_relMEC_uvec(1)], [0 ATMvel_relMEC_uvec(2)],[0 ATMvel_relMEC_uvec(3)],'--^')
hold on
for i=1:1:numpanels
  plot3([0,PNLuvec_MEC_array(i,1)], [0 PNLuvec_MEC_array(i,2)],[0 PNLuvec_MEC_array(i,3)],':x');
  
end
netdrgfor_norm = vecnorm(netdragfor_MEC)
 plot3([0,netdragfor_MEC(1)/netdrgfor_norm], [0 netdragfor_MEC(2)/netdrgfor_norm],[0 netdragfor_MEC(3)/netdrgfor_norm],'-d');

for i=1:1:numpanels
  drgfor_MEC_uvec= drgfor_MEC(:,i)/netdrgfor_norm
  plot3([0,drgfor_MEC_uvec(1)], [0 drgfor_MEC_uvec(2)],[0 drgfor_MEC_uvec(3)],'-d');
end

legend('ATMvel\_relMEC', ...
       'PNL1 uvec', ...
       'PNL2 uvec', ...
       'PNL3 uvec', ...
       'PNL4 uvec', ...
       'PNL5 uvec', ...
       'PNL6 uvec', ...
       ['netdrgfor [', num2str(netdragfor_MEC'),']'],...
       ['PNL1 drgfor uvec [', num2str(drgfor_MEC(:,1)'),']'], ... 
       ['PNL2 drgfor uvec [', num2str(drgfor_MEC(:,2)'),']'], ... 
       ['PNL3 drgfor uvec [', num2str(drgfor_MEC(:,3)'),']'], ... 
       ['PNL4 drgfor uvec [', num2str(drgfor_MEC(:,4)'),']'], ... 
       ['PNL5 drgfor uvec [', num2str(drgfor_MEC(:,5)'),']'], ... 
       ['PNL6 drgfor uvec [', num2str(drgfor_MEC(:,6)'),']'] ... 
       )
xlabel('X_B_O_F')
ylabel('Y_B_O_F')
zlabel('Z_B_O_F')


axis square
