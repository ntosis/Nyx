/*
 * File: SafetyChecks.c
 *
 * Code generated for Simulink model 'SafetyChecks'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:25:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SafetyChecks.h"
#include "SafetyChecks_private.h"
#include "InterfaceBswApp.h"

/* Output and update for referenced model: 'SafetyChecks' */
void SafetyChecks(const int16_T rtu_Iab[2], DW_SafetyChecks_f_T *localDW)
{
  uint16_T rtb_UnitDelay1;
  int16_T rtb_Constant;
  uint16_T tmp;
  uint16_T tmp_0;
  int16_T rtu_Iab_0;
  int16_T rtu_Iab_1;

  /* Sum: '<Root>/Add' */
  rtb_Constant = (int16_T)(-rtu_Iab[0] - rtu_Iab[1]);

  /* Abs: '<Root>/Abs' */
  if (rtb_Constant < 0) {
    rtb_Constant = (int16_T)-rtb_Constant;
  }

  /* End of Abs: '<Root>/Abs' */

  /* Constant: '<S1>/Constant' */
  rtb_UnitDelay1 = MaximumCurrentBeforeReaction;
  if (MaximumCurrentBeforeReaction > 32767) {
    rtb_UnitDelay1 = 32767U;
  }

  /* Constant: '<S2>/Constant' */
  tmp = MaximumCurrentBeforeReaction;
  if (MaximumCurrentBeforeReaction > 32767) {
    tmp = 32767U;
  }

  /* Constant: '<S3>/Constant' */
  tmp_0 = MaximumCurrentBeforeReaction;
  if (MaximumCurrentBeforeReaction > 32767) {
    tmp_0 = 32767U;
  }

  /* Abs: '<Root>/Abs1' */
  if (rtu_Iab[0] < 0) {
    rtu_Iab_0 = (int16_T)-rtu_Iab[0];
  } else {
    rtu_Iab_0 = rtu_Iab[0];
  }

  /* End of Abs: '<Root>/Abs1' */

  /* Abs: '<Root>/Abs2' */
  if (rtu_Iab[1] < 0) {
    rtu_Iab_1 = (int16_T)-rtu_Iab[1];
  } else {
    rtu_Iab_1 = rtu_Iab[1];
  }

  /* End of Abs: '<Root>/Abs2' */

  /* Outputs for Enabled SubSystem: '<Root>/delay error reaction' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Logic: '<Root>/OR' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  if ((rtb_Constant > rtb_UnitDelay1) || (rtu_Iab_0 > tmp) || (rtu_Iab_1 > tmp_0))
  {
    /* UnitDelay: '<S4>/Unit Delay1' */
    rtb_UnitDelay1 = localDW->UnitDelay1_DSTATE;

    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S4>/Unit Delay1'
     */
    localDW->UnitDelay1_DSTATE++;

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    emergency_disable_hardware(rtb_UnitDelay1 >= 4);
  }

  /* End of Logic: '<Root>/OR' */
  /* End of Outputs for SubSystem: '<Root>/delay error reaction' */
}

/* Model initialize function */
void SafetyChecks_initialize(const char_T **rt_errorStatus,
  RT_MODEL_SafetyChecks_T *const SafetyChecks_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(SafetyChecks_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
