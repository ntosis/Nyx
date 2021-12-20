/*
 * File: MotorControlLibNEWFixedP_FULL19b.c
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Oct 22 10:10:23 2021
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
#include "mul_ssu32_loSR_sat.h"
#include "rt_atan2f_snf.h"
#include "rt_atan2f_snf_cordic6.h"

/* Exported block signals */
boolean_T enableFluxObs;               /* '<Root>/Inport2' */
uint8_T set_AngleInput;                /* '<Root>/Inport1' */
boolean_T enablePositionObs;           /* '<Root>/Inport3' */
int16_T dth_dt;                        /* '<Root>/Inport4' */
boolean_T resetPIIntegrator;           /* '<Root>/Inport5' */
int16_T Sig_theta_el_m;                /* '<Root>/Delay' */
int16_T Sig_Ia_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ib_m;                      /* '<Root>/ADCRAwToCurrent(Iabc)' */
int16_T Sig_Ibeta_m;                   /* '<S1>/one_by_sqrt3' */
int16_T Sig_qAxis_m;                   /* '<Root>/Gain3' */
int16_T Sig_qAxis_errorSum_m;          /* '<S5>/Add1' */
int16_T Sig_qAxis_PI_out;              /* '<S66>/Saturation' */
int16_T Sig_Vqsatu_m;                  /* '<Root>/Gain5' */
int16_T Sig_dAxis_m;                   /* '<Root>/Gain2' */
int16_T Sig_dAxis_errorSum_m;          /* '<S5>/Add' */
int16_T Sig_dAxis_PI_out;              /* '<S110>/Saturation' */
int16_T Sig_Vdsatu_m;                  /* '<Root>/Gain4' */
int16_T Sig_Va_m;                      /* '<Root>/Gain' */
int16_T Sig_Vb_m;                      /* '<Root>/Gain1' */
int16_T constantAngle;                 /* '<S134>/Discrete-Time Integrator' */
int16_T PositionObsAnlge;              /* '<S120>/Data Type Conversion5' */
int16_T FluxObsAngle;                  /* '<S16>/PositionGain' */
int16_T Sig_Emfobs_errorSum_m;         /* '<S121>/Add6' */
int16_T Sig_Emfobs_PI_out;             /* '<S128>/Saturation' */
int16_T Sig_First_LPF_out;             /* '<S123>/Product1'
                                        * 16En6
                                        */
int16_T Sig_Second_LPF_out;            /* '<S124>/Product1'
                                        * 16En6
                                        */
int16_T di_dt_times_Ts_En8;            /* '<S127>/Gain' */
int16_T i_integrated_en4;              /* '<S127>/Sum' */
int16_T i_integrated_times_Rs_en8;     /* '<S127>/Resistance' */
int16_T Va_all_16En4;                  /* '<S127>/Add5' */
int16_T di_dt_E9;                      /* '<S127>/Inductance' */

/* Exported block parameters */
uint32_T TsIntern = 839U;              /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S127>/Gain'
                                        *   '<S130>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
int16_T MaxBckEMFVol_sat_neg = -48;    /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S128>/Saturation'
                                        *   '<S131>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
int16_T MaxBckEMFVol_sat_pos = 48;     /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S128>/Saturation'
                                        *   '<S131>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
int16_T Ki_Iab_EMFobs = 0;             /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S129>/Ki'
                                        *   '<S132>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
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
int16_T Kp_Iab_EMFobs = 256;           /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S128>/Kp'
                                        *   '<S131>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
uint16_T CuttOffFreq_c = 4000U;        /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S123>/Constant'
                                        *   '<S124>/Constant'
                                        *   '<S125>/Constant'
                                        *   '<S126>/Constant'
                                        */
int8_T qSoll = 0;                      /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,8,2^-7,0)
                                        */

/* Exported block states */
int16_T UnitDelayIntegratorPosObs;     /* '<S127>/Delay' */

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
  if ((MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.00025s, 0.0s] */
    MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] = 0;
  }

  (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2])++;
  if ((MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2]) > 249) {/* Sample time: [0.0125s, 0.0s] */
    MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
    /* Delay: '<S19>/Delay' */
    if ((localZCE->Delay_Reset_ZCE == POS_ZCSIG) && (localZCE->Delay_Reset_ZCE
         != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE = 0;
    }

    localZCE->Delay_Reset_ZCE = 0U;

    /* Gain: '<S25>/ScalingR' */
    if (EMFobsRS > 127) {
      rtb_DataTypeConversion = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_DataTypeConversion = MIN_int16_T;
    } else {
      rtb_DataTypeConversion = (int16_T)(EMFobsRS << 8);
    }

    /* Sum: '<S19>/Sum' incorporates:
     *  Delay: '<S19>/Delay'
     *  Gain: '<S19>/Gain'
     *  Gain: '<S25>/ScalingR'
     *  Sum: '<S19>/Sum3'
     */
    localDW->Delay_DSTATE = (int16_T)((((int16_T)(rtu_In2 -
      ((rtb_DataTypeConversion * rtu_In4) >> 16)) * 16777) >> 22) +
      localDW->Delay_DSTATE);

    /* Delay: '<S18>/Delay' */
    if ((localZCE->Delay_Reset_ZCE_o == POS_ZCSIG) &&
        (localZCE->Delay_Reset_ZCE_o != UNINITIALIZED_ZCSIG)) {
      localDW->Delay_DSTATE_e = 0;
    }

    localZCE->Delay_Reset_ZCE_o = 0U;

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
    localDW->Delay_DSTATE_e = (int16_T)((((int16_T)(rtu_In1 -
      ((rtb_DataTypeConversion * rtu_In3) >> 16)) * 16777) >> 22) +
      localDW->Delay_DSTATE_e);

    /* Gain: '<S25>/ScalingL' incorporates:
     *  Gain: '<S24>/ScalingL'
     *  Switch: '<S18>/Switch'
     *  Switch: '<S19>/Switch'
     */
    if (EMFobsLdGain > 16383) {
      rtb_DataTypeConversion = MAX_int16_T;
      tmp_0 = MAX_int16_T;
    } else {
      rtb_DataTypeConversion = (int16_T)(EMFobsLdGain << 1);
      tmp_0 = rtb_DataTypeConversion;
    }

    /* Outputs for Atomic SubSystem: '<S16>/atan2' */
    /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     *  DataTypeConversion: '<S17>/Data Type Conversion2'
     *  Delay: '<S18>/Delay'
     *  Delay: '<S19>/Delay'
     *  Gain: '<S24>/ScalingL'
     *  Gain: '<S25>/ScalingL'
     *  Sum: '<S18>/Sum1'
     *  Sum: '<S19>/Sum1'
     *  Switch: '<S18>/Switch'
     *  Switch: '<S19>/Switch'
     *  Trigonometry: '<S17>/Atan2'
     */
    tmp = floorf(rt_atan2f_snf((real32_T)(int16_T)(localDW->Delay_DSTATE -
      (int16_T)((int16_T)(rtb_DataTypeConversion * rtu_In4) << 5)) *
      0.000244140625F, (real32_T)(int16_T)(localDW->Delay_DSTATE_e - (int16_T)
      ((int16_T)(tmp_0 * rtu_In3) << 5)) * 0.000244140625F) * 4096.0F);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = fmodf(tmp, 65536.0F);
    }

    rtb_DataTypeConversion = (int16_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

    /* Outputs for Enabled SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (localC->Compare) {
      /* Inport: '<S22>/In1' */
      localB->Merge = rtb_DataTypeConversion;
    }

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */

    /* Outputs for Enabled SubSystem: '<S17>/per Uint' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (localC->Compare_l) {
      /* Gain: '<S23>/Gain' */
      localB->Merge = (int16_T)((20861 * rtb_DataTypeConversion) >> 17);

      /* Switch: '<S23>/Switch' incorporates:
       *  Bias: '<S23>/Bias'
       */
      if (localB->Merge < 0) {
        localB->Merge = (int16_T)(localB->Merge + 4096);
      }

      /* End of Switch: '<S23>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S17>/per Uint' */

    /* Gain: '<S16>/PositionGain' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S17>/a16'
     */
    *rty_FluxObsAngle = (int16_T)((3217 * localB->Merge) >> 13);

    /* End of Outputs for SubSystem: '<S16>/atan2' */
  }

  /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */
}

