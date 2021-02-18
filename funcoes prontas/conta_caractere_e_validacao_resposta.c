#include <ctype.h>

int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
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