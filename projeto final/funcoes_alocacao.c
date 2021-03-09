/*
Trabalho Intermediário – Jogo Amedonha
Disciplina Programação (CK0226) – Semestre 2020.2
Equipe: Guilherme Sales Fernandes - 499756
		Isabel Cristina de Oliveira Lopes - 493948
		Matheus Ribeiro Alencar - 494711
		
*/

#include "jogo.h"

/* ---------- funcoes de alocacão ---------- */

// aloca struct jogador 

struct Jogador *criar_jogadores(int tamanho) { // aloca matriz do tipo Jogador
	struct Jogador *jog =
		(struct Jogador *)malloc(tamanho * sizeof(struct Jogador));
	return jog;
}

void liberar_jogador(struct Jogador *mem) { // libera memoria
	free(mem);
}

// aloca vetor inteiro

int *criar_vetor(int tamanho) { // aloca matriz de inteiros
	int *vetor = (int *)malloc(tamanho * sizeof(int));
	memset(vetor,-1,sizeof(int));
	return vetor;
}

void liberar_vetor(int *mem) { // libera memoria
	free(mem);
}

/* ---------- fim funcoes de alocacão ---------- */