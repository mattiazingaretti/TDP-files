#ifndef ESRC_H
#define ESRC_H

#include "albero_binario.h"
#include "insieme.h"
#include "lista.h"

void scambiaSCL(TipoLista* l);

Insieme* nodiNormali(TipoAlbero a, int l);

void normalizza(TipoAlbero* a);

void tagliaFoglie(TipoAlbero* a);

TipoAlbero normalizzaFunzionale(TipoAlbero a);

TipoAlbero tagliaFoglieFunzionale(TipoAlbero a);

#endif
