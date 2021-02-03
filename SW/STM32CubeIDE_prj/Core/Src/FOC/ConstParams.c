/*
 * File: ConstParams.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Jan 18 11:43:29 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "multiword_types.h"
#include "MotorControlLibNEWFixedP_FULL19b_types.h"

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T ADC_RES = 16384;

/* fixdt(1,16,2^-2,0) */ //-10.39 | 10.39
const int16_T BrkPoints[3] = { -2660, 0, 2660 } ;

/* fixdt(1,16,2^-8,0) */
const int16_T ComparatorBrkPnt[3] = { 0, 6758, 13517  } ;

/* fixdt(1,16,2^-4,0) */
const int8_T DRV_GAIN = 20;

/* fixdt(1,8,2^-1,0) */
const int16_T DRV_SHUNTR_OHM = 33;

/* fixdt(1,16,2^-15,0) */
const int8_T DRV_V_REF = 106;

/* fixdt(1,8,2^-5,0) */
const int32_T EMFobsLdGain = 42;
const int32_T  Ld = 42;

/* fixdt(1,32,2^-22,0) */
const int16_T EMFobsRS = 179;
const int32_T  Rs = 2933;

/* fixdt(1,16,2^-8,0) */
const int8_T MaxBckEMFVol_sat_neg = -24;

/* fixdt(1,8,2^-1,0) */
const int8_T MaxBckEMFVol_sat_pos = 24;

/* fixdt(1,8,2^-1,0) */
const int16_T TqToIqConst = 11378;

/* fixdt(1,16,2^-8,0) */
const int16_T VoltageOut[3] = { 2458, 0, -2458  } ;

/* fixdt(1,16,2^-10,0) */
const int8_T dSoll = 0;

/* int8 */
const int16_T d_q_Voltage_Limiter_sat_neg = -166;

/* fixdt(1,16,2^-4,0) */
const int16_T d_q_Voltage_Limiter_sat_pos = 166;

/* fixdt(1,16,2^-4,0) */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
