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
	printf("visitaAlberoBinarioRicerca studente\n");
	visitaAlberoBinarioRicerca(albero);
	printf("visitaAlberoBinarioRicerca soluzione\n");
	visitaAlberoBinarioRicerca_soluzione(albero);
	printf("\n");

}
