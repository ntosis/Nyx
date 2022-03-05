/*
 * File: MotorControlLibNEWFixedP_FULL19b.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Feb  4 14:26:17 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorControlLibNEWFixedP_FULL19b.h"
#include "MotorControlLibNEWFixedP_FULL19b_private.h"
#include "InterfaceBswApp.h"
#include "div_s16s32.h"
#include "look1_is16lu32n16tu16_binlcse.h"
#include "rt_atan2f_snf.h"
#include "rt_atan2f_snf_cordic6.h"
#include "ConvertPWMtoAngle.h"

/* Exported block signals */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput=2;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
boolean_T Sig_change_SVMalgorithm;     /* '<Root>/In1' */
boolean_T resetPIIntegratorDQ;         /* '<Root>/Inport6' */
real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Calculate spin speed1' */
real32_T Sig_rpm;                      /* '<Root>/Calculate spin speed1' */
int16_T Sig_theta_el_m;                /* '<Root>/Delay' */
int16_T Sig_Ia_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ib_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_cos_m;                     /* '<S12>/Sum6' */
int16_T Sig_Ibeta_m;                   /* '<S1>/one_by_sqrt3' */
int16_T Sig_sin_m;                     /* '<S12>/Sum4' */
int16_T Sig_Iq_Soll;                   /* '<Root>/Tq--> iqRef' */
int16_T Sig_dAxis_m;                   /* '<Root>/Gain2' */
int16_T Sig_qAxis_m;                   /* '<Root>/Gain3' */
int16_T Sig_Vqsatu_m;                  /* '<Root>/Gain5' */
int16_T Sig_Vdsatu_m;                  /* '<Root>/Gain4' */
int16_T Sig_Va_m;                      /* '<Root>/Gain' */
int16_T Sig_Vb_m;                      /* '<Root>/Gain1' */
int16_T Sig_Valpha_m;                  /* '<S7>/Switch' */
int16_T Sig_Vbeta_m;                   /* '<S7>/Switch1' */
int16_T Sig_Vgamma_m;                  /* '<S7>/Switch2' */
int16_T constantAngle;                 /* '<S137>/Discrete-Time Integrator' */
int16_T PositionObsAnlge;              /* '<S123>/Data Type Conversion5' */
int16_T Sig_dAxis_PI_out;              /* '<S111>/Saturation' */
int16_T Sig_qAxis_PI_out;              /* '<S67>/Saturation' */
int16_T FluxObsAngle;                  /* '<S17>/PositionGain' */
real32_T Sig_Emfobs_errorSum_m;        /* '<S124>/Add6' */
real32_T Sig_Emfobs_PI_out;            /* '<S131>/Saturation' */
real32_T di_dt_E9;                     /* '<S130>/Inductance' */
real32_T di_dt_times_Ts_En8;           /* '<S130>/Gain' */
real32_T i_integrated_en4;             /* '<S130>/Sum' */
real32_T i_integrated_times_Rs_en8;    /* '<S130>/Resistance' */
real32_T Va_all_16En4;                 /* '<S130>/Add5' */
int16_T Sig_First_LPF_out;             /* '<S126>/Product1'
                                        * 16En6
                                        */
int16_T Sig_Second_LPF_out;            /* '<S127>/Product1'
                                        * 16En6
                                        */
int16_T Sig_dAxis_errorSum_m;          /* '<S6>/Add' */
int16_T Sig_qAxis_errorSum_m;          /* '<S6>/Add1' */

/* Exported block parameters */
real32_T TsIntern = 5.0E-5F;           /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S130>/Gain'
                                        *   '<S133>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
int16_T MaxBckEMFVol_sat_neg = -48;    /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S131>/Saturation'
                                        *   '<S134>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
int16_T MaxBckEMFVol_sat_pos = 48;     /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S131>/Saturation'
                                        *   '<S134>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
int16_T Ki_Iab_EMFobs = 0;             /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S132>/Ki'
                                        *   '<S135>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
int16_T d_q_Voltage_Limiter_max = 111; /* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
int16_T d_q_Voltage_Limiter_sat_neg = -96;/* Variable: d_q_Voltage_Limiter_sat_neg
                                           * Referenced by:
                                           *   '<S53>/DeadZone'
                                           *   '<S67>/Saturation'
                                           *   '<S97>/DeadZone'
                                           *   '<S111>/Saturation'
                                           * fixdt(1,16,2^-4,0)
                                           */
int16_T d_q_Voltage_Limiter_sat_pos = 96;/* Variable: d_q_Voltage_Limiter_sat_pos
                                          * Referenced by:
                                          *   '<S53>/DeadZone'
                                          *   '<S67>/Saturation'
                                          *   '<S97>/DeadZone'
                                          *   '<S111>/Saturation'
                                          * fixdt(1,16,2^-4,0)
                                          */
int16_T Ki_dAxis = 4606;                  /* Variable: Ki_dAxis
                                        * Referenced by: '<S7>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Ki_qAxis = 20625;                  /* Variable: Ki_qAxis
                                        * Referenced by: '<S7>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_dAxis = 5;                 /* Variable: Kp_dAxis
                                        * Referenced by: '<S7>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_qAxis = 15;                 /* Variable: Kp_qAxis
                                        * Referenced by: '<S7>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
int16_T Kp_Iab_EMFobs = 256;           /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S131>/Kp'
                                        *   '<S134>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
int16_T qSoll = 1300;                     /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,16,2^-8,0)
                                        */
uint16_T MaximumCurrentBeforeReaction = 10240U;/* Variable: MaximumCurrentBeforeReaction
                                                * Referenced by: '<Root>/SafetyChecks'
                                                * Maximum current limit before softare shutdowns the mosfets.
                                                */
uint16_T CuttOffFreq_c = 4000U;        /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S126>/Constant'
                                        *   '<S127>/Constant'
                                        *   '<S128>/Constant'
                                        *   '<S129>/Constant'
                                        */

