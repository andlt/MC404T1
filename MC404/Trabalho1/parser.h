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

int parse_text (int argc, char* argv[]);

int parse_line (char* text);

int parse_recur_switch (char* text);

#endif