/* System reset for enable system: '<Root>/Position observer' */
void MotorCon_Positionobserver_Reset(DW_Positionobserver_MotorCont_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S121>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  localDW->UnitDelay_DSTATE_cm = 0;

  /* InitializeConditions for UnitDelay: '<S123>/Unit Delay' */
  localDW->UnitDelay_DSTATE_k = 0;

  /* InitializeConditions for Delay: '<S123>/Delay' */
  localDW->Delay_DSTATE_l = 0;

  /* InitializeConditions for UnitDelay: '<S124>/Unit Delay' */
  localDW->UnitDelay_DSTATE_o = 0;

  /* InitializeConditions for Delay: '<S124>/Delay' */
  localDW->Delay_DSTATE_k = 0;

  /* InitializeConditions for Saturate: '<S131>/Saturation' incorporates:
   *  UnitDelay: '<S122>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p = 0;

  /* InitializeConditions for Delay: '<S126>/Delay' */
  localDW->Delay_DSTATE_b = 0;

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  localDW->UnitDelay_DSTATE_mq = 0;

  /* InitializeConditions for Delay: '<S125>/Delay' */
  localDW->Delay_DSTATE_e = 0;

  /* SystemReset for Atomic SubSystem: '<S121>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S127>/Unit Delay' */
  localDW->UnitDelay_DSTATE_c = 0;

  /* InitializeConditions for Delay: '<S127>/Delay' */
  UnitDelayIntegratorPosObs = 0;

  /* End of SystemReset for SubSystem: '<S121>/DC Motor Model' */

  /* SystemReset for Atomic SubSystem: '<S122>/DC Motor Model' */
  /* InitializeConditions for UnitDelay: '<S130>/Unit Delay' */
  localDW->UnitDelay_DSTATE_m = 0;

  /* InitializeConditions for Delay: '<S130>/Delay' */
  localDW->Delay_DSTATE = 0;

  /* End of SystemReset for SubSystem: '<S122>/DC Motor Model' */
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
  int32_T tmp;

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
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
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
      /* UnitDelay: '<S121>/Unit Delay' */
      localB->UnitDelay = localDW->UnitDelay_DSTATE;

      /* UnitDelay: '<S8>/Unit Delay' */
      localB->UnitDelay_n = localDW->UnitDelay_DSTATE_cm;
    }

    /* Outputs for Atomic SubSystem: '<S121>/DC Motor Model' */
    /* Gain: '<S127>/Inductance' incorporates:
     *  UnitDelay: '<S127>/Unit Delay'
     */
    if (EMFobsLdGain > 16383) {
      rtb_Add6 = MAX_int16_T;
    } else {
      rtb_Add6 = (int16_T)(EMFobsLdGain << 1);
    }

    di_dt_E9 = (int16_T)((rtb_Add6 * localDW->UnitDelay_DSTATE_c) >> 12);

    /* End of Gain: '<S127>/Inductance' */

    /* Gain: '<S127>/Gain' */
    tmp = mul_ssu32_loSR_sat(di_dt_E9, TsIntern, 11U);
    if (tmp > 32767) {
      tmp = 32767;
    } else {
      if (tmp < -32768) {
        tmp = -32768;
      }
    }

    di_dt_times_Ts_En8 = (int16_T)tmp;

    /* End of Gain: '<S127>/Gain' */

    /* Sum: '<S127>/Sum' incorporates:
     *  Delay: '<S127>/Delay'
     */
    i_integrated_en4 = (int16_T)(di_dt_times_Ts_En8 + UnitDelayIntegratorPosObs);

    /* Gain: '<S127>/Resistance' */
    if (EMFobsRS > 127) {
      rtb_Add6 = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_Add6 = MIN_int16_T;
    } else {
      rtb_Add6 = (int16_T)(EMFobsRS << 8);
    }

    i_integrated_times_Rs_en8 = (int16_T)((rtb_Add6 * i_integrated_en4) >> 16);

    /* End of Gain: '<S127>/Resistance' */

    /* Sum: '<S127>/Add5' */
    Va_all_16En4 = (int16_T)((int16_T)((int16_T)((rtu_Va >> 4) -
      i_integrated_times_Rs_en8) - (localB->UnitDelay >> 4)) -
      (localB->UnitDelay_n >> 2));

    /* Update for UnitDelay: '<S127>/Unit Delay' */
    localDW->UnitDelay_DSTATE_c = Va_all_16En4;

    /* Update for Delay: '<S127>/Delay' */
    UnitDelayIntegratorPosObs = i_integrated_en4;

    /* End of Outputs for SubSystem: '<S121>/DC Motor Model' */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Outputs for Atomic SubSystem: '<S121>/DC Motor Model' */
      /* Sum: '<S121>/Add6' incorporates:
       *  DataTypeConversion: '<S127>/Data Type Conversion'
       */
      Sig_Emfobs_errorSum_m = (int16_T)((int16_T)(i_integrated_en4 << 4) -
        rtu_Ia);

      /* End of Outputs for SubSystem: '<S121>/DC Motor Model' */

      /* Abs: '<S128>/Abs' */
      if (Sig_Emfobs_errorSum_m < 0) {
        rtb_Add6 = (int16_T)-Sig_Emfobs_errorSum_m;
      } else {
        rtb_Add6 = Sig_Emfobs_errorSum_m;
      }

      /* End of Abs: '<S128>/Abs' */

      /* Outputs for Enabled SubSystem: '<S128>/Anti-windup' incorporates:
       *  EnablePort: '<S129>/Enable'
       */
      /* RelationalOperator: '<S128>/Relational Operator' */
      if (rtb_Add6 <= 59) {
        /* Delay: '<S129>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE_j == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE_j != UNINITIALIZED_ZCSIG)) || rtu_In5)
        {
          localDW->Delay1_DSTATE_m = 0;
        }

        localZCE->Delay1_Reset_ZCE_j = rtu_In5;

        /* Sum: '<S129>/Sum1' incorporates:
         *  Delay: '<S129>/Delay1'
         *  Gain: '<S129>/Gain1'
         *  Gain: '<S129>/Ki'
         */
        localB->Sum1_p = (int16_T)((((int16_T)((Ki_Iab_EMFobs *
          Sig_Emfobs_errorSum_m) >> 3) >> 8) + (localDW->Delay1_DSTATE_m << 4)) >>
          4);

        /* Update for Delay: '<S129>/Delay1' */
        localDW->Delay1_DSTATE_m = localB->Sum1_p;
      }

      /* End of RelationalOperator: '<S128>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S128>/Anti-windup' */

      /* Gain: '<S128>/Kp' */
      if (Kp_Iab_EMFobs > 511) {
        rtb_Add6 = MAX_int16_T;
      } else if (Kp_Iab_EMFobs <= -512) {
        rtb_Add6 = MIN_int16_T;
      } else {
        rtb_Add6 = (int16_T)(Kp_Iab_EMFobs << 6);
      }

      /* Sum: '<S128>/Add1' incorporates:
       *  Gain: '<S128>/Kp'
       */
      Sig_Emfobs_PI_out = (int16_T)((int16_T)((rtb_Add6 * Sig_Emfobs_errorSum_m)
        >> 14) + localB->Sum1_p);

      /* Saturate: '<S128>/Saturation' */
      if (MaxBckEMFVol_sat_neg > 511) {
        rtb_Add6 = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_neg <= -512) {
        rtb_Add6 = MIN_int16_T;
      } else {
        rtb_Add6 = (int16_T)(MaxBckEMFVol_sat_neg << 6);
      }

      if (MaxBckEMFVol_sat_pos > 511) {
        rtb_Add2_k = MAX_int16_T;
      } else if (MaxBckEMFVol_sat_pos <= -512) {
        rtb_Add2_k = MIN_int16_T;
      } else {
        rtb_Add2_k = (int16_T)(MaxBckEMFVol_sat_pos << 6);
      }

      if (Sig_Emfobs_PI_out > rtb_Add2_k) {
        Sig_Emfobs_PI_out = rtb_Add2_k;
      } else {
        if (Sig_Emfobs_PI_out < rtb_Add6) {
          Sig_Emfobs_PI_out = rtb_Add6;
        }
      }

      /* End of Saturate: '<S128>/Saturation' */

      /* Sum: '<S123>/Sum' incorporates:
       *  Delay: '<S123>/Delay'
       *  Gain: '<S123>/Gain'
       *  Sum: '<S123>/Add2'
       *  UnitDelay: '<S123>/Unit Delay'
       */
      localDW->Delay_DSTATE_l = (int16_T)(((int16_T)((Sig_Emfobs_PI_out -
        (localDW->UnitDelay_DSTATE_k << 2)) >> 2) >> 4) +
        localDW->Delay_DSTATE_l);

      /* Product: '<S123>/Product1' incorporates:
       *  Constant: '<S123>/Constant'
       *  Delay: '<S123>/Delay'
       */
      Sig_First_LPF_out = (int16_T)((localDW->Delay_DSTATE_l * CuttOffFreq_c) >>
        8);

      /* Sum: '<S124>/Sum' incorporates:
       *  Delay: '<S124>/Delay'
       *  Gain: '<S124>/Gain'
       *  Sum: '<S124>/Add2'
       *  UnitDelay: '<S124>/Unit Delay'
       */
      localDW->Delay_DSTATE_k = (int16_T)(((int16_T)(Sig_First_LPF_out -
        localDW->UnitDelay_DSTATE_o) >> 4) + localDW->Delay_DSTATE_k);

      /* Product: '<S124>/Product1' incorporates:
       *  Constant: '<S124>/Constant'
       *  Delay: '<S124>/Delay'
       */
      Sig_Second_LPF_out = (int16_T)((localDW->Delay_DSTATE_k * CuttOffFreq_c) >>
        8);

      /* DataTypeConversion: '<S120>/Data Type Conversion6' */
      rtb_Atan2_p = (real32_T)Sig_Second_LPF_out * 0.015625F;

      /* DataTypeConversion: '<S122>/Data Type Conversion' */
      rtb_Add2_k = (int16_T)(rtu_Ib >> 4);

      /* UnitDelay: '<S122>/Unit Delay' */
      localB->UnitDelay_j = localDW->UnitDelay_DSTATE_g;

      /* UnitDelay: '<S8>/Unit Delay1' */
      localB->UnitDelay1 = localDW->UnitDelay1_DSTATE;
    }

    /* Outputs for Atomic SubSystem: '<S122>/DC Motor Model' */
    /* Gain: '<S130>/Inductance' */
    if (EMFobsLdGain > 16383) {
      rtb_Add6 = MAX_int16_T;
    } else {
      rtb_Add6 = (int16_T)(EMFobsLdGain << 1);
    }

    /* Gain: '<S130>/Gain' incorporates:
     *  Gain: '<S130>/Inductance'
     *  UnitDelay: '<S130>/Unit Delay'
     */
    tmp = mul_ssu32_loSR_sat((int16_T)((rtb_Add6 * localDW->UnitDelay_DSTATE_m) >>
      12), TsIntern, 11U);
    if (tmp > 32767) {
      tmp = 32767;
    } else {
      if (tmp < -32768) {
        tmp = -32768;
      }
    }

    localDW->UnitDelay_DSTATE_m = (int16_T)tmp;

    /* End of Gain: '<S130>/Gain' */

    /* Sum: '<S130>/Sum' incorporates:
     *  Delay: '<S130>/Delay'
     *  UnitDelay: '<S130>/Unit Delay'
     */
    localDW->Delay_DSTATE += localDW->UnitDelay_DSTATE_m;

    /* Gain: '<S130>/Resistance' */
    if (EMFobsRS > 127) {
      rtb_Add6 = MAX_int16_T;
    } else if (EMFobsRS <= -128) {
      rtb_Add6 = MIN_int16_T;
    } else {
      rtb_Add6 = (int16_T)(EMFobsRS << 8);
    }

    /* Sum: '<S130>/Add5' incorporates:
     *  Delay: '<S130>/Delay'
     *  Gain: '<S130>/Resistance'
     *  UnitDelay: '<S130>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE_m = (int16_T)((int16_T)(((rtu_Vb >> 4) -
      ((rtb_Add6 * localDW->Delay_DSTATE) >> 16)) - localB->UnitDelay_j) -
      (localB->UnitDelay1 >> 2));

    /* End of Outputs for SubSystem: '<S122>/DC Motor Model' */
    if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S122>/Add6' incorporates:
       *  Delay: '<S130>/Delay'
       */
      rtb_Add6 = (int16_T)(localDW->Delay_DSTATE - rtb_Add2_k);

      /* Outputs for Atomic SubSystem: '<S122>/PI Controller' */
      /* Abs: '<S131>/Abs' */
      if (rtb_Add6 < 0) {
        rtb_Add2_k = (int16_T)-rtb_Add6;
      } else {
        rtb_Add2_k = rtb_Add6;
      }

      /* End of Abs: '<S131>/Abs' */

      /* Outputs for Enabled SubSystem: '<S131>/Anti-windup' incorporates:
       *  EnablePort: '<S132>/Enable'
       */
      /* RelationalOperator: '<S131>/Relational Operator' incorporates:
       *  Constant: '<S131>/Constant1'
       */
      if ((rtb_Add2_k << 4) <= 59) {
        /* Delay: '<S132>/Delay1' */
        if ((((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int32_T)rtu_In5) &&
             (localZCE->Delay1_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtu_In5) {
          localDW->Delay1_DSTATE = 0;
        }

        localZCE->Delay1_Reset_ZCE = rtu_In5;

        /* Sum: '<S132>/Sum1' incorporates:
         *  Delay: '<S132>/Delay1'
         *  Gain: '<S132>/Gain1'
         *  Gain: '<S132>/Ki'
         */
        localB->Sum1 = (int16_T)((((int16_T)((Ki_Iab_EMFobs * rtb_Add6) >> 3) >>
          4) + (localDW->Delay1_DSTATE << 4)) >> 4);

        /* Update for Delay: '<S132>/Delay1' */
        localDW->Delay1_DSTATE = localB->Sum1;
      }

      /* End of RelationalOperator: '<S131>/Relational Operator' */
      /* End of Outputs for SubSystem: '<S131>/Anti-windup' */

      /* Sum: '<S131>/Add1' incorporates:
       *  Gain: '<S131>/Kp'
       */
      rtb_Add2_k = (int16_T)((((int16_T)((Kp_Iab_EMFobs * rtb_Add6) >> 8) << 4)
        + localB->Sum1) >> 4);

      /* Saturate: '<S131>/Saturation' incorporates:
       *  UnitDelay: '<S122>/Unit Delay'
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

      /* End of Saturate: '<S131>/Saturation' */
      /* End of Outputs for SubSystem: '<S122>/PI Controller' */

      /* Sum: '<S126>/Sum' incorporates:
       *  Delay: '<S126>/Delay'
       *  Gain: '<S126>/Gain'
       *  Sum: '<S126>/Add2'
       *  UnitDelay: '<S122>/Unit Delay'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      localDW->Delay_DSTATE_b = (int16_T)(((int16_T)
        (((localDW->UnitDelay_DSTATE_g << 2) - localDW->UnitDelay_DSTATE_p) >> 2)
        >> 2) + localDW->Delay_DSTATE_b);

      /* Product: '<S126>/Product1' incorporates:
       *  Constant: '<S126>/Constant'
       *  Delay: '<S126>/Delay'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_p = (int16_T)((localDW->Delay_DSTATE_b *
        CuttOffFreq_c) >> 8);

      /* Sum: '<S125>/Sum' incorporates:
       *  Delay: '<S125>/Delay'
       *  Gain: '<S125>/Gain'
       *  Sum: '<S125>/Add2'
       *  UnitDelay: '<S125>/Unit Delay'
       *  UnitDelay: '<S126>/Unit Delay'
       */
      localDW->Delay_DSTATE_e = (int16_T)(((int16_T)(localDW->UnitDelay_DSTATE_p
        - localDW->UnitDelay_DSTATE_mq) >> 4) + localDW->Delay_DSTATE_e);

      /* Product: '<S125>/Product1' incorporates:
       *  Constant: '<S125>/Constant'
       *  Delay: '<S125>/Delay'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_mq = (int16_T)((localDW->Delay_DSTATE_e *
        CuttOffFreq_c) >> 8);

      /* Trigonometry: '<S120>/Atan2' incorporates:
       *  DataTypeConversion: '<S120>/Data Type Conversion7'
       *  UnitDelay: '<S125>/Unit Delay'
       */
      rtb_Atan2_p = rt_atan2f_snf_cordic6(rtb_Atan2_p, (real32_T)
        localDW->UnitDelay_DSTATE_mq * 0.015625F);

      /* DataTypeConversion: '<S120>/Data Type Conversion5' */
      rtb_Atan2_p = floorf(rtb_Atan2_p * 256.0F);
      if (rtIsNaNF(rtb_Atan2_p) || rtIsInfF(rtb_Atan2_p)) {
        rtb_Atan2_p = 0.0F;
      } else {
        rtb_Atan2_p = fmodf(rtb_Atan2_p, 65536.0F);
      }

      *rty_theta = (int16_T)(rtb_Atan2_p < 0.0F ? (int32_T)(int16_T)-(int16_T)
        (uint16_T)-rtb_Atan2_p : (int32_T)(int16_T)(uint16_T)rtb_Atan2_p);

      /* End of DataTypeConversion: '<S120>/Data Type Conversion5' */

      /* Update for UnitDelay: '<S121>/Unit Delay' */
      localDW->UnitDelay_DSTATE = Sig_Emfobs_PI_out;

      /* Update for UnitDelay: '<S8>/Unit Delay' */
      localDW->UnitDelay_DSTATE_cm = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S123>/Unit Delay' */
      localDW->UnitDelay_DSTATE_k = Sig_First_LPF_out;

      /* Update for UnitDelay: '<S124>/Unit Delay' */
      localDW->UnitDelay_DSTATE_o = Sig_Second_LPF_out;

      /* Update for UnitDelay: '<S8>/Unit Delay1' incorporates:
       *  UnitDelay: '<S126>/Unit Delay'
       */
      localDW->UnitDelay1_DSTATE = localDW->UnitDelay_DSTATE_p;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
}

/* Model step function */
void MotorControlLibNEWFixedP_FULL19b_step(void)
{
  int32_T rowIdx;
  int32_T rowIdx_0;
  uint16_T rtb_uDLookupTable2;
  boolean_T rtb_Compare;
  int16_T rtb_SignPreSat;
  boolean_T rtb_FixPtRelationalOperator;
  int16_T rtb_convert_pu;
  int16_T rtb_Sum6;
  int16_T rtb_IProdOut;
  int16_T rtb_sum_alpha;
  uint32_T rtb_Sum_idx_3;
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Delay: '<Root>/Delay' */
    Sig_theta_el_m = MotorControlLibNEWFixedP_FUL_DW.Delay_DSTATE;

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
    rtb_Sum6 = (int16_T)(100 * rtb_convert_pu);

    /* DataTypeConversion: '<S10>/Get_Integer' */
    rtb_uDLookupTable2 = (uint16_T)(rtb_Sum6 >> 6);

    /* Sum: '<S10>/Sum' */
    rtb_Sum_idx_3 = rtb_uDLookupTable2 + 100U;

    /* ModelReference: '<Root>/ADCRAwToCurrent(Iabc)' incorporates:
     *  Inport: '<Root>/Inport'
     */
    ADCRawToIab(&Sig_Ia_m, &Sig_Ib_m);

    /* DataTypeConversion: '<S10>/Get_FractionVal' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion1'
     *  Sum: '<S10>/Sum2'
     */
    rtb_sum_alpha = (int16_T)((int16_T)(rtb_Sum6 - (int16_T)((int16_T)
      rtb_uDLookupTable2 << 6)) << 2);

    /* Sum: '<S11>/Sum6' incorporates:
     *  Constant: '<S10>/sine_table_values'
     *  Product: '<S11>/Product1'
     *  Selector: '<S10>/Lookup'
     *  Sum: '<S10>/Sum'
     *  Sum: '<S11>/Sum5'
     */
    rtb_Sum6 = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
      [(int32_T)(rtb_uDLookupTable2 + 101U)] - rtCP_sine_table_values_Value
      [(int32_T)rtb_Sum_idx_3]) * rtb_sum_alpha) >> 8) +
                         rtCP_sine_table_values_Value[(int32_T)rtb_Sum_idx_3]);

    /* Gain: '<S1>/one_by_sqrt3' incorporates:
     *  Sum: '<S1>/a_plus_2b'
     */
    Sig_Ibeta_m = (int16_T)(((int16_T)((int16_T)(Sig_Ia_m + Sig_Ib_m) + Sig_Ib_m)
      * 18919) >> 15);

    /* Sum: '<S11>/Sum4' incorporates:
     *  Constant: '<S10>/sine_table_values'
     *  Product: '<S11>/Product'
     *  Selector: '<S10>/Lookup'
     *  Sum: '<S10>/Sum'
     *  Sum: '<S11>/Sum3'
     */
    rtb_sum_alpha = (int16_T)((int16_T)(((int16_T)(rtCP_sine_table_values_Value
      [(int32_T)(rtb_uDLookupTable2 + 1U)] -
      rtCP_sine_table_values_Value[rtb_uDLookupTable2]) * rtb_sum_alpha) >> 8) +
      rtCP_sine_table_values_Value[rtb_uDLookupTable2]);

    /* Gain: '<Root>/Gain3' incorporates:
     *  Product: '<S7>/asin'
     *  Product: '<S7>/bcos'
     *  Sum: '<S7>/sum_Qs'
     */
    Sig_qAxis_m = (int16_T)((int16_T)((Sig_Ibeta_m * rtb_Sum6) >> 8) - (int16_T)
      ((Sig_Ia_m * rtb_sum_alpha) >> 8));

    /* Sum: '<S5>/Add1' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Gain: '<Root>/Tq--> iqRef'
     */
    Sig_qAxis_errorSum_m = (int16_T)((int16_T)((TqToIqConst * qSoll) >> 7) -
      Sig_qAxis_m);

    /* Sum: '<S5>/Add2' incorporates:
     *  Constant: '<S5>/Constant8'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE++;

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    rtb_Compare = (MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE < 1500.0);

    /* DiscreteIntegrator: '<S59>/Integrator' */
    if (rtb_Compare ||
        (MotorControlLibNEWFixedP_FUL_DW.Integrator_PrevResetState != 0)) {
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE = 0;
    }

    /* Sum: '<S68>/Sum' incorporates:
     *  Constant: '<S5>/Constant4'
     *  DiscreteIntegrator: '<S59>/Integrator'
     *  Product: '<S64>/PProd Out'
     */
    rtb_convert_pu = (int16_T)((int16_T)((Sig_qAxis_errorSum_m * Kp_qAxis) >> 5)
      + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);

    /* Saturate: '<S66>/Saturation' */
    if (d_q_Voltage_Limiter_sat_neg > 2047) {
      Sig_qAxis_PI_out = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
      Sig_qAxis_PI_out = MIN_int16_T;
    } else {
      Sig_qAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
    }

    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      rtb_IProdOut = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      rtb_IProdOut = MIN_int16_T;
    } else {
      rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    if (rtb_convert_pu > rtb_IProdOut) {
      Sig_qAxis_PI_out = rtb_IProdOut;
    } else {
      if (rtb_convert_pu >= Sig_qAxis_PI_out) {
        Sig_qAxis_PI_out = rtb_convert_pu;
      }
    }

    /* End of Saturate: '<S66>/Saturation' */

    /* Gain: '<Root>/Gain5' */
    Sig_Vqsatu_m = Sig_qAxis_PI_out;

    /* Gain: '<Root>/Gain2' incorporates:
     *  Product: '<S7>/acos'
     *  Product: '<S7>/bsin'
     *  Sum: '<S7>/sum_Ds'
     */
    Sig_dAxis_m = (int16_T)((int16_T)((Sig_Ia_m * rtb_Sum6) >> 8) + (int16_T)
      ((Sig_Ibeta_m * rtb_sum_alpha) >> 8));

    /* Sum: '<S5>/Add' incorporates:
     *  Constant: '<Root>/d Soll'
     */
    Sig_dAxis_errorSum_m = (int16_T)((dSoll << 8) - Sig_dAxis_m);

    /* DiscreteIntegrator: '<S103>/Integrator' */
    if (rtb_Compare ||
        (MotorControlLibNEWFixedP_FUL_DW.Integrator_PrevResetState_g != 0)) {
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o = 0;
    }

    /* Sum: '<S112>/Sum' incorporates:
     *  Constant: '<S5>/Constant6'
     *  DiscreteIntegrator: '<S103>/Integrator'
     *  Product: '<S108>/PProd Out'
     */
    rtb_SignPreSat = (int16_T)((int16_T)((Sig_dAxis_errorSum_m * Kp_dAxis) >> 5)
      + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o);

    /* Saturate: '<S110>/Saturation' */
    if (d_q_Voltage_Limiter_sat_neg > 2047) {
      Sig_dAxis_PI_out = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
      Sig_dAxis_PI_out = MIN_int16_T;
    } else {
      Sig_dAxis_PI_out = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
    }

    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      rtb_IProdOut = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      rtb_IProdOut = MIN_int16_T;
    } else {
      rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    if (rtb_SignPreSat > rtb_IProdOut) {
      Sig_dAxis_PI_out = rtb_IProdOut;
    } else {
      if (rtb_SignPreSat >= Sig_dAxis_PI_out) {
        Sig_dAxis_PI_out = rtb_SignPreSat;
      }
    }

    /* End of Saturate: '<S110>/Saturation' */

    /* Gain: '<Root>/Gain4' */
    Sig_Vdsatu_m = Sig_dAxis_PI_out;

    /* Switch: '<S26>/Switch' incorporates:
     *  Product: '<S4>/dcos'
     *  Product: '<S4>/dsin'
     *  Product: '<S4>/qcos'
     *  Product: '<S4>/qsin'
     *  Sum: '<S4>/sum_alpha'
     *  Sum: '<S4>/sum_beta'
     */
    MotorControlLibNEWFixedP_FULL_B.Switch[0] = (int16_T)((int16_T)
      ((Sig_Vdsatu_m * rtb_Sum6) >> 8) - (int16_T)((Sig_Vqsatu_m * rtb_sum_alpha)
      >> 8));
    MotorControlLibNEWFixedP_FULL_B.Switch[1] = (int16_T)((int16_T)
      ((Sig_Vqsatu_m * rtb_Sum6) >> 8) + (int16_T)((Sig_Vdsatu_m * rtb_sum_alpha)
      >> 8));
  }

  /* Outputs for Enabled SubSystem: '<Root>/Position observer' */
  /* Inport: '<Root>/Inport3' incorporates:
   *  Inport: '<Root>/Inport5'
   */
  MotorControlLi_Positionobserver(MotorControlLibNEWFixedP_FUL_M,
    enablePositionObs, MotorControlLibNEWFixedP_FULL_B.Switch[0],
    MotorControlLibNEWFixedP_FULL_B.Switch[1], Sig_Ia_m, Sig_Ibeta_m,
    resetPIIntegrator, &PositionObsAnlge,
    &MotorControlLibNEWFixedP_FULL_B.Positionobserver,
    &MotorControlLibNEWFixedP_FUL_DW.Positionobserver,
    &MotorControlLibNEWFixed_PrevZCX.Positionobserver);

  /* End of Outputs for SubSystem: '<Root>/Position observer' */
  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Start up' */
    /* CombinatorialLogic: '<S139>/Logic' incorporates:
     *  Constant: '<Root>/q Soll'
     *  Memory: '<S139>/Memory'
     *  RelationalOperator: '<S135>/Compare'
     *  UnitDelay: '<S133>/Unit Delay'
     */
    rowIdx = (int32_T)(((((uint32_T)(qSoll == 0) << 1) +
                         MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_e) <<
                        1) +
                       MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput);

    /* UnitDelay: '<S136>/Delay Input1'
     *
     * Block description for '<S136>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator =
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE;

    /* UnitDelay: '<S133>/Unit Delay1' incorporates:
     *  UnitDelay: '<S136>/Delay Input1'
     *
     * Block description for '<S136>/Delay Input1':
     *
     *  Store in Global RAM
     */
    MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE =
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m;

    /* RelationalOperator: '<S136>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S136>/Delay Input1'
     *
     * Block description for '<S136>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator = ((int32_T)
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE < (int32_T)
      rtb_FixPtRelationalOperator);

    /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S137>/Enable'
     */
    /* CombinatorialLogic: '<S139>/Logic' */
    if (rtCP_Logic_table[(uint32_T)rowIdx]) {
      /* RelationalOperator: '<S141>/FixPt Relational Operator' incorporates:
       *  Constant: '<Root>/q Soll'
       *  UnitDelay: '<S141>/Delay Input1'
       *
       * Block description for '<S141>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator = (qSoll !=
        MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h);

      /* Update for UnitDelay: '<S141>/Delay Input1' incorporates:
       *  Constant: '<Root>/q Soll'
       *
       * Block description for '<S141>/Delay Input1':
       *
       *  Store in Global RAM
       */
      MotorControlLibNEWFixedP_FUL_DW.DelayInput1_DSTATE_h = qSoll;
    }

    /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem' */

    /* Memory: '<S140>/Memory' incorporates:
     *  UnitDelay: '<S133>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_e =
      MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b;

    /* CombinatorialLogic: '<S140>/Logic' incorporates:
     *  UnitDelay: '<S133>/Unit Delay'
     */
    rowIdx_0 = (int32_T)(((((uint32_T)
      MotorControlLibNEWFixedP_FULL_B.FixPtRelationalOperator << 1) +
      rtb_FixPtRelationalOperator) << 1) +
                         MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_e);

    /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem1' incorporates:
     *  EnablePort: '<S138>/Enable'
     */
    if (rtCP_Logic_table_m[(uint32_T)rowIdx_0]) {
      /* UnitDelay: '<S138>/Unit Delay1' */
      rtb_uDLookupTable2 = MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE;

      /* Sum: '<S138>/Add' incorporates:
       *  Constant: '<S138>/Constant'
       *  UnitDelay: '<S138>/Unit Delay1'
       */
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE++;

      /* RelationalOperator: '<S138>/Relational Operator' incorporates:
       *  Constant: '<S138>/Constant1'
       *  UnitDelay: '<S133>/Unit Delay1'
       */
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay1_DSTATE_m = (rtb_uDLookupTable2 <=
        10000);
    }

    /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem1' */

    /* UnitDelay: '<S134>/Unit Delay' */
    rtb_FixPtRelationalOperator =
      MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p;

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  UnitDelay: '<S134>/Unit Delay'
     */
    if (MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p &&
        (MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese <= 0))
    {
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = 0;
    }

    constantAngle =
      MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

    /* Abs: '<S134>/Abs' */
    if (constantAngle < 0) {
      rtb_IProdOut = (int16_T)-constantAngle;
    } else {
      rtb_IProdOut = constantAngle;
    }

    /* End of Abs: '<S134>/Abs' */

    /* RelationalOperator: '<S134>/Relational Operator' incorporates:
     *  UnitDelay: '<S134>/Unit Delay'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_p = (rtb_IProdOut >= 1608);

    /* Update for UnitDelay: '<S133>/Unit Delay' incorporates:
     *  CombinatorialLogic: '<S140>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.UnitDelay_DSTATE_e = rtCP_Logic_table_m
      [(uint32_T)rowIdx_0];

    /* Update for Memory: '<S139>/Memory' incorporates:
     *  CombinatorialLogic: '<S139>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput = rtCP_Logic_table
      [(uint32_T)rowIdx];

    /* Update for Memory: '<S140>/Memory' incorporates:
     *  CombinatorialLogic: '<S140>/Logic'
     */
    MotorControlLibNEWFixedP_FUL_DW.Memory_PreviousInput_b = rtCP_Logic_table_m
      [(uint32_T)rowIdx_0];

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Inport4'
     */
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE = (int16_T)
      (((16777 * dth_dt) >> 18) +
       MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_DSTATE);
    MotorControlLibNEWFixedP_FUL_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      rtb_FixPtRelationalOperator;

    /* End of Outputs for SubSystem: '<Root>/Start up' */

    /* Outputs for Enabled SubSystem: '<Root>/FluxObsAngle' */
    /* Inport: '<Root>/Inport2' */
    MotorControlLibNEW_FluxObsAngle(enableFluxObs,
      MotorControlLibNEWFixedP_FULL_B.Switch[0],
      MotorControlLibNEWFixedP_FULL_B.Switch[1], Sig_Ia_m, Sig_Ibeta_m,
      &FluxObsAngle, &MotorControlLibNEWFixedP_FULL_B.FluxObsAngle_k,
      &MotorControlLibNEWFixedP_ConstB.FluxObsAngle_k,
      &MotorControlLibNEWFixedP_FUL_DW.FluxObsAngle_k,
      &MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k);

    /* End of Outputs for SubSystem: '<Root>/FluxObsAngle' */

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Delay: '<Root>/Delay'
     *  Inport: '<Root>/Inport1'
     */
    switch (set_AngleInput) {
     case 0:
      MotorControlLibNEWFixedP_FUL_DW.Delay_DSTATE = constantAngle;
      break;

     case 1:
      MotorControlLibNEWFixedP_FUL_DW.Delay_DSTATE = FluxObsAngle;
      break;

     default:
      MotorControlLibNEWFixedP_FUL_DW.Delay_DSTATE = PositionObsAnlge;
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* Gain: '<Root>/Gain' */
    Sig_Va_m = MotorControlLibNEWFixedP_FULL_B.Switch[0];

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S6>/1-D Lookup Table'
     */
    set_PWM_A_DT(look1_is16lu32n16tu16_binlcse(Sig_Va_m, (&(BrkPoints[0])),
      rtCP_uDLookupTable_tableData, 2U));

    /* Gain: '<S118>/one_by_two' */
    rtb_IProdOut = (int16_T)(Sig_Va_m >> 1);

    /* Gain: '<Root>/Gain1' */
    Sig_Vb_m = MotorControlLibNEWFixedP_FULL_B.Switch[1];

    /* Gain: '<S118>/sqrt3_by_two' */
    rtb_Sum6 = (int16_T)((14189 * Sig_Vb_m) >> 14);

    /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
     *  Lookup_n-D: '<S6>/1-D Lookup Table1'
     *  Sum: '<S118>/add_b'
     */
    set_PWM_B_DT(look1_is16lu32n16tu16_binlcse((int16_T)(rtb_Sum6 - rtb_IProdOut),
      (&(BrkPoints[0])), rtCP_uDLookupTable1_tableData, 2U));

    /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
     *  Lookup_n-D: '<S6>/1-D Lookup Table2'
     *  Sum: '<S118>/add_c'
     */
    set_PWM_C_DT(look1_is16lu32n16tu16_binlcse((int16_T)(-rtb_IProdOut -
      rtb_Sum6), (&(BrkPoints[0])), rtCP_uDLookupTable2_tableData, 2U));

    /* DeadZone: '<S96>/DeadZone' */
    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      rtb_IProdOut = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      rtb_IProdOut = MIN_int16_T;
    } else {
      rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    if (rtb_SignPreSat > rtb_IProdOut) {
      if (d_q_Voltage_Limiter_sat_pos > 2047) {
        rtb_IProdOut = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
        rtb_IProdOut = MIN_int16_T;
      } else {
        rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
      }

      rtb_SignPreSat -= rtb_IProdOut;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 2047) {
        rtb_IProdOut = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
        rtb_IProdOut = MIN_int16_T;
      } else {
        rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
      }

      if (rtb_SignPreSat >= rtb_IProdOut) {
        rtb_SignPreSat = 0;
      } else {
        if (d_q_Voltage_Limiter_sat_neg > 2047) {
          rtb_IProdOut = MAX_int16_T;
        } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
          rtb_IProdOut = MIN_int16_T;
        } else {
          rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
        }

        rtb_SignPreSat -= rtb_IProdOut;
      }
    }

    /* End of DeadZone: '<S96>/DeadZone' */

    /* RelationalOperator: '<S96>/NotEqual' */
    rtb_FixPtRelationalOperator = (0 != rtb_SignPreSat);

    /* Signum: '<S96>/SignPreSat' */
    if (rtb_SignPreSat < 0) {
      rtb_SignPreSat = -1;
    } else {
      rtb_SignPreSat = (int16_T)(rtb_SignPreSat > 0);
    }

    /* End of Signum: '<S96>/SignPreSat' */

    /* Product: '<S100>/IProd Out' incorporates:
     *  Constant: '<S5>/Constant7'
     */
    rtb_IProdOut = (int16_T)((Sig_dAxis_errorSum_m * Ki_dAxis) >> 5);

    /* Signum: '<S96>/SignPreIntegrator' */
    if (rtb_IProdOut < 0) {
      rtb_Sum6 = -1;
    } else {
      rtb_Sum6 = (int16_T)(rtb_IProdOut > 0);
    }

    /* End of Signum: '<S96>/SignPreIntegrator' */

    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S96>/Constant1'
     *  DataTypeConversion: '<S96>/DataTypeConv1'
     *  DataTypeConversion: '<S96>/DataTypeConv2'
     *  Logic: '<S96>/AND3'
     *  RelationalOperator: '<S96>/Equal1'
     */
    if (rtb_FixPtRelationalOperator && (rtb_SignPreSat == rtb_Sum6)) {
      rtb_SignPreSat = 0;
    } else {
      rtb_SignPreSat = rtb_IProdOut;
    }

    /* End of Switch: '<S96>/Switch' */

    /* DeadZone: '<S52>/DeadZone' */
    if (d_q_Voltage_Limiter_sat_pos > 2047) {
      rtb_IProdOut = MAX_int16_T;
    } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
      rtb_IProdOut = MIN_int16_T;
    } else {
      rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
    }

    if (rtb_convert_pu > rtb_IProdOut) {
      if (d_q_Voltage_Limiter_sat_pos > 2047) {
        rtb_IProdOut = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_pos <= -2048) {
        rtb_IProdOut = MIN_int16_T;
      } else {
        rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_pos << 4);
      }

      rtb_convert_pu -= rtb_IProdOut;
    } else {
      if (d_q_Voltage_Limiter_sat_neg > 2047) {
        rtb_IProdOut = MAX_int16_T;
      } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
        rtb_IProdOut = MIN_int16_T;
      } else {
        rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
      }

      if (rtb_convert_pu >= rtb_IProdOut) {
        rtb_convert_pu = 0;
      } else {
        if (d_q_Voltage_Limiter_sat_neg > 2047) {
          rtb_IProdOut = MAX_int16_T;
        } else if (d_q_Voltage_Limiter_sat_neg <= -2048) {
          rtb_IProdOut = MIN_int16_T;
        } else {
          rtb_IProdOut = (int16_T)(d_q_Voltage_Limiter_sat_neg << 4);
        }

        rtb_convert_pu -= rtb_IProdOut;
      }
    }

    /* End of DeadZone: '<S52>/DeadZone' */

    /* RelationalOperator: '<S52>/NotEqual' */
    rtb_FixPtRelationalOperator = (0 != rtb_convert_pu);

    /* Signum: '<S52>/SignPreSat' */
    if (rtb_convert_pu < 0) {
      rtb_convert_pu = -1;
    } else {
      rtb_convert_pu = (int16_T)(rtb_convert_pu > 0);
    }

    /* End of Signum: '<S52>/SignPreSat' */

    /* Product: '<S56>/IProd Out' incorporates:
     *  Constant: '<S5>/Constant5'
     */
    rtb_IProdOut = (int16_T)((Sig_qAxis_errorSum_m * Ki_qAxis) >> 5);

    /* Signum: '<S52>/SignPreIntegrator' */
    if (rtb_IProdOut < 0) {
      rtb_Sum6 = -1;
    } else {
      rtb_Sum6 = (int16_T)(rtb_IProdOut > 0);
    }

    /* End of Signum: '<S52>/SignPreIntegrator' */

    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/Constant1'
     *  DataTypeConversion: '<S52>/DataTypeConv1'
     *  DataTypeConversion: '<S52>/DataTypeConv2'
     *  Logic: '<S52>/AND3'
     *  RelationalOperator: '<S52>/Equal1'
     */
    if (rtb_FixPtRelationalOperator && (rtb_convert_pu == rtb_Sum6)) {
      rtb_IProdOut = 0;
    }

    /* End of Switch: '<S52>/Switch' */

    /* Update for DiscreteIntegrator: '<S59>/Integrator' */
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE = (int16_T)(((16777 *
      rtb_IProdOut) >> 26) + MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE);
    MotorControlLibNEWFixedP_FUL_DW.Integrator_PrevResetState = (int8_T)
      rtb_Compare;

    /* Update for DiscreteIntegrator: '<S103>/Integrator' */
    MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o = (int16_T)(((16777 *
      rtb_SignPreSat) >> 26) +
      MotorControlLibNEWFixedP_FUL_DW.Integrator_DSTATE_o);
    MotorControlLibNEWFixedP_FUL_DW.Integrator_PrevResetState_g = (int8_T)
      rtb_Compare;
  }

  if (MotorControlLibNEWFixedP_FUL_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/Position' incorporates:
     *  Delay: '<Root>/Delay'
     */
    MotorControlLibNEWFixedP_FULL_Y.Position =
      MotorControlLibNEWFixedP_FUL_DW.Delay_DSTATE;
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

  /* Model Initialize function for ModelReference Block: '<Root>/ADCRAwToCurrent(Iabc)' */
  ADCRawToIab_initialize(rtmGetErrorStatusPointer(MotorControlLibNEWFixedP_FUL_M),
    &(MotorControlLibNEWFixedP_FUL_DW.ADCRAwToCurrentIabc_InstanceDat.rtm));
  MotorControlLibNEWFixed_PrevZCX.Positionobserver.Delay1_Reset_ZCE_j =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.Positionobserver.Delay1_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE =
    UNINITIALIZED_ZCSIG;
  MotorControlLibNEWFixed_PrevZCX.FluxObsAngle_k.Delay_Reset_ZCE_o =
    UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Start up' */
  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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
