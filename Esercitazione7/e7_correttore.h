#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "e7_esercizio.h"
#include "strutture.h"

void vec_print(float v[], int dim);
void _Mat_print(Mat *m);
Mat* _Mat_alloc(int rows, int cols);
float* _Mat_diagonale(Mat* m);
Mat* _Mat_sottoFinestre(Mat* m, int k);
int* _conta_2chars(TipoNodoSCL* s, char ch1, char ch2);
int _conta_2chars_aux(TipoNodoSCL* s, char ch);
void _vec_sommaEndTo(float* v, int n, float target);
void _vec_sommaEndTo_aux(float* v, int n, float target, float acc);
TipoNodoSCL* listPushFront(TipoNodoSCL* c0, int info);
TipoNodoSCL* createSCLstring(char* s, int n);
void printList(TipoNodoSCL* l);

