#include "jogo.h"

/* ---------- funcoes de pontuacao ---------- */

int resposta_repetida(struct Jogador *jogador, char *resposta, int num_jogadores){ // retorna quantidade de respostas repetidas na rodada
  int repetidas = 0;
  for(int i = 0; i<num_jogadores; i++){
    if(!strcmp (resposta, jogador[i].resposta))
      repetidas++;
  }
  return repetidas;
}

void pontuacao_Resposta(struct Jogador *jogador, int num_jogadores, int rodada, int *jog_sort){ // calcula pontuação de cada reposta da rodada
	for(int i = 0; i < num_jogadores; i++) {
		int repetidas = resposta_repetida(jogador, jogador[jog_sort[i]].resposta, num_jogadores);
		int resp = contar_Caractere(jogador[jog_sort[i]].resposta);
		resp = arredondar(resp, repetidas);
		jogador[jog_sort[i]].pontos[rodada] = resp;
	}
}

int arredondar(int pontuacao, int n_jogadores){ // calcula pontuacao e arredonda se necessário.
    int pont_inteira = pontuacao /n_jogadores;
    float resto =  ((float) pontuacao/(float) n_jogadores) - (pontuacao/n_jogadores); // formula dada pelo professor
    if (resto >= 0.5)
        pont_inteira = pont_inteira + 1;
    
    return pont_inteira; // retorna pontuacao
}

void somatorio_Pontucao(struct Jogador *jogador, int rodada, int num_jogadores){ // somatorio da pontuacao do jogador 
    for(int i = 0; i < num_jogadores; i++)
        jogador[i].pontos[5] += jogador[i].pontos[rodada];
}

/* ---------- fim funcoes de pontuacao ---------- */

