#include <stdio.h>
#include <stdlib.h>

int contar_Caractere(char *res){
    int tamanho = 0;
    while(res[tamanho] != '\0'){
        tamanho++;
    }
    return tamanho;
}
int validar_jogadores( char *pont ,char nome_de_jogadores[12][10]){
    
    int N,i = 0;
    printf("Digite o numero de jogadores: "); // numero de jogadores deve ser maior q 10 e menor q 2;
    scanf("%d",&N); //Numero de jogadores

    while ((N < 2)||(N>10)) {
        printf("Numero de jogadores invalido!\nDigite novamente: ");
        scanf("%d",&N);
    }

    for(i = 0; i < N ; i++ )
    {
        
        printf("Qual eh o nome do jogador %d: ",i+1);
        scanf("%s",nome_de_jogadores[i]);
       
            while((contar_Caractere(nome_de_jogadores[i])>12) || (contar_Caractere(nome_de_jogadores[i]) == 0)){
                printf("Nome muito longo! \nDigite o nome do jogador %d novamente:",i+1);
                scanf("%s",&nome_de_jogadores[i]);
                }  
            pont = nome_de_jogadores[i];
            }
    return N;
            }


            //ajuda com ponteiros
            //pedir para digitar o nome novamente;
        
   
     
    

int main(){
    char *pont_para_nome_de_jogadores;
    char nome_de_jogadores[12][10];
    int numero_jogadores;
    numero_jogadores = validar_jogadores(pont_para_nome_de_jogadores , nome_de_jogadores);
    for (int i = 0; i < numero_jogadores ; i++ ){//i menor q tamanho, 5 é teste;
        printf("%s\n",nome_de_jogadores[i]);
    }

}