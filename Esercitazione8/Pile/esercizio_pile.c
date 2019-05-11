#include "esercizio_pile.h"

//Scelte implementative:
//rappresentazione con SCL funzionale con condivisione di memoria

Pila pilaVuota() {
	Pila p = (Pila) malloc(sizeof(Pila));
	p->info = 0;
	p->next = NULL;   
	return p;
}

bool estVuota(Pila p) {
	return p==NULL;
}

Pila push(Pila p,T e){
	Pila ris = pilaVuota();
	ris->info = e;
	ris->next = p;
    return ris;
}

Pila pop(Pila p){
	Pila ris = pilaVuota();
	ris->info = p->next->info;
	ris = p->next;
    return ris;
}

T top(Pila p){
	if(p==NULL){
		printf("ERRORE: pila vuota!\n");
		exit(1);
	}
	return p->info;
}

// Funzioni ausiliarie
void printInfo(T e){
	printf("%d", e);
}

