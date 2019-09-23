/*
 * principal.c
 *
 *  Created on: 22 de ago de 2019
 *      Author: thelu
 */

#include <sys/alt_stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include <unistd.h>
#include "lcd.h"
#include "movimento.h"
#include "jogo.h"
#include "buzzer.h"

#define NADA_PRESSIONADO 0x1
#define DEBOUNCE 180000

#define BTN_RESET 0
#define BTN_RESUME_PAUSE 37 //<-- VERIFICAR DEPOIS

int btn_atual = -1;

int anaUm = 34;
int anaDois = 175;

int ondeUm = 1;
int ondeDois = 1;

char txt[16];

int pAnt[2] = {-1, -1};

int getBTN();

int main() {
	buzzerPausa();
	alt_printf("Iniciando!\n");
	int buttons = -1;
	initLCD();

	writeLCD("PING PONG\0");
	usleep(1000000);

	clearLCD();
	writeLCD("Pres. RESET");
	while(buttons != BTN_RESET){
		buttons = getBTN();
	}
	clearLCD();
	jogo_iniciar();
	jogo_loop();

	while (1) {
		usleep(9000);
		if(get_charar() == 'k'){
			converteAna(&ondeUm, &ondeDois);
		}
		if(ondeUm == 0 && anaUm >= 34){
			anaUm = anaUm - 4;
		}else if(ondeUm == 2 && anaUm <= 418){
			anaUm = anaUm + 4;
		}

		if(ondeDois == 0 && anaDois >= 34){
			anaDois = anaDois - 4;
		}else if(ondeDois == 2 && anaDois <= 418){
			anaDois = anaDois + 4;
		}

		jogo_setar_pads(anaUm, anaDois);
		int *p = jogo_pegar_pontos();
		if(pAnt[0] != p[0] || pAnt[1] != p[1]){	// Muda os pontos no LCD, apenas se houve uma munda�a.
			lcd_setPontos(p[0], p[1]);
			pAnt[0] = p[0]; pAnt[1] = p[1];
		}
		jogo_loop();

		if (BTN_RESET == getBTN()) { // Se bot�o reset pressionado
			(jogo_isExec() == 1) ? jogo_parar() : jogo_iniciar();
		}
		if (BTN_RESUME_PAUSE == btn_atual) { // Se bot�o reset pressionado
			jogo_resume_pause();
		}

		//buzzerPlay();

		//char str[10];
		//sprintf(str, "%i vs %i\n", anaUm, anaDois);
	//	alt_printf(str);
	}
	return 0;
}

int getBTN(){
	btn_atual = IORD_ALTERA_AVALON_PIO_DATA(PIO_BASE);
	if( btn_atual != NADA_PRESSIONADO ) {
		usleep (DEBOUNCE);
		return btn_atual;
	}
	return -1;
}
