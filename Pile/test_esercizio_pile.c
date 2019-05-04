#include "correttore_esercizio_pile.h"

int main(){

	Pila p1 = pilaVuota();
	Pila p2 = pilaVuota();

	/* --------------------------------- */
        /*            test push()            */
	/* --------------------------------- */
	p1 = push_soluzione(p1, 4);
	p1 = push_soluzione(p1, -5);
	p1 = push_soluzione(p1, 1);	
	p2 = push(p2, 4);
	p2 = push(p2, -5);
	p2 = push(p2, 1);

	printf("\n");
	printf("pila p1: ");
	printPila(p1);
	printf("pila p2: ");
	printPila(p2);


	/* --------------------------------- */
        /*            test pop()        */
	/* --------------------------------- */
	p1 = pop_soluzione(p1);
	p1 = pop_soluzione(p1);
	p2 = pop(p2);
	p2 = pop(p2);

	printf("\n");
	printf("pila p1: ");
	printPila(p1);
	printf("pila p2: ");
	printPila(p2);

}
