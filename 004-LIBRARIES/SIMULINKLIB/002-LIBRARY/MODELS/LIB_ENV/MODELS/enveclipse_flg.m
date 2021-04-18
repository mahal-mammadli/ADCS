%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Determine Eclipse Condition at a Given Position in Space
%
% Description:
%   Calculates the eclipse condition of a point in space w.r.t. the sun
%   body and a generic celestial body.
%
% Inputs:
%   PNTpos_CEL  position to determine eclipse status in a inertial frame (m)
%   SUNpos_CEL  position of the Sun in a inertial frame (m)
%   BODYpos_CEL position of the celestial body (Earth, Moon, etc.) in a inertial frame (m)
%   SUNradius   radius of the Sun (m)
%   BODYradius  radius of the celestial body (m)
%   zero_tol    tolerance on vector magnitude to prevent division by zero (m)
%
% Outputs:
%   eclipseflg  eclipse condition
%                  0: point is in sunlight
%                  1: point is in umbra
%                  2: point is in penumbra
%   fdi_1      error detection null vectors
%                  0: no problem
%                  1: either PNTrelBODY_CEL or SUNrelBODY_CEL is a null vector
%   fdi_2      error detection non unitvector
%                  0: no problem (ie. -1 < cos_eta < 1)
%                  1: cos_eta>|1| (ie. error with uvec SUNrelBODY_uvec or PNTrelBODY_uvec)       
% References:
%   David A. Vallado, Fundamentals of Astrodynamics and Applications,4nd ed. 
%   Norrwall, MA, USA: Kluwer Academic Publishers, 2001, Section 5.3, ALGORITHM 34
%
% Modifications:
%   MA-06Oct16: Initial Draft. 
%   EG-05Jun17: Updated FDI calcs.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [eclipseflg, fdi_1, fdi_2] = enveclipse_flg( PNTpos_CEL,     ...
                                                SUNpos_CEL,     ...
                                                BODYpos_CEL,    ...
                                                SUNradius,  ...
                                                BODYradius, ...
                                                zero_tol)
  %#codegen
  
  % Predeclare some inputs for codegen
  eclipseflg = 0;
  fdi_2 = 0
  
  % Determine vector from BODY to PNT and vector from celestial BODY to SUN. This is
  % needed in the case where the CEL frame not located at celestial BODY centre of mass.
  PNTrelBODY_CEL = PNTpos_CEL - BODYpos_CEL;
  SUNrelBODY_CEL = SUNpos_CEL - BODYpos_CEL;
  
  % Check  if PNT is at centre of Body or if if Body is at centre of Sun
  PNTrelBODY_mod = vecnorm(PNTrelBODY_CEL);
  SUNrelBODY_mod = vecnorm(SUNrelBODY_CEL);
  fdi_1         = (PNTrelBODY_mod < zero_tol || SUNrelBODY_mod < zero_tol);
  
  if (fdi_1 == 0)
    BODYinfrontOfPNT = SUNrelBODY_CEL' * PNTrelBODY_CEL;
    if (BODYinfrontOfPNT <= 0) % BODY is in front of PNT
      
      % Determine unit vectors of BODY to PNT and BODY to SUN
      PNTrelBODY_uvec    = PNTrelBODY_CEL / PNTrelBODY_mod;
      SUNrelBODY_mod_inv = 1 / SUNrelBODY_mod; % used in a few places
      SUNrelBODY_uvec    = SUNrelBODY_CEL * SUNrelBODY_mod_inv;
      
      % Compute eta angle
      % Watch the sign in reference material as this easy to miss
      cos_eta = -SUNrelBODY_uvec'*PNTrelBODY_uvec;
      % check if -1 < cos_eta < 1 
      if (-1 <= cos_eta <=1 )==1
          fdi_2 = 0;
      eta     = acos(cos_eta);
      sin_eta = sin(eta);
      else
          fdi_2= 1;
          sin_eta=0;
      end
      
      % Calculate instantaneous value of penumbra and umbra angles
      tanAlphaUmb    = (SUNradius - BODYradius) * SUNrelBODY_mod_inv;
      tanAlphaPreumb = (SUNradius + BODYradius) * SUNrelBODY_mod_inv;
      
      % Compute Locations of satellite in "shadow frame"
      SAThorz  = PNTrelBODY_mod * cos_eta;
      SAThvert = PNTrelBODY_mod * sin_eta;
      PENvert  = BODYradius + tanAlphaPreumb * SAThorz;
      
      if (SAThvert <= PENvert)
        % Set to value for penumbra, 2 is used because it will stand out 
        eclipseflg = 2;
        UMBvert  = BODYradius - tanAlphaUmb * SAThorz;
        if (SAThvert <= UMBvert)
          % Set to value for umbra 
          eclipseflg = 1;
        end
      else
        % Point is not shadowed by BODY
        eclipseflg = 0;
      end
    else
      % Point in in front of BODY shadowing is not possible
      eclipseflg = 0;
    end
  end
end
