#include "banco.h"

#define NOME_BANCO "pokemon.csv"

int carregaPokedex (Pokedex pokedex) {

	char *campos = (char*)malloc(sizeof(char) * 120);
	struct pokemon pokemon;
	
	FILE *fp = fopen(NOME_BANCO, "r");
	if(fp == NULL) {
		perror("ERRO: A pokedex não foi lida.\n");
		return 0;
	}

	/* Pega a primeira linha com informações da tabela (csv)*/
	fscanf(fp, "%[^\n]s", campos);
	/* Remove o \n do final da primeira linha */
	fscanf(fp, "%[^\n]s", campos);

	/* Pega os dados do csv e coloca na pokedex */
	while(fscanf(fp, " %[^,]s", campos) != EOF) {

		pokemon.id = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.nome = malloc(strlen(campos)+1);
		if(pokemon.nome == NULL) {
			perror("Erro: Memória não alocada.\n");
			return 0;
		}
		strcpy(pokemon.nome, campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.tipo1 = pegaTipo(campos);

		fscanf(fp, ",%[^,]s", campos);
		if(pegaTipo(campos) == pokemon.tipo1) {
			strcpy(campos, "UNDEFINED");
		}
		pokemon.tipo2 = pegaTipo(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.score_total = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.hp = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.ataque = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.defesa = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.ataque_esp = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.defesa_esp = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.velocidade = atoi(campos);

		fscanf(fp, ",%[^,]s", campos);
		pokemon.geracao = atoi(campos);

		fscanf(fp, ",%[^\n]s", campos);
		pokemon.lendario = lendarioConv(campos);

		inserePokemon(pokedex[pokemon.tipo1], pokemon);

	}
	free(campos);
	fclose(fp);

	return 1;
}