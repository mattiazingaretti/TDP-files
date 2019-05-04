#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "correttore_esercizio_insiemi.h"



int main() {


    Insieme* ins1 = insiemeVuoto();

    inserisci(ins1, 5);
    inserisci(ins1, 7);
    inserisci(ins1, 9);
    stampa(ins1,"ins1");

    Insieme* ins2 = insiemeVuoto();
    inserisci(ins2, 1);
    inserisci(ins2, 3);
    inserisci(ins2, 7);
    inserisci(ins2, 5);
    inserisci(ins2, 4);
    stampa(ins2,"ins2");

    Insieme* ins3_corretto = intersezione_soluzione(ins1,ins2);

    Insieme* ins3 = intersezione(ins1,ins2);

    stampa(ins3,"ins3 - mia intersezione");
    stampa(ins3_corretto,"ins3 - intersezione corretta");
		

    Insieme* ins4_corretto = unione_soluzione(ins1,ins2);
    Insieme* ins4 = unione(ins1,ins2);
    stampa(ins4,"ins4 - la mia unione");
    stampa(ins4_corretto,"ins4 - unione corretta");
		
    printf("mia soluzione -- ins1 = ins 2? condizione booleana: %d\n", uguali(ins1, ins2));
    printf("soluzione corretta -- ins1 = ins 2? condizione booleana: %d\n", uguali_soluzione(ins1, ins2));
    
    printf("mia soluzione -- ins1 = ins 1? condizione booleana: %d\n", uguali(ins1, ins1));
    printf("soluzione corretta -- ins1 = ins 1? condizione booleana: %d\n", uguali_soluzione(ins1, ins1));	

}
