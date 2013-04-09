/*
 *  parser.c: módulo que lê o conteúdo do arquivo e o carrega na memória
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 27/03/13
 */

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
//#include "linked_list.h"
#include <string.h>

#define TAMANHO 200
#define HEAD_NODE_CODE -999
#define NON_INIT_LINE -1

typedef struct str { //nó individual da lista ligada
	int line;
	char* phrase;
	struct str* next;
	struct str* last;
} str;

str* create_str_list ();

str* insert_str (int line, char *text, str* previous_str);

int remove_str (str* target_str);

str* parse_text (int argc, char* argv[]);

int print_str_phrase (str* target_str);

int print_str_phrase_recur (str* target_str);

#endif
