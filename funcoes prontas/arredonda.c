int arredondar(int pontuacao, int n_jogadores){//pontuacao, numero de jogadores com respostas repetidas; 
    int pont_inteira = pontuacao/n_jogadores;
    float resto =  ((float) pontuacao/(float) n_jogadores) - (pontuacao/n_jogadores);
    if ( resto >= 0.5 ){
        pont_inteira = pont_inteira + 1;
    }
    return pont_inteira;
}