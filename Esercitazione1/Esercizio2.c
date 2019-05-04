#include<stdio.h>
/*
Si scriva un programma in linguaggio C per calcolare la media aritmetica di una serie di
numeri inseriti da tastiera. L'introduzione di un valore particolare pari a "0" indica il
termine del caricamento dei dati.
*/
int main(){
    float media = 0;
    float val = 0;
    float totale = 0;
    int i = 0;

    do{
        printf("inserisci valore per calcolo media: ");
        scanf("%f", &val);
        totale = totale + val;
        i = i+1;
    }while(val != 0);
    media = totale / (i -1);
    printf("Il valore della media %f : ", media);


    return 0;
}