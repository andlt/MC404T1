/*
 *  parser.c: módulo que lê o conteúdo do arquivo e o carrega na memória
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 27/03/13
 *  
 *  Log: Criar Lista ligada para conter cada caracter?
 *  
 */

#include "parser.h"

int parse_text (int argc, char* argv[])
{
	FILE *file;
	//int i = 0;
	char *read_string = NULL;//, read_char = '0';
	node *list = NULL, *list_last = NULL;//, *aux;

	file = fopen(argv[1], "r"); //abre o arquivo do argumento

	list_last = list = create_list();

	while(!feof(file)){
		read_string = malloc(sizeof(char)*TAMANHO);
		fgets(read_string, TAMANHO, file);
		list_last = insert_node(NON_INIT_LINE, read_string, list_last); //linha não inicializada
	}

	while(list != NULL){
		list = list->next;
		while(list->words != NULL){
			list->words = list->words->next;
			//printf("%s\n", list->words->word);
		}
	}

	fclose(file); //fecha o arquivo

	return 0;
}

/*int skip_spaces ()
{
	while(read_char == ' ')
		read_char = fgetc(file):

	return 0;
}
*/


/*while(read_char == ' '){
	read_char = fgetc(file);
}*/
/*while(read_char != EOF){ //percorre o arquivo lendo o conteúdo
	while(read_char != '\n'){ //percorre a linha
		read_char = fgetc(file);
		printf("%c\n", read_char);
		read_string[i] = read_char;
		i++;
		//printf("blow\n");
	}
	//printf("Hey\n");
}*/

int parse_line (char* text)
{
	//parse_ recur_switch(text)

	return 0;
}
/*
int parse_recur_swicth (char* text)
{

	switch (text[0]) {
		case '\o':
			return 0;
		case '.': //label
			printf("label\n");
			return 1;
		case ';':
			printf("comentário\n");
			return 2;
		case ' ':
			return parse_recur_swicth(text[1]);
		default:
			return 3;
	}

	return 0;
}
*/

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
