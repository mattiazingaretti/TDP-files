#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ERRORE_InfoAlbero -9999999;

typedef int TipoInfoAlbero;

// SCL ALBERO BINARIO
struct StructAlbero {
	TipoInfoAlbero info;
	struct StructAlbero *destro , *sinistro;
};

typedef struct StructAlbero TipoNodoAlbero;
typedef TipoNodoAlbero *TipoAlbero;

// SCL LISTA
struct TipoListaSCL {
	TipoInfoAlbero value;
	struct TipoListaSCL* next;
};


// SCL CODA
typedef struct {
	TipoInfoAlbero* data; // elemento data[0]: testa della coda
	int size; // dimensione array
	int nelem; // dimensione coda
} Coda;

typedef struct {
    Coda *c;
    int ptr; // indice del prossimo elemento
} IteratoreCoda;



// Funzione fornite per Alberi Binari
TipoAlbero albBinVuoto ();
TipoAlbero creaAlbBin ( TipoInfoAlbero infoRadice , TipoAlbero sx , TipoAlbero dx );
bool estVuoto ( TipoAlbero a );
TipoInfoAlbero radice ( TipoAlbero a );
TipoAlbero sinistro ( TipoAlbero a );
TipoAlbero destro ( TipoAlbero a );

//Funzioni fornite per Liste
TipoListaSCL* creaLista();
TipoListaSCL* listPushFront(TipoListaSCL* l, TipoInfoAlbero info);
int lunghezzaLista(TipoListaSCL* l);
TipoListaSCL* listPushBack(TipoListaSCL* l, TipoInfoAlbero info);
void printList(TipoListaSCL* l);

// Funzioni fornite Code 
Coda* codaVuota();
bool estVuota(Coda* c);
void inCoda(Coda* c, TipoInfoAlbero e);
void outCoda(Coda* c);
TipoInfoAlbero primo(Coda* c);
void printInfo(TipoInfoAlbero e);
void printCoda(Coda* c);

// Funzioni fornite Iteratore coda
IteratoreCoda* creaIteratoreCoda(Coda *ins);
bool hasNext(IteratoreCoda *it);
TipoInfoAlbero next(IteratoreCoda *it);





// FUNZIONI DA IMPLEMENTARE
int ricercaLivello(TipoAlbero a, TipoInfoAlbero v, int livello_corrente);
int verificaNodi(TipoAlbero a, int livello);
int singleChildSum(TipoAlbero a);
TipoListaSCL* listaNodiFoglia(TipoAlbero a);
Coda* codaNodiDueFigli(TipoAlbero a);
TipoListaSCL* listaPercorso(TipoAlbero a);
