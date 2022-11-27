/*
 * drv8304.h
 *
 *  Created on: Apr 27, 2020
 *      Author: unix
 */

#ifndef INC_DRV8304_DRV8304_H_
#define INC_DRV8304_DRV8304_H_


//#define configASSERTDRV( ( x ) )     if( ( x ) == 0 ) { for( ;; ); }
/**
  * @brief  DRV8304 Lock structures definition
  */
typedef enum
{
  DRV_Unlocked = 0x00U,
  DRV_Locked   = 0x01U,
  DRV_UndefinedStatus = 0x02U
} DRV8304_LockTypeDef;

/* DRV_8304 Register address value*/
typedef enum
{
  Fault_Status1_Adr = 0x00U,
  VGS_Status2_Adr   = 0x01U,
  Driver_Control_Adr = 0x02U,
  Gate_Drive_HS_Adr = 0x03U,
  Gate_Drive_LS_Adr = 0x04U,
  OCP_Control_Adr = 0x05U,
  CSA_Control_Adr = 0x06U
} DRV8304_RegAddress;
/*Read/Write command for DRV8304 SPI data*/
typedef enum
{
  DRV_Read = 1,
  DRV_Write = !DRV_Read
} DRV8304_R_W_Command;

typedef enum
{
  DRV_Disable = 1,
  DRV_Enable = !DRV_Disable
} FunctionalStateDRV;
typedef enum
{
  Reported = 1,
  NotReported = !Reported
} ReportedStateDRV;

typedef enum
{
  X6Mode = 0x00U,
  X3Mode = 0x01U,
  X1Mode = 0x02U,
  IndependetMode = 0x03U
} PWMModeState;

typedef enum
{
  Synchronous = 0x00U,
  Asynchronous = 0x01U
} RectificationState;

typedef enum
{
  IP15mA = 0x00U,
  IP15mA_b = 0x01U,
  IP45mA = 0x02U,
  IP60mA = 0x03U,
  IP90mA = 0x04U,
  IP105mA = 0x05U,
  IP135mA = 0x06U,
  IP150mA = 0x07U
} IDrivePState;

typedef enum
{
  IN30mA = 0x00U,
  IN30mA_b = 0x01U,
  IN90mA = 0x02U,
  IN120mA = 0x03U,
  IN180mA = 0x04U,
  IN210mA = 0x05U,
  IN270mA = 0x06U,
  IN300mA = 0x07U
} IDriveNState;

/*Peak gate-current drive time */
typedef enum
{
  T500ns = 0x00U,
  T1000ns = 0x01U,
  T2000ns = 0x02U,
  T4000ns = 0x03U
} TDriveState;

/*Retry time VDS_OCP & SEN_OCP*/
typedef enum
{
  T4ms = 0x00U,
  T50us = 0x01U
} RetryTimeState;

/*Dead time */
typedef enum
{
  T50ns = 0x00U,
  T100ns = 0x01U,
  T200ns = 0x02U,
  T400ns = 0x03U
} DeadTimeState;

/*OCP_Mode */
typedef enum
{
  LF = 0x00U, /*latched fault*/
  AUTRTR = 0x01U, /* automatic retrying fault*/
  ONLRPRT = 0x02U, /*only report the fault but no action taken*/
  NOTHING = 0x03U /* nothing to do*/
} OCPState;

/*OCP_Actuation */
typedef enum
{
  AllShutdown = 0x00U, /* all half-bridges are shutdown in response VDS_OCP*/
  OnlyAssociatedShutdown = 0x01U /* associated half-bride is shutdown in response to VDS_OCP*/
} OCPACTState;

/*VDS level*/
typedef enum
{
  V0_15V = 0x00U,
  V0_24V = 0x01U,
  V0_40V = 0x02U,
  V0_51V = 0x03U,
  V0_60V = 0x04U,
  V0_90V= 0x05U,
  V1_8V = 0x06U,
  VDSDisabled = 0x07U
} VDSLVLState;

/*Sense amplifier reference voltage*/
typedef enum
{
  VREF = 0x00U, /*(unidirectional mode)*/
  VREFHALF = 0x01U
} VrefState;

/*VDS_OCP for the LS Mosfet is measured across SHx to Sxx*/
typedef enum
{
  SHx_SPx = 0x00U,
  SHx_SNx = 0x01U
} VDS_OCPLowSideMeasuredState;

