#include<stdio.h>
int main(){
    int N ;
    printf("inserire dimensione N : ");
    scanf("%d", &N);
    printf("\n");
    for(int i = 0; i < N ; i++){
        printf("*");
        
    }
    printf("\n");
    for(int i = 0; i< (N-2);i++){
        printf("*");
        for(int j = 0; j<(N-2) ; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for(int i = 0; i < N ; i++){
        printf("*");
    }
    printf("\n \n ");
    
    return 0;
}