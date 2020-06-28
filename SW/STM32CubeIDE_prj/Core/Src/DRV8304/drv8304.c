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

const uint8_t DRV_INx_MASK = 0x0B; /* PB: 00001011 */
const uint8_t DRV_INx_Pos = 0;

const uint8_t DRV_Commutation_Vector[8][4] = \
{
	/* AB AC BC BA CA CB*/
	/* INHC is always LOW (direction)*/
	/* State , INLA , INHB , INLB */
	{    1   ,  1   ,  1   ,   0  } , /* BC */
	{    2   ,  1   ,  0   ,   0  } , /* AC */
	{    3   ,  1   ,  0   ,   1  } , /* AB */
	{    4   ,  0   ,  0   ,   1  } , /* CB */
	{    5   ,  0   ,  1   ,   1  } , /* CA */
	{    6   ,  0   ,  1   ,   0  } , /* BA */
	{    7   ,  0   ,  0   ,   0  } , /* stop  */
	{    8   ,  1   ,  1   ,   1  }   /* align */
};

const uint8_t GPIO_bit_Commutation_Vector[8][2] = \
{
	/* AB AC BC BA CA CB*/
	/* INHC is always LOW (direction)*/
	/* State , INLB , x , INLA , INHB */
	{    1  ,  0b1010  } , /* AB */
	{    2  ,  0b0010  } , /* AC */
	{    3  ,  0b0011  } , /* BC */
	{    4  ,  0b0001  } , /* BA */
	{    5  ,  0b1001  } , /* CA */
	{    6  ,  0b1000  } , /* CB */
	{    7  ,  0b0000  } , /* stop  */
	{    8  ,  0b1011  }   /* align */
};

/* HAL Sensors fake
const uint8_t GPIO_bit_Commutation_Vector[8][2] = \
{
	 AB AC BC BA CA CB
	 INHC is always LOW (direction)
	 State , INLB , x , INLA , INHB
	{    1  ,  0b1010  } ,  AB
	{    2  ,  0b0010  } ,  AC
	{    3  ,  0b0011  } ,  BC
	{    4  ,  0b0001  } ,  BA
	{    5  ,  0b1001  } ,  CA
	{    6  ,  0b1000  } ,  CB
	{    7  ,  0b0000  } ,  stop
	{    8  ,  0b1011  }    align
};
*/

void MX_DRV8304_Init(void){

//	hdrv8304.Instance = _DRV;

	/* set the chip state in sleep mode (after reset is always in sleep mode)*/
	hdrv8304.State = SleepMode;

	/* configure the parameters of drv8304*/
	hdrv8304.Init.DIS_CPUV = DRV_Enable;
	hdrv8304.Init.DIS_GDF = DRV_Enable;
	hdrv8304.Init.OTW_REP = NotReported;
	hdrv8304.Init.PWM_MODE = X1Mode;
	hdrv8304.Init.PWM_COM1 = Asynchronous;
	hdrv8304.Init.IDRIVEP_HS = IP135mA;
	hdrv8304.Init.IDRIVEN_HS = IN120mA;
	hdrv8304.Init.TDRIVE = T1000ns;
	hdrv8304.Init.IDRIVEP_LS = IP135mA;
	hdrv8304.Init.IDRIVEN_LS = IN120mA;
	hdrv8304.Init.TRETRY = T4ms;
	hdrv8304.Init.DEAD_TIME = T100ns;
	hdrv8304.Init.OCP_MODE = AUTRTR;
	hdrv8304.Init.OCP_ACT = AllShutdown;
	hdrv8304.Init.VDS_LVL = V0_15V;
	hdrv8304.Init.VREF_DIV = VREF;
	hdrv8304.Init.LS_REF= SHx_SPx;
	hdrv8304.Init.CSA_GAIN = G40V_V;
	hdrv8304.Init.DIS_SEN = DRV_Disable;
	hdrv8304.Init.SPI_CAL = DRV_Enable;
	// AUTOCAL
	hdrv8304.Init.SEN_LVL = OCP1V; /* don't clear*/

	hdrv8304.ErrorCode = LL_DRV8304_Init(&hdrv8304);
}
DRVErrorStatus LL_DRV8304_Init(DRV8304_HandleTypeDef *hdrv8304){


	uint16_t pRxData[1] = {0};

	uint8_t lengthOfRegisterSruct = (sizeof(hdrv8304->Instance)/sizeof(uint16_t));

	uint8_t *pTxBuffPtr;

	pTxBuffPtr  = (uint8_t *)hdrv8304;

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

	while(lengthOfRegisterSruct>0) {


		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_RESET);

		if(HAL_SPI_TransmitReceive(&hspi1, (uint8_t *)pTxBuffPtr, (uint8_t *)pRxData,1,50)!=HAL_OK)
		{
			HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);
			/* Lock the registers again */
			if((LL_DRV8304_LockUnlock(hdrv8304,LockRegisters)!=DRV_OK))
				{

					return DRV_ERROR;

				}

					return DRV_ERROR;

				}

		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);

		pTxBuffPtr += sizeof(uint16_t);

		lengthOfRegisterSruct --;

	}

	 /*Lock the registers again*/
	if((LL_DRV8304_LockUnlock(hdrv8304,LockRegisters)!=DRV_OK))
	{

			return DRV_ERROR;

	}
	else
	{

			return DRV_OK;

	}

}

