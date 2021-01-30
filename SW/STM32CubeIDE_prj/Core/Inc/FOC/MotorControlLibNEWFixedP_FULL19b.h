/*
 * File: MotorControlLibNEWFixedP_FULL19b.h
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

#ifndef RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_
#define RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_
#include <math.h>
#ifndef MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_
# define MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                   /* MotorControlLibNEWFixedP_FULL19b_COMMON_INCLUDES_ */

#include "MotorControlLibNEWFixedP_FULL19b_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "ADCRawToIab.h"

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

/* Block signals (default storage) */
typedef struct {
  int16_T DiscreteTimeIntegrator;      /* '<S208>/Discrete-Time Integrator' */
  int16_T Merge;                       /* '<S202>/Merge' */
  int16_T PositionGain;                /* '<S111>/PositionGain' */
  boolean_T RelationalOperator;        /* '<S212>/Relational Operator' */
  boolean_T FixPtRelationalOperator;   /* '<S215>/FixPt Relational Operator' */
} B_MotorControlLibNEWFixedP_FU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T UnitDelay1_DSTATE;          /* '<S212>/Unit Delay1' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S208>/Discrete-Time Integrator' */
  int16_T DiscreteTimeIntegrator_DSTATE_e;/* '<S109>/Discrete-Time Integrator' */
  int16_T DiscreteTimeIntegrator_DSTATE_j;/* '<S110>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE;           /* '<S92>/Integrator' */
  int16_T Integrator_DSTATE_m;         /* '<S48>/Integrator' */
  int16_T Integrator_DSTATE_k;         /* '<S142>/Integrator' */
  int16_T Integrator_DSTATE_n;         /* '<S187>/Integrator' */
  boolean_T UnitDelay_DSTATE;          /* '<S207>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S210>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S208>/Unit Delay' */
  int8_T DelayInput1_DSTATE_h;         /* '<S215>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S208>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput;      /* '<S213>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S214>/Memory' */
  boolean_T SimulatestartupTheta_MODE; /* '<S8>/Simulate start up Theta' */
  boolean_T Positionobserver_MODE;     /* '<Root>/Position observer' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
} DW_MotorControlLibNEWFixedP_F_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int32_T Gain;                  /* '<S208>/Gain' */
  const boolean_T Compare;             /* '<S203>/Compare' */
  const boolean_T Compare_o;           /* '<S204>/Compare' */
} ConstB_MotorControlLibNEWFixe_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Position;                    /* '<Root>/Position' */
} ExtY_MotorControlLibNEWFixedP_T;

