#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Valore errore di tipo T (per iteratore)
#define TERRORVALUE -999999

typedef int T;

typedef struct {
	T* data; // elemento data[0]: testa della coda
	int size; // dimensione array
	int nelem; // dimensione coda
} Coda;

typedef struct {
    Coda *c;
    int ptr; // indice del prossimo elemento
} IteratoreCoda;

Coda* codaVuota();
int estVuota(Coda* c);
void inCoda(Coda* c, T e);
void outCoda(Coda* c);
T primo(Coda* c);

// Iteratore
IteratoreCoda* creaIteratoreCoda(Coda *ins);
bool hasNext(IteratoreCoda *it);
T next(IteratoreCoda *it);

// Funzioni ausiliarie
void printInfo(T e);
void printCoda(Coda* c);


