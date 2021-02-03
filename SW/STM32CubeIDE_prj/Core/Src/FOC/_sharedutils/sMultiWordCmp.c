/*
 * File: sMultiWordCmp.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 31 10:36:33 2021
 */

#include "rtwtypes.h"
#include "sMultiWordCmp.h"

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T u2i;
  uint32_T su1;
  int32_T i;
  su1 = u1[n - 1] & 2147483648U;
  if (((u2[n - 1] & 2147483648U) ^ su1) != 0U) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
