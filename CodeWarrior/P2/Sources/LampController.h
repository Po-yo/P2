/*
 * LampController.h
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

#ifndef LAMPCONTROLLER_H_
	#define LAMPCONTROLLER_H_


/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/

const struct
{
	const T_UWORD LED_RED   = 1<<18;//0x00040000
	const T_UWORD LED_GREEN = 1<<19;//0x00080000
	const T_UWORD LED_BLUE  = 1<<01;//0x00000002
}S_RGB;
typedef enum
{
    LIGHTS_OFF = 0,	//“Parklamps” y “Headlamps” apagadas
    LIGHTS_HALF,	//“Parklamps” prendida y “Headlamps” apagada
    LIGHTS_ON,		//“Parklamps” y “Headlamps” prendidas
}E_LAMP;

const struct
{
	const T_UWORD LIGHTS_OFF  = 0;
	const T_UWORD LIGHTS_HALF = 0|S_RGB.LED_RED|S_RGB.LED_GREEN;
	const T_UWORD LIGHTS_ON   = 0|S_RGB.LED_RED|S_RGB.LED_GREEN|S_RGB.LED_BLUE;
}S_LAMP_GPIOB_PCOR;

const struct
{
	const T_UWORD LIGHTS_OFF  = 0|S_RGB.LED_RED|S_RGB.LED_GREEN|S_RGB.LED_BLUE;
	const T_UWORD LIGHTS_HALF = 0|S_RGB.LED_BLUE;
	const T_UWORD LIGHTS_ON   = 0;
}S_LAMP_GPIOB_PSOR;


#endif /* LAMPCONTROLLER_H_ */
