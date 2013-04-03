/*
 *  opcodes.c: tabela com as conversões nome->opcode do trabalho 1, MC404 1s2013
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#include <stdio.h>
#include "opcode.h"

char* rec_mneumonic (char* str)
{
	//converte um mneumonico para ser respectivo opcode

	if (strcmp(str, "LMQ") == 0){
		return "0A";
	}
	else if (strcmp(str, "LMQM") == 0){
		return "09";
	}
	else if (strcmp(str, "ST") == 0){
		return "21";
	}
	else if (strcmp(str, "LD") == 0){
		return "01";
	}
	else if (strcmp(str, "LDN") == 0){
		return "02";
	}
	else if (strcmp(str, "LDMOD") == 0){
		return "03";
	}
	else if (strcmp(str, "JMP") == 0){
		return "0D";
		//return "0E";
	}
	else if (strcmp(str, "JMPP") == 0){
		return "0F";
		//return "10";
	}
	else if (strcmp(str, "ADD") == 0){
		return "05";
	}
	else if (strcmp(str, "ADDMOD") == 0){
		return "07";
	}
	else if (strcmp(str, "SUB") == 0){
		return "06";
	}
	else if (strcmp(str, "SUBMOD") == 0){
		return "08";
	}
	else if (strcmp(str, "MUL") == 0){
		return "0B";
	}
	else if (strcmp(str, "DIV") == 0){
		return "0C";
	}
	else if (strcmp(str, "LSH") == 0){
		return "14";
	}
	else if (strcmp(str, "RSH") == 0){
		return "15";
	}
	else if (strcmp(str, "STM") == 0){
		return "12";
		//return "13";
	}
	else{
		printf("\nrec_mneumonic: mneumônico incorreto\n");
		return "error";
	}
	return 0;
}

