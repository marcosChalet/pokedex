#include "lista.h"

struct elemento {
	struct pokemon dados;
	struct elemento *prox;
};

struct lista {
	int qtd;
	struct elemento *inicio;
	struct elemento *final;
};


enum tipo pegaTipo (char *tipoPokemon) {
	for (int i = 0; tipoPokemon[i] != '\0'; i++) {
		tipoPokemon[i] = toupper(tipoPokemon[i]);
	}

		 if (strcmp(tipoPokemon, "FIRE"    ) == 0) return FIRE;
	else if (strcmp(tipoPokemon, "NORMAL"  ) == 0) return NORMAL;
	else if (strcmp(tipoPokemon, "WATER"   ) == 0) return WATER;
	else if (strcmp(tipoPokemon, "GRASS"   ) == 0) return GRASS;
	else if (strcmp(tipoPokemon, "FLYING"  ) == 0) return FLYING;
	else if (strcmp(tipoPokemon, "FIGHTING") == 0) return FIGHTING;
	else if (strcmp(tipoPokemon, "POISON"  ) == 0) return POISON;
	else if (strcmp(tipoPokemon, "ELECTRIC") == 0) return ELECTRIC;
	else if (strcmp(tipoPokemon, "GROUND"  ) == 0) return GROUND;
	else if (strcmp(tipoPokemon, "ROCK"    ) == 0) return ROCK;
	else if (strcmp(tipoPokemon, "PSYCHIC" ) == 0) return PSYCHIC;
	else if (strcmp(tipoPokemon, "ICE"     ) == 0) return ICE;
	else if (strcmp(tipoPokemon, "BUG"     ) == 0) return BUG;
	else if (strcmp(tipoPokemon, "GHOST"   ) == 0) return GHOST;
	else if (strcmp(tipoPokemon, "STEEL"   ) == 0) return STEEL;
	else if (strcmp(tipoPokemon, "DRAGON"  ) == 0) return DRAGON;
	else if (strcmp(tipoPokemon, "DARK"    ) == 0) return DARK;
	else if (strcmp(tipoPokemon, "FAIRY"   ) == 0) return FAIRY;
	else return UNDEFINED;
}


char* convEnumTipo (enum tipo tipoPokemon) {

	switch (tipoPokemon) {
		case FIRE: 		return "Fire";
		case NORMAL: 	return "Normal";
		case WATER: 	return "Water";
		case GRASS:		return "Grass";
		case FLYING: 	return "Flying";
		case FIGHTING: 	return "Fighting";
		case POISON: 	return "Poison";
		case ELECTRIC: 	return "Eletric";
		case GROUND: 	return "Ground";
		case ROCK: 		return "Rock";
		case PSYCHIC: 	return "Psychic";
		case ICE: 		return "Ice";
		case BUG: 		return "Bug";
		case GHOST: 	return "Ghost";
		case STEEL: 	return "Stell";
		case DRAGON: 	return "Dragon";
		case DARK: 		return "Dark";
		case FAIRY: 	return "Fairy";
		case UNDEFINED: return " ";
	}
}


char* conLendarioStr (int val) {
	if (val == 0) return "False";
	else return "TRUE";
}


int lendarioConv (char *lendario) {
	if (strcmp(lendario, "True") == 0) return 1;
	else return 0;
}


void criaLista (Pokedex lstPokemon) {
	for (int i = 0; i < QTD_TIPOS; i++) {
		lstPokemon[i] = (struct lista*)malloc(sizeof(struct lista));
		if (lstPokemon[i] != NULL) {
			lstPokemon[i]->inicio = NULL;
			lstPokemon[i]->final  = NULL;
			lstPokemon[i]->qtd = 0;
		}
	}
}


void liberaPokedex (Pokedex pokedex) {

	Elemento *aux;
	for (int i = 0; i < QTD_TIPOS; i++) {
		while (pokedex[i]->inicio != NULL) {
			aux = pokedex[i]->inicio;
			pokedex[i]->inicio = pokedex[i]->inicio->prox;
			free(aux->dados.nome);
			free(aux);
		}
		pokedex[i]->qtd = 0;
	}
}


