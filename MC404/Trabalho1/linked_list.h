/*
 *  linked_list.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 28/03/13
 */
/*
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define HEAD_NODE_CODE -999
#define NON_INIT_LINE -1

#include <stdio.h>
#include <string.h>

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

//funções

token* create_token_list ();

token* insert_token (char *word, token* previous_node);

token* tokenize_string (char* phrase);

node* create_list ();

node* insert_node (int line, char *text, node* previous_node);

int remove_node (node* target_node);

int print_node_text (node* target_node);

int print_node_text_recur (node* target_node);

#endif /* LINKED_LIST_H */

