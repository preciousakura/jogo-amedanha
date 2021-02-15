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
    srand(time(NULL));
    int sorteado = rand() % range;
    return sorteado;
}

void sortear_categoria(char **categorias, char **nulo){

    int sorteio = sortear_numero(4);
    while(categorias[sorteio] == nulo[0]){
        sorteio = sortear_numero(5);
    }

    categorias[sorteio] =  nulo[0];
}




int main(int argc, char *argv[]){
    char *categorias[5] = {"nome de pessoas", "nomes de cidade", "nomes de comida", "nomes de animais", "profissoes"};
    char *nulo[1] = {"0"};

    int i = 0;
    while(i < 5){
        sortear_categoria(categorias, nulo);
        for(int i = 0; i<5; i++){
            printf("%s\n", categorias[i]);
        }   
        printf("\n");
        i++;
    }


    



    char *pt_res;
    char res[30];
    scanf("%s", &res);
    pt_res = res;


    validacao_Resposta(pt_res, 'a');
    return 0;
}