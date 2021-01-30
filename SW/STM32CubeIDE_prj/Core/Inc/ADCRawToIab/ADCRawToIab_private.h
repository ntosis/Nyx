/*
 * File: ADCRawToIab_private.h
 *
 * Code generated for Simulink model 'ADCRawToIab'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Jan 24 11:53:12 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ADCRawToIab_private_h_
#define RTW_HEADER_ADCRawToIab_private_h_
#include "rtwtypes.h"

/* Includes for objects with custom storage classes. */
#include "InterfaceBswApp.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const int16_T rtCP_pooled_bqgxaasbfOxy[2];
extern const uint16_T rtCP_pooled_kvvxyW9ttTmC[2];

#define rtCP_uDLookupTable3_tableData  rtCP_pooled_bqgxaasbfOxy  /* Computed Parameter: rtCP_uDLookupTable3_tableData
                                                                  * Referenced by: '<Root>/1-D Lookup Table3'
                                                                  */
#define rtCP_uDLookupTable2_tableData  rtCP_pooled_bqgxaasbfOxy  /* Computed Parameter: rtCP_uDLookupTable2_tableData
                                                                  * Referenced by: '<Root>/1-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable3_bp01Data   rtCP_pooled_kvvxyW9ttTmC  /* Computed Parameter: rtCP_uDLookupTable3_bp01Data
                                                                  * Referenced by: '<Root>/1-D Lookup Table3'
                                                                  */
#define rtCP_uDLookupTable2_bp01Data   rtCP_pooled_kvvxyW9ttTmC  /* Computed Parameter: rtCP_uDLookupTable2_bp01Data
                                                                  * Referenced by: '<Root>/1-D Lookup Table2'
                                                                  */
#endif                                 /* RTW_HEADER_ADCRawToIab_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
