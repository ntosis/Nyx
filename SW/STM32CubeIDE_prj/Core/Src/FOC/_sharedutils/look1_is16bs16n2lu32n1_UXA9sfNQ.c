/*
 * File: look1_is16bs16n2lu32n1_UXA9sfNQ.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 31 10:36:12 2021
 */

#include "rtwtypes.h"
#include "div_nzp_repeat_u32.h"
#include "look1_is16bs16n2lu32n1_UXA9sfNQ.h"

int16_T look1_is16bs16n2lu32n1_UXA9sfNQ(int16_T u0, const int16_T bp0[], const
  int16_T table[], uint32_T maxIndex)
{
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  int16_T uCast;

  /* Column-major Lookup 1-D
     Canonical function name: look1_is16bs16n2lu32n16ts16Ds32_binlcs
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 > 8191) {
    uCast = MAX_int16_T;
  } else if (u0 <= -8192) {
    uCast = MIN_int16_T;
  } else {
    uCast = (int16_T)(u0 << 2);
  }

  if ((u0 << 2) < bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (uCast < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (uCast < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = div_nzp_repeat_u32(((uint32_T)u0 << 2) - bp0[iLeft], (uint16_T)
      (bp0[iLeft + 1U] - bp0[iLeft]), 16U);
  } else {
    iLeft = maxIndex - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  return (int16_T)((int16_T)(((table[iLeft + 1U] - table[iLeft]) * (int32_T)frac)
    >> 16) + table[iLeft]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
