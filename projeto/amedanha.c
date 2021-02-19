#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Jogador {
	char nome[13];
	char resposta[30];
	int pontos[5];
	int pontos_totais;
	int tempo_total;
};

/* ---------- funcoes de alocacão ---------- */

// aloca struct jogador 

struct Jogador *criar_jogadores(int tamanho) {
	struct Jogador *jog =
		(struct Jogador *)malloc(tamanho * sizeof(struct Jogador));
	return jog;
}

void liberar_jogador(struct Jogador *mem) {
	free(mem);
}

// aloca vetor inteiro

int *criar_vetor(int tamanho) {
	int *vetor = (int *)malloc(tamanho * sizeof(int));
	memset(vetor,-1,sizeof(int));
	return vetor;
}

void liberar_vetor(int *mem) {
	free(mem);
}

/* ---------- fim funcoes de alocacão ---------- */

/* ---------- funcoes de tempo ---------- */

int marcar_tempo() {
	int tempo_inicial;
	time_t tempo_i;
	tempo_i = clock();

	tempo_inicial = (int)(tempo_i) / CLOCKS_PER_SEC;
	return tempo_inicial;
}

int tempo_final(int t_init, int t_final) {
	int tempo_total = t_final - t_init;
	return tempo_total;
}

int tempo_jogador(int qtd_de_jogadores, int jogadas_ja_feitas) { //calcula o tempo que cada jogador tem;
	int temp;
	temp = 8 + (2 * (qtd_de_jogadores - jogadas_ja_feitas));
	return temp;
}

int tempo_excedido(int tempo_rodada, int tempo) {
	if (tempo_rodada > tempo) {
		return 1; 
	} else {
		return 0; 
	}
}

/* ---------- fim funcoes de tempo ---------- */

/* ---------- funcoes de entradas ---------- */

int contar_Caractere(char *res) { // conta o número de caracteres
	int tamanho = 0;
	while (res[tamanho] != '\0') {
		tamanho++;
	}
	return tamanho;
}

