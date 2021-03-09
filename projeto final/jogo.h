/*
Trabalho Intermediário – Jogo Amedonha
Disciplina Programação (CK0226) – Semestre 2020.2
Equipe: Guilherme Sales Fernandes - 499756
		Isabel Cristina de Oliveira Lopes - 493948
		Matheus Ribeiro Alencar - 494711
		
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

struct Jogador {
	char nome[13];
	char resposta[30];
	int pontos[6];
	int tempo_total;
};

/* ---------- funcoes de alocacão ---------- */
struct Jogador *criar_jogadores(int);
void liberar_jogador(struct Jogador *);
int *criar_vetor(int);
void liberar_vetor(int *);
/* ---------- fim funcoes de alocacão ---------- */

/* ---------- funcoes de tempo ---------- */
int marcar_tempo();
int tempo_final(int);
int tempo_jogador(int, int);
int tempo_excedido(int, int);
void somatorio_tempo(struct Jogador *,int,int);
/* ---------- fim funcoes de tempo ---------- */

/* ---------- funcoes de entradas ---------- */
int contar_Caractere(char *);
void getString(char *, int);
int num_jogadores();
void jogadores(struct Jogador *, int);
void resposta(char *, char);
void validacao_Nome_de_Pessoa(char *);
void minusculo(char *);
/* ---------- fim funcoes de entradas ---------- */

/* ---------- funcoes de sorteio ---------- */
int sortear_numero(int);
int verifica_sort(int, int *);
int sortear_elemento(int *, int);
int verifi_existe_sort(int *, int, int);
void sortear_sequencia(int *, int, int );
void limpar_sequencia(int *, int);
/* ---------- fim funcoes de sorteio ---------- */

/* ---------- funcoes de pontuacao ---------- */
int arredondar(int, int);
int resposta_repetida(struct Jogador *, char *, int);
void pontuacao_Resposta(struct Jogador *, int, int, int *);
void somatorio_Pontucao(struct Jogador *, int , int);
/* ---------- fim funcoes de pontuacao ---------- */

/* ---------- funcoes de output ---------- */
void mostrar_resultado(struct Jogador *, int, int *, char **, int);
void limpar_tela();
int ganhador(struct Jogador *, int);
/* ---------- fim funcoes de output ---------- */

// rodar o jogo
void rodar_jogo();













