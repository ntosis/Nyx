/*
 * File: CalcSpinSpeednDir.h
 *
 * Code generated for Simulink model 'CalcSpinSpeednDir'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Feb  4 14:24:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CalcSpinSpeednDir_h_
#define RTW_HEADER_CalcSpinSpeednDir_h_
#ifndef CalcSpinSpeednDir_COMMON_INCLUDES_
# define CalcSpinSpeednDir_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CalcSpinSpeednDir_COMMON_INCLUDES_ */

#include "CalcSpinSpeednDir_types.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"

/* Block signals for model 'CalcSpinSpeednDir' */
typedef struct {
  real_T setOutput;                    /* '<Root>/Chart1' */
} B_CalcSpinSpeednDir_c_T;

/* Block states (default storage) for model 'CalcSpinSpeednDir' */
typedef struct {
  real32_T TappedDelay1_X[3];          /* '<S2>/Tapped Delay1' */
  real32_T UnitDelay1_DSTATE;          /* '<Root>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<Root>/Unit Delay2' */
  real32_T PrevY;                      /* '<Root>/Rate Limiter' */
  uint8_T is_active_c7_CalcSpinSpeednDir;/* '<Root>/Chart1' */
  uint8_T is_c7_CalcSpinSpeednDir;     /* '<Root>/Chart1' */
  uint8_T is_InvalidSignal;            /* '<Root>/Chart1' */
  uint8_T is_noTimeout;                /* '<Root>/Chart1' */
  uint8_T count;                       /* '<Root>/Chart1' */
} DW_CalcSpinSpeednDir_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_CalcSpinSpeednDir_T {
  const char_T **errorStatus;
};

typedef struct {
  B_CalcSpinSpeednDir_c_T rtb;
  DW_CalcSpinSpeednDir_f_T rtdw;
  RT_MODEL_CalcSpinSpeednDir_T rtm;
} MdlrefDW_CalcSpinSpeednDir_T;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T Sig_rpm;               /* '<Root>/Switch1' */
extern real32_T Sig_Angular_Velocity_radpsec_m;/* '<Root>/Unit Conversion1' */

/* Model reference registration function */
extern void CalcSpinSpeednDir_initialize(const char_T **rt_errorStatus,
  RT_MODEL_CalcSpinSpeednDir_T *const CalcSpinSpeednDir_M);
extern void CalcSpinSpeednDir(const real32_T *rtu_Theta, B_CalcSpinSpeednDir_c_T
  *localB, DW_CalcSpinSpeednDir_f_T *localDW);

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
 * '<Root>' : 'CalcSpinSpeednDir'
 * '<S1>'   : 'CalcSpinSpeednDir/Chart1'
 * '<S2>'   : 'CalcSpinSpeednDir/Detect direction '
 * '<S3>'   : 'CalcSpinSpeednDir/Detect direction /Compare To Constant1'
 * '<S4>'   : 'CalcSpinSpeednDir/Detect direction /Compare To Zero'
 * '<S5>'   : 'CalcSpinSpeednDir/Detect direction /Compare To Zero1'
 * '<S6>'   : 'CalcSpinSpeednDir/Detect direction /Compare To Zero2'
 * '<S7>'   : 'CalcSpinSpeednDir/Detect direction /Compare To Zero5'
 */
#endif                                 /* RTW_HEADER_CalcSpinSpeednDir_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
