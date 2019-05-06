#include "esercizio_code.h"
//Implementazione con side-effect senza condivisione di memoria.
//Mediante SCL.

Coda* codaVuota() {
  Coda *c = (Coda*)malloc(sizeof(Coda));
  c->size = 1;
  c->data = (T*)malloc(sizeof(T)*c->size);
  c->nelem = 0;
  return c;
}

int estVuota(Coda* c) {
  return c->nelem == 0;
}

void inCoda(Coda* c, T e){
  // IMPLEMENTARE
  return;
}

void outCoda(Coda* c){
  // IMPLEMENTARE
  return;
}

T primo(Coda* c){
  if (c->nelem == 0){
    printf("ERRORE: coda vuota");
    exit(1);
  }
	return c->data[0];
}

IteratoreCoda* creaIteratoreCoda(Coda *c) {
    IteratoreCoda *it = (IteratoreCoda *)malloc(sizeof(IteratoreCoda));
    it->c = c;
    it->ptr = 0;
    return it;
}

bool hasNext(IteratoreCoda *it) {
    return it->ptr < it->c->nelem;
}

T next(IteratoreCoda *it) {
    T r = TERRORVALUE;
    if (hasNext(it)) {
        r = it->c->data[it->ptr];
        it->ptr ++;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}

// Implementazione funzioni ausiliarie

void printInfo(T e){
	printf("%d", e);
}

void printCoda(Coda* c){
  if(c == NULL)
  {
	printf(" coda non allocata\n");
	return;
  }
  IteratoreCoda* it = creaIteratoreCoda(c);
  while(hasNext(it)){
    printInfo(next(it));
    printf(" ");    
  }
  printf("\n");
}
