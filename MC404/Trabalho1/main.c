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
	str* parsed_text;
	label_node* label_table;

	printf("Tah Live!\n");

	parsed_text = parse_text(argc, argv);

	label_table = create_label_table();



	printf("%s", parsed_text->next->next->next->words->next->next->word);

	printf("Tah dead!\n");

	return 0;
}
