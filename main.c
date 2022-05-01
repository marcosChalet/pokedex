#include "banco.h"
#include "lista.h"

int main () {

	Lista pokedex[QTD_TIPOS];
	criaLista(pokedex);
	carregaPokedex(pokedex);


	for (int i = 0; i < QTD_TIPOS; i++) {
		printf("################################# %s #################################\n\n", convEnumTipo(i));
		imprimePorTipo(pokedex[i]);
	}

/*

	for(int i = 0; i < QTD_TIPOS; i++) {
		printf("%-9s = %d\n", convEnumTipo(i), qtd_por_tipo(pokedex[i]));
	}
	printf("\nTamanho: %d\n", tamanho(pokedex));
	removePokemon(pokedex, 123);
	printf("Tamanho: %d\n", tamanho(pokedex));


	atualizaPokemon(pokedex, 12);

	struct pokemon saida;
	saida.id = -1;
	buscaPokemon (pokedex, 12, &saida);
	imprimePokemon(&saida);
*/

	liberaPokedex(pokedex);

	return 0;
}