#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>

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


int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}

void validacao_Resposta(char *resposta, char letra_Atual){
    int str_tamanho = contar_Caractere(resposta);
    while(str_tamanho > 30 || str_tamanho == 0 || tolower(resposta[0]) != letra_Atual){
        printf("Resposta Inválida! Digite uma resposta válida: ");
        scanf("%s", &(*resposta));
    }
}

int sortear_numero(int range){
    int sorteado = rand() % range;
    return sorteado;
}

int existe(int *sequencia, int valor){
    int i;
    for(i = 0; i<5; i++){
        if(sequencia[i] == valor){
            return 1;
        }
    }
    return 0;
}

void sortear_sequencia(int *sequencia, int tamanho_sequencia){
  int sorteio = sortear_numero(5);
  int i = 0;

    for(int i = 0; i < tamanho_sequencia; i++){
      while(existe(sequencia, sorteio) == 1){
        sorteio = sortear_numero(5); 
    }
      sequencia[i] = sorteio;
    }
}




int main(int argc, char *argv[]){
    int *sequencia = criar_vetor(5);
    char *categorias[5] = {"nome de pessoas", "nomes de cidade", "nomes de comida", "nomes de animais", "profissoes"};
    srand(time(NULL));
    sortear_sequencia(sequencia, 5);

    for(int i = 0; i<5; i++){
      printf("%s\n", categorias[sequencia[i]]);
    }   

    liberar_vetor(sequencia);

    return 0;
}