/*
 * File: MotorControlLib.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Oct 28 10:27:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorControlLib_h_
#define RTW_HEADER_MotorControlLib_h_
#include <math.h>
#ifndef MotorControlLib_COMMON_INCLUDES_
# define MotorControlLib_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* MotorControlLib_COMMON_INCLUDES_ */

#include "MotorControlLib_types.h"

/* Child system includes */
#include "ADCRawToIab.h"
#define ConvertPWMtoAngle_MDLREF_HIDE_CHILD_
#include "ConvertPWMtoAngle.h"
#include "SafetyChecks.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"
#include "PWMtoAngle_const.h"
#include "rtGetNaN.h"
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

/* Block signals for system '<Root>/Flux_observer' */
typedef struct {
  real32_T Merge;                      /* '<S21>/Merge' */
} B_Flux_observer_MotorControlL_T;

/* Block states (default storage) for system '<Root>/Flux_observer' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S23>/Delay' */
  real32_T Delay_DSTATE_e;             /* '<S22>/Delay' */
} DW_Flux_observer_MotorControl_T;

/* Zero-crossing (trigger) state for system '<Root>/Flux_observer' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S23>/Delay' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S22>/Delay' */
} ZCE_Flux_observer_MotorContro_T;

/* Block states (default storage) for system '<S6>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S64>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S64>/Integrator' */
} DW_PIDAxis_MotorControlLib_T;

/* Block states (default storage) for system '<S6>/PI Qaxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S109>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S109>/Integrator' */
} DW_PIQaxis_MotorControlLib_T;

/* Block signals for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay;                  /* '<S130>/Unit Delay' */
  int16_T Sum1;                        /* '<S141>/Sum1' */
  int16_T Sum1_p;                      /* '<S138>/Sum1' */
  int16_T UnitDelay_n;                 /* '<S9>/Unit Delay' */
  int16_T UnitDelay1;                  /* '<S9>/Unit Delay1' */
  int16_T UnitDelay_j;                 /* '<S131>/Unit Delay' */
} B_Positionobserver_MotorContr_T;

/* Block states (default storage) for system '<Root>/Position observer' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S130>/Unit Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S136>/Unit Delay' */
  int16_T Delay1_DSTATE;               /* '<S141>/Delay1' */
  int16_T Delay1_DSTATE_m;             /* '<S138>/Delay1' */
  int16_T UnitDelay_DSTATE_g;          /* '<S131>/Unit Delay' */
  int16_T UnitDelay_DSTATE_m;          /* '<S139>/Unit Delay' */
  int16_T Delay_DSTATE;                /* '<S139>/Delay' */
  int16_T Delay_DSTATE_l;              /* '<S132>/Delay' */
  int16_T Delay_DSTATE_k;              /* '<S133>/Delay' */
  int16_T Delay_DSTATE_b;              /* '<S135>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S134>/Delay' */
  int16_T UnitDelay_DSTATE_cm;         /* '<S9>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S132>/Unit Delay' */
  int16_T UnitDelay_DSTATE_o;          /* '<S133>/Unit Delay' */
  int16_T UnitDelay1_DSTATE;           /* '<S9>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_p;          /* '<S135>/Unit Delay' */
  int16_T UnitDelay_DSTATE_mq;         /* '<S134>/Unit Delay' */
  boolean_T Positionobserver_MODE;     /* '<Root>/Position observer' */
} DW_Positionobserver_MotorCont_T;

/* Zero-crossing (trigger) state for system '<Root>/Position observer' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S141>/Delay1' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S138>/Delay1' */
} ZCE_Positionobserver_MotorCon_T;

