#ifndef __MOVIMENTO_H_
#define __MOVIMENTO_H_
#include "system.h"
#include <stdlib.h>


char get_charar( void ){
	volatile int * RS232_UART_ptr = (int *) RS232_0_BASE; // RS232 UART address
	int data;
	data = *(RS232_UART_ptr); // read the RS232_UART data register
	if (data & 0x00008000){ // check RVALID to see if there is new data
		char result = (char) data & 0xFF;
		return result;
	}
	else{
		char nada = '\0';
		return nada;
	}
}


void setPosition(int v_p1, int v_p2, int x_b, int y_b){
	long int dataa, datab;
	dataa = v_p1;
	dataa |= (v_p2 << 16);
	datab = y_b;
	datab |= (x_b << 16);
	ALT_CI_VGA(dataa, datab);

}

void converteAna(int* anaUm, int* anaDois){
	int bolo = 0;
	int vai = -1;
	int vae = -1;
	//char va[9];
	char v;
	int i = 0;
	//char h, y;
	v = get_charar();
	/*while( v != '\n' && i < 5){
		if(v == 'h'  ){
			bolo++;
			break;
		}else if(bolo == 0){
			vai = (int)v - 48;
			bolo++;
		}else if(bolo == 1){
			vae = (int)v - 48;
			bolo++;
		}else{
			bolo = 5;
		}
		v = get_charar();
		i++;
	}*/
	if(v == 'a'){
		*anaUm = 0;
		*anaDois = 0;
	}else if(v == 'b'){
		*anaUm = 0;
		*anaDois = 1;
	}else if(v == 'c'){
		*anaUm = 1;
		*anaDois = 0;
	}else if(v == 'd'){
		*anaUm = 1;
		*anaDois = 1;
	}else if(v == 'e'){
		*anaUm = 2;
		*anaDois = 2;
	}else if(v == 'f'){
		*anaUm = 0;
		*anaDois = 2;
	}else if(v == 'g'){
		*anaUm = 2;
		*anaDois = 0;
	}else if(v == 'l'){
		*anaUm = 2;
		*anaDois = 1;
	}else if(v == 'm'){
		*anaUm = 1;
		*anaDois = 2;
	}else{
		*anaUm = 1;
		*anaDois = 1;
	}


	/*if(bolo!=3){
	 *anaUm = 1;
	 *anaDois = 1;
	}else{
	 *anaUm = vai;
	 *anaDois = vae;

		//vai = atoi(va);



		if(vai < 350){
	 *anaUm = 0;
		}else if(vai > 750){
	 *anaUm = 2;
		}else{
	 *anaUm = 1;
		}

	}*/
}

#endif
