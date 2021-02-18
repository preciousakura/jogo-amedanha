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


void liberar_jogador(struct Jogador *mem){
    free(mem);
}

int *criar_vetor(int tamanho){
    int *vetor = (int*)malloc(tamanho * sizeof(int));
    for(int i = 0; i<tamanho; i++){
      vetor[i] = -1;
    }
    return vetor;
}

void liberar_vetor(int *mem){
    free(mem);
}

void limpar_tela(){
    system("clear");
}

int tempo(int qtd_de_jogadores, int jogadas_ja_feitas){
    int temp;
    temp = 8 + (2*(qtd_de_jogadores - jogadas_ja_feitas));
    return temp;
}

int tempo_excedido(int tempo_rodada, int tempo){ 
    if (tempo_rodada > tempo) {
        return 1;// tempo excedido, não contaremos a resposta
    }
    else {
        return 0; //tempo limita NÃO foi excedido
    }
}

int marcar_tempo(){
    int tempo_inicial;
    time_t tempo_i;
    tempo_i = clock();
    
    tempo_inicial = (int) (tempo_i) /CLOCKS_PER_SEC;
    return tempo_inicial;
}

int tempo_final(int t_init, int t_final){
    int tempo_total = t_final - t_init;
    return tempo_total;
}

int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

int sortear_numero(int range){
    int sorteado = rand() % range;
    return sorteado;
}

int existe(int *sequencia, int valor, int tam){
    int i;
    for(i = 0; i<tam; i++){
        if(sequencia[i] == valor){
            return 1;
        }
    }
    return 0;
}

void sortear_sequencia(int *sequencia, int tamanho_sequencia, int qtd){
  int sorteio = sortear_numero(qtd);
  int i = 0;

    for(int i = 0; i < tamanho_sequencia; i++){
      while(existe(sequencia, sorteio, qtd) == 1){
        sorteio = sortear_numero(qtd); 
    }
      sequencia[i] = sorteio;
    }
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

void limpar_sequencia(int *sequencia, int tam){
  for(int i = 0; i<tam;i++){
    sequencia[i] = -1;
  }
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
      printf("Digite o nome do jogador %d: ",i+1);
      scanf("%s", jogador[i].nome);

	  while((contar_Caractere(jogador[i].nome) > 12) || (contar_Caractere(jogador[i].nome) == 0)) {
		  printf("Nome invalido! Digite o nome do jogador %d novamente: ",i+1);
		  scanf("%s", jogador[i].nome);
	  }
  }
}

void resposta(char *resposta, char letra_Atual){
    scanf("%s", resposta);

    int str_tamanho = contar_Caractere(resposta);
    while(str_tamanho > 30 || str_tamanho == 0 || tolower(resposta[0]) != letra_Atual){
        printf("Resposta Invalida! Digite uma resposta valida: ");
        scanf("%s", resposta);
    }
}

void rodar_jogo(){
    char *categorias[5] = {"Nome de Pessoa", "Nome de Cidade", "Nome de Comida", "Nome de Animal", "Profissao"};
    const char alfabeto[23] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p','q','r','s','t', 'u', 'v', 'x', 'z'}; 
    int temp_init, temp_fim, temp_total;
    char letraAtual; 
    char *categoriaAtual[18];
    int *letra_sort = criar_vetor(5);
    int *categ_sort = criar_vetor(5);
    sortear_sequencia(letra_sort, 5, 23);
    sortear_sequencia(categ_sort, 5, 5);
    printf("*** JOGO AMEDONHA ***\n\n");
    int qtd_jogadores = num_jogadores();
    int *jog_sort = criar_vetor(qtd_jogadores);
    struct Jogador *jogador = criar_jogadores(qtd_jogadores);
    jogadores(jogador, qtd_jogadores);

    int i, j;
    for(i = 0; i < 5; i++){
        letraAtual = alfabeto[letra_sort[i]];
        categoriaAtual[0] = categorias[categ_sort[i]];
        printf("\nA letra desta rodada e: %c\n", toupper(letraAtual));
        printf("A categoria desta rodada e: %s\n", categoriaAtual[0]);
        sortear_sequencia(jog_sort, qtd_jogadores, qtd_jogadores);
        printf("A ordem desta jogada sera: \n");
        for(j = 0; j < qtd_jogadores; j++){
          printf("  %d. %s\n", j+1, jogador[jog_sort[j]].nome);
        }
        //limpar_tela();
        for(j = 0; j < qtd_jogadores; j++){
          printf("%s, voce deve entrar um \"%s\" em %d segundos: ", jogador[jog_sort[j]].nome, categoriaAtual[0],tempo(qtd_jogadores, j));
          temp_init = marcar_tempo();
          resposta(jogador[jog_sort[j]].resposta, letraAtual);
          temp_fim = marcar_tempo();
          temp_total = tempo_final(temp_init, temp_fim);
          if(tempo_excedido(temp_total, tempo(qtd_jogadores, j))){
            jogador[jog_sort[j]].resposta[0] = '\0';
          }
        }
        limpar_sequencia(jog_sort, qtd_jogadores);
    }
}

int main(){
    srand(time(NULL));
    rodar_jogo();
    return 0;
}