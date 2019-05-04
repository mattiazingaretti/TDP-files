#pragma once

typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

struct TipoNodoSCL {
    char value;
    struct TipoNodoSCL* next;
};