/*Amplifier gain*/
typedef enum
{
  G5V_V = 0x00U,
  G10V_V = 0x01U,
  G20V_V = 0x02U,
  G40V_V = 0x03U
} AmplifierGainState;

/*Sense OCP level*/
typedef enum
{
  OCP0_25V = 0x00U,
  OCP0_5V = 0x01U,
  OCP0_75V = 0x02U,
  OCP1V = 0x03U
} SenseLevelState;

/*Lock drv 8304 registers*/
typedef enum
{
  UnlockRegisters = 0x03U,
  LockRegisters = 0x06U
} LockRegisterState;

/*DRV8304 Error Status*/
typedef enum
{
  DRV_OK = 0x00U,
  LockFailed = 0x01U,
  UnlockFailed = 0x02U,
  BadArgument = 0x03U,
  DRV_ERROR = 0x04U
} DRVErrorStatus;

/* DRV8304 State Type Definition*/
typedef enum
{
  SleepMode = 0x00U,
  ActiveMode = 0X01U
}DRV8304_StateTypeDef;
/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint16_t FaultStatus1;
  __IO uint16_t VGSStatus2;
  __IO uint16_t DriverControl;
  __IO uint16_t GateDriveHS;
  __IO uint16_t GateDriveLS;
  __IO uint16_t OCPControl;
  __IO uint16_t CSAControl;
} DRV8304_TypeDef;
/**
  * @brief  Structure definition of DRV8304 initialization
  */
typedef struct
{

	FunctionalStateDRV DIS_CPUV; /*Charge-pump undervoltage lockout fault is (enabled(d) 0b/disabled 1b) */

	FunctionalStateDRV DIS_GDF; /*Gate drive fault is (enabled(d) 0b/disabled 1b)*/

	ReportedStateDRV OTW_REP; /*OTW is not reported on nFault or the Fault bit (not reported(d) 0b/reported 1b)*/

	PWMModeState PWM_MODE; /*PWM Mode* 6xMode(d)*/

	RectificationState PWM_COM1; /*rectification mode synchronous(d)/asynchronous-diode freewheeling*/

	IDrivePState IDRIVEP_HS;

	IDriveNState IDRIVEN_HS;

	TDriveState TDRIVE; /* Peak gate-current drive time */

	IDrivePState IDRIVEP_LS;

	IDriveNState IDRIVEN_LS;

	RetryTimeState TRETRY; /*Retry time VDS_OCP & SEN_OCP (4ms(d)/50us)*/

	DeadTimeState DEAD_TIME; /*100ns(d)*/

	OCPState OCP_MODE;

	OCPACTState OCP_ACT;

	VDSLVLState VDS_LVL;

	VrefState VREF_DIV; /*reference voltage is Vref divided by 2 (d) / reference voltage is Vref (unidirectional mode)*/

	VDS_OCPLowSideMeasuredState LS_REF;

	AmplifierGainState CSA_GAIN;

	FunctionalStateDRV DIS_SEN;

	FunctionalStateDRV SPI_CAL;

	SenseLevelState SEN_LVL;

}DRV8304_InitTypeDef;
/**
  * @brief  DRV8304 handle Structure definition
  */
typedef struct __DRV8304_HandleTypeDef
{
  DRV8304_TypeDef                   Instance;              /*!< Register base address */

  DRV8304_InitTypeDef               Init;                   /*!< DRV8304 required parameters */

  DRV8304_LockTypeDef               Lock;                   /*!< DRV8304 locking object */

  DRV8304_StateTypeDef              State;                  /*!< ADC communication state (bitmap of ADC states) */

  volatile uint32_t                 ErrorCode;              /*!< ADC Error code */

}DRV8304_HandleTypeDef;

/* Structure definition */
struct table_1d {
    uint8_t x_length;

    float *x_values;
    float *y_values;
};

//#define _DRV (uint16_t)0x00U /*Base Address*/

/********************  Bit definition for Fault Status register 1  ********************/
#define DRV_FAULT_Pos                       (10U)
#define DRV_FAULT_Msk                       (0x1UL << DRV_FAULT_Pos)         /*!< 0x0001 */
#define DRV_FAULT                           DRV_FAULT_Msk                      /*!< Data Register */

