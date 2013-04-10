/*
 *  definitions.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdlib.h>

#define CONVERTED_NUM_SIZE 11

typedef struct mem_word { //estrutura que guarda uma palavra de memória
	int line;
	char side; //l para primeira palavra, r para a segunda
	char* opcode;
	char* address;
	struct mem_word* next;
	struct mem_word* last;
} mem_word;

void* convert_base (char init_base, char final_base, void* number);

char* bin_to_dec (char* bin);
char* bin_to_octa (char* bin);
char* bin_to_hexa (char* bin);
char* octa_to_bin (char* octa);
char* octa_to_dec (char* octa);
char* octa_to_hexa (char* octa);
char* dec_to_bin (char* dec);
char* dec_to_octa (char* dec);
char* dec_to_hexa (int dec);
char* hexa_to_bin (char* hexa);
char* hexa_to_octa (char* hexa);
char* hexa_to_dec (char* hexa);

#endif
