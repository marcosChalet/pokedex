#ifndef CPOKEDEX_H
#define CPOKEDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define QTD_TIPOS 18

enum tipo{
	NORMAL,
	FIRE,
	WATER,
	GRASS,
	FLYING,
	FIGHTING,
	POISON,
	ELECTRIC,
	GROUND,
	ROCK,
	PSYCHIC,
	ICE,
	BUG,
	GHOST,
	STEEL,
	DRAGON,
	DARK,
	FAIRY,
	UNDEFINED
};

struct pokemon {
	char *nome;
	enum tipo tipo1;
	enum tipo tipo2;
	int id;
	int score_total;
	int hp;
	int ataque;
	int defesa;
	int ataque_esp;
	int defesa_esp;
	int velocidade;
	int geracao;
	int lendario;
};

typedef struct lista* Lista;
typedef struct lista** Pokedex;
typedef struct elemento Elemento;

enum  tipo pegaTipo  (char *);
char* convEnumTipo 	 (enum tipo);
char* conLendarioStr (int val);
int   lendarioConv 	 (char *);
void criaLista    	 (Pokedex);
int  listaVazia   	 (Lista);
int  qtd_por_tipo 	 (Lista);
int  tamanho      	 (Pokedex);
void liberaPokedex 	 (Pokedex);
int  inserePokemon 	 (Lista, struct pokemon);
int  buscaPokemon  	 (Pokedex, int, struct pokemon *);
int  atualizaPokemon (Pokedex, int, struct pokemon);
int  removePokemon	 (Pokedex, int);
void imprimePokemon  (struct pokemon *);
int  imprimePorTipo	 (Lista);
int  pegaId 		 (Pokedex);

#endif