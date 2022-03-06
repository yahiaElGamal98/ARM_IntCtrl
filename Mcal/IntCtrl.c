/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Mcal/Inc/IntCtrl_Types.h"
#include "./Inc/IntCtrl.h"
#include "../Common/Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
extern const uint8 prigroupVal;
extern const IntCtrl_InterruptStatus ST_arr_interruptCfg[];
extern const IntCtrl_FaultStatus ST_arr_faultCfg[];
extern const IntCtrl_PRIGROUP_type ST_arr_PRIGROUPCfg[];
extern const uint8 mem_pri;
extern const uint8 bus_pri;
extern const uint8 usage_pri;
extern const uint8 svc_pri; 
extern const uint8 debug_pri;
extern const uint8 pendsv_pri;
extern const uint8 tick_pri;
#define INTERRUPT_ARR_SIZE 78
#define REGISTER_SIZE 32
#define FIELDS_PER_REGISTER 4
#define SPOT_A 0
#define SPOT_B 1
#define SPOT_C 2
#define SPOT_D 3
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	__asm("CPSID i");
	uint8 u8_index;

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    (APINT->B.VECTKEY) = 0xFA05;
    (APINT->B.PRIGROUP)=prigroupVal;
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	
	SYSPRI1->B.MEM=mem_pri;
	SYSPRI1->B.BUS=bus_pri;
	SYSPRI1->B.USAGE=usage_pri;
	SYSPRI2->B.SVC=svc_pri;
	SYSPRI3->B.DEBUG=debug_pri;
	SYSPRI3->B.PENDSV=pendsv_pri;
	SYSPRI3->B.TICK=tick_pri;
	
	for(u8_index=0;u8_index<INTERRUPT_ARR_SIZE;u8_index++)
	{
		if(SPOT_A==(ST_arr_PRIGROUPCfg[u8_index].name%FIELDS_PER_REGISTER))
		{
			PRI((uint8)(ST_arr_PRIGROUPCfg[u8_index].name/FIELDS_PER_REGISTER))->B.INTA=ST_arr_PRIGROUPCfg[u8_index].prigroupVal;
		}
		else if(SPOT_B==(ST_arr_PRIGROUPCfg[u8_index].name%FIELDS_PER_REGISTER))
		{
			PRI((uint8)(ST_arr_PRIGROUPCfg[u8_index].name/FIELDS_PER_REGISTER))->B.INTB=ST_arr_PRIGROUPCfg[u8_index].prigroupVal;
		}
		else if(SPOT_C==(ST_arr_PRIGROUPCfg[u8_index].name%FIELDS_PER_REGISTER))
		{
			PRI((uint8)(ST_arr_PRIGROUPCfg[u8_index].name/FIELDS_PER_REGISTER))->B.INTC=ST_arr_PRIGROUPCfg[u8_index].prigroupVal;
		}
		else if(SPOT_D==(ST_arr_PRIGROUPCfg[u8_index].name%FIELDS_PER_REGISTER))
		{
			PRI((uint8)(ST_arr_PRIGROUPCfg[u8_index].name/FIELDS_PER_REGISTER))->B.INTD=ST_arr_PRIGROUPCfg[u8_index].prigroupVal;
		}
		else
		{
			continue;
		}
	}

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	for(u8_index=0;u8_index<FAULT_ARR_SIZE;u8_index++)
	{
		if(STD_ON==ST_arr_faultCfg[u8_index].status)
		{
			//Turn ON selected Exception
			SYSHNDCTRL|=STD_ON<<ST_arr_faultCfg[u8_index].name;
		}
		else
		{
			//TURN OFF selected Exceptions
			SYSHNDCTRL&=~(STD_ON<<ST_arr_faultCfg[u8_index].name);
		}
	}
	for(u8_index=0;u8_index<INTERRUPT_ARR_SIZE;u8_index++)
	{
		if(STD_ON==ST_arr_interruptCfg[u8_index].status)
		{
			//Enable selected interrupts
			EN((uint8)(ST_arr_interruptCfg[u8_index].name)/REGISTER_SIZE)|=STD_ON<<((ST_arr_interruptCfg[u8_index].name)%REGISTER_SIZE);
		}
		else
		{
			//no need to disable interrupts (disabled by default)
			continue;
		}
	}
	__asm("CPSIE i");
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
