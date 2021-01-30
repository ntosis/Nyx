/*
 * File: mul_s32_hiSR.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 24 13:11:13 2021
 */

#include "rtwtypes.h"
#include "mul_wide_s32.h"
#include "mul_s32_hiSR.h"

int32_T mul_s32_hiSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi >> aShift;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
