#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "esercizio_insiemi.h"



Insieme* intersezione(Insieme* i1, Insieme* i2){
  if(estVuoto(i1)){ return i1;}
  if(estVuoto(i2)){ return i2;}
  //Gestiti i casi di ins vuoti
  IteratoreInsieme *r = creaIteratoreInsieme(i1);
  do{
	  T value = next(r);
	  printf("%d\n" ,membro(i2, value));
	  if(!membro(i2, value)){
		elimina(i1, value);
	  }  
  }while(hasNext(r));
  return i1;
}

Insieme* unione(Insieme* i1, Insieme* i2){
  // Da implementare
  return i1;
}

bool uguali(Insieme* i1, Insieme* i2){
  // Da implementare
  return false;
}


void stampa(Insieme* ins, const char *name) {
    printf("%s = { ",name);
    IteratoreInsieme* it = creaIteratoreInsieme(ins);
    while (hasNext(it)) {
        T e = next(it);
        printf("%d ", e);
    }
    printf("} \n");
}

// O(1)
Insieme* insiemeVuoto() {
  Insieme* r = (Insieme*) malloc(sizeof(Insieme*));
  *r = NULL;
  return r;
}

// O(1)
bool estVuoto(Insieme* ins) {
    return *ins == NULL;
}

// O(n)
void inserisci(Insieme *ins, T e) {
    if (!membro(ins,e)) {
        NodoSCL* n = (NodoSCL*) malloc(sizeof(NodoSCL));
        n->info = e;
        n->next = *ins;
        *ins = n;
    }
}

// O(n)
void elimina(Insieme *ins, T e) {
    NodoSCL* p = *ins;
    while (p->next!=NULL && p->next->info!=e)
        p = p->next;
    if (p->next!=NULL) {
        NodoSCL *q = p->next;
        p->next = p->next->next;
        free(q);
    }
}

// O(n)
bool  membro(Insieme* ins, T e) {
    NodoSCL* p = *ins;
    while (p!=NULL) {
        if (p -> info == e){
          return true;
        }
        p = p->next;
    }
    return false;
}

// O(1)
IteratoreInsieme* creaIteratoreInsieme(Insieme* ins) {
  IteratoreInsieme* r = (IteratoreInsieme*) malloc(sizeof(IteratoreInsieme));
  *r = *ins;
  return r;
}

// O(1)
bool hasNext(IteratoreInsieme* it) {
    return *it!=NULL;
}

// O(1)
T next(IteratoreInsieme *it) {
    T r = TERRORVALUE;
    if (*it!=NULL) {
        r = (*it)->info;
        *it = (*it)->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}