int listaVazia(Lista lstPokemon) {
	if (lstPokemon == NULL)
		return -1;
	if (lstPokemon->inicio == NULL)
		return 1;
	else return 0;
}


int inserePokemon (Lista lstPokemon, struct pokemon novosDados) {

	if(listaVazia(lstPokemon) == -1)
		return 0;

	Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
	if (novo == NULL) return 0;

	novo->dados = novosDados;

	if (listaVazia(lstPokemon) == 1 || lstPokemon->inicio->dados.score_total > novosDados.score_total) {
		novo->prox = lstPokemon->inicio;
		lstPokemon->inicio = novo;
		lstPokemon->final  = novo;
		lstPokemon->qtd++;
		return 1;
	}

	Elemento *ant = lstPokemon->inicio;
	Elemento *aux = ant->prox;

	while (aux != NULL && aux->dados.score_total < novosDados.score_total) {
		ant = ant->prox;
		aux = aux->prox;
	}

	ant->prox = novo;
	novo->prox = aux;
	lstPokemon->qtd++;

	return 1;
}


int buscaPokemon (Pokedex pokedex, int id, struct pokemon *saida) {

	Elemento *aux = NULL;
	for (int i = 0; i < QTD_TIPOS; i++) {

		if (listaVazia(pokedex[i]) == 1)
			continue;

		aux = pokedex[i]->inicio;

		while (aux != NULL && aux->dados.id != id)
			aux = aux->prox;

		if (aux != NULL)
			break;
	}

	if (aux == NULL) {
		return 0;
	}
	
	*saida = aux->dados;

	return 1;
}


void imprimePokemon(struct pokemon *pokemon) {

	if(pokemon->id == -1) return;

	printf(" **********************************\n");
	printf(" * Nome: %-25s*\n", pokemon->nome);
	printf(" * ID: %-27d*\n", pokemon->id);
	printf(" * Tipo1: %-24s*\n", convEnumTipo(pokemon->tipo1));
	printf(" * Tipo2: %-24s*\n", convEnumTipo(pokemon->tipo2));
	printf(" * HP: %-27d*\n", pokemon->hp);
	printf(" * Ataque: %-23d*\n", pokemon->ataque);
	printf(" * Defesa: %-23d*\n", pokemon->defesa);
	printf(" * Ataque ESP: %-19d*\n", pokemon->ataque);
	printf(" * Defesa ESP: %-19d*\n", pokemon->defesa);
	printf(" * Velocidade: %-19d*\n", pokemon->velocidade);
	printf(" * Geração: %-22d*\n", pokemon->geracao);
	printf(" * Lendário: %-21s*\n", conLendarioStr(pokemon->lendario));
	printf(" **********************************\n\n");
}


