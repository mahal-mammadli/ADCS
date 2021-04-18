%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert date expressed in MJD2000 to juilan date
% 
% Description: 
%   converts mjd2000 time in days to a juilian date time by changing epochs
%   mjd2000 can typically used as a reference so conversion is common)
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [ time_relJDepoch_REF_days ] = mjd2000tojd( time_relMJD2000epoch_REF_days )

  JDepochtoMJDepoch_days = 2400000.5; % Vallado p.187         
  MJDepochtoMJD2000epoch_days = 51544;
  JDepochtoMJD2000epoch_days =JDepochtoMJDepoch_days + MJDepochtoMJD2000epoch_days;
  
  time_relJDepoch_REF_days = time_relMJD2000epoch_REF_days + JDepochtoMJD2000epoch_days;
  
end

