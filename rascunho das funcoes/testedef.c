#include <stdio.h>
#include <stdlib.h>

int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}


int validar_jogadores(char *nome_de_jogadores, int linha){
    int numero_de_jogadores;
    int i = 0;
    

    printf("Digite o numero de jogadores: "); // numero de jogadores deve ser maior q 10 e menor q 2;
    scanf("%d", &numero_de_jogadores); //Numero de jogadores

    while ((numero_de_jogadores < 2) || (numero_de_jogadores>10)) {
        printf("Numero de jogadores invalido!\nDigite novamente: ");
        scanf("%d" , &numero_de_jogadores);
    }

    numero_de_jogadores = 5;
    printf("%d",numero_de_jogadores);
    /*
    for(i = 0; i < numero_de_jogadores ; i++){
        
        printf("Qual eh o nome do jogador %d: ",i+1);
        scanf("%s", *nome_de_jogadores[i]);
        while((contar_Caractere(nome_de_jogadores[i]) > 12) || (contar_Caractere(nome_de_jogadores[i]) == 0)){
            printf("Nome muito longo! \nDigite o nome do jogador %d novamente:",i+1);
            scanf("%s", *nome_de_jogadores);
        }  
    }*/
    
    return numero_de_jogadores;
}

int main(){
    int linha = 0;
    char *nome_de_jogadores[12][10];
    int numero_jogadores = validar_jogadores(nome_de_jogadores[linha], linha++);

    for (int i = 0; i < numero_jogadores ; i++ ){//i menor q tamanho, 5 é teste;
        printf("%s\n",nome_de_jogadores[i]);
    }
}