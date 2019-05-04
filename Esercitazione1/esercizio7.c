#include<stdio.h>
/*
Scrivere un programma in linguaggio C che legge una serie di valori interi in input e ne
restituisce il minimo. La sequenza di inserimento termina quando viene inserito il valore
0, che non deve essere conteggiato nel calcolo del minimo.
*/
int main(){
    int num ,minimo;
    //Necessario per inizializzare num
    printf("Inserisci numero che gioia..");
    scanf("%d", &num);
    if(num!= 0) minimo = num;
    else printf("Il primo numero è 0 sveglio..\n");
    while(num != 0){
        printf("Inserisci numero che gioia..");
        scanf("%d", &num);
        if(num < minimo) minimo = num;
    }
    printf("Il minimo è : %d\n", minimo);
    return 0;
}