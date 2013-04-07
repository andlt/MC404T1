/*
 *  definitions.C:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#include <stdio.h>
#include "definitions.h"

/*void* convert_base (char init_base, char final_base, void* number)
{
	if(init_base == 'x'){
		if(final_base == 'd'){
			return hexa_to_dec(number);
		}
		else if(final_base == 'b'){
			return hexa_to_bin(number);
		}
		else if(final_base == 'o'){
			return hexa_to_octa(number);
		}
		else{
			printf("\nconvert_base: parâmetro incorreto; base final incorreta\n");
		}
	}
	else if(init_base == 'd'){
		if(final_base == 'x'){
			return dec_to_hexa(number);
		}
		else if(final_base == 'b'){
			return dec_to_bin(number);
		}
		else if(final_base == 'o'){
			return dec_to_octa(number);
		}
		else{
			printf("\nconvert_base: parâmetro incorreto; base final incorreta\n");
		}
	}
	else if(init_base == 'b'){
		if(final_base == 'x'){
			return bin_to_hexa(number);
		}
		else if(final_base == 'd'){
			return bin_to_dec(number);
		}
		else if(final_base == 'o'){
			return bin_to_octa(number);
		}
		else{
			printf("\nconvert_base: parâmetro incorreto; base final incorreta\n");
		}
	}
	else if(init_base == 'o'){
		if(final_base == 'x'){
			return octa_to_hexa(number);
		}
		else if(final_base == 'd'){
			return octa_to_dec(number);
		}
		else if(final_base == 'b'){
			return octa_to_bin(number);
		}
		else{
			printf("\nconvert_base: parâmetro incorreto; base final incorreta\n");
		}
	}
	else{
		printf("\nconvert_base: parâmetro incorreto; base inicial incorreta\n");
		int error = -1;
		return &error;
	}
}*/
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

char* octa_to_dec (char* octa)
{
	char* dec = NULL;
	sscanf("%o", octa, "d", dec);
	return dec;
}

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

char* dec_to_hexa (int dec)
{
	return 'c';
}

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