/* Exported block states */
real32_T UnitDelayIntegratorPosObs;    /* '<S130>/Delay' */

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
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1])++;
  if ((MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.0001s, 0.0s] */
    MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] = 0;
  }

  (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2])++;
  if ((MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.0002s, 0.0s] */
    MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Output and update for atomic system: '<Root>/DQ_Limiter' */
void MotorControlLibNEWFi_DQ_Limiter(int16_T rtu_Vd_ref, int16_T rtu_Vq_ref,
  int16_T rty_Vd_sat[2], int16_T *rty_Vmax_unsat, int16_T rtp_Vmax)
{
  int16_T rtb_Gain;
  real32_T tmp;

  /* Sum: '<S3>/Sum2' incorporates:
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   */
  *rty_Vmax_unsat = (int16_T)((int16_T)((rtu_Vd_ref * rtu_Vd_ref) >> 8) +
    (int16_T)((rtu_Vq_ref * rtu_Vq_ref) >> 8));

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Sqrt: '<S3>/Sqrt'
   */
  tmp = floorf(sqrtf((real32_T)*rty_Vmax_unsat * 0.00390625F) * 256.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  *rty_Vmax_unsat = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S3>/Data Type Conversion1' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Product: '<S3>/Product2'
   */
  if (rtp_Vmax > 2047) {
    rtb_Gain = MAX_int16_T;
  } else if (rtp_Vmax <= -2048) {
    rtb_Gain = MIN_int16_T;
  } else {
    rtb_Gain = (int16_T)(rtp_Vmax << 4);
  }

  if (*rty_Vmax_unsat >= rtb_Gain) {
    /* Gain: '<S3>/Gain' incorporates:
     *  Math: '<S3>/Math Function2'
     *
     * About '<S3>/Math Function2':
     *  Operator: reciprocal
     */
    if (rtp_Vmax > 127) {
      rtb_Gain = MAX_int16_T;
    } else if (rtp_Vmax <= -128) {
      rtb_Gain = MIN_int16_T;
    } else {
      rtb_Gain = (int16_T)(rtp_Vmax << 8);
    }

    rtb_Gain = (int16_T)((rtb_Gain * div_s16s32(65536, *rty_Vmax_unsat)) >> 12);

    /* End of Gain: '<S3>/Gain' */
    rty_Vd_sat[0] = (int16_T)((rtb_Gain * rtu_Vd_ref) >> 8);
    rty_Vd_sat[1] = (int16_T)((rtb_Gain * rtu_Vq_ref) >> 8);
  } else {
    rty_Vd_sat[0] = rtu_Vd_ref;
    rty_Vd_sat[1] = rtu_Vq_ref;
  }

  /* End of Switch: '<S3>/Switch' */
}

/* Output and update for enable system: '<Root>/FluxObsAngle' */
void MotorControlLibNEW_FluxObsAngle(boolean_T rtu_Enable, int16_T rtu_In1,
  int16_T rtu_In2, int16_T rtu_In3, int16_T rtu_In4, int16_T *rty_FluxObsAngle,
  B_FluxObsAngle_MotorControlLi_T *localB, const ConstB_FluxObsAngle_MotorCont_T
  *localC, DW_FluxObsAngle_MotorControlL_T *localDW,
  ZCE_FluxObsAngle_MotorControl_T *localZCE)
{
  int16_T rtb_DataTypeConversion;
  real32_T u;
  real32_T v;
  real32_T u_0;
  int16_T tmp;

  /* Outputs for Enabled SubSystem: '<Root>/FluxObsAngle' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtu_Enable) {
    /* Outputs for Atomic SubSystem: '<S4>/Flux Observer' */
    /* Delay: '<S20>/Delay' */
    if ((localZCE->Delay_Reset_ZCE == POS_ZCSIG) && (localZCE->Delay_Reset_ZCE
         != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE = 0;
    }

    localZCE->Delay_Reset_ZCE = 0U;

    /* Gain: '<S26>/ScalingR' */
    u = EMFobsRS * 65536.0F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_DataTypeConversion = (int16_T)u;
      } else {
        rtb_DataTypeConversion = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion = MAX_int16_T;
    }

    /* Sum: '<S20>/Sum' incorporates:
     *  Delay: '<S20>/Delay'
     *  Gain: '<S20>/Gain'
     *  Gain: '<S26>/ScalingR'
     *  Sum: '<S20>/Sum3'
     */
    localDW->Delay_DSTATE = (int16_T)((((int16_T)(rtu_In2 -
      ((rtb_DataTypeConversion * rtu_In4) >> 16)) * 53687) >> 25) +
      localDW->Delay_DSTATE);

    /* Gain: '<S26>/ScalingL' incorporates:
     *  Switch: '<S20>/Switch'
     */
    u = EMFobsLdGain * 0.5F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    /* Delay: '<S19>/Delay' */
    if ((localZCE->Delay_Reset_ZCE_o == POS_ZCSIG) &&
        (localZCE->Delay_Reset_ZCE_o != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE_e = 0;
    }

    localZCE->Delay_Reset_ZCE_o = 0U;

    /* Gain: '<S25>/ScalingR' */
    u_0 = EMFobsRS * 65536.0F;
    v = fabsf(u_0);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u_0 = floorf(u_0 + 0.5F);
      } else {
        u_0 *= 0.0F;
      }
    }

    if (u_0 < 32768.0F) {
      if (u_0 >= -32768.0F) {
        rtb_DataTypeConversion = (int16_T)u_0;
      } else {
        rtb_DataTypeConversion = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion = MAX_int16_T;
    }

    /* Sum: '<S19>/Sum' incorporates:
     *  Delay: '<S19>/Delay'
     *  Gain: '<S19>/Gain'
     *  Gain: '<S25>/ScalingR'
     *  Sum: '<S19>/Sum3'
     */
    localDW->Delay_DSTATE_e = (int16_T)((((int16_T)(rtu_In1 -
      ((rtb_DataTypeConversion * rtu_In3) >> 16)) * 53687) >> 25) +
      localDW->Delay_DSTATE_e);

    /* Gain: '<S25>/ScalingL' incorporates:
     *  Switch: '<S19>/Switch'
     */
    u_0 = EMFobsLdGain * 0.5F;
    v = fabsf(u_0);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u_0 = floorf(u_0 + 0.5F);
      } else {
        u_0 *= 0.0F;
      }
    }

    /* Gain: '<S26>/ScalingL' incorporates:
     *  Switch: '<S20>/Switch'
     */
    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_DataTypeConversion = (int16_T)u;
      } else {
        rtb_DataTypeConversion = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion = MAX_int16_T;
    }

    /* Gain: '<S25>/ScalingL' incorporates:
     *  Switch: '<S19>/Switch'
     */
    if (u_0 < 32768.0F) {
      if (u_0 >= -32768.0F) {
        tmp = (int16_T)u_0;
      } else {
        tmp = MIN_int16_T;
      }
    } else {
      tmp = MAX_int16_T;
    }

    /* Outputs for Atomic SubSystem: '<S17>/atan2' */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     *  DataTypeConversion: '<S18>/Data Type Conversion2'
     *  Delay: '<S19>/Delay'
     *  Delay: '<S20>/Delay'
     *  Gain: '<S25>/ScalingL'
     *  Gain: '<S26>/ScalingL'
     *  Sum: '<S19>/Sum1'
     *  Sum: '<S20>/Sum1'
     *  Switch: '<S19>/Switch'
     *  Switch: '<S20>/Switch'
     *  Trigonometry: '<S18>/Atan2'
     */
    u = floorf(rt_atan2f_snf((real32_T)(int16_T)(localDW->Delay_DSTATE -
      (int16_T)((int16_T)(rtb_DataTypeConversion * rtu_In4) << 5)) *
                0.000244140625F, (real32_T)(int16_T)(localDW->Delay_DSTATE_e -
      (int16_T)((int16_T)(tmp * rtu_In3) << 5)) * 0.000244140625F) * 4096.0F);
    if (rtIsNaNF(u) || rtIsInfF(u)) {
      u = 0.0F;
    } else {
      u = fmodf(u, 65536.0F);
    }

    rtb_DataTypeConversion = (int16_T)(u < 0.0F ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-u : (int32_T)(int16_T)(uint16_T)u);

    /* End of DataTypeConversion: '<S18>/Data Type Conversion' */

    /* Outputs for Enabled SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (localC->Compare) {
      /* Inport: '<S23>/In1' */
      localB->Merge = rtb_DataTypeConversion;
    }

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S18>/per Uint' incorporates:
     *  EnablePort: '<S24>/Enable'
     */
    if (localC->Compare_l) {
      /* Gain: '<S24>/Gain' */
      localB->Merge = (int16_T)((20861 * rtb_DataTypeConversion) >> 17);

      /* Switch: '<S24>/Switch' incorporates:
       *  Bias: '<S24>/Bias'
       */
      if (localB->Merge < 0) {
        localB->Merge = (int16_T)(localB->Merge + 4096);
      }

      /* End of Switch: '<S24>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S18>/per Uint' */

    /* Gain: '<S17>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
     */
    *rty_FluxObsAngle = (int16_T)((3217 * localB->Merge) >> 13);

    /* End of Outputs for SubSystem: '<S17>/atan2' */
    /* End of Outputs for SubSystem: '<S4>/Flux Observer' */
  }

  /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */
}

