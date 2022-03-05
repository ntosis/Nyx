/*
 * File: MotorControlLibNEWFixedP_FULL19b.h
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

#ifndef RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_
#define RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_
#include <math.h>
#ifndef MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_
# define MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                   /* MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_ */

#include "MotorControlLibNEWFixedP_FULL19b_types.h"

/* Child system includes */
#include "ADCRawToIab.h"
#include "CalcSpinSpeednDir.h"
#include "SafetyChecks.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals for system '<Root>/FluxObsAngle' */
typedef struct {
  int16_T Merge;                       /* '<S18>/Merge' */
} B_FluxObsAngle_MotorControlLi_T;

/* Block states (default storage) for system '<Root>/FluxObsAngle' */
typedef struct {
  int16_T Delay_DSTATE;                /* '<S20>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S19>/Delay' */
} DW_FluxObsAngle_MotorControlL_T;

/* Zero-crossing (trigger) state for system '<Root>/FluxObsAngle' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S20>/Delay' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S19>/Delay' */
} ZCE_FluxObsAngle_MotorControl_T;

/* Block states (default storage) for system '<Root>/PI_Controller' */
typedef struct {
  int16_T Integrator_DSTATE;           /* '<S104>/Integrator' */
  int16_T Integrator_DSTATE_m;         /* '<S60>/Integrator' */
  uint16_T UnitDelay_DSTATE;            /* '<S30>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S104>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S60>/Integrator' */
} DW_PI_Controller_MotorControl_T;

/* Block signals for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay;                  /* '<S124>/Unit Delay' */
  real32_T DataTypeConversion1;        /* '<S9>/Data Type Conversion1' */
  real32_T DataTypeConversion3;        /* '<S9>/Data Type Conversion3' */
  int16_T Sum1;                        /* '<S135>/Sum1' */
  int16_T Sum1_p;                      /* '<S132>/Sum1' */
  int16_T UnitDelay_n;                 /* '<S9>/Unit Delay' */
  int16_T UnitDelay1;                  /* '<S9>/Unit Delay1' */
  int16_T UnitDelay_j;                 /* '<S125>/Unit Delay' */
} B_Positionobserver_MotorContr_T;

/* Block states (default storage) for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S124>/Unit Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S130>/Unit Delay' */
  int16_T Delay1_DSTATE;               /* '<S135>/Delay1' */
  int16_T Delay1_DSTATE_m;             /* '<S132>/Delay1' */
  int16_T UnitDelay_DSTATE_g;          /* '<S125>/Unit Delay' */
  int16_T UnitDelay_DSTATE_m;          /* '<S133>/Unit Delay' */
  int16_T Delay_DSTATE;                /* '<S133>/Delay' */
  int16_T Delay_DSTATE_l;              /* '<S126>/Delay' */
  int16_T Delay_DSTATE_k;              /* '<S127>/Delay' */
  int16_T Delay_DSTATE_b;              /* '<S129>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S128>/Delay' */
  int16_T UnitDelay_DSTATE_cm;         /* '<S9>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S126>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S127>/Unit Delay' */
  int16_T UnitDelay1_DSTATE;           /* '<S9>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_p;          /* '<S129>/Unit Delay' */
  int16_T UnitDelay_DSTATE_mq;         /* '<S128>/Unit Delay' */
  boolean_T Positionobserver_MODE;     /* '<Root>/Position observer' */
} DW_Positionobserver_MotorCont_T;

/* Zero-crossing (trigger) state for system '<Root>/Position observer' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S135>/Delay1' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S132>/Delay1' */
} ZCE_Positionobserver_MotorCon_T;

