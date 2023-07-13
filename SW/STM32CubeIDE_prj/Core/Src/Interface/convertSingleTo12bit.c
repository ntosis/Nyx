/*
 * File: convertSingleTo12bit.c
 *
 * Code generated for Simulink model 'convertSingleTo12bit'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 30 23:02:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "convertSingleTo12bit.h"
#include "rtwtypes.h"
#include "convertSingleTo12bit_private.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Exported data definition */

/* Definition for custom storage class: Reusable */
real32_T in_theta;                     /* '<Root>/Inport' */

/* External outputs (root outports fed by signals with default storage) */
ExtY_convertSingleTo12bit_T convertSingleTo12bit_Y;

/* Real-time model */
static RT_MODEL_convertSingleTo12bit_T convertSingleTo12bit_M_;
RT_MODEL_convertSingleTo12bit_T *const convertSingleTo12bit_M =
  &convertSingleTo12bit_M_;
uint16_T look1_iflftu16Df_binlcpw(real32_T u0, const real32_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T v;
  uint32_T iLeft;
  uint16_T yL_0d0;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  frac *= (real32_T)table[iLeft + 1U] - (real32_T)yL_0d0;
  v = fabsf(frac);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      frac = floorf(frac + 0.5F);
    } else {
      frac *= 0.0F;
    }
  }

  if (rtIsNaNF(frac) || rtIsInfF(frac)) {
    frac = 0.0F;
  } else {
    frac = fmodf(frac, 65536.0F);
  }

  return (uint16_T)((uint32_T)(uint16_T)(frac < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-frac : (int32_T)(uint16_T)frac) + yL_0d0);
}

/* Model step function */
void convertSingleTo12bit_step(void)
{
  /* Outport: '<Root>/Outport' incorporates:
   *  Inport: '<Root>/Inport'
   *  Lookup_n-D: '<Root>/n-D Lookup Table'
   */
  convertSingleTo12bit_Y.Outport = look1_iflftu16Df_binlcpw(in_theta,
    convertSingleTo12bit_ConstP.nDLookupTable_bp01Data,
    convertSingleTo12bit_ConstP.nDLookupTable_tableData, 1U);
}

/* Model initialize function */
void convertSingleTo12bit_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void convertSingleTo12bit_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
