/*
 * drv8304.c
 *
 *  Created on: Apr 27, 2020
 *      Author: unix
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include "drv8304.h"
#include "spi.h"
#include "adc.h"
#include "tim.h"


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




/* Declare variable using above structure and the function datapoints */
/* These coordinates correspond to the points illustrated in the above graph */
#ifdef UNIDIRECTMODE

//static float comparator_value[] = {0.0, DRV_V_REF/2.0F, DRV_V_REF };
static float voltage[] = {0.3, 0.00, -0.3  };

#else

static float sine_x[] = {0.0, 0.24, 0.64, 1.03, 1.43, M_PI_2};
static float sine_y[] = {0.0, 0.24, 0.6,  0.87, 1.00, 1.00};

#endif

/*static struct table_1d comparator_tables = {
    3,       Number of data points
	comparator_value,  Array of x-coordinates
	voltage   Array of y-coordinates
};*/


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
	hdrv8304.Init.DIS_CPUV = DRV_Disable;
	hdrv8304.Init.DIS_GDF = DRV_Disable;
	hdrv8304.Init.OTW_REP = NotReported;
	hdrv8304.Init.PWM_MODE = X3Mode;
	hdrv8304.Init.PWM_COM1 = Synchronous;
	hdrv8304.Init.IDRIVEP_HS = IP105mA;
	hdrv8304.Init.IDRIVEN_HS = IN120mA;
	hdrv8304.Init.TDRIVE = T2000ns;
	hdrv8304.Init.IDRIVEP_LS = IP105mA;
	hdrv8304.Init.IDRIVEN_LS = IN120mA;
	hdrv8304.Init.TRETRY = T50us;
	hdrv8304.Init.DEAD_TIME = T100ns;
	hdrv8304.Init.OCP_MODE = NOTHING;
	hdrv8304.Init.OCP_ACT = OnlyAssociatedShutdown;
	hdrv8304.Init.VDS_LVL = VDSDisabled;
	hdrv8304.Init.VREF_DIV = VREF;
	hdrv8304.Init.LS_REF= SHx_SPx;
	hdrv8304.Init.CSA_GAIN = G10V_V;
	hdrv8304.Init.DIS_SEN = DRV_Disable;
	hdrv8304.Init.SPI_CAL = DRV_Disable;
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

		if(HAL_SPI_TransmitReceive(&hspi2, (uint8_t *)pTxBuffPtr, (uint8_t *)pRxData,1,50)!=HAL_OK)
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
		if(HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
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
		if(HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
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

	if(HAL_SPI_TransmitReceive(&hspi2, (uint8_t*)&RegValueTmp, (uint8_t *)pRxData,1,50)!=HAL_OK)
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
void MX_DRV8304_Report_Fault(uint16_t *faultReg1,uint16_t *faultReg2,uint16_t *faultReg3,DRV8304_HandleTypeDef *hdrv8304) {



	*faultReg1 = LL_DRV8304_ReadRegister(hdrv8304,Fault_Status1_Adr);

	*faultReg2 = LL_DRV8304_ReadRegister(hdrv8304,VGS_Status2_Adr);

	*faultReg3 = LL_DRV8304_ReadRegister(hdrv8304,Driver_Control_Adr);

	/*temp = LL_DRV8304_ReadRegister(hdrv8304,Gate_Drive_HS_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,Gate_Drive_LS_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,OCP_Control_Adr);

	temp = LL_DRV8304_ReadRegister(hdrv8304,CSA_Control_Adr);*/

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

/**
* Returns the interpolated y-value.
* Saturates to y0 or y1 if x outside interval [x0, x1].
*/
float interpolate_segment(float x0, float y0, float x1, float y1, float x)
{
    float t;

    if (x <= x0) { return y0; }
    if (x >= x1) { return y1; }

    t =  (x-x0);
    t /= (x1-x0);

    return y0 + t*(y1-y0);
}


float interpolate_table_1d(struct table_1d *table, float x)
/* 1D Table lookup with interpolation */
{
    uint8_t segment;

    /* Check input bounds and saturate if out-of-bounds */
    if (x > (table->x_values[table->x_length-1])) {
       /* x-value too large, saturate to max y-value */
        return table->y_values[table->x_length-1];
    }
    else if (x < (table->x_values[0])) {
       /* x-value too small, saturate to min y-value */
        return table->y_values[0];
    }

    /* Find the segment that holds x */
    for (segment = 0; segment<(table->x_length-1); segment++)
    {
        if ((table->x_values[segment]   <= x) &&
            (table->x_values[segment+1] >= x))
        {
            /* Found the correct segment */
            /* Interpolate */
            return interpolate_segment(table->x_values[segment],   /* x0 */
                                       table->y_values[segment],   /* y0 */
                                       table->x_values[segment+1], /* x1 */
                                       table->y_values[segment+1], /* y1 */
                                       x);                         /* x  */
        }
    }

    /* Something with the data was wrong if we get here */
    /* Saturate to the max value */
    return table->y_values[table->x_length-1];
}
void MX_DRV8304_CalculateIabc(DRV8304_HandleTypeDef *hdrv8304){

	/*switch(hdrv8304->Init.CSA_GAIN) {

	case G5V_V: TempGain = 5;
	break;

	case G10V_V: TempGain = 10;
	break;

	case G20V_V: TempGain = 20;
	break;

	case G40V_V: TempGain = 40;
	break;

	default: TempGain = 0;
	break;

	}*/

	/*Convert ADC raw value to volt (12bit resolution)*/
	/* adcBuffer[0]; //SOA Pin */
	//TempRawVoltage = (DRV_V_REF * ((float)adcBuffer[0]) ) / ADC_RES ;



/*	__disable_irq();
	start = ARM_CM_DWT_CYCCNT;
	test_step();
	stop = ARM_CM_DWT_CYCCNT;
	__enable_irq();
	delta = stop - start;*/
}