/* Block signals (default storage) */
typedef struct {
  real32_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  int16_T RateTransition3;             /* '<Root>/Rate Transition3' */
  int16_T RateTransition2;             /* '<Root>/Rate Transition2' */
  boolean_T RateTransition4;           /* '<Root>/Rate Transition4' */
  boolean_T FixPtRelationalOperator;   /* '<S144>/FixPt Relational Operator' */
  B_Positionobserver_MotorContr_T Positionobserver;/* '<Root>/Position observer' */
  B_FluxObsAngle_MotorControlLi_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} B_MotorControlLibNEWFixedP_FU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T UnitDelay1_DSTATE;          /* '<S141>/Unit Delay1' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S137>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S144>/Delay Input1' */
  int16_T RateTransition3_Buffer0;     /* '<Root>/Rate Transition3' */
  int16_T RateTransition2_Buffer0;     /* '<Root>/Rate Transition2' */
  int16_T RateTransition1_Buffer;      /* '<Root>/Rate Transition1' */
  boolean_T UnitDelay_DSTATE;          /* '<S136>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S139>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S136>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S137>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S137>/Discrete-Time Integrator' */
  boolean_T RateTransition4_Buffer0;   /* '<Root>/Rate Transition4' */
  boolean_T Memory_PreviousInput;      /* '<S142>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S143>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_CalcSpinSpeednDir_T Calculatespinspeed1_InstanceDat;/* '<Root>/Calculate spin speed1' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_Positionobserver_MotorCont_T Positionobserver;/* '<Root>/Position observer' */
  DW_PI_Controller_MotorControl_T PI_Controller;/* '<Root>/PI_Controller' */
  DW_FluxObsAngle_MotorControlL_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} DW_MotorControlLibNEWFixedP_F_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Positionobserver_MotorCon_T Positionobserver;/* '<Root>/Position observer' */
  ZCE_FluxObsAngle_MotorControl_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} PrevZCX_MotorControlLibNEWFix_T;

/* Invariant block signals for system '<Root>/FluxObsAngle' */
typedef struct {
  const boolean_T Compare;             /* '<S21>/Compare' */
  const boolean_T Compare_l;           /* '<S22>/Compare' */
} ConstB_FluxObsAngle_MotorCont_T;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_FluxObsAngle_MotorCont_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} ConstB_MotorControlLibNEWFixe_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Position;                    /* '<Root>/Position' */
} ExtY_MotorControlLibNEWFixedP_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLibNEWFix_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorControlLibNEWFixedP_FU_T MotorControlLibNEWFixedP_FULL_B;

/* Block states (default storage) */
extern DW_MotorControlLibNEWFixedP_F_T MotorControlLibNEWFixedP_FUL_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorControlLibNEWFixedP_T MotorControlLibNEWFixedP_FULL_Y;
extern const ConstB_MotorControlLibNEWFixe_T MotorControlLibNEWFixedP_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T enableFluxObs;        /* '<Root>/Inport2' */
extern uint8_T set_AngleInput;         /* '<Root>/Inport1' */
extern boolean_T enablePositionObs;    /* '<Root>/Inport3' */
extern int16_T dth_dt;                 /* '<Root>/Inport4' */
extern boolean_T resetPIIntegrator;    /* '<Root>/Inport5' */
extern boolean_T Sig_change_SVMalgorithm;/* '<Root>/In1' */
extern boolean_T resetPIIntegratorDQ;  /* '<Root>/Inport6' */
extern real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Calculate spin speed1' */
extern real32_T Sig_rpm;               /* '<Root>/Calculate spin speed1' */
extern int16_T Sig_theta_el_m;         /* '<Root>/Delay' */
extern int16_T Sig_Ia_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ib_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_cos_m;              /* '<S12>/Sum6' */
extern int16_T Sig_Ibeta_m;            /* '<S1>/one_by_sqrt3' */
extern int16_T Sig_sin_m;              /* '<S12>/Sum4' */
extern int16_T Sig_Iq_Soll;            /* '<Root>/Tq--> iqRef' */
extern int16_T Sig_dAxis_m;            /* '<Root>/Gain2' */
extern int16_T Sig_qAxis_m;            /* '<Root>/Gain3' */
extern int16_T Sig_Vqsatu_m;           /* '<Root>/Gain5' */
extern int16_T Sig_Vdsatu_m;           /* '<Root>/Gain4' */
extern int16_T Sig_Va_m;               /* '<Root>/Gain' */
extern int16_T Sig_Vb_m;               /* '<Root>/Gain1' */
extern int16_T Sig_Valpha_m;           /* '<S7>/Switch' */
extern int16_T Sig_Vbeta_m;            /* '<S7>/Switch1' */
extern int16_T Sig_Vgamma_m;           /* '<S7>/Switch2' */
extern int16_T constantAngle;          /* '<S137>/Discrete-Time Integrator' */
extern int16_T PositionObsAnlge;       /* '<S123>/Data Type Conversion5' */
extern int16_T Sig_dAxis_PI_out;       /* '<S111>/Saturation' */
extern int16_T Sig_qAxis_PI_out;       /* '<S67>/Saturation' */
extern int16_T FluxObsAngle;           /* '<S17>/PositionGain' */
extern real32_T Sig_Emfobs_errorSum_m; /* '<S124>/Add6' */
extern real32_T Sig_Emfobs_PI_out;     /* '<S131>/Saturation' */
extern real32_T di_dt_E9;              /* '<S130>/Inductance' */
extern real32_T di_dt_times_Ts_En8;    /* '<S130>/Gain' */
extern real32_T i_integrated_en4;      /* '<S130>/Sum' */
extern real32_T i_integrated_times_Rs_en8;/* '<S130>/Resistance' */
extern real32_T Va_all_16En4;          /* '<S130>/Add5' */
extern int16_T Sig_First_LPF_out;      /* '<S126>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_Second_LPF_out;     /* '<S127>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_dAxis_errorSum_m;   /* '<S6>/Add' */
extern int16_T Sig_qAxis_errorSum_m;   /* '<S6>/Add1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T TsIntern;              /* Variable: TsIntern
                                        * Referenced by:
                                        *   '<S130>/Gain'
                                        *   '<S133>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
extern int16_T MaxBckEMFVol_sat_neg;   /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S131>/Saturation'
                                        *   '<S134>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
extern int16_T MaxBckEMFVol_sat_pos;   /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S131>/Saturation'
                                        *   '<S134>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
extern int16_T Ki_Iab_EMFobs;          /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S132>/Ki'
                                        *   '<S135>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S53>/DeadZone'
                                            *   '<S67>/Saturation'
                                            *   '<S97>/DeadZone'
                                            *   '<S111>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S53>/DeadZone'
                                            *   '<S67>/Saturation'
                                            *   '<S97>/DeadZone'
                                            *   '<S111>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S6>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S6>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_Iab_EMFobs;          /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S131>/Kp'
                                        *   '<S134>/Kp'
                                        * fixdt(1,16,2^-8,0)
                                        */
