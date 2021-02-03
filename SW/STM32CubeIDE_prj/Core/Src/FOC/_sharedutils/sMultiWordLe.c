/*
 * File: sMultiWordLe.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 31 10:36:33 2021
 */

#include "rtwtypes.h"
#include "sMultiWordCmp.h"
#include "sMultiWordLe.h"

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
