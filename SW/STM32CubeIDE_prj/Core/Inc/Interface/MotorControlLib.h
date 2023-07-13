/*
 * File: MotorControlLib.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 3.56
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:30:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MotorControlLib_h_
#define RTW_HEADER_MotorControlLib_h_
#ifndef MotorControlLib_COMMON_INCLUDES_
#define MotorControlLib_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MotorControlLib_COMMON_INCLUDES_ */

#include "MotorControlLib_types.h"
#include "ADCRawToIab.h"
#include "SafetyChecks.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Includes for objects with custom storage classes */
#include "ConstParams.h"
#include "PWMtoAngle_const.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block states (default storage) for system '<S17>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S56>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S56>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S56>/Integrator' */
} DW_PIDAxis_MotorControlLib_T;

/* Block signals (default storage) */
typedef struct {
  boolean_T FixPtRelationalOperator;   /* '<S137>/FixPt Relational Operator' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<Root>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE;          /* '<S134>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S125>/Unit Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S130>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S137>/Delay Input1' */
  uint8_T UnitDelay_DSTATE_c;          /* '<S8>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_pf;       /* '<S130>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S132>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S129>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_eb;       /* '<S129>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S21>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S130>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput;      /* '<S135>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S136>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_PIDAxis_MotorControlLib_T PIQaxis;/* '<S17>/PI Qaxis' */
  DW_PIDAxis_MotorControlLib_T PIDAxis;/* '<S17>/PI DAxis' */
} DW_MotorControlLib_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Position;                   /* '<Root>/Position' */
} ExtY_MotorControlLib_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLib_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
extern DW_MotorControlLib_T MotorControlLib_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MotorControlLib_T MotorControlLib_Y;

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
extern real32_T Sig_Theta_el_cont_m;   /* '<S5>/Switch' */
extern real32_T Sig_Iq_Soll;           /* '<S18>/Tq--> iqRef' */
extern real32_T Sig_cos_m;             /* '<S10>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S138>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S10>/Sum4' */
extern real32_T Sig_Id_axis_meas;      /* '<S7>/Gain2' */
extern real32_T Sig_Iq_axis_meas;      /* '<S7>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<S3>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<S3>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S4>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S4>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S4>/Switch2' */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S17>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S17>/Add1' */
extern real32_T Sig_dAxis_PI_out;      /* '<S17>/PI DAxis' */
extern real32_T Sig_qAxis_PI_out;      /* '<S17>/PI Qaxis' */
extern int16_T constantAngle;          /* '<S130>/Discrete-Time Integrator' */
extern volatile float Q_P;
extern volatile float Q_I;
/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S3>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S63>/Saturation'
                                            *   '<S114>/Saturation'
                                            *   '<S49>/DeadZone'
                                            *   '<S100>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S63>/Saturation'
                                            *   '<S114>/Saturation'
                                            *   '<S49>/DeadZone'
                                            *   '<S100>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern uint16_T Kp_dAxis;              /* Variable: Kp_dAxis
                                        * Referenced by: '<S17>/Constant6'
                                        * fixdt(0,16,2^-10,0)
                                        */
extern uint32_T Kp_qAxis;              /* Variable: Kp_qAxis
                                        * Referenced by: '<S17>/Constant4'
                                        * fixdt(0,16,2^-10,0)
                                        */
extern uint16_T Ki_dAxis;              /* Variable: Ki_dAxis
                                        * Referenced by: '<S17>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint32_T Ki_qAxis;              /* Variable: Ki_qAxis
                                        * Referenced by: '<S17>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T MaximumCurrentBeforeReaction;/* Variable: MaximumCurrentBeforeReaction
                                              * Referenced by: '<Root>/SafetyChecks'
                                              * Maximum current limit before software shutdowns the mosfets.
                                              */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern int16_T qSoll;                  /* '<Root>/Data Store Memory'
                                      * fixdt(1,16,2^-8,0)
                                        */
