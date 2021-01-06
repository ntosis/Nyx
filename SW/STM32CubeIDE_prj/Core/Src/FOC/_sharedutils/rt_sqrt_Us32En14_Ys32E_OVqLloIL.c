/*
 * File: rt_sqrt_Us32En14_Ys32E_OVqLloIL.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Dec 29 14:13:06 2020
 */

#include "rtwtypes.h"
#include "multiword_types.h"
#include "sLong2MultiWord.h"
#include "sMultiWordLe.h"
#include "sMultiWordMul.h"
#include "sMultiWordShl.h"
#include "rt_sqrt_Us32En14_Ys32E_OVqLloIL.h"

int32_T rt_sqrt_Us32En14_Ys32E_OVqLloIL(int32_T u)
{
  int32_T y;
  int32_T tmp01_y;
  int32_T shiftMask;
  int64m_T tmp03_u;
  int32_T iBit;
  int64m_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0) {
    y = 0;
    shiftMask = 1073741824;
    sLong2MultiWord(u, &tmp.chunks[0U], 2);
    sMultiWordShl(&tmp.chunks[0U], 2, 14U, &tmp03_u.chunks[0U], 2);
    for (iBit = 0; iBit < 31; iBit++) {
      tmp01_y = y | shiftMask;
      tmp_0 = (uint32_T)tmp01_y;
      tmp_1 = (uint32_T)tmp01_y;
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);
      if (sMultiWordLe(&tmp.chunks[0U], &tmp03_u.chunks[0U], 2)) {
        y = tmp01_y;
      }

      shiftMask = (int32_T)((uint32_T)shiftMask >> 1U);
    }
  } else {
    y = 0;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