#define DRV_VDS_OCP_Pos                     (9U)
#define DRV_VDS_OCP_Msk                     (0x1UL << DRV_VDS_OCP_Pos)         /*!< 0x0001 */
#define DRV_VDS_OCP                         DRV_VDS_OCP_Msk                      /*!< Data Register */

#define DRV_GDF_Pos                         (8U)
#define DRV_GDF_Msk                         (0x1UL << DRV_GDF_Pos)         /*!< 0x0001 */
#define DRV_GDF                             DRV_GDF_Msk                      /*!< Data Register */

#define DRV_UVLO_Pos                         (7U)
#define DRV_UVLO_Msk                         (0x1UL << DRV_UVLO_Pos)         /*!< 0x0001 */
#define DRV_UVLO                             DRV_UVLO_Msk                      /*!< Data Register */

#define DRV_OTSD_Pos                         (6U)
#define DRV_OTSD_Msk                         (0x1UL << DRV_OTSD_Pos)         /*!< 0x0001 */
#define DRV_OTSD                             DRV_OTSD_Msk                      /*!< Data Register */

#define DRV_VDS_HA_Pos                         (5U)
#define DRV_VDS_HA_Msk                         (0x1UL << DRV_VDS_HA_Pos)         /*!< 0x0001 */
#define DRV_VDS_HA                             DRV_VDS_HA_Msk                      /*!< Data Register */

#define DRV_VDS_LA_Pos                         (4U)
#define DRV_VDS_LA_Msk                         (0x1UL << DRV_VDS_LA_Pos)         /*!< 0x0001 */
#define DRV_VDS_LA                             DRV_VDS_LA_Msk                      /*!< Data Register */

#define DRV_VDS_HB_Pos                         (3U)
#define DRV_VDS_HB_Msk                         (0x1UL << DRV_VDS_HB_Pos)         /*!< 0x0001 */
#define DRV_VDS_HB                             DRV_VDS_HB_Msk                      /*!< Data Register */

#define DRV_VDS_LB_Pos                         (2U)
#define DRV_VDS_LB_Msk                         (0x1UL << DRV_VDS_LB_Pos)         /*!< 0x0001 */
#define DRV_VDS_LB                             DRV_VDS_LB_Msk                      /*!< Data Register */

#define DRV_VDS_HC_Pos                         (1U)
#define DRV_VDS_HC_Msk                         (0x1UL << DRV_VDS_HC_Pos)         /*!< 0x0001 */
#define DRV_VDS_HC                             DRV_VDS_HC_Msk                      /*!< Data Register */

#define DRV_VDS_LC_Pos                         (1U)
#define DRV_VDS_LC_Msk                         (0x1UL << DRV_VDS_LC_Pos)         /*!< 0x0001 */
#define DRV_VDS_LC                             DRV_VDS_LC_Msk                      /*!< Data Register */

/********************  Bit definition for VGS Status register 2  ********************/

#define DRV_SA_OC_Pos                         (10U)
#define DRV_SA_OC_Msk                         (0x1UL << DRV_SA_OC_Pos)         /*!< 0x0001 */
#define DRV_SA_OC                             DRV_SA_OC_Msk                      /*!< Data Register */

#define DRV_SB_OC_Pos                         (9U)
#define DRV_SB_OC_Msk                         (0x1UL << DRV_SB_OC_Pos)         /*!< 0x0001 */
#define DRV_SB_OC                             DRV_SB_OC_Msk                      /*!< Data Register */

#define DRV_SC_OC_Pos                         (8U)
#define DRV_SC_OC_Msk                         (0x1UL << DRV_SC_OC_Pos)         /*!< 0x0001 */
#define DRV_SC_OC                             DRV_SC_OC_Msk                      /*!< Data Register */

#define DRV_OTW_Pos                         (7U)
#define DRV_OTW_Msk                         (0x1UL << DRV_OTW_Pos)         /*!< 0x0001 */
#define DRV_OTW                             DRV_OTW_Msk                      /*!< Data Register */

#define DRV_CPUV_Pos                         (6U)
#define DRV_CPUV_Msk                         (0x1UL << DRV_CPUV_Pos)         /*!< 0x0001 */
#define DRV_CPUV                             DRV_CPUV_Msk                      /*!< Data Register */

