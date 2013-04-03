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
#include <stdio.h>
#include <stdlib.h>
//#include "linked_list.h"
#include <string.h>

#define TAMANHO 200
#define HEAD_NODE_CODE -999
#define NON_INIT_LINE -1

typedef struct token {
	char* word;
	struct token* next;
	struct token* last;
} token;

typedef struct node { //nó individual da lista ligada
	int line;
	char* phrase;
	token* words;
	struct node* next;
	struct node* last;
} node;

int parse_text (int argc, char* argv[]);

int parse_line (char* text);

int parse_recur_switch (char* text);

token* create_token_list ();

token* insert_token (char *word, token* previous_node);

token* tokenize_string (char* phrase);

node* create_list ();

node* insert_node (int line, char *text, node* previous_node);

int remove_node (node* target_node);

int print_node_text (node* target_node);

int print_node_text_recur (node* target_node);

#endif
