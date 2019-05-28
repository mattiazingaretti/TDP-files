#include "albero_binario.h"
#include "insieme.h"
#include "lista.h"
#include "esercizio.h"
#include "soluzione.h"

int main() {
  TipoAlbero a1, clone_a1, a2, clone_a2, a3, clone_a3;
  TipoLista l1, clone_l1, l2, clone_l2, l3, clone_l3, l4, clone_l4;

  a1 = LeggiAlbero("a1.txt");
  a2 = LeggiAlbero("a2.txt");
  a3 = LeggiAlbero("a3.txt");

  clone_a1 = LeggiAlbero("a1.txt");
  clone_a2 = LeggiAlbero("a2.txt");
  clone_a3 = LeggiAlbero("a3.txt");

  initLista(&l1);
  initLista(&clone_l1);

  initLista(&l2);
  addLista(&l2,0);

  initLista(&clone_l2);
  addLista(&clone_l2,0);

  initLista(&l3);
  addLista(&l3,4);
  addLista(&l3,7);
  addLista(&l3,9);
  addLista(&l3,3);
  addLista(&l3,2);

  initLista(&clone_l3);
  addLista(&clone_l3,4);
  addLista(&clone_l3,7);
  addLista(&clone_l3,9);
  addLista(&clone_l3,3);
  addLista(&clone_l3,2);

  initLista(&l4);
  addLista(&l4,5);
  addLista(&l4,4);
  addLista(&l4,3);
  addLista(&l4,2);
  addLista(&l4,1);

  initLista(&clone_l4);
  addLista(&clone_l4,5);
  addLista(&clone_l4,4);
  addLista(&clone_l4,3);
  addLista(&clone_l4,2);
  addLista(&clone_l4,1);
/*
  printf("\n***************** FUNZIONE scambiaSCL ******************\n\n");
    printf("TEST %d\n", 1);
    printf("l1=");
    stampa(l1);
    scambiaSCL(&l1);
    printf("Risultato ottenuto: scambiaSCL(&l1)=");
    stampa(l1);
    scambiaSCL_soluzione(&clone_l1);
    printf("Risultato atteso: scambiaSCL(&l1)=");
    stampa(clone_l1);
    printf("\n");

    printf("TEST %d\n", 2);
    printf("l2=");
    stampa(l2);
    scambiaSCL(&l2);
    printf("Risultato ottenuto: scambiaSCL(&l2)=");
    stampa(l2);
    scambiaSCL_soluzione(&clone_l2);
    printf("Risultato atteso: scambiaSCL(&l2)=");
    stampa(clone_l2);
    printf("\n");

    printf("TEST %d\n", 3);
    printf("l3=");
    stampa(l3);
    scambiaSCL(&l3);
    printf("Risultato ottenuto: scambiaSCL(&l3)=");
    stampa(l3);
    scambiaSCL_soluzione(&clone_l3);
    printf("Risultato atteso: scambiaSCL(&l3)=");
    stampa(clone_l3);
    printf("\n");

    printf("TEST %d\n", 4);
    printf("l4=");
    stampa(l4);
    scambiaSCL(&l2);
    printf("Risultato ottenuto: scambiaSCL(&l4)=");
    stampa(l4);
    scambiaSCL_soluzione(&clone_l4);
    printf("Risultato atteso: scambiaSCL(&l4)=");
    stampa(clone_l4);
    printf("\n");
  printf("********************************************************\n\n");
*/
    printf("\n***************** FUNZIONE nodiNormali ******************\n\n");
      Insieme *i, *j;
      StampaAlbero("a1",a1);
      printf("\n");
      printf("TEST %d\n", 5);
      i = nodiNormali(a1,0);
      printf("Risultato ottenuto:");
      stampaInsieme(i,"nodiNormali(a1,0)");
      j = nodiNormali_soluzione(clone_a1,0);
      printf("Risultato atteso:");
      stampaInsieme(j,"nodiNormali(a1,0)");
      printf("\n");

      printf("TEST %d\n", 6);
      i = nodiNormali(a1,1);
      printf("Risultato ottenuto:");
      stampaInsieme(i,"nodiNormali(a1,1)");
      j = nodiNormali_soluzione(clone_a1,1);
      printf("Risultato atteso:");
      stampaInsieme(j,"nodiNormali(a1,1)");
      printf("\n");

      StampaAlbero("a2",a2);
      printf("\n");
      printf("TEST %d\n", 7);
      i = nodiNormali(a2,0);
      printf("Risultato ottenuto:");
      stampaInsieme(i,"nodiNormali(a2,0)");
      j = nodiNormali_soluzione(clone_a2,0);
      printf("Risultato atteso:");
      stampaInsieme(j,"nodiNormali(a2,0)");
      printf("\n");

      printf("TEST %d\n", 8);
      i = nodiNormali(a2,1);
      printf("Risultato ottenuto:");
      stampaInsieme(i,"nodiNormali(a2,1)");
      j = nodiNormali_soluzione(clone_a2,1);
      printf("Risultato atteso:");
      stampaInsieme(j,"nodiNormali(a2,1)");
      printf("\n");

      printf("TEST %d\n", 9);
      i = nodiNormali(a2,2);
      printf("Risultato ottenuto:");
      stampaInsieme(i,"nodiNormali(a2,2)");
      j = nodiNormali_soluzione(clone_a2,2);
      printf("Risultato atteso:");
      stampaInsieme(j,"nodiNormali(a2,2)");
      printf("\n");
    printf("********************************************************\n\n");
/*
    printf("\n***************** FUNZIONE normalizzaFunzionale ******************\n\n");
      StampaAlbero("a1",a1);
      printf("\n");
      printf("TEST %d\n", 10);
      printf("Risultato atteso:");
      StampaAlbero("normalizzaFunzionale(a1)",normalizzaFunzionale(a1));
      printf("Risultato ottenuto:");
      StampaAlbero("normalizzaFunzionale(a1)",normalizzaFunzionale_soluzione(a1));
      printf("\n");

      StampaAlbero("a2",a2);
      printf("\n");
      printf("TEST %d\n", 11);
      printf("Risultato atteso:");
      StampaAlbero("normalizzaFunzionale(a2)",normalizzaFunzionale(a2));
      printf("Risultato ottenuto:");
      StampaAlbero("normalizzaFunzionale(a2)",normalizzaFunzionale_soluzione(a2));
      printf("\n");
      printf("\n");
    printf("********************************************************\n\n");

    printf("\n***************** FUNZIONE tagliaFoglieFunzionale ******************\n\n");
      StampaAlbero("a3",a3);
      printf("\n");
      printf("TEST %d\n", 12);
      printf("Risultato ottenuto:");
      StampaAlbero("tagliaFoglieFunzionale(a3)",tagliaFoglieFunzionale(a3));
      printf("Risultato atteso:");
      StampaAlbero("tagliaFoglieFunzionale(a3)",tagliaFoglieFunzionale_soluzione(clone_a3));
      printf("\n");

    printf("********************************************************\n\n");



    printf("\n***************** FUNZIONE normalizza ******************\n\n");
      StampaAlbero("a1",a1);
      printf("\n");
      printf("TEST %d\n", 13);
      normalizza(&a1);
      printf("Risultato ottenuto:");
      StampaAlbero("normalizza(&a1)",a1);
      normalizza_soluzione(&clone_a1);
      printf("Risultato atteso:");
      StampaAlbero("normalizza(&a1)",clone_a1);
      printf("\n");

      StampaAlbero("a2",a2);
      printf("\n");
      printf("TEST %d\n", 14);
      normalizza(&a2);
      printf("Risultato ottenuto:");
      StampaAlbero("normalizza(&a2)",a2);
      normalizza_soluzione(&clone_a2);
      printf("Risultato atteso:");
      StampaAlbero("normalizza(&a2)",clone_a2);
      printf("\n");
    printf("********************************************************\n\n");

    printf("\n***************** FUNZIONE tagliaFoglie ******************\n\n");
      StampaAlbero("a3",a3);
      printf("\n");
      printf("TEST %d\n", 15);
      tagliaFoglie(&a3);
      printf("Risultato ottenuto:");
      StampaAlbero("tagliaFoglie(&a3)",a3);
      tagliaFoglie_soluzione(&clone_a3);
      printf("Risultato atteso:");
      StampaAlbero("tagliaFoglie(&clone_a3)",clone_a3);
      printf("\n");
    printf("********************************************************\n\n");
*/

}
