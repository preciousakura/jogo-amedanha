/*
Trabalho Intermediário – Jogo Amedonha
Disciplina Programação (CK0226) – Semestre 2020.2
Equipe: Guilherme Sales Fernandes - 499756
		Isabel Cristina de Oliveira Lopes - 493948
		Matheus Ribeiro Alencar - 494711
		
*/

#include "jogo.h"

/* ---------- funcoes de entradas ---------- */

int contar_Caractere(char *res) { // conta o número de caracteres de uma string
	int tamanho = 0;
	while (res[tamanho] != '\0') 
		tamanho++;
	
	return tamanho;
}

void getString(char *string, int tamanho){ // le uma string com fgets e tira o \n 
	fgets(string, tamanho, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int num_jogadores() { // lê e valida o numero de jogadores
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

void jogadores(struct Jogador *jogador, int num_jogadores) { // lê e valida o nome dos jogadores
	for (int i = 0; i < num_jogadores; i++) {
		printf("Digite o nome do jogador %d: ", i + 1);
		getString(jogador[i].nome, 255);

		while ((contar_Caractere(jogador[i].nome) > 12) || (contar_Caractere(jogador[i].nome) == 0)) {
			printf("Nome invalido! Digite o nome do jogador %d novamente: ", i + 1);
			getString(jogador[i].nome, 255);
		}
	}
}

void resposta(char *resposta, char letra_Atual) { // lê e valida a resposta
	getString(resposta, 255);
	while (contar_Caractere(resposta) > 30 || contar_Caractere(resposta) == 0 || toupper(resposta[0]) != letra_Atual) {
		printf("Resposta Invalida! Digite uma resposta valida: ");
		getString(resposta, 255);
	}
}

void validacao_Nome_de_Pessoa(char *resposta){ // faz manutenção da resposta para a categoria Nome de Pessoa
    resposta[strcspn(resposta, " ")] = '\0'; // acha o espaço da string e o substitui por \0 
}

void minusculo(char *resposta){ // todas as letra da string minúscula
    for (int i = 0; i<contar_Caractere(resposta);i++)
        resposta[i] = tolower(resposta[i]);
}

/* ---------- fim funcoes de entradas ---------- */
