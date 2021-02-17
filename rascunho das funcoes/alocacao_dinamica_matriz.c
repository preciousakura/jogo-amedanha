#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char **criar_matriz(int tamanho_x, int tamanho_y){
    char **matriz = (char**)malloc((tamanho_x) * sizeof(char));
    for(int i = 0; i<tamanho_x * tamanho_y; i++){ 
      matriz[i] = (char*)malloc(tamanho_y * sizeof(char));
    }
    return matriz;
}

void liberar_matriz(char **mem){
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

void jogadores(char **nome_de_jogadores, int num_jogadores){
  for(int i = 0; i < num_jogadores ; i++){
      printf("Qual eh o nome do jogador %d: ",i+1);
      scanf("%s", nome_de_jogadores[i]);

	  while((contar_Caractere(nome_de_jogadores[i]) > 12) || (contar_Caractere(nome_de_jogadores[i]) == 0)) {
		  printf("Nome muito longo! \nDigite o nome do jogador %d novamente:",i+1);
		  scanf("%s", nome_de_jogadores[i]);
	  }
  }
}


int main(){

  struct Jogador{
    char nome[12];
    int pontos[5];
    int pontos_totais;
    int tempo_total;
  };
  int qtd_jogadores = num_jogadores();
  char **pt_nome_pl = criar_matriz(qtd_jogadores, 12);
  jogadores(pt_nome_pl, qtd_jogadores);

  for(int i = 0; i < qtd_jogadores; i++){
    printf("%s\n", pt_nome_pl[i]);
  }

  liberar_matriz(pt_nome_pl);
}