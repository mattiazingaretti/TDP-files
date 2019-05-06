#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#pragma once

typedef int T;

typedef struct NodoSCL {
	T info;
	struct NodoSCL *next;
};

typedef NodoSCL* Pila;
// Il primo nodo della SCL e' l'elemento affiorante

// Funzioni primitive
Pila pilaVuota();
bool estVuota(Pila p);
Pila push(Pila p,T e);
Pila pop(Pila p);
T top(Pila p);

// Funzioni ausiliarie
void printInfo(T e);




