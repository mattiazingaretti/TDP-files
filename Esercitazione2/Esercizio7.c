/*Definite due variabili intere a e b, calcolare la distanza in memoria tra queste variabili
(tramite differenza di puntatori) e modificare il contenuto di a scrivendo una espressione che
contiene solo il puntatore a b e la differenza in memoria tra a e b.
 */
#include<stdlib.h>
#include<stdio.h>
int main(){
    int a = 0, b = 256;
    int *p = &a;
    int *q = &b;
    long int gap = 0;
    if(p < q){
        while(*p != *q){
            gap++;
            printf("q vale %p: *q vale %d \n", q, *q);
            printf("p vale %p: *p vale %d \n", p, *p);
            p = p + 1;
        }
        *(q - gap )= 666;//Modifica richiesta
    }else{
        while(*p != *q){
            gap++;
            p = p -1;
        }
        *(q + gap) = 666;
    }
    printf("distanza in byte %ld \n", gap);

    printf("valore modificato %d :\n", a);
    return 0;
}
