/*
 *  definitions.c: reune as funções de conversão entre binario, octal, decimal e
 *   hexadecimal
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#include <stdio.h>
#include "definitions.h"

/*
int bin_to_dec (char* bin)
{
	int dec = 0, len = strlen(bin), base = 2;
	for(i = 1; i <= len; i++){
		if(bin[len-i] == 1){
			dec = dec +
		}
	}
	return 0;
}

int bin_to_octa (int bin)
{
	return bin;
}

char* bin_to_hexa (int bin)
{
	return 'c';
}

int octa_to_bin (int octa)
{
	return octa;
}
*/
char* octa_to_dec (char* octa)
{
	char* dec = NULL;
	sscanf("%o", octa, "%d", dec);
	return dec;
}
/*
char* octa_to_hexa (int octa)
{
	return 'c';
}

int dec_to_bin (int dec)
{
	return dec;
}

int dec_to_octa (int dec)
{
	return dec;
}
*/
char* dec_to_hexa (int dec)
{
	char* converted = malloc(sizeof(char)*CONVERTED_NUM_SIZE);
	sprintf(converted,"%010X", dec);
	return converted;
}
/*
int hexa_to_bin (char* hexa)
{
	return hexa;
}

int hexa_to_octa (char* hexa)
{
	return 0;
}

int hexa_to_dec (char* hexa)
{
 return 0;
}
*/
