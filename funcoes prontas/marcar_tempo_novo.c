#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int marcar_tempo_inicial(){ //t_init = marcar_tempo_inicial()
    struct timeval  inicio;
    gettimeofday(&inicio,NULL);
    int tempo_inicial = inicio.tv_sec;
    return tempo_inicial;
}

int marcar_tempo_final(int t_init){ //t_total = marcar_tempo_final
    struct timeval fim;
    gettimeofday(&fim,NULL);
    int tempo_final = fim.tv_sec - t_init;
    return tempo_final;
}


