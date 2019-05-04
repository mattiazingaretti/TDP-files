#include<stdlib.h>
#include<stdio.h>
int main(){
    int *n = (int *) malloc(sizeof(int));
    printf("Inserire un numero :");
    scanf("%d", n);
    int *min;
    if(*n > 0){
        min = n+sizeof(int);//per evita di usa malloc alloco memoria attaccata a n
        *min = *n;//inizializzo il minimo
        while(*n > 0){
             if(*n < *min && *n != 0){
                *min = *n;
            }
            printf("Inserire un numero :");
            scanf("%d", n);
            //DEBUG printf("min %d : n %d \n",*min,*n);
        }
        printf("Numero minimo :%d\n",*min);
    }else printf("sbagliato seq :\n");


    return 0;
}
