function [pos_BCI, vel_BCI, fdi_rmod_i, fdi_slr_i] = kep2rv(sma, ecc, incl, raan, argp, tano, mu_cst, zero_tol)
  %#codegen 
 
  Or_BCI  = zeros(3,1);
  P_BCI   = zeros(3,1);
  Q_BCI   = zeros(3,1);
  pos_BCI = zeros(3,1);
  vel_BCI = zeros(3,1);
  
  alat = tano +argp;                  % Eq 2.3-1 from Bate  et. al.
  cosalat = cos(alat);
  sinalat = sin(alat);
  cosraan = cos(raan);
  sinraan = sin(raan);
  cosincl = cos(incl);
  sinincl = sin(incl);
  
  % FDI flags is initially zero and then set to one if any problems.
  fdi_rmod_i = 0; 
  fdi_slr_i  = 0; 
  
  % ---- Routine ----
  eccsq = ecc*ecc;
  
  if (eccsq < zero_tol)     % If smaller than zero assumes zero as for circular orbit (no FDI flags required)
    ecc  = 0.0;
    slr  = sma;          % sma*(1.0-eccsq) = sma*(1.0-0.0) = sma
  else
    ecc  = sqrt(eccsq);
    slr  = sma*(1.0 - eccsq);  % Eq 1.5-6 from Bate  et. al.
  end;
  
  % Precompute (1 + e* cos(tano))
  ecostano1 = 1.0 + ecc*cos(tano) ;
  
  % Compute norm of position
  if (abs(ecostano1) < zero_tol)
    fdi_rmod_i = 1;
    rmod       = sma;
  else
    rmod       = slr/ecostano1;  % eq 1.5-4 from Bate  et. al.
  end;
  
  % Precompute sqrt(mu/slr)
  if (slr < zero_tol)
    fdi_slr_i = 1;
    v_temp    = 7.5;
  else
    v_temp    = sqrt(mu_cst/slr); %NOTE this is not the velocity of a circular orbit so it is not vmod
  end;
  
  % Compute inertial coordinates of the Orbital unit vectors
  Or_BCI(1) = cosalat*cosraan - sinalat*sinraan*cosincl;
  Or_BCI(2) = cosalat*sinraan + sinalat*cosraan*cosincl;
  Or_BCI(3) = sinalat*sinincl;
  
  % Compute inertial coordinates of the Perifocal (PQW frame) unit vectors
  % PQW_BCI is equivalent to ORB_BCI with alat replaced by argp
  cosargp = cos(argp);
  sinargp = sin(argp);
  
  P_BCI(1)  = cosargp*cosraan - sinargp*sinraan*cosincl;
  P_BCI(2)  = cosargp*sinraan + sinargp*cosraan*cosincl;
  P_BCI(3)  = sinargp*sinincl;
  
  Q_BCI(1) = -sinargp*cosraan - cosargp*sinraan*cosincl;
  Q_BCI(2) = -sinargp*sinraan + cosargp*cosraan*cosincl;
  Q_BCI(3) =  cosargp*sinincl;
  
  % Compute inertial position
  pos_BCI(1) = rmod*Or_BCI(1);
  pos_BCI(2) = rmod*Or_BCI(2);
  pos_BCI(3) = rmod*Or_BCI(3);
  
  % Compute inertial velocity as per Jdel eq 2.52 alternativly [6][3] of http://ccar.colorado.edu/asen5050/projects/projects_2010/doyle/Introduction.html
  % Compute rate of change as true anomaly is varied for P and Q frame rotations
  Pmod = -v_temp * sin(tano);
  Qmod =  v_temp * (ecc + cos(tano));
  
  vel_BCI(1) = Pmod*P_BCI(1) + Qmod*Q_BCI(1);
  vel_BCI(2) = Pmod*P_BCI(2) + Qmod*Q_BCI(2);
  vel_BCI(3) = Pmod*P_BCI(3) + Qmod*Q_BCI(3);
end

