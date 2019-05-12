#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define ERRORE_InfoAlbero -9999999;

typedef int TipoInfoAlbero;


struct StructAlbero {
	TipoInfoAlbero info;
	struct StructAlbero *destro , *sinistro;
};

typedef struct StructAlbero TipoNodoAlbero;

typedef TipoNodoAlbero *TipoAlbero;



TipoAlbero albBinVuoto ();
TipoAlbero creaAlbBin ( TipoInfoAlbero infoRadice , TipoAlbero sx , TipoAlbero dx );
TipoNodoAlbero * nodoalb_alloc ( TipoInfoAlbero e );

bool estVuoto ( TipoAlbero a );
TipoInfoAlbero radice ( TipoAlbero a );
TipoAlbero sinistro ( TipoAlbero a );
TipoAlbero destro ( TipoAlbero a );

TipoInfoAlbero DimensioneAlbero(TipoAlbero a);
TipoInfoAlbero TrovaMassimo(TipoAlbero a);
TipoInfoAlbero contaFraMinMax(TipoAlbero a, const TipoInfoAlbero min, const TipoInfoAlbero max);
TipoInfoAlbero sommaValoriFoglie(TipoAlbero a);
void visitaAlberoBinarioRicerca(TipoAlbero a);