/* Output and update for atomic system: '<Root>/PI_Controller' */
void MotorControlLibNE_PI_Controller(int8_T rtu_dRef, int16_T rtu_qRef, int16_T
  rtu_In5, int16_T rtu_In6, boolean_T rtu_Inport6, int16_T *rty_d, int16_T
  *rty_q, DW_PI_Controller_MotorControl_T *localDW)
{
  boolean_T rtb_OR;
  boolean_T rtb_NotEqual;
  int16_T rtb_Sum_j;
  int8_T rtb_DataTypeConv2;
  int16_T rtb_IProdOut;
  int16_T rtb_Switch_e;
  int16_T tmp;
  int16_T tmp_0;

  /* Sum: '<S6>/Add' */
  Sig_dAxis_errorSum_m = (int16_T)((rtu_dRef << 8) - rtu_In5);

  /* Sum: '<S30>/Add2' incorporates:
   *  Constant: '<S30>/Constant8'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  if(localDW->UnitDelay_DSTATE < 1500) {
  localDW->UnitDelay_DSTATE++;
  }
  /* Logic: '<S6>/OR' incorporates:
   *  Constant: '<S119>/Constant'
   *  RelationalOperator: '<S119>/Compare'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  rtb_OR = ((localDW->UnitDelay_DSTATE < 1500) || rtu_Inport6);

  /* DiscreteIntegrator: '<S104>/Integrator' */
  if (rtb_OR || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0;
  }

  /* Sum: '<S113>/Sum' incorporates:
   *  Constant: '<S6>/Constant6'
   *  DiscreteIntegrator: '<S104>/Integrator'
   *  Product: '<S109>/PProd Out'
   */
  rtb_IProdOut = (int16_T)((int16_T)((Sig_dAxis_errorSum_m * Kp_dAxis) >> 5) +
    localDW->Integrator_DSTATE);

  /* DeadZone: '<S97>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 2047) {
    tmp_0 = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
    tmp_0 = MIN_int16_T;
  } else {
    tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
  }

  if (rtb_IProdOut > tmp_0) {
    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      tmp_0 = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      tmp_0 = MIN_int16_T;
    } else {
      tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    rtb_Sum_j = (int16_T)(rtb_IProdOut - tmp_0);
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 2047) {
      tmp_0 = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
      tmp_0 = MIN_int16_T;
    } else {
      tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
    }

    if (rtb_IProdOut >= tmp_0) {
      rtb_Sum_j = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 2047) {
        tmp_0 = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
        tmp_0 = MIN_int16_T;
      } else {
        tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
      }

      rtb_Sum_j = (int16_T)(rtb_IProdOut - tmp_0);
    }
  }

  /* End of DeadZone: '<S97>/DeadZone' */

  /* RelationalOperator: '<S97>/NotEqual' */
  rtb_NotEqual = (0 != rtb_Sum_j);

  /* Signum: '<S97>/SignPreSat' */
  if (rtb_Sum_j < 0) {
    rtb_Sum_j = -1;
  } else {
    rtb_Sum_j = (int16_T)(rtb_Sum_j > 0);
  }

  /* End of Signum: '<S97>/SignPreSat' */

  /* DataTypeConversion: '<S97>/DataTypeConv1' */
  rtb_DataTypeConv2 = (int8_T)rtb_Sum_j;

  /* Product: '<S101>/IProd Out' incorporates:
   *  Constant: '<S6>/Constant7'
   */
  rtb_Sum_j = (int16_T)((Sig_dAxis_errorSum_m * Ki_dAxis) >> 5);

  /* Signum: '<S97>/SignPreIntegrator' */
  if (rtb_Sum_j < 0) {
    rtb_Switch_e = -1;
  } else {
    rtb_Switch_e = (int16_T)(rtb_Sum_j > 0);
  }

  /* End of Signum: '<S97>/SignPreIntegrator' */

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Constant1'
   *  DataTypeConversion: '<S97>/DataTypeConv2'
   *  Logic: '<S97>/AND3'
   *  RelationalOperator: '<S97>/Equal1'
   */
  if (rtb_NotEqual && (rtb_DataTypeConv2 == rtb_Switch_e)) {
    rtb_Switch_e = 0;
  } else {
    rtb_Switch_e = rtb_Sum_j;
  }

  /* End of Switch: '<S97>/Switch' */

  /* Saturate: '<S111>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 2047) {
    tmp_0 = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
    tmp_0 = MIN_int16_T;
  } else {
    tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
  }

  if (d_q_Voltage_Limiter_sat_pos > 2047) {
    tmp = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
    tmp = MIN_int16_T;
  } else {
    tmp = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
  }

  if (rtb_IProdOut > tmp) {
    *rty_d = tmp;
  } else if (rtb_IProdOut < tmp_0) {
    *rty_d = tmp_0;
  } else {
    *rty_d = rtb_IProdOut;
  }

  /* End of Saturate: '<S111>/Saturation' */

  /* DiscreteIntegrator: '<S60>/Integrator' */
  if (rtb_OR || (localDW->Integrator_PrevResetState_l != 0)) {
    localDW->Integrator_DSTATE_m = 0;
  }

  /* Sum: '<S6>/Add1' */
  Sig_qAxis_errorSum_m = (int16_T)(rtu_qRef - rtu_In6);

  /* Sum: '<S69>/Sum' incorporates:
   *  Constant: '<S6>/Constant4'
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Product: '<S65>/PProd Out'
   */
  rtb_Sum_j = (int16_T)((int16_T)((Sig_qAxis_errorSum_m * Kp_qAxis) >> 5) +
                        localDW->Integrator_DSTATE_m);

  /* DeadZone: '<S53>/DeadZone' */
  if (d_q_Voltage_Limiter_sat_pos > 2047) {
    tmp_0 = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
    tmp_0 = MIN_int16_T;
  } else {
    tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
  }

  if (rtb_Sum_j > tmp_0) {
    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      tmp_0 = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      tmp_0 = MIN_int16_T;
    } else {
      tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    rtb_IProdOut = (int16_T)(rtb_Sum_j - tmp_0);
  } else {
    if (d_q_Voltage_Limiter_sat_neg > 2047) {
      tmp_0 = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
      tmp_0 = MIN_int16_T;
    } else {
      tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
    }

    if (rtb_Sum_j >= tmp_0) {
      rtb_IProdOut = 0;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 2047) {
        tmp_0 = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
        tmp_0 = MIN_int16_T;
      } else {
        tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
      }

      rtb_IProdOut = (int16_T)(rtb_Sum_j - tmp_0);
    }
  }

  /* End of DeadZone: '<S53>/DeadZone' */

  /* RelationalOperator: '<S53>/NotEqual' */
  rtb_NotEqual = (0 != rtb_IProdOut);

  /* Signum: '<S53>/SignPreSat' */
  if (rtb_IProdOut < 0) {
    rtb_IProdOut = -1;
  } else {
    rtb_IProdOut = (int16_T)(rtb_IProdOut > 0);
  }

  /* End of Signum: '<S53>/SignPreSat' */

  /* DataTypeConversion: '<S53>/DataTypeConv1' */
  rtb_DataTypeConv2 = (int8_T)rtb_IProdOut;

  /* Product: '<S57>/IProd Out' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  rtb_IProdOut = (int16_T)((Sig_qAxis_errorSum_m * Ki_qAxis) >> 5);

  /* Saturate: '<S67>/Saturation' */
  if (d_q_Voltage_Limiter_sat_neg > 2047) {
    tmp_0 = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
    tmp_0 = MIN_int16_T;
  } else {
    tmp_0 = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
  }

  if (d_q_Voltage_Limiter_sat_pos > 2047) {
    tmp = MAX_int16_T;
  } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
    tmp = MIN_int16_T;
  } else {
    tmp = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
  }

  if (rtb_Sum_j > tmp) {
    *rty_q = tmp;
  } else if (rtb_Sum_j < tmp_0) {
    *rty_q = tmp_0;
  } else {
    *rty_q = rtb_Sum_j;
  }

  /* End of Saturate: '<S67>/Saturation' */

  /* Update for DiscreteIntegrator: '<S104>/Integrator' */
  localDW->Integrator_DSTATE = (int16_T)(((6711 * rtb_Switch_e) >> 25) +
    localDW->Integrator_DSTATE);
  localDW->Integrator_PrevResetState = (int8_T)rtb_OR;

  /* Signum: '<S53>/SignPreIntegrator' */
  if (rtb_IProdOut < 0) {
    rtb_Sum_j = -1;
  } else {
    rtb_Sum_j = (int16_T)(rtb_IProdOut > 0);
  }

  /* End of Signum: '<S53>/SignPreIntegrator' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Constant1'
   *  DataTypeConversion: '<S53>/DataTypeConv2'
   *  Logic: '<S53>/AND3'
   *  RelationalOperator: '<S53>/Equal1'
   */
  if (rtb_NotEqual && (rtb_DataTypeConv2 == rtb_Sum_j)) {
    rtb_IProdOut = 0;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  localDW->Integrator_DSTATE_m = (int16_T)(((6711 * rtb_IProdOut) >> 25) +
    localDW->Integrator_DSTATE_m);
  localDW->Integrator_PrevResetState_l = (int8_T)rtb_OR;
}

