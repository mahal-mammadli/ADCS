%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert Gregorian Calendar to JD
%
% Description
%   Converts Julian date to Gregorian calendar using Algorithm 14 found in 
%   Fundamentals of Astrodynamics (Vallado).
%   - The algorithm is only valid between years 1900 and 2100.
%   - The algorithm does not account for leap seconds or any other change
%     of time systems.
%
% INPUTS:
%   time_REF_wholeyears   Common Era years [year]
%   time_REF_monthofyear  Numerical value for the month [month]
%   time_REF_dayofmonth   Day of the month [day]
%   time_REF_hrofday      Hours of the day [h]
%   time_REF_minofhr      Minutes of the hour [min]
%   time_REF_secofmin     Seconds of the minute [s]
%
% OUTPUTS:
%   time_relJDepoch_REF_days Julian Date (number of fractional days since 01 Jan 4713 B.C.E. @ noon)expressed in some reference time frame
%
% REFERENCES:
%   David A. Vallado, Fundamentals of Astrodynamics and Applications,
%   2nd ed. Norrwall, MA, USA: Kluwer Academic Publishers, 2001.
%   Code from Vallado's supporting website
%
% UPDATES:
%   MA-25Jul16: First draft
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function time_relJDepoch_REF_days = ymdhms2jd(time_REF_wholeyears,  ...
                                              time_REF_monthofyear, ...
                                              time_REF_dayofmonth,  ...
                                              time_REF_hrofday,     ...
                                              time_REF_minofhr,     ...
                                              time_REF_secofmin)
  %#codegen
  % Perform conversion
  time_relJDepoch_REF_days = ...
    367 * time_REF_wholeyears  ...
    - floor((7 * (time_REF_wholeyears + floor((time_REF_monthofyear + 9) / 12))) /4)   ...
    + floor(275 * time_REF_monthofyear / 9) ...
    + time_REF_dayofmonth + 1721013.5  ...
    + ((time_REF_secofmin / 60 + time_REF_minofhr) / 60 + time_REF_hrofday) / 24;
  
end


