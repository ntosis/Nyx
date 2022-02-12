/*
 * File: SafetyChecks.h
 *
 * Code generated for Simulink model 'SafetyChecks'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Jan 27 21:25:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SafetyChecks_h_
#define RTW_HEADER_SafetyChecks_h_
#ifndef SafetyChecks_COMMON_INCLUDES_
# define SafetyChecks_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SafetyChecks_COMMON_INCLUDES_ */

#include "SafetyChecks_types.h"

/* Block states (default storage) for model 'SafetyChecks' */
typedef struct {
  uint16_T UnitDelay1_DSTATE;          /* '<S4>/Unit Delay1' */
} DW_SafetyChecks_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_SafetyChecks_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_SafetyChecks_f_T rtdw;
  RT_MODEL_SafetyChecks_T rtm;
} MdlrefDW_SafetyChecks_T;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern uint16_T MaximumCurrentBeforeReaction;/* Variable: MaximumCurrentBeforeReaction
                                              * Referenced by:
                                              *   '<S1>/Constant'
                                              *   '<S2>/Constant'
                                              *   '<S3>/Constant'
                                              * Maximum current limit before softare shutdowns the mosfets.
                                              */

/* Model reference registration function */
extern void SafetyChecks_initialize(const char_T **rt_errorStatus,
  RT_MODEL_SafetyChecks_T *const SafetyChecks_M);
extern void SafetyChecks(const int16_T rtu_Iab[2], DW_SafetyChecks_f_T *localDW);

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
 * '<Root>' : 'SafetyChecks'
 * '<S1>'   : 'SafetyChecks/Compare To Constant'
 * '<S2>'   : 'SafetyChecks/Compare To Constant1'
 * '<S3>'   : 'SafetyChecks/Compare To Constant2'
 * '<S4>'   : 'SafetyChecks/delay error reaction'
 */
#endif                                 /* RTW_HEADER_SafetyChecks_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
