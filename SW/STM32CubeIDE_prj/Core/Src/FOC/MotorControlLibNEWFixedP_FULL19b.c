/*
 * File: MotorControlLibNEWFixedP_FULL19b.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Feb  3 12:55:42 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorControlLibNEWFixedP_FULL19b.h"
#include "MotorControlLibNEWFixedP_FULL19b_private.h"
#include "InterfaceBswApp.h"
#include "look1_is16lu32n16tu16_binlcse.h"
#include "mul_s32_hiSR.h"
#include "rt_atan2f_snf.h"

/* Exported block signals */
boolean_T enableFluxobs;               /* '<Root>/Inport2' */
boolean_T set_AngleInput=1;              /* '<Root>/Inport1' */
int16_T Sig_theta_el_m;                /* '<Root>/Delay' */
int16_T Sig_Ia_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ib_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ibeta_m;                   /* '<S1>/one_by_sqrt3' */
int16_T Sig_qAxis_m;                   /* '<Root>/Gain3' */
int16_T Sig_qAxis_errorSum_m;          /* '<S5>/Add1' */
int16_T Sig_dAxis_m;                   /* '<Root>/Gain2' */
int16_T Sig_dAxis_errorSum_m;          /* '<S5>/Add' */
int16_T constantAngle;                 /* '<S119>/Discrete-Time Integrator' */
int16_T Sig_Va_m;                      /* '<Root>/Gain' */
int16_T Sig_Vb_m;                      /* '<Root>/Gain1' */
int16_T FluxObsAngle;                  /* '<S15>/PositionGain' */
int16_T Sig_qAxis_PI_out;              /* '<S64>/Saturation' */
int16_T Sig_dAxis_PI_out;              /* '<S108>/Saturation' */

/* Exported block parameters */
int16_T Ki_dAxis = 0;                  /* Variable: Ki_dAxis
                                        * Referenced by: '<S5>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Ki_qAxis = 0;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S5>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_dAxis = 32;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S5>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_qAxis = 32;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S5>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
int8_T qSoll = 26;                     /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,8,2^-7,0)
                                        */

/* Block signals (default storage) */
B_MotorControlLibNEWFixedP_FU_T MotorControlLibNEWFixedP_FULL_B;

/* Block states (default storage) */
DW_MotorControlLibNEWFixedP_F_T MotorControlLibNEWFixedP_FUL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_MotorControlLibNEWFix_T MotorControlLibNEWFixed_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MotorControlLibNEWFixedP_T MotorControlLibNEWFixedP_FULL_Y;

/* Real-time model */
RT_MODEL_MotorControlLibNEWFi_T MotorControlLibNEWFixedP_FUL_M_;
RT_MODEL_MotorControlLibNEWFi_T *const MotorControlLibNEWFixedP_FUL_M =
  &MotorControlLibNEWFixedP_FUL_M_;