DRVErrorStatus LL_DRV8304_LockUnlock(DRV8304_HandleTypeDef *hdrv8304,LockRegisterState Option){

	uint16_t RegValueTmp=0;
	uint16_t pRxData[2];

	if((MX_DRV8304_ReadLockRegister(hdrv8304,&RegValueTmp))==DRV_UndefinedStatus){

		return UnlockFailed;

	}

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

		MERGE_SPI_LOCK_REG(RegValueTmp,(\
				 DRV_Write << DRV_R_W_CMND_Pos\
				|Gate_Drive_HS_Adr << DRV_ADDR_REG_Pos\
				|UnlockRegisters << DRV_LOCK_Pos));

		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_RESET);
		if(HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
		{
			hdrv8304->Lock=DRV_Locked;
			HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);

			return UnlockFailed;

		}
		else
		{

			hdrv8304->Lock=DRV_Unlocked;
			HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);
			return DRV_OK;

		}
	}
	else if((hdrv8304->Lock==DRV_Unlocked)&&(Option==UnlockRegisters))
	{

		return DRV_OK;

	}
	else if((hdrv8304->Lock==DRV_Unlocked)&&(Option==LockRegisters))
	{ /* Lock registers */

		MERGE_SPI_LOCK_REG(RegValueTmp,(\
				 DRV_Write << DRV_R_W_CMND_Pos\
				|Gate_Drive_HS_Adr << DRV_ADDR_REG_Pos\
				|LockRegisters << DRV_LOCK_Pos));

		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_RESET);
		if(HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
		{
			hdrv8304->Lock=DRV_Unlocked;
			HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);

			return LockFailed;

		}
		else
		{

			hdrv8304->Lock=DRV_Locked;
			HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);
			return DRV_OK;

		}

	}

	return DRV_ERROR;
}

static void LL_DRV8304_ActiveMode(DRV8304_HandleTypeDef *hdrv8304){

	hdrv8304->State = ActiveMode;

	HAL_GPIO_WritePin(DRV_ENABLE_GPIO_Port, DRV_ENABLE_Pin, GPIO_PIN_SET);

	/* wait short time to be sure that DRV is active */
	HAL_Delay(5);

}
static void LL_DRV8304_SleepMode(DRV8304_HandleTypeDef *hdrv8304){

	hdrv8304->State = SleepMode;

	HAL_GPIO_WritePin(DRV_ENABLE_GPIO_Port, DRV_ENABLE_Pin, GPIO_PIN_RESET);

}