/* System reset for enable system: '<Root>/Position observer' */
void MotorCon_Positionobserver_Reset(DW_Positionobserver_MotorCont_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  localDW->UnitDelay_DSTATE_cm = 0;

  /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k = 0;

  /* InitializeConditions for Delay: '<S126>/Delay' */
  localDW->Delay_DSTATE_l = 0;

  /* InitializeConditions for UnitDelay: '<S127>/Unit Delay' */
  localDW->UnitDelay_DSTATE_o = 0;

  /* InitializeConditions for Delay: '<S127>/Delay' */
  localDW->Delay_DSTATE_k = 0;

  /* InitializeConditions for Saturate: '<S134>/Saturation' incorporates:
   *  UnitDelay: '<S125>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S129>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p = 0;

  /* InitializeConditions for Delay: '<S129>/Delay' */
  localDW->Delay_DSTATE_b = 0;

  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
  localDW->UnitDelay_DSTATE_mq = 0;

  /* InitializeConditions for Delay: '<S128>/Delay' */
  localDW->Delay_DSTATE_e = 0;

  /* SystemReset for Atomic SubSystem: '<S124>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S130>/Unit Delay' */
  localDW->UnitDelay_DSTATE_c = 0.0F;

  /* InitializeConditions for Delay: '<S130>/Delay' */
  UnitDelayIntegratorPosObs = 0.0F;

  /* End of SystemReset for SubSystem: '<S124>/DC Motor Model' */

  /* SystemReset for Atomic SubSystem: '<S125>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S133>/Unit Delay' */
  localDW->UnitDelay_DSTATE_m = 0;

  /* InitializeConditions for Delay: '<S133>/Delay' */
  localDW->Delay_DSTATE = 0;

  /* End of SystemReset for SubSystem: '<S125>/DC Motor Model' */
}

/* Disable for enable system: '<Root>/Position observer' */
void MotorC_Positionobserver_Disable(DW_Positionobserver_MotorCont_T *localDW)
{
  localDW->Positionobserver_MODE = false;
}

