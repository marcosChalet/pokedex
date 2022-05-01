#include "pokedexManager.h"
#include <stdbool.h>

int main () {

	Lista pokedex[QTD_TIPOS];
	criaLista(pokedex);
	carregaPokedex(pokedex);

	while(true) {
		switch(menu()) {
			case 1:
				system("clear||cls");
				qtdTipo(pokedex);
				break;
			case 2:
				system("clear||cls");
				tamanhoPokedex(pokedex);
				break;
			case 3:
				system("clear||cls");
				insere(pokedex);
				break;
			case 4:
				system("clear||cls");
				busca(pokedex);
				break;
			case 5:
				system("clear||cls");
				atualiza(pokedex);
				break;
			case 6:
				system("clear||cls");
				removePkm(pokedex);
				break;
			case 7:
				system("clear||cls");
				imprime(pokedex);
				break;
			default: 
				return 0;
		}
	}

	liberaPokedex(pokedex);

	return 0;
}