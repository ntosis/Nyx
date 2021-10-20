%% Machine Parameters
Pmax = 88;      % Maximum power                      [W]
Tmax = 0.28;        % Maximum torque                     [N*m]
Ld   = 0.193e-4; % Stator d-axis inductance           [H]
Lq   = 0.193e-4; % Stator q-axis inductance           [H]
L0   = 0.01e-4; % Stator zero-sequence inductance    [H]
Rs   = 0.022;   % Stator resistance per phase        [Ohm]
cBackEMF = 0.015;  % Back EMF Constant     [V/rad/sec]
%1 volt per rad / s = 104.72 v / krpm
cBackEMF_VKPRM = cBackEMF * 104.72;
p    = 8/2;          % Number of pole pairs, BE CAREFUL PAIRS not Poles
Jm   = 0.0000008;  % Rotor inertia                      [Kg*m^2]
Vnom = 12;
Ts=250.0e-06;
psim = cBackEMF/p; %magnet flux linkage $\psi_m$