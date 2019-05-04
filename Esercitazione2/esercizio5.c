/*Scrivere un programma in linguaggio C che inserita una sequenza di interi positivi in input ne
restituisce il minimo usando variabili di tipo puntatore ad int anziché variabili di tipo int. La
sequenza di input termina quando viene inserito il numero 0. Tutta la memoria utilizzata
deve essere allocata dinamicamente, e quando non più utilizzata deve essere rilasciata.
Nota bene: il programma deve controllare che la sequenza inserita sia costituita da numeri
interi positivi.*/
#include<stdlib.h>
#include<stdio.h>

int main(){
    int *num = (int*) malloc(sizeof(int));
    int *min = (int*) malloc(sizeof(int));
    printf("Inserire numero :");
    scanf("%d", num);
    if(*num > 0){
        *min = *num;
        do{
            printf("Inserire numero :");
            scanf("%d", num);
            if( *num < *min && *num != 0){
                *min = *num;
            }
        }while(*num > 0);
    printf("Il minimo è :%d  \n",*min);
    }else printf("Nessuna sequenza : \n");

	return 0;
}
