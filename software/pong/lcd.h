#ifndef __LCD_H_
#define __LCD_H_

#include <stdlib.h>
#include <string.h>
#include "altera_avalon_pio_regs.h"
#include <unistd.h>

#define DELAY 1000

char str[13];


void writeLCD(char str[]){
	int c = (0x3 << 9) ;
	int i = 0;
	while(str[i] != '\0'){
		c  |= str[i];
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, c);
		usleep(DELAY);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, str[i]);
		i++;
		c = (0x3 << 9) ;
	}
}

void clearLCD(){
	usleep(DELAY);
	int send = 1025;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 1;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
}


void initLCD(){
	int send = 1072;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 48;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 1036;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 12;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 1025;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 1;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	send = 1030;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
	usleep(DELAY);
	send = 6;
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, send);
}

void lcd_setPontos(int p0, int p1){
	clearLCD();
	sprintf(str, "PLC: %d X %d\0", p0, p1);
	writeLCD(str);
}

#endif
