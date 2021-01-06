/*
 * File: MotorControlLibNEWFixedP_FULL19b.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Dec 29 14:13:06 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorControlLibNEWFixedP_FULL19b.h"
#include "MotorControlLibNEWFixedP_FULL19b_private.h"
//#include "InterfaceBswApp.h"
#include "look1_is16lu32n16Ds32_binlcs.h"
#include "rt_atan2f_snf.h"
#include "rt_sqrt_Us32En14_Ys32E_OVqLloIL.h"

/* Exported block signals */
uint16_T Sig_theta_el_m;               /* '<Root>/Delay' */
int16_T Sig_Ia_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ib_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_dAxis_m;                   /* '<Root>/Gain2' */
int16_T Sig_dAxis_errorSum_m;          /* '<S4>/Add' */
int16_T Sig_qAxis_m;                   /* '<Root>/Gain3' */
int16_T Sig_qAxis_errorSum_m;          /* '<S4>/Add1' */
int16_T Sig_Vqsatu_m;                  /* '<S8>/Multiport Switch1' */
int16_T Sig_Vdsatu_m;                  /* '<S8>/Multiport Switch' */
int16_T Sig_Va_m;                      /* '<Root>/Gain' */
int16_T Sig_Vb_m;                      /* '<Root>/Gain1' */
int16_T Sig_Emfobs_errorSum_m;         /* '<S108>/Add6' */
int16_T Sig_dAxis_PI_out;              /* '<S100>/Sum' */
int16_T Sig_qAxis_PI_out;              /* '<S56>/Sum' */
int16_T Sig_Emfobs_PI_out;             /* '<S150>/Sum' */

/* Exported block parameters */
int16_T Ki_dAxis = 0;                  /* Variable: Ki_dAxis
                                        * Referenced by: '<S4>/Constant7'
                                        */
int16_T Ki_qAxis = 0;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S4>/Constant5'
                                        */
int16_T Kp_dAxis = 32;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S4>/Constant6'
                                        */
int16_T Kp_qAxis = 32;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S4>/Constant4'
                                        */

/* Exported data definition */

/* Const memory section */
/* Definition for custom storage class: Const */
const int16_T ComparatorBrkPnt[3] = { 0, 26, 53 } ;
                             /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */

