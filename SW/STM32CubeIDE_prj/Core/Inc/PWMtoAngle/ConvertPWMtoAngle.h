/*
 * File: ConvertPWMtoAngle.h
 *
 * Code generated for Simulink model 'ConvertPWMtoAngle'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov  2 10:54:19 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ConvertPWMtoAngle_h_
#define RTW_HEADER_ConvertPWMtoAngle_h_
#ifndef ConvertPWMtoAngle_COMMON_INCLUDES_
# define ConvertPWMtoAngle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ConvertPWMtoAngle_COMMON_INCLUDES_ */

#include "ConvertPWMtoAngle_types.h"

/* Includes for objects with custom storage classes. */
#include "PWMtoAngle_const.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_ConvertPWMtoAngle_T {
  const char_T * volatile errorStatus;
};

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T setAngleFormat;       /* '<Root>/Inport' */
extern int16_T Angle_sensor_in;        /* '<Root>/Switch' */

/* Model entry point functions */
extern void ConvertPWMtoAngle_initialize(void);
extern void ConvertPWMtoAngle_step(void);
extern void ConvertPWMtoAngle_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ConvertPWMtoAngle_T *const ConvertPWMtoAngle_M;

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
 * '<Root>' : 'ConvertPWMtoAngle'
 */
#endif                                 /* RTW_HEADER_ConvertPWMtoAngle_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
