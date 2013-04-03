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

	fill_label_table(parsed_text, label_table);

	//printf(label_table->next->name);
	/*while(label_table != NULL){
		printf("a");
		if(label_table->next != NULL){
			label_table = label_table->next;
			printf("%s\n",label_table->name);
		}
	}*/
printf("Hey\n");
	write_mem_map(argv[2], parsed_text, label_table);

	printf("Tah dead!\n");

	return 0;
}
