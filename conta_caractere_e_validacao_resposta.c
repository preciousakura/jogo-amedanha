#include <ctype.h>

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
