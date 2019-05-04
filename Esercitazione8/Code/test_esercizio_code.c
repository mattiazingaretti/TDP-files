// Realizzazione con side-effect

#include <stdlib.h>
#include <stdio.h>
#include "correttore_esercizio_code.h"

int main(){

	/* --------------------------------- */
        /*            test codaVuota()       */
	/* --------------------------------- */
	Coda* c1 = codaVuota_soluzione();
	Coda* c2 = codaVuota();
	printf("\n");
	printf("code c1 e c2 uguali? %d\n\n", compareCode(c1,c2));


	/* --------------------------------- */
        /*            test estVuota()        */
	/* --------------------------------- */
	inCoda_soluzione(c1,10);
	printf("la coda c1 è vuota? %d (soluzione), %d\n", estVuota_soluzione(c1), estVuota(c1) );
        printf("la coda c2 è vuota? %d (soluzione), %d\n\n", estVuota_soluzione(c2), estVuota(c2) );
	outCoda_soluzione(c1);

	/* --------------------------------- */
        /*            test inCoda()          */
	/* --------------------------------- */
	inCoda_soluzione(c1,10);
	inCoda_soluzione(c1,-8);
	inCoda_soluzione(c1,4);
	inCoda(c2,10);
	inCoda(c2,-8);
	inCoda(c2,4);
	printf("c1 =");
	printCoda(c1);
	printf("c2 =");
        printCoda(c2);
	printf("\n");

	/* --------------------------------- */
        /*            test outCoda()         */
	/* --------------------------------- */
	outCoda_soluzione(c1);
	inCoda_soluzione(c1,57);
	outCoda(c2);
	inCoda(c2,57);
	printf("c1 =");
	printCoda(c1);
	printf("c2 =");
        printCoda(c2);
	printf("\n");


}
