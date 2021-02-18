#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Jogador{
    char nome[12];
    char resposta[30];
    int tempo_resposta;
    int pontos[5];
    int pontos_totais;
    int tempo_total;
};

struct Jogador *criar_jogadores(int tamanho){
    struct Jogador *jog = (struct Jogador*)malloc(tamanho* sizeof(struct Jogador));
    return jog;
}

char **criar_matriz(int tamanho_x, int tamanho_y){
    char **matriz = (char**)malloc((tamanho_x) * sizeof(char));
    for(int i = 0; i<tamanho_x * tamanho_y; i++){ 
      matriz[i] = (char*)malloc(tamanho_y * sizeof(char));
    }
    return matriz;
}

void liberar_vetor(struct Jogador *mem){
    free(mem);
}

int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho++] != '\0');
    return tamanho;
}

int validar_string(char *string){ //verifica se o numero de jogadores digitado é valido
  int cont = 0; 
  for (int i = 0; i < contar_Caractere(string) - 1 ; i++){
    if (!isdigit(string[i])){
      return 1;
    }
  }
  return 0;
}

int num_jogadores(){
  char str_jogadores[3];//numero de jogadores em char
  printf("Digite o numero de jogadores: "); // numero de jogadores deve ser maior q 10 e menor q 2;
  scanf("%s", str_jogadores); //Numero de jogadores
  while (validar_string(str_jogadores) == 1){
    printf("Numero invalido! Digite novamente:");
    scanf("%s",str_jogadores);
  }
  int numero_de_jogadores = atoi(str_jogadores); //se o numero for valido, convertemos para inteiro 
  while ((numero_de_jogadores < 2)||(numero_de_jogadores>10)) {
      printf("Numero de jogadores invalido!\nDigite novamente: ");
      scanf("%d",&numero_de_jogadores);
  }
  return numero_de_jogadores;
}

void jogadores(struct Jogador *jogador, int num_jogadores){
  for(int i = 0; i < num_jogadores ; i++){
      printf("Qual eh o nome do jogador %d: ",i+1);
      scanf("%s", jogador[i].nome);

	  while((contar_Caractere(jogador[i].nome) > 12) || (contar_Caractere(jogador[i].nome) == 0)) {
		  printf("Nome muito longo! \nDigite o nome do jogador %d novamente:",i+1);
		  scanf("%s", jogador[i].nome);
	  }
  }
}

int resposta_repetida(struct Jogador *jogador, char *resposta, int num_jogadores){
  int repetidas = 0;
  for(int i = 0; i<num_jogadores; i++){
    printf("%s %s\n", resposta, jogador[i].resposta);
    if(!strcmp (resposta,jogador[i].resposta)){
      repetidas++;
    }
  }
  return repetidas;
}


void resposta(char *resposta, char letra_Atual){
    printf("Resposta ");
    scanf("%s", resposta);

    int str_tamanho = contar_Caractere(resposta);
    while(str_tamanho > 30 || str_tamanho == 0 || tolower(resposta[0]) != letra_Atual){
        printf("Resposta Inválida! Digite uma resposta válida: ");
        scanf("%s", resposta);
    }
}

int main(){ 
  int qtd_jogadores = num_jogadores();
  //char **pt_nome_pl = criar_matriz(qtd_jogadores, 12);
  struct Jogador *players = criar_jogadores(qtd_jogadores);
  jogadores(players, qtd_jogadores);
  for(int i = 0; i < qtd_jogadores; i++){
    resposta(players[i].resposta, 'a');
    printf("%d\n", resposta_repetida(players, players[i].resposta, i));
  }
  for(int i = 0; i < qtd_jogadores; i++){
     // printf("%s\n", players[i].resposta);
  }
  liberar_vetor(players);
}