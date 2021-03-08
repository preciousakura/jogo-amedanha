#include "jogo.h"

/* ---------- funcoes de tempo ---------- */

int marcar_tempo(){ // marca o tempo
    struct timeval  inicio;
    gettimeofday(&inicio,NULL);
    int tempo_inicial = inicio.tv_sec;
    return tempo_inicial;
}

int tempo_final(int t_init){  // marca o tempo, pega o tempo inicial, diminui e retorna o tempo total
    struct timeval fim;
    gettimeofday(&fim,NULL);
    int tempo_final = fim.tv_sec - t_init;
    return tempo_final;
}

int tempo_jogador(int qtd_de_jogadores, int jogadas_ja_feitas) { //calcula o tempo que cada jogador tem
	int temp;
	temp = 8 + (2 * (qtd_de_jogadores - jogadas_ja_feitas));
	return temp;
}

int tempo_excedido(int tempo_rodada, int tempo) { //verifica se o tempo foi excedido
	if (tempo_rodada > tempo) 
		return 1; 
	else 
		return 0; 
}

void somatorio_tempo(struct Jogador *jogador,int tempo_rodada,int numero_do_jogador){ // somatorio dos tempos dos jogadores
    jogador[numero_do_jogador].tempo_total += tempo_rodada;
}

/* ---------- fim funcoes de tempo ---------- */