/* Output and update for enable system: '<Root>/Position observer' */
void MotorControlLi_Positionobserver(RT_MODEL_MotorControlLibNEWFi_T * const
  MotorControlLibNEWFixedP_FUL_M, boolean_T rtu_Enable, int16_T rtu_Va, int16_T
  rtu_Vb, int16_T rtu_Ia, int16_T rtu_Ib, boolean_T rtu_In5, int16_T *rty_theta,
  B_Positionobserver_MotorContr_T *localB, DW_Positionobserver_MotorCont_T
  *localDW, ZCE_Positionobserver_MotorCon_T *localZCE)
{
  real32_T rtb_Atan2_p;
  int16_T rtb_Add6;
  int16_T rtb_Add2_k;
  real32_T u2;
  real32_T u;
  real32_T v;

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
    if (rtu_Enable) {
      if (!localDW->Positionobserver_MODE) {
        MotorCon_Positionobserver_Reset(localDW);
        localDW->Positionobserver_MODE = true;
      }
    } else {
      if (localDW->Positionobserver_MODE) {
        MotorC_Positionobserver_Disable(localDW);
      }
    }
  }

  if (localDW->Positionobserver_MODE) {
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
      /* DataTypeConversion: '<S9>/Data Type Conversion' */
      rtb_Atan2_p = (real32_T)rtu_Ia * 0.00390625F;

      /* UnitDelay: '<S124>/Unit Delay' */
      localB->UnitDelay = localDW->UnitDelay_DSTATE;

      /* UnitDelay: '<S9>/Unit Delay' */
      localB->UnitDelay_n = localDW->UnitDelay_DSTATE_cm;
    }

    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
      /* DataTypeConversion: '<S9>/Data Type Conversion1' */
      localB->DataTypeConversion1 = (real32_T)rtu_Va * 0.00390625F;
    }

    /* Outputs for Atomic SubSystem: '<S124>/DC Motor Model' */
    /* Gain: '<S130>/Inductance' incorporates:
     *  UnitDelay: '<S130>/Unit Delay'
     */
    di_dt_E9 = EMFobsLdGain * localDW->UnitDelay_DSTATE_c;

    /* Gain: '<S130>/Gain' */
    di_dt_times_Ts_En8 = TsIntern * di_dt_E9;

    /* Sum: '<S130>/Sum' incorporates:
     *  Delay: '<S130>/Delay'
     */
    i_integrated_en4 = di_dt_times_Ts_En8 + UnitDelayIntegratorPosObs;

    /* Gain: '<S130>/Resistance' */
    i_integrated_times_Rs_en8 = EMFobsRS * i_integrated_en4;

    /* Sum: '<S130>/Add5' */
    Va_all_16En4 = ((localB->DataTypeConversion1 - i_integrated_times_Rs_en8) -
                    localB->UnitDelay) - (real32_T)localB->UnitDelay_n *
      0.015625F;

    /* Update for UnitDelay: '<S130>/Unit Delay' */
    localDW->UnitDelay_DSTATE_c = Va_all_16En4;

    /* Update for Delay: '<S130>/Delay' */
    UnitDelayIntegratorPosObs = i_integrated_en4;

    /* End of Outputs for SubSystem: '<S124>/DC Motor Model' */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S124>/Add6' */
      Sig_Emfobs_errorSum_m = i_integrated_en4 - rtb_Atan2_p;

      /* Outputs for Enabled SubSystem: '<S131>/Anti-windup' incorporates:
       *  EnablePort: '<S132>/Enable'
       */
      /* RelationalOperator: '<S131>/Relational Operator' incorporates:
       *  Abs: '<S131>/Abs'
       *  Constant: '<S131>/Ki activation treashold'
       */
      if (fabsf(Sig_Emfobs_errorSum_m) <= 0.23F) {
        /* Delay: '<S132>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE_j == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE_j != UNINITIALIZED_ZCSIG)) || rtu_In5)
        {
          localDW->Delay1_DSTATE_m = 0;
        }

        localZCE->Delay1_Reset_ZCE_j = rtu_In5;

        /* Sum: '<S132>/Sum1' incorporates:
         *  Delay: '<S132>/Delay1'
         *  Gain: '<S132>/Gain1'
         *  Gain: '<S132>/Ki'
         */
        u2 = floorf(((real32_T)Ki_Iab_EMFobs * 0.125F * Sig_Emfobs_errorSum_m *
                     0.000244140625F + (real32_T)localDW->Delay1_DSTATE_m *
                     0.00390625F) * 256.0F);
        if (rtIsNaNF(u2) || rtIsInfF(u2)) {
          u2 = 0.0F;
        } else {
          u2 = fmodf(u2, 65536.0F);
        }

        localB->Sum1_p = (int16_T)(u2 < 0.0F ? (int32_T)(int16_T)-(int16_T)
          (uint16_T)-u2 : (int32_T)(int16_T)(uint16_T)u2);

        /* End of Sum: '<S132>/Sum1' */

        /* Update for Delay: '<S132>/Delay1' */
        localDW->Delay1_DSTATE_m = localB->Sum1_p;
      }

      /* End of RelationalOperator: '<S131>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S131>/Anti-windup' */

      /* Sum: '<S131>/Add1' incorporates:
       *  Gain: '<S131>/Kp'
       */
      Sig_Emfobs_PI_out = (real32_T)Kp_Iab_EMFobs * 0.00390625F *
        Sig_Emfobs_errorSum_m + (real32_T)localB->Sum1_p * 0.00390625F;

      /* Saturate: '<S131>/Saturation' */
      rtb_Atan2_p = (real32_T)MaxBckEMFVol_sat_neg * 0.25F;
      u2 = (real32_T)MaxBckEMFVol_sat_pos * 0.25F;
      if (Sig_Emfobs_PI_out > u2) {
        /* Sum: '<S131>/Add1' */
        Sig_Emfobs_PI_out = u2;
      } else {
        if (Sig_Emfobs_PI_out < rtb_Atan2_p) {
          /* Sum: '<S131>/Add1' */
          Sig_Emfobs_PI_out = rtb_Atan2_p;
        }
      }

      /* End of Saturate: '<S131>/Saturation' */

      /* Gain: '<S126>/Gain' incorporates:
       *  Sum: '<S126>/Add2'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      u2 = floorf((Sig_Emfobs_PI_out - (real32_T)localDW->UnitDelay_DSTATE_k *
                   0.015625F) * 0.000244140625F * 16384.0F);
      if (u2 < 32768.0F) {
        if (u2 >= -32768.0F) {
          rtb_Add6 = (int16_T)u2;
        } else {
          rtb_Add6 = MIN_int16_T;
        }
      } else {
        rtb_Add6 = MAX_int16_T;
      }

      /* End of Gain: '<S126>/Gain' */

      /* Sum: '<S126>/Sum' incorporates:
       *  Delay: '<S126>/Delay'
       */
      localDW->Delay_DSTATE_l += rtb_Add6;

      /* Product: '<S126>/Product1' incorporates:
       *  Constant: '<S126>/Constant'
       *  Delay: '<S126>/Delay'
       */
      Sig_First_LPF_out = (int16_T)((localDW->Delay_DSTATE_l * CuttOffFreq_c) >>
        8);

      /* Sum: '<S127>/Sum' incorporates:
       *  Delay: '<S127>/Delay'
       *  Gain: '<S127>/Gain'
       *  Sum: '<S127>/Add2'
       *  UnitDelay: '<S127>/Unit Delay'
       */
      localDW->Delay_DSTATE_k = (int16_T)(((int16_T)(Sig_First_LPF_out -
        localDW->UnitDelay_DSTATE_o) >> 4) + localDW->Delay_DSTATE_k);

      /* Product: '<S127>/Product1' incorporates:
       *  Constant: '<S127>/Constant'
       *  Delay: '<S127>/Delay'
       */
      Sig_Second_LPF_out = (int16_T)((localDW->Delay_DSTATE_k * CuttOffFreq_c) >>
        8);

      /* DataTypeConversion: '<S123>/Data Type Conversion6' */
      rtb_Atan2_p = (real32_T)Sig_Second_LPF_out * 0.015625F;

      /* DataTypeConversion: '<S125>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion2'
       */
      rtb_Add2_k = (int16_T)(rtu_Ib >> 4);

      /* UnitDelay: '<S125>/Unit Delay' */
      localB->UnitDelay_j = localDW->UnitDelay_DSTATE_g;

      /* UnitDelay: '<S9>/Unit Delay1' */
      localB->UnitDelay1 = localDW->UnitDelay1_DSTATE;
    }

    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
      /* DataTypeConversion: '<S9>/Data Type Conversion3' */
      localB->DataTypeConversion3 = (real32_T)rtu_Vb * 0.00390625F;
    }

    /* Outputs for Atomic SubSystem: '<S125>/DC Motor Model' */
    /* Gain: '<S133>/Inductance' */
    u = EMFobsLdGain * 0.5F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_Add6 = (int16_T)u;
      } else {
        rtb_Add6 = MIN_int16_T;
      }
    } else {
      rtb_Add6 = MAX_int16_T;
    }

    /* Gain: '<S133>/Gain' incorporates:
     *  Gain: '<S133>/Inductance'
     *  UnitDelay: '<S133>/Unit Delay'
     */
    u2 = floorf((real32_T)(int16_T)((rtb_Add6 * localDW->UnitDelay_DSTATE_m) >>
      12) * 512.0F * TsIntern * 16.0F);
    if (u2 < 32768.0F) {
      if (u2 >= -32768.0F) {
        localDW->UnitDelay_DSTATE_m = (int16_T)u2;
      } else {
        localDW->UnitDelay_DSTATE_m = MIN_int16_T;
      }
    } else {
      localDW->UnitDelay_DSTATE_m = MAX_int16_T;
    }

    /* End of Gain: '<S133>/Gain' */

    /* Sum: '<S133>/Sum' incorporates:
     *  Delay: '<S133>/Delay'
     *  UnitDelay: '<S133>/Unit Delay'
     */
    localDW->Delay_DSTATE += localDW->UnitDelay_DSTATE_m;

    /* Sum: '<S133>/Add5' */
    u2 = floorf(localB->DataTypeConversion3 * 16.0F);
    if (rtIsNaNF(u2) || rtIsInfF(u2)) {
      u2 = 0.0F;
    } else {
      u2 = fmodf(u2, 65536.0F);
    }

    /* Gain: '<S133>/Resistance' */
    u = EMFobsRS * 65536.0F;
    v = fabsf(u);
    if (v < 8.388608E+6F) {
      if (v >= 0.5F) {
        u = floorf(u + 0.5F);
      } else {
        u *= 0.0F;
      }
    }

    if (u < 32768.0F) {
      if (u >= -32768.0F) {
        rtb_Add6 = (int16_T)u;
      } else {
        rtb_Add6 = MIN_int16_T;
      }
    } else {
      rtb_Add6 = MAX_int16_T;
    }

    /* Sum: '<S133>/Add5' incorporates:
     *  Delay: '<S133>/Delay'
     *  Gain: '<S133>/Resistance'
     *  UnitDelay: '<S133>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE_m = (int16_T)((int16_T)((int16_T)((u2 < 0.0F ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-u2 : (int32_T)(int16_T)(uint16_T)u2)
      - ((rtb_Add6 * localDW->Delay_DSTATE) >> 16)) - localB->UnitDelay_j) -
      (localB->UnitDelay1 >> 2));

    /* End of Outputs for SubSystem: '<S125>/DC Motor Model' */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
      /* Sum: '<S125>/Add6' incorporates:
       *  Delay: '<S133>/Delay'
       */
      rtb_Add6 = (int16_T)(localDW->Delay_DSTATE - rtb_Add2_k);

      /* Outputs for Atomic SubSystem: '<S125>/PI Controller' */
      /* Abs: '<S134>/Abs' */
      if (rtb_Add6 < 0) {
        rtb_Add2_k = (int16_T)-rtb_Add6;
      } else {
        rtb_Add2_k = rtb_Add6;
      }

      /* End of Abs: '<S134>/Abs' */

      /* Outputs for Enabled SubSystem: '<S134>/Anti-windup' incorporates:
       *  EnablePort: '<S135>/Enable'
       */
      /* RelationalOperator: '<S134>/Relational Operator' incorporates:
       *  Constant: '<S134>/Constant1'
       */
      if ((rtb_Add2_k << 4) <= 59) {
        /* Delay: '<S135>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtu_In5) {
          localDW->Delay1_DSTATE = 0;
        }

        localZCE->Delay1_Reset_ZCE = rtu_In5;

        /* Sum: '<S135>/Sum1' incorporates:
         *  Delay: '<S135>/Delay1'
         *  Gain: '<S135>/Gain1'
         *  Gain: '<S135>/Ki'
         */
        localB->Sum1 = (int16_T)((((int16_T)((Ki_Iab_EMFobs * rtb_Add6) >> 3) >>
          4) + (localDW->Delay1_DSTATE << 4)) >> 4);

        /* Update for Delay: '<S135>/Delay1' */
        localDW->Delay1_DSTATE = localB->Sum1;
      }

      /* End of RelationalOperator: '<S134>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S134>/Anti-windup' */

      /* Sum: '<S134>/Add1' incorporates:
       *  Gain: '<S134>/Kp'
       */
      rtb_Add2_k = (int16_T)((((int16_T)((Kp_Iab_EMFobs * rtb_Add6) >> 8) << 4)
        + localB->Sum1) >> 4);

      /* Saturate: '<S134>/Saturation' incorporates:
       *  UnitDelay: '<S125>/Unit Delay'
       */
      if (MaxBckEMFVol_sat_neg > 8191) {
        localDW->UnitDelay_DSTATE_g = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_neg <= -8192) {
        localDW->UnitDelay_DSTATE_g = MIN_int16_T;
      } else {
        localDW->UnitDelay_DSTATE_g = (int16_T)(MaxBckEMFVol_sat_neg << 2);
      }

      if (MaxBckEMFVol_sat_pos > 8191) {
        rtb_Add6 = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_pos <= -8192) {
        rtb_Add6 = MIN_int16_T;
      } else {
        rtb_Add6 = (int16_T)(MaxBckEMFVol_sat_pos << 2);
      }

      if (rtb_Add2_k > rtb_Add6) {
        localDW->UnitDelay_DSTATE_g = rtb_Add6;
      } else {
        if (rtb_Add2_k >= localDW->UnitDelay_DSTATE_g) {
          localDW->UnitDelay_DSTATE_g = rtb_Add2_k;
        }
      }

      /* End of Saturate: '<S134>/Saturation' */
      /* End of Outputs for SubSystem: '<S125>/PI Controller' */

      /* Sum: '<S129>/Sum' incorporates:
       *  Delay: '<S129>/Delay'
       *  Gain: '<S129>/Gain'
       *  Sum: '<S129>/Add2'
       *  UnitDelay: '<S125>/Unit Delay'
       *  UnitDelay: '<S129>/Unit Delay'
       */
      localDW->Delay_DSTATE_b = (int16_T)(((int16_T)
        (((localDW->UnitDelay_DSTATE_g << 2) - localDW->UnitDelay_DSTATE_p) >> 2)
        >> 2) + localDW->Delay_DSTATE_b);

      /* Product: '<S129>/Product1' incorporates:
       *  Constant: '<S129>/Constant'
       *  Delay: '<S129>/Delay'
       *  UnitDelay: '<S129>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_p = (int16_T)((localDW->Delay_DSTATE_b *
        CuttOffFreq_c) >> 8);

      /* Sum: '<S128>/Sum' incorporates:
       *  Delay: '<S128>/Delay'
       *  Gain: '<S128>/Gain'
       *  Sum: '<S128>/Add2'
       *  UnitDelay: '<S128>/Unit Delay'
       *  UnitDelay: '<S129>/Unit Delay'
       */
      localDW->Delay_DSTATE_e = (int16_T)(((int16_T)(localDW->UnitDelay_DSTATE_p
        - localDW->UnitDelay_DSTATE_mq) >> 4) + localDW->Delay_DSTATE_e);

      /* Product: '<S128>/Product1' incorporates:
       *  Constant: '<S128>/Constant'
       *  Delay: '<S128>/Delay'
       *  UnitDelay: '<S128>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_mq = (int16_T)((localDW->Delay_DSTATE_e *
        CuttOffFreq_c) >> 8);

      /* Trigonometry: '<S123>/Atan2' incorporates:
       *  DataTypeConversion: '<S123>/Data Type Conversion7'
       *  UnitDelay: '<S128>/Unit Delay'
       */
      rtb_Atan2_p = rt_atan2f_snf_cordic6(rtb_Atan2_p, (real32_T)
        localDW->UnitDelay_DSTATE_mq * 0.015625F);

      /* DataTypeConversion: '<S123>/Data Type Conversion5' */
      u2 = floorf(rtb_Atan2_p * 256.0F);
      if (rtIsNaNF(u2) || rtIsInfF(u2)) {
        u2 = 0.0F;
      } else {
        u2 = fmodf(u2, 65536.0F);
      }

      *rty_theta = (int16_T)(u2 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
        -u2 : (int32_T)(int16_T)(uint16_T)u2);

      /* End of DataTypeConversion: '<S123>/Data Type Conversion5' */

      /* Update for UnitDelay: '<S124>/Unit Delay' */
      localDW->UnitDelay_DSTATE = Sig_Emfobs_PI_out;

      /* Update for UnitDelay: '<S9>/Unit Delay' */
      localDW->UnitDelay_DSTATE_cm = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S126>/Unit Delay' */
      localDW->UnitDelay_DSTATE_k = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S127>/Unit Delay' */
      localDW->UnitDelay_DSTATE_o = Sig_Second_LPF_out;

      /* Update for UnitDelay: '<S9>/Unit Delay1' incorporates:
       *  UnitDelay: '<S129>/Unit Delay'
       */
      localDW->UnitDelay1_DSTATE = localDW->UnitDelay_DSTATE_p;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
}