#define DRV_VGS_HA_Pos                         (5U)
#define DRV_VGS_HA_Msk                         (0x1UL << DRV_VGS_HA_Pos)         /*!< 0x0001 */
#define DRV_VGS_HA                             DRV_VGS_HA_Msk                      /*!< Data Register */

#define DRV_VGS_LA_Pos                         (4U)
#define DRV_VGS_LA_Msk                         (0x1UL << DRV_VGS_LA_Pos)         /*!< 0x0001 */
#define DRV_VGS_LA                             DRV_VGS_LA_Msk                      /*!< Data Register */

#define DRV_VGS_HB_Pos                         (3U)
#define DRV_VGS_HB_Msk                         (0x1UL << DRV_VGS_HB_Pos)         /*!< 0x0001 */
#define DRV_VGS_HB                             DRV_VGS_HB_Msk                      /*!< Data Register */

#define DRV_VGS_LB_Pos                         (2U)
#define DRV_VGS_LB_Msk                         (0x1UL << DRV_VGS_LB_Pos)         /*!< 0x0001 */
#define DRV_VGS_LB                             DRV_VGS_LB_Msk                      /*!< Data Register */

#define DRV_VGS_HC_Pos                         (1U)
#define DRV_VGS_HC_Msk                         (0x1UL << DRV_VGS_HC_Pos)         /*!< 0x0001 */
#define DRV_VGS_HC                             DRV_VGS_HC_Msk                      /*!< Data Register */

#define DRV_VGS_LC_Pos                         (0U)
#define DRV_VGS_LC_Msk                         (0x1UL << DRV_VGS_LC_Pos)         /*!< 0x0001 */
#define DRV_VGS_LC                             DRV_VGS_LC_Msk                      /*!< Data Register */

/********************  Bit definition for driver control register   ********************/

#define DRV_DIS_CPUV_Pos                         (9U)
#define DRV_DIS_CPUV_Msk                         (0x1UL << DRV_DIS_CPUV_Pos)         /*!< 0x0001 */
#define DRV_DIS_CPUV                             DRV_DIS_CPUV_Msk                      /*!< Data Register */

#define DRV_DIS_GDF_Pos                         (8U)
#define DRV_DIS_GDF_Msk                         (0x1UL << DRV_DIS_GDF_Pos)         /*!< 0x0001 */
#define DRV_DIS_GDF                             DRV_DIS_GDF_Msk                      /*!< Data Register */

#define DRV_OTW_REP_Pos                         (7U)
#define DRV_OTW_REP_Msk                         (0x1UL << DRV_OTW_REP_Pos)         /*!< 0x0001 */
#define DRV_OTW_REP                             DRV_OTW_REP_Msk                      /*!< Data Register */

#define DRV_PWM_MODE_Pos                         (5U)
#define DRV_PWM_MODE_Msk                         (0x3UL << DRV_PWM_MODE_Pos)         /*!< 0x0011 */
#define DRV_PWM_MODE                             DRV_PWM_MODE_Msk                      /*!< Data Register */

#define DRV_1PWM_COM_Pos                         (4U)
#define DRV_1PWM_COM_Msk                         (0x1UL << DRV_1PWM_COM_Pos)         /*!< 0x0001 */
#define DRV_1PWM_COM                             DRV_1PWM_COM_Msk                      /*!< Data Register */

#define DRV_1PWM_DIR_Pos                         (3U)
#define DRV_1PWM_DIR_Msk                         (0x1UL << DRV_1PWM_DIR_Pos)         /*!< 0x0001 */
#define DRV_1PWM_DIR                             DRV_1PWM_DIR_Msk                      /*!< Data Register */

#define DRV_COAST_Pos                         (2U)
#define DRV_COAST_Msk                         (0x1UL << DRV_COAST_Pos)         /*!< 0x0001 */
#define DRV_COAST                             DRV_COAST_Msk                      /*!< Data Register */

#define DRV_BRAKE_Pos                         (1U)
#define DRV_BRAKE_Msk                         (0x1UL << DRV_BRAKE_Pos)         /*!< 0x0001 */
#define DRV_BRAKE                             DRV_BRAKE_Msk                      /*!< Data Register */

#define DRV_CLR_FLT_Pos                         (0U)
#define DRV_CLR_FLT_Msk                         (0x1UL << DRV_CLR_FLT_Pos)         /*!< 0x0001 */
#define DRV_CLR_FLT                             DRV_CLR_FLT_Msk                      /*!< Data Register */