extern float Sig_omega;
/* Model entry point functions */
extern void MotorControlLib_initialize(void);
extern void MotorControlLib_step(void);
extern void MotorControlLib_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLib_T *const MotorControlLib_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S9>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S16>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S15>/Offset' : Unused code path elimination
 * Block '<S15>/Unary_Minus' : Unused code path elimination
 * Block '<S140>/Offset' : Unused code path elimination
 * Block '<S140>/Unary_Minus' : Unused code path elimination
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
 * '<S1>'   : 'MotorControlLib/CosSin'
 * '<S2>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S3>'   : 'MotorControlLib/PI stage'
 * '<S4>'   : 'MotorControlLib/PWM Output'
 * '<S5>'   : 'MotorControlLib/Prepare theta el. for RPM'
 * '<S6>'   : 'MotorControlLib/Start up'
 * '<S7>'   : 'MotorControlLib/Subsystem'
 * '<S8>'   : 'MotorControlLib/detectStartUp'
 * '<S9>'   : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S10>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S11>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S12>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S13>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S14>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S15>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S16>'  : 'MotorControlLib/PI stage/DQ_Limiter'
 * '<S17>'  : 'MotorControlLib/PI stage/PI_Controller'
 * '<S18>'  : 'MotorControlLib/PI stage/torqueToIq'
 * '<S19>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis'
 * '<S20>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis'
 * '<S21>'  : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up'
 * '<S22>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID'
 * '<S23>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup'
 * '<S24>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain'
 * '<S25>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter'
 * '<S26>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs'
 * '<S27>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain'
 * '<S28>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain'
 * '<S29>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S30>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator'
 * '<S31>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs'
 * '<S32>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy'
 * '<S33>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain'
 * '<S34>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy'
 * '<S35>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain'
 * '<S36>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal'
 * '<S37>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation'
 * '<S38>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk'
 * '<S39>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum'
 * '<S40>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk'
 * '<S41>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode'
 * '<S42>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum'
 * '<S43>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral'
 * '<S44>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain'
 * '<S45>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal'
 * '<S46>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal'
 * '<S47>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S48>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S49>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S50>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain/Disabled'
 * '<S51>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter/Disabled'
 * '<S52>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs/Disabled'
 * '<S53>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain/External Parameters'
 * '<S54>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S55>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S56>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator/Discrete'
 * '<S57>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs/External IC'
 * '<S58>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S59>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain/Disabled'
 * '<S60>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy/Disabled'
 * '<S61>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S62>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal/External Reset'
 * '<S63>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation/Enabled'
 * '<S64>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S65>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum/Sum_PI'
 * '<S66>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S67>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S68>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S69>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S70>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S71>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S72>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S73>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID'
 * '<S74>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup'
 * '<S75>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain'
 * '<S76>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter'
 * '<S77>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs'
 * '<S78>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain'
 * '<S79>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain'
 * '<S80>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk'
 * '<S81>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator'
 * '<S82>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs'
 * '<S83>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy'
 * '<S84>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain'
 * '<S85>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy'
 * '<S86>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain'
 * '<S87>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal'
 * '<S88>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation'
 * '<S89>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk'
 * '<S90>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum'
 * '<S91>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk'
 * '<S92>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode'
 * '<S93>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum'
 * '<S94>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral'
 * '<S95>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain'
 * '<S96>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal'
 * '<S97>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal'
 * '<S98>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S99>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S100>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S101>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain/Disabled'
 * '<S102>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter/Disabled'
 * '<S103>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs/Disabled'
 * '<S104>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain/External Parameters'
 * '<S105>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain/Passthrough'
 * '<S106>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S107>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator/Discrete'
 * '<S108>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs/External IC'
 * '<S109>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy/Disabled wSignal Specification'
 * '<S110>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain/Disabled'
 * '<S111>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy/Disabled'
 * '<S112>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain/External Parameters'
 * '<S113>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal/External Reset'
 * '<S114>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation/Enabled'
 * '<S115>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk/Disabled'
 * '<S116>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum/Sum_PI'
 * '<S117>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk/Disabled'
 * '<S118>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode/Disabled'
 * '<S119>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum/Passthrough'
 * '<S120>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral/Passthrough'
 * '<S121>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain/Passthrough'
 * '<S122>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal/Forward_Path'
 * '<S123>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal/Forward_Path'
 * '<S124>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S125>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Subsystem'
 * '<S126>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S127>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S128>' : 'MotorControlLib/Prepare theta el. for RPM/Compare To Constant'
 * '<S129>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S130>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S131>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S132>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S133>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S134>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S135>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S136>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S137>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S138>' : 'MotorControlLib/Subsystem/Clarke Transform'
 * '<S139>' : 'MotorControlLib/Subsystem/Park Transform'
 * '<S140>' : 'MotorControlLib/Subsystem/Park Transform/Switch_Axis'
 * '<S141>' : 'MotorControlLib/detectStartUp/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
