#include<stdio.h>
int main(){
    int num;
    do{    
        scanf("%d",&num);
        for(int i = 0; i < num; i++){
            if(num!= 0)
                printf("*");
        }
        printf("\n");
    }while(num != 0);
    return 0;
}