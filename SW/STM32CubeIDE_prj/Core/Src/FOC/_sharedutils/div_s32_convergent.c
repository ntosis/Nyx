/*
 * File: div_s32_convergent.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:24:27 2022
 */

#include "rtwtypes.h"
#include "div_s32_convergent.h"

int32_T div_s32_convergent(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    tempAbsQuotient = absNumerator / absDenominator;
    absNumerator %= absDenominator;
    absNumerator <<= 1U;
    if ((absNumerator > absDenominator) || ((absNumerator == absDenominator) &&
         ((tempAbsQuotient & 1U) != 0U))) {
      tempAbsQuotient++;
    }

    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */