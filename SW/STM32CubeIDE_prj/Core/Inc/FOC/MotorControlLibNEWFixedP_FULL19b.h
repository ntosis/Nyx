/*
 * File: MotorControlLibNEWFixedP_FULL19b.h
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:39:22 2022
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
  int16_T Merge;                       /* '<S23>/Merge' */
} B_FluxObsAngle_MotorControlLi_T;

/* Block states (default storage) for system '<Root>/FluxObsAngle' */
typedef struct {
  int16_T Delay_DSTATE;                /* '<S25>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S24>/Delay' */
} DW_FluxObsAngle_MotorControlL_T;

/* Zero-crossing (trigger) state for system '<Root>/FluxObsAngle' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S25>/Delay' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S24>/Delay' */
} ZCE_FluxObsAngle_MotorControl_T;

/* Block states (default storage) for system '<Root>/PI_Controller' */
typedef struct {
  int16_T Integrator_DSTATE;           /* '<S109>/Integrator' */
  int16_T Integrator_DSTATE_m;         /* '<S65>/Integrator' */
  uint8_T UnitDelay_DSTATE;            /* '<S35>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S109>/Integrator' */
  int8_T Integrator_PrevResetState_l;  /* '<S65>/Integrator' */
} DW_PI_Controller_MotorControl_T;

/* Block signals for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay;                  /* '<S129>/Unit Delay' */
  real32_T DataTypeConversion1;        /* '<S10>/Data Type Conversion1' */
  real32_T DataTypeConversion3;        /* '<S10>/Data Type Conversion3' */
  int16_T Sum1;                        /* '<S140>/Sum1' */
  int16_T Sum1_p;                      /* '<S137>/Sum1' */
  int16_T UnitDelay_n;                 /* '<S10>/Unit Delay' */
  int16_T UnitDelay1;                  /* '<S10>/Unit Delay1' */
  int16_T UnitDelay_j;                 /* '<S130>/Unit Delay' */
} B_Positionobserver_MotorContr_T;

/* Block states (default storage) for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S129>/Unit Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S135>/Unit Delay' */
  int16_T Delay1_DSTATE;               /* '<S140>/Delay1' */
  int16_T Delay1_DSTATE_m;             /* '<S137>/Delay1' */
  int16_T UnitDelay_DSTATE_g;          /* '<S130>/Unit Delay' */
  int16_T UnitDelay_DSTATE_m;          /* '<S138>/Unit Delay' */
  int16_T Delay_DSTATE;                /* '<S138>/Delay' */
  int16_T Delay_DSTATE_l;              /* '<S131>/Delay' */
  int16_T Delay_DSTATE_k;              /* '<S132>/Delay' */
  int16_T Delay_DSTATE_b;              /* '<S134>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S133>/Delay' */
  int16_T UnitDelay_DSTATE_cm;         /* '<S10>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S131>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S132>/Unit Delay' */
  int16_T UnitDelay1_DSTATE;           /* '<S10>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_p;          /* '<S134>/Unit Delay' */
  int16_T UnitDelay_DSTATE_mq;         /* '<S133>/Unit Delay' */
  boolean_T Positionobserver_MODE;     /* '<Root>/Position observer' */
} DW_Positionobserver_MotorCont_T;

