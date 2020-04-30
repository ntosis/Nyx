/*
 * drv8304.c
 *
 *  Created on: Apr 27, 2020
 *      Author: unix
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include "drv8304.h"
#include "spi.h"

DRV8304_HandleTypeDef hdrv8304;

void MX_DRV8304_Init(void){

//	hdrv8304.Instance = _DRV;

	/* set the chip state in sleep mode (after reset is always in sleep mode)*/
	hdrv8304.State = SleepMode;

	/* configure the parameters of drv8304*/
	hdrv8304.Init.DIS_CPUV = DRV_Enable;
	hdrv8304.Init.DIS_GDF = DRV_Enable;
	hdrv8304.Init.OTW_REP = DRV_Disable;
	hdrv8304.Init.PWM_MODE = IndependetMode;
	hdrv8304.Init.PWM_COM1 = Sycronous;
	hdrv8304.Init.IDRIVEP_HS = IP15mA;
	hdrv8304.Init.IDRIVEN_HS = IN30mA;
	hdrv8304.Init.TDRIVE = T4000ns;
	hdrv8304.Init.IDRIVEP_LS = IP15mA;
	hdrv8304.Init.IDRIVEN_LS = IN30mA;
	hdrv8304.Init.TRETRY = T4ms;
	hdrv8304.Init.DEAD_TIME = T100ns;
	hdrv8304.Init.OCP_MODE = AUTRTR;
	hdrv8304.Init.OCP_ACT = AllShutdown;
	hdrv8304.Init.VDS_LVL = V0_15V;
	hdrv8304.Init.VREF_DIV = VREF;
	hdrv8304.Init.LS_REF= SHx_SNx; /* Don't use shunt resistor in the first tests*/
	hdrv8304.Init.CSA_GAIN = G10V_V;
	hdrv8304.Init.DIS_SEN = DRV_Disable;
	hdrv8304.Init.SPI_CAL = DRV_Enable;
	// AUTOCAL
	hdrv8304.Init.SEN_LVL = OCP0_25V; /* don't clear*/


	LL_DRV8304_Init(&hdrv8304);
}
DRVErrorStatus LL_DRV8304_Init(DRV8304_HandleTypeDef *hdrv8304){


	uint8_t pRxData[(sizeof(hdrv8304->Instance)/sizeof(uint8_t))];
	uint8_t lengthOfRegisterSruct = (sizeof(hdrv8304->Instance)/sizeof(uint8_t));

	/* Set the DRV8304 in active mode.*/
	LL_DRV8304_ActiveMode(hdrv8304);

	CREATE_SPI_REG(hdrv8304->Instance.DriverControl,(\
			 DRV_Write << DRV_R_W_CMND_Pos\
			|Driver_Control_Adr << DRV_ADDR_REG_Pos\
			|hdrv8304->Init.DIS_CPUV << DRV_DIS_CPUV_Pos\
			|hdrv8304->Init.DIS_GDF << DRV_DIS_GDF_Pos\
			|hdrv8304->Init.OTW_REP << DRV_OTW_REP_Pos\
			|hdrv8304->Init.PWM_MODE << DRV_PWM_MODE_Pos\
			|hdrv8304->Init.PWM_COM1 << DRV_1PWM_COM_Pos\
			));

	CREATE_SPI_REG(hdrv8304->Instance.GateDriveHS,(\
			 DRV_Write << DRV_R_W_CMND_Pos\
			|Gate_Drive_HS_Adr << DRV_ADDR_REG_Pos\
			|hdrv8304->Init.IDRIVEP_HS << DRV_IDRIVEP_HS_Pos\
			|hdrv8304->Init.IDRIVEN_HS << DRV_IDRIVEN_HS_Pos\
			));

	CREATE_SPI_REG(hdrv8304->Instance.GateDriveLS,(\
			 DRV_Write << DRV_R_W_CMND_Pos\
			|Gate_Drive_LS_Adr << DRV_ADDR_REG_Pos\
			|hdrv8304->Init.TDRIVE << DRV_TDRIVE_Pos\
			|hdrv8304->Init.IDRIVEP_LS << DRV_IDRIVEP_LS_Pos\
			|hdrv8304->Init.IDRIVEN_LS << DRV_IDRIVEN_LS_Pos\
			));

	CREATE_SPI_REG(hdrv8304->Instance.OCPControl,(\
			 DRV_Write << DRV_R_W_CMND_Pos\
			|OCP_Control_Adr << DRV_ADDR_REG_Pos\
			|hdrv8304->Init.TRETRY << DRV_TRETRY_Pos\
			|hdrv8304->Init.DEAD_TIME << DRV_DEAD_TIME_Pos\
			|hdrv8304->Init.OCP_MODE << DRV_OCP_MODE_Pos\
			|hdrv8304->Init.OCP_ACT << DRV_OCP_ACT_Pos\
			|hdrv8304->Init.VDS_LVL << DRV_VDS_LVL_Pos\
			));

	CREATE_SPI_REG(hdrv8304->Instance.CSAControl,(\
			 DRV_Write << DRV_R_W_CMND_Pos\
			|CSA_Control_Adr << DRV_ADDR_REG_Pos\
			|hdrv8304->Init.VREF_DIV << DRV_VREF_DIV_Pos\
			|hdrv8304->Init.LS_REF << DRV_LS_REF_Pos\
			|hdrv8304->Init.CSA_GAIN << DRV_CSA_GAIN_Pos\
			|hdrv8304->Init.DIS_SEN << DRV_DIS_SEN_Pos\
			|hdrv8304->Init.SPI_CAL << DRV_SPI_CAL_Pos\
			|hdrv8304->Init.SEN_LVL << DRV_SEN_LVL_Pos\
			));

	/* Unlock the registers before to write the configuration parameters*/
	if((LL_DRV8304_LockUnlock(hdrv8304,UnlockRegisters)!=DRV_OK)){

		return DRV_ERROR;

	}

	if(HAL_SPI_TransmitReceive(&hspi1, &(hdrv8304->Instance), pRxData,lengthOfRegisterSruct,50)!=HAL_OK)
			{
				/* Lock the registers again */
				if((LL_DRV8304_LockUnlock(hdrv8304,LockRegisters)!=DRV_OK))
				{

					return DRV_ERROR;

				}

				return DRV_ERROR;

			}
			else
			{

				/* Lock the registers again */
				if((LL_DRV8304_LockUnlock(hdrv8304,LockRegisters)!=DRV_OK))
				{

				 	return DRV_ERROR;

				}

				return DRV_OK;

			}

}

