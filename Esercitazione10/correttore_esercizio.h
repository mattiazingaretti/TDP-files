#include "esercizio.h"

int ricercaLivello_soluzione(TipoAlbero a, TipoInfoAlbero v, int livello_corrente);
int verificaNodi_soluzione(TipoAlbero a, int livello);
int singleChildSum_soluzione(TipoAlbero a);
TipoListaSCL* listaNodiFoglia_soluzione(TipoAlbero a);
TipoListaSCL* listaNodiFoglia_soluzione_aux(TipoAlbero a, TipoListaSCL* l);
Coda* codaNodiDueFigli_soluzione(TipoAlbero a);
Coda* codaNodiDueFigli_soluzione_aux(TipoAlbero a, Coda* c);
TipoListaSCL* listaPercorso_soluzione(TipoAlbero a);
