#ifndef ALB_BIN
#define ALB_BIN

#include <stdio.h>
#include <stdlib.h>

#define ERRORE_InfoAlbBin -99999
typedef int TipoInfoAlbero;

typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero infoRadice,TipoAlbero sx,TipoAlbero dx);
bool estVuoto(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);


// Funzioni ausiliarie
TipoNodoAlbero* nodoalb_alloc(TipoInfoAlbero e);
void stampa_parentetica(TipoAlbero a);
void StampaAlbero(const char* astr, TipoAlbero a);
void LeggiParentesi(FILE *file_albero);
TipoAlbero LeggiSottoAlbero(FILE *file_albero);

TipoAlbero LeggiAlbero(char *nome_file);
int size(TipoAlbero a);
int profondita(TipoAlbero a);

#endif
