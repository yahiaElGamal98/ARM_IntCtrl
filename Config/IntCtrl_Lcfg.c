/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *         \brief  In this file the user chooses Priority of exceptions, priority grouping of interrupts, disable
                  and enable specific interrupts and exceptions
 *
 *          \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Mcal/Inc/IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/***********************************************************************************************************************
*														EXCEPTIONS & FAULTS PRIOIRITY SETTINGS                                      *
*                                      CHOOSE A VALUE FROM 0 -> 7 in the following                                    *
***********************************************************************************************************************/
#define MEM_PRIORITY        0
#define BUS_PRIORITY        1
#define USAGE_PRIORITY      2
#define SVC_PRIORITY        3
#define DEBUG_PRIORITY      4
#define PENDSV_PRIORITY     5
#define TICK_PRIORITY       6

/***********************************************************************************************************************
*                                      INTERRUPTS PRIORITY GROUPING SETTINGS                                           *
*                             PRIGROUP_CONFIG_1 -> 8 Groups from (0 to 7) & 0 Sub Groups                               *
*                             PRIGROUP_CONFIG_2 -> 4 Groups from (0 to 3) & 2 Sub Groups (0 to 1)                      *
*                             PRIGROUP_CONFIG_3 -> 2 Groups from (0 to 1) & 4 Sub Groups (0 to 3)                      *
*                             PRIGROUP_CONFIG_4 -> 0 Groups               & 8 Sub Groups (0 to 7)                      *
***********************************************************************************************************************/
#define PRIGROUP_CONFIG_1 	0
#define PRIGROUP_CONFIG_2 	1
#define PRIGROUP_CONFIG_3 	0
#define PRIGROUP_CONFIG_4 	0

