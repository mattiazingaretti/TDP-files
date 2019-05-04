#include<stdio.h>
int main(){
    float a = 0; 
    float b = 0;
    float x = 0;
    printf("Inserisci valore a:");
    scanf("%f", &a);
    printf("Inserisci valore b: ");
    scanf("%f", &b);
    x = b*(-1)/a;
    printf("Il risultato è %f :\n", x);
    return 0;
    
}