/********************  Bit definition for gate drive HS register   ********************/

#define DRV_LOCK_Pos                         (8U)
#define DRV_LOCK_Msk                         (0x07UL << DRV_LOCK_Pos)         /*!< 0x0007 */
#define DRV_LOCK                             DRV_LOCK_Msk                      /*!< Data Register */

#define DRV_IDRIVEP_HS_Pos                         (4U)
#define DRV_IDRIVEP_HS_Msk                         (0x7UL << DRV_IDRIVEP_HS_Pos)         /*!< 0x0001 */
#define DRV_IDRIVEP_HS                             DRV_IDRIVEP_HS_Msk                      /*!< Data Register */

#define DRV_IDRIVEN_HS_Pos                         (0U)
#define DRV_IDRIVEN_HS_Msk                         (0x7UL << DRV_IDRIVEN_HS_Pos)         /*!< 0x0001 */
#define DRV_IDRIVEN_HS                             DRV_IDRIVEN_HS_Msk                      /*!< Data Register */

/********************  Bit definition for gate drive LS register   ********************/

#define DRV_CBC_Pos                         (10U)
#define DRV_CBC_Msk                         (0x1UL << DRV_CBC_Pos)         /*!< 0x0001 */
#define DRV_CBC                             DRV_CBC_Msk                      /*!< Data Register */

#define DRV_TDRIVE_Pos                         (8U)
#define DRV_TDRIVE_Msk                         (0x3UL << DRV_TDRIVE_Pos)         /*!< 0x0001 */
#define DRV_TDRIVE                             DRV_TDRIVE_Msk                      /*!< Data Register */

#define DRV_IDRIVEP_LS_Pos                         (4U)
#define DRV_IDRIVEP_LS_Msk                         (0x7UL << DRV_IDRIVEP_LS_Pos)         /*!< 0x0001 */
#define DRV_IDRIVEP_LS                             DRV_IDRIVEP_LS_Msk                      /*!< Data Register */

#define DRV_IDRIVEN_LS_Pos                         (0U)
#define DRV_IDRIVEN_LS_Msk                         (0x7UL << DRV_IDRIVEN_LS_Pos)         /*!< 0x0001 */
#define DRV_IDRIVEN_LS                             DRV_IDRIVEN_LS_Msk                      /*!< Data Register */

/********************  Bit definition for OCP Control register   ********************/

#define DRV_TRETRY_Pos                         (10U)
#define DRV_TRETRY_Msk                         (0x1UL << DRV_TRETRY_Pos)         /*!< 0x0001 */
#define DRV_TRETRY                             DRV_TRETRY_Msk                      /*!< Data Register */

#define DRV_DEAD_TIME_Pos                         (8U)
#define DRV_DEAD_TIME_Msk                         (0x3UL << DRV_DEAD_TIME_Pos)         /*!< 0x0001 */
#define DRV_DEAD_TIME                             DRV_DEAD_TIME_Msk                      /*!< Data Register */

#define DRV_OCP_MODE_Pos                         (6U)
#define DRV_OCP_MODE_Msk                         (0x3UL << DRV_OCP_MODE_Pos)         /*!< 0x0001 */
#define DRV_OCP_MODE                             DRV_OCP_MODE_Msk                      /*!< Data Register */

#define DRV_OCP_ACT_Pos                         (5U)
#define DRV_OCP_ACT_Msk                         (0x1UL << DRV_OCP_ACT_Pos)         /*!< 0x0001 */
#define DRV_OCP_ACT                             DRV_OCP_ACT_Msk                      /*!< Data Register */

#define DRV_VDS_LVL_Pos                         (0U)
#define DRV_VDS_LVL_Msk                         (0x07UL << DRV_VDS_LVL_Pos)         /*!< 0x0001 */
#define DRV_VDS_LVL                             DRV_VDS_LVL_Msk                      /*!< Data Register */

/********************  Bit definition for CSA Control register   ********************/

#define DRV_VREF_DIV_Pos                         (9U)
#define DRV_VREF_DIV_Msk                         (0x1UL << DRV_VREF_DIV_Pos)         /*!< 0x0001 */
#define DRV_VREF_DIV                             DRV_VREF_DIV_Msk                      /*!< Data Register */

