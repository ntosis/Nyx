/*
 * File: ConvertPWMtoAngle.c
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

#include "ConvertPWMtoAngle.h"
#include "ConvertPWMtoAngle_private.h"

/* Exported block signals */
boolean_T setAngleFormat=1;              /* '<Root>/Inport' */
int16_T Angle_sensor_in;               /* '<Root>/Switch' */

/* Real-time model */
RT_MODEL_ConvertPWMtoAngle_T ConvertPWMtoAngle_M_;
RT_MODEL_ConvertPWMtoAngle_T *const ConvertPWMtoAngle_M = &ConvertPWMtoAngle_M_;

/* Model step function */
void ConvertPWMtoAngle_step(void)
{
  uint16_T tmp;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Input'
   *  LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
   *  Sum: '<Root>/Add'
   *
   * About '<Root>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   */
  if (setAngleFormat) {
    /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
     *  Inport: '<Root>/Input'
     *
     * About '<Root>/Direct Lookup Table (n-D)':
     *  1-dimensional Direct Look-Up returning a Scalar,
     */
    if (Duty < 4095) {
      tmp = Duty;
    } else {
      tmp = 4095U;
    }

    Angle_sensor_in = (int16_T)(1608 - (Angle_T[tmp] >> 2));
  } else {
    if (Duty < 4095) {
      /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)' incorporates:
       *  Inport: '<Root>/Input'
       *
       * About '<Root>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       */
      tmp = Duty;
    } else {
      /* LookupNDDirect: '<Root>/Direct Lookup Table (n-D)'
       *
       * About '<Root>/Direct Lookup Table (n-D)':
       *  1-dimensional Direct Look-Up returning a Scalar,
       */
      tmp = 4095U;
    }

    Angle_sensor_in = (int16_T)(Angle_T[tmp] >> 2);
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model initialize function */
void ConvertPWMtoAngle_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ConvertPWMtoAngle_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
