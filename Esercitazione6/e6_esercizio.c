#include "e6_esercizio.h"
#include <stdio.h>

//Terminazione assicurata dal fatto che ogni stringa ha /0
int lunghezza(char *s){
    if(*s != '\0'){return 1+lunghezza(s+1);}
}

int char_in_posizione(char *s, char ch){
    if(*s == '\0'){return -1;}
    if(*s != ch ){return char_in_posizione(s+1, ch);}
}

bool tuttiMinuscoli(char *s){
    bool check;
    if(*s <'Z' || *s >'A'){return false;}
    else { check = tuttiMinuscoli(s+1);}
    return check;
}

void converti(char *s){
    if(*s == '\0') return;
    if(*s <'a' || *s > 'z'){
        *s = *s +'a'-'A';
        converti(s+1);
    }
    else{converti(s+1);}
}

//in i la somma da 0 a i -1
void vec_integral(float* v, int n){

    if(*v != v[n-1]){
        vec_integral(v,

    }
}



float vec_dot(float* v1, float* v2, int n) {

	return 0;
}

int contaParentesi(char *s){

	return 0;
}

void concatenate(char* dest, char* src){

	return;
}

float prodotto(float a[], int n){

	return 0;
}
