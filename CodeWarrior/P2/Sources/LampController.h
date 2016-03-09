/*
 * LampController.h
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

#ifndef LAMPCONTROLLER_H_
	#define LAMPCONTROLLER_H_


/* Includes */
/*============================================================================*/
#include <MKL25Z4.h>
#include "Practica2.h"


/* Constants and types */
/*============================================================================*/

typedef enum
{
	LED_RED   = 1<<18,//0x00040000
	LED_GREEN = 1<<19,//0x00080000
	LED_BLUE  = 1<<01//0x00000002
}S_RGB;
typedef enum
{
    LIGHTS_OFF = 0,	//“Parklamps” y “Headlamps” apagadas
    LIGHTS_HALF,	//“Parklamps” prendida y “Headlamps” apagada
    LIGHTS_ON		//“Parklamps” y “Headlamps” prendidas
}E_LAMP;

typedef enum
{
	PCOR_VALUE_LIGHTS_OFF  = 0,
	PCOR_VALUE_LIGHTS_HALF = 0|LED_RED|LED_GREEN,
	PCOR_VALUE_LIGHTS_ON   = 0|LED_RED|LED_GREEN|LED_BLUE
}S_LAMP_GPIOB_PCOR;// = {0, 0|1<<18|1<<19, 0|1<<18|1<<19|1<<01};

typedef enum
{
	PSOR_VALUE_LIGHTS_OFF  = 0|LED_RED|LED_GREEN|LED_BLUE,
	PSOR_VALUE_LIGHTS_HALF = 0|LED_BLUE,
	PSOR_VALUE_LIGHTS_ON   = 0
}S_LAMP_GPIOB_PSOR;// = {0|1<<18|1<<19|1<<01, 0|1<<01, 0};


#endif /* LAMPCONTROLLER_H_ */
