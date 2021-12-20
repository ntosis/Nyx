/*
 * File: ADCRawToIab.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Mar 30 15:54:58 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCRawToIab.h"
#include "ADCRawToIab_private.h"
#include "div_s32_floor.h"

volatile int16_t MAX_Ia=0;
volatile int16_t MAX_Ib=0;
volatile int16_t MIN_Ia=0;
volatile int16_t MIN_Ib=0;
/* Output and update for referenced model: 'ADCRawToIab' */
void ADCRawToIab(int16_T *rty_Ia, int16_T *rty_Ib)
{
  uint16_T tmp;
  int32_T tmp_0;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  tmp_0 = (DRV_GAIN * DRV_SHUNTR_OHM) >> 6;
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
   *  Inport: '<Root>/adcBuffer'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (adcBuffer[0] < 4096) {
    tmp = adcBuffer[0];
  } else {
    tmp = 4096U;
  }

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *  Product: '<Root>/Divide2'
   *  Sum: '<Root>/Add'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  tmp_0 = div_s32_floor((int16_T)((DRV_V_REF_Div2 << 5) - ADC_V_OUT[tmp]) << 8,
                        tmp_0);
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  *rty_Ia = (int16_T)tmp_0;

  /* End of Product: '<Root>/Divide1' */

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  tmp_0 = (DRV_GAIN * DRV_SHUNTR_OHM) >> 6;
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1' incorporates:
   *  Inport: '<Root>/adcBuffer'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (adcBuffer[1] < 4096) {
    tmp = adcBuffer[1];
  } else {
    tmp = 4096U;
  }

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)1'
   *  Product: '<Root>/Divide4'
   *  Sum: '<Root>/Add1'
   *
   * About '<Root>/Direct Lookup Table (n-D)1':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  tmp_0 = div_s32_floor((int16_T)((DRV_V_REF_Div2 << 5) - ADC_V_OUT[tmp]) << 8,
                        tmp_0);
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  *rty_Ib = (int16_T)tmp_0;

   if(*rty_Ia > MAX_Ia) {MAX_Ia=*rty_Ia;}
   if(*rty_Ib > MAX_Ib) {MAX_Ib=*rty_Ib;}
   if(*rty_Ia < MIN_Ia) {MIN_Ia=*rty_Ia;}
   if(*rty_Ib < MIN_Ib) {MIN_Ib=*rty_Ib;}

  /* End of Product: '<Root>/Divide3' */
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
