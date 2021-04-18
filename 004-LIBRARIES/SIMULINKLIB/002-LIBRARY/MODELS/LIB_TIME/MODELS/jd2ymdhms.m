%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert JD to Gregorian Calendar
%
% Description
%   Converts Juilian Date to Year Month Day... using Algorithm 22 found in
%   Fundamentals of Astrodynamics (Vallado)
%   - The algorithm is only valid between years 1900 and 2100.
%   - The algorithm does not account for leap seconds or any other change
%     of time systems) e.g. UTC to UT1, or  UT2, or  BDT, or TAI.
%
% inputs:
%   time_relJDepoch_REF_days:  Julian Date (number of fractional days since 01 Jan 4713 B.C.E. @ noon)expressed in some reference time frame
%
% OUTPUTS:
%   time_REF_wholeyears  Common Era years [years]
%   time_REF_monthofyear Numerical value for the month [months]
%   time_REF_dayofmonth  Day of the month [days]
%   time_REF_hrofday     Hours of the day [h]
%   time_REF_minofhr     Minutes of the hour [min]
%   time_REF_secofmin    Seconds of the minute [s]
%   time_REF_dayofyear   Day of the year [day]
%   time_REF_secofday    Seconds of the day [s]
%
% REFERENCES:
%   David A. Vallado, Fundamentals of Astrodynamics and Applications,
%   2nd ed. Norrwall, MA, USA: Kluwer Academic Publishers, 2001, p.204.
%   Code from Vallado's supporting website
%
% Modifications:
%   MA-25Jul16: Initial draft
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [...
    time_REF_wholeyears,...
    time_REF_monthofyear,...
    time_REF_dayofmonth,...
    time_REF_hrofday,...
    time_REF_minofhr,...
    time_REF_secofmin,...
    time_REF_dayofyear,...
    time_REF_secofday ] = jd2ymdhms(time_relJDepoch_REF_days)
  %#codegen
  
  % Find year and days of the year
  temp                = time_relJDepoch_REF_days - 2415019.5;
  tu                  = temp / 365.25;
  time_REF_wholeyears = 1900 + floor(tu);
  leapyrs             = floor((time_REF_wholeyears - 1901) * 0.25);
  days                = temp - ((time_REF_wholeyears - 1900) * 365.0 + leapyrs);
  
  % Check for case of beginning of a year
  if days < 1.0
    time_REF_wholeyears    = time_REF_wholeyears - 1;
    leapyrs = floor((time_REF_wholeyears - 1901) * 0.25);
    days    = temp - ((time_REF_wholeyears - 1900) * 365.0 + leapyrs);
  end
  
  % Find remaining data
  [ time_REF_monthofyear, ...
    time_REF_dayofmonth,  ...
    time_REF_hrofday,     ...
    time_REF_minofhr,     ...
    time_REF_secofmin,    ...
    time_REF_dayofyear] = days2mdh(time_REF_wholeyears, days);
  
  time_REF_secofday = time_REF_hrofday * 3600 + time_REF_minofhr * 60 + time_REF_secofmin;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Subfunction to handle days in a month
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [mon, day, hr, minute, sec, dayofyr] = days2mdh(year, days)
  lmonth = zeros(12,1);
  
  % Set up array of days in month
  for i = 1:1:12
    lmonth(i) = 31;
    if i == 2
      lmonth(i)= 28;
    end;
    if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
      lmonth(i) = 30;
    end;
  end
  dayofyr = floor(days);
  
  % Find month and day of month
  if rem(year - 1900,4) == 0
    lmonth(2) = 29;
  end
  
  % Find month and day from day of year
  i = 1;
  inttemp = 0;
  while (dayofyr > inttemp + lmonth(i)) && (i < 12)
    inttemp = inttemp + lmonth(i);
    i = i + 1;
  end
  mon = i;
  day = dayofyr - inttemp;
  
  % Find hours minutes and seconds
  temp   = (days - dayofyr)*24.0;
  hr     = fix(temp);
  temp   = (temp - hr) * 60.0;
  minute = fix(temp);
  sec    = (temp - minute) * 60.0;
end
