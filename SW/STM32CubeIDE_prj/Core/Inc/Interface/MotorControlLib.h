/*
 * File: MotorControlLib.h
 *
 * Code generated for Simulink model 'MotorControlLib'.
 *
 * Model version                  : 3.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 11 16:23:53 2023
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

/* Block states (default storage) for system '<S20>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S58>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S58>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S58>/Integrator' */
} DW_PIDAxis_MotorControlLib_T;

/* Block states (default storage) for system '<S8>/PI DAxis' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S177>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S177>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S177>/Integrator' */
} DW_PIDAxis_MotorControlLib_l_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Saturation;                 /* '<S184>/Saturation' */
  uint16_T Add2;                       /* '<S127>/Add2' */
  boolean_T TmpRTBAtSwitchInport2;
  boolean_T RelationalOperator;        /* '<S135>/Relational Operator' */
  boolean_T FixPtRelationalOperator;   /* '<S138>/FixPt Relational Operator' */
} B_MotorControlLib_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T IntegratorofAngle_DSTATE;   /* '<Root>/Integrator of Angle' */
  volatile real32_T RateTransition5_Buffer0;/* '<Root>/Rate Transition5' */
  uint16_T UnitDelay1_DSTATE;          /* '<S135>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S127>/Unit Delay' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S131>/Discrete-Time Integrator' */
  int16_T DelayInput1_DSTATE;          /* '<S138>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_pf;       /* '<S131>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_f;      /* '<S133>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S130>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_e;        /* '<S130>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_o;        /* '<S23>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S131>/Discrete-Time Integrator' */
  boolean_T TmpRTBAtSwitchInport2_Buffer0;/* synthesized block */
  boolean_T Memory_PreviousInput;      /* '<S136>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S137>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  MdlrefDW_SafetyChecks_T SafetyChecks_InstanceData;/* '<Root>/SafetyChecks' */
  DW_PIDAxis_MotorControlLib_l_T PIDAxis_h;/* '<S8>/PI DAxis' */
  DW_PIDAxis_MotorControlLib_T PIQaxis;/* '<S20>/PI Qaxis' */
  DW_PIDAxis_MotorControlLib_T PIDAxis;/* '<S20>/PI DAxis' */
} DW_MotorControlLib_T;

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
      uint32_T TID1_2;
      boolean_T b_TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B_MotorControlLib_T MotorControlLib_B;

/* Block states (default storage) */
extern DW_MotorControlLib_T MotorControlLib_DW;

/* External data declarations for dependent source files */
extern const int16_T MotorControlLib_sfix16_En8_GND;/* int16_T ground */

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
extern boolean_T activateRPMCntlr;     /* '<Root>/Inport8'
                                        * Set to 1 to activate the RPM Controller
                                        */
