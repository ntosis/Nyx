/*
 * File: ConstParams.h
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Jan 18 11:43:29 2021
 */

#ifndef RTW_HEADER_ConstParams_h_
#define RTW_HEADER_ConstParams_h_
#include "rtwtypes.h"

/* Const memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Const */
extern const int16_T ADC_RES;

/* fixdt(1,16,2^-2,0) */
extern const int16_T BrkPoints[3];

/* fixdt(1,16,2^-8,0) */
extern const int16_T ComparatorBrkPnt[3];

/* fixdt(1,16,2^-4,0) */
extern const int8_T DRV_GAIN;

/* fixdt(1,8,2^-1,0) */
extern const int16_T DRV_SHUNTR_OHM;

/* fixdt(1,16,2^-15,0) */
extern const int8_T DRV_V_REF;

/* fixdt(1,8,2^-5,0) */
extern const int32_T EMFobsLdGain;
extern const int32_T  Ld;
extern const int32_T  Rs;

/* fixdt(1,32,2^-22,0) */
extern const int16_T EMFobsRS;

/* fixdt(1,16,2^-8,0) */
extern const int8_T MaxBckEMFVol_sat_neg;

/* fixdt(1,8,2^-1,0) */
extern const int8_T MaxBckEMFVol_sat_pos;

/* fixdt(1,8,2^-1,0) */
extern const int16_T TqToIqConst;

/* fixdt(1,16,2^-8,0) */
extern const int16_T VoltageOut[3];

/* fixdt(1,16,2^-10,0) */
extern const int16_T VphMax;

/* fixdt(1,16,2^-8,0) */
extern const int8_T dSoll;

/* int8 */
extern const int16_T d_q_Voltage_Limiter_sat_neg;

/* fixdt(1,16,2^-4,0) */
extern const int16_T d_q_Voltage_Limiter_sat_pos;

/* fixdt(1,16,2^-4,0) */
extern const int16_T RShunt_table_data_out[4097];

#endif                                 /* RTW_HEADER_ConstParams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
