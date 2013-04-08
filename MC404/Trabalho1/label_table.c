/*
 *  label_table.h:
 *
 *  Autor: André Luís L C Tavares
 *  RA: 116125
 *  Data de Criação: 31/03/13
 */

#include "label_table.h"
#include "opcode.h"


//funções do grupo label (cada label contém as informações de um rótulo)
/*
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

label_node* fill_label_table (str* parsed_list, label_node* table)
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
		if(next_str->tok != NULL){
			if(strcmp(next_str->tok->word, "HEAD_NODE_CODE") == 0){ //pula o nó cabeça
				next_str->tok = next_str->tok->next;
			}
		}
		while(next_str->tok != NULL){
			if(next_str->tok->word[strlen(next_str->tok->word)-1] == ':'){
				insert_label(line_count, side, next_str->tok->word,table);
			}
			next_str->tok = next_str->tok->next;
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
*/

int label_exists(char* label)
{
	//retorna 1 se o rótulo label existe na lista de rótulos, retorna 0 caso contrário

	return 0;
}

//funções de escrita do mapa de memória

char* str_cpy (char* str, int start, int end)
{
	// devolve uma string com o conteúdo de str[start] até (incluindo) str[end]

	char* copy = NULL;
	int i; //contador

	if(start < 0){ //testa o valor de in;icio
		printf("Error: str_cpy início menor que 0.\n");
		start = 0;
	}
	if(strlen(str)-1 < end){ //testa o valor do fim
		printf("Error: str_cpy fim menor que o tamanho da string.\n");
		end = strlen(str);
	}

	copy = malloc(sizeof(char)*(end + 2 - start)); //aloca o vetor da copia

	for(i = 0 + start; i <= end ; i++){ //percorre str de start a end, adiciona em copy de 0 a end-start
		copy[i-start] = str[i];
	}
	copy[end+1-start] = '\0'; //adiciona o caracter de fim de string

	return copy;
}

char* get_real_address (char* token)
{
	//recebe um token contendo o código referente a um registrador na memória do IAS. Esse código deve ser na forma M(XXX), onde XXX é o endereço do registrador. Devolveremos o valor de XXX em hexa

	char* address = NULL;

	if(strlen(token) < 4){ //não possui o tamanho mínimo -> M(x)
		printf("Error: get_real_address : endereço do registrador pequeno de mais (mínimo 4 caracteres).\n");
		return "error";
	}

	if((token[0] != 'M' && token[0] != 'm') || (token[1] != '(')){
		printf("Error: get_real_address : endereço do registrador não começa com 'M(' ou 'm('.\n");
		return "error";
	}

	address = str_cpy(token, 2, strlen(token)-2);
	if(strlen(address) == 1 || strlen(address) == 2){ //workaround nojento
		char* aux = malloc(sizeof(char)*5);
		aux[0] = '0';
		aux[1] = '\0';
		if(strlen(address) == 1){
			aux[1] = '0';
			aux[2] = '\0';
		}
		address = strcat(aux, address);
	}
	if(strlen(address) == 2){

	}
	//testar rótulos
	if(label_exists(address)){
		//substituir address por label
	}

	return address;
}

char* read_line(char* line)
{
	char* tok = NULL;
	char* result = malloc(sizeof(char)*WORD_SIZE);
	//int i = 0;

	if(line == NULL){
		printf("Error: read_line : received null line");
		return "error";
	}

	//get directives
	/*for(i = 0; line[i] != ' ' && line[i] != '.'; i++){
		if(line[i] == '.'){
			printf("Directive found!\n");
		}
	}*/
	printf("%s\n", line);
	tok = strtok(line, " ,\n\r\0\t()");
	if(tok != NULL){
		char* mnem = rec_mneumonic(tok);
		if(strcmp(mnem, UNREC_MNEM) != 0){
			strcat(result, mnem);
		}
		tok = strtok(NULL, " ,\n\r\0\t()");
		if(tok == NULL){
			strcat(result, " 000");  //adiciona um endereço qualquer para instruções sem endereço (como LMQ)
		}
	}
	strcat(result, " ");
	if(tok != NULL){
		strcat(result, get_real_address(tok));
	}

	return result;
}

int write_mem_map (char* map_name, str* read_list, label_node* label_table){

	FILE *file;
	int line = 0;

	file = fopen(map_name, "w");

	if(read_list != NULL){
		if(read_list->line == HEAD_NODE_CODE){ //pula nó cabeça
			read_list = read_list->next;
		}
	}

	while(read_list != NULL){
		fprintf(file, "%03d", line);
		fprintf(file, " %s", read_line(read_list->phrase));
		if(read_list->next == NULL){
			return 0;
		}
		read_list = read_list->next;
		fprintf(file, " %s", read_line(read_list->phrase));
		if(read_list->next == NULL){
			return 0;
		}
		read_list = read_list->next;
		fprintf(file, "\n");
		line++;
	}

	fclose(file); //fecha o arquivo

	return 0;
}

