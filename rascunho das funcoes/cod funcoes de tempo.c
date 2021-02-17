#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct Jogador{
    char nome[12];
    char resposta[30];
    int pontos[5];
    int pontos_totais;
    int tempo_total;
};



struct Jogador *criar_jogadores(int tamanho){
    struct Jogador *jog = (struct Jogador*)malloc(tamanho* sizeof(struct Jogador));
    return jog;
}

int marcar_tempo(){
    int tempo_inicial;
    time_t tempo_i;
    tempo_i = clock();
    tempo_inicial = (int) (tempo_i) /CLOCKS_PER_SEC;
    return tempo_inicial;
}


void somatorio_tempo(struct Jogador *players,int tempo_inicio, int tempo_final,int numero_do_jogador){
    int tempo_rodada = tempo_final - tempo_inicio;
    players[numero_do_jogador].tempo_total += tempo_rodada;
}
int tempo_excedido(int tempo_inicio ,int tempo_final,int numero_de_jogadores,int jogadas_ja_feitas){ 
    /*jogadas ja feitas é o numero de jogadores que ja jogaram nessa rodada, usamos para calcular o tempo máximo
    Exemplo se numero_de_jogadores = 5, o primeiro jogador terá 8 + 2*(5 - 0) = 18 segundos
    ja o segundo jogador terá 8 + 2*(5 - 1) = 16 segundos e assim em diante
    */
    int tempo_rodada = tempo_final - tempo_inicio;
    int tempo_maximo = 8+(2*(numero_de_jogadores - jogadas_ja_feitas));
    if (tempo_rodada > tempo_maximo){
        return 1;// tempo excedido, não contaremos a resposta
    }
    else{ //caso o tempo da rodada tenha sido menor q o tempo maximo para responder validaremos a resposta
        return 0; //tempo limita NÃO foi excedido
    }
}

char **criar_matriz(int tamanho_x, int tamanho_y){
    char **matriz = (char**)malloc((tamanho_x) * sizeof(char));
    for(int i = 0; i< tamanho_x * tamanho_y; i++){ 
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

int main(){ 
  int qtd_jogadores = num_jogadores();
  int t_init,t_final,tempo_rodada;
  
  char resp[12];//
  //char **pt_nome_pl = criar_matriz(qtd_jogadores, 12);
  struct Jogador *players = criar_jogadores(qtd_jogadores);
  jogadores(players, qtd_jogadores);
  //INICIALIZAR OS TEMPOS COM 0:
  for (int i = 0; i < qtd_jogadores;i++){
      players[i].tempo_total = 0;
  }

  for(int j = 0; j < 2 ; j++) {//2 rodadas neste caso (teste) 
    for(int numero_do_jogador = 0; numero_do_jogador < qtd_jogadores; numero_do_jogador++){
        printf("vez de %s\n", players[numero_do_jogador].nome);
        printf("%s digite uma palavra! Voce tem %d segundos ",players[numero_do_jogador].nome,(8+(2*(qtd_jogadores - numero_do_jogador))));
        t_init = marcar_tempo();
        scanf("%s",resp);
        t_final  = marcar_tempo();

        if(tempo_excedido(t_init,t_final,qtd_jogadores,numero_do_jogador)){
            printf("-tempo excedido-\n");//nao contabilizar pontuação
        }
        else{
            printf("-ok-\n"); //contabilizar a pontuação
        }
        somatorio_tempo(players, t_init , t_final , numero_do_jogador); //i é o numero do jogador;
    }
  }
  for (int i = 0; i < qtd_jogadores ; i++){
      printf("Tempo total %s = %i segundos\n", players[i].nome, players[i].tempo_total);
  }
  liberar_vetor(players);
}