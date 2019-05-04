#include "e7_correttore.h"

int main(int argc, char **argv){


//**************************************************************
//INIZIALIZZAZIONE PARAMETRI

	//alloca matrice di dimensione rows cols
	int rows = 3;
	int cols = 3;
	Mat* m = _Mat_alloc(rows, cols);

	//definisci valori numerici sulle diagonali
	m->row_ptrs[0][0] = 2.0;
	m->row_ptrs[1][1] = 4.0;
	m->row_ptrs[2][2] = 1.0;

	//definisci valori non sulle diagonali
	m->row_ptrs[0][1] = 1.0;
	m->row_ptrs[0][2] = 1.0;
	m->row_ptrs[1][0] = 1.0;
	m->row_ptrs[1][2] = 1.0;
	m->row_ptrs[2][0] = 1.0;
	m->row_ptrs[2][1] = 2.5;

	//inizializza e trasforma stringa in SCL
	char a[10] = "ababdfhy\0";
	TipoNodoSCL* list = createSCLstring(a,9);

	//inizializza array
	float v2[5] = {1.0, 2.0, 3.5, 4.0, 2.5};

	//print di strutture in input
	printf("Matrice in input: \n");
	_Mat_print(m);
	printf("\nSCL in input: \n");
  	printList(list);
	printf("\nArray in input: \n");
	vec_print(v2,5);


//**************************************************************
//ESERCIZIO 7.1
	printf("\n \n*************Esercizio 7.1************* \n\n");
	float* _vec = _Mat_diagonale(m);
	printf("La somma corretta è: %f, il prodotto corretto è: %f\n", _vec[0], _vec[1]);

	//printf("Devo implementare la funzione Mat_diagonale(m)\n\n");
	float* my_vec = Mat_diagonale(m);
	printf("La mia somma è: %f, il mio prodotto è: %f\n", my_vec[0], my_vec[1]);
	printf("\n");

//**************************************************************
//ESERCIZIO 7.2
	printf("*************Esercizio 7.2************* \n\n");
	int k = 2;
	Mat* m_sottofinestra = _Mat_sottoFinestre(m, k);
	printf("Prodotto sottomatrici corretto: \n");
	_Mat_print(m_sottofinestra);

	Mat* my_m_sottofinestra = Mat_sottoFinestre(m, k);
    printf("Mio output \n");
    _Mat_print(my_m_sottofinestra);

//**************************************************************
//ESERCIZIO 7.3
	printf("\n*************Esercizio 7.3************* \n\n");
	char ch1 = 'a';
	char ch2 = 'f';
	int* v = _conta_2chars(list, ch1, ch2);
	printf("\n");

	printf("Devo implementare la funzione conta_2chars(list, ch1, ch2)\n\n");
	int* my_v = conta_2chars(list, ch1, ch2);

//**************************************************************
//ESERCIZIO 7.4
	printf("\n");
	printf("*************Esercizio 7.4************* \n\n");
	printf("Array corretto: \n");
 	float target1 = 3.5;
	_vec_sommaEndTo(v2, 5, target1);
	vec_print(v2,5);

	printf("Devo implementare la funzione _vec_sommaEndTo(v2, 5, target1)\n\n");
	_vec_sommaEndTo(v2, 5, target1);

	return 0;
}
