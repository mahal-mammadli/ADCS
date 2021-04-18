%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% returns skew semetric matrix representing cross multiplication i.e 
% cross(A ,B) = _(A^x)_*B  
%
% Discription:
%  returns  a skew semetric cross product matrix, Using equation B-13 from
%  Hughes 2004 
%
% Inputs
% u: vector to obtain cross product matrix for.
%
% Outputs 
% u_cross: a skew semetric cross product matrix for vector u.
%
% References:
%  Spacecraft Attitude Dynamics P. C. Hughes, 2004
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ u_cross ] = crossmat( u )
%#codegen
u_cross = [    0, -u(3),  u(2); 
            u(3),     0, -u(1);
           -u(2),  u(1),     0];

end

