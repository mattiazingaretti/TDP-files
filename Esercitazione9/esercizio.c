#include "esercizio.h"

void sottoTree(TipoAlbero a, TipoInfoAlbero *c){
	if(! estVuoto(sinistro(a))){
		*c += 1;
		sottoTree(sinistro(a), c);
	}
	if(! estVuoto(destro(a))){
		*c += 1;
		sottoTree(destro(a), c);
	}
}

TipoInfoAlbero DimensioneAlbero(TipoAlbero a){
	//Visita in preordine
	TipoInfoAlbero counter = 0;
	if(!estVuoto(a)){
		counter += 1;
	}
	//Inizio i controlli ricorsivi sapendo che l'albero non è vuoto alla radice
	sottoTree(a, &counter);
	return counter;
}

void sottoMassimo(TipoAlbero a , TipoInfoAlbero *m){
	//visita sx radice e poi dx
	if(!estVuoto(sinistro(a))){
		if(radice(sinistro(a)) >= *m){
			*m = radice(sinistro(a));
		}
		sottoMassimo(sinistro(a), m);
	}
	if(!estVuoto(a)){
		if(radice(a) >= *m ){
			*m = radice(a);
		}
	}
	if(!estVuoto(destro(a))){
		if(radice(destro(a)) >= *m){
			*m = radice(destro(a));
		}
		sottoMassimo(destro(a), m);
	}
}

TipoInfoAlbero TrovaMassimo(TipoAlbero a){
	//Provo a implementare una visita simmetrica
	TipoInfoAlbero massimo ;
	if(! estVuoto(a)){
		massimo = radice(a);
	}
	sottoMassimo(a, &massimo);
	return massimo;
}

void postOrdine(TipoAlbero a , const TipoInfoAlbero min , const TipoInfoAlbero max , TipoInfoAlbero *c){
	if(!estVuoto(sinistro(a))){
		if(radice(sinistro(a)) < max && radice(sinistro(a)) > min ){
			*c += 1;
		}
		postOrdine(sinistro(a), min , max , c);
	}
	if(!estVuoto(destro(a))){
		if(radice(destro(a)) < max && radice(destro(a)) > min ){
			*c += 1;
		}
		postOrdine(destro(a), min , max , c);
	}
}

TipoInfoAlbero contaFraMinMax(TipoAlbero a, const TipoInfoAlbero min, const TipoInfoAlbero max){
	//Provo a implementare una visita in post ordine
	TipoInfoAlbero counter = 0;
	if(! estVuoto(a) && radice(a) < max && radice(a) > min){
		counter += 1;
	}	
	postOrdine(a, min , max , &counter);
	return counter;
}

void contaFoglie(TipoAlbero a, TipoInfoAlbero *c){
	if(estVuoto(sinistro(a)) && estVuoto(destro(a))){
		*c += radice(a);	
	}
	if(!estVuoto(sinistro(a))){
		contaFoglie(sinistro(a), c);
	}
	if(!estVuoto(destro(a))){
		contaFoglie(destro(a), c);
	}
}

TipoInfoAlbero sommaValoriFoglie(TipoAlbero a){
	TipoInfoAlbero counter = 0;
	contaFoglie(a, &counter);
	return counter;
}


void visitaAlberoBinarioRicerca(TipoAlbero a){
	if(!estVuoto(sinistro(a))){
		visitaAlberoBinarioRicerca(sinistro(a));
	}
	if(!estVuoto(a)){
		printf("%d ", radice(a));
	}
	if(!estVuoto(destro(a))){
		visitaAlberoBinarioRicerca(destro(a));
	}
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
