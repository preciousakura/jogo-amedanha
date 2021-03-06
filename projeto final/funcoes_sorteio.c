#include "jogo.h"

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