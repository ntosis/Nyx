/*
 * File: MotorControlLibNEWFixedP_FULL19b.h
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

/* Exported data define */

/* Definition for custom storage class: Define */
#define ADC_RES                        16384                     /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */
#define DRV_GAIN                       80                        /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */
#define DRV_SHUNTR_OHM                 33                        /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */
#define DRV_V_REF                      106                       /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */

/* Block signals (default storage) */
typedef struct {
  int16_T Merge;                       /* '<S201>/Merge' */
} B_MotorControlLibNEWFixedP_FU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S108>/Discrete-Time Integrator' */
  int16_T DiscreteTimeIntegrator_DSTATE_j;/* '<S109>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE;           /* '<S91>/Integrator' */
  int16_T Integrator_DSTATE_m;         /* '<S47>/Integrator' */
  int16_T Integrator_DSTATE_k;         /* '<S141>/Integrator' */
  int16_T Integrator_DSTATE_j;         /* '<S186>/Integrator' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
} DW_MotorControlLibNEWFixedP_F_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T Compare;             /* '<S202>/Compare' */
  const boolean_T Compare_o;           /* '<S203>/Compare' */
} ConstB_MotorControlLibNEWFixe_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Position;                   /* '<Root>/Position' */
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
extern uint16_T Sig_theta_el_m;        /* '<Root>/Delay' */
extern int16_T Sig_Ia_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ib_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_dAxis_m;            /* '<Root>/Gain2' */
extern int16_T Sig_dAxis_errorSum_m;   /* '<S4>/Add' */
extern int16_T Sig_qAxis_m;            /* '<Root>/Gain3' */
extern int16_T Sig_qAxis_errorSum_m;   /* '<S4>/Add1' */
extern int16_T Sig_Vqsatu_m;           /* '<S8>/Multiport Switch1' */
extern int16_T Sig_Vdsatu_m;           /* '<S8>/Multiport Switch' */
extern int16_T Sig_Va_m;               /* '<Root>/Gain' */
extern int16_T Sig_Vb_m;               /* '<Root>/Gain1' */
extern int16_T Sig_Emfobs_errorSum_m;  /* '<S108>/Add6' */
extern int16_T Sig_dAxis_PI_out;       /* '<S100>/Sum' */
extern int16_T Sig_qAxis_PI_out;       /* '<S56>/Sum' */
extern int16_T Sig_Emfobs_PI_out;      /* '<S150>/Sum' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S4>/Constant7'
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S4>/Constant5'
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S4>/Constant6'
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S4>/Constant4'
                                        */

/* Model entry point functions */
extern void MotorControlLibNEWFixedP_FULL19b_initialize(void);
extern void MotorControlLibNEWFixedP_FULL19b_step(void);
extern void MotorControlLibNEWFixedP_FULL19b_terminate(void);

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const int16_T ComparatorBrkPnt[3];
                             /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */
extern const int16_T VoltageOut[3];
                             /* Referenced by: '<Root>/ADCRAwToCurrent(Iabc)' */

