/*
 * File: ADCRawToIab.c
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 24 13:10:49 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADCRawToIab.h"
#include "ADCRawToIab_private.h"
#include "div_s32_floor.h"
#include "look1_is16bs16n2lu32n1_UXA9sfNQ.h"
#include "look1_iu16lu32n16ts16D_2s4GBl96.h"

/* Output and update for referenced model: 'ADCRawToIab' */
void ADCRawToIab(int16_T *rty_Ia, int16_T *rty_Ib)
{
  int32_T tmp;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/adcBuffer'
   *  Lookup_n-D: '<Root>/1-D Lookup Table'
   *  Lookup_n-D: '<Root>/1-D Lookup Table3'
   */



  tmp = div_s32_floor(look1_is16bs16n2lu32n1_UXA9sfNQ
                      (look1_iu16lu32n16ts16D_2s4GBl96(adcBuffer[0],
    rtCP_uDLookupTable3_bp01Data, rtCP_uDLookupTable3_tableData, 1U),
                       (&(ComparatorBrkPnt[0])), (&(VoltageOut[0])), 2U) << 6,
                      DRV_SHUNTR_OHM);
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

  /* Product: '<Root>/Divide5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Inport: '<Root>/adcBuffer'
   *  Lookup_n-D: '<Root>/1-D Lookup Table1'
   *  Lookup_n-D: '<Root>/1-D Lookup Table2'
   */
  tmp = div_s32_floor(look1_is16bs16n2lu32n1_UXA9sfNQ
                      (look1_iu16lu32n16ts16D_2s4GBl96(adcBuffer[1],
    rtCP_uDLookupTable2_bp01Data, rtCP_uDLookupTable2_tableData, 1U),
                       (&(ComparatorBrkPnt[0])), (&(VoltageOut[0])), 2U) << 6,
                      DRV_SHUNTR_OHM);
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
