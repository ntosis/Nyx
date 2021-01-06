/*
 * File: MotorControlLibNEWFixedP_FULL19b_private.h
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

#ifndef RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_private_h_
#define RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Includes for objects with custom storage classes. */
//#include "InterfaceBswApp.h"
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

extern const int16_T rtCP_pooled_s8cmtSV5mIIg[502];
extern const int16_T rtCP_pooled_AmmRxwP1dU5l[3];

#define rtCP_sine_table_values_Value   rtCP_pooled_s8cmtSV5mIIg  /* Computed Parameter: rtCP_sine_table_values_Value
                                                                  * Referenced by: '<S9>/sine_table_values'
                                                                  */
#define rtCP_uDLookupTable1_tableData  rtCP_pooled_AmmRxwP1dU5l  /* Computed Parameter: rtCP_uDLookupTable1_tableData
                                                                  * Referenced by: '<S5>/1-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable2_tableData  rtCP_pooled_AmmRxwP1dU5l  /* Computed Parameter: rtCP_uDLookupTable2_tableData
                                                                  * Referenced by: '<S5>/1-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_AmmRxwP1dU5l  /* Computed Parameter: rtCP_uDLookupTable_tableData
                                                                  * Referenced by: '<S5>/1-D Lookup Table'
                                                                  */

/* Imported (extern) block parameters */
extern int16_T VphMax;                 /* Variable: VphMax
                                        * Referenced by: '<Root>/Constant3'
                                        */

#endif              /* RTW_HEADER_MotorControlLibNEWFixedP_FULL19b_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