/* Block signals (default storage) */
typedef struct {
  real32_T RateTransition3;            /* '<Root>/Rate Transition3' */
  real32_T RateTransition2;            /* '<Root>/Rate Transition2' */
  real32_T UnitDelay3;                 /* '<Root>/Unit Delay3' */
  real32_T AngleCalculation_o2;        /* '<Root>/AngleCalculation' */
  boolean_T RateTransition4;           /* '<Root>/Rate Transition4' */
  boolean_T FixPtRelationalOperator;   /* '<S151>/FixPt Relational Operator' */
  B_Positionobserver_MotorContr_T Positionobserver;/* '<Root>/Position observer' */
  B_Flux_observer_MotorControlL_T Flux_observer;/* '<Root>/Flux_observer' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<Root>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<Root>/Unit Delay2' */
  real32_T UnitDelay_DSTATE;           /* '<Root>/Unit Delay' */
  real32_T RateTransition3_Buffer0;    /* '<Root>/Rate Transition3' */
  real32_T RateTransition2_Buffer0;    /* '<Root>/Rate Transition2' */
  uint16_T UnitDelay1_DSTATE_o;        /* '<S148>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S125>/Unit Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S144>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S151>/Delay Input1' */
  int16_T RateTransition1_Buffer;      /* '<Root>/Rate Transition1' */
  uint8_T UnitDelay_DSTATE_c;          /* '<S12>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_eb;       /* '<S143>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S146>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S143>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_pf;       /* '<S144>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S33>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S144>/Discrete-Time Integrator' */
  boolean_T RateTransition4_Buffer0;   /* '<Root>/Rate Transition4' */
  boolean_T Memory_PreviousInput;      /* '<S149>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S150>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_Positionobserver_MotorCont_T Positionobserver;/* '<Root>/Position observer' */
  DW_PIQaxis_MotorControlLib_T PIQaxis;/* '<S6>/PI Qaxis' */
  DW_PIDAxis_MotorControlLib_T PIDAxis;/* '<S6>/PI DAxis' */
  DW_Flux_observer_MotorControl_T Flux_observer;/* '<Root>/Flux_observer' */
} DW_MotorControlLib_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Positionobserver_MotorCon_T Positionobserver;/* '<Root>/Position observer' */
  ZCE_Flux_observer_MotorContro_T Flux_observer;/* '<Root>/Flux_observer' */
} PrevZCX_MotorControlLib_T;

