/*
 *  main.c: módulo principal do trabalho 1, MC404 1s2013
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 23/03/13
 */

#include <stdio.h>
#include "definitions.h"
#include "parser.h"
#include "opcode.h"
//#include "linked_list.h"
#include "label_table.h"

int main (int argc, char* argv[])
{
	/* main : recebe o nome do arquivo de entrada e o nome do arquivo de saida.
	 * Lê a entrada, cria uma lista de rótulos e imprime a saída seguindo as
	 * especificações do IAS.
	 */

	str* parsed_text = NULL; //receberá o nó cabeça de uma lista de linhas
	label_node* label_table = NULL; //receberá uma lista de rótulos presendes na entrada

	char* hexa = dec_to_hexa(100);
	printf("%s Tah Live!\n", hexa);

	//divide o arquivo de entrada em linhas
	parsed_text = parse_text(argc, argv);

	//cria e preenche a lista de rótulos
	label_table = create_label_table();
	fill_label_table(parsed_text, label_table);

	//lê a lista de linhas e a tabela de rótulos para imprimir o mapa de meória
	write_mem_map(argv[2], parsed_text, label_table);

	//liberar as memórias

	printf("Tah dead!\n");

	return 0;
}