void getString(char *string, int tamanho){
	fgets(string, tamanho, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int num_jogadores() { // numero de jogadores
	char str_jogadores[50]; 
  	printf("Digite o numero de jogadores: ");
	getString(str_jogadores, 50);
	int numero_de_jogadores = atoi(str_jogadores); 
	while ((numero_de_jogadores < 2) || (numero_de_jogadores > 10)) {
		printf("Quantidade Invalida. Somente de 2 a 10 jogadores: ");
		getString(str_jogadores, 50);
    	numero_de_jogadores = atoi(str_jogadores);
	}
	return numero_de_jogadores;
}

void jogadores(struct Jogador *jogador, int num_jogadores) { // nome dos jogadores
	for (int i = 0; i < num_jogadores; i++) {
	printf("Digite o nome do jogador %d: ", i + 1);
	getString(jogador[i].nome, 255);

		while ((contar_Caractere(jogador[i].nome) > 12) || (contar_Caractere(jogador[i].nome) == 0)) {
			printf("Nome invalido! Digite o nome do jogador %d novamente: ", i + 1);
			getString(jogador[i].nome, 255);
		}
	}
}

void resposta(char *resposta, char letra_Atual) { // resposta
	getString(resposta, 255);
	while (contar_Caractere(resposta) > 30 || contar_Caractere(resposta) == 0 || toupper(resposta[0]) != letra_Atual) {
		printf("Resposta Invalida! Digite uma resposta valida: ");
		getString(resposta, 255);
	}
}

/* ---------- fim funcoes de entradas ---------- */

/* ---------- funcoes de sorteio ---------- */

int sortear_numero(int range) {
	int sorteado = rand() % range;
	return sorteado;
}

//sortear um elemento por vez

int verifica_sort(int sorteado, int *sortvetor){
  if(sortvetor[sorteado] == sorteado){
    return 1;
  } sortvetor[sorteado] = sorteado; 
  return 0;
}

int sortear_elemento(int *sortvetor, int qtd){
  int sorteado = sortear_numero(qtd);
  while(verifica_sort(sorteado, sortvetor)){
    sorteado = sortear_numero(qtd);
  }
  return sorteado;
}


// sortear uma sequencia 

int verifi_existe_sort(int *sequencia, int valor, int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		if (sequencia[i] == valor) {
			return 1;
		}
	}
	return 0;
}

void sortear_sequencia(int *sequencia, int tamanho_sequencia, int qtd) {
	int sorteio = sortear_numero(qtd);
	int i = 0;

	for (int i = 0; i < tamanho_sequencia; i++) {
		while (verifi_existe_sort(sequencia, sorteio, i) == 1) {
			sorteio = sortear_numero(qtd);
		}
		sequencia[i] = sorteio;
	}
}

void limpar_sequencia(int *sequencia, int tam) {
	memset(sequencia, -1, sizeof(int));
}

/* ---------- fim funcoes de sorteio ---------- */

void limpar_tela() {
	system("cls");
}

void rodar_jogo() {
	char *categorias[5] = {"Nome de Pessoa",
						   "Nome de Cidade",
						   "Nome de Comida",
						   "Nome de Animal",
						   "Profissao"};

	char alfabeto[23] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
						 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q',
						 'R', 'S', 'T', 'U', 'V', 'X', 'Z'};

	printf("*** JOGO AMEDONHA ***\n\n");
	int qtd_jogadores = num_jogadores(); // numero de jogadores

	int temp_init, temp_fim, temp_total; // variaveis de tempo

	char letraAtual;
	char *categoriaAtual[18];

	// guardar sequencia de sorteios 
	int *letra_sort = criar_vetor(23);
	int *categ_sort = criar_vetor(5);
	int *jog_sort = criar_vetor(qtd_jogadores);

	struct Jogador *jogador = criar_jogadores(qtd_jogadores);
	jogadores(jogador, qtd_jogadores); // nome dos jogadores

	sortear_sequencia(categ_sort, 5, 5);

	int i, j, k;

	for (i = 0; i < 5; i++) {
		letraAtual = alfabeto[sortear_elemento(letra_sort, 23)];
		printf("\nA letra desta rodada e: %c\n", letraAtual);

		categoriaAtual[0] = categorias[categ_sort[i]];
		printf("A categoria desta rodada e: %s\n", categoriaAtual[0]);

		sortear_sequencia(jog_sort, qtd_jogadores, qtd_jogadores); // ordem de jogadores
		printf("A ordem desta jogada sera: \n");
		for (j = 0; j < qtd_jogadores; j++) {
			printf("  %d. %s\n", j + 1, jogador[jog_sort[j]].nome);
		}
    	printf("\nTecle [Enter] para iniciar a rodada: ");
		getchar();
		limpar_tela();

		for (j = 0; j < qtd_jogadores; j++) {
			printf("%s, voce deve entrar um \"%s\" com a letra \"%c\" em %d segundos: ", jogador[jog_sort[j]].nome, categoriaAtual[0], letraAtual,tempo_jogador(qtd_jogadores, j));

			temp_init = marcar_tempo();
			resposta(jogador[jog_sort[j]].resposta, letraAtual);
			temp_fim = marcar_tempo();
			temp_total = tempo_final(temp_init, temp_fim);

			if (tempo_excedido(temp_total, tempo_jogador(qtd_jogadores, j))) {
				jogador[jog_sort[j]].resposta[0] = '\0';
			}
			//tempo total
			//pontuacao
			limpar_tela();
		}
		
		printf("Jogadas realizadas:\n");
		for (j = 0; j < qtd_jogadores; j++) {
			printf("%-12s -> %s\n", jogador[j].nome, jogador[j].resposta);
		}

		limpar_sequencia(jog_sort, qtd_jogadores);
	}
	
	liberar_vetor(letra_sort);
    liberar_vetor(categ_sort);
	liberar_vetor(jog_sort);

    liberar_jogador(jogador);
}

int main() {
	srand(time(NULL));
	rodar_jogo();
	return 0;
}