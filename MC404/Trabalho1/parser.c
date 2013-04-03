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

//funções grupo token (cada token contém uma única palavra lida do arquivo de entrada)

token* create_token_list ()
{
	//retorna um apontador para o nó cabeça de uma nova lista de tokens

	token* new_token = NULL;

	new_token = malloc(sizeof(token));

	new_token->word = "HEAD_NODE_CODE";
	new_token->next = NULL;
	new_token->last = NULL;

	return new_token;
}

token* insert_token (char *word, token* previous_token)
{
	//insere um novo token após previous_token, retorna um apontador para ele

	token* new_token = NULL;

	if(previous_token == NULL){ //validação de previous_token
		printf("\ninsert_token: parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		new_token = malloc(sizeof(token));
		if(new_token == NULL){ //teste da alocação de memória
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
	//divide uma string em "palavras", retorna uma lista ligada com essas palavras

	token* new_token = NULL, *previous_token = NULL;
	char* tok;

	new_token = create_token_list();
	if(new_token == NULL){ //testa a alocação de memória
			printf("A Memória não pode ser alocada!\n");
		}

	tok = strtok(phrase, " ");
	/*if(tok != NULL){ //adiciona o primeiro elemento após o nó cabeça
		previous_token = insert_token(tok, new_token);
		//printf("%s", previous_token->word);
		printf("%s", tok);
		tok = strtok(phrase, " ");
	}*/
	while(tok != NULL){ //adiciona os demais elementos
		previous_token = insert_token(tok, new_token);//previous_token);
		//printf("%s", previous_token->word);
		//printf("%s\n", tok);
		tok = strtok(NULL, " ");
	}

	while(new_token->last != NULL)
		new_token = new_token->last;

	return new_token;
}

//funções grupo str (cada str equivale a uma linha lida do arquivo de entrada

str* create_str_list ()
{
	//devolve um apontador para o nó cabeça de uma lista ligada de "frases" (linhas do arquivo de entrada)

	str* new_str = NULL;

	new_str = malloc(sizeof(str));

	new_str->line = HEAD_NODE_CODE;
	new_str->next = NULL;
	new_str->last = NULL;
	new_str->phrase = "Cabeça";

	return new_str;
}

str* insert_str (int line, char* phrase, str* previous_str)
{
	//insere um nó novo após previous_str

	if(previous_str == NULL){
		printf("\ninsert_str: parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		str* new_str = NULL;

		new_str = malloc(sizeof(str));
		if(new_str == NULL){
			printf("A Memória não pode ser alocada!\n");
		}

		new_str->line = line; //define os campos
		new_str->phrase = phrase;
		new_str->words = tokenize_string (phrase);

		new_str->last = previous_str;
		new_str->next = previous_str->next;

		previous_str->next = new_str; //arruma os apontadores

		return new_str;
	}
}

int remove_str (str* target_str)
{
	//remove o nó target_str

	target_str->last->next = target_str->next; //arruma os apontadores
	target_str->next->last = target_str->last;

	free(target_str); //libera a memória

	return 0;
}

//funções do grupo parse

int parse_text (int argc, char* argv[])
{
	FILE *file;
	//int i = 0;
	char *read_string = NULL;//, read_char = '0';
	str *list = NULL, *list_last = NULL;//, *aux;

	file = fopen(argv[1], "r"); //abre o arquivo do argumento

	list_last = list = create_str_list();

	while(!feof(file)){
		read_string = malloc(sizeof(char)*TAMANHO);
		fgets(read_string, TAMANHO, file);
		//printf("%s", read_string);
		list_last = insert_str(NON_INIT_LINE, read_string, list_last); //linha não inicializada
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

int parse_line (char* text)
{
	//parse_ recur_switch(text)

	return 0;
}

//funções auxiliares

int print_str_tokens (str* target_str)
{
	token* next_word = NULL;

	next_word = target_str->words;

	while(next_word != NULL){
		printf("%s\n", next_word);
		next_word = next_word->next;
	}

	return 0;
}

int print_str_tokens_recur (str* target_str)
{
	if(target_str != NULL){
		if(print_str_tokens(target_str) == 0){
			return print_str_tokens_recur(target_str->next);
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

int print_str_phrase (str* target_str)
{
	printf("%s", target_str->phrase);

	return 0;
}

int print_str_phrase_recur (str* target_str)
{
	if(target_str != NULL){
		if(print_str_phrase(target_str) == 0){
			return print_str_phrase_recur(target_str->next);
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