#if PRIGROUP_CONFIG_1
const uint8 prigroupVal=4;
const IntCtrl_PRIGROUP_type ST_arr_PRIGROUPCfg[INTERRUPT_ARR_SIZE]={
   {INTCTRL_GPIO_PORTA                                      ,((0))},    //(GROUP NUM (0->7))
   {INTCTRL_GPIO_PORTB                                      ,((0))},
   {INTCTRL_GPIO_PORTC                                      ,((0))},
   {INTCTRL_GPIO_PORTD                                      ,((0))},
   {INTCTRL_GPIO_PORTE                                      ,((0))},
   {INTCTRL_UART0                                           ,((0))},
   {INTCTRL_UART1                                           ,((0))},
   {INTCTRL_SSI0                                            ,((0))},
   {INTCTRL_I2C0                                            ,((0))},
   {INTCTRL_PWM0_FAULT                                      ,((0))},
   {INTCTRL_PWM_GEN0                                        ,((0))},
   {INTCTRL_PWM_GEN1                                        ,((0))},
   {INTCTRL_PWM_GEN2                                        ,((0))},
   {INTCTRL_QEI0                                            ,((0))},
   {INTCTRL_ADC_SEQUENCE0                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE1                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE2                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE3                                   ,((0))},
   {INTCTRL_WATCHDOG_T0_T1                                  ,((0))},
   {INTCTRL_TIMER0A                                         ,((0))},
   {INTCTRL_TIMER0B                                         ,((0))},
   {INTCTRL_TIMER1A                                         ,((0))},
   {INTCTRL_TIMER1B                                         ,((0))},
   {INTCTRL_TIMER2A                                         ,((0))},
   {INTCTRL_TIMER2B                                         ,((0))},
   {INTCTRL_ANALOG_COMPARATOR0                              ,((0))},
   {INTCTRL_ANALOG_COMPARATOR1                              ,((0))},
   {INTCTRL_SYSTEM_CONTROL                                  ,((0))},
   {INTCTRL_FLASH_MEM_EEPROM_CTRL                           ,((0))},
   {INTCTRL_GPIO_PORTF                                      ,((0))},
   {INTCTRL_UART2                                           ,((0))},
   {INTCTRL_SSI1                                            ,((0))},
   {INTCTRL_TIMER3A                                         ,((0))},
   {INTCTRL_TIMER3B                                         ,((0))},
   {INTCTRL_I2C1                                            ,((0))},
   {INTCTRL_QEI1                                            ,((0))},
   {INTCTRL_CAN0                                            ,((0))},
   {INTCTRL_CAN1                                            ,((0))},
   {INTCTRL_HIBERNATION_MODULE                              ,((0))},
   {INTCTRL_USB                                             ,((0))},
   {INTCTRL_PWM_GENERATOR3                                  ,((0))},
   {INTCTRL_DMA_SOFTWARE                                    ,((0))},
   {INTCTRL_DMA_ERROR                                       ,((0))},
   {INTCTRL_ADC1_SEQUENCE0                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE1                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE2                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE3                                  ,((0))},
   {INTCTRL_SSI2                                            ,((0))},
   {INTCTRL_SSI3                                            ,((0))},
   {INTCTRL_UART3                                           ,((0))},
   {INTCTRL_UART4                                           ,((0))},
   {INTCTRL_UART5                                           ,((0))},
   {INTCTRL_UART6                                           ,((0))},
   {INTCTRL_UART7                                           ,((0))},
   {INTCTRL_I2C2                                            ,((0))},
   {INTCTRL_I2C3                                            ,((0))},
   {INTCTRL_TIMER4A                                         ,((0))},
   {INTCTRL_TIMER4B                                         ,((0))},
   {INTCTRL_TIMER5A                                         ,((0))},
   {INTCTRL_TIMER5B                                         ,((0))},
   {INTCTRL_TIMER0A_32_64                                   ,((0))},
   {INTCTRL_TIMER0B_32_64                                   ,((0))},
   {INTCTRL_TIMER1A_32_64                                   ,((0))},
   {INTCTRL_TIMER1B_32_64                                   ,((0))},
   {INTCTRL_TIMER2A_32_64                                   ,((0))},
   {INTCTRL_TIMER2B_32_64                                   ,((0))},
   {INTCTRL_TIMER3A_32_64                                   ,((0))},
   {INTCTRL_TIMER3B_32_64                                   ,((0))},
   {INTCTRL_TIMER4A_32_64                                   ,((0))},
   {INTCTRL_TIMER4B_32_64                                   ,((0))},
   {INTCTRL_TIMER5A_32_64                                   ,((0))},
   {INTCTRL_TIMER5B_32_64                                   ,((0))},
   {INTCTRL_SYSTEM_EXCEPTION                                ,((0))},
   {INTCTRL_PWM1_GENERATOR0                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR1                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR2                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR3                                 ,((0))},
   {INTCTRL_PWM1_FAULT                                      ,((0))}
};
#elif PRIGROUP_CONFIG_2
const uint8 prigroupVal=5;
const IntCtrl_PRIGROUP_type ST_arr_PRIGROUPCfg[INTERRUPT_ARR_SIZE]={
   {INTCTRL_GPIO_PORTA													,((0)+(0))},  //(GROUP NUM 0-> 3)+(SUBGROUP NUM 0->1)
   {INTCTRL_GPIO_PORTB                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTC                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTD                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTE                                      ,((0)+(0))},
   {INTCTRL_UART0                                           ,((0)+(0))},
   {INTCTRL_UART1                                           ,((0)+(0))},
   {INTCTRL_SSI0                                            ,((0)+(0))},
   {INTCTRL_I2C0                                            ,((0)+(0))},
   {INTCTRL_PWM0_FAULT                                      ,((0)+(0))},
   {INTCTRL_PWM_GEN0                                        ,((0)+(0))},
   {INTCTRL_PWM_GEN1                                        ,((0)+(0))},
   {INTCTRL_PWM_GEN2                                        ,((0)+(0))},
   {INTCTRL_QEI0                                            ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE0                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE1                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE2                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE3                                   ,((0)+(0))},
   {INTCTRL_WATCHDOG_T0_T1                                  ,((0)+(0))},
   {INTCTRL_TIMER0A                                         ,((0)+(0))},
   {INTCTRL_TIMER0B                                         ,((0)+(0))},
   {INTCTRL_TIMER1A                                         ,((0)+(0))},
   {INTCTRL_TIMER1B                                         ,((0)+(0))},
   {INTCTRL_TIMER2A                                         ,((0)+(0))},
   {INTCTRL_TIMER2B                                         ,((0)+(0))},
   {INTCTRL_ANALOG_COMPARATOR0                              ,((0)+(0))},
   {INTCTRL_ANALOG_COMPARATOR1                              ,((0)+(0))},
   {INTCTRL_SYSTEM_CONTROL                                  ,((0)+(0))},
   {INTCTRL_FLASH_MEM_EEPROM_CTRL                           ,((0)+(0))},
   {INTCTRL_GPIO_PORTF                                      ,((0)+(0))},
   {INTCTRL_UART2                                           ,((0)+(0))},
   {INTCTRL_SSI1                                            ,((0)+(0))},
   {INTCTRL_TIMER3A                                         ,((0)+(0))},
   {INTCTRL_TIMER3B                                         ,((0)+(0))},
   {INTCTRL_I2C1                                            ,((0)+(0))},
   {INTCTRL_QEI1                                            ,((0)+(0))},
   {INTCTRL_CAN0                                            ,((0)+(0))},
   {INTCTRL_CAN1                                            ,((0)+(0))},
   {INTCTRL_HIBERNATION_MODULE                              ,((0)+(0))},
   {INTCTRL_USB                                             ,((0)+(0))},
   {INTCTRL_PWM_GENERATOR3                                  ,((0)+(0))},
   {INTCTRL_DMA_SOFTWARE                                    ,((0)+(0))},
   {INTCTRL_DMA_ERROR                                       ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE0                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE1                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE2                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE3                                  ,((0)+(0))},
   {INTCTRL_SSI2                                            ,((0)+(0))},
   {INTCTRL_SSI3                                            ,((0)+(0))},
   {INTCTRL_UART3                                           ,((0)+(0))},
   {INTCTRL_UART4                                           ,((0)+(0))},
   {INTCTRL_UART5                                           ,((0)+(0))},
   {INTCTRL_UART6                                           ,((0)+(0))},
   {INTCTRL_UART7                                           ,((0)+(0))},
   {INTCTRL_I2C2                                            ,((0)+(0))},
   {INTCTRL_I2C3                                            ,((0)+(0))},
   {INTCTRL_TIMER4A                                         ,((0)+(0))},
   {INTCTRL_TIMER4B                                         ,((0)+(0))},
   {INTCTRL_TIMER5A                                         ,((0)+(0))},
   {INTCTRL_TIMER5B                                         ,((0)+(0))},
   {INTCTRL_TIMER0A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER0B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER1A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER1B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER2A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER2B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER3A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER3B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER4A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER4B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER5A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER5B_32_64                                   ,((0)+(0))},
   {INTCTRL_SYSTEM_EXCEPTION                                ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR0                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR1                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR2                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR3                                 ,((0)+(0))},
   {INTCTRL_PWM1_FAULT                                      ,((0)+(0))}
};
#elif PRIGROUP_CONFIG_3
const uint8 prigroupVal=6;
const IntCtrl_PRIGROUP_type ST_arr_PRIGROUPCfg[INTERRUPT_ARR_SIZE]={
   {INTCTRL_GPIO_PORTA                                      ,((0)+(0))},  //(GROUP NUM 0->1)+(SUBGROUP NUM0->3)
   {INTCTRL_GPIO_PORTB                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTC                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTD                                      ,((0)+(0))},
   {INTCTRL_GPIO_PORTE                                      ,((0)+(0))},
   {INTCTRL_UART0                                           ,((0)+(0))},
   {INTCTRL_UART1                                           ,((0)+(0))},
   {INTCTRL_SSI0                                            ,((0)+(0))},
   {INTCTRL_I2C0                                            ,((0)+(0))},
   {INTCTRL_PWM0_FAULT                                      ,((0)+(0))},
   {INTCTRL_PWM_GEN0                                        ,((0)+(0))},
   {INTCTRL_PWM_GEN1                                        ,((0)+(0))},
   {INTCTRL_PWM_GEN2                                        ,((0)+(0))},
   {INTCTRL_QEI0                                            ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE0                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE1                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE2                                   ,((0)+(0))},
   {INTCTRL_ADC_SEQUENCE3                                   ,((0)+(0))},
   {INTCTRL_WATCHDOG_T0_T1                                  ,((0)+(0))},
   {INTCTRL_TIMER0A                                         ,((0)+(0))},
   {INTCTRL_TIMER0B                                         ,((0)+(0))},
   {INTCTRL_TIMER1A                                         ,((0)+(0))},
   {INTCTRL_TIMER1B                                         ,((0)+(0))},
   {INTCTRL_TIMER2A                                         ,((0)+(0))},
   {INTCTRL_TIMER2B                                         ,((0)+(0))},
   {INTCTRL_ANALOG_COMPARATOR0                              ,((0)+(0))},
   {INTCTRL_ANALOG_COMPARATOR1                              ,((0)+(0))},
   {INTCTRL_SYSTEM_CONTROL                                  ,((0)+(0))},
   {INTCTRL_FLASH_MEM_EEPROM_CTRL                           ,((0)+(0))},
   {INTCTRL_GPIO_PORTF                                      ,((0)+(0))},
   {INTCTRL_UART2                                           ,((0)+(0))},
   {INTCTRL_SSI1                                            ,((0)+(0))},
   {INTCTRL_TIMER3A                                         ,((0)+(0))},
   {INTCTRL_TIMER3B                                         ,((0)+(0))},
   {INTCTRL_I2C1                                            ,((0)+(0))},
   {INTCTRL_QEI1                                            ,((0)+(0))},
   {INTCTRL_CAN0                                            ,((0)+(0))},
   {INTCTRL_CAN1                                            ,((0)+(0))},
   {INTCTRL_HIBERNATION_MODULE                              ,((0)+(0))},
   {INTCTRL_USB                                             ,((0)+(0))},
   {INTCTRL_PWM_GENERATOR3                                  ,((0)+(0))},
   {INTCTRL_DMA_SOFTWARE                                    ,((0)+(0))},
   {INTCTRL_DMA_ERROR                                       ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE0                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE1                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE2                                  ,((0)+(0))},
   {INTCTRL_ADC1_SEQUENCE3                                  ,((0)+(0))},
   {INTCTRL_SSI2                                            ,((0)+(0))},
   {INTCTRL_SSI3                                            ,((0)+(0))},
   {INTCTRL_UART3                                           ,((0)+(0))},
   {INTCTRL_UART4                                           ,((0)+(0))},
   {INTCTRL_UART5                                           ,((0)+(0))},
   {INTCTRL_UART6                                           ,((0)+(0))},
   {INTCTRL_UART7                                           ,((0)+(0))},
   {INTCTRL_I2C2                                            ,((0)+(0))},
   {INTCTRL_I2C3                                            ,((0)+(0))},
   {INTCTRL_TIMER4A                                         ,((0)+(0))},
   {INTCTRL_TIMER4B                                         ,((0)+(0))},
   {INTCTRL_TIMER5A                                         ,((0)+(0))},
   {INTCTRL_TIMER5B                                         ,((0)+(0))},
   {INTCTRL_TIMER0A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER0B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER1A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER1B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER2A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER2B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER3A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER3B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER4A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER4B_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER5A_32_64                                   ,((0)+(0))},
   {INTCTRL_TIMER5B_32_64                                   ,((0)+(0))},
   {INTCTRL_SYSTEM_EXCEPTION                                ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR0                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR1                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR2                                 ,((0)+(0))},
   {INTCTRL_PWM1_GENERATOR3                                 ,((0)+(0))},
   {INTCTRL_PWM1_FAULT                                      ,((0)+(0))}
};
#elif PRIGROUP_CONFIG_4
const uint8 prigroupVal=7;
const IntCtrl_PRIGROUP_type ST_arr_PRIGROUPCfg[INTERRUPT_ARR_SIZE]={
   {INTCTRL_GPIO_PORTA													,((0))}, //(SUBGROUP NUM 0->7)
   {INTCTRL_GPIO_PORTB                                      ,((0))},
   {INTCTRL_GPIO_PORTC                                      ,((0))},
   {INTCTRL_GPIO_PORTD                                      ,((0))},
   {INTCTRL_GPIO_PORTE                                      ,((0))},
   {INTCTRL_UART0                                           ,((0))},
   {INTCTRL_UART1                                           ,((0))},
   {INTCTRL_SSI0                                            ,((0))},
   {INTCTRL_I2C0                                            ,((0))},
   {INTCTRL_PWM0_FAULT                                      ,((0))},
   {INTCTRL_PWM_GEN0                                        ,((0))},
   {INTCTRL_PWM_GEN1                                        ,((0))},
   {INTCTRL_PWM_GEN2                                        ,((0))},
   {INTCTRL_QEI0                                            ,((0))},
   {INTCTRL_ADC_SEQUENCE0                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE1                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE2                                   ,((0))},
   {INTCTRL_ADC_SEQUENCE3                                   ,((0))},
   {INTCTRL_WATCHDOG_T0_T1                                  ,((0))},
   {INTCTRL_TIMER0A                                         ,((0))},
   {INTCTRL_TIMER0B                                         ,((0))},
   {INTCTRL_TIMER1A                                         ,((0))},
   {INTCTRL_TIMER1B                                         ,((0))},
   {INTCTRL_TIMER2A                                         ,((0))},
   {INTCTRL_TIMER2B                                         ,((0))},
   {INTCTRL_ANALOG_COMPARATOR0                              ,((0))},
   {INTCTRL_ANALOG_COMPARATOR1                              ,((0))},
   {INTCTRL_SYSTEM_CONTROL                                  ,((0))},
   {INTCTRL_FLASH_MEM_EEPROM_CTRL                           ,((0))},
   {INTCTRL_GPIO_PORTF                                      ,((0))},
   {INTCTRL_UART2                                           ,((0))},
   {INTCTRL_SSI1                                            ,((0))},
   {INTCTRL_TIMER3A                                         ,((0))},
   {INTCTRL_TIMER3B                                         ,((0))},
   {INTCTRL_I2C1                                            ,((0))},
   {INTCTRL_QEI1                                            ,((0))},
   {INTCTRL_CAN0                                            ,((0))},
   {INTCTRL_CAN1                                            ,((0))},
   {INTCTRL_HIBERNATION_MODULE                              ,((0))},
   {INTCTRL_USB                                             ,((0))},
   {INTCTRL_PWM_GENERATOR3                                  ,((0))},
   {INTCTRL_DMA_SOFTWARE                                    ,((0))},
   {INTCTRL_DMA_ERROR                                       ,((0))},
   {INTCTRL_ADC1_SEQUENCE0                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE1                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE2                                  ,((0))},
   {INTCTRL_ADC1_SEQUENCE3                                  ,((0))},
   {INTCTRL_SSI2                                            ,((0))},
   {INTCTRL_SSI3                                            ,((0))},
   {INTCTRL_UART3                                           ,((0))},
   {INTCTRL_UART4                                           ,((0))},
   {INTCTRL_UART5                                           ,((0))},
   {INTCTRL_UART6                                           ,((0))},
   {INTCTRL_UART7                                           ,((0))},
   {INTCTRL_I2C2                                            ,((0))},
   {INTCTRL_I2C3                                            ,((0))},
   {INTCTRL_TIMER4A                                         ,((0))},
   {INTCTRL_TIMER4B                                         ,((0))},
   {INTCTRL_TIMER5A                                         ,((0))},
   {INTCTRL_TIMER5B                                         ,((0))},
   {INTCTRL_TIMER0A_32_64                                   ,((0))},
   {INTCTRL_TIMER0B_32_64                                   ,((0))},
   {INTCTRL_TIMER1A_32_64                                   ,((0))},
   {INTCTRL_TIMER1B_32_64                                   ,((0))},
   {INTCTRL_TIMER2A_32_64                                   ,((0))},
   {INTCTRL_TIMER2B_32_64                                   ,((0))},
   {INTCTRL_TIMER3A_32_64                                   ,((0))},
   {INTCTRL_TIMER3B_32_64                                   ,((0))},
   {INTCTRL_TIMER4A_32_64                                   ,((0))},
   {INTCTRL_TIMER4B_32_64                                   ,((0))},
   {INTCTRL_TIMER5A_32_64                                   ,((0))},
   {INTCTRL_TIMER5B_32_64                                   ,((0))},
   {INTCTRL_SYSTEM_EXCEPTION                                ,((0))},
   {INTCTRL_PWM1_GENERATOR0                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR1                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR2                                 ,((0))},
   {INTCTRL_PWM1_GENERATOR3                                 ,((0))},
   {INTCTRL_PWM1_FAULT                                      ,((0))}
};
#endif

