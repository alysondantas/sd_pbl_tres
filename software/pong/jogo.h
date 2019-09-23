#ifndef __JOGO_H_
#define __JOGO_H_

#include "system.h"
#include <stdlib.h>
#include <time.h>
#include "buzzer.h"

#define LIMITE_SUPERIOR 34
#define LIMITE_INFERIOR 514
#define LIMITE_ESQUERDO 143
#define LIMITE_DIREITO  783
#define VELOCIDADE 5
#define MAX_PTN 10

typedef struct bola {
	int x, y;
	int l, a;
	int dx, dy;
} bola_t;

typedef struct pad {
	int x, y;
	int l, a;
} pad_t;

//srand(time(NULL));

int contador = 0;

bola_t bola;
pad_t pads[2];
int pontos[2] = {0, 0};
int exec = 0;

int verifica_colisao();
int valor_aleat();
void move_bola();
void jogo_set_inicio();
void jogo_iniciar();
void jogo_setar_pads(int, int);
void set_position(int, int, int, int);
int* jogo_pegar_pontos();
void jogo_loop();

int verifica_colisao(bola_t a, pad_t b){
	int esq_a, esq_b;
	int dir_a, dir_b;
	int topo_a, topo_b;
	int base_a, base_b;

	esq_a = a.x;
	dir_a = a.x + a.l;
	topo_a = a.y + a.l/2;
	base_a = a.y + a.a;

	esq_b = b.x;
	dir_b = b.x + b.l;
	topo_b = b.y;
	base_b = b.y + b.a;


	if (dir_a > esq_b && dir_a < dir_b && topo_a > topo_b && topo_a < base_b) {
		return 1;
	}

	if (esq_a < dir_b && esq_a > esq_b && topo_a > topo_b && topo_a < base_b) {
		return 1;
	}

	return 0;
}

int valor_aleat(){
	int v;
	v = contador;
	v = (v == 2) ? -1 : v;
	return v;
}

void move_bola(){
	bola.x += bola.dx;					// Incrementa a posição da bola
	bola.y += bola.dy;


	if(bola.y < LIMITE_SUPERIOR || (bola.y + bola.a) > LIMITE_INFERIOR){ // Testa se atingiu as paredes superiores e inferiores
		bola.dy = -bola.dy;		//Inveter o sentido da bola
		buzzerPlay();
	}

	int i;

	for(i=0; i < 2; i++){
		int c = verifica_colisao(bola, pads[i]); // Testa colisao
		if(c == 1){
			bola.dx = -bola.dx; // Muda a direção
			if((bola.dx < 0 ? -bola.dx: bola.dx) != VELOCIDADE)
				bola.dx += bola.dx < 0 ? -1 : 1;

			//************* AQUI FICA ANGULO POR AREA DE COLISAO *********
			int colisao_ponto = bola.y - pads[i].y;
			if (colisao_ponto >= 0 && colisao_ponto < 21) {
				bola.dy = valor_aleat();
			} else if (colisao_ponto >= 21 && colisao_ponto < 39) {
				bola.dy = 1; //45º
			} else if (colisao_ponto >= 39 && colisao_ponto < 57) {
				bola.dy = 0;
			} else if (colisao_ponto >= 57 && colisao_ponto < 75) {
				bola.dy = -1; //-45º
			} else if (colisao_ponto >= 75 && colisao_ponto < 96) {
				bola.dy = valor_aleat();
			}
			buzzerPlay();
		} else {
			if (bola.x < (pads[0].x + pads[0].l - 5)) {
				pontos[1] += 1;
				jogo_reset_pontos();
			}
			if (bola.x > (pads[1].x)) {
				pontos[0] += 1;
				jogo_reset_pontos();
			}
		}
		if(pontos[0] >= MAX_PTN || pontos[1] >= MAX_PTN){
			jogo_iniciar();
			jogo_resume_pause();
		}
	}
}

void jogo_set_inicio(){
	bola.l = 17;
	bola.a = 17;
	bola.x = 400;
	bola.y = 228;

	pads[0].y = 200;
	pads[0].l = 32;
	pads[0].a = 96;
	pads[0].x = 143;

	pads[1].y = 200;
	pads[1].l = 32;
	pads[1].a = 96;
	pads[1].x = 751;

	pontos[0] = 0;
	pontos[1] = 0;
	jogo_loop();
}

void jogo_iniciar(){
	jogo_set_inicio();
	bola.dx = -1;
	bola.dy = 0;
	exec = 1;
}

void jogo_reset_pontos(){
	bola.l = 17;
	bola.a = 17;
	bola.x = 400;
	bola.y = 228;

	pads[0].y = 200;
	pads[0].l = 32;
	pads[0].a = 96;
	pads[0].x = 143;

	pads[1].y = 200;
	pads[1].l = 32;
	pads[1].a = 96;
	pads[1].x = 751;

	bola.dx = 1;
	bola.dy = 0;
}

void jogo_setar_pads(int y_p1, int y_p2){
	pads[0].y = y_p1;
	pads[1].y = y_p2;
}

void set_position(int v_p1, int v_p2, int x_b, int y_b){
	v_p1 = v_p1 > LIMITE_INFERIOR - 96 ? LIMITE_INFERIOR - 96: v_p1;
	v_p1 = v_p1 < LIMITE_SUPERIOR ? LIMITE_SUPERIOR : v_p1;
	v_p2 = v_p2 > LIMITE_INFERIOR - 96 ? LIMITE_INFERIOR - 96: v_p2;
	v_p2 = v_p2 < LIMITE_SUPERIOR ? LIMITE_SUPERIOR : v_p2;

	long int dataa, datab;
	dataa = v_p1;
	dataa |= (v_p2 << 16);
	datab = y_b;
	datab |= (x_b << 16);
	ALT_CI_VGA(dataa, datab);
}

int* jogo_pegar_pontos(){
	return pontos;
}

void jogo_parar(){
	exec = 0;
	jogo_set_inicio();
}

void jogo_resume_pause(){
	exec = (exec == 1) ? 0 : 1;
}

int jogo_isExec(){
	return exec;
}
/*
 * Essa função deve ficar no loop principal da aplicação*/
void jogo_loop(){
	if(1 == exec){
		move_bola();
		set_position(pads[0].y, pads[1].y, bola.x, bola.y);
	}
	contador++;
	contador = contador == 3 ? 0 : contador;
}
#endif
