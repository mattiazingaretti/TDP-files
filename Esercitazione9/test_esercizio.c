// Realizzazione con side-effect

#include <stdlib.h>
#include <stdio.h>
#include "correttore_esercizio.h"

int main(){

	/* Creazione albero binario:   */
	/*		 1	       */
	/*	     /       \	       */
	/*	   -9         4	       */
	/*	  /   \     /    \     */
	/*	 5    -2   6     -1    */
	TipoAlbero A = creaAlbBin( 5  , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero B = creaAlbBin( -2 , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero C = creaAlbBin( 6  , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero D = creaAlbBin( -1 , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero E = creaAlbBin( -9 , A, B);
	TipoAlbero F = creaAlbBin( 4  , C, D);
	TipoAlbero G = creaAlbBin( 1  , E, F);
	TipoAlbero albero = G;

	/* ---------------------------------------------- */
        /*            test DimensioneAlbero()             */
	/* ---------------------------------------------- */
	printf("\ndimensione studente %d, dimensione soluzione %d\n\n", DimensioneAlbero(albero), DimensioneAlbero_soluzione(albero));

	/* ---------------------------------------------- */
        /*            test TrovaMassimo()                 */
	/* ---------------------------------------------- */
	printf("massimo valore studente %d, massimo valore soluzione %d\n\n", TrovaMassimo(albero), TrovaMassimo_soluzione(albero));

	/* ---------------------------------------------- */
        /*            test contaFraMinMax()               */
	/* ---------------------------------------------- */
	printf("contaFraMinMax studente %d, contaFraMinMax soluzione %d\n\n", contaFraMinMax(albero, -3, 4), contaFraMinMax_soluzione(albero, -3, 4));

	/* ---------------------------------------------- */
        /*            test sommaValoriFoglie()            */
	/* ---------------------------------------------- */
	printf("sommaValoriFoglie studente %d, sommaValoriFoglie soluzione %d\n\n", sommaValoriFoglie(albero), sommaValoriFoglie_soluzione(albero));

	/* ---------------------------------------------- */
        /*            test visitaAlberoBinarioRicerca()   */
	/* ---------------------------------------------- */
	
	//Creo un caZzo di albero binario di ricerca...
	/* Creazione albero binario:   */
	/*		 1	       */
	/*	     /       \	       */
	/*	   -2         5	       */
	/*	  /   \     /    \     */
	/*	 -9    -1   4     6    */
	TipoAlbero A2 = creaAlbBin( -9  , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero B2 = creaAlbBin( -1 , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero C2 = creaAlbBin( 4  , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero D2 = creaAlbBin( 6 , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero E2 = creaAlbBin( -2, A2, B2);
	TipoAlbero F2 = creaAlbBin( 5  , C2, D2);
	TipoAlbero G2 = creaAlbBin( 1  , E2, F2);
	TipoAlbero albero2 = G2;
	
	printf("visitaAlberoBinarioRicerca studente\n");
	visitaAlberoBinarioRicerca(albero2);
	printf("visitaAlberoBinarioRicerca soluzione\n");
	visitaAlberoBinarioRicerca_soluzione(albero2);
	printf("\n");

}