int imprimePorTipo (Lista lstPokemon) {

	if (listaVazia(lstPokemon)) return 0;

	Elemento *aux = lstPokemon->inicio;
	Elemento *proxEl = aux->prox;

	while (proxEl != NULL) {

		printf(" **********************************    **********************************\n");
		printf(" * Score Total: %-18d*    * Score Total: %-18d*\n", aux->dados.score_total, proxEl->dados.score_total);
		printf(" * Nome: %-25s*    * Nome: %-25s*\n", aux->dados.nome, proxEl->dados.nome);
		printf(" * ID: %-27d*    * ID: %-27d*\n", aux->dados.id, proxEl->dados.id);
		printf(" * Tipo1: %-24s*    * Tipo1: %-24s*\n", convEnumTipo(aux->dados.tipo1), convEnumTipo(proxEl->dados.tipo1));
		printf(" * Tipo2: %-24s*    * Tipo2: %-24s*\n", convEnumTipo(aux->dados.tipo2), convEnumTipo(proxEl->dados.tipo2));
		printf(" * HP: %-27d*    * HP: %-27d*\n", aux->dados.hp, proxEl->dados.hp);
		printf(" * Ataque: %-23d*    * Ataque: %-23d*\n", aux->dados.ataque, proxEl->dados.ataque);
		printf(" * Defesa: %-23d*    * Defesa: %-23d*\n", aux->dados.defesa, proxEl->dados.defesa);
		printf(" * Ataque ESP: %-19d*    * Ataque ESP: %-19d*\n", aux->dados.ataque, proxEl->dados.ataque_esp);
		printf(" * Defesa ESP: %-19d*    * Defesa ESP: %-19d*\n", aux->dados.defesa, proxEl->dados.defesa_esp);
		printf(" * Velocidade: %-19d*    * Velocidade: %-19d*\n", aux->dados.velocidade, proxEl->dados.velocidade);
		printf(" * Geração: %-22d*    * Geração: %-22d*\n", aux->dados.geracao, proxEl->dados.geracao);
		printf(" * Lendário: %-21s*    * Lendário: %-21d*\n", conLendarioStr(aux->dados.lendario), conLendarioStr(proxEl->dados.lendario));
		printf(" **********************************    **********************************\n\n");

		aux = proxEl->prox;
		if (proxEl->prox == NULL)
			break;
		proxEl = proxEl->prox->prox;
	}

	if (aux != NULL) {
		printf(" **********************************\n");
		printf(" * Nome: %-25s*\n", aux->dados.nome);
		printf(" * ID: %-27d*\n", aux->dados.id);
		printf(" * Tipo1: %-24s*\n", convEnumTipo(aux->dados.tipo1));
		printf(" * Tipo2: %-24s*\n", convEnumTipo(aux->dados.tipo2));
		printf(" * HP: %-27d*\n", aux->dados.hp);
		printf(" * Ataque: %-23d*\n", aux->dados.ataque);
		printf(" * Defesa: %-23d*\n", aux->dados.defesa);
		printf(" * Ataque ESP: %-19d*\n", aux->dados.ataque);
		printf(" * Defesa ESP: %-19d*\n", aux->dados.defesa);
		printf(" * Velocidade: %-19d*\n", aux->dados.velocidade);
		printf(" * Geração: %-22d*\n", aux->dados.geracao);
		printf(" * Lendário: %-21s*\n", conLendarioStr(aux->dados.lendario));
		printf(" **********************************\n\n");
	}
	return 1;
}


int qtd_por_tipo (Lista lstPokemon) {
	return lstPokemon->qtd;
}


int tamanho (Pokedex pokedex) {
	int tamanho = 0;
	for (int i = 0; i < QTD_TIPOS; i++) {
		tamanho += pokedex[i]->qtd;
	}
	return tamanho;
}


int removePokemon (Pokedex pokedex, int id) {

	Elemento *aux, *ant;
	int i;
	for (i = 0; i < QTD_TIPOS; i++) {
		if (listaVazia(pokedex[i]) == 1)
			continue;

		ant = pokedex[i]->inicio;
		aux = ant->prox;
		while (aux != NULL && aux->dados.id != id) {
			ant = ant->prox;
			aux = aux->prox;
		}

		if (aux != NULL)
			break;
	}

	if (aux == NULL) {
		return 0;
	}


	ant->prox = aux->prox;
	free(aux->dados.nome);
	free(aux);
	pokedex[i]->qtd--;

	return 1;
}


int atualizaPokemon (Pokedex pokedex, int id) {

	struct pokemon pokemon, aux;

	if(buscaPokemon(pokedex, id, &pokemon) != 1)
		return 0;

	/* Atualiza o pokemon aqui!!! */
	aux = pokemon;
	aux.nome = malloc(strlen(pokemon.nome)+1);
	if (aux.nome == NULL) {
		perror("Erro de alocação de memória!\n");
		return 0;
	}
	strcpy(aux.nome, pokemon.nome);
	aux.hp = 99999;


	removePokemon(pokedex, pokemon.id);

	pokemon = aux;
	inserePokemon(pokedex[pokemon.tipo1], pokemon);

	return 1;
}