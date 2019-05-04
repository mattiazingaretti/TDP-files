#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
  int rows;
  int cols;
  float **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols);
Mat* Mat_read(const char *filename);
void Mat_print(Mat *m);
void Mat_write(const char *filename, Mat *m);
void Mat_free(Mat *m);
bool  Mat_is_symmetric(Mat *m);
void Mat_normalize_rows(Mat *m);
Mat* Mat_clone(Mat *m);
Mat* Mat_sum(Mat *m1, Mat *m2);
Mat* Mat_product(Mat *m1, Mat *m2);

int main(int argc, char **argv) {
  Mat *m = Mat_alloc(5,6);
  printf("righe %d: colonne %d \n",m->rows, m-> cols);

  /********************************************************
  *             TEST Mat_alloc/Mat_read                  *
  ********************************************************/
  printf("Leggo m1 dal file mat_1.txt...");
  Mat *m1 = Mat_read("mat_1.txt");
  printf(" fatto.\n\n");

  /********************************************************
  *                    TEST Mat_print                    *
  ********************************************************/
  printf("m1:\n");
  Mat_print(m1);
  printf("\n");

  /********************************************************
  *                    TEST Mat_write                    *
  ********************************************************/
  //printf("Scrivo una copia di m1 in copia_mat_1.txt...");
  //Mat_write("copia_mat_1.txt", m1);
  //printf(" fatto.\n\n");

  /********************************************************
  *                TEST Mat_is_symmetric                 *
  ********************************************************/
  //printf("Leggo m2 dal file mat_2.txt...");
  //Mat *m2 = Mat_read("mat_2.txt");
  //printf(" fatto.\n");
  //printf("m2:\n");
  //Mat_print(m2);
  //printf("La matrice m2 e' simmetrica?\n");
  //int is_symmmetric = Mat_is_symmetric(m2);
  //if(is_symmmetric) {
    //printf("Si e' simmetrica.\n");
  //}
  //else {
    //printf("No non e' simmetrica.\n");
  //}
  //printf("\n");

  /********************************************************
  *               TEST Mat_normalize_rows                *
  ********************************************************/
  //printf("Leggo m3 dal file mat_3.txt...");
  //Mat *m3 = Mat_read("mat_3.txt");
  //printf(" fatto.\n");
  //printf("m3:\n");
  //Mat_print(m3);
  //printf("Normalizzo le righe della matrice m3...");
  //Mat_normalize_rows(m3);
  //printf(" fatto.\n");
  //printf("La matrice m3 con righe normalizzate e':\n");
  //Mat_print(m3);
  //printf("\n");

  /********************************************************
  *                    TEST Mat_clone                    *
  ********************************************************/
  //printf("Clono m2...");
  //Mat *copy_m2 = Mat_clone(m2);
  //printf(" fatto.\n");
  //printf("Copia m2:\n");
  //Mat_print(copy_m2);
  //printf("\n");

  /********************************************************
  *                    TEST Mat_sum                       *
  ********************************************************/
  //printf("Sommo m2 e m3...\n");
  //Mat *sum_m2_m3 = Mat_sum(m2, m3);
  //if( sum_m2_m3 != NULL ){
    //printf(" fatto.\n");
    //Mat_print(sum_m2_m3);
  //}
  //printf("\n");

  /********************************************************
  *                    TEST Mat_product                   *
  ********************************************************/
  printf("leggo m4 e ne eseguo il prodotto con m1...\n");
  Mat *m4 = Mat_read("mat_4.txt");
  Mat *product_m1_m4 = Mat_product(m1, m4);
  if( product_m1_m4 != NULL ){
    printf(" fatto.\n");
    Mat_print(product_m1_m4);
  }
  printf("\n");

  /********************************************************
  *                    TEST Mat_free                     *
  ********************************************************/
  //Mat_free(copy_m2);
  //Mat_free(m4);
  //Mat_free(m3);
  //Mat_free(m2);
  //Mat_free(m1);

  return 0;
}

Mat* Mat_alloc(int rows, int cols) {
  Mat *m = (Mat*) malloc(sizeof(Mat));
  m -> rows = rows;
  m -> cols = cols;
  float **p = (float**)malloc(rows*sizeof(float*));
  m -> row_ptrs = p;
  return m;
}

