%% Parameters for IPMSM Torque Control Example

% This example shows how to control the torque in an interior permanent
% magnet synchronous machine (IPMSM) based automotive electrical-traction 
% drive. A high-voltage battery feeds the IPMSM through a controlled three-
% phase converter. The IPMSM operates in both motoring and generating modes 
% according to the load. An ideal angular velocity source provides the 
% load. The Control subsystem uses an open-loop approach to control the 
% IPMSM torque and a closed-loop approach to control the current. At each 
% sample instant, the torque request is converted to relevant current 
% references. The current control is PI-based and uses a sample rate that 
% is faster than the rate that is used for torque control. The simulation 
% uses several torque steps in both motor and generator modes. The task 
% scheduling is designed in Stateflow(R). The Scopes subsystem 
% contains scopes that allow you to see the simulation results.

% Copyright 2016-2019 The MathWorks, Inc.

%% Machine Parameters
Pmax = 88;      % Maximum power                      [W]
Tmax = 0.28;        % Maximum torque                     [N*m]
Ld   = 0.193e-4; % Stator d-axis inductance           [H]
Lq   = 0.193e-4; % Stator q-axis inductance           [H]
L0   = 0.01e-4; % Stator zero-sequence inductance    [H]
Rs   = 0.022;   % Stator resistance per phase        [Ohm]
cBackEMF = 0.015;  % Back EMF Constant     [V/rad/sec]
p    = 8/2;          % Number of pole pairs, BE CAREFUL PAIRS not Poles
Jm   = 0.0000008;  % Rotor inertia                      [Kg*m^2]

%% High-Voltage System Parameters
Cdc  = 0.001;      % DC-link capacitor      [F]
Vnom = 12;        % Nominal DC voltage     [V] 
%V1   = 290;        % Voltage V1(< Vnom)     [V]
AH0  = 280;        % Initial battery charge [hr*A]

%% Control Parameters
Ts   = 5e-6;       % Fundamental sample time               [s]
fsw  = 10e3;       % PMSM drive switching frequency        [Hz]
Tsi  = 1e-4;       % Sample time for current control loops [s]

Kp_id = 0.8779;     % Proportional gain id controller
Ki_id = 710.3004;   % Integrator gain id controller
Kp_iq = 1.0744;     % Proportional gain iq controller
Ki_iq = 1.0615e+03; % Integrator gain iq controller

%% Zero-Cancellation Transfer Functions
numd_id = Tsi/(Kp_id/Ki_id);
dend_id = [1 (Tsi-(Kp_id/Ki_id))/(Kp_id/Ki_id)];
numd_iq = Tsi/(Kp_iq/Ki_iq);
dend_iq = [1 (Tsi-(Kp_iq/Ki_iq))/(Kp_iq/Ki_iq)];

%% Current references
%load ee_ipmsm_35kW_ref_idq;