#define DRV_LS_REF_Pos                         (8U)
#define DRV_LS_REF_Msk                         (0x1UL << DRV_LS_REF_Pos)         /*!< 0x0001 */
#define DRV_LS_REF                             DRV_LS_REF_Msk                      /*!< Data Register */

#define DRV_CSA_GAIN_Pos                         (6U)
#define DRV_CSA_GAIN_Msk                         (0x3UL << DRV_CSA_GAIN_Pos)         /*!< 0x0001 */
#define DRV_CSA_GAIN                             DRV_CSA_GAIN_Msk                      /*!< Data Register */

#define DRV_DIS_SEN_Pos                         (5U)
#define DRV_DIS_SEN_Msk                         (0x1UL << DRV_DIS_SEN_Pos)         /*!< 0x0001 */
#define DRV_DIS_SEN                             DRV_DIS_SEN_Msk                      /*!< Data Register */

#define DRV_SPI_CAL_Pos                         (4U)
#define DRV_SPI_CAL_Msk                         (0x1UL << DRV_SPI_CAL_Pos)         /*!< 0x0001 */
#define DRV_SPI_CAL                             DRV_SPI_CAL_Msk                      /*!< Data Register */

#define DRV_AUTOCAL_Pos                         (3U)
#define DRV_AUTOCAL_Msk                         (0x1UL << DRV_AUTOCAL_Pos)         /*!< 0x0001 */
#define DRV_AUTOCAL                             DRV_AUTOCAL_Msk                      /*!< Data Register */

#define DRV_SEN_LVL_Pos                         (0U)
#define DRV_SEN_LVL_Msk                         (0x3UL << DRV_SEN_LVL_Pos)         /*!< 0x0001 */
#define DRV_SEN_LVL                             DRV_SEN_LVL_Msk                      /*!< Data Register */
/*******************************************************************************************************/

#define DRV_ADDR_REG_Pos                         (11U)
#define DRV_R_W_CMND_Pos                         (15U)
//#define DRV_V_REF							     (3.3F)
#define UNIDIRECTMODE							 (1U)
#define SHUNT_RESISTOR							 ((1.0f/1000.0f)) // 1 mOhm


#define CREATE_SPI_REG(VIRTUAL_REG, VAL)   ((VIRTUAL_REG) = (uint16_t)(VAL))
#define MERGE_SPI_LOCK_REG(VIRTUAL_REG, VAL) ((VIRTUAL_REG) = ((uint16_t)(VAL)|(VIRTUAL_REG&(0xffU))))


extern DRV8304_HandleTypeDef hdrv8304;

static uint8_t actual_commutation_state = 1;

const uint8_t DRV_INx_MASK;

const uint8_t DRV_INx_Pos;

const uint8_t DRV_Commutation_Vector[8][4] ;

const uint8_t GPIO_bit_Commutation_Vector[8][2];

extern volatile uint16_t adcBuffer[3];

void MX_DRV8304_Init(void);
DRVErrorStatus LL_DRV8304_Init(DRV8304_HandleTypeDef *hdrv8304);
DRVErrorStatus LL_DRV8304_LockUnlock(DRV8304_HandleTypeDef *hdrv8304,LockRegisterState Option);
static void LL_DRV8304_ActiveMode(DRV8304_HandleTypeDef *hdrv8304);
static void LL_DRV8304_SleepMode(DRV8304_HandleTypeDef *hdrv8304);
static uint16_t LL_DRV8304_ReadRegister(DRV8304_HandleTypeDef *hdrv8304,DRV8304_RegAddress RegisterAddr);
void MX_DRV8304_Report_Fault(uint16_t *faultReg1,uint16_t *faultReg2,uint16_t *faultReg3,DRV8304_HandleTypeDef *hdrv8304);
static DRV8304_LockTypeDef MX_DRV8304_ReadLockRegister(DRV8304_HandleTypeDef *hdrv8304, uint16_t *RegValue);
DRVErrorStatus MX_Change_Commutation_State();
void MX_DRV8304_CalculateIabc(DRV8304_HandleTypeDef *hdrv8304);
float interpolate_segment(float x0, float y0, float x1, float y1, float x);
float interpolate_table_1d(struct table_1d *table, float x);
#endif /* INC_DRV8304_DRV8304_H_ */
