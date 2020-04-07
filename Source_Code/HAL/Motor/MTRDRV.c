#include "MTRDRV.h"
#include "Pwm.h"

void MTRDRV_Init(void)
{
	unsigned char i;
	for(i = 0 ; i < MTR_NUM_OF_MOTORS ; i++)
	{
		MTRDRV_Stop(i);
	}
	
}
void MTRDRV_SetDirection(unsigned char Motor_Index, MotorDirectionType Direction)
{
	switch(Direction)
	{
		case DIR_FWD:
				DIO_Write(MOTOR_ConfigParam[Motor_Index].DioGroupId_DIR, HIGH);
				break;
		case DIR_REV:
				DIO_Write(MOTOR_ConfigParam[Motor_Index].DioGroupId_DIR, LOW);
				break
	}
	
	
}
void MTRDRV_SetSpeed(unsigned char Motor_Index, unsigned long int RotPerMin)
{
	PWM_SetDutyCycle(MOTOR_ConfigParam[Motor_Index].ChannelId_PWM, GET_DUTY_CYCLE_FROM_RPM(RotPerMin),MOTOR_ConfigParam[Motor_Index].Motor_Frequency);
}
void MTRDRV_Stop(unsigned char Motor_Index);
{
	PWM_SetDutyCycle(MOTOR_ConfigParam[Motor_Index].ChannelId_PWM, LOW , MOTOR_ConfigParam[Motor_Index].Motor_Frequency);
}

