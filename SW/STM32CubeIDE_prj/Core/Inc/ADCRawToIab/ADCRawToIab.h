/*
 * File: ADCRawToIab.h
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Feb 23 13:40:23 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADCRawToIab_h_
#define RTW_HEADER_ADCRawToIab_h_
#ifndef ADCRawToIab_COMMON_INCLUDES_
# define ADCRawToIab_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ADCRawToIab_COMMON_INCLUDES_ */

#include "ADCRawToIab_types.h"

/* Includes for objects with custom storage classes. */
#include "ConstParams.h"
#include "stdint.h"
/* Real-time Model Data Structure */
struct tag_RTM_ADCRawToIab_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_ADCRawToIab_T rtm;
} MdlrefDW_ADCRawToIab_T;

/* Model reference registration function */
extern void ADCRawToIab_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ADCRawToIab_T *const ADCRawToIab_M);
extern void ADCRawToIab(int16_T *rty_Ia, int16_T *rty_Ib);

extern volatile int16_t MAX_Ia;
extern volatile int16_t MAX_Ib;
extern volatile int16_t MIN_Ia;
extern volatile int16_t MIN_Ib;

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
 * '<Root>' : 'ADCRawToIab'
 */
#endif                                 /* RTW_HEADER_ADCRawToIab_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
