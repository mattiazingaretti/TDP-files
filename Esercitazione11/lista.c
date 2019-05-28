#include <stdlib.h>
#include "lista.h"

/* restituisce true se lis e' la lista vuota */
int emptyLista(TipoLista lis){
	return lis == NULL;
}

/* restituisce il primo elemento di una lista non vuota */
TipoInfoLista primoLista(TipoLista lis){
	if (emptyLista(lis)){
		printf("ERRORE: lista vuota!\n");
		exit(1);
	}
	return lis -> info;
}

/* restituisce la lista privata del primo elemento */
TipoLista restoLista(TipoLista lis){
	if (lis != NULL){
		return lis -> next;
	}
	return NULL;
}

/* assegna al parametro la lista vuota */
void initLista(TipoLista * lis){
	*lis = NULL;
}

/* modifica la lista aggiungendo l'elemento e in testa*/
void addLista(TipoLista* lis, TipoInfoLista e){
	TipoNodoLista* n = (TipoNodoLista*) malloc(sizeof(TipoNodoLista));
	n -> info = e;
	n -> next = *lis;
	*lis = n;
	return;
}


/* verifica se l'elemento e e' presente nella lista l*/
int presente(TipoLista l, TipoInfoLista e){
	if (emptyLista(l)){
		return 0;
	}
	if (e == l -> info) {
		return 1;
	}
	if (e < l -> info) {
		return 0;
	}
	return presente(l -> next, e);
}

/* Stampa la lista */
void stampa(TipoLista lis){
	if (lis == NULL){
		printf("\n");
		return;
	}
	printf("%d ",lis -> info);
	stampa(lis -> next);
}
