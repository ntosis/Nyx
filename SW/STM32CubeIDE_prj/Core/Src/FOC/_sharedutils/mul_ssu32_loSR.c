/*
 * File: mul_ssu32_loSR.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b_new'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Sep 29 11:35:11 2021
 */

#include "rtwtypes.h"
#include "mul_wide_su32.h"
#include "mul_ssu32_loSR.h"

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
