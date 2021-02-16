#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int marcar_tempo(){
    int tempo_inicial;
    time_t tempo_i;
    tempo_i = clock();
    
    tempo_inicial = (int) (tempo_i) /CLOCKS_PER_SEC;
    return tempo_inicial;

}


int main() {
    int t_init,t_final,i;
    t_init = marcar_tempo();
    scanf("%d",&i);
    t_final = marcar_tempo();
    int tempo_total = t_final - t_init;
    printf("Tempo total: %d",tempo_total);
    
    return 0;

}