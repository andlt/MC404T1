/*
 *  linked_list.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 28/03/13
 */

#include "linked_list.h"
#include <stdlib.h>

token* create_token_list ()
{
	//devolve o nó cabeça de uma lista nova

	token* new_token = NULL;

	new_token = malloc(sizeof(token));

	new_token->word = "HEAD_NODE_CODE";
	new_token->next = NULL;
	new_token->last = NULL;

	return new_token;
}

token* insert_token (char *word, token* previous_token)
{
	//insere um novo token após previous_token

	token* new_token = NULL;

	if(previous_token == NULL){
		printf("\ninsert_token: parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		token* new_token = NULL;

		new_token = malloc(sizeof(token));
		if(new_token == NULL){
			printf("A Memória não pode ser alocada!\n");
		}

		new_token->word = word;

		new_token->last = previous_token;
		new_token->next = previous_token->next;

		previous_token->next = new_token; //arruma os apontadores

		return new_token;
	}
}

token* tokenize_string (char* phrase)
{
	token* new_token = NULL, *previous_token = NULL;
	char* tok;

	new_token = create_token_list();
	if(new_token == NULL){
			printf("A Memória não pode ser alocada!\n");
		}

	tok = strtok(phrase, " ");
	if(tok != NULL){
		previous_token = insert_token(tok, new_token);
		//printf("%s", previous_token->word);
		printf("%s", tok);
		tok = strtok(phrase, " ");
	}
	while(tok != NULL){
		previous_token = insert_token(tok, previous_token);
		//printf("%s", previous_token->word);
		printf("%s", tok);
		tok = strtok(NULL, " ");
	}

	return new_token;
}

node* create_list ()
{
	//devolve o nó cabeça de uma lista nova

	node* new_node = NULL;

	new_node = malloc(sizeof(node));

	new_node->line = HEAD_NODE_CODE;
	new_node->next = NULL;
	new_node->last = NULL;
	new_node->phrase = "Cabeça";

	return new_node;
}

node* insert_node (int line, char* phrase, node* previous_node)
{
	//insere um nó novo após previous_node

	if(previous_node == NULL){
		printf("\ninsert_node: parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		node* new_node = NULL;

		new_node = malloc(sizeof(node));
		if(new_node == NULL){
			printf("A Memória não pode ser alocada!\n");
		}

		new_node->line = line; //define os campos
		new_node->phrase = phrase;
		new_node->words = tokenize_string (phrase);

		new_node->last = previous_node;
		new_node->next = previous_node->next;

		previous_node->next = new_node; //arruma os apontadores

		return new_node;
	}
}

int remove_node (node* target_node)
{
	//remove o nó target_node

	target_node->last->next = target_node->next; //arruma os apontadores
	target_node->next->last = target_node->last;

	free(target_node); //libera a memória

	return 0;
}

int print_node_phrase (node* target_node)
{
	printf("%s", target_node->phrase);

	return 0;
}

int print_node_phrase_recur (node* target_node)
{
	if(target_node != NULL){
		if(print_node_phrase(target_node) == 0){
			return print_node_phrase_recur(target_node->next);
		}
		else{
			printf("Erro na impressao");
			return -1;
		}
	}
	else{
		return 0;
	}
}
