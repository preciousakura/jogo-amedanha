#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>

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

int existe(int sequencia[], int valor){
    int i;
    for(i = 0; i<5; i++){
        if(sequencia[i] == valor){
            return 1;
        }
    }
    return 0;
}

void sortear_categoria(int sequencia[]){
    int sorteio = sortear_numero(5);
    int i = 0;
    while(i < 5){
        while(existe(sequencia, sorteio) == 1){
            sorteio = sortear_numero(5);
        }
        printf("%d", sorteio);
        sequencia[i] = sorteio; 
        i++;
    }
}




int main(int argc, char *argv[]){
    int sequencia[5] = {-1,-1,-1,-1,-1};
    char *categorias[5] = {"nome de pessoas", "nomes de cidade", "nomes de comida", "nomes de animais", "profissoes"};
    srand(time(NULL));
    sortear_categoria(sequencia);

    for(int i = 0; i<5; i++){
        printf("%d ", sequencia[i]);
    }

    /*
    int i = 0;
    while(i < 5){
        sortear_categoria(categorias, nulo);
        for(int i = 0; i<5; i++){
            printf("%s\n", categorias[i]);
        }   
        printf("\n");
        i++;
    }
*/

    



    char *pt_res;
    char res[30];
    scanf("%s", &res);
    pt_res = res;


    validacao_Resposta(pt_res, 'a');
    return 0;
}