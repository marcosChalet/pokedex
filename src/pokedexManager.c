#include "pokedexManager.h"

int menu () {

	int opcao;
	printf(" =-=-=-=-=-=-=-=-=-= Pokedex =-=-=-=-=-=-=-=-=-=\n");
	printf(" # [0] Sair                                    #\n");
	printf(" # [1] Mostra a quantidade por tipo            #\n");
	printf(" # [2] Mostra o tamanho da pokedex             #\n");
	printf(" # [3] Insere pokemon                          #\n");
	printf(" # [4] Busca pokemon                           #\n");
	printf(" # [5] Atualiza pokemon                        #\n");
	printf(" # [6] Remove pokemon                          #\n");
	printf(" # [7] Imprime por tipo                        #\n");
	printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf(" -> ");
	scanf("%d", &opcao);

	return opcao;
}


void qtdTipo (Pokedex pokedex) {
	for(int i = 0; i < QTD_TIPOS; i++) {
		printf("%-9s = %d\n", convEnumTipo(i), qtd_por_tipo(pokedex[i]));
	}
}


void tamanhoPokedex (Pokedex pokedex) {
	printf("Tamanho: %d\n", tamanho(pokedex));
}


void imprimeTipos () {
	printf("%-20s[ TIPOS DE POKEMONS ]\n","");
	for (int i = 0; i < QTD_TIPOS; i++) {
		printf("[%-7s], ", convEnumTipo(i));
		if((i+1)%6==0) puts("");
	}
	puts("");
}


int pegaDadosPokemon (Pokedex pokedex, struct pokemon *ptPokemon, int novoPkm) {

	struct pokemon pokemon;
	char nome[30], tipo1[30], tipo2[30];

	imprimeTipos();
	
	printf("Entre com o nome do pokemon\n-> ");
	scanf("%s", nome);
	printf("Entre com o Tipo-1 do pokemon\n-> ");
	scanf("%s", tipo1);
	printf("Entre com o Tipo-2 do pokemon\n-> ");
	scanf("%s", tipo2);
	printf("Entre com o HP do pokemon\n-> ");
	scanf("%d", &pokemon.hp);
	printf("Entre com o poder de Ataque do pokemon\n-> ");
	scanf("%d", &pokemon.ataque);
	printf("Entre com o poder de Defesa do pokemon\n-> ");
	scanf("%d", &pokemon.defesa);
	printf("Entre com o poder de Ataque Especial do pokemon\n-> ");
	scanf("%d", &pokemon.ataque_esp);
	printf("Entre com o poder de Defesa Especial do pokemon\n-> ");
	scanf("%d", &pokemon.defesa_esp);
	printf("Entre com a Velocidade do pokemon\n-> ");
	scanf("%d", &pokemon.velocidade);
	printf("Entre com a Geração\n-> ");
	scanf("%d", &pokemon.geracao);
	printf("O pokemon é lendário? [1/0]\n-> ");
	scanf("%d", &pokemon.lendario);


	pokemon.nome = malloc(strlen(nome)+1);
	if(pokemon.nome == NULL) {
		perror("Erro de alocação de memória. Pokemon não inserido!\n");
		return 0;
	}

	strcpy(pokemon.nome, nome);
	pokemon.tipo1 = pegaTipo(tipo1);
	pokemon.tipo2 = pegaTipo(tipo2);

	pokemon.score_total = pokemon.hp + pokemon.ataque +
						  pokemon.defesa + pokemon.ataque_esp +
						  pokemon.defesa_esp + pokemon.velocidade;

	if(novoPkm == 1)
		pokemon.id = pegaId(pokedex);

	*ptPokemon = pokemon;

	return 1;
}


int insere(Pokedex pokedex) {

	struct pokemon pokemon;

	pegaDadosPokemon(pokedex ,&pokemon, 1);

	if (inserePokemon(pokedex[pokemon.tipo1], pokemon) == 0)
		printf("O pokemon não foi inserido!\n");

	return 1;
}


void busca(Pokedex pokedex) {
	int id;
	struct pokemon saida;
	saida.id = -1;

	printf("Entre com o Id do pokemon a ser buscado\n-> ");
	scanf("%d", &id);

	buscaPokemon(pokedex, id, &saida);
	imprimePokemon(&saida);
}


void atualiza (Pokedex pokedex) {

	int id;
	struct pokemon pokemon;

	printf("Qual o Id do pokemon que será alterado?\n-> ");
	scanf("%d", &id);

	pegaDadosPokemon(pokedex, &pokemon, 0);
	atualizaPokemon(pokedex, id, pokemon);
}


void removePkm (Pokedex pokedex) {
	int id;
	printf("Entre com o Id do pokemon a ser removido\n-> ");
	scanf("%d", &id);
	removePokemon(pokedex, id);
}


void imprime (Pokedex pokedex) {
	char tipoStr[30];
	int tipo;

	imprimeTipos();
	printf("Entre com o tipo a ser mostrado\n-> ");
	scanf("%s", tipoStr);

	tipo = pegaTipo(tipoStr);
	imprimePorTipo(pokedex[tipo]);
}