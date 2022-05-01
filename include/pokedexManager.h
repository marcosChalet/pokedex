#ifndef POKEDEXMANAGER_H
#define POKEDEXMANAGER_H

#include "banco.h"
#include "cpokedex.h"

int  menu ();
void qtdTipo (Pokedex);
void tamanhoPokedex (Pokedex);
void imprimeTipos ();
int  pegaDadosPokemon (Pokedex, struct pokemon *, int);
int  insere(Pokedex);
void busca(Pokedex);
void atualiza (Pokedex);
void removePkm (Pokedex);
void imprime (Pokedex);

#endif