/* Output and update for enable system: '<Root>/FluxObsAngle' */
void MotorControlLibNEW_FluxObsAngle(boolean_T rtu_Enable, int16_T rtu_In1,
  int16_T rtu_In2, int16_T rtu_In3, int16_T rtu_In4, int16_T *rty_FluxObsAngle,
  B_FluxObsAngle_MotorControlLi_T *localB, const ConstB_FluxObsAngle_MotorCont_T
  *localC, DW_FluxObsAngle_MotorControlL_T *localDW,
  ZCE_FluxObsAngle_MotorControl_T *localZCE)
{
  int16_T rtb_DataTypeConversion;
  real32_T tmp;
  int16_T tmp_0;

  /* Outputs for Enabled SubSystem: '<Root>/FluxObsAngle' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtu_Enable) {
    /* Delay: '<S18>/Delay' */
    if ((localZCE->Delay_Reset_ZCE == POS_ZCSIG) && (localZCE->Delay_Reset_ZCE
         != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE = 0;
    }

    localZCE->Delay_Reset_ZCE = 0U;

    /* Gain: '<S24>/ScalingR' */
    if (EMFobsRS > 127) {
      rtb_DataTypeConversion = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_DataTypeConversion = MIN_int16_T;
    } else {
      rtb_DataTypeConversion = (int16_T)(EMFobsRS << 8);
    }

    /* Sum: '<S18>/Sum' incorporates:
     *  Delay: '<S18>/Delay'
     *  Gain: '<S18>/Gain'
     *  Gain: '<S24>/ScalingR'
     *  Sum: '<S18>/Sum3'
     */
    localDW->Delay_DSTATE = (int16_T)((((int16_T)(rtu_In2 -
      ((rtb_DataTypeConversion * rtu_In4) >> 16)) * 16777) >> 22) +
      localDW->Delay_DSTATE);

    /* Delay: '<S17>/Delay' */
    if ((localZCE->Delay_Reset_ZCE_o == POS_ZCSIG) &&
        (localZCE->Delay_Reset_ZCE_o != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE_e = 0;
    }

    localZCE->Delay_Reset_ZCE_o = 0U;

    /* Gain: '<S23>/ScalingR' */
    if (EMFobsRS > 127) {
      rtb_DataTypeConversion = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_DataTypeConversion = MIN_int16_T;
    } else {
      rtb_DataTypeConversion = (int16_T)(EMFobsRS << 8);
    }

    /* Sum: '<S17>/Sum' incorporates:
     *  Delay: '<S17>/Delay'
     *  Gain: '<S17>/Gain'
     *  Gain: '<S23>/ScalingR'
     *  Sum: '<S17>/Sum3'
     */
    localDW->Delay_DSTATE_e = (int16_T)((((int16_T)(rtu_In1 -
      ((rtb_DataTypeConversion * rtu_In3) >> 16)) * 16777) >> 22) +
      localDW->Delay_DSTATE_e);

    /* Gain: '<S24>/ScalingL' incorporates:
     *  Gain: '<S23>/ScalingL'
     *  Switch: '<S17>/Switch'
     *  Switch: '<S18>/Switch'
     */
    if (EMFobsLdGain > 63) {
      rtb_DataTypeConversion = MAX_int16_T;
      tmp_0 = MAX_int16_T;
    } else if (EMFobsLdGain <= -64) {
      rtb_DataTypeConversion = MIN_int16_T;
      tmp_0 = MIN_int16_T;
    } else {
      rtb_DataTypeConversion = (int16_T)(EMFobsLdGain << 9);
      tmp_0 = (int16_T)(EMFobsLdGain << 9);
    }

    /* Outputs for Atomic SubSystem: '<S15>/atan2' */
    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion1'
     *  DataTypeConversion: '<S16>/Data Type Conversion2'
     *  Delay: '<S17>/Delay'
     *  Delay: '<S18>/Delay'
     *  Gain: '<S23>/ScalingL'
     *  Gain: '<S24>/ScalingL'
     *  Sum: '<S17>/Sum1'
     *  Sum: '<S18>/Sum1'
     *  Switch: '<S17>/Switch'
     *  Switch: '<S18>/Switch'
     *  Trigonometry: '<S16>/Atan2'
     */
    tmp = floorf(rt_atan2f_snf((real32_T)(int16_T)(localDW->Delay_DSTATE -
      (((rtb_DataTypeConversion * rtu_In4) >> 31) << 4)) * 0.000244140625F,
      (real32_T)(int16_T)(localDW->Delay_DSTATE_e - (((tmp_0 * rtu_In3) >> 31) <<
      4)) * 0.000244140625F) * 4096.0F);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = fmodf(tmp, 65536.0F);
    }

    rtb_DataTypeConversion = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

    /* Outputs for Enabled SubSystem: '<S16>/If Action Subsystem' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (localC->Compare) {
      /* Inport: '<S21>/In1' */
      localB->Merge = rtb_DataTypeConversion;
    }

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S16>/per Uint' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (localC->Compare_l) {
      /* Gain: '<S22>/Gain' */
      localB->Merge = (int16_T)((20861 * rtb_DataTypeConversion) >> 17);

      /* Switch: '<S22>/Switch' incorporates:
       *  Bias: '<S22>/Bias'
       */
      if (localB->Merge < 0) {
        localB->Merge = (int16_T)(localB->Merge + 4096);
      }

      /* End of Switch: '<S22>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S16>/per Uint' */

    /* Gain: '<S15>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S16>/a16'
     */
    *rty_FluxObsAngle = (int16_T)((3217 * localB->Merge) >> 13);

    /* End of Outputs for SubSystem: '<S15>/atan2' */
  }

  /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */
}

