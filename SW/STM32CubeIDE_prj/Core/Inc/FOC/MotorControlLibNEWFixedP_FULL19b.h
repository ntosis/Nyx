/*
 * File: MotorControlLibNEWFixedP_FULL19b.h
 *
 * Code generated for Simulink model 'MotorControlLibNEWFixedP_FULL19b'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 31 14:34:47 2021
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

/* Block signals for system '<Root>/FluxObsAngle' */
typedef struct {
  int16_T Merge;                       /* '<S17>/Merge' */
} B_FluxObsAngle_MotorControlLi_T;

/* Block states (default storage) for system '<Root>/FluxObsAngle' */
typedef struct {
  int16_T Delay_DSTATE;                /* '<S19>/Delay' */
  int16_T Delay_DSTATE_e;              /* '<S18>/Delay' */
} DW_FluxObsAngle_MotorControlL_T;

/* Zero-crossing (trigger) state for system '<Root>/FluxObsAngle' */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S19>/Delay' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S18>/Delay' */
} ZCE_FluxObsAngle_MotorControl_T;

/* Block signals (default storage) */
typedef struct {
  boolean_T FixPtRelationalOperator;   /* '<S127>/FixPt Relational Operator' */
  B_FluxObsAngle_MotorControlLi_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} B_MotorControlLibNEWFixedP_FU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T UnitDelay1_DSTATE;          /* '<S124>/Unit Delay1' */
  int16_T DiscreteTimeIntegrator_DSTATE;/* '<S120>/Discrete-Time Integrator' */
  int16_T Integrator_DSTATE;           /* '<S102>/Integrator' */
  int16_T Integrator_DSTATE_m;         /* '<S58>/Integrator' */
  boolean_T UnitDelay_DSTATE;          /* '<S119>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S122>/Delay Input1' */
  boolean_T UnitDelay1_DSTATE_m;       /* '<S119>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_p;        /* '<S120>/Unit Delay' */
  int8_T DelayInput1_DSTATE_h;         /* '<S127>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S120>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput;      /* '<S125>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S126>/Memory' */
  MdlrefDW_ADCRawToIab_T ADCRAwToCurrentIabc_InstanceDat;/* '<Root>/ADCRAwToCurrent(Iabc)' */
  DW_FluxObsAngle_MotorControlL_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} DW_MotorControlLibNEWFixedP_F_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_FluxObsAngle_MotorControl_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
} PrevZCX_MotorControlLibNEWFix_T;

/* Invariant block signals for system '<Root>/FluxObsAngle' */
typedef struct {
  const boolean_T Compare;             /* '<S20>/Compare' */
  const boolean_T Compare_l;           /* '<S21>/Compare' */
} ConstB_FluxObsAngle_MotorCont_T;