/* Model step function */
void MotorControlLibNEWFixedP_FULL19b_step(void)
{
  int16_T minV;
  int32_T rowIdx;
  int32_T rowIdx_0;
  uint16_T rtb_uDLookupTable2;
  int16_T rtb_Switch_d[2];
  boolean_T rtb_FixPtRelationalOperator;
  int16_T rtb_convert_pu;
  int16_T rtb_RateTransition1;
  int16_T rtb_a;
  int16_T rtb_Abs;
  int16_T rtb_one_by_two;
  int16_T rtb_VectorConcatenate[2];
  uint32_T rtb_Sum_idx_3;
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Delay: '<Root>/Delay' */
    Sig_theta_el_m = MotorControlLibNEWFixedP_FULL_Y.Position;

    /* Gain: '<S13>/convert_pu' */
    rtb_convert_pu = (int16_T)((20861 * Sig_theta_el_m) >> 17);

    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* If: '<S13>/If' incorporates:
     *  DataTypeConversion: '<S15>/Convert_back'
     *  DataTypeConversion: '<S15>/Convert_uint16'
     *  Sum: '<S15>/Sum'
     */
    rtb_convert_pu = (int16_T)(rtb_convert_pu - ((rtb_convert_pu >> 8) << 8));

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */

    /* Gain: '<S11>/indexing' */
    rtb_convert_pu = (int16_T)(100 * rtb_convert_pu);

    /* DataTypeConversion: '<S11>/Get_Integer' */
    rtb_uDLookupTable2 = (uint16_T)(rtb_convert_pu >> 6);

    /* Sum: '<S11>/Sum' */
    rtb_Sum_idx_3 = rtb_uDLookupTable2 + 100U;

    /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
     *  Inport: '<Root>/Inport'
     *  Inport: '<Root>/Inport7'
     */
    ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

    /* DataTypeConversion: '<S11>/Get_FractionVal' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  Sum: '<S11>/Sum2'
     */
    rtb_a = (int16_T)((int16_T)(rtb_convert_pu - (int16_T)((int16_T)
      rtb_uDLookupTable2 << 6)) << 2);

    /* Sum: '<S12>/Sum6' incorporates:
     *  Constant: '<S11>/sine_table_values'
     *  Product: '<S12>/Product1'
     *  Selector: '<S11>/Lookup'
     *  Sum: '<S11>/Sum'
     *  Sum: '<S12>/Sum5'
     */
    Sig_cos_m = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
      [(int32_T)(rtb_uDLookupTable2 + 101U)] - rtCP_sine_table_values_Value
      [(int32_T)rtb_Sum_idx_3]) * rtb_a) >> 8) + rtCP_sine_table_values_Value
                          [(int32_T)rtb_Sum_idx_3]);

    /* Gain: '<S1>/one_by_sqrt3' incorporates:
     *  Sum: '<S1>/a_plus_2b'
     */
    Sig_Ibeta_m = (int16_T)(((int16_T)((int16_T)(Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m)
      * 18919) >> 15);

    /* Sum: '<S12>/Sum4' incorporates:
     *  Constant: '<S11>/sine_table_values'
     *  Product: '<S12>/Product'
     *  Selector: '<S11>/Lookup'
     *  Sum: '<S11>/Sum'
     *  Sum: '<S12>/Sum3'
     */
    Sig_sin_m = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
      [(int32_T)(rtb_uDLookupTable2 + 1U)] -
      rtCP_sine_table_values_Value[rtb_uDLookupTable2]) * rtb_a) >> 8) +
                          rtCP_sine_table_values_Value[rtb_uDLookupTable2]);

    /* Switch: '<S122>/Switch' incorporates:
     *  Product: '<S8>/acos'
     *  Product: '<S8>/asin'
     *  Product: '<S8>/bcos'
     *  Product: '<S8>/bsin'
     *  Sum: '<S8>/sum_Ds'
     *  Sum: '<S8>/sum_Qs'
     */
    rtb_Switch_d[0] = (int16_T)((int16_T)((Sig_Ia_m * Sig_cos_m) >> 8) +
      (int16_T)((Sig_Ibeta_m * Sig_sin_m) >> 8));
    rtb_Switch_d[1] = (int16_T)((int16_T)((Sig_Ibeta_m * Sig_cos_m) >> 8) -
      (int16_T)((Sig_Ia_m * Sig_sin_m) >> 8));

    /* Gain: '<Root>/Tq--> iqRef' incorporates:
     *  Constant: '<Root>/q Soll'
     */
    Sig_Iq_Soll = (int16_T)((TqToIqConst * qSoll) >> 8);

    /* Gain: '<Root>/Gain2' */
    Sig_dAxis_m = rtb_Switch_d[0];

    /* Gain: '<Root>/Gain3' */
    Sig_qAxis_m = rtb_Switch_d[1];

    /* Outputs for Atomic SubSystem: '<Root>/PI_Controller' */
    /* Constant: '<Root>/d Soll' incorporates:
     *  Inport: '<Root>/Inport6'
     */
    MotorControlLibNE_PI_Controller(dSoll, Sig_Iq_Soll, Sig_dAxis_m, Sig_qAxis_m,
      resetPIIntegratorDQ, &Sig_dAxis_PI_out, &Sig_qAxis_PI_out,
      &MotorControlLibNEWFixedP_FUL_DW.PI_Controller);

    /* End of Outputs for SubSystem: '<Root>/PI_Controller' */

    /* Outputs for Atomic SubSystem: '<Root>/DQ_Limiter' */
    MotorControlLibNEWFi_DQ_Limiter(Sig_dAxis_PI_out, Sig_qAxis_PI_out,
      rtb_Switch_d, &rtb_convert_pu, d_q_Voltage_Limiter_max);

    /* End of Outputs for SubSystem: '<Root>/DQ_Limiter' */

    /* Gain: '<Root>/Gain5' */
    Sig_Vqsatu_m = rtb_Switch_d[1];

    /* Gain: '<Root>/Gain4' */
    Sig_Vdsatu_m = rtb_Switch_d[0];

    /* Switch: '<S27>/Switch' incorporates:
     *  Product: '<S5>/dcos'
     *  Product: '<S5>/dsin'
     *  Product: '<S5>/qcos'
     *  Product: '<S5>/qsin'
     *  Sum: '<S5>/sum_alpha'
     *  Sum: '<S5>/sum_beta'
     */
    rtb_Switch_d[0] = (int16_T)((int16_T)((Sig_Vdsatu_m * Sig_cos_m) >> 8) -
      (int16_T)((Sig_Vqsatu_m * Sig_sin_m) >> 8));
    rtb_Switch_d[1] = (int16_T)((int16_T)((Sig_Vqsatu_m * Sig_cos_m) >> 8) +
      (int16_T)((Sig_Vdsatu_m * Sig_sin_m) >> 8));

    /* Gain: '<Root>/Gain' */
    Sig_Va_m = rtb_Switch_d[0];

    /* Gain: '<Root>/Gain1' */
    Sig_Vb_m = rtb_Switch_d[1];

    /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
    /* Gain: '<S120>/one_by_two' incorporates:
     *  Inport: '<S120>/In1'
     */
    rtb_convert_pu = (int16_T)(Sig_Va_m >> 1);

    /* Gain: '<S120>/sqrt3_by_two' */
    rtb_one_by_two = (int16_T)((14189 * Sig_Vb_m) >> 14);

    /* Sum: '<S120>/add_b' */
    Sig_Vbeta_m = (int16_T)(rtb_one_by_two - rtb_convert_pu);

    /* Sum: '<S120>/add_c' */
    Sig_Vgamma_m = (int16_T)(-rtb_convert_pu - rtb_one_by_two);

    /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */

    /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
    /* Gain: '<S121>/one_by_sqrt3' */
    rtb_Abs = (int16_T)((37 * Sig_Va_m) >> 6);

    /* Sum: '<S121>/a' */
    rtb_a = (int16_T)(rtb_Abs + rtb_Abs);

    /* Sum: '<S121>/b' */
    rtb_convert_pu = (int16_T)(Sig_Vb_m - rtb_Abs);

    /* Sum: '<S121>/c' */
    rtb_Abs = (int16_T)(-rtb_Abs - Sig_Vb_m);

    /* MinMax: '<S121>/Max' */
    if (rtb_a > rtb_convert_pu) {
      rtb_one_by_two = rtb_a;
    } else {
      rtb_one_by_two = rtb_convert_pu;
    }

    /* MinMax: '<S121>/Min' */
    if (rtb_a < rtb_convert_pu) {
      minV = rtb_a;
    } else {
      minV = rtb_convert_pu;
    }

    /* MinMax: '<S121>/Max' */
    if (rtb_one_by_two <= rtb_Abs) {
      rtb_one_by_two = rtb_Abs;
    }

    /* MinMax: '<S121>/Min' */
    if (minV >= rtb_Abs) {
      minV = rtb_Abs;
    }

    /* Gain: '<S121>/one_by_two' incorporates:
     *  Sum: '<S121>/Add'
     */
    rtb_one_by_two = (int16_T)((int16_T)(rtb_one_by_two + minV) >> 1);

    /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */

    /* Switch: '<S7>/Switch' incorporates:
     *  Inport: '<Root>/In1'
     *  Inport: '<S120>/In1'
     *  Sum: '<S121>/Da'
     *  Sum: '<S121>/Db'
     *  Switch: '<S7>/Switch1'
     */
    if (Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S7>/Inverse Clarke Transform' */
      Sig_Valpha_m = Sig_Va_m;

      /* End of Outputs for SubSystem: '<S7>/Inverse Clarke Transform' */
    } else {
      /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
      Sig_Valpha_m = (int16_T)(rtb_a - rtb_one_by_two);
      Sig_Vbeta_m = (int16_T)(rtb_convert_pu - rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */
    }

    /* End of Switch: '<S7>/Switch' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table'
     */
    set_PWM_A_DT(look1_is16lu32n16tu16_binlcse(Sig_Valpha_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table1'
     */
    set_PWM_B_DT(look1_is16lu32n16tu16_binlcse(Sig_Vbeta_m, (&(BrkPoints[0])), (
      &(pwmTableData[0])), 2U));

    /* Switch: '<S7>/Switch2' incorporates:
     *  Inport: '<Root>/In1'
     *  Sum: '<S121>/Dc'
     */
    if (!Sig_change_SVMalgorithm) {
      /* Outputs for Atomic SubSystem: '<S7>/Space Vector Generator' */
      Sig_Vgamma_m = (int16_T)(rtb_Abs - rtb_one_by_two);

      /* End of Outputs for SubSystem: '<S7>/Space Vector Generator' */
    }

    /* End of Switch: '<S7>/Switch2' */

    /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S7>/1-D Lookup Table2'
     */
    set_PWM_C_DT(look1_is16lu32n16tu16_binlcse(Sig_Vgamma_m, (&(BrkPoints[0])),
      (&(pwmTableData[0])), 2U));

    /* Outputs for Atomic SubSystem: '<Root>/Start up' */
    /* CombinatorialLogic: '<S142>/Logic' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Memory: '<S142>/Memory'
     *  RelationalOperator: '<S138>/Compare'
     *  UnitDelay: '<S136>/Unit Delay'
     */
    rowIdx = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
                         MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE) << 1)
                       + MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput);

    /* UnitDelay: '<S139>/Delay Input1'
     *
     * Block description for '<S139>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator =
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_f;

    /* UnitDelay: '<S136>/Unit Delay1' incorporates:
     *  UnitDelay: '<S139>/Delay Input1'
     *
     * Block description for '<S139>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_f =
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S139>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S139>/Delay Input1'
     *
     * Block description for '<S139>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = ((int32_T)
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_f < (int32_T)
      rtb_FixPtRelationalOperator);

    /* Outputs for Enabled SubSystem: '<S136>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S140>/Enable'
     */
    /* CombinatorialLogic: '<S142>/Logic' */
    if (rtCP_Logic_table[(uint32_T)rowIdx]) {
      /* RelationalOperator: '<S144>/FixPt Relational Operator' incorporates:
       *  Constant: '<Root>/q Soll'
       *  UnitDelay: '<S144>/Delay Input1'
       *
       * Block description for '<S144>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator = (qSoll !=
        MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE);

      /* Update for UnitDelay: '<S144>/Delay Input1' incorporates:
       *  Constant: '<Root>/q Soll'
       *
       * Block description for '<S144>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE = qSoll;
    }

    /* End of Outputs for SubSystem: '<S136>/Enabled Subsystem' */

    /* Memory: '<S143>/Memory' incorporates:
     *  UnitDelay: '<S136>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE =
      MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b;

    /* CombinatorialLogic: '<S143>/Logic' incorporates:
     *  UnitDelay: '<S136>/Unit Delay'
     */
    rowIdx_0 = (int32_T)(((((uint32_T)
      MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator << 1) +
      rtb_FixPtRelationalOperator) << 1) +
                         MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE);

    /* Outputs for Enabled SubSystem: '<S136>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S141>/Enable'
     */
    if (rtCP_Logic_table_m[(uint32_T)rowIdx_0]) {
      /* UnitDelay: '<S141>/Unit Delay1' */
      rtb_uDLookupTable2 = MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE;

      /* Sum: '<S141>/Add' incorporates:
       *  Constant: '<S141>/Constant'
       *  UnitDelay: '<S141>/Unit Delay1'
       */
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE++;

      /* RelationalOperator: '<S141>/Relational Operator' incorporates:
       *  Constant: '<S141>/Constant1'
       *  UnitDelay: '<S136>/Unit Delay1'
       */
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m = (rtb_uDLookupTable2 <=
        10000);
    }

    /* End of Outputs for SubSystem: '<S136>/Enabled Subsystem1' */

    /* UnitDelay: '<S137>/Unit Delay' */
    rtb_FixPtRelationalOperator =
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p;

    /* DiscreteIntegrator: '<S137>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S137>/Unit Delay'
     */
    if (MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p &&
        (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese <= 0))
    {
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    constantAngle =
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S137>/Discrete-Time Integrator' */

    /* Abs: '<S137>/Abs' */
    if (constantAngle < 0) {
      rtb_convert_pu = (int16_T)-constantAngle;
    } else {
      rtb_convert_pu = constantAngle;
    }

    /* End of Abs: '<S137>/Abs' */

    /* RelationalOperator: '<S137>/Relational Operator' incorporates:
     *  UnitDelay: '<S137>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p = (rtb_convert_pu >= 1608);

    /* Update for UnitDelay: '<S136>/Unit Delay' incorporates:
     *  CombinatorialLogic: '<S143>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE = rtCP_Logic_table_m
      [(uint32_T)rowIdx_0];

    /* Update for Memory: '<S142>/Memory' incorporates:
     *  CombinatorialLogic: '<S142>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput = rtCP_Logic_table
      [(uint32_T)rowIdx];

    /* Update for Memory: '<S143>/Memory' incorporates:
     *  CombinatorialLogic: '<S143>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b = rtCP_Logic_table_m
      [(uint32_T)rowIdx_0];

    /* Update for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)
      (((6711 * dth_dt) >> 17) +
       MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE);
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      rtb_FixPtRelationalOperator;

    /* End of Outputs for SubSystem: '<Root>/Start up' */
  }

  /* RateTransition: '<Root>/Rate Transition3' incorporates:
   *  SignalConversion generated from: '<S4>/Enable'
   */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<Root>/Rate Transition2' incorporates:
     *  RateTransition: '<Root>/Rate Transition4'
     */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLibNEWFixedP_FULL_B.RateTransition3 =
        MotorControlLibNEWFixedP_FUL_DW.RateTransition3_Buffer0;
      MotorControlLibNEWFixedP_FULL_B.RateTransition2 =
        MotorControlLibNEWFixedP_FUL_DW.RateTransition2_Buffer0;
      MotorControlLibNEWFixedP_FULL_B.RateTransition4 =
        MotorControlLibNEWFixedP_FUL_DW.RateTransition4_Buffer0;
    }

    /* End of RateTransition: '<Root>/Rate Transition2' */

    /* Outputs for Enabled SubSystem: '<Root>/FluxObsAngle' */
    MotorControlLibNEW_FluxObsAngle
      (MotorControlLibNEWFixedP_FULL_B.RateTransition4,
       MotorControlLibNEWFixedP_FULL_B.RateTransition3,
       MotorControlLibNEWFixedP_FULL_B.RateTransition2, Sig_Ia_m, Sig_Ibeta_m,
       &FluxObsAngle, &MotorControlLibNEWFixedP_FULL_B.FluxObsAngle_k,
       &MotorControlLibNEWFixedP_ConstB.FluxObsAngle_k,
       &MotorControlLibNEWFixedP_FUL_DW.FluxObsAngle_k,
       &MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k);

    /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */

    /* RateTransition: '<Root>/Rate Transition1' incorporates:
     *  SignalConversion generated from: '<S4>/Enable'
     */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
      MotorControlLibNEWFixedP_FUL_DW.RateTransition1_Buffer = FluxObsAngle;
    }
  }

  /* End of RateTransition: '<Root>/Rate Transition3' */

  /* RateTransition: '<Root>/Rate Transition1' */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
    rtb_RateTransition1 = MotorControlLibNEWFixedP_FUL_DW.RateTransition1_Buffer;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' */
  /* Inport: '<Root>/Inport3' incorporates:
   *  Inport: '<Root>/Inport5'
   */
  MotorControlLi_Positionobserver(MotorControlLibNEWFixedP_FUL_M,
    enablePositionObs, MotorControlLibNEWFixedP_FULL_B.RateTransition3,
    MotorControlLibNEWFixedP_FULL_B.RateTransition2, Sig_Ia_m, Sig_Ibeta_m,
    resetPIIntegrator, &PositionObsAnlge,
    &MotorControlLibNEWFixedP_FULL_B.Positionobserver,
    &MotorControlLibNEWFixedP_FUL_DW.Positionobserver,
    &MotorControlLibNEWFixed_PrevZCX.Positionobserver);

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Delay: '<Root>/Delay'
     *  Inport: '<Root>/Inport1'
     */
    switch (set_AngleInput) {
     case 0:
      MotorControlLibNEWFixedP_FULL_Y.Position = constantAngle;
      break;

     case 1:
      MotorControlLibNEWFixedP_FULL_Y.Position = rtb_RateTransition1;
      break;

     case 2:
      ConvertPWMtoAngle_step();
      MotorControlLibNEWFixedP_FULL_Y.Position = (Angle_sensor_in * 4) % (2 * 804); // pi = 804 in 2^-8
      break;

     default:
      MotorControlLibNEWFixedP_FULL_Y.Position = PositionObsAnlge;
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Delay: '<Root>/Delay'
     */
    MotorControlLibNEWFixedP_FULL_B.DataTypeConversion = (real32_T)
      MotorControlLibNEWFixedP_FULL_Y.Position * 0.00390625F;

    /* ModelReference: '<Root>/Calculate spin speed1' */
    CalcSpinSpeednDir(&MotorControlLibNEWFixedP_FULL_B.DataTypeConversion,
                      &(MotorControlLibNEWFixedP_FUL_DW.Calculatespinspeed1_InstanceDat.rtb),
                      &(MotorControlLibNEWFixedP_FUL_DW.Calculatespinspeed1_InstanceDat.rtdw));

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[0] = Sig_Ia_m;

    /* SignalConversion generated from: '<Root>/Vector Concatenate' */
    rtb_VectorConcatenate[1] = Sig_Ib_m;

    /* ModelReference: '<Root>/SafetyChecks' */
    SafetyChecks(&rtb_VectorConcatenate[0],
                 &(MotorControlLibNEWFixedP_FUL_DW.SafetyChecks_InstanceData.rtdw));

    /* Update for RateTransition: '<Root>/Rate Transition3' */
    MotorControlLibNEWFixedP_FUL_DW.RateTransition3_Buffer0 = rtb_Switch_d[0];

    /* Update for RateTransition: '<Root>/Rate Transition2' */
    MotorControlLibNEWFixedP_FUL_DW.RateTransition2_Buffer0 = rtb_Switch_d[1];

    /* Update for RateTransition: '<Root>/Rate Transition4' incorporates:
     *  Inport: '<Root>/Inport2'
     */
    MotorControlLibNEWFixedP_FUL_DW.RateTransition4_Buffer0 = enableFluxObs;
  }

  rate_scheduler();
}