/* Real-time Model object */
extern RT_MODEL_MotorControlLibNEWFi_T *const MotorControlLibNEWFixedP_FUL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Data Type Conversion2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion3' : Unused code path elimination
 * Block '<Root>/Data Type Conversion4' : Unused code path elimination
 * Block '<Root>/Data Type Conversion5' : Unused code path elimination
 * Block '<Root>/Data Type Conversion9' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Scope3' : Unused code path elimination
 * Block '<S7>/Scope5' : Unused code path elimination
 * Block '<Root>/d-Axis Scope' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S209>/Data Type Propagation' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Data Type Propagation' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Data Type Propagation' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Offset' : Unused code path elimination
 * Block '<S15>/Unary_Minus' : Unused code path elimination
 * Block '<S107>/Offset' : Unused code path elimination
 * Block '<S107>/Unary_Minus' : Unused code path elimination
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
 * '<S8>'   : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter'
 * '<S9>'   : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup'
 * '<S10>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S11>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S12>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S13>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S14>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S15>'  : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform/Switch_Axis'
 * '<S16>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis'
 * '<S17>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1'
 * '<S18>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup'
 * '<S19>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain'
 * '<S20>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter'
 * '<S21>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs'
 * '<S22>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain'
 * '<S23>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain'
 * '<S24>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S25>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator'
 * '<S26>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs'
 * '<S27>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy'
 * '<S28>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain'
 * '<S29>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy'
 * '<S30>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain'
 * '<S31>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal'
 * '<S32>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation'
 * '<S33>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk'
 * '<S34>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum'
 * '<S35>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk'
 * '<S36>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode'
 * '<S37>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum'
 * '<S38>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal'
 * '<S39>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal'
 * '<S40>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup/Passthrough'
 * '<S41>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain/Disabled'
 * '<S42>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter/Disabled'
 * '<S43>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S44>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain/External Parameters'
 * '<S45>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S46>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator/Discrete'
 * '<S48>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S49>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain/Disabled'
 * '<S51>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy/Disabled'
 * '<S52>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S53>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal/Disabled'
 * '<S54>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation/Passthrough'
 * '<S55>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S56>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum/Sum_PI'
 * '<S57>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S58>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S59>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S61>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S62>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup'
 * '<S63>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain'
 * '<S64>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter'
 * '<S65>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs'
 * '<S66>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain'
 * '<S67>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain'
 * '<S68>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S69>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator'
 * '<S70>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs'
 * '<S71>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy'
 * '<S72>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain'
 * '<S73>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy'
 * '<S74>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain'
 * '<S75>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal'
 * '<S76>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation'
 * '<S77>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk'
 * '<S78>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum'
 * '<S79>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk'
 * '<S80>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode'
 * '<S81>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S82>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal'
 * '<S83>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal'
 * '<S84>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup/Passthrough'
 * '<S85>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain/Disabled'
 * '<S86>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter/Disabled'
 * '<S87>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S88>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S89>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S90>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator/Discrete'
 * '<S92>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S93>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S94>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain/Disabled'
 * '<S95>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy/Disabled'
 * '<S96>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S97>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal/Disabled'
 * '<S98>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation/Passthrough'
 * '<S99>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S100>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S101>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S102>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S103>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S105>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S106>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Inverse Clarke Transform'
 * '<S107>' : 'MotorControlLibNEWFixedP_FULL19b/Park Transform/Switch_Axis'
 * '<S108>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia'
 * '<S109>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib'
 * '<S110>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator'
 * '<S111>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller'
 * '<S112>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Anti-windup'
 * '<S113>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/D Gain'
 * '<S114>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter'
 * '<S115>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter ICs'
 * '<S116>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/I Gain'
 * '<S117>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain'
 * '<S118>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain Fdbk'
 * '<S119>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator'
 * '<S120>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator ICs'
 * '<S121>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Copy'
 * '<S122>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Gain'
 * '<S123>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/P Copy'
 * '<S124>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Parallel P Gain'
 * '<S125>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Reset Signal'
 * '<S126>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation'
 * '<S127>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation Fdbk'
 * '<S128>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum'
 * '<S129>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum Fdbk'
 * '<S130>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode'
 * '<S131>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode Sum'
 * '<S132>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/postSat Signal'
 * '<S133>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/preSat Signal'
 * '<S134>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Anti-windup/Passthrough'
 * '<S135>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/D Gain/Disabled'
 * '<S136>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter/Disabled'
 * '<S137>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Filter ICs/Disabled'
 * '<S138>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/I Gain/Internal Parameters'
 * '<S139>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain/Passthrough'
 * '<S140>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S141>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator/Discrete'
 * '<S142>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Integrator ICs/Internal IC'
 * '<S143>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S144>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/N Gain/Disabled'
 * '<S145>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/P Copy/Disabled'
 * '<S146>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S147>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Reset Signal/Disabled'
 * '<S148>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation/Passthrough'
 * '<S149>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Saturation Fdbk/Disabled'
 * '<S150>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum/Sum_PI'
 * '<S151>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Sum Fdbk/Disabled'
 * '<S152>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode/Disabled'
 * '<S153>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S154>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/postSat Signal/Forward_Path'
 * '<S155>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ia/PID Controller/preSat Signal/Forward_Path'
 * '<S156>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller'
 * '<S157>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Anti-windup'
 * '<S158>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/D Gain'
 * '<S159>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter'
 * '<S160>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter ICs'
 * '<S161>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/I Gain'
 * '<S162>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain'
 * '<S163>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain Fdbk'
 * '<S164>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator'
 * '<S165>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator ICs'
 * '<S166>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Copy'
 * '<S167>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Gain'
 * '<S168>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/P Copy'
 * '<S169>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Parallel P Gain'
 * '<S170>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Reset Signal'
 * '<S171>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation'
 * '<S172>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation Fdbk'
 * '<S173>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum'
 * '<S174>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum Fdbk'
 * '<S175>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode'
 * '<S176>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode Sum'
 * '<S177>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/postSat Signal'
 * '<S178>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/preSat Signal'
 * '<S179>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Anti-windup/Passthrough'
 * '<S180>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/D Gain/Disabled'
 * '<S181>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter/Disabled'
 * '<S182>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Filter ICs/Disabled'
 * '<S183>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/I Gain/Internal Parameters'
 * '<S184>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain/Passthrough'
 * '<S185>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S186>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator/Discrete'
 * '<S187>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Integrator ICs/Internal IC'
 * '<S188>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S189>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/N Gain/Disabled'
 * '<S190>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/P Copy/Disabled'
 * '<S191>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S192>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Reset Signal/Disabled'
 * '<S193>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation/Passthrough'
 * '<S194>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Saturation Fdbk/Disabled'
 * '<S195>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum/Sum_PI'
 * '<S196>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Sum Fdbk/Disabled'
 * '<S197>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode/Disabled'
 * '<S198>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S199>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/postSat Signal/Forward_Path'
 * '<S200>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/EMF Observer Ib/PID Controller/preSat Signal/Forward_Path'
 * '<S201>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2'
 * '<S202>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/Compare To Constant'
 * '<S203>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/Compare To Constant1'
 * '<S204>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/If Action Subsystem'
 * '<S205>' : 'MotorControlLibNEWFixedP_FULL19b/Position observer/Position Calculator/atan2/per Uint'
 * '<S206>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization'
 * '<S207>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1'
 * '<S208>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Prevent division by zero'
 * '<S209>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v1'
 * '<S210>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v2'
 * '<S211>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vd'
 * '<S212>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vq'
 * '<S213>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization/Compare To Constant'
 * '<S214>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1/Compare To Constant'
 */
#endif                      /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