/* Invariant block signals (default storage) */
typedef struct {
  const int32_T Gain;                  /* '<S120>/Gain' */
  ConstB_FluxObsAngle_MotorCont_T FluxObsAngle_k;/* '<Root>/FluxObsAngle' */
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
extern boolean_T enableFluxobs;        /* '<Root>/Inport2' */
extern boolean_T set_AngleInput;       /* '<Root>/Inport1' */
extern int16_T Sig_theta_el_m;         /* '<Root>/Delay' */
extern int16_T Sig_Ia_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ib_m;               /* '<Root>/ADCRAwToCurrent(Iabc)' */
extern int16_T Sig_Ibeta_m;            /* '<S1>/one_by_sqrt3' */
extern int16_T Sig_dAxis_m;            /* '<Root>/Gain2' */
extern int16_T Sig_dAxis_errorSum_m;   /* '<S5>/Add' */
extern int16_T Sig_qAxis_m;            /* '<Root>/Gain3' */
extern int16_T Sig_qAxis_errorSum_m;   /* '<S5>/Add1' */
extern int16_T Sig_Vqsatu_m;           /* '<S9>/Multiport Switch1' */
extern int16_T Sig_Vdsatu_m;           /* '<S9>/Multiport Switch' */
extern int16_T constantAngle;          /* '<S120>/Discrete-Time Integrator' */
extern int16_T Sig_Va_m;               /* '<Root>/Gain' */
extern int16_T Sig_Vb_m;               /* '<Root>/Gain1' */
extern int16_T FluxObsAngle;           /* '<S16>/PositionGain' */
extern int16_T Sig_dAxis_PI_out;       /* '<S109>/Saturation' */
extern int16_T Sig_qAxis_PI_out;       /* '<S65>/Saturation' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern int16_T Ki_dAxis;               /* Variable: Ki_dAxis
                                        * Referenced by: '<S5>/Constant7'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Ki_qAxis;               /* Variable: Ki_qAxis
                                        * Referenced by: '<S5>/Constant5'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_dAxis;               /* Variable: Kp_dAxis
                                        * Referenced by: '<S5>/Constant6'
                                        * fixdt(1,16,2^-5,0)
                                        */
extern int16_T Kp_qAxis;               /* Variable: Kp_qAxis
                                        * Referenced by: '<S5>/Constant4'
                                        * fixdt(1,16,2^-5,0)
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
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Conversion' : Unused code path elimination
 * Block '<S16>/Data Type Conversion1' : Unused code path elimination
 * Block '<S16>/FluxGain' : Unused code path elimination
 * Block '<S16>/Product' : Unused code path elimination
 * Block '<S16>/Product1' : Unused code path elimination
 * Block '<S16>/Sqrt' : Unused code path elimination
 * Block '<S16>/Square' : Unused code path elimination
 * Block '<S16>/Square1' : Unused code path elimination
 * Block '<S16>/Sum' : Unused code path elimination
 * Block '<S16>/Sum1' : Unused code path elimination
 * Block '<S16>/TorqueGain' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/d-Axis Scope' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Propagation' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Propagation' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S26>/Offset' : Unused code path elimination
 * Block '<S26>/Unary_Minus' : Unused code path elimination
 * Block '<S118>/Offset' : Unused code path elimination
 * Block '<S118>/Unary_Minus' : Unused code path elimination
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
 * '<S3>'   : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle'
 * '<S4>'   : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform'
 * '<S5>'   : 'MotorControlLibNEWFixedP_FULL19b/PI Controller'
 * '<S6>'   : 'MotorControlLibNEWFixedP_FULL19b/PWM Output'
 * '<S7>'   : 'MotorControlLibNEWFixedP_FULL19b/Park Transform'
 * '<S8>'   : 'MotorControlLibNEWFixedP_FULL19b/Start up'
 * '<S9>'   : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter'
 * '<S10>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup'
 * '<S11>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/Interpolation'
 * '<S12>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp'
 * '<S13>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S14>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S15>'  : 'MotorControlLibNEWFixedP_FULL19b/CosSin/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S16>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer'
 * '<S17>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2'
 * '<S18>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha'
 * '<S19>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta'
 * '<S20>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant'
 * '<S21>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/Compare To Constant1'
 * '<S22>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/If Action Subsystem'
 * '<S23>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/atan2/per Uint'
 * '<S24>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiAlpha/Scaling'
 * '<S25>'  : 'MotorControlLibNEWFixedP_FULL19b/FluxObsAngle/Flux Observer/psiBeta/Scaling'
 * '<S26>'  : 'MotorControlLibNEWFixedP_FULL19b/Inverse Park Transform/Switch_Axis'
 * '<S27>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis'
 * '<S28>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1'
 * '<S29>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup'
 * '<S30>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain'
 * '<S31>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter'
 * '<S32>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs'
 * '<S33>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain'
 * '<S34>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain'
 * '<S35>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk'
 * '<S36>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator'
 * '<S37>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs'
 * '<S38>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy'
 * '<S39>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain'
 * '<S40>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy'
 * '<S41>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain'
 * '<S42>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal'
 * '<S43>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation'
 * '<S44>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk'
 * '<S45>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum'
 * '<S46>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk'
 * '<S47>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode'
 * '<S48>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum'
 * '<S49>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal'
 * '<S50>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal'
 * '<S51>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Anti-windup/Disc. Clamping Parallel'
 * '<S52>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/D Gain/Disabled'
 * '<S53>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter/Disabled'
 * '<S54>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Filter ICs/Disabled'
 * '<S55>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/I Gain/External Parameters'
 * '<S56>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain/Passthrough'
 * '<S57>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Ideal P Gain Fdbk/Disabled'
 * '<S58>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator/Discrete'
 * '<S59>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Integrator ICs/Internal IC'
 * '<S60>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Copy/Disabled wSignal Specification'
 * '<S61>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/N Gain/Disabled'
 * '<S62>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/P Copy/Disabled'
 * '<S63>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Parallel P Gain/External Parameters'
 * '<S64>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Reset Signal/Disabled'
 * '<S65>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation/Enabled'
 * '<S66>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Saturation Fdbk/Disabled'
 * '<S67>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum/Sum_PI'
 * '<S68>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Sum Fdbk/Disabled'
 * '<S69>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode/Disabled'
 * '<S70>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/Tracking Mode Sum/Passthrough'
 * '<S71>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/postSat Signal/Forward_Path'
 * '<S72>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis/preSat Signal/Forward_Path'
 * '<S73>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup'
 * '<S74>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain'
 * '<S75>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter'
 * '<S76>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs'
 * '<S77>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain'
 * '<S78>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain'
 * '<S79>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk'
 * '<S80>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator'
 * '<S81>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs'
 * '<S82>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy'
 * '<S83>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain'
 * '<S84>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy'
 * '<S85>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain'
 * '<S86>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal'
 * '<S87>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation'
 * '<S88>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk'
 * '<S89>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum'
 * '<S90>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk'
 * '<S91>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode'
 * '<S92>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum'
 * '<S93>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal'
 * '<S94>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal'
 * '<S95>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Anti-windup/Disc. Clamping Parallel'
 * '<S96>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/D Gain/Disabled'
 * '<S97>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter/Disabled'
 * '<S98>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Filter ICs/Disabled'
 * '<S99>'  : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/I Gain/External Parameters'
 * '<S100>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain/Passthrough'
 * '<S101>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Ideal P Gain Fdbk/Disabled'
 * '<S102>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator/Discrete'
 * '<S103>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Integrator ICs/Internal IC'
 * '<S104>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Copy/Disabled wSignal Specification'
 * '<S105>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/N Gain/Disabled'
 * '<S106>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/P Copy/Disabled'
 * '<S107>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Parallel P Gain/External Parameters'
 * '<S108>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Reset Signal/Disabled'
 * '<S109>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation/Enabled'
 * '<S110>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Saturation Fdbk/Disabled'
 * '<S111>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum/Sum_PI'
 * '<S112>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Sum Fdbk/Disabled'
 * '<S113>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode/Disabled'
 * '<S114>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/Tracking Mode Sum/Passthrough'
 * '<S115>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/postSat Signal/Forward_Path'
 * '<S116>' : 'MotorControlLibNEWFixedP_FULL19b/PI Controller/PID q-Axis1/preSat Signal/Forward_Path'
 * '<S117>' : 'MotorControlLibNEWFixedP_FULL19b/PWM Output/Inverse Clarke Transform'
 * '<S118>' : 'MotorControlLibNEWFixedP_FULL19b/Park Transform/Switch_Axis'
 * '<S119>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped'
 * '<S120>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Simulate start up Theta'
 * '<S121>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Compare To Zero'
 * '<S122>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Detect Decrease'
 * '<S123>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem'
 * '<S124>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem1'
 * '<S125>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop'
 * '<S126>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/S-R Flip-Flop1'
 * '<S127>' : 'MotorControlLibNEWFixedP_FULL19b/Start up/Logic after motor is stoped/Enabled Subsystem/Detect Change'
 * '<S128>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization'
 * '<S129>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1'
 * '<S130>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Prevent division by zero'
 * '<S131>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v1'
 * '<S132>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation v2'
 * '<S133>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vd'
 * '<S134>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Saturation vq'
 * '<S135>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization/Compare To Constant'
 * '<S136>' : 'MotorControlLibNEWFixedP_FULL19b/d-q Voltage Limiter/Axis prioritization1/Compare To Constant'
 */
#endif                      /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
