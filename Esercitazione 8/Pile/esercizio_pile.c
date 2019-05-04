#include "esercizio_pile.h"

Pila pilaVuota() {
	return NULL;
}

bool estVuota(Pila p) {
	return p==NULL;
}

Pila push(Pila p,T e){
	//Implementare
	return NULL;
}

Pila pop(Pila p){
	// Implementare
	return NULL;
}

T top(Pila p){
	// Implementare
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

