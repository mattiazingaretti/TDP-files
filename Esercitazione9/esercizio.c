#include "esercizio.h"

TipoInfoAlbero DimensioneAlbero(TipoAlbero a){
	// IMPLEMENTARE
	return 0;
}

TipoInfoAlbero TrovaMassimo(TipoAlbero a){
	// IMPLEMENTARE
	return 0;
}

TipoInfoAlbero contaFraMinMax(TipoAlbero a, const TipoInfoAlbero min, const TipoInfoAlbero max){
	// IMPLEMENTARE
	return 0;
}

TipoInfoAlbero sommaValoriFoglie(TipoAlbero a){
	// IMPLEMENTARE
	return 0;
}

void visitaAlberoBinarioRicerca(TipoAlbero a){
	// IMPLEMENTARE
	return;
}


TipoAlbero albBinVuoto () {
	return 0;
}

TipoAlbero creaAlbBin( TipoInfoAlbero infoRadice, TipoAlbero sx, TipoAlbero dx ) {
	TipoAlbero a = ( TipoAlbero ) malloc ( sizeof (TipoNodoAlbero) ) ;
	a->info = infoRadice ;
	a->sinistro = sx ;
	a->destro = dx ;
	return a ;
}

TipoNodoAlbero* nodoalb_alloc ( TipoInfoAlbero e ) {
	TipoNodoAlbero * r = ( TipoNodoAlbero *) malloc ( sizeof (TipoNodoAlbero) ) ;
	r-> info = e ; 
	r-> destro = NULL ; 
	r-> sinistro = NULL ;
	return r ;
}


bool estVuoto ( TipoAlbero a ) {
	return ( a == NULL );
}

TipoInfoAlbero radice ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
		return ERRORE_InfoAlbero;
	}
	else
		return a->info;
}

TipoAlbero sinistro ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
	return NULL;
	}
	else
		return a->sinistro ;
}

TipoAlbero destro ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
		return NULL;
	}
	else
		return a->destro;
}
