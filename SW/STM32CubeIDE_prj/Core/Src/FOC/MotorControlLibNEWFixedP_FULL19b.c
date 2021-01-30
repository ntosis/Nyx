/*
 * File: MotorControlLibNEWFixedP_FULL19b.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Jan 22 15:30:32 2021
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
#include "rt_sqrt_Us32En14_Ys32E_OVqLloIL.h"

/* Exported block signals */
int16_T Sig_theta_el_m;                /* '<Root>/Delay' */
int16_T Sig_Ia_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ib_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_dAxis_m;                   /* '<Root>/Gain2' */
int16_T Sig_dAxis_errorSum_m;          /* '<S4>/Add' */
int16_T Sig_qAxis_m;                   /* '<Root>/Gain3' */
int16_T Sig_qAxis_errorSum_m;          /* '<S4>/Add1' */
int16_T Sig_Vqsatu_m;                  /* '<S9>/Multiport Switch1' */
int16_T Sig_Vdsatu_m;                  /* '<S9>/Multiport Switch' */
int16_T Sig_Va_m;                      /* '<Root>/Gain' */
int16_T Sig_Vb_m;                      /* '<Root>/Gain1' */
int16_T Sig_Emfobs_errorSum_m;         /* '<S109>/Add6' */
int16_T Sig_dAxis_PI_out;              /* '<S99>/Saturation' */
int16_T Sig_qAxis_PI_out;              /* '<S55>/Saturation' */
int16_T Sig_Emfobs_PI_out;             /* '<S149>/Saturation' */

/* Exported block parameters */
int16_T Ki_Iab_EMFobs = 0;             /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S139>/Integral Gain'
                                        *   '<S184>/Integral Gain'
                                        * fixdt(1,16,2^-3,0)
                                        */
int16_T Ki_dAxis = 0;                  /* Variable: Ki_dAxis
                                        * Referenced by: '<S4>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Ki_qAxis = 0;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S4>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_dAxis = 32;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S4>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_qAxis = 32;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S4>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_Iab_EMFobs = 256;           /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S147>/Proportional Gain'
                                        *   '<S192>/Proportional Gain'
                                        * fixdt(1,16,2^-8,0)
                                        */
int8_T qSoll = 26;                     /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,8,2^-7,0)
                                        */

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T VphMax = 1772;

/* fixdt(1,16,2^-8,0)
   Val = Vnom*(1/sqrt(3)) */

/* Block signals (default storage) */
B_MotorControlLibNEWFixedP_FU_T MotorControlLibNEWFixedP_FULL_B;

/* Block states (default storage) */
DW_MotorControlLibNEWFixedP_F_T MotorControlLibNEWFixedP_FUL_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MotorControlLibNEWFixedP_T MotorControlLibNEWFixedP_FULL_Y;

/* Real-time model */
RT_MODEL_MotorControlLibNEWFi_T MotorControlLibNEWFixedP_FUL_M_;
RT_MODEL_MotorControlLibNEWFi_T *const MotorControlLibNEWFixedP_FUL_M =
  &MotorControlLibNEWFixedP_FUL_M_;

