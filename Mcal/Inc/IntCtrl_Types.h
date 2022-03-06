/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	INTCTRL_MEMORY_MANAGEMENT_FAULT_ENABLE=16,
	INTCTRL_BUS_FAULT_ENABLE,
	INTCTRL_USAGE_FAULT_ENABLE
}IntCtrl_FaultType;

typedef struct
{
		IntCtrl_FaultType name;
		uint8 status:1;
}IntCtrl_FaultStatus;


typedef enum
{
	INTCTRL_GPIO_PORTA=0,
	INTCTRL_GPIO_PORTB,
	INTCTRL_GPIO_PORTC,
	INTCTRL_GPIO_PORTD,
	INTCTRL_GPIO_PORTE,
	INTCTRL_UART0,
	INTCTRL_UART1,
	INTCTRL_SSI0,
	INTCTRL_I2C0,
	INTCTRL_PWM0_FAULT,
	INTCTRL_PWM_GEN0,
	INTCTRL_PWM_GEN1,
	INTCTRL_PWM_GEN2,
	INTCTRL_QEI0,
	INTCTRL_ADC_SEQUENCE0,
	INTCTRL_ADC_SEQUENCE1,
	INTCTRL_ADC_SEQUENCE2,
	INTCTRL_ADC_SEQUENCE3,
	INTCTRL_WATCHDOG_T0_T1,
	INTCTRL_TIMER0A,
	INTCTRL_TIMER0B,
	INTCTRL_TIMER1A,
	INTCTRL_TIMER1B,
	INTCTRL_TIMER2A,
	INTCTRL_TIMER2B,
	INTCTRL_ANALOG_COMPARATOR0,
	INTCTRL_ANALOG_COMPARATOR1,
	INTCTRL_SYSTEM_CONTROL=28,
	INTCTRL_FLASH_MEM_EEPROM_CTRL,
	INTCTRL_GPIO_PORTF,
	INTCTRL_UART2=33,
	INTCTRL_SSI1,
	INTCTRL_TIMER3A,
	INTCTRL_TIMER3B,
	INTCTRL_I2C1,
	INTCTRL_QEI1,
	INTCTRL_CAN0,
	INTCTRL_CAN1,
	INTCTRL_HIBERNATION_MODULE=43,
	INTCTRL_USB,
	INTCTRL_PWM_GENERATOR3,
	INTCTRL_DMA_SOFTWARE,
	INTCTRL_DMA_ERROR,
	INTCTRL_ADC1_SEQUENCE0,
	INTCTRL_ADC1_SEQUENCE1,
	INTCTRL_ADC1_SEQUENCE2,
	INTCTRL_ADC1_SEQUENCE3,
	INTCTRL_SSI2=57,
	INTCTRL_SSI3,
	INTCTRL_UART3,
	INTCTRL_UART4,
	INTCTRL_UART5,
	INTCTRL_UART6,
	INTCTRL_UART7,
	INTCTRL_I2C2=68,
	INTCTRL_I2C3,
	INTCTRL_TIMER4A,
	INTCTRL_TIMER4B,
	INTCTRL_TIMER5A=92,
	INTCTRL_TIMER5B,
	INTCTRL_TIMER0A_32_64,
	INTCTRL_TIMER0B_32_64,
	INTCTRL_TIMER1A_32_64,
	INTCTRL_TIMER1B_32_64,
	INTCTRL_TIMER2A_32_64,
	INTCTRL_TIMER2B_32_64,
	INTCTRL_TIMER3A_32_64,
	INTCTRL_TIMER3B_32_64,
	INTCTRL_TIMER4A_32_64,
	INTCTRL_TIMER4B_32_64,
	INTCTRL_TIMER5A_32_64,
	INTCTRL_TIMER5B_32_64,
	INTCTRL_SYSTEM_EXCEPTION,
	INTCTRL_PWM1_GENERATOR0=134,
	INTCTRL_PWM1_GENERATOR1,
	INTCTRL_PWM1_GENERATOR2,
	INTCTRL_PWM1_GENERATOR3,
	INTCTRL_PWM1_FAULT
}IntCtrl_InterruptType;

typedef struct
{
   IntCtrl_InterruptType name;
   uint8 status   :1;
}IntCtrl_InterruptStatus;

typedef struct{
	IntCtrl_InterruptType name;
	uint8 prigroupVal   :3;
}IntCtrl_PRIGROUP_type;


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
