%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Converts a direction cosine matrix to a quaterion representation
%
% Discription:
%  Converts a dcm to quaterion using  
%  this function follows the reuslt shown in section 5.8 of Kuiperss 1999.
%
% Inputs
% Aq_B: quaternion representing the rotation from frame B to frame A
% vec_B: vector expressed in frame B
%
% Outputs 
% vec_A vector expressed in frame A
%
% References: :)
%  spacecraft attitude dynamics P. C. Hughes, 2004
%
% Modifications:
%  MA-20Jun16 initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [A_B] = q2dcm( Aq_B )
  %#codegen
  Aq_Bscalar = Aq_B(1);
  Aq_Bvector = Aq_B(2:4);
  Aq_Bvector = Aq_Bvector(:);

  % Using equation 2.2-13 from Hughes 2004
  A_B = (Aq_Bscalar^2 - (Aq_Bvector' * Aq_Bvector)) * eye(3) ...
         + 2 * (Aq_Bvector * Aq_Bvector')                    ...
         - 2 * Aq_Bscalar * crossmat(Aq_Bvector);

end