static uint16_t LL_DRV8304_ReadRegister(DRV8304_HandleTypeDef *hdrv8304,DRV8304_RegAddress RegisterAddr){

	uint16_t RegValueTmp=0;
	uint16_t pRxData[1] = {0};

	/* Read the Fault_Status1 register */
	CREATE_SPI_REG(RegValueTmp,(\
					 DRV_Read << DRV_R_W_CMND_Pos\
					|RegisterAddr << DRV_ADDR_REG_Pos));

	HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_RESET);

	if(HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
	{
		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);

		return 0xFFFFU;

	}
	else
	{
		HAL_GPIO_WritePin(DRV_CS_GPIO_Port, DRV_CS_Pin, GPIO_PIN_SET);

		return pRxData[0];

	}

}
void MX_DRV8304_Request_Status(uint16_t *intermediateVar,DRV8304_HandleTypeDef *hdrv8304){

	volatile uint16_t temp =0;

	temp = LL_DRV8304_ReadRegister(hdrv8304,Fault_Status1_Adr);

	temp= LL_DRV8304_ReadRegister(hdrv8304,VGS_Status2_Adr);

	temp= LL_DRV8304_ReadRegister(hdrv8304,Driver_Control_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,Gate_Drive_HS_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,Gate_Drive_LS_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,OCP_Control_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,CSA_Control_Adr);

}

static DRV8304_LockTypeDef MX_DRV8304_ReadLockRegister(DRV8304_HandleTypeDef *hdrv8304,uint16_t *RegValue){

	*RegValue = LL_DRV8304_ReadRegister(hdrv8304,Gate_Drive_HS_Adr);

	uint8_t ValTmp = (uint8_t)((*RegValue&DRV_LOCK_Msk)>>DRV_LOCK_Pos);

	if(*RegValue==(0xFFFFU))
	{

		hdrv8304->Lock=DRV_UndefinedStatus;

		return DRV_UndefinedStatus;

	}
	else if(ValTmp==UnlockRegisters)
	{

		hdrv8304->Lock=DRV_Unlocked;

		return DRV_Unlocked;

	}
	else if(ValTmp==LockRegisters)
	{

		hdrv8304->Lock=DRV_Locked;

		return DRV_Locked;

	}
	else
	{

		hdrv8304->Lock=DRV_UndefinedStatus;

		return DRV_UndefinedStatus;

	}


}

DRVErrorStatus MX_Change_Commutation_State(){

	uint32_t tempGPIOB = GPIOB->ODR; /* Read the actual ODR Register values. */
	//volatile static uint32_t temp4=0;
	uint8_t *pvector = &GPIO_bit_Commutation_Vector;

	uint8_t CommutationVal;

	if(actual_commutation_state==6) {

		actual_commutation_state=1;

	}
	else if(actual_commutation_state==0)
	{

		return DRV_ERROR;

	}
	else
	{

		actual_commutation_state++;

	}


	CommutationVal = GPIO_bit_Commutation_Vector[actual_commutation_state-1][1];//(uint8_t)*((pvector + actual_commutation_state + 2) - 1);
/*	volatile uint8_t temp1 = (CommutationVal<<DRV_INx_Pos);
	volatile uint8_t temp2 = (CommutationVal<<DRV_INx_Pos) & DRV_INx_MASK;
	volatile uint8_t temp3 = (tempGPIOB & ~DRV_INx_MASK);
	volatile uint8_t temp4 = ((tempGPIOB & ~DRV_INx_MASK) | ((CommutationVal<<DRV_INx_Pos) & DRV_INx_MASK));*/
	//temp4 |= (uint32_t)((tempGPIOB & ~DRV_INx_MASK) | ((CommutationVal<<DRV_INx_Pos) & DRV_INx_MASK));
	/* Update the ODR Register of the GPIOB with the new values of the pins */
    (GPIOB->ODR) = (uint32_t)((tempGPIOB & ~DRV_INx_MASK) | ((CommutationVal<<DRV_INx_Pos) & DRV_INx_MASK));

    return DRV_OK;
}

