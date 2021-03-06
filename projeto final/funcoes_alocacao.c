#include "jogo.h"

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