const int16_T VoltageOut[3] = { 307, 0, -307 } ;
                             /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */

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
  uint16_T rtb_Get_Integer;
  int16_T rtb_Resistance;
  int16_T rtb_convert_pu;
  int16_T rtb_DiscreteTimeIntegrator_c;
  int16_T rtb_Integrator;
  int16_T rtb_SignChange_p;
  int32_T rtb_Sqrt;
  uint32_T rtb_Sum_idx_3;
  real32_T tmp;
  int32_T tmp_0;

  /* Delay: '<Root>/Delay' */
  Sig_theta_el_m = MotorControlLibNEWFixedP_FULL_Y.Position;

  /* Gain: '<S11>/convert_pu' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_convert_pu = (int16_T)(((int32_T)((uint32_T)Sig_theta_el_m >> 2) * 20861) >>
    17);

  /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S14>/Action Port'
   */
  /* If: '<S11>/If' incorporates:
   *  DataTypeConversion: '<S14>/Convert_back'
   *  DataTypeConversion: '<S14>/Convert_uint16'
   *  Gain: '<S9>/indexing'
   *  Sum: '<S14>/Sum'
   */
  rtb_convert_pu = (int16_T)((int16_T)(rtb_convert_pu - ((rtb_convert_pu >> 8) <<
    8)) * 100);

  /* End of Outputs for SubSystem: '<S11>/If Action Subsystem1' */

  /* DataTypeConversion: '<S9>/Get_Integer' */
  rtb_Get_Integer = (uint16_T)(rtb_convert_pu >> 6);

  /* Sum: '<S9>/Sum' */
  rtb_Sum_idx_3 = rtb_Get_Integer + 100U;

  /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
   *  Inport: '<Root>/Inport'
   */
  ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

  /* DataTypeConversion: '<S9>/Get_FractionVal' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion1'
   *  Sum: '<S9>/Sum2'
   */
  rtb_DiscreteTimeIntegrator_c = (int16_T)((int16_T)(rtb_convert_pu - (int16_T)
    ((int16_T)rtb_Get_Integer << 6)) << 2);

  /* Sum: '<S10>/Sum6' incorporates:
   *  Constant: '<S9>/sine_table_values'
   *  Product: '<S10>/Product1'
   *  Selector: '<S9>/Lookup'
   *  Sum: '<S10>/Sum5'
   *  Sum: '<S9>/Sum'
   */
  rtb_convert_pu = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
    [(int32_T)(rtb_Get_Integer + 101U)] - rtCP_sine_table_values_Value[(int32_T)
    rtb_Sum_idx_3]) * rtb_DiscreteTimeIntegrator_c) >> 8) +
    rtCP_sine_table_values_Value[(int32_T)rtb_Sum_idx_3]);

  /* Gain: '<S1>/one_by_sqrt3' incorporates:
   *  Sum: '<S1>/a_plus_2b'
   */
  rtb_Integrator = (int16_T)(((int16_T)((int16_T)(Sig_Ia_m + Sig_Ib_m) +
    Sig_Ib_m) * 18919) >> 15);

  /* Sum: '<S10>/Sum4' incorporates:
   *  Constant: '<S9>/sine_table_values'
   *  Product: '<S10>/Product'
   *  Selector: '<S9>/Lookup'
   *  Sum: '<S10>/Sum3'
   *  Sum: '<S9>/Sum'
   */
  rtb_DiscreteTimeIntegrator_c = (int16_T)((int16_T)(((int16_T)
    (rtCP_sine_table_values_Value[(int32_T)(rtb_Get_Integer + 1U)] -
     rtCP_sine_table_values_Value[rtb_Get_Integer]) *
    rtb_DiscreteTimeIntegrator_c) >> 8) +
    rtCP_sine_table_values_Value[rtb_Get_Integer]);

  /* Gain: '<Root>/Gain2' incorporates:
   *  Product: '<S6>/acos'
   *  Product: '<S6>/bsin'
   *  Sum: '<S6>/sum_Ds'
   */
  Sig_dAxis_m = (int16_T)((int16_T)((Sig_Ia_m * rtb_convert_pu) >> 8) + (int16_T)
    ((rtb_Integrator * rtb_DiscreteTimeIntegrator_c) >> 8));

  /* Sum: '<S4>/Add' */
  Sig_dAxis_errorSum_m = (int16_T)-Sig_dAxis_m;

  /* Sum: '<S100>/Sum' incorporates:
   *  Constant: '<S4>/Constant6'
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Product: '<S96>/PProd Out'
   */
  Sig_dAxis_PI_out = (int16_T)((int16_T)((Sig_dAxis_errorSum_m * Kp_dAxis) >> 6)
    + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Gain: '<Root>/Gain3' incorporates:
   *  Product: '<S6>/asin'
   *  Product: '<S6>/bcos'
   *  Sum: '<S6>/sum_Qs'
   */
  Sig_qAxis_m = (int16_T)((int16_T)((rtb_Integrator * rtb_convert_pu) >> 8) -
    (int16_T)((Sig_Ia_m * rtb_DiscreteTimeIntegrator_c) >> 8));

  /* Sum: '<S4>/Add1' incorporates:
   *  Gain: '<Root>/Tq--> iqRef'
   */
  Sig_qAxis_errorSum_m = (int16_T)(((int8_T)((TqToIqConst * 13) >> 7) << 1) -
    Sig_qAxis_m);

  /* Sum: '<S56>/Sum' incorporates:
   *  Constant: '<S4>/Constant4'
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Product: '<S52>/PProd Out'
   */
  Sig_qAxis_PI_out = (int16_T)((int16_T)((Sig_qAxis_errorSum_m * Kp_qAxis) >> 6)
    + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m);

  /* RelationalOperator: '<S209>/LowerRelop1' incorporates:
   *  RelationalOperator: '<S209>/UpperRelop'
   *  Switch: '<S206>/Switch'
   *  Switch: '<S209>/Switch2'
   */
  tmp_0 = Sig_dAxis_PI_out << 1;

  /* Switch: '<S209>/Switch2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  RelationalOperator: '<S209>/LowerRelop1'
   */
  if (tmp_0 > VphMax) {
    rtb_SignChange_p = (int16_T)(VphMax >> 1);
  } else {
    /* Gain: '<S8>/Sign Change' */
    rtb_SignChange_p = (int16_T)-VphMax;

    /* Switch: '<S209>/Switch' incorporates:
     *  RelationalOperator: '<S209>/UpperRelop'
     *  Switch: '<S206>/Switch'
     */
    if (tmp_0 < rtb_SignChange_p) {
      rtb_SignChange_p >>= 1;
    } else {
      rtb_SignChange_p = Sig_dAxis_PI_out;
    }

    /* End of Switch: '<S209>/Switch' */
  }

  /* Sqrt: '<S8>/Sqrt' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Math: '<S8>/Math Function'
   *  Math: '<S8>/Math Function1'
   *  Sum: '<S8>/Sum4'
   */
  rtb_Sqrt = rt_sqrt_Us32En14_Ys32E_OVqLloIL(((VphMax * VphMax) >> 2) -
    rtb_SignChange_p * rtb_SignChange_p);

  /* RelationalOperator: '<S210>/LowerRelop1' incorporates:
   *  RelationalOperator: '<S210>/UpperRelop'
   *  Switch: '<S207>/Switch'
   *  Switch: '<S210>/Switch2'
   */
  tmp_0 = Sig_qAxis_PI_out << 7;

  /* Switch: '<S210>/Switch2' incorporates:
   *  RelationalOperator: '<S210>/LowerRelop1'
   */
  if (tmp_0 > rtb_Sqrt) {
    rtb_Resistance = (int16_T)(rtb_Sqrt >> 7);
  } else {
    /* Gain: '<S8>/Sign Change ' */
    rtb_Sqrt = -rtb_Sqrt;

    /* Switch: '<S210>/Switch' incorporates:
     *  RelationalOperator: '<S210>/UpperRelop'
     *  Switch: '<S207>/Switch'
     */
    if (tmp_0 < rtb_Sqrt) {
      rtb_Resistance = (int16_T)(rtb_Sqrt >> 7);
    } else {
      rtb_Resistance = Sig_qAxis_PI_out;
    }

    /* End of Switch: '<S210>/Switch' */
  }

  /* MultiPortSwitch: '<S8>/Multiport Switch1' */
  Sig_Vqsatu_m = (int16_T)(rtb_Resistance << 1);

  /* MultiPortSwitch: '<S8>/Multiport Switch' */
  Sig_Vdsatu_m = (int16_T)(rtb_SignChange_p << 1);

  /* Sum: '<S108>/Add5' incorporates:
   *  Product: '<S3>/dcos'
   *  Product: '<S3>/qsin'
   *  Sum: '<S3>/sum_alpha'
   *  Switch: '<S15>/Switch'
   */
  Sig_Va_m = (int16_T)((int16_T)((Sig_Vdsatu_m * rtb_convert_pu) >> 8) -
                       (int16_T)((Sig_Vqsatu_m * rtb_DiscreteTimeIntegrator_c) >>
    8));

  /* Sum: '<S109>/Add5' incorporates:
   *  Product: '<S3>/dsin'
   *  Product: '<S3>/qcos'
   *  Sum: '<S3>/sum_beta'
   *  Switch: '<S15>/Switch'
   */
  Sig_Vb_m = (int16_T)((int16_T)((Sig_Vqsatu_m * rtb_convert_pu) >> 8) +
                       (int16_T)((Sig_Vdsatu_m * rtb_DiscreteTimeIntegrator_c) >>
    8));

  /* Gain: '<S106>/one_by_two' */
  rtb_convert_pu = (int16_T)(Sig_Va_m >> 1);

  /* Gain: '<S106>/sqrt3_by_two' */
  rtb_SignChange_p = (int16_T)((14189 * Sig_Vb_m) >> 14);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table1'
   *  Sum: '<S106>/add_b'
   */
  set_PWM_B_DT((uint8_T)(look1_is16lu32n16Ds32_binlcs((int16_T)(rtb_SignChange_p
    - rtb_convert_pu), (&(BrkPoints[0])), rtCP_uDLookupTable1_tableData, 2U) >>
    8));

  /* DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table2'
   *  Sum: '<S106>/add_c'
   */
  set_PWM_C_DT((uint8_T)(look1_is16lu32n16Ds32_binlcs((int16_T)(-rtb_convert_pu
    - rtb_SignChange_p), (&(BrkPoints[0])), rtCP_uDLookupTable2_tableData, 2U) >>
    8));

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Lookup_n-D: '<S5>/1-D Lookup Table'
   */
  set_PWM_A_DT((uint8_T)(look1_is16lu32n16Ds32_binlcs(Sig_Va_m, (&(BrkPoints[0])),
    rtCP_uDLookupTable_tableData, 2U) >> 8));

  /* Sum: '<S108>/Add6' incorporates:
   *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
   */
  Sig_Emfobs_errorSum_m = (int16_T)
    (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE - Sig_Ia_m);

  /* Sum: '<S150>/Sum' incorporates:
   *  DiscreteIntegrator: '<S141>/Integrator'
   *  Gain: '<S146>/Proportional Gain'
   */
  Sig_Emfobs_PI_out = (int16_T)(((33 * Sig_Emfobs_errorSum_m) >> 8) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k);

  /* Sum: '<S109>/Add6' incorporates:
   *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator'
   */
  rtb_convert_pu = (int16_T)
    (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j -
     rtb_Integrator);

  /* Sum: '<S195>/Sum' incorporates:
   *  DiscreteIntegrator: '<S186>/Integrator'
   *  Gain: '<S191>/Proportional Gain'
   */
  rtb_Integrator = (int16_T)(((33 * rtb_convert_pu) >> 8) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_j);

  /* Outputs for Atomic SubSystem: '<S110>/atan2' */
  /* DataTypeConversion: '<S201>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S201>/Data Type Conversion1'
   *  DataTypeConversion: '<S201>/Data Type Conversion2'
   *  Trigonometry: '<S201>/Atan2'
   */
  tmp = floorf(rt_atan2f_snf((real32_T)rtb_Integrator * 0.0078125F, (real32_T)
    Sig_Emfobs_PI_out * 0.0078125F) * 128.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  rtb_SignChange_p = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S201>/Data Type Conversion' */

  /* Outputs for Enabled SubSystem: '<S201>/If Action Subsystem' incorporates:
   *  EnablePort: '<S204>/Enable'
   */
  if (MotorControlLibNEWFixedP_ConstB.Compare) {
    /* Inport: '<S204>/In1' */
    MotorControlLibNEWFixedP_FULL_B.Merge = rtb_SignChange_p;
  }

  /* End of Outputs for SubSystem: '<S201>/If Action Subsystem' */

  /* Outputs for Enabled SubSystem: '<S201>/per Uint' incorporates:
   *  EnablePort: '<S205>/Enable'
   */
  if (MotorControlLibNEWFixedP_ConstB.Compare_o) {
    /* Gain: '<S205>/Gain' */
    MotorControlLibNEWFixedP_FULL_B.Merge = (int16_T)((20861 * rtb_SignChange_p)
      >> 17);

    /* Switch: '<S205>/Switch' incorporates:
     *  Bias: '<S205>/Bias'
     */
    if (MotorControlLibNEWFixedP_FULL_B.Merge < 0) {
      MotorControlLibNEWFixedP_FULL_B.Merge = (int16_T)
        (MotorControlLibNEWFixedP_FULL_B.Merge + 128);
    }

    /* End of Switch: '<S205>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S201>/per Uint' */

  /* Gain: '<S110>/PositionGain' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
   *  Delay: '<Root>/Delay'
   */
  MotorControlLibNEWFixedP_FULL_Y.Position = (uint16_T)((201 *
    MotorControlLibNEWFixedP_FULL_B.Merge) >> 2);

  /* End of Outputs for SubSystem: '<S110>/atan2' */

  /* Update for DiscreteIntegrator: '<S91>/Integrator' incorporates:
   *  Constant: '<S4>/Constant7'
   *  Product: '<S88>/IProd Out'
   */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE = (int16_T)((((int16_T)
    ((Sig_dAxis_errorSum_m * Ki_dAxis) >> 6) * 16777) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Constant: '<S4>/Constant5'
   *  Product: '<S44>/IProd Out'
   */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m = (int16_T)((((int16_T)
    ((Sig_qAxis_errorSum_m * Ki_qAxis) >> 6) * 16777) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_m);

  /* Gain: '<S108>/Resistance' */
  if (EMFobsRS > 63) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (EMFobsRS <= -64) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(EMFobsRS << 9);
  }

  /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S108>/Inductance'
   *  Gain: '<S108>/Resistance'
   *  Sum: '<S108>/Add5'
   */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE -= ((int16_T)
    (((Sig_Va_m - ((rtb_SignChange_p *
                    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE)
                   >> 17)) - (Sig_Emfobs_PI_out << 1)) >> 1) * 26816 < 0);

  /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
   *  Gain: '<S138>/Integral Gain'
   */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k = (int16_T)((((int16_T)
    (800 * Sig_Emfobs_errorSum_m) * 16777) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_k);

  /* Gain: '<S109>/Resistance' */
  if (EMFobsRS > 63) {
    rtb_SignChange_p = MAX_int16_T;
  } else if (EMFobsRS <= -64) {
    rtb_SignChange_p = MIN_int16_T;
  } else {
    rtb_SignChange_p = (int16_T)(EMFobsRS << 9);
  }

  /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S109>/Inductance'
   *  Gain: '<S109>/Resistance'
   *  Sum: '<S109>/Add5'
   */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j -= ((int16_T)
    (((Sig_Vb_m - ((rtb_SignChange_p *
                    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE_j)
                   >> 17)) - (rtb_Integrator << 1)) >> 1) * 26816 < 0);

  /* Update for DiscreteIntegrator: '<S186>/Integrator' incorporates:
   *  Gain: '<S183>/Integral Gain'
   */
  MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_j = (int16_T)((((int16_T)
    (800 * rtb_convert_pu) * 16777) >> 26) +
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_j);
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
