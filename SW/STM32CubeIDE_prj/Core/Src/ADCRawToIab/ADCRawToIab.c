/*
 * File: ADCRawToIab.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Dec 29 13:39:40 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCRawToIab.h"
#include "ADCRawToIab_private.h"
#include "div_s32_floor.h"
#include "look1_is16bs16p8lu32n1_8EtRrfdo.h"
// Manual include TODO remove it
#include "main.h"
/* Output and update for referenced model: 'ADCRawToIab' */
void ADCRawToIab(int16_T *rty_Ia, int16_T *rty_Ib)
{
  uint32_T tmp;
  int32_T tmp_0;
  uint16_T tmp_1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/adcBuffer'
   */
  if (((int8_T)DRV_V_REF) <= 0) {
    tmp_1 = 0U;
  } else {
    tmp_1 = (uint16_T)(((int8_T)DRV_V_REF) << 9);
  }

  tmp = ((uint32_T)tmp_1 * adcBuffer[0]) >> 12;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   */
  tmp_0 = div_s32_floor((int32_T)tmp << 12, ((int16_T)ADC_RES));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* Product: '<Root>/Divide1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Lookup_n-D: '<Root>/1-D Lookup Table'
   *  Product: '<Root>/Divide'
   */
  tmp_0 = div_s32_floor(look1_is16bs16p8lu32n1_8EtRrfdo((int16_T)tmp_0,
    (&(ComparatorBrkPnt[0])), (&(VoltageOut[0])), 2U) << 3, ((int8_T)DRV_GAIN));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Product: '<Root>/Divide1'
   */
  tmp_0 = div_s32_floor(tmp_0 << 11, ((int16_T)DRV_SHUNTR_OHM));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  *rty_Ia = (int16_T)tmp_0;

  /* End of Product: '<Root>/Divide2' */

  /* Gain: '<Root>/Gain1' incorporates:
   *  Inport: '<Root>/adcBuffer'
   */
  if (((int8_T)DRV_V_REF) <= 0) {
    tmp_1 = 0U;
  } else {
    tmp_1 = (uint16_T)(((int8_T)DRV_V_REF) << 9);
  }

  tmp = ((uint32_T)tmp_1 * adcBuffer[1]) >> 12;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  /* Product: '<Root>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain1'
   */
  tmp_0 = div_s32_floor((int32_T)tmp << 12, ((int16_T)ADC_RES));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* Product: '<Root>/Divide4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Lookup_n-D: '<Root>/1-D Lookup Table1'
   *  Product: '<Root>/Divide3'
   */
  tmp_0 = div_s32_floor(look1_is16bs16p8lu32n1_8EtRrfdo((int16_T)tmp_0,
    (&(ComparatorBrkPnt[0])), (&(VoltageOut[0])), 2U) << 3, ((int8_T)DRV_GAIN));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  /* Product: '<Root>/Divide5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Product: '<Root>/Divide4'
   */
  tmp_0 = div_s32_floor(tmp_0 << 11, ((int16_T)DRV_SHUNTR_OHM));
  if (tmp_0 > 32767) {
    tmp_0 = 32767;
  } else {
    if (tmp_0 < -32768) {
      tmp_0 = -32768;
    }
  }

  *rty_Ib = (int16_T)tmp_0;

  /* End of Product: '<Root>/Divide5' */
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
