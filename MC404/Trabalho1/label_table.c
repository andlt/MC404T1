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
		printf("Error : insert_label : parâmetro incorreto; nó anetrior nulo\n");
		return NULL;
	}
	else{
		label_node* new_node = malloc(sizeof(label_node));
		if(new_node == NULL){ //testa a alocação de memória
			printf("Error : insert_label : A Memória não pode ser alocada!\n");
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
	/*
	 * remove o nó target_node da lista na qual ele se situa
	 */

	target_node->last->next = target_node->next; //arruma os apontadores
	target_node->next->last = target_node->last;

	free(target_node); //libera a memória

	return 0;
}

label_node* fill_label_table (str* line_list, label_node* table)
{
	/*
	 * Recebe uma lista ligada de strings line_list e um nó cabeça de uma lista
	 * ligada table. Preenche table com o os rótulos (abcd:) presentes nas
	 * strings. Retorna 0 para sucesso e 1 para erro.
	 */

	int line_count = 0;
	char side = 'l';
	char* tok = NULL; //vai guardar as palavras de cada linha line->list->phrase

	if(line_list != NULL){
		if(line_list->line == HEAD_NODE_CODE){ //pula nó cabeça
			line_list = line_list->next;
		}
	}
	else{
		printf("Erro : fill_label_table : nó cabeça 'line_list' possui valor nulo\n");
		return NULL;
	}
	if(table == NULL){
		printf("Erro : fill_label_table : nó cabeça 'table' possui valor nulo\n");
		return NULL;
	}

	while(line_list != NULL){
		tok = strtok(line_list->phrase, " ,\n\r\0\t()"); //lê a primeira palavra da linha
		while(tok != NULL){
			if(tok[strlen(tok) -1] == ':'){
				printf("Label %s found!\n", tok);
				insert_label(line_count, side, tok, table);
			}
			tok = strtok(NULL, " ,\n\r\0\t()"); //pega a próxima palavra (endereço)
		}
		if(side == 'l'){
			side = 'r';
		}
		else{ //side == 'r'
			side = 'l';
			line_count++;
		}
		line_list = line_list->next;
	}

	return 0;
}

label_node* label_exists(char* label, label_node* table)
{
	//retorna 1 se o rótulo label existe na lista de rótulos, retorna 0 caso contrário

	if(label == NULL){
		printf("Error : label_exists : recebeu um apontador nulo como rótulo a ser testado");
		return 0;
	}
	else if(table == NULL){
		printf("Error : label_exists : recebeu um apontador nulo como tabela");
		return 0;
	}
	else if(table->next == NULL){
		printf("Error : label_exists : recebeu apenas o nó cabeça");
		return 0;
	}

	table = table->next; //pula o nó cabeça

	while(table != NULL){
		if(table->name == label){
			return table;
		}
		table = table->next;
	}

	return NULL;
}

//funções de escrita do mapa de memória

char* str_cpy (char* str, int start, int end)
{
	// devolve uma string com o conteúdo de str[start] até (incluindo) str[end]

	char* copy = NULL;
	int i; //contador

	if(start < 0){ //testa o valor de início
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

char* get_real_address (char* token, label_node* table)
{
	//recebe um token contendo o código referente a um registrador na memória do IAS. Esse código deve ser na forma M(XXX), onde XXX é o endereço do registrador. Devolveremos o valor de XXX em hexa

	char* address = NULL;
	label_node* label = NULL;

	if(strlen(token) < 4){ //não possui o tamanho mínimo -> M(x)
		printf("Error: get_real_address : endereço do registrador pequeno de mais (mínimo 4 caracteres).\n");
		return "error";
	}

	if((token[0] != 'M' && token[0] != 'm') || (token[1] != '(')){
		printf("Error: get_real_address : endereço do registrador não começa com 'M(' ou 'm('.\n");
		return "error";
	}

	//testar rótulos
	label = label_exists(address, table);
	if(label != NULL){ //se foi encontrado um rótulo na string address
		return label->name;//substituir address por label
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

	return address;
}

char* read_line(char* line, label_node* table)
{
	/* Lê uma linha line e retorna a palavra de memória que deve ser escrita no arquivo
 	 *
	 */

	if(line == NULL){ //testa o parâmetro line
		printf("Error : read_line : received null line");
		return "error";
	}

	char* tok = NULL; //vai guardar as palavras da linha line
	char* result = malloc(sizeof(char)*WORD_SIZE); //guarda a string final
	result[0] = '\0';
	char* mnem = NULL; //guarda o menumônico lido

	tok = strtok(line, " ,\n\r\0\t()"); //lê a primeira palavra da linha
	if(tok != NULL){
		mnem = rec_mnemonic(tok);
		if(strcmp(mnem, UNREC_MNEM) != 0){
			strcat(result, mnem);

			tok = strtok(NULL, " ,\n\r\0\t()"); //pega a próxima palavra (endereço)

			strcat(result, " ");
			if(tok == NULL){ //fim de linha
				strcat(result, "000");  //adiciona um endereço qualquer para instruções sem endereço (como LMQ)
			}
			else if(tok[0] != 'M' && tok[0] != ';' && tok[0] != '#'){  //não é um endereço de memória M(xxx) ou comentário
				printf("Valor de token[0] = %c\n", tok[0]);
			}
			else{
				strcat(result, get_real_address(tok, table));
			}
			printf("%s\n", result);
			return result;
		}
		return "";
	}
	else{
		return "Error";
	}
}

int write_mem_map (char* map_name, str* read_list, label_node* table)
{
	/* Lê a lista de linhas read_list e a tabela de rótulos label_table para
	 * imprimir o mapa de meória em um arquivo chamado map_name
	 */

	FILE *file;
	int line = 0; //guarda o número da linha atual no mapa de memória

	file = fopen(map_name, "w");

	if(read_list != NULL){
		if(read_list->line == HEAD_NODE_CODE){ //pula nó cabeça
			read_list = read_list->next;
		}
	}

	while(read_list != NULL){
		fprintf(file, "%03d", line); //imprime a linha
		fprintf(file, " %s", read_line(read_list->phrase, table)); //imprime a palavra da esquerda
		if(read_list->next == NULL){
			return 0;
		}
		read_list = read_list->next;
		fprintf(file, " %s\n", read_line(read_list->phrase, table)); //imprime a palavra da direita
		if(read_list->next == NULL){
			return 0;
		}
		read_list = read_list->next;
		line++;
	}

	fclose(file); //fecha o arquivo

	return 0;
}

