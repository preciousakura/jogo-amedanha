
void somatorio_tempo(struct Jogador *players, int tempo_rodada, int numero_do_jogador){
    players[numero_do_jogador].tempo_total += tempo_rodada;
}
int tempo_excedido(int tempo_rodada ,int numero_de_jogadores,int jogadas_ja_feitas){ 
    /*jogadas ja feitas é o numero de jogadores que ja jogaram nessa rodada, usamos para calcular o tempo máximo
    Exemplo se numero_de_jogadores = 5, o primeiro jogador terá 8 + 2*(5 - 0) = 18 segundos
    ja o segundo jogador terá 8 + 2*(5 - 1) = 16 segundos e assim em diante
    */
    int tempo_maximo = 8+(2*(numero_de_jogadores - jogadas_ja_feitas)); //formula dada no enunciado
    
    if (tempo_rodada > tempo_maximo) {
        return 1;// tempo excedido, não contaremos a resposta
    }
    else { //caso o tempo da rodada tenha sido menor q o tempo maximo para responder validaremos a resposta
        return 0; //tempo limita NÃO foi excedido
    }
}