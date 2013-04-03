/*
 *  label_table.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 31/03/13
 */

#ifndef LABEL_TABLE_H
#define LABEL_TABLE_H

#include "definitions.h"
#include "stdlib.h"
#include "stdio.h"
#include "parser.h"

typedef struct label_node { //estrutura que guarda uma palavra de memória
	int line;
	char side; //l para primeira palavra, r para a segunda
	char* name;
	struct label_node* next;
	struct label_node* last;
} label_node;

mem_word* insert_word (int line, char side, char* opcode, char* address,
		mem_word* previous_word);

int remove_word (mem_word* target_node);

label_node* create_lable_table ();

label_node* insert_label (int line, char side, char* name, label_node* previous_node);

int remove_label (label_node* target_node);

mem_word* fill_lable_table (node* parsed_list);

int write_mem_map (char* map_name, node* parsed_list, mem_word* table);

#endif /* LABEL_TABLE_H_ */
