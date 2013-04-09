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

//funções grupo str (cada str equivale a uma linha lida do arquivo de entrada

str* create_str_list ()
{
	//devolve um apontador para o nó cabeça de uma lista ligada de "frases" (linhas do arquivo de entrada)

	str* new_str = NULL;

	new_str = malloc(sizeof(str));

	new_str->line = HEAD_NODE_CODE; //define os campos
	new_str->next = NULL;
	new_str->last = NULL;
	new_str->phrase = "Cabeça";

	return new_str;
}

str* insert_str (int line, char* phrase, str* previous_str)
{
	/* insere um nó novo após previous_str */

	if(previous_str == NULL){ //teste dos parâmetros
		printf("Error : insert_str : parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		str* new_str = malloc(sizeof(str));

		if(new_str == NULL){ //testa alocação de memória
			printf("Error : insert_str : A Memória não pode ser alocada!\n");
		}

		new_str->line = line; //define os campos
		new_str->phrase = phrase;
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

str* parse_text (int argc, char* argv[])
{
	/*Lê o arquivo de entrada e retorna uma estrutura contendo cada linha dele */

	FILE *file; //arquivo de entrada
	char *read_string = NULL; //linha mais recentemente lida do arquivo
	str *str_list = NULL; //aponta para o nó cabeça da lista de linhas lidas
	str *str_last = NULL; //aponta para o último elemento da lista de linhas lidas

	file = fopen(argv[1], "r"); //abre o arquivo do argumento

	str_last = str_list = create_str_list(); //cria o nó cabeça da lista

	//nó principal: lê uma linha do arquivo e insere na estrutura de dados
	while(!feof(file)){
		read_string = malloc(sizeof(char)*TAMANHO);
		read_string = fgets(read_string, TAMANHO, file);
		str_last = insert_str(NON_INIT_LINE, read_string, str_last); //linha não inicializada
	}

	fclose(file); //fecha o arquivo

	return str_list;
}

//funções auxiliares

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
