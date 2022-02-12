/*
 * File: div_s16s32.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:39:22 2022
 */

#include "rtwtypes.h"
#include "div_s16s32.h"

int16_T div_s16s32(int32_T numerator, int32_T denominator)
{
  int16_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = (int16_T)(numerator >= 0 ? 32767 : -32768);

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                       numerator) / (denominator < 0 ? ~(uint32_T)denominator +
      1U : (uint32_T)denominator);
    quotient = (int16_T)((numerator < 0) != (denominator < 0) ? (int32_T)
                         (int16_T)-(int32_T)tempAbsQuotient : (int32_T)(int16_T)
                         tempAbsQuotient);
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
