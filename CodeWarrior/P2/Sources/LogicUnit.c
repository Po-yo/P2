/*
 * LogicUnit.c
 *  Created on: Mar 5, 2016
 *      Author: Equipo 9
 */

/* Includes */
/*============================================================================*/
#include "LampController.h"
#include "LightSensor.h"
#include "SelectorSensor.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void p_update(void);
void p_initLogicUnit(void);

/* Private functions */
/*============================================================================*/

/**************************************************************
 *  Name                 : p_update
 *  Description          : Gets readings from sensors and sets corresponding value for lamps
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_update(void)
{
	switch (p_get_SelectorSensor_Value())
	{
	case DEFAULT:
		if (p_get_LightSensor_Value() >= 0 && p_get_LightSensor_Value() <= 59)
		{
			p_set_Lamps(LIGHTS_ON);
		}
		else if (p_get_LightSensor_Value() >= 60 && p_get_LightSensor_Value() <= 79)
		{
			p_set_Lamps(LIGHTS_HALF);
		}
		else if (p_get_LightSensor_Value() >= 80 && p_get_LightSensor_Value() <= 100)
		{
			p_set_Lamps(LIGHTS_OFF);
		}
		break;
	case OFF:
		p_set_Lamps(LIGHTS_OFF);
		break;
	case PARKLAMPS:
		p_set_Lamps(LIGHTS_HALF);
		break;
	case HEADLAMPS:
		p_set_Lamps(LIGHTS_ON);
		break;
	}
}

/**************************************************************
 *  Name                 : p_initLogicUnit
 *  Description          : Initializate all componentes
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : [No]
 **************************************************************/
void p_initLogicUnit(void)
{
	p_init_Lamps();
	p_init_LightSensor();
	p_init_SelectorSensor();
}


/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
