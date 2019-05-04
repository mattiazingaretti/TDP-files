#pragma once
#include "strutture.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

float* Mat_diagonale(Mat* m);
Mat* Mat_sottoFinestre(Mat* m, int k);
int* conta_2chars(TipoNodoSCL* s, char ch1, char ch2);
void vec_sommaEndTo(float* v, int n, float target);

void vec_print(float v[], int dim);
void _Mat_print(Mat *m);
Mat* _Mat_alloc(int rows, int cols);


