#include "jogo.h"

void rodar_jogo() {
	char *categorias[5] = {"Nome de Pessoa", "Nome de Cidade", "Nome de Comida", "Nome de Animal", "Profissao"};
	char alfabeto[23] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Z'};

	printf("*** JOGO AMEDONHA ***\n\n");
	int qtd_jogadores = num_jogadores(); // numero de jogadores

	int temp_init, temp_fim, temp_total; // variaveis de tempo

	char letraAtual;
	char *categoriaAtual[18];

	// guardar sequencia de sorteios 
	int *letra_sort = criar_vetor(23);
	int *categ_sort = criar_vetor(5);
	int *jog_sort = criar_vetor(qtd_jogadores);

	struct Jogador *jogador = criar_jogadores(qtd_jogadores);
	jogadores(jogador, qtd_jogadores); // nome dos jogadores

	sortear_sequencia(categ_sort, 5, 5);

	int i, j;

	for (i = 0; i < 5; i++) {
		letraAtual = alfabeto[sortear_elemento(letra_sort, 23)];
		printf("\nA letra desta rodada e: %c\n", letraAtual);

		categoriaAtual[0] = categorias[categ_sort[i]];
		printf("A categoria desta rodada e: %s\n", categoriaAtual[0]);

		sortear_sequencia(jog_sort, qtd_jogadores, qtd_jogadores); // ordem de jogadores
		printf("A ordem desta jogada sera: \n");
		for (j = 0; j < qtd_jogadores; j++) {
			printf("  %d. %s\n", j + 1, jogador[jog_sort[j]].nome);
		}

    	printf("\nTecle [Enter] para iniciar a rodada: ");
		getchar();
		limpar_tela();

		for (j = 0; j < qtd_jogadores; j++) {
			printf("%s, voce deve entrar um \"%s\" com a letra \"%c\" em %d segundos: ", jogador[jog_sort[j]].nome, categoriaAtual[0], letraAtual,tempo_jogador(qtd_jogadores, j));

			temp_init = marcar_tempo();
			resposta(jogador[jog_sort[j]].resposta, letraAtual);
			if(categoriaAtual[0] == categorias[0]){
				validacao_Nome_de_Pessoa(jogador[jog_sort[j]].resposta);
			}
			temp_total = tempo_final(temp_init);
      		somatorio_tempo(jogador,temp_total, jog_sort[j]); 
			if (tempo_excedido(temp_total, tempo_jogador(qtd_jogadores, j))) {
				jogador[jog_sort[j]].resposta[0] = '\0';
			}
			minusculo(jogador[jog_sort[j]].resposta);
			limpar_tela();
		}
		
		printf("Jogadas realizadas:\n");
		for (j = 0; j < qtd_jogadores; j++) {
      		printf("%-12s ", jogador[j].nome);
      		if(contar_Caractere(jogador[j].resposta) == 0)
        		printf("-> -\n");
      		else 
				printf("-> %s\n", jogador[j].resposta);
		}

		pontuacao_Resposta(jogador, qtd_jogadores, categ_sort[i], jog_sort);
    	somatorio_Pontucao(jogador, categ_sort[i], qtd_jogadores);
		mostrar_resultado(jogador, i, categ_sort, categorias, qtd_jogadores);
		limpar_sequencia(jog_sort, qtd_jogadores); 
	}

  printf("\nO ganhador e: %s", jogador[ganhador(jogador, qtd_jogadores)].nome);
  liberar_vetor(letra_sort);
  liberar_vetor(categ_sort);
  liberar_vetor(jog_sort);
  liberar_jogador(jogador);
}
