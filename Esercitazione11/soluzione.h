#ifndef SOL_H
#define SOL_H

#include "albero_binario.h"
#include "insieme.h"
#include "lista.h"

void scambiaSCL_soluzione(TipoLista* l);

Insieme* nodiNormali_soluzione(TipoAlbero a, int l);

void normalizza_soluzione(TipoAlbero* a);

void tagliaFoglie_soluzione(TipoAlbero* a);

TipoAlbero normalizzaFunzionale_soluzione(TipoAlbero a);

TipoAlbero tagliaFoglieFunzionale_soluzione(TipoAlbero a);

#endif
