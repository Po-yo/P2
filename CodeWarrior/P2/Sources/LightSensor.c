/*
 * LightSensor.c
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

/* Includes */
/*============================================================================*/
#include "LightSensor.h"
#include "Practica2.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void p_init_LightSensor(void);
T_UWORD p_get_LightSensor_Value(void);


/* Private functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_init_LightSensor
 *  Description          : Initializes clock and configures pin 0
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_init_LightSensor(void)
{
	//Enable the clock for the desired port 
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
	 
	// Configure the pins as GPIO, using the mux macro:
	PORTC_PCR0 = PORT_PCR_MUX(1);    //Pin function alternative '1' is GPIO
	
	//Configure pin 0 as input
	GPIOC_PDDR &= ~PIN0;
}

/**************************************************************
 *  Name                 : p_get_LightSensor_Value
 *  Description          : Returns value from light sensor
 *  Parameters           : void
 *  Return               : T_UWORD
 *  Critical/explanation : [No]
 **************************************************************/
T_UWORD p_get_LightSensor_Value(void)
{
	//Return reading from pin 0
	return GPIOC_PDIR & PIN0;
}


/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