/* Model step function */
void MotorControlLibNEWFixedP_FULL19b_step(void)
{
  int32_T rowIdx;
  int32_T rowIdx_0;
  uint16_T rtb_uDLookupTable2;
  boolean_T rtb_Uk1_c;
  boolean_T rtb_NotEqual;
  int16_T rtb_SignPreSat_e;
  int16_T rtb_convert_pu;
  int16_T rtb_Sum6;
  int16_T rtb_Sum4;
  int16_T rtb_sum_alpha;
  int16_T rtb_add_c;
  uint32_T rtb_Sum_idx_3;

  /* Delay: '<Root>/Delay' */
  Sig_theta_el_m = MotorControlLibNEWFixedP_FULL_Y.Position;

  /* Gain: '<S11>/convert_pu' */
  rtb_convert_pu = (int16_T)((20861 * Sig_theta_el_m) >> 17);

  /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
   *  ActionPort: '<S13>/Action Port'
   */
  /* If: '<S11>/If' incorporates:
   *  DataTypeConversion: '<S13>/Convert_back'
   *  DataTypeConversion: '<S13>/Convert_uint16'
   *  Sum: '<S13>/Sum'
   */
  rtb_convert_pu = (int16_T)(rtb_convert_pu - ((rtb_convert_pu >> 8) << 8));

  /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */

  /* Gain: '<S9>/indexing' */
  rtb_Sum6 = (int16_T)(100 * rtb_convert_pu);

  /* DataTypeConversion: '<S9>/Get_Integer' */
  rtb_uDLookupTable2 = (uint16_T)(rtb_Sum6 >> 6);

  /* Sum: '<S9>/Sum' */
  rtb_Sum_idx_3 = rtb_uDLookupTable2 + 100U;

  /* CombinatorialLogic: '<S124>/Logic' incorporates:
   *  Constant: '<Root>/q Soll'
   *  Memory: '<S124>/Memory'
   *  RelationalOperator: '<S120>/Compare'
   *  UnitDelay: '<S118>/Unit Delay'
   */
  rowIdx = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
                       MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE) << 1) +
                     MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput);

  /* UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Uk1_c = MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE;

  /* UnitDelay: '<S118>/Unit Delay1' incorporates:
   *  UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE =
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m;

  /* Outputs for Enabled SubSystem: '<S118>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S122>/Enable'
   */
  /* CombinatorialLogic: '<S124>/Logic' */
  if (rtCP_Logic_table[(uint32_T)rowIdx]) {
    /* RelationalOperator: '<S126>/FixPt Relational Operator' incorporates:
     *  Constant: '<Root>/q Soll'
     *  UnitDelay: '<S126>/Delay Input1'
     *
     * Block description for '<S126>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator = (qSoll !=
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h);

    /* Update for UnitDelay: '<S126>/Delay Input1' incorporates:
     *  Constant: '<Root>/q Soll'
     *
     * Block description for '<S126>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h = qSoll;
  }

  /* End of Outputs for SubSystem: '<S118>/Enabled Subsystem' */

  /* Memory: '<S125>/Memory' incorporates:
   *  UnitDelay: '<S118>/Unit Delay'
   */
  MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE =
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b;

  /* CombinatorialLogic: '<S125>/Logic' incorporates:
   *  RelationalOperator: '<S121>/FixPt Relational Operator'
   *  UnitDelay: '<S118>/Unit Delay'
   *  UnitDelay: '<S121>/Delay Input1'
   *
   * Block description for '<S121>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rowIdx_0 = (int32_T)(((((uint32_T)
    MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator << 1) + ((int32_T)
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE < (int32_T)rtb_Uk1_c)) <<
                        1) + MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE);

  /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
   *  Inport: '<Root>/Inport'
   */
  ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

  /* DataTypeConversion: '<S9>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  Sum: '<S9>/Sum2'
   */
  rtb_Sum4 = (int16_T)((int16_T)(rtb_Sum6 - (int16_T)((int16_T)
    rtb_uDLookupTable2 << 6)) << 2);

  /* Sum: '<S10>/Sum6' incorporates:
   *  Constant: '<S9>/sine_table_values'
   *  Product: '<S10>/Product1'
   *  Selector: '<S9>/Lookup'
   *  Sum: '<S10>/Sum5'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sum6 = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
    [(int32_T)(rtb_uDLookupTable2 + 101U)] - rtCP_sine_table_values_Value
    [(int32_T)rtb_Sum_idx_3]) * rtb_Sum4) >> 8) + rtCP_sine_table_values_Value
                       [(int32_T)rtb_Sum_idx_3]);

  /* Gain: '<S1>/one_by_sqrt3' incorporates:
   *  Sum: '<S1>/a_plus_2b'
   */
  Sig_Ibeta_m = (int16_T)(((int16_T)((int16_T)(Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m) *
    18919) >> 15);

  /* Sum: '<S10>/Sum4' incorporates:
   *  Constant: '<S9>/sine_table_values'
   *  Product: '<S10>/Product'
   *  Selector: '<S9>/Lookup'
   *  Sum: '<S10>/Sum3'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sum4 = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
    [(int32_T)(rtb_uDLookupTable2 + 1U)] -
    rtCP_sine_table_values_Value[rtb_uDLookupTable2]) * rtb_Sum4) >> 8) +
                       rtCP_sine_table_values_Value[rtb_uDLookupTable2]);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Product: '<S7>/asin'
   *  Product: '<S7>/bcos'
   *  Sum: '<S7>/sum_Qs'
   */
  Sig_qAxis_m = (int16_T)((int16_T)((Sig_Ibeta_m * rtb_Sum6) >> 8) - (int16_T)
    ((Sig_Ia_m * rtb_Sum4) >> 8));

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<Root>/q Soll'
   *  Gain: '<Root>/Tq--> iqRef'
   */
  Sig_qAxis_errorSum_m = (int16_T)(((int8_T)((TqToIqConst * qSoll) >> 8) << 1) -
    Sig_qAxis_m);

  /* Sum: '<S66>/Sum' incorporates:
   *  Constant: '<S5>/Constant4'
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Product: '<S62>/PProd Out'
   */
  rtb_convert_pu = (int16_T)((int16_T)((Sig_qAxis_errorSum_m * Kp_qAxis) >> 6) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Saturate: '<S64>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 4095) {
    Sig_qAxis_PI_out = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
    Sig_qAxis_PI_out = MIN_int16_T;
  } else {
    Sig_qAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
  }

  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_add_c = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_add_c = MIN_int16_T;
  } else {
    rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_convert_pu > rtb_add_c) {
    Sig_qAxis_PI_out = rtb_add_c;
  } else {
    if (rtb_convert_pu >= Sig_qAxis_PI_out) {
      Sig_qAxis_PI_out = rtb_convert_pu;
    }
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Gain: '<Root>/Gain5' */
  rtb_sum_alpha = (int16_T)(Sig_qAxis_PI_out << 1);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Product: '<S7>/acos'
   *  Product: '<S7>/bsin'
   *  Sum: '<S7>/sum_Ds'
   */
  Sig_dAxis_m = (int16_T)((int16_T)((Sig_Ia_m * rtb_Sum6) >> 8) + (int16_T)
    ((Sig_Ibeta_m * rtb_Sum4) >> 8));

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<Root>/d Soll'
   */
  Sig_dAxis_errorSum_m = (int16_T)((dSoll << 8) - Sig_dAxis_m);

  /* Sum: '<S110>/Sum' incorporates:
   *  Constant: '<S5>/Constant6'
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Product: '<S106>/PProd Out'
   */
  rtb_SignPreSat_e = (int16_T)((int16_T)((Sig_dAxis_errorSum_m * Kp_dAxis) >> 6)
    + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o);

  /* Saturate: '<S108>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 4095) {
    Sig_dAxis_PI_out = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
    Sig_dAxis_PI_out = MIN_int16_T;
  } else {
    Sig_dAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
  }

  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_add_c = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_add_c = MIN_int16_T;
  } else {
    rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_SignPreSat_e > rtb_add_c) {
    Sig_dAxis_PI_out = rtb_add_c;
  } else {
    if (rtb_SignPreSat_e >= Sig_dAxis_PI_out) {
      Sig_dAxis_PI_out = rtb_SignPreSat_e;
    }
  }

  /* End of Saturate: '<S108>/Saturation' */

  /* Gain: '<Root>/Gain4' */
  rtb_add_c = (int16_T)(Sig_dAxis_PI_out << 1);

  /* Switch: '<S117>/Switch' incorporates:
   *  Product: '<S4>/dcos'
   *  Product: '<S4>/dsin'
   *  Product: '<S4>/qcos'
   *  Product: '<S4>/qsin'
   *  Sum: '<S4>/sum_alpha'
   *  Sum: '<S4>/sum_beta'
   *  Switch: '<S25>/Switch'
   */
  Sig_Va_m = (int16_T)((int16_T)((rtb_add_c * rtb_Sum6) >> 8) - (int16_T)
                       ((rtb_sum_alpha * rtb_Sum4) >> 8));
  Sig_Vb_m = (int16_T)((int16_T)((rtb_sum_alpha * rtb_Sum6) >> 8) + (int16_T)
                       ((rtb_add_c * rtb_Sum4) >> 8));

  /* Outputs for Enabled SubSystem: '<Root>/FluxObsAngle' */
  /* Inport: '<Root>/Inport2' */
  MotorControlLibNEW_FluxObsAngle(enableFluxobs, Sig_Va_m, Sig_Vb_m, Sig_Ia_m,
    Sig_Ibeta_m, &FluxObsAngle, &MotorControlLibNEWFixedP_FULL_B.FluxObsAngle_k,
    &MotorControlLibNEWFixedP_ConstB.FluxObsAngle_k,
    &MotorControlLibNEWFixedP_FUL_DW.FluxObsAngle_k,
    &MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k);

  /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */

  /* UnitDelay: '<S119>/Unit Delay' */
  rtb_Uk1_c = MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p;

  /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
   *  UnitDelay: '<S119>/Unit Delay'
   */
  if (MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p &&
      (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = 0;
  }

  constantAngle = MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Inport: '<Root>/Inport1'
   */
  if (set_AngleInput) {
    MotorControlLibNEWFixedP_FULL_Y.Position = constantAngle;
  } else {
    MotorControlLibNEWFixedP_FULL_Y.Position = FluxObsAngle;
  }

  /* End of Switch: '<Root>/Switch' */

  /* RelationalOperator: '<S119>/Relational Operator' incorporates:
   *  UnitDelay: '<S119>/Unit Delay'
   */
  MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p = (constantAngle >= 1608);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S6>/1-D Lookup Table'
   */
  set_PWM_A_DT(look1_is16lu32n16tu16_binlcse(Sig_Va_m, (&(BrkPoints[0])),
    rtCP_uDLookupTable_tableData, 2U));

  /* Gain: '<S116>/one_by_two' */
  rtb_add_c = (int16_T)(Sig_Va_m >> 1);

  /* Gain: '<S116>/sqrt3_by_two' */
  rtb_Sum6 = (int16_T)((14189 * Sig_Vb_m) >> 14);

  /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S6>/1-D Lookup Table1'
   *  Sum: '<S116>/add_b'
   */
  set_PWM_B_DT(look1_is16lu32n16tu16_binlcse((int16_T)(rtb_Sum6 - rtb_add_c),
    (&(BrkPoints[0])), rtCP_uDLookupTable1_tableData, 2U));

  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S6>/1-D Lookup Table2'
   *  Sum: '<S116>/add_c'
   */
  set_PWM_C_DT(look1_is16lu32n16tu16_binlcse((int16_T)(-rtb_add_c - rtb_Sum6), (
    &(BrkPoints[0])), rtCP_uDLookupTable2_tableData, 2U));

  /* DeadZone: '<S94>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_add_c = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_add_c = MIN_int16_T;
  } else {
    rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_SignPreSat_e > rtb_add_c) {
    if (d_q_Voltage_Limiter_sat_pos > 4095) {
      rtb_add_c = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
      rtb_add_c = MIN_int16_T;
    } else {
      rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
    }

    rtb_SignPreSat_e -= rtb_add_c;
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 4095) {
      rtb_add_c = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
      rtb_add_c = MIN_int16_T;
    } else {
      rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
    }

    if (rtb_SignPreSat_e >= rtb_add_c) {
      rtb_SignPreSat_e = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 4095) {
        rtb_add_c = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
        rtb_add_c = MIN_int16_T;
      } else {
        rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
      }

      rtb_SignPreSat_e -= rtb_add_c;
    }
  }

  /* End of DeadZone: '<S94>/DeadZone' */

  /* RelationalOperator: '<S94>/NotEqual' */
  rtb_NotEqual = (0 != rtb_SignPreSat_e);

  /* Signum: '<S94>/SignPreSat' */
  if (rtb_SignPreSat_e < 0) {
    rtb_SignPreSat_e = -1;
  } else {
    rtb_SignPreSat_e = (int16_T)(rtb_SignPreSat_e > 0);
  }

  /* End of Signum: '<S94>/SignPreSat' */

  /* Product: '<S98>/IProd Out' incorporates:
   *  Constant: '<S5>/Constant7'
   */
  rtb_add_c = (int16_T)((Sig_dAxis_errorSum_m * Ki_dAxis) >> 6);

  /* Signum: '<S94>/SignPreIntegrator' */
  if (rtb_add_c < 0) {
    rtb_Sum6 = -1;
  } else {
    rtb_Sum6 = (int16_T)(rtb_add_c > 0);
  }

  /* End of Signum: '<S94>/SignPreIntegrator' */

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S94>/Constant1'
   *  DataTypeConversion: '<S94>/DataTypeConv1'
   *  DataTypeConversion: '<S94>/DataTypeConv2'
   *  Logic: '<S94>/AND3'
   *  RelationalOperator: '<S94>/Equal1'
   */
  if (rtb_NotEqual && (rtb_SignPreSat_e == rtb_Sum6)) {
    rtb_SignPreSat_e = 0;
  } else {
    rtb_SignPreSat_e = rtb_add_c;
  }

  /* End of Switch: '<S94>/Switch' */

  /* DeadZone: '<S50>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_add_c = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_add_c = MIN_int16_T;
  } else {
    rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_convert_pu > rtb_add_c) {
    if (d_q_Voltage_Limiter_sat_pos > 4095) {
      rtb_add_c = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
      rtb_add_c = MIN_int16_T;
    } else {
      rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
    }

    rtb_convert_pu -= rtb_add_c;
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 4095) {
      rtb_add_c = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
      rtb_add_c = MIN_int16_T;
    } else {
      rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
    }

    if (rtb_convert_pu >= rtb_add_c) {
      rtb_convert_pu = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 4095) {
        rtb_add_c = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
        rtb_add_c = MIN_int16_T;
      } else {
        rtb_add_c = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
      }

      rtb_convert_pu -= rtb_add_c;
    }
  }

  /* End of DeadZone: '<S50>/DeadZone' */

  /* RelationalOperator: '<S50>/NotEqual' */
  rtb_NotEqual = (0 != rtb_convert_pu);

  /* Signum: '<S50>/SignPreSat' */
  if (rtb_convert_pu < 0) {
    rtb_convert_pu = -1;
  } else {
    rtb_convert_pu = (int16_T)(rtb_convert_pu > 0);
  }

  /* End of Signum: '<S50>/SignPreSat' */

  /* Product: '<S54>/IProd Out' incorporates:
   *  Constant: '<S5>/Constant5'
   */
  rtb_add_c = (int16_T)((Sig_qAxis_errorSum_m * Ki_qAxis) >> 6);

  /* Outputs for Enabled SubSystem: '<S118>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S123>/Enable'
   */
  /* CombinatorialLogic: '<S125>/Logic' */
  if (rtCP_Logic_table_m[(uint32_T)rowIdx_0]) {
    /* UnitDelay: '<S123>/Unit Delay1' */
    rtb_uDLookupTable2 = MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE;

    /* Sum: '<S123>/Add' incorporates:
     *  Constant: '<S123>/Constant'
     *  UnitDelay: '<S123>/Unit Delay1'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE++;

    /* RelationalOperator: '<S123>/Relational Operator' incorporates:
     *  Constant: '<S123>/Constant1'
     *  UnitDelay: '<S118>/Unit Delay1'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m = (rtb_uDLookupTable2 <=
      10000);
  }

  /* End of Outputs for SubSystem: '<S118>/Enabled Subsystem1' */

  /* Update for UnitDelay: '<S118>/Unit Delay' incorporates:
   *  CombinatorialLogic: '<S125>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE = rtCP_Logic_table_m
    [(uint32_T)rowIdx_0];

  /* Update for Memory: '<S124>/Memory' incorporates:
   *  CombinatorialLogic: '<S124>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput = rtCP_Logic_table
    [(uint32_T)rowIdx];

  /* Update for Memory: '<S125>/Memory' incorporates:
   *  CombinatorialLogic: '<S125>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b = rtCP_Logic_table_m
    [(uint32_T)rowIdx_0];

  /* Signum: '<S50>/SignPreIntegrator' */
  if (rtb_add_c < 0) {
    rtb_Sum6 = -1;
  } else {
    rtb_Sum6 = (int16_T)(rtb_add_c > 0);
  }

  /* End of Signum: '<S50>/SignPreIntegrator' */

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant1'
   *  DataTypeConversion: '<S50>/DataTypeConv1'
   *  DataTypeConversion: '<S50>/DataTypeConv2'
   *  Logic: '<S50>/AND3'
   *  RelationalOperator: '<S50>/Equal1'
   */
  if (rtb_NotEqual && (rtb_convert_pu == rtb_Sum6)) {
    rtb_add_c = 0;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Update for DiscreteIntegrator: '<S57>/Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE = (int16_T)(((16777 *
    rtb_add_c) >> 26) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Update for DiscreteIntegrator: '<S101>/Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o = (int16_T)(((16777 *
    rtb_SignPreSat_e) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o);

  /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE += ((int16_T)
    mul_s32_hiSR(274877907, MotorControlLibNEWFixedP_ConstB.Gain, 16U));
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    rtb_Uk1_c;
}

/* Model initialize function */
void MotorControlLibNEWFixedP_FULL19b_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Model Initialize function for ModelReference Block: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab_initialize(rtmGetErrorStatusPointer(MotorControlLibNEWFixedP_FUL_M),
    &(MotorControlLibNEWFixedP_FUL_DW.ADCRAwToCurrentIabc_InstanceDat.rtm));
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE_o =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void MotorControlLibNEWFixedP_FULL19b_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
