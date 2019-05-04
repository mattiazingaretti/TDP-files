#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int T;

// Valore errore di tipo T (per iteratore)
#define TERRORVALUE -999999

struct NodoSCL {
    T info;
    struct NodoSCL* next;
};

typedef NodoSCL* Insieme;

typedef Insieme IteratoreInsieme;

// Funzioni primitive del tipo:
Insieme* insiemeVuoto();
bool estVuoto(Insieme *ins);
void inserisci(Insieme *ins, T e);
void elimina(Insieme *ins, T e);
bool membro(Insieme* ins, T e);


Insieme* intersezione(Insieme* i1, Insieme* i2);
Insieme* unione(Insieme* i1, Insieme* i2);
bool uguali(Insieme* i1, Insieme* i2);



void stampa(Insieme* ins, const char *name);

// Iteratore:
IteratoreInsieme* creaIteratoreInsieme(Insieme *ins);
bool hasNext(IteratoreInsieme* it);
T next(IteratoreInsieme *it);


