/*
 * File: ADCRawToIab.h
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Dec 29 13:39:40 2020
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

/* Exported data define */

/* Definition for custom storage class: Define */
#define ADC_RES                        16384                     /* Referenced by:
                                                                  * '<Root>/Constant'
                                                                  * '<Root>/Constant3'
                                                                  */
#define DRV_GAIN                       80                        /* Referenced by:
                                                                  * '<Root>/Constant1'
                                                                  * '<Root>/Constant4'
                                                                  */
#define DRV_SHUNTR_OHM                 33                        /* Referenced by:
                                                                  * '<Root>/Constant2'
                                                                  * '<Root>/Constant5'
                                                                  */
#define DRV_V_REF                      106                       /* Referenced by:
                                                                  * '<Root>/Gain'
                                                                  * '<Root>/Gain1'
                                                                  */

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

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const int16_T ComparatorBrkPnt[3];/* Referenced by:
                                          * '<Root>/1-D Lookup Table'
                                          * '<Root>/1-D Lookup Table1'
                                          */
extern const int16_T VoltageOut[3];    /* Referenced by:
                                        * '<Root>/1-D Lookup Table'
                                        * '<Root>/1-D Lookup Table1'
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
 * '<Root>' : 'ADCRawToIab'
 */
#endif                                 /* RTW_HEADER_ADCRawToIab_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
