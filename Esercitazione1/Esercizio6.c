/*
Scrivere un programma che dati in input due numeri interi positivi N ed M (M
sottomultiplo di N), disegni una scacchiera N*MxN*M con blocchi di asterischi M*M.
Esempio con M = 2 ed N = 4:
**--**--
**--**--
--**--**
--**--**
**--**--
**--**--
--**--**
--**--**
*/
#include<stdio.h>
int main(){
    int N,M;
    printf("Inserisci intero positivo M(Sottomultiplo di N) :");
    scanf("%d", &M);
    printf("Inserisci intero positivo N: ");
    scanf("%d", &N);
    int r = N*M;
    int c = r;
    char inizio = '*';
    char fine = '-';
    int counter = 0;
    char app = 'a';
    for(int i = 0; i < N; i++){
        while(counter < M){
            for(int k = 0; k<N ;k++){
                for(int h = 0; h<M ;h++){
                    if(k%2 == 0)
                        printf("%c",inizio);
                    else
                        printf("%c", fine);
                }
            }
        printf("\n");    
        counter += 1;
        }
        app = inizio;
        inizio = fine ;
        fine = app;
        counter = 0;
    }
    return 0;
}