/* Model initialize function */
void MotorControlLibNEWFixedP_FULL19b_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* external inputs */
  dth_dt = 210;
  Sig_change_SVMalgorithm = true;

  /* Model Initialize function for ModelReference Block: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab_initialize(rtmGetErrorStatusPointer(MotorControlLibNEWFixedP_FUL_M),
    &(MotorControlLibNEWFixedP_FUL_DW.ADCRAwToCurrentIabc_InstanceDat.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/Calculate spin speed1' */
  CalcSpinSpeednDir_initialize(rtmGetErrorStatusPointer
    (MotorControlLibNEWFixedP_FUL_M),
    &(MotorControlLibNEWFixedP_FUL_DW.Calculatespinspeed1_InstanceDat.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/SafetyChecks' */
  SafetyChecks_initialize(rtmGetErrorStatusPointer
    (MotorControlLibNEWFixedP_FUL_M),
    &(MotorControlLibNEWFixedP_FUL_DW.SafetyChecks_InstanceData.rtm));
  MotorControlLibNEWFixed_PrevZCX.Positionobserver.Delay1_Reset_ZCE_j =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.Positionobserver.Delay1_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE_o =
    UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Discrete-Time Integrator' */
  MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* End of SystemInitialize for SubSystem: '<Root>/Start up' */
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
