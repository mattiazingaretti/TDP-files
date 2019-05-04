#include<stdio.h>
/*
Scrivere un programma in linguaggio C che calcoli e stampi i primi N numeri della serie
di Fibonacci, con N inserito da tastiera. La serie di Fibonacci inizia con 1, 1 ed ogni
numero successivo è dato dalla somma dei due precedenti: 1, 1, 2, 3, 5, 8, 13, 21 . . .
*/
int main(){
    int N;
    int counter = 0;
    int ultimo, penultimo;
    printf("Inserire grandezza sequenza fibonacci: \n");
    scanf("%d", &N);
    printf("\n");
    printf("Sequenza: \n");
    printf("1 1 ");
    ultimo = 1;
    penultimo = 1;
    for(int i = 2 ;  i<N ; i ++){
        counter =  penultimo + ultimo;
        printf(" %d ",counter);
        penultimo = ultimo;
        ultimo = counter;
        
    }
    return 0;
}