#include <stdio.h>
#include <stdlib.h>

char **criar_matriz(int tamanho_x, int tamanho_y){
    char **matriz = (char**)malloc((tamanho_x * tamanho_y) * sizeof(char));
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

int num_jogadores(){
  int numero_de_jogadores = 0;

    printf("Digite o numero de jogadores: "); // numero de jogadores deve ser maior q 10 e menor q 2;
    scanf("%d", &numero_de_jogadores); //Numero de jogadores

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
  int qtd_jogadores = num_jogadores();
  char **pt_nome_pl = criar_matriz(qtd_jogadores, 12);
  jogadores(pt_nome_pl, qtd_jogadores);

  for(int i = 0; i < qtd_jogadores; i++){
    printf("%s\n", pt_nome_pl[i]);
  }

  liberar_matriz(pt_nome_pl);
}