#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "esercizio_insiemi.h"



Insieme* intersezione(Insieme* i1, Insieme* i2){
    Insieme *ris = insiemeVuoto();
    IteratoreInsieme *it = creaIteratoreInsieme(i1);
    T value;
    while(hasNext(it)){ 
        value = next(it);
        if (membro(i2,value)) {
            inserisci(ris, value);
        } 
    }
    return ris;
}

Insieme* unione(Insieme* i1, Insieme* i2){
    Insieme *ris = insiemeVuoto();
    IteratoreInsieme *it1 = creaIteratoreInsieme(i1);
    IteratoreInsieme *it2 = creaIteratoreInsieme(i2);
    T value1,value2;
    while(hasNext(it1)){
        value1 = next(it1); 
        inserisci(ris, value1);
    }
    while(hasNext(it2)){
            value2 = next(it2);
            inserisci(ris, value2);
        }
    return ris;
}

bool uguali(Insieme* i1, Insieme* i2){
    IteratoreInsieme *it = creaIteratoreInsieme(i1);
    IteratoreInsieme *it1 = creaIteratoreInsieme(i2);
    while(hasNext(it)){
        T value = next(it);
        if(membro(i2, value) == 0){
            return false;
        }
    }
    while(hasNext(it1)){
        T value1 = next(it1);
        if(membro(i1, value1)== 0){
            return false;
        } 
    }
    return true;
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
    if(p->info != e){
        while (p->next!=NULL && p->next->info!=e ){
        p = p->next;
        }
        if (p->next!=NULL) {
            NodoSCL *q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
    else{
        p = p->next;
        *ins = p;
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




