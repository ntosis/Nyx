/*
 * File: convertSingleTo12bit.h
 *
 * Code generated for Simulink model 'convertSingleTo12bit'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 30 23:02:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_convertSingleTo12bit_h_
#define RTW_HEADER_convertSingleTo12bit_h_
#ifndef convertSingleTo12bit_COMMON_INCLUDES_
#define convertSingleTo12bit_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* convertSingleTo12bit_COMMON_INCLUDES_ */

#include "convertSingleTo12bit_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: nDLookupTable_bp01Data
   * Referenced by: '<Root>/n-D Lookup Table'
   */
  real32_T nDLookupTable_bp01Data[2];

  /* Computed Parameter: nDLookupTable_tableData
   * Referenced by: '<Root>/n-D Lookup Table'
   */
  uint16_T nDLookupTable_tableData[2];
} ConstP_convertSingleTo12bit_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Outport;                    /* '<Root>/Outport' */
} ExtY_convertSingleTo12bit_T;

/* Real-time Model Data Structure */
struct tag_RTM_convertSingleTo12bit_T {
  const char_T * volatile errorStatus;
};

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_convertSingleTo12bit_T convertSingleTo12bit_Y;

/* Constant parameters (default storage) */
extern const ConstP_convertSingleTo12bit_T convertSingleTo12bit_ConstP;

/* Model entry point functions */
extern void convertSingleTo12bit_initialize(void);
extern void convertSingleTo12bit_step(void);
extern void convertSingleTo12bit_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: Reusable */
extern real32_T in_theta;              /* '<Root>/Inport' */

/* Real-time Model object */
extern RT_MODEL_convertSingleTo12bit_T *const convertSingleTo12bit_M;

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
 * '<Root>' : 'convertSingleTo12bit'
 */
#endif                                 /* RTW_HEADER_convertSingleTo12bit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