extern int16_T qSoll;                  /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,16,2^-8,0)
                                        */
extern uint16_T MaximumCurrentBeforeReaction;/* Variable: MaximumCurrentBeforeReaction
                                              * Referenced by: '<Root>/SafetyChecks'
                                              * Maximum current limit before softare shutdowns the mosfets.
                                              */
extern uint16_T CuttOffFreq_c;         /* Variable: CuttOffFreq_c
                                        * Referenced by:
                                        *   '<S126>/Constant'
                                        *   '<S127>/Constant'
                                        *   '<S128>/Constant'
                                        *   '<S129>/Constant'
                                        */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T UnitDelayIntegratorPosObs;/* '<S130>/Delay' */

/* Model entry point functions */
extern void MotorControlLibNEWFixedP_FULL19b_initialize(void);
extern void MotorControlLibNEWFixedP_FULL19b_step(void);
extern void MotorControlLibNEWFixedP_FULL19b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLibNEWFi_T *const MotorControlLibNEWFixedP_FUL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/Data Type Conversion1' : Unused code path elimination
 * Block '<S17>/FluxGain' : Unused code path elimination
 * Block '<S17>/Product' : Unused code path elimination
 * Block '<S17>/Product1' : Unused code path elimination
 * Block '<S17>/Sqrt' : Unused code path elimination
 * Block '<S17>/Square' : Unused code path elimination
 * Block '<S17>/Square1' : Unused code path elimination
 * Block '<S17>/Sum' : Unused code path elimination
 * Block '<S17>/Sum1' : Unused code path elimination
 * Block '<S17>/TorqueGain' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S130>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S124>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S124>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S124>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S124>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S125>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S125>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S125>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S125>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S27>/Offset' : Unused code path elimination
 * Block '<S27>/Unary_Minus' : Unused code path elimination
 * Block '<S122>/Offset' : Unused code path elimination
 * Block '<S122>/Unary_Minus' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MotorControlLibNEWFixedP_FULL19b'
 * '<S1>'   : 'MotorControlLibNEWFixedP_FULL19b/Clarke Transform'
 * '<S2>'   : 'MotorControlLibNEWFixedP_FULL19b/CosSin'
 * '<S3>'   : 'MotorControlLibNEWFixedP_FULL19b/DQ_Limiter'
 * '<S4>'   : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle'
 * '<S5>'   : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform'
 * '<S6>'   : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller'
 * '<S7>'   : 'MotorControlLibNEWFixedP_FULL19b/PWM Output'
 * '<S8>'   : 'MotorControlLibNEWFixedP_FULL19b/Park Transform'
 * '<S9>'   : 'MotorControlLibNEWFixedP_FULL19b/Position observer'
 * '<S10>'  : 'MotorControlLibNEWFixedP_FULL19b/Start up'
 * '<S11>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup'
 * '<S12>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S13>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S14>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S15>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S16>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S17>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer'
 * '<S18>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2'
 * '<S19>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha'
 * '<S20>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta'
 * '<S21>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant'
 * '<S22>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant1'
 * '<S23>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/If Action Subsystem'
 * '<S24>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/per Uint'
 * '<S25>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha/Scaling'
 * '<S26>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta/Scaling'
 * '<S27>'  : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform/Switch_Axis'
 * '<S28>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis'
 * '<S29>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1'
 * '<S30>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/disable integrator on start up'
 * '<S31>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Anti-windup'
 * '<S32>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/D Gain'
 * '<S33>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter'
 * '<S34>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter ICs'
 * '<S35>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/I Gain'
 * '<S36>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain'
 * '<S37>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S38>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator'
 * '<S39>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator ICs'
 * '<S40>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Copy'
 * '<S41>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Gain'
 * '<S42>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/P Copy'
 * '<S43>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Parallel P Gain'
 * '<S44>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Reset Signal'
 * '<S45>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation'
 * '<S46>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation Fdbk'
 * '<S47>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum'
 * '<S48>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum Fdbk'
 * '<S49>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode'
 * '<S50>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode Sum'
 * '<S51>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/postSat Signal'
 * '<S52>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/preSat Signal'
 * '<S53>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Anti-windup/Disc. Clamping Parallel'
 * '<S54>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/D Gain/Disabled'
 * '<S55>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter/Disabled'
 * '<S56>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S57>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/I Gain/External Parameters'
 * '<S58>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S59>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S60>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator/Discrete'
 * '<S61>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S62>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S63>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Gain/Disabled'
 * '<S64>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/P Copy/Disabled'
 * '<S65>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S66>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Reset Signal/External Reset'
 * '<S67>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation/Enabled'
 * '<S68>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S69>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum/Sum_PI'
 * '<S70>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S71>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S72>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S73>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S74>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S75>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Anti-windup'
 * '<S76>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/D Gain'
 * '<S77>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter'
 * '<S78>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter ICs'
 * '<S79>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/I Gain'
 * '<S80>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain'
 * '<S81>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S82>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator'
 * '<S83>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator ICs'
 * '<S84>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Copy'
 * '<S85>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Gain'
 * '<S86>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/P Copy'
 * '<S87>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Parallel P Gain'
 * '<S88>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Reset Signal'
 * '<S89>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation'
 * '<S90>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation Fdbk'
 * '<S91>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum'
 * '<S92>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum Fdbk'
 * '<S93>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode'
 * '<S94>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S95>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/postSat Signal'
 * '<S96>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/preSat Signal'
 * '<S97>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Anti-windup/Disc. Clamping Parallel'
 * '<S98>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/D Gain/Disabled'
 * '<S99>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter/Disabled'
 * '<S100>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S101>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S102>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S103>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S104>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator/Discrete'
 * '<S105>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S106>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S107>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Gain/Disabled'
 * '<S108>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/P Copy/Disabled'
 * '<S109>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S110>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Reset Signal/External Reset'
 * '<S111>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation/Enabled'
 * '<S112>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S113>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S114>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S115>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S116>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S117>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S118>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S119>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S120>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Inverse Clarke Transform'
 * '<S121>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Space Vector Generator'
 * '<S122>' : 'MotorControlLibNEWFixedP_FULL19b/Park Transform/Switch_Axis'
 * '<S123>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Atan2'
 * '<S124>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia'
 * '<S125>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2'
 * '<S126>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter'
 * '<S127>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter1'
 * '<S128>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter2'
 * '<S129>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter3'
 * '<S130>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/DC Motor Model'
 * '<S131>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PI Controller'
 * '<S132>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PI Controller/Anti-windup'
 * '<S133>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/DC Motor Model'
 * '<S134>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/PI Controller'
 * '<S135>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/PI Controller/Anti-windup'
 * '<S136>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped'
 * '<S137>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Simulate start up Theta'
 * '<S138>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S139>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S140>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S141>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S142>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S143>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S144>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 */
#endif                      /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