extern real32_T Sig_MechanicalAngle;   /* '<Root>/AngleCalculation' */
extern real32_T Sig_theta_el_m;        /* '<Root>/Multiport Switch' */
extern real32_T Sig_Ia_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Ib_m;              /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern real32_T Sig_Iq_Soll;           /* '<S9>/Switch' */
extern real32_T Sig_cos_m;             /* '<S13>/Sum6' */
extern real32_T Sig_Ibeta_m;           /* '<S139>/one_by_sqrt3' */
extern real32_T Sig_sin_m;             /* '<S13>/Sum4' */
extern real32_T Sig_Id_axis_meas;      /* '<S7>/Gain2' */
extern real32_T Sig_Iq_axis_meas;      /* '<S7>/Gain3' */
extern real32_T Sig_Vqsatu_m;          /* '<S4>/DQ_Limiter' */
extern real32_T Sig_Vdsatu_m;          /* '<S4>/DQ_Limiter' */
extern real32_T Sig_Va_m;              /* '<Root>/Gain' */
extern real32_T Sig_Vb_m;              /* '<Root>/Gain1' */
extern real32_T Sig_Valpha_m;          /* '<S5>/Switch' */
extern real32_T Sig_Vbeta_m;           /* '<S5>/Switch1' */
extern real32_T Sig_Vgamma_m;          /* '<S5>/Switch2' */
extern real32_T Sig_angle_speed;       /* '<Root>/Integrator of Angle' */
extern real32_T Sig_Rpm_measurment;    /* '<S8>/Unit Conversion' */
extern real32_T Sig_PRPM;              /* '<S8>/Data Type Conversion3' */
extern real32_T Sig_IRPM;              /* '<S8>/Data Type Conversion4' */
extern real32_T Sig_dAxis_errorSum_m;  /* '<S20>/Add' */
extern real32_T Sig_qAxis_errorSum_m;  /* '<S20>/Add1' */
extern real32_T Sig_IQ;                /* '<S20>/Data Type Conversion1' */
extern real32_T Sig_PQ;                /* '<S20>/Data Type Conversion2' */
extern real32_T Sig_PD;                /* '<S20>/Data Type Conversion3' */
extern real32_T Sig_ID;                /* '<S20>/Data Type Conversion4' */
extern real32_T Sig_dAxis_PI_out;      /* '<S20>/PI DAxis' */
extern real32_T Sig_qAxis_PI_out;      /* '<S20>/PI Qaxis' */
extern int16_T constantAngle;          /* '<S131>/Discrete-Time Integrator' */
extern boolean_T Sig_requestMotorBreak;/* '<S1>/OR' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T d_q_Voltage_Limiter_max;/* Variable: d_q_Voltage_Limiter_max
                                        * Referenced by: '<S4>/DQ_Limiter'
                                        * =Vnom/sqrt(3)
                                        */
extern int16_T d_q_Voltage_Limiter_sat_neg;/* Variable: d_q_Voltage_Limiter_sat_neg
                                            * Referenced by:
                                            *   '<S184>/Saturation'
                                            *   '<S65>/Saturation'
                                            *   '<S116>/Saturation'
                                            *   '<S170>/DeadZone'
                                            *   '<S51>/DeadZone'
                                            *   '<S102>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern int16_T d_q_Voltage_Limiter_sat_pos;/* Variable: d_q_Voltage_Limiter_sat_pos
                                            * Referenced by:
                                            *   '<S184>/Saturation'
                                            *   '<S65>/Saturation'
                                            *   '<S116>/Saturation'
                                            *   '<S170>/DeadZone'
                                            *   '<S51>/DeadZone'
                                            *   '<S102>/DeadZone'
                                            * fixdt(1,16,2^-4,0)
                                            */
extern uint16_T Ki_Rpm;                /* Variable: Ki_Rpm
                                        * Referenced by: '<S8>/Constant7'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Kp_Rpm;                /* Variable: Kp_Rpm
                                        * Referenced by: '<S8>/Constant6'
                                        * fixdt(0,16,2^-11,0)
                                        */
extern uint16_T Ki_dAxis;              /* Variable: Ki_dAxis
                                        * Referenced by: '<S20>/Constant7'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Ki_qAxis;              /* Variable: Ki_qAxis
                                        * Referenced by: '<S20>/Constant5'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_dAxis;              /* Variable: Kp_dAxis
                                        * Referenced by: '<S20>/Constant6'
                                        * fixdt(0,16,2^-8,0)
                                        */
extern uint16_T Kp_qAxis;              /* Variable: Kp_qAxis
                                        * Referenced by: '<S20>/Constant4'
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
extern uint16_T rpmSoll;               /* '<Root>/Data Store Memory1' */
extern int16_T qSoll;                  /* '<Root>/Data Store Memory'
                                        * fixdt(1,16,2^-8,0)
                                        */