/* Real-time Model Data Structure */
struct tag_RTM_MotorControlLibNEWFix_T {
  const char_T * volatile errorStatus;
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
extern int16_T Sig_theta_el_m;         /* '<Root>/Delay' */
extern int16_T Sig_Ia_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ib_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_dAxis_m;            /* '<Root>/Gain2' */
extern int16_T Sig_dAxis_errorSum_m;   /* '<S4>/Add' */
extern int16_T Sig_qAxis_m;            /* '<Root>/Gain3' */
extern int16_T Sig_qAxis_errorSum_m;   /* '<S4>/Add1' */
extern int16_T Sig_Vqsatu_m;           /* '<S9>/Multiport Switch1' */
extern int16_T Sig_Vdsatu_m;           /* '<S9>/Multiport Switch' */
extern int16_T Sig_Va_m;               /* '<Root>/Gain' */
extern int16_T Sig_Vb_m;               /* '<Root>/Gain1' */
extern int16_T Sig_Emfobs_errorSum_m;  /* '<S109>/Add6' */
extern int16_T Sig_dAxis_PI_out;       /* '<S99>/Saturation' */
extern int16_T Sig_qAxis_PI_out;       /* '<S55>/Saturation' */
extern int16_T Sig_Emfobs_PI_out;      /* '<S149>/Saturation' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T Ki_Iab_EMFobs;          /* Variable: Ki_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S139>/Integral Gain'
                                        *   '<S184>/Integral Gain'
                                        * fixdt(1,16,2^-3,0)
                                        */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S4>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S4>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S4>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S4>/Constant4'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_Iab_EMFobs;          /* Variable: Kp_Iab_EMFobs
                                        * Referenced by:
                                        *   '<S147>/Proportional Gain'
                                        *   '<S192>/Proportional Gain'
                                        * fixdt(1,16,2^-8,0)
                                        */
extern int8_T qSoll;                   /* Variable: qSoll
                                        * Referenced by: '<Root>/q Soll'
                                        * fixdt(1,8,2^-7,0)
                                        */

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
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<Root>/Data Type Conversion5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion9' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Scope3' : Unused code path elimination
 * Block '<S7>/Scope5' : Unused code path elimination
 * Block '<Root>/d-Axis Scope' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Propagation' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Propagation' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Propagation' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S16>/Offset' : Unused code path elimination
 * Block '<S16>/Unary_Minus' : Unused code path elimination
 * Block '<S108>/Offset' : Unused code path elimination
 * Block '<S108>/Unary_Minus' : Unused code path elimination
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
 * '<S3>'   : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform'
 * '<S4>'   : 'MotorControlLibNEWFixedP_FULL19b/PI Controller'
 * '<S5>'   : 'MotorControlLibNEWFixedP_FULL19b/PWM Output'
 * '<S6>'   : 'MotorControlLibNEWFixedP_FULL19b/Park Transform'
 * '<S7>'   : 'MotorControlLibNEWFixedP_FULL19b/Position observer'
 * '<S8>'   : 'MotorControlLibNEWFixedP_FULL19b/Start up'
 * '<S9>'   : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter'
 * '<S10>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup'
 * '<S11>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S12>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S13>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S14>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S15>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S16>'  : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform/Switch_Axis'
 * '<S17>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis'
 * '<S18>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1'
 * '<S19>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup'
 * '<S20>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain'
 * '<S21>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter'
 * '<S22>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs'
 * '<S23>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain'
 * '<S24>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain'
 * '<S25>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S26>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator'
 * '<S27>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs'
 * '<S28>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy'
 * '<S29>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain'
 * '<S30>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy'
 * '<S31>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain'
 * '<S32>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal'
 * '<S33>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation'
 * '<S34>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk'
 * '<S35>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum'
 * '<S36>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk'
 * '<S37>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode'
 * '<S38>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum'
 * '<S39>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal'
 * '<S40>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal'
 * '<S41>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup/Disc. Clamping Parallel'
 * '<S42>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain/Disabled'
 * '<S43>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter/Disabled'
 * '<S44>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S45>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain/External Parameters'
 * '<S46>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S47>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator/Discrete'
 * '<S49>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S50>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S51>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain/Disabled'
 * '<S52>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy/Disabled'
 * '<S53>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S54>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal/Disabled'
 * '<S55>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation/Enabled'
 * '<S56>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S57>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum/Sum_PI'
 * '<S58>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S59>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S60>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S62>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S63>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup'
 * '<S64>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain'
 * '<S65>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter'
 * '<S66>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs'
 * '<S67>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain'
 * '<S68>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain'
 * '<S69>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S70>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator'
 * '<S71>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs'
 * '<S72>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy'
 * '<S73>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain'
 * '<S74>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy'
 * '<S75>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain'
 * '<S76>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal'
 * '<S77>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation'
 * '<S78>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk'
 * '<S79>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum'
 * '<S80>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk'
 * '<S81>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode'
 * '<S82>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S83>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal'
 * '<S84>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal'
 * '<S85>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup/Disc. Clamping Parallel'
 * '<S86>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain/Disabled'
 * '<S87>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter/Disabled'
 * '<S88>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S89>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S90>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S91>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator/Discrete'
 * '<S93>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S94>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S95>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain/Disabled'
 * '<S96>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy/Disabled'
 * '<S97>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S98>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal/Disabled'
 * '<S99>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation/Enabled'
 * '<S100>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S101>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S102>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S103>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S104>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S105>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S106>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S107>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Inverse Clarke Transform'
 * '<S108>' : 'MotorControlLibNEWFixedP_FULL19b/Park Transform/Switch_Axis'
 * '<S109>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia'
 * '<S110>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib'
 * '<S111>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator'
 * '<S112>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller'
 * '<S113>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Anti-windup'
 * '<S114>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/D Gain'
 * '<S115>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter'
 * '<S116>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter ICs'
 * '<S117>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/I Gain'
 * '<S118>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain'
 * '<S119>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain Fdbk'
 * '<S120>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator'
 * '<S121>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator ICs'
 * '<S122>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Copy'
 * '<S123>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Gain'
 * '<S124>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/P Copy'
 * '<S125>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Parallel P Gain'
 * '<S126>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Reset Signal'
 * '<S127>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation'
 * '<S128>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation Fdbk'
 * '<S129>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum'
 * '<S130>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum Fdbk'
 * '<S131>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode'
 * '<S132>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode Sum'
 * '<S133>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/postSat Signal'
 * '<S134>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/preSat Signal'
 * '<S135>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S136>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/D Gain/Disabled'
 * '<S137>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter/Disabled'
 * '<S138>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter ICs/Disabled'
 * '<S139>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/I Gain/Internal Parameters'
 * '<S140>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain/Passthrough'
 * '<S141>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S142>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator/Discrete'
 * '<S143>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator ICs/Internal IC'
 * '<S144>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S145>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Gain/Disabled'
 * '<S146>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/P Copy/Disabled'
 * '<S147>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S148>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Reset Signal/Disabled'
 * '<S149>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation/Enabled'
 * '<S150>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation Fdbk/Disabled'
 * '<S151>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum/Sum_PI'
 * '<S152>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum Fdbk/Disabled'
 * '<S153>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode/Disabled'
 * '<S154>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S155>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/postSat Signal/Forward_Path'
 * '<S156>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/preSat Signal/Forward_Path'
 * '<S157>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller'
 * '<S158>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Anti-windup'
 * '<S159>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/D Gain'
 * '<S160>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter'
 * '<S161>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter ICs'
 * '<S162>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/I Gain'
 * '<S163>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain'
 * '<S164>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain Fdbk'
 * '<S165>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator'
 * '<S166>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator ICs'
 * '<S167>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Copy'
 * '<S168>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Gain'
 * '<S169>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/P Copy'
 * '<S170>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Parallel P Gain'
 * '<S171>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Reset Signal'
 * '<S172>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation'
 * '<S173>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation Fdbk'
 * '<S174>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum'
 * '<S175>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum Fdbk'
 * '<S176>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode'
 * '<S177>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode Sum'
 * '<S178>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/postSat Signal'
 * '<S179>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/preSat Signal'
 * '<S180>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S181>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/D Gain/Disabled'
 * '<S182>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter/Disabled'
 * '<S183>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter ICs/Disabled'
 * '<S184>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/I Gain/Internal Parameters'
 * '<S185>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain/Passthrough'
 * '<S186>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S187>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator/Discrete'
 * '<S188>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator ICs/Internal IC'
 * '<S189>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S190>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Gain/Disabled'
 * '<S191>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/P Copy/Disabled'
 * '<S192>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S193>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Reset Signal/Disabled'
 * '<S194>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation/Enabled'
 * '<S195>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation Fdbk/Disabled'
 * '<S196>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum/Sum_PI'
 * '<S197>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum Fdbk/Disabled'
 * '<S198>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode/Disabled'
 * '<S199>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S200>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/postSat Signal/Forward_Path'
 * '<S201>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/preSat Signal/Forward_Path'
 * '<S202>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2'
 * '<S203>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/Compare To Constant'
 * '<S204>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/Compare To Constant1'
 * '<S205>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/If Action Subsystem'
 * '<S206>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/per Uint'
 * '<S207>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped'
 * '<S208>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Simulate start up Theta'
 * '<S209>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S210>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S211>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S212>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S213>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S214>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S215>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S216>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization'
 * '<S217>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1'
 * '<S218>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Prevent division by zero'
 * '<S219>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v1'
 * '<S220>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v2'
 * '<S221>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vd'
 * '<S222>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vq'
 * '<S223>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization/Compare To Constant'
 * '<S224>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1/Compare To Constant'
 */
#endif                      /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
