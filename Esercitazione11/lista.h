#include <stdio.h>

#ifndef LST_ORD_H
#define LST_ORD_H

typedef int TipoInfoLista;

struct ElemLista{
	TipoInfoLista info;
	struct ElemLista* next;
};

typedef struct ElemLista TipoNodoLista;

typedef TipoNodoLista* TipoLista;

/* restituisce true se lis e' la lista vuota */
int emptyLista(TipoLista lis);

/* restituisce il primo elemento di una lista non vuota */
TipoInfoLista primoLista(TipoLista lis);

/* restituisce la lista privata del primo elemento */
TipoLista restoLista(TipoLista lis);

/* assegna al parametro la lista vuota */
void initLista(TipoLista * lis);

/* modifica la lista aggiungendo l'elemento e in testa*/
void addLista(TipoLista * lis, TipoInfoLista e);

/* verifica se l'elemento e e' presente nella lista l*/
int presente(TipoLista l, TipoInfoLista e);

void stampa(TipoLista lis);


#endif
