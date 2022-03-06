/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct 
{
    uint32 VECTRESET 	:1;
    uint32 VECTCLRACT	:1;
    uint32 SYSRESREQ 	:1;
    uint32   					:5;
    uint32 PRIGROUP	 	:3;
		uint32 					 	:4;
    uint32 ENDIANESS 	:1;
    uint32 VECTKEY   	:16; 
}APINT_BF;
typedef union 
{
    uint32 R;
    APINT_BF B;
}APINT_Tag;

typedef struct 
{
    uint32 		 				:5;
    uint32 INTA				:3;
    uint32					 	:5;
    uint32 INTB				:3;
    uint32 					 	:5;
		uint32 INTC			 	:3;
    uint32 					 	:5;
    uint32 INTD		  	:3; 
}PRI_BF;
typedef union 
{
    uint32 R;
    PRI_BF B;
}PRI_Tag;

typedef struct 
{
    uint32 		 				:5;
    uint32 MEM				:3;
    uint32					 	:5;
    uint32 BUS				:3;
    uint32 					 	:5;
		uint32 USAGE		 	:3;
    uint32 					 	:8; 
}SYSPRI1_BF;
typedef union 
{
    uint32 R;
    SYSPRI1_BF B;
}SYSPRI1_Tag;

typedef struct 
{
    uint32 		 				:29;
    uint32 SVC  			:3;
}SYSPRI2_BF;
typedef union 
{
    uint32 R;
    SYSPRI2_BF B;
}SYSPRI2_Tag;

typedef struct 
{
    uint32 		 				:5;
    uint32 DEBUG			:3;
    uint32					 	:13;
    uint32 PENDSV			:3;
    uint32 					 	:5;
		uint32 TICK			 	:3; 
}SYSPRI3_BF;
typedef union 
{
    uint32 R;
    SYSPRI3_BF B;
}SYSPRI3_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  ((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define EN(OFFSET)														 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100+(4*OFFSET)))
#define SYSHNDCTRL														 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define PRI(OFFSET)														 ((volatile PRI_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x400+(4*OFFSET)))
#define SYSPRI1																 ((volatile SYSPRI1_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2																 ((volatile SYSPRI2_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3																 ((volatile SYSPRI3_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
