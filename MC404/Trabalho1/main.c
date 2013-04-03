/*
 *  main.c: módulo principal do trabalho 1, MC404 1s2013
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#include <stdio.h>
#include "definitions.h"
#include "parser.h"
#include "opcode.h"
//#include "linked_list.h"
#include "label_table.h"

int main (int argc, char* argv[])
{
	printf("Tah Live!\n");

	parse_text(argc, argv);

	printf("Tah dead!\n");

	return 0;
}
