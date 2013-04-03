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

//funções do grupo label (cada label contém as informações de um rótulo)

label_node* create_label_table ()
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

mem_word* fill_label_table (str* parsed_list, label_node* table)
{
	int line_count = 0;
	char side = 'l';
	str* next_str = parsed_list;

	if(next_str != NULL){
		if(next_str->line == HEAD_NODE_CODE){ //pula nó cabeça
			next_str = next_str->next;
		}
	}

	while(next_str != NULL){
		if(next_str->words != NULL){
			if(strcmp(next_str->words->word, "HEAD_NODE_CODE") == 0){ //pula o nó cabeça
				next_str->words = next_str->words->next;
			}
		}
		while(next_str->words != NULL){
			if(next_str->words->word[strlen(next_str->words->word)-1] == ':'){
				insert_label(line_count, side, next_str->words->word,table);
			}
			next_str->words = next_str->words->next;
		}
		if(next_str->next == NULL){
			return 0;
		}
		else{
			next_str = next_str->next; //Isso pode dar merda
			if(side == 'l'){
				side = 'r';
			}
			else { //side == 'r'
				side = 'l';
				line_count++;
			}
		}
	}

	return 0;
}

//funções de escrita do mapa de memória

int write_mem_map (char* map_name, str* parsed_list, label_node* label_table){

	FILE *file;

	file = fopen(map_name, "w");

	if(parsed_list != NULL){
		if(parsed_list->line == HEAD_NODE_CODE){ //pula nó cabeça
			parsed_list = parsed_list->next;
		}
	}

	while(parsed_list != NULL){
		if(parsed_list->words != NULL){
			if(strcmp(parsed_list->words->word, "HEAD_NODE_CODE") == 0){ //pula o nó cabeça
				parsed_list->words = parsed_list->words->next;
			}
		}
		//printf("%s\n", parsed_list->words->word);
		print_str_tokens_recur(parsed_list);
		if(parsed_list->words != NULL)
			printf("!!%s!!\n", parsed_list->phrase);
		while(parsed_list->words != NULL){
			//if(parsed_list->words->word[strlen(parsed_list->words->word)-1] == ':'){
				fprintf(file, "%s", parsed_list->words->word);
				printf("%s", parsed_list->words->word);
			//}
			parsed_list->words = parsed_list->words->next;
		}
		if(parsed_list->next == NULL){
			return 0;
		}
		parsed_list = parsed_list->next;
	}

	fclose(file); //fecha o arquivo

	return 0;
}

