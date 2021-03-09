/*
Trabalho Intermediário – Jogo Amedonha
Disciplina Programação (CK0226) – Semestre 2020.2
Equipe: Guilherme Sales Fernandes - 499756
		Isabel Cristina de Oliveira Lopes - 493948
		Matheus Ribeiro Alencar - 494711
		
*/

#include "jogo.h"

/* ---------- funcoes de output ---------- */

void mostrar_resultado(struct Jogador *jogador, int rodada, int *sequencia, char **categoria, int num_jog) {
	if(rodada < 4)
		printf("\nConcluída a rodada, esta é a tabela de escores:\n\n");
  	else // ultima rodada exibe resultado final
    	printf("\nRESULTADO FINAL:\n\n");
  
	printf("%13s", "  "); // espaço na tabela para nome dos jogadores
	for(int i = 0; i<rodada+1; i++){
		if(i < 5) 
			printf("%-15s ", categoria[sequencia[i]]); // printa categorias na ordem sorteada
	}
  	if(rodada < 4) 
    	printf("%-15s", "Total Parcial"); 
  	else 
    	printf("%-15s", "Total Geral"); // ultima rodada exibe total geral 
  	printf("\n");

	for(int i = 0; i<num_jog; i++){
		printf("%-12s ", jogador[i].nome);
		for(int j = 0; j<rodada+1; j++)
			printf("%-15d ", jogador[i].pontos[sequencia[j]]);
			
    	printf("%-15d", jogador[i].pontos[5]);
		printf("\n");
	}
}

int ganhador(struct Jogador *jogador, int qtd){ // retorna indice do jogador ganhador
  int i = 0;
  int maior = i;
  for(i = 0; i<qtd; i++){
    if(jogador[i].pontos[5] > jogador[maior].pontos[5])
      maior = i;
    else if (jogador[i].pontos[5] == jogador[maior].pontos[5]){ // se der empate
      if(jogador[i].tempo_total < jogador[maior].tempo_total)   // compara o tempo total e o menor é o ganhador
        maior = i;
    }
  } return maior;
}


void limpar_tela() {
	system("clear"); // limpa tela no linux, se for windows, mudar para "cls"
}

/* ---------- fim funções de entradas ---------- */