/* Zero-crossing (trigger) state for system '<Root>/Position observer' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S140>/Delay1' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S137>/Delay1' */
} ZCE_Positionobserver_MotorCon_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Merge;                      /* '<S1>/Merge' */
  int16_T RateTransition3;             /* '<Root>/Rate Transition3' */
  int16_T RateTransition2;             /* '<Root>/Rate Transition2' */
  boolean_T RateTransition4;           /* '<Root>/Rate Transition4' */
  boolean_T FixPtRelationalOperator;   /* '<S149>/FixPt Relational Operator' */
  B_Positionobserver_MotorContr_T Positionobserver;/* '<Root>/Position observer' */
  B_FluxObsAngle_MotorControlLi_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} B_MotorControlLibNEWFixedP_FU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
  real32_T UD_DSTATE;                  /* '<S13>/UD' */
  uint16_T UnitDelay1_DSTATE;          /* '<S146>/Unit Delay1' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S142>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S149>/Delay Input1' */
  int16_T RateTransition3_Buffer0;     /* '<Root>/Rate Transition3' */
  int16_T RateTransition2_Buffer0;     /* '<Root>/Rate Transition2' */
  int16_T RateTransition1_Buffer;      /* '<Root>/Rate Transition1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S141>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S144>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S141>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S142>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S142>/Discrete-Time Integrator' */
  boolean_T RateTransition4_Buffer0;   /* '<Root>/Rate Transition4' */
  boolean_T Memory_PreviousInput;      /* '<S147>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S148>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
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
  const boolean_T Compare;             /* '<S26>/Compare' */
  const boolean_T Compare_l;           /* '<S27>/Compare' */
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
extern real32_T Sig_Angular_Velocity_radpsec_m;/* '<S1>/Abs' */
extern real32_T Sig_rpm;               /* '<S1>/Unit Conversion' */
extern int16_T Sig_theta_el_m;         /* '<Root>/Delay' */
extern int16_T Sig_Ia_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ib_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_cos_m;              /* '<S17>/Sum6' */
extern int16_T Sig_Ibeta_m;            /* '<S2>/one_by_sqrt3' */
extern int16_T Sig_sin_m;              /* '<S17>/Sum4' */
extern int16_T Sig_Iq_Soll;            /* '<Root>/Tq--> iqRef' */
extern int16_T Sig_dAxis_m;            /* '<Root>/Gain2' */
extern int16_T Sig_qAxis_m;            /* '<Root>/Gain3' */
extern int16_T Sig_Vqsatu_m;           /* '<Root>/Gain5' */
extern int16_T Sig_Vdsatu_m;           /* '<Root>/Gain4' */
extern int16_T Sig_Va_m;               /* '<Root>/Gain' */
extern int16_T Sig_Vb_m;               /* '<Root>/Gain1' */
extern int16_T Sig_Valpha_m;           /* '<S8>/Switch' */
extern int16_T Sig_Vbeta_m;            /* '<S8>/Switch1' */
extern int16_T Sig_Vgamma_m;           /* '<S8>/Switch2' */
extern int16_T constantAngle;          /* '<S142>/Discrete-Time Integrator' */
extern int16_T PositionObsAnlge;       /* '<S128>/Data Type Conversion5' */
extern int16_T Sig_dAxis_PI_out;       /* '<S116>/Saturation' */
extern int16_T Sig_qAxis_PI_out;       /* '<S72>/Saturation' */
extern int16_T FluxObsAngle;           /* '<S22>/PositionGain' */
extern real32_T Sig_Emfobs_errorSum_m; /* '<S129>/Add6' */
extern real32_T Sig_Emfobs_PI_out;     /* '<S136>/Saturation' */
extern real32_T di_dt_E9;              /* '<S135>/Inductance' */
extern real32_T di_dt_times_Ts_En8;    /* '<S135>/Gain' */
extern real32_T i_integrated_en4;      /* '<S135>/Sum' */
extern real32_T i_integrated_times_Rs_en8;/* '<S135>/Resistance' */
extern real32_T Va_all_16En4;          /* '<S135>/Add5' */
extern int16_T Sig_First_LPF_out;      /* '<S131>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_Second_LPF_out;     /* '<S132>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_dAxis_errorSum_m;   /* '<S7>/Add' */
extern int16_T Sig_qAxis_errorSum_m;   /* '<S7>/Add1' */

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
                                        *   '<S135>/Gain'
                                        *   '<S138>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
extern int16_T MaxBckEMFVol_sat_neg;   /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
extern int16_T MaxBckEMFVol_sat_pos;   /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S136>/Saturation'
                                        *   '<S139>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
extern int16_T Ki_Iab_EMFobs;          /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S137>/Ki'
                                        *   '<S140>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S58>/DeadZone'
                                            *   '<S72>/Saturation'
                                            *   '<S102>/DeadZone'
                                            *   '<S116>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S58>/DeadZone'
                                            *   '<S72>/Saturation'
                                            *   '<S102>/DeadZone'
                                            *   '<S116>/Saturation'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S7>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S7>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S7>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S7>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_Iab_EMFobs;          /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S136>/Kp'
                                        *   '<S139>/Kp'
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
                                        *   '<S131>/Constant'
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S134>/Constant'
                                        */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T UnitDelayIntegratorPosObs;/* '<S135>/Delay' */

