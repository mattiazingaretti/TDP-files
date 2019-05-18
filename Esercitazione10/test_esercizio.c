// Realizzazione con side-effect

#include <stdlib.h>
#include <stdio.h>
#include "correttore_esercizio.h"

int main(){

	/* Creazione albero binario:   */
	/*		 13	       */
	/*	     /       \	       */
	/*	    7        32	       */
	/*	  /   \         \      */
	/*	 -2    8         40    */
	/*              \       /      */
	/*               11    36      */

	TipoAlbero A = creaAlbBin( 11  , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero B = creaAlbBin( 36 , albBinVuoto(), albBinVuoto() ) ;

	TipoAlbero C = creaAlbBin( -2 , albBinVuoto(), albBinVuoto() ) ;
	TipoAlbero D = creaAlbBin( 8 , albBinVuoto(), A);
	TipoAlbero E = creaAlbBin( 40  , B, albBinVuoto());

	TipoAlbero F = creaAlbBin( 7 , C, D);
	TipoAlbero G = creaAlbBin( 32  , albBinVuoto(), E);

	TipoAlbero H = creaAlbBin( 13  , F, G);
	TipoAlbero albero = H;

	/* ---------------------------------------------- */
        /*            test ricercaLivello()               */
	/* ---------------------------------------------- */
	printf("\nricercaLivello studente %d, ricercaLivello soluzione %d\n\n", ricercaLivello(albero, 7, 0), ricercaLivello_soluzione(albero, 7, 0 ));
	printf("ricercaLivello studente %d, ricercaLivello soluzione %d\n\n", ricercaLivello(albero, 36, 0), ricercaLivello_soluzione(albero, 36, 0 ));

	/* ---------------------------------------------- */
        /*            test verificaNodi()                 */
	/* ---------------------------------------------- */
	printf("verificaNodi studente %d, verificaNodi soluzione %d\n\n", verificaNodi(albero, 0), verificaNodi_soluzione(albero, 0));

	/* ---------------------------------------------- */
        /*            test singleChildSum()               */
	/* ---------------------------------------------- */
	printf("singleChildSum studente %d, singleChildSum soluzione %d\n\n", singleChildSum(albero), singleChildSum_soluzione(albero));

	/* ---------------------------------------------- */
        /*            test listaNodiFoglia()              */
	/* ---------------------------------------------- */
	TipoListaSCL* lf1 = listaNodiFoglia(albero);
	TipoListaSCL* lf2 = listaNodiFoglia_soluzione(albero);
	printf("listaNodiFoglia studente: ");
	printList(lf1);
	printf("\n");
	printf("listaNodiFoglia soluzione: ");
	printList(lf2);
	printf("\n");

	/* ---------------------------------------------- */
        /*            test codaNodiDueFigli()             */
	/* ---------------------------------------------- */
	Coda* c1 = codaNodiDueFigli(albero);
	Coda* c2 = codaNodiDueFigli_soluzione(albero);
	printf("\ncodaNodiDueFigli studente: ");
	printCoda(c1);
	printf("codaNodiDueFigli soluzione: ");
	printCoda(c2);
	printf("\n");

	/* ---------------------------------------------- */
        /*            test listaPercorso()                */
	/* ---------------------------------------------- */
	TipoListaSCL* lf3 = listaPercorso(albero);
	TipoListaSCL* lf4 = listaPercorso_soluzione(albero);
	printf("listaPercorso studente: ");
	printList(lf3);
	printf("\n");
	printf("listaPercorso soluzione: ");
	printList(lf4);
	printf("\n");
}
