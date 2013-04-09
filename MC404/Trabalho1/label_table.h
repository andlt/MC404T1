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
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

#define WORD_SIZE 8//"AA AAA\0"

typedef struct label_node { //estrutura que guarda uma palavra de memória
	int line;
	char side; //l para primeira palavra, r para a segunda
	char* name;
	struct label_node* next;
	struct label_node* last;
} label_node;

label_node* create_label_table ();

label_node* insert_label (int line, char side, char* name, label_node* previous_node);

int remove_label (label_node* target_node);

label_node* fill_label_table (str* parsed_list, label_node* table);

label_node* label_exists(char* label, label_node* table);

char* get_real_address (char* token, label_node* table);

char* read_line(char* line, label_node* table);

int write_mem_map (char* map_name, str* parsed_list, label_node* table);

#endif /* LABEL_TABLE_H_ */

