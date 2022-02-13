/*
 * File: CalcSpinSpeednDir.c
 *
 * Code generated for Simulink model 'CalcSpinSpeednDir'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Feb  4 14:24:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CalcSpinSpeednDir.h"
#include "CalcSpinSpeednDir_private.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define CalcSpinS_IN_MotorWasInRotation ((uint8_T)1U)
#define CalcSpinSpee_IN_MotorWasStalled ((uint8_T)2U)
#define CalcSpinSpee_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define CalcSpinSpeednD_IN_ValidSignal1 ((uint8_T)2U)
#define CalcSpinSpeednDir_IN_noTimeout ((uint8_T)1U)
#define CalcSpinSpeednDir_IN_timeout   ((uint8_T)2U)
#define CalcSpinSpeedn_IN_InvalidSignal ((uint8_T)1U)

/* Output and update for referenced model: 'CalcSpinSpeednDir' */
void CalcSpinSpeednDir(const real32_T *rtu_Theta, B_CalcSpinSpeednDir_c_T
  *localB, DW_CalcSpinSpeednDir_f_T *localDW)
{
  real32_T rtb_Switch;
  boolean_T rtb_rightDirFlag;
  boolean_T rtb_NOT;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_h;
  real32_T rtb_Invertsignalinputifmotorspi;
  int32_T tmp;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay1'
   *  Sum: '<S2>/Add4'
   */
  rtb_rightDirFlag = (localDW->TappedDelay1_X[1] - localDW->TappedDelay1_X[0] >
                      0.0F);

  /* Logic: '<S2>/NOT' */
  rtb_NOT = !rtb_rightDirFlag;

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay1'
   *  Sum: '<S2>/Add5'
   */
  rtb_Compare_f = (localDW->TappedDelay1_X[2] - localDW->TappedDelay1_X[1] >
                   0.0F);

  /* Sum: '<S2>/Add6' incorporates:
   *  S-Function (sfix_udelay): '<S2>/Tapped Delay1'
   */
  rtb_Switch = *rtu_Theta - localDW->TappedDelay1_X[2];

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_Compare_h = (rtb_Switch > 0.0F);

  /* Logic: '<S2>/AND' */
  rtb_rightDirFlag = (rtb_rightDirFlag && rtb_Compare_f && rtb_Compare_h);

  /* Logic: '<S2>/AND3' incorporates:
   *  Constant: '<S7>/Constant'
   *  Logic: '<S2>/AND1'
   *  Logic: '<S2>/AND2'
   *  Logic: '<S2>/NOT1'
   *  Logic: '<S2>/NOT2'
   *  Logic: '<S2>/NOT4'
   *  RelationalOperator: '<S7>/Compare'
   */
  rtb_NOT = ((!(rtb_Switch == 0.0F)) && ((boolean_T)((rtb_NOT && (!rtb_Compare_f)
    && (!rtb_Compare_h)) ^ rtb_rightDirFlag)));

  /* Chart: '<Root>/Chart1' incorporates:
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  if (localDW->is_active_c7_CalcSpinSpeednDir == 0U) {
    localDW->is_active_c7_CalcSpinSpeednDir = 1U;
    if (!rtb_NOT) {
      localDW->is_c7_CalcSpinSpeednDir = CalcSpinSpeedn_IN_InvalidSignal;
      tmp = localDW->count + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      localDW->count = (uint8_T)tmp;
      localDW->is_InvalidSignal = CalcSpinSpeednDir_IN_noTimeout;
      if (Sig_rpm != 0.0F) {
        localDW->is_noTimeout = CalcSpinS_IN_MotorWasInRotation;
        localB->setOutput = Sig_rpm;
      } else {
        localDW->is_noTimeout = CalcSpinSpee_IN_MotorWasStalled;
        localB->setOutput = 0.0;
      }
    } else {
      localDW->is_c7_CalcSpinSpeednDir = CalcSpinSpeednD_IN_ValidSignal1;
    }
  } else if (localDW->is_c7_CalcSpinSpeednDir == CalcSpinSpeedn_IN_InvalidSignal)
  {
    if (rtb_NOT) {
      localDW->is_noTimeout = CalcSpinSpee_IN_NO_ACTIVE_CHILD;
      localDW->is_InvalidSignal = CalcSpinSpee_IN_NO_ACTIVE_CHILD;
      localDW->is_c7_CalcSpinSpeednDir = CalcSpinSpeednD_IN_ValidSignal1;
    } else if (localDW->is_InvalidSignal == CalcSpinSpeednDir_IN_noTimeout) {
      if (localDW->count > 3) {
        localDW->is_noTimeout = CalcSpinSpee_IN_NO_ACTIVE_CHILD;
        localDW->is_InvalidSignal = CalcSpinSpeednDir_IN_timeout;
        localB->setOutput = 0.0;
      } else {
        tmp = localDW->count + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        localDW->count = (uint8_T)tmp;
        if (localDW->is_noTimeout == CalcSpinS_IN_MotorWasInRotation) {
          localB->setOutput = Sig_rpm;
        } else {
          /* case IN_MotorWasStalled: */
          localB->setOutput = 0.0;
        }
      }
    } else {
      /* case IN_timeout: */
    }
  } else {
    /* case IN_ValidSignal1: */
    if (!rtb_NOT) {
      localDW->is_c7_CalcSpinSpeednDir = CalcSpinSpeedn_IN_InvalidSignal;
      tmp = localDW->count + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      localDW->count = (uint8_T)tmp;
      localDW->is_InvalidSignal = CalcSpinSpeednDir_IN_noTimeout;
      if (Sig_rpm != 0.0F) {
        localDW->is_noTimeout = CalcSpinS_IN_MotorWasInRotation;
        localB->setOutput = Sig_rpm;
      } else {
        localDW->is_noTimeout = CalcSpinSpee_IN_MotorWasStalled;
        localB->setOutput = 0.0;
      }
    } else {
      localDW->count = 0U;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Switch: '<Root>/Invert signal input if motor spins to left' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Sum: '<Root>/Add4'
   */
  if (rtb_rightDirFlag) {
    rtb_Invertsignalinputifmotorspi = *rtu_Theta;
  } else {
    rtb_Invertsignalinputifmotorspi = 6.28318548F - *rtu_Theta;
  }

  /* End of Switch: '<Root>/Invert signal input if motor spins to left' */

  /* Sum: '<Root>/Add2' incorporates:
   *  Sum: '<Root>/Add3'
   *  Switch: '<Root>/Switch'
   *  UnitDelay: '<Root>/Unit Delay2'
   */
  rtb_Switch = rtb_Invertsignalinputifmotorspi - localDW->UnitDelay2_DSTATE;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sum: '<Root>/Add2'
   *  Sum: '<Root>/Add3'
   */
  if (!(rtb_Switch >= 0.0F)) {
    rtb_Switch += 6.28318548F;
  }

  /* Product: '<Root>/Dth//dt' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   */
  Sig_rpm = rtb_Switch / ((real32_T)p * 2.38418579E-7F) / 0.0002F;

  /* RateLimiter: '<Root>/Rate Limiter' */
  rtb_Switch = Sig_rpm - localDW->PrevY;
  if (rtb_Switch > 10.0F) {
    Sig_rpm = localDW->PrevY + 10.0F;
  } else {
    if (rtb_Switch < -10.0F) {
      Sig_rpm = localDW->PrevY + -10.0F;
    }
  }

  localDW->PrevY = Sig_rpm;

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* UnitConversion: '<Root>/Unit Conversion' */
  /* Unit Conversion - from: rad/sec to: rpm
     Expression: output = (9.5493*input) + (0) */
  Sig_rpm *= 9.54929638F;

  /* Switch: '<Root>/Switch1' */
  if (!rtb_NOT) {
    Sig_rpm = (real32_T)localB->setOutput;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* UnitConversion: '<Root>/Unit Conversion1' */
  /* Unit Conversion - from: rpm to: rad/sec
     Expression: output = (0.10472*input) + (0) */
  Sig_Angular_Velocity_radpsec_m = 0.104719758F * Sig_rpm;

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
  localDW->TappedDelay1_X[0] = localDW->TappedDelay1_X[1];
  localDW->TappedDelay1_X[1] = localDW->TappedDelay1_X[2];
  localDW->TappedDelay1_X[2] = *rtu_Theta;

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  localDW->UnitDelay2_DSTATE = rtb_Invertsignalinputifmotorspi;
}

/* Model initialize function */
void CalcSpinSpeednDir_initialize(const char_T **rt_errorStatus,
  RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(CalcSpinSpeednDir_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
