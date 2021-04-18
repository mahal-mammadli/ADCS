%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Call MICE/SPICE to generate Precalculated Celestial Body States Data
%
% Description:
%   Prepares data structure that can be interpolated within simulink.
%
%   A list of valid celestial bodies (for body_str and origin_str inputs)
%   is as follows:
%   'SUN'                      - the Sun's centre of mass
%   'SSB'                      - the Solar System's barycentre
%   'SOLAR SYSTEM BARYCENTER'  - the Solar System's barycentre
%   'EMB'                      - the Earth Moon system barycentre
%   'EARTH'                    - the Earth's centre of mass
%   'MOON'                     - the Earth's Moon centre of mass
%   'MARS'                     - Mars centre of mass
%   Names of additional bodies can be found in SPICE/MICE documentation under
%   required reading: "naif_ids". Also note there may be several valid ways to
%   refer to a celestial body (or system of bodies)
%
%   A list of valid frame orientation (for body_frame_str and
%   origin_frame_str inputs) is as follows:
%   'J2000'       - An inertial frame frame with:
%                   x axis is the Mean equinox of a standard epoch J2000
%                   z axis is along Earth rotation axis of reference.
%   'IAU_EARTH'   - General purpose Earth Centred Earth Fixed (ECEF) frame
%                   (does not model all precision / nutation effects).
%   'ITRF93'      - Higher precision Earth centred earth fixed frame
%                   includes nutation and precession effects (requires
%                   additional SPICE modules to be loaded).
%   'IAU_*'       - General purpose Body Centred Body Fixed (BCBF) frame
%                   for the celestial body indicated by the *, most
%                   celestial bodies have one.
%
%   Name of additional frames can be found in "frames.req" file in the
%   references.
%
%   The celestial body states are packed in columns as follows:
%     Columns         State
%     1               intertial time from beginng time [days]
%     2               intertial time from J2000 epoch [days]
%     3 to 5          BODYpos_CEL (m)
%     6 to 8          BODYvel_CEL (m/s)
%     9 to 11         BCBFw_relCEL_BCBF (rad/s)
%     12 to 15        BCBFq_CEL
%
% Inputs:
%   time_relJD_CEL_days_start:  start time of data in JD  (days)
%   time_relJDepoch_days_end:   end time of data in JD (days)
%   timestep_days:              Step size expressed (days)
%   body_str:                   String that describes the celestial body for which the ephemeris is desired e.g. 'EARTH'
%   body_frame_str:             String that describes orientation of the celestial body for which the ephemeris is desired e.g. 'J2000'
%   origin_str:                 String that describes the reference frame origin e.g. 'SSB'
%   origin_frame_str:           String that describes orientation of the origins reference frame e.g. 'J2000'
% Outputs:
%   body_states: a data variable containing data that needs to be interpolated in a simulation
% References:
%   MICE documentation, http://naif.jpl.nasa.gov/naif/
%
% Modifications:
%  MA-25Jul16: Initial draft
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [ body_states ] = getspiceephem(time_relJDepoch_TAI_days_start,...
                                         time_relJDepoch_TAI_days_end,  ...
                                         timestep_TAI_days,             ...
                                         body_str,                      ...
                                         body_frame_str,                ...
                                         origin_str,                    ...
                                         origin_frame_str )
  
  % Check if kernels are loaded into spice
  num_kern_load = cspice_ktotal('all');
  if(num_kern_load == 0)
    error('getspiceephem:SPICE_error', 'SPICE kernel files were not loaded. ');
  end
  
  timestr     = sprintf('JD%f',time_relJDepoch_TAI_days_start);
  et_start    = cspice_str2et(timestr);
  numdays     = (time_relJDepoch_TAI_days_end - time_relJDepoch_TAI_days_start);
  num_smp     = ceil(numdays / timestep_TAI_days);
  et          = (0:1:num_smp) * timestep_TAI_days * cspice_spd + et_start;
  time_relJDepoch_TAI_days_vec = (0:1:num_smp)' * timestep_TAI_days + time_relJDepoch_TAI_days_start;
  time_ZERO_days_vec           = (0:1:num_smp)' * timestep_TAI_days;
  
  % Get position and velocity of planetary bodies
  tra_states = cspice_spkezr(body_str, et, origin_frame_str, 'NONE', origin_str);
  
  % Get rotation and rate of (rotation) matrices between Body fixed frame and RefFrame
  att_states = cspice_sxform(origin_frame_str, body_frame_str, et);
  
  % Copy other outputs to output variables
  BODYpos_ref = tra_states(1:3,:)'*1000;
  BODYvel_ref = tra_states(4:6,:)'*1000;
  
  % Prepare attitude outputs
  BCBFw_relCEL_BCBF = zeros(num_smp+1,3);
  BCBFq_CEL         = zeros(num_smp+1,4);
  
  for i=1:1:num_smp + 1
    % Compute orientation quaternion
    BCBFq_CEL(i,:) = dcm2q((squeeze(att_states(1:3,1:3,i))));
    
    % Compute angular rate
    % See SPICE documentation for more info PATH2SPICE/doc/html/cspice/tisbod_c.html
    BODYwx_CEL = att_states(4:6,1:3,i)' * att_states(1:3,1:3,i);
    
    % Get body rates from cross product matrix
    BCBFw_relCEL_BCBF(i,:) = [BODYwx_CEL(3,2), BODYwx_CEL(1,3), BODYwx_CEL(2,1)];
  end
  
  %pack into a structure for convinence 
  body_states.BODYpos_ref                    = BODYpos_ref;
  body_states.BODYvel_ref                    = BODYvel_ref;
  body_states.BCBFw_relCEL_BCBF              = BCBFw_relCEL_BCBF;
  body_states.BCBFq_CEL                      = BCBFq_CEL;
  body_states.time_relJDepoch_TAI_days_vec   = time_relJDepoch_TAI_days_vec;
  body_states.time_relJDepoch_TAI_days_start = time_relJDepoch_TAI_days_vec(1);
  body_states.time_relJDepoch_TAI_days_step  = mean(diff(time_relJDepoch_TAI_days_vec));
  body_states.time_ZERO_days_vec             = time_ZERO_days_vec;
end