Mat* Mat_read(const char *filename) {
  Mat *m;
  char path[] = "./";//I file di testo sono nella directory corrente
  strcat(path, filename);
  FILE* file = fopen(path, "r");
  char line[256];//Imposto un buffer per riga di 256 byte
  if(file != NULL){
	  fgets(line,sizeof(line),file);
	  int r =(int)line[0] -48;
	  int c = (int)line[2] -48;
	  m = Mat_alloc(r,c);
	  float **rpointer = (float**) malloc(r*sizeof(float*));
	  for(int i = 0; i < r; i++){
          rpointer[i] = (float*) malloc(c*sizeof(float));
          fgets(line,sizeof(line),file);
		  char *token = strtok(line," ");
		  float first = (float)atof(token);
          rpointer[i][0] = first;
          for(int j = 1; j <c;j++){
                token = strtok(NULL," ");
                float value = atof(token);
                rpointer[i][j] = value;
            }
          }
	  m->row_ptrs= rpointer;
  }else{
	  printf("Filename non valido!\n");
  }
  fclose(file);
  return m;
}

void Mat_print(Mat *m) {
    float **app =  m->row_ptrs;
  for(int i = 0; i < m->rows;i++){
	for(int j = 0; j < m->cols; j++){
		printf("%0.2f ",app[i][j]);
	}
    printf("\n");
  }
}

void Mat_write(const char *filename, Mat *m) {
    FILE *file = fopen(filename,"w");
    if(file != NULL){
        fprintf(file, "matrice :\n");
        for(int i =0 ;i<m->rows;i++){
            fprintf(file, "v[%d]: [", i);
            for(int j = 0;j < m->cols;j++){
                fprintf(file, " %.2f ", m->row_ptrs[i][j]);
            }
            fprintf(file, "]\n");
        }
    }
    else{
        printf("Non è stato possibile scrivere la matrice sul file");
    }
    fclose(file);
}

bool  Mat_is_symmetric(Mat *m) {
    for(int i =0 ; i < m->rows; i++){
        for(int j = 0; j < m->cols;j++){
            if(m->row_ptrs[i][j] != m->row_ptrs[j][i]) return false;
        }
    }
    return true;
}

void Mat_normalize_rows(Mat *m) {
    float *norma = (float*)calloc( m->rows*sizeof(float), sizeof(float));
    for(int i =0; i < m->rows;i++){
        for(int j = 0; j< m->cols; j++){
            norma[i] += pow( m->row_ptrs[i][j], 2);
        }
        norma[i] = (float)sqrt(norma[i]);
    }
    for(int i =0 ; i < m->rows; i++){
        for(int j = 0; j < m->cols;j++){
            m->row_ptrs[i][j] = m->row_ptrs[i][j]/norma[i];
        }
    }
}

Mat* Mat_clone(Mat *m) {

  Mat *copy = (Mat*)malloc(sizeof(Mat));
  copy = m;//Fa la copia valore per valore
  return copy;
}

void Mat_free(Mat *m) {
    for(int i = 0; i < m->rows; i++){
        free(m->row_ptrs[i]);
    }
    free(m);
}

Mat* Mat_sum(Mat *m1, Mat *m2){
  Mat *output = (Mat*)malloc(sizeof(Mat));
  //Mi pesa il culo usare -> XD lol
  int r1 = m1->rows;
  int c1 = m1->cols;
  float **p1 = m1->row_ptrs;
  int r2 = m2->rows;
  int c2 = m2->cols;
  float **p2 = m2->row_ptrs;
  if(r1 == r2 && c1 == c2){
      int r = r1;
      int c = c1;
      output->rows = r;
      output->cols = c;
        for(int i = 0;i <r ; i++){
            for(int j = 0;j< c;j++){
                output->row_ptrs[i][j] = p1[i][j] +p2[i][j];
            }
        }
  }
  else{
    printf("Somma non possibile!\n");
    return NULL;
  }
  return output;
}


Mat* Mat_product(Mat *m1, Mat *m2){
  Mat *output = (Mat*)malloc(sizeof(Mat));
  if(m1->cols == m2->rows){
      output->rows = m1->rows;
      output->cols = m2->cols;
      int i, j, k;
      float **res = (float**)calloc(m1->rows,sizeof(float*));
      for (i = 0; i < m1->rows; i++){
          res[i] = (float*)calloc(m2->cols,sizeof(float));
          for (j = 0; j < m2->cols; j++){
                for (k = 0; k < m2->cols; k++)
                    {
                        res[i][j] += m1->row_ptrs[i][k]*m2->row_ptrs[k][j];
                        printf("%f %d %d %d\n",res[i][j], i,j,k);
                    }
                output->row_ptrs[i][j]= res[i][j];
        }

    }


  }
  else{
    printf("Prodotto tra matrici non possibile\n");
    return NULL;
  }

  return output;
}
