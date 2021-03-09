/*
Trabalho Intermediário – Jogo Amedonha
Disciplina Programação (CK0226) – Semestre 2020.2
Equipe: Guilherme Sales Fernandes - 499756
		Isabel Cristina de Oliveira Lopes - 493948
		Matheus Ribeiro Alencar - 494711
		
*/

#include "jogo.h"

/* ---------- funcoes de sorteio ---------- */

int sortear_numero(int range) { // sorteia um numero de 0 a range e o retorna
	int sorteado = rand() % range;
	return sorteado;
}

//sortear um elemento por vez

int sortear_elemento(int *sortvetor, int qtd){ // sorteia o numero
  int sorteado = sortear_numero(qtd);
  while(verifica_sort(sorteado, sortvetor))
    sorteado = sortear_numero(qtd);
  return sorteado;
}

int verifica_sort(int sorteado, int *sortvetor){ // verifica se o numero sorteado ja foi sorteado
  if(sortvetor[sorteado] == sorteado)
    return 1;
  sortvetor[sorteado] = sorteado; 
  return 0;
}

// sortear uma sequencia 


void sortear_sequencia(int *sequencia, int tamanho_sequencia, int qtd) { // sorteia um numero e forma uma sequencia 
	int sorteio = sortear_numero(qtd);
	int i = 0;

	for (int i = 0; i < tamanho_sequencia; i++) {
		while (verifi_existe_sort(sequencia, sorteio, i) == 1) 
			sorteio = sortear_numero(qtd);
		sequencia[i] = sorteio;
	}
}


int verifi_existe_sort(int *sequencia, int valor, int tam) { // verifica se o numero sorteado ja existe na sequencia
	int i;
	for (i = 0; i < tam; i++) {
		if (sequencia[i] == valor)
			return 1;
	}
	return 0;
}

void limpar_sequencia(int *sequencia, int tam) { // atribui -1 a todos os elementos da sequencia
	memset(sequencia, -1, sizeof(int));
}

/* ---------- fim funcoes de sorteio ---------- */

