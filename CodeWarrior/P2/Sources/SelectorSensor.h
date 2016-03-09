/*
 * SelectorSensor.h
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

#ifndef SELECTORSENSOR_H_
	#define SELECTORSENSOR_H_


/* Includes */
/*============================================================================*/
#include <MKL25Z4.h>


/* Constants and types */
/*============================================================================*/
#define PIN1    (1<<1)
#define PIN2    (1<<2)
#define PIN3    (1<<3)
#define PIN4    (1<<4)

typedef enum
{
    OFF = 0,		//Salidas apagadas
    PARKLAMPS,		//“Parklamps” prendida y “Headlamps” apagada
    HEADLAMPS,		//“Parklamps” y “Headlamps” prendidas
    DEFAULT,		//Opera con la entrada del sensor de luz
}E_SELECTOR;


#endif /* SELECTORSENSOR_H_ */