/***********************************************************************************************************************
*                                      EXCEPTIONS ON_OFF SETTINGS                                                      *
*                                   CHOOSE STD_ON  to    LEAVE EXCEPTION ENABLED                                       *
*                                   CHOOSE STD_OFF to    DISABLE EXCEPTION                                             *
***********************************************************************************************************************/
const IntCtrl_FaultStatus ST_arr_faultCfg[FAULT_ARR_SIZE]={
   {INTCTRL_MEMORY_MANAGEMENT_FAULT_ENABLE                  ,STD_ON},
   {INTCTRL_BUS_FAULT_ENABLE                                ,STD_ON},
   {INTCTRL_USAGE_FAULT_ENABLE                              ,STD_ON}
};
/***********************************************************************************************************************
*                                      INTERRUPTS ON_OFF SETTINGS                                                      *
*                                   CHOOSE STD_ON to ENABLE SPECIFIC INTERRUPT                                         *
*                                   CHOOSE STD_OFF to LEAVE INTERRUPT DISABLED                                         *
***********************************************************************************************************************/
const IntCtrl_InterruptStatus ST_arr_interruptCfg[INTERRUPT_ARR_SIZE]={
   {INTCTRL_GPIO_PORTA                                      ,STD_OFF},
   {INTCTRL_GPIO_PORTB                                      ,STD_OFF},
   {INTCTRL_GPIO_PORTC                                      ,STD_OFF},
   {INTCTRL_GPIO_PORTD                                      ,STD_OFF},
   {INTCTRL_GPIO_PORTE                                      ,STD_OFF},
   {INTCTRL_UART0                                           ,STD_OFF},
   {INTCTRL_UART1                                           ,STD_OFF},
   {INTCTRL_SSI0                                            ,STD_OFF},
   {INTCTRL_I2C0                                            ,STD_OFF},
   {INTCTRL_PWM0_FAULT                                      ,STD_OFF},
   {INTCTRL_PWM_GEN0                                        ,STD_OFF},
   {INTCTRL_PWM_GEN1                                        ,STD_OFF},
   {INTCTRL_PWM_GEN2                                        ,STD_OFF},
   {INTCTRL_QEI0                                            ,STD_OFF},
   {INTCTRL_ADC_SEQUENCE0                                   ,STD_OFF},
   {INTCTRL_ADC_SEQUENCE1                                   ,STD_OFF},
   {INTCTRL_ADC_SEQUENCE2                                   ,STD_OFF},
   {INTCTRL_ADC_SEQUENCE3                                   ,STD_OFF},
   {INTCTRL_WATCHDOG_T0_T1                                  ,STD_OFF},
   {INTCTRL_TIMER0A                                         ,STD_OFF},
   {INTCTRL_TIMER0B                                         ,STD_OFF},
   {INTCTRL_TIMER1A                                         ,STD_OFF},
   {INTCTRL_TIMER1B                                         ,STD_OFF},
   {INTCTRL_TIMER2A                                         ,STD_OFF},
   {INTCTRL_TIMER2B                                         ,STD_OFF},
   {INTCTRL_ANALOG_COMPARATOR0                              ,STD_OFF},
   {INTCTRL_ANALOG_COMPARATOR1                              ,STD_OFF},
   {INTCTRL_SYSTEM_CONTROL                                  ,STD_OFF},
   {INTCTRL_FLASH_MEM_EEPROM_CTRL                           ,STD_OFF},
   {INTCTRL_GPIO_PORTF                                      ,STD_OFF},
   {INTCTRL_UART2                                           ,STD_OFF},
   {INTCTRL_SSI1                                            ,STD_OFF},
   {INTCTRL_TIMER3A                                         ,STD_OFF},
   {INTCTRL_TIMER3B                                         ,STD_OFF},
   {INTCTRL_I2C1                                            ,STD_OFF},
   {INTCTRL_QEI1                                            ,STD_OFF},
   {INTCTRL_CAN0                                            ,STD_OFF},
   {INTCTRL_CAN1                                            ,STD_OFF},
   {INTCTRL_HIBERNATION_MODULE                              ,STD_OFF},
   {INTCTRL_USB                                             ,STD_OFF},
   {INTCTRL_PWM_GENERATOR3                                  ,STD_OFF},
   {INTCTRL_DMA_SOFTWARE                                    ,STD_OFF},
   {INTCTRL_DMA_ERROR                                       ,STD_OFF},
   {INTCTRL_ADC1_SEQUENCE0                                  ,STD_OFF},
   {INTCTRL_ADC1_SEQUENCE1                                  ,STD_OFF},
   {INTCTRL_ADC1_SEQUENCE2                                  ,STD_OFF},
   {INTCTRL_ADC1_SEQUENCE3                                  ,STD_OFF},
   {INTCTRL_SSI2                                            ,STD_OFF},
   {INTCTRL_SSI3                                            ,STD_OFF},
   {INTCTRL_UART3                                           ,STD_OFF},
   {INTCTRL_UART4                                           ,STD_OFF},
   {INTCTRL_UART5                                           ,STD_OFF},
   {INTCTRL_UART6                                           ,STD_OFF},
   {INTCTRL_UART7                                           ,STD_OFF},
   {INTCTRL_I2C2                                            ,STD_OFF},
   {INTCTRL_I2C3                                            ,STD_OFF},
   {INTCTRL_TIMER4A                                         ,STD_OFF},
   {INTCTRL_TIMER4B                                         ,STD_OFF},
   {INTCTRL_TIMER5A                                         ,STD_OFF},
   {INTCTRL_TIMER5B                                         ,STD_OFF},
   {INTCTRL_TIMER0A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER0B_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER1A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER1B_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER2A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER2B_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER3A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER3B_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER4A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER4B_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER5A_32_64                                   ,STD_OFF},
   {INTCTRL_TIMER5B_32_64                                   ,STD_OFF},
   {INTCTRL_SYSTEM_EXCEPTION                                ,STD_OFF},
   {INTCTRL_PWM1_GENERATOR0                                 ,STD_OFF},
   {INTCTRL_PWM1_GENERATOR1                                 ,STD_OFF},
   {INTCTRL_PWM1_GENERATOR2                                 ,STD_OFF},
   {INTCTRL_PWM1_GENERATOR3                                 ,STD_OFF},
   {INTCTRL_PWM1_FAULT                                      ,STD_OFF}
};
/**********************************************************************************************************************
                           LEAVE THE VARIABLES BELOW UNTOUCHED
**********************************************************************************************************************/
#define SAFETY_MASK 0x7
const uint8 mem_pri   =    (MEM_PRIORITY&SAFETY_MASK);
const uint8 bus_pri   =    (BUS_PRIORITY&SAFETY_MASK);
const uint8 usage_pri =    (USAGE_PRIORITY&SAFETY_MASK);
const uint8 svc_pri   =    (SVC_PRIORITY&SAFETY_MASK);
const uint8 debug_pri =    (DEBUG_PRIORITY&SAFETY_MASK);
const uint8 pendsv_pri=    (PENDSV_PRIORITY&SAFETY_MASK);
const uint8 tick_pri  =    (TICK_PRIORITY&SAFETY_MASK);

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
