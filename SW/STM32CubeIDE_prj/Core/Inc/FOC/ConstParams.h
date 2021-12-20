/*
 * File: ConstParams.h
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Apr 30 10:12:45 2021
 */

#ifndef RTW_HEADER_ConstParams_h_
#define RTW_HEADER_ConstParams_h_
#include "rtwtypes.h"

/* Const memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Const */
extern const int16_T ADC_V_OUT[4097];

/* fixdt(1,16,2^-10,0) */
extern const int16_T BrkPoints[3];

/* fixdt(1,16,2^-8,0) */
extern const int8_T DRV_GAIN;

/* fixdt(1,8,2^-1,0) */
extern const int16_T DRV_SHUNTR_OHM;

/* fixdt(1,16,2^-15,0) */
extern const uint8_T DRV_V_REF_Div2;

/* fixdt(1,8,2^-5,0) */
extern const int32_T EMFobsLdGain;

/* (1/L) = 100.000

   fixdt(1,32,2^-12,0) */
extern const int16_T EMFobsRS;

/* fixdt(1,16,2^-8,0) */
extern const int16_T TqToIqConst;

/* fixdt(1,16,2^-8,0)
   Val=2/(3*p*psim) */
extern const int8_T dSoll;

/* int8 */
extern const int16_T d_q_Voltage_Limiter_sat_neg;

/* fixdt(1,16,2^-4,0) */
extern const int16_T d_q_Voltage_Limiter_sat_pos;

/* fixdt(1,16,2^-4,0) */
#endif                                 /* RTW_HEADER_ConstParams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
