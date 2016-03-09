/*
 * SelectorSensor.c
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

/* Includes */
/*============================================================================*/
#include "SelectorSensor.h"
#include "Practica2.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void p_init_SelectorSensor(void);
T_UWORD p_get_SelectorSensor_Value(void);


/* Private functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_init_SelectorSensor
 *  Description          : Initializes clock and configures pin 1 - pin 4
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_init_SelectorSensor(void)
{
	//Enable the clock for the desired port 
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	 
	// Configure the pins as GPIO, using the mux macro:
	PORTC_PCR0 = PORT_PCR_MUX(1);    //Pin function alternative '1' is GPIO
	
	//Configure pin 1 as input
	GPIOC_PDDR &= ~PIN1;	
	//Configure pin 2 as input
	GPIOC_PDDR &= ~PIN2;	
	//Configure pin 3 as input
	GPIOC_PDDR &= ~PIN3;	
	//Configure pin 4 as input
	GPIOC_PDDR &= ~PIN4;
}

/**************************************************************
 *  Name                 : p_get_LightSensor_Value
 *  Description          : Returns value from selector
 *  Parameters           : void
 *  Return               : T_UWORD
 *  Critical/explanation : [No]
 **************************************************************/
T_UWORD p_get_SelectorSensor_Value(void)
{
	T_UWORD switch_1 = GPIOC_PDIR & PIN1;
	T_UWORD switch_2 = GPIOC_PDIR & PIN2;
	T_UWORD switch_3 = GPIOC_PDIR & PIN3;
	T_UWORD switch_4 = GPIOC_PDIR & PIN4;
	
	if (switch_1 > switch_2 && switch_1 > switch_3 && switch_1 > switch_4)
	{
		return DEFAULT;
	}
	else if (switch_2 > switch_1 && switch_2 > switch_3 && switch_2 > switch_4)
	{
		return OFF;
	}
	else if (switch_3 > switch_1 && switch_3 > switch_2 && switch_3 > switch_4)
	{
		return PARKLAMPS;
	}
	else if (switch_4 > switch_1 && switch_4 > switch_2 && switch_4 > switch_3)
	{
		return HEADLAMPS;
	}
	else
	{
		return DEFAULT;
	}
}


/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
