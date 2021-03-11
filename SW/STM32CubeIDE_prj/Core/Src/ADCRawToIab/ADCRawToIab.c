/*
 * File: ADCRawToIab.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Feb 23 13:40:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCRawToIab.h"
#include "ADCRawToIab_private.h"
#include "div_s32_floor.h"

/* Output and update for referenced model: 'ADCRawToIab' */
void ADCRawToIab(int16_T *rty_Ia, int16_T *rty_Ib)
{
  int32_T tmp;
  uint16_T tmp_0;

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
   *  Inport: '<Root>/adcBuffer'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (adcBuffer[0] < 4096) {
    tmp_0 = adcBuffer[0];
  } else {
    tmp_0 = 4096U;
  }

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  tmp = div_s32_floor(RShunt_table_data_out[tmp_0] << 6, DRV_SHUNTR_OHM);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Product: '<Root>/Divide2'
   */
  tmp = div_s32_floor(tmp << 5, DRV_GAIN);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  *rty_Ia = (int16_T)tmp;

  /* End of Product: '<Root>/Divide1' */

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1' incorporates:
   *  Inport: '<Root>/adcBuffer'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (adcBuffer[1] < 4096) {
    tmp_0 = adcBuffer[1];
  } else {
    tmp_0 = 4096U;
  }

  /* Product: '<Root>/Divide5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  tmp = div_s32_floor(RShunt_table_data_out[tmp_0] << 6, DRV_SHUNTR_OHM);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Product: '<Root>/Divide5'
   */
  tmp = div_s32_floor(tmp << 5, DRV_GAIN);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  *rty_Ib = (int16_T)tmp;

  /* End of Product: '<Root>/Divide4' */
}

/* Model initialize function */
void ADCRawToIab_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ADCRawToIab_T *const ADCRawToIab_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ADCRawToIab_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
