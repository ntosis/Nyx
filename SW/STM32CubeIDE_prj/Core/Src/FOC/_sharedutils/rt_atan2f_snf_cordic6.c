/*
 * File: rt_atan2f_snf_cordic6.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:39:22 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_atan2f_snf_cordic6.h"

real32_T rt_atan2f_snf_cordic6(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T u3[6];
  real32_T xAcc;
  real32_T yAcc;
  boolean_T y_quad_adjust;
  boolean_T y_nonzero;
  boolean_T x_quad_adjust;
  real32_T xtmp;
  real32_T ytmp;
  int16_T idx;
  int32_T idx_0;
  static const real32_T atan2_cordicLUT_n6_f[6] = { 0.785398185F, 0.463647604F,
    0.244978666F, 0.124354996F, 0.062418811F, 0.0312398337F };

  for (idx_0 = 0; idx_0 < 6; idx_0++) {
    u3[idx_0] = atan2_cordicLUT_n6_f[idx_0];
  }

  if (u0 < 0.0F) {
    yAcc = -u0;
    y_quad_adjust = true;
    y_nonzero = true;
  } else {
    yAcc = u0;
    y_quad_adjust = false;
    y_nonzero = (u0 > 0.0F);
  }

  if (u1 < 0.0F) {
    xAcc = -u1;
    x_quad_adjust = true;
  } else {
    xAcc = u1;
    x_quad_adjust = false;
  }

  y = 0.0F;
  xtmp = xAcc;
  ytmp = yAcc;
  for (idx_0 = 0; idx_0 < 6; idx_0++) {
    idx = (int16_T)(idx_0 + 1);
    if (yAcc < 0.0F) {
      xAcc -= ytmp;
      yAcc += xtmp;
      y -= u3[idx - 1];
    } else {
      xAcc += ytmp;
      yAcc -= xtmp;
      y += u3[idx - 1];
    }

    xtmp = ldexpf(xAcc, -idx);
    ytmp = ldexpf(yAcc, -idx);
  }

  if (y_nonzero) {
    if (x_quad_adjust) {
      if (y_quad_adjust) {
        y -= 3.14159274F;
      } else {
        y = 3.14159274F - y;
      }
    } else {
      if (y_quad_adjust) {
        y = -y;
      }
    }
  } else if (x_quad_adjust) {
    y = 3.14159274F;
  } else {
    y = 0.0F;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