DRVErrorStatus LL_DRV8304_LockUnlock(DRV8304_HandleTypeDef *hdrv8304,LockRegisterState Option){

	uint16_t RegValueTmp=0;
	uint8_t pTxData[2],pRxData[2];

	/* Check lock/unlock argument*/
	if((Option!=UnlockRegisters)&&(Option!=LockRegisters))
	{
		 return BadArgument;
	}
	/* Lock/Unlock state machine*/
	if((hdrv8304->Lock==DRV_Locked)&&(Option==LockRegisters))
	{

		return DRV_OK;

	}
	else if((hdrv8304->Lock==DRV_Locked)&&(Option==UnlockRegisters))
	{ /* Unlock registers */

		CREATE_SPI_REG(RegValueTmp,(\
				 DRV_Write << DRV_R_W_CMND_Pos\
				|Gate_Drive_HS_Adr << DRV_ADDR_REG_Pos\
				|UnlockRegisters << DRV_LOCK_Pos));

		pTxData[0] = (uint8_t)(RegValueTmp >> 8);

		pTxData[1] = (uint8_t)(RegValueTmp & 0x00FF);

		if(HAL_SPI_TransmitReceive(&hspi1, pTxData, pRxData,2,50)!=HAL_OK)
		{
			hdrv8304->Lock=DRV_Locked;

			return UnlockFailed;

		}
		else
		{

			hdrv8304->Lock=DRV_Unlocked;

			return DRV_OK;

		}
	}
	else if((hdrv8304->Lock==DRV_Unlocked)&&(Option==UnlockRegisters))
	{

		return DRV_OK;

	}
	else if((hdrv8304->Lock==DRV_Unlocked)&&(Option==LockRegisters))
	{ /* Lock registers */

		CREATE_SPI_REG(RegValueTmp,(\
				 DRV_Write << DRV_R_W_CMND_Pos\
				|Gate_Drive_HS_Adr << DRV_ADDR_REG_Pos\
				|LockRegisters << DRV_LOCK_Pos));

		pTxData[0] = (uint8_t)(RegValueTmp >> 8);

		pTxData[1] = (uint8_t)(RegValueTmp & 0x00FF);

		if(HAL_SPI_TransmitReceive(&hspi1, pTxData, pRxData,2,50)!=HAL_OK)
		{
			hdrv8304->Lock=DRV_Unlocked;

			return LockFailed;

		}
		else
		{

			hdrv8304->Lock=DRV_Locked;

			return DRV_OK;

		}

	}

	return DRV_ERROR;
}

static void LL_DRV8304_ActiveMode(DRV8304_HandleTypeDef *hdrv8304){

	hdrv8304->State = ActiveMode;

	HAL_GPIO_WritePin(DRV_ENABLE_GPIO_Port, DRV_ENABLE_Pin, GPIO_PIN_SET);

}
static void LL_DRV8304_SleepMode(DRV8304_HandleTypeDef *hdrv8304){

	hdrv8304->State = SleepMode;

	HAL_GPIO_WritePin(DRV_ENABLE_GPIO_Port, DRV_ENABLE_Pin, GPIO_PIN_RESET);

}