/* Invariant block signals for system '<Root>/Flux_observer' */
typedef struct {
  const boolean_T Compare;             /* '<S24>/Compare' */
  const boolean_T Compare_l;           /* '<S25>/Compare' */
} ConstB_Flux_observer_MotorCon_T;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_Flux_observer_MotorCon_T Flux_observer;/* '<Root>/Flux_observer' */
} ConstB_MotorControlLib_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Position;                   /* '<Root>/Position' */
} ExtY_MotorControlLib_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLib_T {
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
extern B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
extern DW_MotorControlLib_T MotorControlLib_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorControlLib_T MotorControlLib_Y;
extern const ConstB_MotorControlLib_T MotorControlLib_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T resetPIIntegratorDQ;  /* '<Root>/Inport6' */
extern boolean_T enableFluxObs;        /* '<Root>/Inport2' */
extern uint8_T set_AngleInput;         /* '<Root>/Inport1' */
extern boolean_T enablePositionObs;    /* '<Root>/Inport3' */
extern int16_T dth_dt;                 /* '<Root>/Inport4' */
extern boolean_T resetPIIntegrator;    /* '<Root>/Inport5' */
extern boolean_T Sig_change_SVMalgorithm;/* '<Root>/In1' */
extern real32_T Sig_Ia_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Ib_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Theta_el_cont_m;   /* '<S10>/Switch' */
extern real32_T Sig_Iq_Soll;           /* '<S13>/Tq--> iqRef' */
extern real32_T Sig_cos_m;             /* '<S15>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S1>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S15>/Sum4' */
extern real32_T Sig_dAxis_m;           /* '<Root>/Gain2' */
extern real32_T Sig_qAxis_m;           /* '<Root>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<Root>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<Root>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S7>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S7>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S7>/Switch2' */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S6>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S6>/Add1' */
extern int16_T constantAngle;          /* '<S144>/Discrete-Time Integrator' */
extern int16_T PositionObsAnlge;       /* '<S129>/Data Type Conversion5' */
extern int16_T FluxObsAngle;           /* '<S20>/PositionGain' */
extern real32_T Sig_Emfobs_errorSum_m; /* '<S130>/Add6' */
extern real32_T Sig_Emfobs_PI_out;     /* '<S137>/Saturation' */
extern real32_T di_dt_E9;              /* '<S136>/Inductance' */
extern real32_T di_dt_times_Ts_En8;    /* '<S136>/Gain' */
extern real32_T i_integrated_en4;      /* '<S136>/Sum' */
extern real32_T i_integrated_times_Rs_en8;/* '<S136>/Resistance' */
extern real32_T Va_all_16En4;          /* '<S136>/Add5' */
extern int16_T Sig_First_LPF_out;      /* '<S132>/Product1'
                                        * 16En6
                                        */
extern int16_T Sig_Second_LPF_out;     /* '<S133>/Product1'
                                        * 16En6
                                        */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S8>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S8>/Add1' */

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
                                        *   '<S136>/Gain'
                                        *   '<S139>/Gain'
                                        * fixdt(0,32,2^-24,0)
                                        */
extern int16_T MaxBckEMFVol_sat_neg;   /* Variable: MaxBckEMFVol_sat_neg
                                        * Referenced by:
                                        *   '<S137>/Saturation'
                                        *   '<S140>/Saturation'
                                        * fixdt(1,16,2^-2,0)
                                        */
extern int16_T MaxBckEMFVol_sat_pos;   /* Variable: MaxBckEMFVol_sat_pos
                                        * Referenced by:
                                        *   '<S137>/Saturation'
                                        *   '<S140>/Saturation'
                                        * fixdt(1,32,2^-8,0)
                                        */
extern int16_T Ki_Iab_EMFobs;          /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S138>/Ki'
                                        *   '<S141>/Ki'
                                        * fixdt(1,16,2^-3,0)
                                        */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<Root>/DQ_Limiter'
                                        * =12/sqrt(3)
                                        */
extern uint16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S6>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern uint16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S6>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern uint16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S6>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern uint16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S6>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_Iab_EMFobs;          /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S137>/Kp'
                                        *   '<S140>/Kp'
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
                                        *   '<S132>/Constant'
                                        *   '<S133>/Constant'
                                        *   '<S134>/Constant'
                                        *   '<S135>/Constant'
                                        */
extern real32_T Sig_theta_el_m;
/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T UnitDelayIntegratorPosObs;/* '<S136>/Delay' */

/* Model entry point functions */
extern void MotorControlLib_initialize(void);
extern void MotorControlLib_step(void);
extern void MotorControlLib_terminate(void);
extern float Sig_dAxis_PI_out;      /* '<S111>/Saturation' */
extern float Sig_qAxis_PI_out;      /* '<S67>/Saturation' */
/* Real-time Model object */
extern RT_MODEL_MotorControlLib_T *const MotorControlLib_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Propagation' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Conversion1' : Unused code path elimination
 * Block '<S20>/FluxGain' : Unused code path elimination
 * Block '<S20>/Product' : Unused code path elimination
 * Block '<S20>/Product1' : Unused code path elimination
 * Block '<S20>/Sqrt' : Unused code path elimination
 * Block '<S20>/Square' : Unused code path elimination
 * Block '<S20>/Square1' : Unused code path elimination
 * Block '<S20>/Sum' : Unused code path elimination
 * Block '<S20>/Sum1' : Unused code path elimination
 * Block '<S20>/TorqueGain' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S14>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S32>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S9>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S136>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S130>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S130>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S131>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S131>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S131>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S131>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S10>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Offset' : Unused code path elimination
 * Block '<S30>/Unary_Minus' : Unused code path elimination
 * Block '<S128>/Offset' : Unused code path elimination
 * Block '<S128>/Unary_Minus' : Unused code path elimination
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
 * '<Root>' : 'MotorControlLib'
 * '<S1>'   : 'MotorControlLib/Clarke Transform'
 * '<S2>'   : 'MotorControlLib/CosSin'
 * '<S3>'   : 'MotorControlLib/DQ_Limiter'
 * '<S4>'   : 'MotorControlLib/Flux_observer'
 * '<S5>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S6>'   : 'MotorControlLib/PI_Controller'
 * '<S7>'   : 'MotorControlLib/PWM Output'
 * '<S8>'   : 'MotorControlLib/Park Transform'
 * '<S9>'   : 'MotorControlLib/Position observer'
 * '<S10>'  : 'MotorControlLib/Prepare theta el. for RPM'
 * '<S11>'  : 'MotorControlLib/Start up'
 * '<S12>'  : 'MotorControlLib/detectStartUp'
 * '<S13>'  : 'MotorControlLib/torqueToIq'
 * '<S14>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S15>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S16>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S17>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S18>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S19>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S20>'  : 'MotorControlLib/Flux_observer/Flux Observer'
 * '<S21>'  : 'MotorControlLib/Flux_observer/Flux Observer/atan2'
 * '<S22>'  : 'MotorControlLib/Flux_observer/Flux Observer/psiAlpha'
 * '<S23>'  : 'MotorControlLib/Flux_observer/Flux Observer/psiBeta'
 * '<S24>'  : 'MotorControlLib/Flux_observer/Flux Observer/atan2/Compare To Constant'
 * '<S25>'  : 'MotorControlLib/Flux_observer/Flux Observer/atan2/Compare To Constant1'
 * '<S26>'  : 'MotorControlLib/Flux_observer/Flux Observer/atan2/If Action Subsystem'
 * '<S27>'  : 'MotorControlLib/Flux_observer/Flux Observer/atan2/per Uint'
 * '<S28>'  : 'MotorControlLib/Flux_observer/Flux Observer/psiAlpha/Scaling'
 * '<S29>'  : 'MotorControlLib/Flux_observer/Flux Observer/psiBeta/Scaling'
 * '<S30>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S31>'  : 'MotorControlLib/PI_Controller/PI DAxis'
 * '<S32>'  : 'MotorControlLib/PI_Controller/PI Qaxis'
 * '<S33>'  : 'MotorControlLib/PI_Controller/disable integrator on start up'
 * '<S34>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID'
 * '<S35>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Anti-windup'
 * '<S36>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/D Gain'
 * '<S37>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Filter'
 * '<S38>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Filter ICs'
 * '<S39>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/I Gain'
 * '<S40>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Ideal P Gain'
 * '<S41>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S42>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Integrator'
 * '<S43>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Integrator ICs'
 * '<S44>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/N Copy'
 * '<S45>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/N Gain'
 * '<S46>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/P Copy'
 * '<S47>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Parallel P Gain'
 * '<S48>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Reset Signal'
 * '<S49>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Saturation'
 * '<S50>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Saturation Fdbk'
 * '<S51>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Sum'
 * '<S52>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Sum Fdbk'
 * '<S53>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Tracking Mode'
 * '<S54>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Tracking Mode Sum'
 * '<S55>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/postSat Signal'
 * '<S56>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/preSat Signal'
 * '<S57>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S58>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/D Gain/Disabled'
 * '<S59>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Filter/Disabled'
 * '<S60>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Filter ICs/Disabled'
 * '<S61>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/I Gain/External Parameters'
 * '<S62>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S63>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S64>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Integrator/Discrete'
 * '<S65>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Integrator ICs/Internal IC'
 * '<S66>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S67>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/N Gain/Disabled'
 * '<S68>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/P Copy/Disabled'
 * '<S69>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S70>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Reset Signal/External Reset'
 * '<S71>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Saturation/Enabled'
 * '<S72>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S73>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Sum/Sum_PI'
 * '<S74>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S75>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S76>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S77>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S78>'  : 'MotorControlLib/PI_Controller/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S79>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID'
 * '<S80>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Anti-windup'
 * '<S81>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/D Gain'
 * '<S82>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Filter'
 * '<S83>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Filter ICs'
 * '<S84>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/I Gain'
 * '<S85>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Ideal P Gain'
 * '<S86>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk'
 * '<S87>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Integrator'
 * '<S88>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Integrator ICs'
 * '<S89>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/N Copy'
 * '<S90>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/N Gain'
 * '<S91>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/P Copy'
 * '<S92>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Parallel P Gain'
 * '<S93>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Reset Signal'
 * '<S94>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Saturation'
 * '<S95>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Saturation Fdbk'
 * '<S96>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Sum'
 * '<S97>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Sum Fdbk'
 * '<S98>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Tracking Mode'
 * '<S99>'  : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Tracking Mode Sum'
 * '<S100>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/postSat Signal'
 * '<S101>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/preSat Signal'
 * '<S102>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S103>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/D Gain/Disabled'
 * '<S104>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Filter/Disabled'
 * '<S105>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Filter ICs/Disabled'
 * '<S106>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/I Gain/External Parameters'
 * '<S107>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Ideal P Gain/Passthrough'
 * '<S108>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Integrator/Discrete'
 * '<S110>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Integrator ICs/Internal IC'
 * '<S111>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/N Gain/Disabled'
 * '<S113>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/P Copy/Disabled'
 * '<S114>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Parallel P Gain/External Parameters'
 * '<S115>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Reset Signal/External Reset'
 * '<S116>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Saturation/Enabled'
 * '<S117>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Saturation Fdbk/Disabled'
 * '<S118>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Sum/Sum_PI'
 * '<S119>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Sum Fdbk/Disabled'
 * '<S120>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Tracking Mode/Disabled'
 * '<S121>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/postSat Signal/Forward_Path'
 * '<S123>' : 'MotorControlLib/PI_Controller/PI Qaxis/PID/preSat Signal/Forward_Path'
 * '<S124>' : 'MotorControlLib/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S125>' : 'MotorControlLib/PI_Controller/disable integrator on start up/Subsystem'
 * '<S126>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S127>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S128>' : 'MotorControlLib/Park Transform/Switch_Axis'
 * '<S129>' : 'MotorControlLib/Position observer/Atan2'
 * '<S130>' : 'MotorControlLib/Position observer/EMF Observer Ia'
 * '<S131>' : 'MotorControlLib/Position observer/EMF Observer Ia2'
 * '<S132>' : 'MotorControlLib/Position observer/Low pass filter'
 * '<S133>' : 'MotorControlLib/Position observer/Low pass filter1'
 * '<S134>' : 'MotorControlLib/Position observer/Low pass filter2'
 * '<S135>' : 'MotorControlLib/Position observer/Low pass filter3'
 * '<S136>' : 'MotorControlLib/Position observer/EMF Observer Ia/DC Motor Model'
 * '<S137>' : 'MotorControlLib/Position observer/EMF Observer Ia/PI Controller'
 * '<S138>' : 'MotorControlLib/Position observer/EMF Observer Ia/PI Controller/Anti-windup'
 * '<S139>' : 'MotorControlLib/Position observer/EMF Observer Ia2/DC Motor Model'
 * '<S140>' : 'MotorControlLib/Position observer/EMF Observer Ia2/PI Controller'
 * '<S141>' : 'MotorControlLib/Position observer/EMF Observer Ia2/PI Controller/Anti-windup'
 * '<S142>' : 'MotorControlLib/Prepare theta el. for RPM/Compare To Constant'
 * '<S143>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S144>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S145>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S146>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S147>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S148>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S149>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S150>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S151>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S152>' : 'MotorControlLib/detectStartUp/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