/* Model step function */
void MotorControlLibNEWFixedP_FULL19b_step(void)
{
  int32_T rowIdx;
  int32_T rowIdx_0;
  uint16_T rtb_uDLookupTable2;
  boolean_T rtb_UnitDelay1_b;
  int16_T rtb_SignPreSat_o;
  boolean_T rtb_NotEqual_a;
  int16_T rtb_SignPreSat_m;
  int16_T rtb_convert_pu;
  int16_T rtb_Add6;
  int16_T rtb_one_by_sqrt3;
  int16_T rtb_SignChange_p;
  int16_T rtb_add_c;
  int32_T rtb_Sqrt;
  uint32_T rtb_Sum_idx_3;
  real32_T tmp;
  int16_T rtb_IntegralGain_0;
  int32_T tmp_0;
  int32_T tmp_1;

  /* Delay: '<Root>/Delay' */
  Sig_theta_el_m = MotorControlLibNEWFixedP_FULL_Y.Position;

  /* Gain: '<S12>/convert_pu' */
  rtb_convert_pu = (int16_T)((20861 * Sig_theta_el_m) >> 17);

  /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
   *  ActionPort: '<S14>/Action Port'
   */
  /* If: '<S12>/If' incorporates:
   *  DataTypeConversion: '<S14>/Convert_back'
   *  DataTypeConversion: '<S14>/Convert_uint16'
   *  Sum: '<S14>/Sum'
   */
  rtb_convert_pu = (int16_T)(rtb_convert_pu - ((rtb_convert_pu >> 8) << 8));

  /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */

  /* Gain: '<S10>/indexing' */
  rtb_Add6 = (int16_T)(100 * rtb_convert_pu);

  /* DataTypeConversion: '<S10>/Get_Integer' */
  rtb_uDLookupTable2 = (uint16_T)(rtb_Add6 >> 6);

  /* Sum: '<S10>/Sum' */
  rtb_Sum_idx_3 = rtb_uDLookupTable2 + 100U;

  /* CombinatorialLogic: '<S213>/Logic' incorporates:
   *  Constant: '<Root>/q Soll'
   *  Memory: '<S213>/Memory'
   *  RelationalOperator: '<S209>/Compare'
   *  UnitDelay: '<S207>/Unit Delay'
   */
  rowIdx = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
                       MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE) << 1) +
                     MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput);

  /* Outputs for Enabled SubSystem: '<S207>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S211>/Enable'
   */
  if (rtCP_Logic_table[(uint32_T)rowIdx]) {
    /* RelationalOperator: '<S215>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S215>/Delay Input1'
     *
     * Block description for '<S215>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator = (qSoll !=
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h);

    /* Update for UnitDelay: '<S215>/Delay Input1'
     *
     * Block description for '<S215>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h = qSoll;
  }

  /* End of Outputs for SubSystem: '<S207>/Enabled Subsystem' */

  /* UnitDelay: '<S207>/Unit Delay1' */
  rtb_UnitDelay1_b = MotorControlLibNEWFixedP_FULL_B.RelationalOperator;

  /* Memory: '<S214>/Memory' incorporates:
   *  UnitDelay: '<S207>/Unit Delay'
   */
  MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE =
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b;

  /* CombinatorialLogic: '<S214>/Logic' incorporates:
   *  RelationalOperator: '<S210>/FixPt Relational Operator'
   *  UnitDelay: '<S207>/Unit Delay'
   *  UnitDelay: '<S207>/Unit Delay1'
   *  UnitDelay: '<S210>/Delay Input1'
   *
   * Block description for '<S210>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rowIdx_0 = (int32_T)(((((uint32_T)
    MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator << 1) + ((int32_T)
    MotorControlLibNEWFixedP_FULL_B.RelationalOperator < (int32_T)
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE)) << 1) +
                       MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE);

  /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
   *  Inport: '<Root>/Inport'
   */
  ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);


  /* DataTypeConversion: '<S10>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  Sum: '<S10>/Sum2'
   */
  rtb_SignPreSat_m = (int16_T)((int16_T)(rtb_Add6 - (int16_T)((int16_T)
    rtb_uDLookupTable2 << 6)) << 2);

  /* Sum: '<S11>/Sum6' incorporates:
   *  Constant: '<S10>/sine_table_values'
   *  Product: '<S11>/Product1'
   *  Selector: '<S10>/Lookup'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S11>/Sum5'
   */
  rtb_Add6 = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
    [(int32_T)(rtb_uDLookupTable2 + 101U)] - rtCP_sine_table_values_Value
    [(int32_T)rtb_Sum_idx_3]) * rtb_SignPreSat_m) >> 8) +
                       rtCP_sine_table_values_Value[(int32_T)rtb_Sum_idx_3]);

  /* Gain: '<S1>/one_by_sqrt3' incorporates:
   *  Sum: '<S1>/a_plus_2b'
   */
  rtb_one_by_sqrt3 = (int16_T)(((int16_T)((int16_T)(Sig_Ia_m + Sig_Ib_m) +
    Sig_Ib_m) * 18919) >> 15);

  /* Sum: '<S11>/Sum4' incorporates:
   *  Constant: '<S10>/sine_table_values'
   *  Product: '<S11>/Product'
   *  Selector: '<S10>/Lookup'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S11>/Sum3'
   */
  rtb_SignPreSat_m = (int16_T)((int16_T)(((int16_T)
    (rtCP_sine_table_values_Value[(int32_T)(rtb_uDLookupTable2 + 1U)] -
     rtCP_sine_table_values_Value[rtb_uDLookupTable2]) * rtb_SignPreSat_m) >> 8)
    + rtCP_sine_table_values_Value[rtb_uDLookupTable2]);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Product: '<S6>/acos'
   *  Product: '<S6>/bsin'
   *  Sum: '<S6>/sum_Ds'
   */
  Sig_dAxis_m = (int16_T)((int16_T)((Sig_Ia_m * rtb_Add6) >> 8) + (int16_T)
    ((rtb_one_by_sqrt3 * rtb_SignPreSat_m) >> 8));

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<Root>/d Soll'
   */
  Sig_dAxis_errorSum_m = (int16_T)((dSoll << 8) - Sig_dAxis_m);

  /* Sum: '<S101>/Sum' incorporates:
   *  Constant: '<S4>/Constant6'
   *  DiscreteIntegrator: '<S92>/Integrator'
   *  Product: '<S97>/PProd Out'
   */
  rtb_convert_pu = (int16_T)((int16_T)((Sig_dAxis_errorSum_m * Kp_dAxis) >> 6) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Saturate: '<S99>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 4095) {
    Sig_dAxis_PI_out = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
    Sig_dAxis_PI_out = MIN_int16_T;
  } else {
    Sig_dAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
  }

  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_convert_pu > rtb_SignChange_p) {
    Sig_dAxis_PI_out = rtb_SignChange_p;
  } else {
    if (rtb_convert_pu >= Sig_dAxis_PI_out) {
      Sig_dAxis_PI_out = rtb_convert_pu;
    }
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* Gain: '<Root>/Gain3' incorporates:
   *  Product: '<S6>/asin'
   *  Product: '<S6>/bcos'
   *  Sum: '<S6>/sum_Qs'
   */
  Sig_qAxis_m = (int16_T)((int16_T)((rtb_one_by_sqrt3 * rtb_Add6) >> 8) -
    (int16_T)((Sig_Ia_m * rtb_SignPreSat_m) >> 8));

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<Root>/q Soll'
   *  Gain: '<Root>/Tq--> iqRef'
   */
  Sig_qAxis_errorSum_m = (int16_T)(((int8_T)((TqToIqConst * qSoll) >> 8) << 1) -
    Sig_qAxis_m);

  /* Sum: '<S57>/Sum' incorporates:
   *  Constant: '<S4>/Constant4'
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Product: '<S53>/PProd Out'
   */
  rtb_SignPreSat_o = (int16_T)((int16_T)((Sig_qAxis_errorSum_m * Kp_qAxis) >> 6)
    + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m);

  /* Saturate: '<S55>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 4095) {
    Sig_qAxis_PI_out = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
    Sig_qAxis_PI_out = MIN_int16_T;
  } else {
    Sig_qAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
  }

  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_SignPreSat_o > rtb_SignChange_p) {
    Sig_qAxis_PI_out = rtb_SignChange_p;
  } else {
    if (rtb_SignPreSat_o >= Sig_qAxis_PI_out) {
      Sig_qAxis_PI_out = rtb_SignPreSat_o;
    }
  }

  /* End of Saturate: '<S55>/Saturation' */

  /* RelationalOperator: '<S219>/LowerRelop1' incorporates:
   *  RelationalOperator: '<S219>/UpperRelop'
   *  Switch: '<S216>/Switch'
   *  Switch: '<S219>/Switch2'
   */
  tmp_0 = Sig_dAxis_PI_out << 1;

  /* Switch: '<S219>/Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  RelationalOperator: '<S219>/LowerRelop1'
   */
  if (tmp_0 > VphMax) {
    rtb_add_c = (int16_T)(VphMax >> 1);
  } else {
    /* Gain: '<S9>/Sign Change' */
    rtb_SignChange_p = (int16_T)-VphMax;

    /* Switch: '<S219>/Switch' incorporates:
     *  RelationalOperator: '<S219>/UpperRelop'
     *  Switch: '<S216>/Switch'
     */
    if (tmp_0 < rtb_SignChange_p) {
      rtb_add_c = (int16_T)(rtb_SignChange_p >> 1);
    } else {
      rtb_add_c = Sig_dAxis_PI_out;
    }

    /* End of Switch: '<S219>/Switch' */
  }

  /* Sqrt: '<S9>/Sqrt' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Math: '<S9>/Math Function'
   *  Math: '<S9>/Math Function1'
   *  Sum: '<S9>/Sum4'
   */
  rtb_Sqrt = rt_sqrt_Us32En14_Ys32E_OVqLloIL(((VphMax * VphMax) >> 2) -
    rtb_add_c * rtb_add_c);

  /* RelationalOperator: '<S220>/LowerRelop1' incorporates:
   *  RelationalOperator: '<S220>/UpperRelop'
   *  Switch: '<S217>/Switch'
   *  Switch: '<S220>/Switch2'
   */
  tmp_0 = Sig_qAxis_PI_out << 7;

  /* Switch: '<S220>/Switch2' incorporates:
   *  RelationalOperator: '<S220>/LowerRelop1'
   */
  if (tmp_0 > rtb_Sqrt) {
    rtb_SignChange_p = (int16_T)(rtb_Sqrt >> 7);
  } else {
    /* Gain: '<S9>/Sign Change ' */
    rtb_Sqrt = -rtb_Sqrt;

    /* Switch: '<S220>/Switch' incorporates:
     *  RelationalOperator: '<S220>/UpperRelop'
     *  Switch: '<S217>/Switch'
     */
    if (tmp_0 < rtb_Sqrt) {
      rtb_SignChange_p = (int16_T)(rtb_Sqrt >> 7);
    } else {
      rtb_SignChange_p = Sig_qAxis_PI_out;
    }

    /* End of Switch: '<S220>/Switch' */
  }

  /* MultiPortSwitch: '<S9>/Multiport Switch1' */
  Sig_Vqsatu_m = (int16_T)(rtb_SignChange_p << 1);

  /* MultiPortSwitch: '<S9>/Multiport Switch' */
  Sig_Vdsatu_m = (int16_T)(rtb_add_c << 1);

  /* Sum: '<S109>/Add5' incorporates:
   *  Product: '<S3>/dcos'
   *  Product: '<S3>/qsin'
   *  Sum: '<S3>/sum_alpha'
   *  Switch: '<S16>/Switch'
   */
  Sig_Va_m = (int16_T)((int16_T)((Sig_Vdsatu_m * rtb_Add6) >> 8) - (int16_T)
                       ((Sig_Vqsatu_m * rtb_SignPreSat_m) >> 8));

  /* Sum: '<S110>/Add5' incorporates:
   *  Product: '<S3>/dsin'
   *  Product: '<S3>/qcos'
   *  Sum: '<S3>/sum_beta'
   *  Switch: '<S16>/Switch'
   */
  Sig_Vb_m = (int16_T)((int16_T)((Sig_Vqsatu_m * rtb_Add6) >> 8) + (int16_T)
                       ((Sig_Vdsatu_m * rtb_SignPreSat_m) >> 8));

  /* Outputs for Enabled SubSystem: '<S207>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S212>/Enable'
   */
  /* CombinatorialLogic: '<S214>/Logic' */
  if (rtCP_Logic_table_m[(uint32_T)rowIdx_0]) {
    /* UnitDelay: '<S212>/Unit Delay1' */
    rtb_uDLookupTable2 = MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE;

    /* Sum: '<S212>/Add' incorporates:
     *  Constant: '<S212>/Constant'
     *  UnitDelay: '<S212>/Unit Delay1'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE++;

    /* RelationalOperator: '<S212>/Relational Operator' incorporates:
     *  Constant: '<S212>/Constant1'
     */
    MotorControlLibNEWFixedP_FULL_B.RelationalOperator = (rtb_uDLookupTable2 <=
      10000);
  }

  /* End of Outputs for SubSystem: '<S207>/Enabled Subsystem1' */

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* Logic: '<Root>/NOT' */
  if (!MotorControlLibNEWFixedP_FULL_B.RelationalOperator) {
    if (!MotorControlLibNEWFixedP_FUL_DW.Positionobserver_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_e = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S187>/Integrator' */
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_n = 0;
      MotorControlLibNEWFixedP_FUL_DW.Positionobserver_MODE = true;
    }

    /* Sum: '<S109>/Add6' incorporates:
     *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator'
     */
    Sig_Emfobs_errorSum_m = (int16_T)
      (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_e -
       Sig_Ia_m);

    /* Gain: '<S147>/Proportional Gain' incorporates:
     *  Gain: '<S192>/Proportional Gain'
     */
    rtb_Sqrt = (Kp_Iab_EMFobs + 1) >> 1;

    /* Sum: '<S151>/Sum' incorporates:
     *  DiscreteIntegrator: '<S142>/Integrator'
     *  Gain: '<S147>/Proportional Gain'
     */
    rtb_SignPreSat_m = (int16_T)((int16_T)((rtb_Sqrt * Sig_Emfobs_errorSum_m) >>
      8) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k);

    /* Saturate: '<S149>/Saturation' incorporates:
     *  DeadZone: '<S135>/DeadZone'
     *  DeadZone: '<S180>/DeadZone'
     */
    tmp_0 = MaxBckEMFVol_sat_neg << 6;
    tmp_1 = MaxBckEMFVol_sat_pos << 6;
    if (rtb_SignPreSat_m > (int16_T)tmp_1) {
      Sig_Emfobs_PI_out = (int16_T)tmp_1;
    } else if (rtb_SignPreSat_m < (int16_T)tmp_0) {
      Sig_Emfobs_PI_out = (int16_T)tmp_0;
    } else {
      Sig_Emfobs_PI_out = rtb_SignPreSat_m;
    }

    /* Sum: '<S110>/Add6' incorporates:
     *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
     */
    rtb_Add6 = (int16_T)
      (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j -
       rtb_one_by_sqrt3);

    /* Sum: '<S196>/Sum' incorporates:
     *  DiscreteIntegrator: '<S187>/Integrator'
     *  Gain: '<S192>/Proportional Gain'
     */
    rtb_SignChange_p = (int16_T)((int16_T)((rtb_Sqrt * rtb_Add6) >> 8) +
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_n);

    /* Saturate: '<S194>/Saturation' incorporates:
     *  Saturate: '<S149>/Saturation'
     */
    if (rtb_SignChange_p > (int16_T)tmp_1) {
      rtb_one_by_sqrt3 = (int16_T)tmp_1;
    } else if (rtb_SignChange_p < (int16_T)tmp_0) {
      rtb_one_by_sqrt3 = (int16_T)tmp_0;
    } else {
      rtb_one_by_sqrt3 = rtb_SignChange_p;
    }

    /* End of Saturate: '<S194>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S111>/atan2' */
    /* DataTypeConversion: '<S202>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S202>/Data Type Conversion1'
     *  DataTypeConversion: '<S202>/Data Type Conversion2'
     *  Trigonometry: '<S202>/Atan2'
     */
    tmp = floorf(rt_atan2f_snf((real32_T)rtb_one_by_sqrt3 * 0.0078125F,
      (real32_T)Sig_Emfobs_PI_out * 0.0078125F) * 128.0F);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = fmodf(tmp, 65536.0F);
    }

    rtb_add_c = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                          -tmp : (int32_T)(int16_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S202>/Data Type Conversion' */

    /* Outputs for Enabled SubSystem: '<S202>/If Action Subsystem' incorporates:
     *  EnablePort: '<S205>/Enable'
     */
    if (MotorControlLibNEWFixedP_ConstB.Compare) {
      MotorControlLibNEWFixedP_FULL_B.Merge = rtb_add_c;
    }

    /* End of Outputs for SubSystem: '<S202>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S202>/per Uint' incorporates:
     *  EnablePort: '<S206>/Enable'
     */
    if (MotorControlLibNEWFixedP_ConstB.Compare_o) {
      /* Gain: '<S206>/Gain' */
      MotorControlLibNEWFixedP_FULL_B.Merge = (int16_T)((20861 * rtb_add_c) >>
        17);

      /* Switch: '<S206>/Switch' incorporates:
       *  Bias: '<S206>/Bias'
       */
      if (MotorControlLibNEWFixedP_FULL_B.Merge < 0) {
        MotorControlLibNEWFixedP_FULL_B.Merge = (int16_T)
          (MotorControlLibNEWFixedP_FULL_B.Merge + 128);
      }

      /* End of Switch: '<S206>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S202>/per Uint' */

    /* Gain: '<S111>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  Inport: '<S205>/In1'
     */
    MotorControlLibNEWFixedP_FULL_B.PositionGain = (int16_T)((201 *
      MotorControlLibNEWFixedP_FULL_B.Merge) >> 2);

    /* End of Outputs for SubSystem: '<S111>/atan2' */

    /* DeadZone: '<S180>/DeadZone' */
    if (rtb_SignChange_p > tmp_1) {
      rtb_SignChange_p = (int16_T)(rtb_SignChange_p - tmp_1);
    } else if (rtb_SignChange_p >= tmp_0) {
      rtb_SignChange_p = 0;
    } else {
      rtb_SignChange_p = (int16_T)(rtb_SignChange_p - tmp_0);
    }

    /* RelationalOperator: '<S180>/NotEqual' */
    rtb_NotEqual_a = (0 != rtb_SignChange_p);

    /* Signum: '<S180>/SignPreSat' */
    if (rtb_SignChange_p < 0) {
      rtb_SignChange_p = -1;
    } else {
      rtb_SignChange_p = (int16_T)(rtb_SignChange_p > 0);
    }

    /* End of Signum: '<S180>/SignPreSat' */

    /* Gain: '<S184>/Integral Gain' */
    if (Ki_Iab_EMFobs <= 0) {
      rtb_uDLookupTable2 = 0U;
    } else if (Ki_Iab_EMFobs > 16383) {
      rtb_uDLookupTable2 = MAX_uint16_T;
    } else {
      rtb_uDLookupTable2 = (uint16_T)(Ki_Iab_EMFobs << 2);
    }

    rtb_Add6 = (int16_T)((rtb_uDLookupTable2 * rtb_Add6) >> 6);

    /* End of Gain: '<S184>/Integral Gain' */

    /* Signum: '<S180>/SignPreIntegrator' */
    if (rtb_Add6 < 0) {
      rtb_IntegralGain_0 = -1;
    } else {
      rtb_IntegralGain_0 = (int16_T)(rtb_Add6 > 0);
    }

    /* End of Signum: '<S180>/SignPreIntegrator' */

    /* Switch: '<S180>/Switch' incorporates:
     *  Constant: '<S180>/Constant1'
     *  DataTypeConversion: '<S180>/DataTypeConv1'
     *  DataTypeConversion: '<S180>/DataTypeConv2'
     *  Logic: '<S180>/AND3'
     *  RelationalOperator: '<S180>/Equal1'
     */
    if (rtb_NotEqual_a && (rtb_SignChange_p == rtb_IntegralGain_0)) {
      rtb_add_c = 0;
    } else {
      rtb_add_c = rtb_Add6;
    }

    /* End of Switch: '<S180>/Switch' */

    /* DeadZone: '<S135>/DeadZone' */
    if (rtb_SignPreSat_m > tmp_1) {
      rtb_SignPreSat_m = (int16_T)(rtb_SignPreSat_m - tmp_1);
    } else if (rtb_SignPreSat_m >= tmp_0) {
      rtb_SignPreSat_m = 0;
    } else {
      rtb_SignPreSat_m = (int16_T)(rtb_SignPreSat_m - tmp_0);
    }

    /* RelationalOperator: '<S135>/NotEqual' */
    rtb_NotEqual_a = (0 != rtb_SignPreSat_m);

    /* Signum: '<S135>/SignPreSat' */
    if (rtb_SignPreSat_m < 0) {
      rtb_SignPreSat_m = -1;
    } else {
      rtb_SignPreSat_m = (int16_T)(rtb_SignPreSat_m > 0);
    }

    /* End of Signum: '<S135>/SignPreSat' */

    /* Gain: '<S139>/Integral Gain' */
    if (Ki_Iab_EMFobs <= 0) {
      rtb_uDLookupTable2 = 0U;
    } else if (Ki_Iab_EMFobs > 16383) {
      rtb_uDLookupTable2 = MAX_uint16_T;
    } else {
      rtb_uDLookupTable2 = (uint16_T)(Ki_Iab_EMFobs << 2);
    }

    rtb_Add6 = (int16_T)((rtb_uDLookupTable2 * Sig_Emfobs_errorSum_m) >> 6);

    /* End of Gain: '<S139>/Integral Gain' */

    /* Gain: '<S109>/Inductance' */
    if (EMFobsLdGain > 63) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (EMFobsLdGain <= -64) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(EMFobsLdGain << 9);
    }

    /* Gain: '<S109>/Resistance' */
    if (EMFobsRS > 127) {
      rtb_IntegralGain_0 = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_IntegralGain_0 = MIN_int16_T;
    } else {
      rtb_IntegralGain_0 = (int16_T)(EMFobsRS << 8);
    }

    /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S109>/Inductance'
     *  Gain: '<S109>/Resistance'
     *  Sum: '<S109>/Add5'
     */
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_e -= ((int16_T)
      (((Sig_Va_m - ((rtb_IntegralGain_0 *
                      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_e)
                     >> 16)) - (Sig_Emfobs_PI_out << 1)) >> 1) *
      rtb_SignChange_p < 0);

    /* Signum: '<S135>/SignPreIntegrator' */
    if (rtb_Add6 < 0) {
      rtb_IntegralGain_0 = -1;
    } else {
      rtb_IntegralGain_0 = (int16_T)(rtb_Add6 > 0);
    }

    /* End of Signum: '<S135>/SignPreIntegrator' */

    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S135>/Constant1'
     *  DataTypeConversion: '<S135>/DataTypeConv1'
     *  DataTypeConversion: '<S135>/DataTypeConv2'
     *  Logic: '<S135>/AND3'
     *  RelationalOperator: '<S135>/Equal1'
     */
    if (rtb_NotEqual_a && (rtb_SignPreSat_m == rtb_IntegralGain_0)) {
      rtb_Add6 = 0;
    }

    /* End of Switch: '<S135>/Switch' */

    /* Update for DiscreteIntegrator: '<S142>/Integrator' */
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k = (int16_T)(((16777 *
      rtb_Add6) >> 26) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k);

    /* Gain: '<S110>/Inductance' */
    if (EMFobsLdGain > 63) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (EMFobsLdGain <= -64) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(EMFobsLdGain << 9);
    }

    /* Gain: '<S110>/Resistance' */
    if (EMFobsRS > 127) {
      rtb_IntegralGain_0 = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_IntegralGain_0 = MIN_int16_T;
    } else {
      rtb_IntegralGain_0 = (int16_T)(EMFobsRS << 8);
    }

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' incorporates:
     *  Gain: '<S110>/Inductance'
     *  Gain: '<S110>/Resistance'
     *  Sum: '<S110>/Add5'
     */
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j -=
      ((((Sig_Vb_m - ((rtb_IntegralGain_0 *
                       MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j)
                      >> 16)) - (rtb_one_by_sqrt3 << 1)) >> 1) *
       rtb_SignChange_p < 0);

    /* Update for DiscreteIntegrator: '<S187>/Integrator' */
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_n = (int16_T)(((16777 *
      rtb_add_c) >> 26) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_n);
  } else {
    MotorControlLibNEWFixedP_FUL_DW.Positionobserver_MODE = false;
  }

  /* End of Logic: '<Root>/NOT' */
  /* End of Outputs for SubSystem: '<Root>/Position observer' */

  /* Outputs for Enabled SubSystem: '<S8>/Simulate start up Theta' incorporates:
   *  EnablePort: '<S208>/Enable'
   */
  /* Switch: '<Root>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (MotorControlLibNEWFixedP_FULL_B.RelationalOperator) {
    if (!MotorControlLibNEWFixedP_FUL_DW.SimulatestartupTheta_MODE) {
      /* InitializeConditions for UnitDelay: '<S208>/Unit Delay' */
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p = false;

      /* InitializeConditions for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = 0;
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = 2;
      MotorControlLibNEWFixedP_FUL_DW.SimulatestartupTheta_MODE = true;
    }

    /* UnitDelay: '<S208>/Unit Delay' */
    rtb_NotEqual_a = MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p;

    /* DiscreteIntegrator: '<S208>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S208>/Unit Delay'
     */
    if (MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p &&
        (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese <= 0))
    {
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    MotorControlLibNEWFixedP_FULL_B.DiscreteTimeIntegrator =
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S208>/Relational Operator' incorporates:
     *  UnitDelay: '<S208>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p =
      (MotorControlLibNEWFixedP_FULL_B.DiscreteTimeIntegrator >= 1608);

    /* Update for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE += (int16_T)
      mul_s32_hiSR(274877907, MotorControlLibNEWFixedP_ConstB.Gain, 16U);
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      rtb_NotEqual_a;
    MotorControlLibNEWFixedP_FULL_Y.Position =
      MotorControlLibNEWFixedP_FULL_B.DiscreteTimeIntegrator;
  } else {
    MotorControlLibNEWFixedP_FUL_DW.SimulatestartupTheta_MODE = false;
    MotorControlLibNEWFixedP_FULL_Y.Position = (int16_T)
      (MotorControlLibNEWFixedP_FULL_B.PositionGain >> 2);
  }

  /* End of Switch: '<Root>/Switch' */
  /* End of Outputs for SubSystem: '<S8>/Simulate start up Theta' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table'
   */
  set_PWM_A_DT(look1_is16lu32n16tu16_binlcse(Sig_Va_m, (&(BrkPoints[0])),
    rtCP_uDLookupTable_tableData, 2U));

  /* Gain: '<S107>/one_by_two' */
  rtb_SignPreSat_m = (int16_T)(Sig_Va_m >> 1);

  /* Gain: '<S107>/sqrt3_by_two' */
  rtb_SignChange_p = (int16_T)((14189 * Sig_Vb_m) >> 14);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table1'
   *  Sum: '<S107>/add_b'
   */
  set_PWM_B_DT(look1_is16lu32n16tu16_binlcse((int16_T)(rtb_SignChange_p -
    rtb_SignPreSat_m), (&(BrkPoints[0])), rtCP_uDLookupTable1_tableData, 2U));

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table2'
   *  Sum: '<S107>/add_c'
   */
  set_PWM_C_DT(look1_is16lu32n16tu16_binlcse((int16_T)(-rtb_SignPreSat_m -
    rtb_SignChange_p), (&(BrkPoints[0])), rtCP_uDLookupTable2_tableData, 2U));

  /* DeadZone: '<S41>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_SignPreSat_o > rtb_SignChange_p) {
    if (d_q_Voltage_Limiter_sat_pos > 4095) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
    }

    rtb_SignPreSat_o -= rtb_SignChange_p;
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 4095) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
    }

    if (rtb_SignPreSat_o >= rtb_SignChange_p) {
      rtb_SignPreSat_o = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 4095) {
        rtb_SignChange_p = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
        rtb_SignChange_p = MIN_int16_T;
      } else {
        rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
      }

      rtb_SignPreSat_o -= rtb_SignChange_p;
    }
  }

  /* End of DeadZone: '<S41>/DeadZone' */

  /* RelationalOperator: '<S41>/NotEqual' */
  rtb_NotEqual_a = (0 != rtb_SignPreSat_o);

  /* Signum: '<S41>/SignPreSat' */
  if (rtb_SignPreSat_o < 0) {
    rtb_SignPreSat_o = -1;
  } else {
    rtb_SignPreSat_o = (int16_T)(rtb_SignPreSat_o > 0);
  }

  /* End of Signum: '<S41>/SignPreSat' */

  /* Product: '<S45>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant5'
   */
  rtb_SignPreSat_m = (int16_T)((Sig_qAxis_errorSum_m * Ki_qAxis) >> 6);

  /* Signum: '<S41>/SignPreIntegrator' */
  if (rtb_SignPreSat_m < 0) {
    rtb_Add6 = -1;
  } else {
    rtb_Add6 = (int16_T)(rtb_SignPreSat_m > 0);
  }

  /* End of Signum: '<S41>/SignPreIntegrator' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Constant1'
   *  DataTypeConversion: '<S41>/DataTypeConv1'
   *  DataTypeConversion: '<S41>/DataTypeConv2'
   *  Logic: '<S41>/AND3'
   *  RelationalOperator: '<S41>/Equal1'
   */
  if (rtb_NotEqual_a && (rtb_SignPreSat_o == rtb_Add6)) {
    rtb_SignPreSat_o = 0;
  } else {
    rtb_SignPreSat_o = rtb_SignPreSat_m;
  }

  /* End of Switch: '<S41>/Switch' */

  /* DeadZone: '<S85>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 4095) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
  }

  if (rtb_convert_pu > rtb_SignChange_p) {
    if (d_q_Voltage_Limiter_sat_pos > 4095) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -4096) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_pos << 3);
    }

    rtb_convert_pu -= rtb_SignChange_p;
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 4095) {
      rtb_SignChange_p = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
      rtb_SignChange_p = MIN_int16_T;
    } else {
      rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
    }

    if (rtb_convert_pu >= rtb_SignChange_p) {
      rtb_convert_pu = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 4095) {
        rtb_SignChange_p = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -4096) {
        rtb_SignChange_p = MIN_int16_T;
      } else {
        rtb_SignChange_p = (int16_T)(d_q_Voltage_Limiter_sat_neg << 3);
      }

      rtb_convert_pu -= rtb_SignChange_p;
    }
  }

  /* End of DeadZone: '<S85>/DeadZone' */

  /* RelationalOperator: '<S85>/NotEqual' */
  rtb_NotEqual_a = (0 != rtb_convert_pu);

  /* Signum: '<S85>/SignPreSat' */
  if (rtb_convert_pu < 0) {
    rtb_convert_pu = -1;
  } else {
    rtb_convert_pu = (int16_T)(rtb_convert_pu > 0);
  }

  /* End of Signum: '<S85>/SignPreSat' */

  /* Product: '<S89>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant7'
   */
  rtb_SignPreSat_m = (int16_T)((Sig_dAxis_errorSum_m * Ki_dAxis) >> 6);

  /* Update for UnitDelay: '<S207>/Unit Delay' incorporates:
   *  CombinatorialLogic: '<S214>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE = rtCP_Logic_table_m
    [(uint32_T)rowIdx_0];

  /* Update for Memory: '<S213>/Memory' incorporates:
   *  CombinatorialLogic: '<S213>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput = rtCP_Logic_table
    [(uint32_T)rowIdx];

  /* Update for UnitDelay: '<S210>/Delay Input1'
   *
   * Block description for '<S210>/Delay Input1':
   *
   *  Store in Global RAM
   */
  MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE = rtb_UnitDelay1_b;

  /* Update for Memory: '<S214>/Memory' incorporates:
   *  CombinatorialLogic: '<S214>/Logic'
   */
  MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b = rtCP_Logic_table_m
    [(uint32_T)rowIdx_0];

  /* Signum: '<S85>/SignPreIntegrator' */
  if (rtb_SignPreSat_m < 0) {
    rtb_Add6 = -1;
  } else {
    rtb_Add6 = (int16_T)(rtb_SignPreSat_m > 0);
  }

  /* End of Signum: '<S85>/SignPreIntegrator' */

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/Constant1'
   *  DataTypeConversion: '<S85>/DataTypeConv1'
   *  DataTypeConversion: '<S85>/DataTypeConv2'
   *  Logic: '<S85>/AND3'
   *  RelationalOperator: '<S85>/Equal1'
   */
  if (rtb_NotEqual_a && (rtb_convert_pu == rtb_Add6)) {
    rtb_SignPreSat_m = 0;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Update for DiscreteIntegrator: '<S92>/Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE = (int16_T)(((16777 *
    rtb_SignPreSat_m) >> 26) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Update for DiscreteIntegrator: '<S48>/Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m = (int16_T)(((16777 *
    rtb_SignPreSat_o) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m);
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

  /* SystemInitialize for Enabled SubSystem: '<S8>/Simulate start up Theta' */
  /* InitializeConditions for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<S8>/Simulate start up Theta' */
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