/* Model entry point functions */
extern void MotorControlLib_initialize(void);
extern void MotorControlLib_step0(void);
extern void MotorControlLib_step1(void);
extern void MotorControlLib_step2(void);
extern void MotorControlLib_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorControlLib_T *const MotorControlLib_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S129>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S12>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S18>/Offset' : Unused code path elimination
 * Block '<S18>/Unary_Minus' : Unused code path elimination
 * Block '<S141>/Offset' : Unused code path elimination
 * Block '<S141>/Unary_Minus' : Unused code path elimination
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
 * '<S1>'   : 'MotorControlLib/Break Conditions'
 * '<S2>'   : 'MotorControlLib/CosSin'
 * '<S3>'   : 'MotorControlLib/Inverse Park Transform'
 * '<S4>'   : 'MotorControlLib/PI stage'
 * '<S5>'   : 'MotorControlLib/PWM Output'
 * '<S6>'   : 'MotorControlLib/Start up'
 * '<S7>'   : 'MotorControlLib/Subsystem'
 * '<S8>'   : 'MotorControlLib/Subsystem1'
 * '<S9>'   : 'MotorControlLib/Subsystem2'
 * '<S10>'  : 'MotorControlLib/Break Conditions/Compare To Zero'
 * '<S11>'  : 'MotorControlLib/Break Conditions/Compare To Zero1'
 * '<S12>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup'
 * '<S13>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S14>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S15>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S16>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S17>'  : 'MotorControlLib/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S18>'  : 'MotorControlLib/Inverse Park Transform/Switch_Axis'
 * '<S19>'  : 'MotorControlLib/PI stage/DQ_Limiter'
 * '<S20>'  : 'MotorControlLib/PI stage/PI_Controller'
 * '<S21>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis'
 * '<S22>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis'
 * '<S23>'  : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up'
 * '<S24>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID'
 * '<S25>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup'
 * '<S26>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain'
 * '<S27>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter'
 * '<S28>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs'
 * '<S29>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain'
 * '<S30>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain'
 * '<S31>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S32>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator'
 * '<S33>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs'
 * '<S34>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy'
 * '<S35>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain'
 * '<S36>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy'
 * '<S37>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain'
 * '<S38>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal'
 * '<S39>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation'
 * '<S40>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk'
 * '<S41>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum'
 * '<S42>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk'
 * '<S43>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode'
 * '<S44>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum'
 * '<S45>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral'
 * '<S46>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain'
 * '<S47>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal'
 * '<S48>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal'
 * '<S49>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S50>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S51>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S52>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/D Gain/Disabled'
 * '<S53>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter/Disabled'
 * '<S54>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Filter ICs/Disabled'
 * '<S55>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/I Gain/External Parameters'
 * '<S56>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S57>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S58>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator/Discrete'
 * '<S59>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Integrator ICs/External IC'
 * '<S60>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S61>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/N Gain/Disabled'
 * '<S62>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/P Copy/Disabled'
 * '<S63>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S64>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Reset Signal/External Reset'
 * '<S65>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation/Enabled'
 * '<S66>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S67>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum/Sum_PI'
 * '<S68>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S69>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S70>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S71>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S72>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S73>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S74>'  : 'MotorControlLib/PI stage/PI_Controller/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S75>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID'
 * '<S76>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup'
 * '<S77>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain'
 * '<S78>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter'
 * '<S79>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs'
 * '<S80>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain'
 * '<S81>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain'
 * '<S82>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk'
 * '<S83>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator'
 * '<S84>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs'
 * '<S85>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy'
 * '<S86>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain'
 * '<S87>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy'
 * '<S88>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain'
 * '<S89>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal'
 * '<S90>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation'
 * '<S91>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk'
 * '<S92>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum'
 * '<S93>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk'
 * '<S94>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode'
 * '<S95>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum'
 * '<S96>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral'
 * '<S97>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain'
 * '<S98>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal'
 * '<S99>'  : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal'
 * '<S100>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S101>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S102>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S103>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/D Gain/Disabled'
 * '<S104>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter/Disabled'
 * '<S105>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Filter ICs/Disabled'
 * '<S106>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/I Gain/External Parameters'
 * '<S107>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain/Passthrough'
 * '<S108>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S109>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator/Discrete'
 * '<S110>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Integrator ICs/External IC'
 * '<S111>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Copy/Disabled wSignal Specification'
 * '<S112>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/N Gain/Disabled'
 * '<S113>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/P Copy/Disabled'
 * '<S114>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Parallel P Gain/External Parameters'
 * '<S115>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Reset Signal/External Reset'
 * '<S116>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation/Enabled'
 * '<S117>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Saturation Fdbk/Disabled'
 * '<S118>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum/Sum_PI'
 * '<S119>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Sum Fdbk/Disabled'
 * '<S120>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode/Disabled'
 * '<S121>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tracking Mode Sum/Passthrough'
 * '<S122>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Integral/Passthrough'
 * '<S123>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/Tsamp - Ngain/Passthrough'
 * '<S124>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/postSat Signal/Forward_Path'
 * '<S125>' : 'MotorControlLib/PI stage/PI_Controller/PI Qaxis/PID/preSat Signal/Forward_Path'
 * '<S126>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Compare To Constant'
 * '<S127>' : 'MotorControlLib/PI stage/PI_Controller/disable integrator on start up/Subsystem'
 * '<S128>' : 'MotorControlLib/PWM Output/Inverse Clarke Transform'
 * '<S129>' : 'MotorControlLib/PWM Output/Space Vector Generator'
 * '<S130>' : 'MotorControlLib/Start up/Logic after motor is stoped'
 * '<S131>' : 'MotorControlLib/Start up/Simulate start up Theta'
 * '<S132>' : 'MotorControlLib/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S133>' : 'MotorControlLib/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S134>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S135>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S136>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S137>' : 'MotorControlLib/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S138>' : 'MotorControlLib/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S139>' : 'MotorControlLib/Subsystem/Clarke Transform'
 * '<S140>' : 'MotorControlLib/Subsystem/Park Transform'
 * '<S141>' : 'MotorControlLib/Subsystem/Park Transform/Switch_Axis'
 * '<S142>' : 'MotorControlLib/Subsystem1/PI DAxis'
 * '<S143>' : 'MotorControlLib/Subsystem1/PI DAxis/PID'
 * '<S144>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Anti-windup'
 * '<S145>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/D Gain'
 * '<S146>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Filter'
 * '<S147>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Filter ICs'
 * '<S148>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/I Gain'
 * '<S149>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Ideal P Gain'
 * '<S150>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Ideal P Gain Fdbk'
 * '<S151>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Integrator'
 * '<S152>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Integrator ICs'
 * '<S153>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/N Copy'
 * '<S154>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/N Gain'
 * '<S155>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/P Copy'
 * '<S156>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Parallel P Gain'
 * '<S157>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Reset Signal'
 * '<S158>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Saturation'
 * '<S159>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Saturation Fdbk'
 * '<S160>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Sum'
 * '<S161>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Sum Fdbk'
 * '<S162>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tracking Mode'
 * '<S163>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tracking Mode Sum'
 * '<S164>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tsamp - Integral'
 * '<S165>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tsamp - Ngain'
 * '<S166>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/postSat Signal'
 * '<S167>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/preSat Signal'
 * '<S168>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel'
 * '<S169>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S170>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S171>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/D Gain/Disabled'
 * '<S172>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Filter/Disabled'
 * '<S173>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Filter ICs/Disabled'
 * '<S174>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/I Gain/External Parameters'
 * '<S175>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Ideal P Gain/Passthrough'
 * '<S176>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Ideal P Gain Fdbk/Disabled'
 * '<S177>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Integrator/Discrete'
 * '<S178>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Integrator ICs/External IC'
 * '<S179>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/N Copy/Disabled wSignal Specification'
 * '<S180>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/N Gain/Disabled'
 * '<S181>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/P Copy/Disabled'
 * '<S182>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Parallel P Gain/External Parameters'
 * '<S183>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Reset Signal/External Reset'
 * '<S184>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Saturation/Enabled'
 * '<S185>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Saturation Fdbk/Disabled'
 * '<S186>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Sum/Sum_PI'
 * '<S187>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Sum Fdbk/Disabled'
 * '<S188>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tracking Mode/Disabled'
 * '<S189>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tracking Mode Sum/Passthrough'
 * '<S190>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tsamp - Integral/Passthrough'
 * '<S191>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/Tsamp - Ngain/Passthrough'
 * '<S192>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/postSat Signal/Forward_Path'
 * '<S193>' : 'MotorControlLib/Subsystem1/PI DAxis/PID/preSat Signal/Forward_Path'
 * '<S194>' : 'MotorControlLib/Subsystem2/torqueToIq'
 */
#endif                                 /* RTW_HEADER_MotorControlLib_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
