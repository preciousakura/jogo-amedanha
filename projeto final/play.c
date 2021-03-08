#include "jogo.h"

void rodar_jogo() {
	char *categorias[5] = {"Nome de Pessoa", "Nome de Cidade", "Nome de Comida", "Nome de Animal", "Profissao"}; // vetor de categorias
	char alfabeto[23] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Z'}; // vetor de letras

	printf("*** JOGO AMEDONHA ***\n\n");
	int qtd_jogadores = num_jogadores(); // numero de jogadores

	int temp_init, temp_fim, temp_total; // variaveis de tempo

	char letraAtual; // letra da rodada
	char *categoriaAtual[18]; // categoria da rodada

	// guardar sequencia de sorteios 
	int *letra_sort = criar_vetor(23); // sequencia de letras já sorteadas (indice)
	int *categ_sort = criar_vetor(5); // sequencia de categorias já sorteadas (indice)
	int *jog_sort = criar_vetor(qtd_jogadores); // ordem de jogadas dos jogadores

	struct Jogador *jogador = criar_jogadores(qtd_jogadores); // vetor de jogadores
	jogadores(jogador, qtd_jogadores); // nome dos jogadores

	sortear_sequencia(categ_sort, 5, 5); // sorteia a sequencia sorteada de categorias

	int i, j;

	for (i = 0; i < 5; i++) { // roda o numero de rodadas (5)
		letraAtual = alfabeto[sortear_elemento(letra_sort, 23)]; // sorteia a letra da rodada
		printf("\nA letra desta rodada e: %c\n", letraAtual);

		categoriaAtual[0] = categorias[categ_sort[i]]; // categoria da rodada (que já foi sorteada na linha 23)
		printf("A categoria desta rodada e: %s\n", categoriaAtual[0]);

		sortear_sequencia(jog_sort, qtd_jogadores, qtd_jogadores); // sorteia a ordem dos jogadores
		printf("A ordem desta jogada sera: \n");
		for (j = 0; j < qtd_jogadores; j++) // percorre o vetor de jogadores
			printf("  %d. %s\n", j + 1, jogador[jog_sort[j]].nome); // mostra a ordem sorteada dos jogadores
		

    	printf("\nTecle [Enter] para iniciar a rodada: ");
		getchar();
		limpar_tela();

		for (j = 0; j < qtd_jogadores; j++) { // percorre o vetor de jogadores
			printf("%s, voce deve entrar um \"%s\" com a letra \"%c\" em %d segundos: ", jogador[jog_sort[j]].nome, categoriaAtual[0], letraAtual,tempo_jogador(qtd_jogadores, j));

			temp_init = marcar_tempo(); // marca o tempo inicial
			resposta(jogador[jog_sort[j]].resposta, letraAtual); // lê a resposta do jogador e valida
			if(categoriaAtual[0] == categorias[0]) // se a categoria atual for "Nome de Jogadores" faz a manutenção de nome composto
				validacao_Nome_de_Pessoa(jogador[jog_sort[j]].resposta);

			temp_total = tempo_final(temp_init); // tempo que levou para digitar a resposta
      		somatorio_tempo(jogador,temp_total, jog_sort[j]); // soma o tempo
			if (tempo_excedido(temp_total, tempo_jogador(qtd_jogadores, j))) // se tiver excedido o tempo, invalida a resposta do jogador
				jogador[jog_sort[j]].resposta[0] = '\0';
			
			minusculo(jogador[jog_sort[j]].resposta); // transforma a resposta em minusculo
			limpar_tela(); // limpa a tela
		}
		
		printf("Jogadas realizadas:\n");
		for (j = 0; j < qtd_jogadores; j++) { // percorre o vetor de jogadores
      		printf("%-12s ", jogador[j].nome); // mostra as respostas das rodadas
			// tratamento para respostas invalidadas
      		if(contar_Caractere(jogador[j].resposta) == 0) 
        		printf("-> -\n");
      		else 
				printf("-> %s\n", jogador[j].resposta);
		}

		pontuacao_Resposta(jogador, qtd_jogadores, categ_sort[i], jog_sort); // calcula pontuacao da rodada 
    	somatorio_Pontucao(jogador, categ_sort[i], qtd_jogadores); // somatorio dos pontos de cada jogador
		mostrar_resultado(jogador, i, categ_sort, categorias, qtd_jogadores); // mostra os resultados da rodada
		limpar_sequencia(jog_sort, qtd_jogadores); // reinicia a sequencia que guarda a ordem dos jogadores
	}

  printf("\nO ganhador e: %s", jogador[ganhador(jogador, qtd_jogadores)].nome); // mostra o ganhador da partida
  // liberação da memória
  liberar_vetor(letra_sort); 
  liberar_vetor(categ_sort);
  liberar_vetor(jog_sort);
  liberar_jogador(jogador);
}