/* Model entry point functions */
extern void MotorControlLibNEWFixedP_FULL19b_initialize(void);
extern void MotorControlLibNEWFixedP_FULL19b_step(void);
extern void MotorControlLibNEWFixedP_FULL19b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLibNEWFi_T *const MotorControlLibNEWFixedP_FUL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Conversion' : Unused code path elimination
 * Block '<S22>/Data Type Conversion1' : Unused code path elimination
 * Block '<S22>/FluxGain' : Unused code path elimination
 * Block '<S22>/Product' : Unused code path elimination
 * Block '<S22>/Product1' : Unused code path elimination
 * Block '<S22>/Sqrt' : Unused code path elimination
 * Block '<S22>/Square' : Unused code path elimination
 * Block '<S22>/Square1' : Unused code path elimination
 * Block '<S22>/Sum' : Unused code path elimination
 * Block '<S22>/Sum1' : Unused code path elimination
 * Block '<S22>/TorqueGain' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S22>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S129>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S129>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S32>/Offset' : Unused code path elimination
 * Block '<S32>/Unary_Minus' : Unused code path elimination
 * Block '<S127>/Offset' : Unused code path elimination
 * Block '<S127>/Unary_Minus' : Unused code path elimination
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
 * '<S1>'   : 'MotorControlLibNEWFixedP_FULL19b/Calculate spin speed'
 * '<S2>'   : 'MotorControlLibNEWFixedP_FULL19b/Clarke Transform'
 * '<S3>'   : 'MotorControlLibNEWFixedP_FULL19b/CosSin'
 * '<S4>'   : 'MotorControlLibNEWFixedP_FULL19b/DQ_Limiter'
 * '<S5>'   : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle'
 * '<S6>'   : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform'
 * '<S7>'   : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller'
 * '<S8>'   : 'MotorControlLibNEWFixedP_FULL19b/PWM Output'
 * '<S9>'   : 'MotorControlLibNEWFixedP_FULL19b/Park Transform'
 * '<S10>'  : 'MotorControlLibNEWFixedP_FULL19b/Position observer'
 * '<S11>'  : 'MotorControlLibNEWFixedP_FULL19b/Start up'
 * '<S12>'  : 'MotorControlLibNEWFixedP_FULL19b/Calculate spin speed/2 * pi offset'
 * '<S13>'  : 'MotorControlLibNEWFixedP_FULL19b/Calculate spin speed/Calculate Angular Velocity'
 * '<S14>'  : 'MotorControlLibNEWFixedP_FULL19b/Calculate spin speed/Chart'
 * '<S15>'  : 'MotorControlLibNEWFixedP_FULL19b/Calculate spin speed/No offset'
 * '<S16>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup'
 * '<S17>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S18>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S19>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S20>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S21>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S22>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer'
 * '<S23>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2'
 * '<S24>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha'
 * '<S25>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta'
 * '<S26>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant'
 * '<S27>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant1'
 * '<S28>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/If Action Subsystem'
 * '<S29>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/per Uint'
 * '<S30>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha/Scaling'
 * '<S31>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta/Scaling'
 * '<S32>'  : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform/Switch_Axis'
 * '<S33>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis'
 * '<S34>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1'
 * '<S35>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/disable integrator on start up'
 * '<S36>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Anti-windup'
 * '<S37>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/D Gain'
 * '<S38>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter'
 * '<S39>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter ICs'
 * '<S40>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/I Gain'
 * '<S41>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain'
 * '<S42>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S43>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator'
 * '<S44>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator ICs'
 * '<S45>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Copy'
 * '<S46>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Gain'
 * '<S47>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/P Copy'
 * '<S48>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Parallel P Gain'
 * '<S49>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Reset Signal'
 * '<S50>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation'
 * '<S51>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation Fdbk'
 * '<S52>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum'
 * '<S53>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum Fdbk'
 * '<S54>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode'
 * '<S55>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode Sum'
 * '<S56>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/postSat Signal'
 * '<S57>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/preSat Signal'
 * '<S58>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Anti-windup/Disc. Clamping Parallel'
 * '<S59>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/D Gain/Disabled'
 * '<S60>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter/Disabled'
 * '<S61>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S62>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/I Gain/External Parameters'
 * '<S63>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S64>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S65>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator/Discrete'
 * '<S66>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S67>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S68>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/N Gain/Disabled'
 * '<S69>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/P Copy/Disabled'
 * '<S70>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S71>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Reset Signal/External Reset'
 * '<S72>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation/Enabled'
 * '<S73>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S74>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum/Sum_PI'
 * '<S75>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S76>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S77>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S78>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S79>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S80>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Anti-windup'
 * '<S81>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/D Gain'
 * '<S82>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter'
 * '<S83>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter ICs'
 * '<S84>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/I Gain'
 * '<S85>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain'
 * '<S86>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S87>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator'
 * '<S88>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator ICs'
 * '<S89>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Copy'
 * '<S90>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Gain'
 * '<S91>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/P Copy'
 * '<S92>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Parallel P Gain'
 * '<S93>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Reset Signal'
 * '<S94>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation'
 * '<S95>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation Fdbk'
 * '<S96>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum'
 * '<S97>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum Fdbk'
 * '<S98>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode'
 * '<S99>'  : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S100>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/postSat Signal'
 * '<S101>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/preSat Signal'
 * '<S102>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Anti-windup/Disc. Clamping Parallel'
 * '<S103>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/D Gain/Disabled'
 * '<S104>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter/Disabled'
 * '<S105>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S106>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S107>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S108>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator/Discrete'
 * '<S110>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S111>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/N Gain/Disabled'
 * '<S113>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/P Copy/Disabled'
 * '<S114>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S115>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Reset Signal/External Reset'
 * '<S116>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation/Enabled'
 * '<S117>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S118>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S119>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S120>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S121>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S123>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S124>' : 'MotorControlLibNEWFixedP_FULL19b/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S125>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Inverse Clarke Transform'
 * '<S126>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Space Vector Generator'
 * '<S127>' : 'MotorControlLibNEWFixedP_FULL19b/Park Transform/Switch_Axis'
 * '<S128>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Atan2'
 * '<S129>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia'
 * '<S130>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2'
 * '<S131>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter'
 * '<S132>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter1'
 * '<S133>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter2'
 * '<S134>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Low pass filter3'
 * '<S135>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/DC Motor Model'
 * '<S136>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PI Controller'
 * '<S137>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PI Controller/Anti-windup'
 * '<S138>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/DC Motor Model'
 * '<S139>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/PI Controller'
 * '<S140>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia2/PI Controller/Anti-windup'
 * '<S141>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped'
 * '<S142>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Simulate start up Theta'
 * '<S143>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S144>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S145>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S146>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S147>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S148>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S149>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 */
#endif                      /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
