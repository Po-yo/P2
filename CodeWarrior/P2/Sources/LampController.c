/*
 * LampController.c
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

/* Includes */
/*============================================================================*/
#include <MKL25Z4.h>

/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
E_LAMP e_lamp_currentState;

/* Exported functions prototypes */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
static void p_init_Lamps(void);
static void p_set_Lamps(E_LAMP state);
static E_LAMP p_get_Lamps();


/* Private functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_init_Lamps
 *  Description          : Initializes ports for Leds simulating lamp states
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
static void p_init_Lamps(void)
{
	/** Initialize the RED LED (PTB18) **/
	PORTB_PCR18 = 0x00000140;/* Set the PTB18 pin multiplexer to GPIO mode */
	GPIOB_PSOR |= S_RGB.LED_RED;/* Set the initial output state to high */
	GPIOB_PDDR |= S_RGB.LED_RED;/* Set the pins direction to output */
	
	/** Initialize the GREEN LED (PTB19) **/
	PORTB_PCR19 = 0x00000140;/* Set the PTB19 pin multiplexer to GPIO mode */
	GPIOB_PSOR |= S_RGB.LED_GREEN;/* Set the initial output state to high */
	GPIOB_PDDR |= S_RGB.LED_GREEN;/* Set the pins direction to output */
	
	/** Initialize the BLUE LED (PTD1) **/
	PORTD_PCR1 = 0x00000140;/* Set the PTD1 pin multiplexer to GPIO mode */
	GPIOD_PSOR = S_RGB.LED_BLUE;/* Set the initial output state to high */
	GPIOD_PDDR |= S_RGB.LED_BLUE;/* Set the pins direction to output */
	
	//GPIOB_PSOR |= (S_RGB.COLOR); OFF
	//GPIOB_PCOR |= (S_RGB.COLOR); ON
	//GPIOB_PTOR |= (S_RGB.COLOR); TOGGLE
	p_set_Lamps(LIGHTS_OFF);
	e_lamp_currentState = LIGHTS_OFF;
}

/**************************************************************
 *  Name                 : p_init_Lamps
 *  Description          : Sets current state of lamps
 *  Parameters           : E_LAMP
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
static void p_set_Lamps(E_LAMP state)
{
	switch (state) {
		case LIGHTS_OFF:
		default:
			GPIOB_PSOR = (S_LAMP_GPIOB_PSOR.LIGHTS_OFF);
			GPIOB_PCOR = (S_LAMP_GPIOB_PCOR.LIGHTS_OFF);
		break;
		case LIGHTS_HALF:
			GPIOB_PSOR = (S_LAMP_GPIOB_PSOR.LIGHTS_HALF);
			GPIOB_PCOR = (S_LAMP_GPIOB_PCOR.LIGHTS_HALF);
		break;
		case LIGHTS_ON:
			GPIOB_PSOR = (S_LAMP_GPIOB_PSOR.LIGHTS_ON);
			GPIOB_PCOR = (S_LAMP_GPIOB_PCOR.LIGHTS_ON);
		break;
	}
	e_lamp_currentState = state;
}

/**************************************************************
 *  Name                 : p_get_Lamps
 *  Description          : Returns current state of lamps
 *  Parameters           : void
 *  Return               : E_LAMP
 *  Critical/explanation : [No]
 **************************************************************/
static E_LAMP p_get_Lamps(void)
{
	return e_lamp_currentState;
}


/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
