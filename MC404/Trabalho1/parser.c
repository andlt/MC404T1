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
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define TAMANHO 200

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
