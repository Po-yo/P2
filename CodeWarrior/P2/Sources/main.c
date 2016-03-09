/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "LogicUnit.h"


int main(void)
{
	p_initLogicUnit();
	
	for(;;) {
		p_update();
	}
	
	return 0;
}
