#include "jogo.h"

/* ---------- funcoes de output ---------- */

void mostrar_resultado(struct Jogador *jogador, int rodada, int *sequencia, char **categoria, int num_jog) {
	if(rodada < 4)
		printf("\nConcluída a rodada, esta é a tabela de escores:\n\n");
  	else 
    	printf("\nRESULTADO FINAL:\n\n");
  
	printf("%13s", "  ");
	for(int i = 0; i<rodada+1; i++){
		if(i < 5) 
			printf("%-15s ", categoria[sequencia[i]]);
	}
  	if(rodada < 4) 
    	printf("%-15s", "Total Parcial");
  	else 
    	printf("%-15s", "Total Geral");
  	printf("\n");

	for(int i = 0; i<num_jog; i++){
		printf("%-12s ", jogador[i].nome);
		for(int j = 0; j<rodada+1; j++)
			printf("%-15d ", jogador[i].pontos[sequencia[j]]);
			
    	printf("%-15d", jogador[i].pontos[5]);
		printf("\n");
	}
}

int ganhador(struct Jogador *jogador, int qtd){
  int i = 0;
  int maior = i;
  int temp = i;
  for(i = 0; i<qtd; i++){
    if(jogador[i].pontos[5] > jogador[maior].pontos[5]){
      maior = i;
    } else if (jogador[i].pontos[5] == jogador[maior].pontos[5]){
      if(jogador[i].tempo_total < jogador[maior].tempo_total)
        maior = i;
    }
  } return maior;
}


void limpar_tela() {
	system("clear");
}

/* ---------- fim funções de entradas ---------- */