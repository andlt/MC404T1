/*
 *  label_table.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 31/03/13
 */

#include "label_table.h"

mem_word* insert_word (int line, char side, char* opcode, char* address,
		mem_word* previous_word)
{
	//insere uma nova palavra de memória na lista, após previous_word

	if(previous_word == NULL){
		printf("\ninsert_word: parâmetro incorreto; palavra anterior nula\n");
		return NULL;
	}
	else{
	mem_word* new_word = NULL;

	new_word = malloc(sizeof(mem_word));
	if(new_word == NULL){
		printf("A Memória não pode ser alocada!\n");
	}

	new_word->line = line; //define os campos
	new_word->side = side;
	new_word->opcode = opcode;
	new_word->address = address;

	new_word->last = previous_word;
	new_word->next = previous_word->next;

	previous_word->next = new_word; //arruma os apontadores

	return new_word;
	}
}

int remove_word (mem_word* target_word)
{
	//remove a palavra target_word

	target_word->last->next = target_word->next; //arruma os apontadores
	target_word->next->last = target_word->last;

	free(target_word); //libera a memória

	return 0;
}


label_node* create_lable_table ()
{
	//devolve o nó cabeça de uma lista nova

	label_node* new_node = NULL;

	new_node = malloc(sizeof(label_node));

	new_node->line = HEAD_NODE_CODE;
	new_node->side = 'h';
	new_node->name = "Cabeça";
	new_node->next = NULL;
	new_node->last = NULL;

	return new_node;
}

label_node* insert_label (int line, char side, char* name, label_node* previous_node)
{
	//insere um nó novo após previous_node

	if(previous_node == NULL){
		printf("\ninsert_label_node: parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		label_node* new_node = NULL;

		new_node = malloc(sizeof(label_node));
		if(new_node == NULL){
			printf("A Memória não pode ser alocada!\n");
		}

		new_node->line = line; //define os campos
		new_node->side = side;
		new_node->name = name;

		new_node->last = previous_node;
		new_node->next = previous_node->next;

		previous_node->next = new_node; //arruma os apontadores

		return new_node;
	}
}

int remove_label (label_node* target_node)
{
	//remove o nó target_node

	target_node->last->next = target_node->next; //arruma os apontadores
	target_node->next->last = target_node->last;

	free(target_node); //libera a memória

	return 0;

}

mem_word* fill_label_table (node* parsed_list)
{
	int line_count = 0;
	char side = 'l';
	label_node* previous_label = NULL;

	while(parsed_list != NULL){
		//do stuff
		//insert_word(side, opcode, address, previous_word);
		parsed_list = parsed_list->next; //Isso pode dar merda
		side = 'r';
		if(parsed_list != NULL){
			//do stuff
			parsed_list = parsed_list->next; //Isso pode dar merda
			line_count++;
		}
		else{
			break;
		}
	}

	return 0;
}

int write_mem_map (char* map_name, node* parsed_list, mem_word* table){

	FILE *file;

	file = fopen(map_name, "w");

	while(parsed_list != NULL){
		//do stuff
		parsed_list = parsed_list->next;
	}

	fclose(file); //fecha o arquivo

	return 0;
}
