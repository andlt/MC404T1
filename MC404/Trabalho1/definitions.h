/*
 *  definitions.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//#include <stdbool.h>

typedef struct mem_word { //estrutura que guarda uma palavra de memória
	int line;
	char side; //l para primeira palavra, r para a segunda
	char* opcode;
	char* address;
	struct mem_word* next;
	struct mem_word* last;
} mem_word;

void* convert_base (char init_base, char final_base, void* number);

int bin_to_dec (char* bin);
int bin_to_octa (int bin);
char* bin_to_hexa (int bin);
int octa_to_bin (int octa);
int octa_to_dec (int octa);
char* octa_to_hexa (int octa);
int dec_to_bin (int dec);
int dec_to_octa (int dec);
char* dec_to_hexa (int dec);
int hexa_to_bin (char* hexa);
int hexa_to_octa (char* hexa);
int hexa_to_dec (char* hexa);

#endif
