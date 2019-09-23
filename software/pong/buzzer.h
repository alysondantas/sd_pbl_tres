/*
 * buzzer.h
 *
 *  Created on: 16 de set de 2019
 *      Author: thelu
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "altera_avalon_pio_regs.h"


void buzzerPausa(){
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_BUZZER_BASE, 1);
}

void buzzerPlay(){
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_BUZZER_BASE, 0);
	usleep(50000);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_BUZZER_BASE, 1);
}

#endif /* BUZZER_H_ */
