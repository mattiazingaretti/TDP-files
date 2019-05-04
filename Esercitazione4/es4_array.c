#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inizializzaArrayRandom(double v[], int dim, double max_value);

void vec_print(double v[], int dim);

double* vec_sum(double v[],int dim);

double* vec_rec(double v1[],double v2[], int dim1,int dim2);

void vec_scale(double v[], int dim, double scale);

double vec_dot(double src1[], double src2[], int dim);

double* vec_clone(double v[], int dim);

bool vec_positive_check(double v[], int dim);

int main(int argc, char **argv) {
  int dim1 = 10;
  double max_value = 10;
  
  /********************************************************
   *              TEST inizializzaArrayRandom             *
   ********************************************************/
  printf("Inizializzo l'array con numeri random...");
  double v1[dim1];
  inizializzaArrayRandom(v1, dim1, max_value);
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print     v1             *
   ********************************************************/
   printf("v1: ");
   vec_print(v1, dim1);
   printf("\n\n");

  /********************************************************
   *                    TEST allocate vectors             *
   ********************************************************/
   printf("Alloco il vettore v2...\n");
   double v2[] = {2.1, -3.5, 1.0, 6.5, -5.2};
   int dim2 = sizeof(v2)/sizeof(double);
   
   printf("Alloco il vettore v3...\n\n");
   int dim3 = dim2;
   double* v3 = (double *) malloc(dim3*sizeof(double));
   v3[0] = 4.8;
   v3[1] = 0.1;
   v3[2] = -6.2;
   v3[3] = -2.5;
   v3[4] = 7.2;
   
   printf("v2: ");
   vec_print(v2, dim2);
   printf("\n");
   
   printf("v3: ");
   vec_print(v3, dim3);
   printf("\n\n");
   
   //DEBUG funzione vec_sum(double v[],int dim)
   //double *v4; 
   //v4 = vec_sum(v2, 5);
   //vec_print(v4, 5);
   //DEBUG funzione vec_rec(double v1[],double v2[], int dim1,int dim2)
   //double *v4 ;
   //v4 = vec_rec(v2,v3, 5,5);
   //vec_print(v4,5);
  /********************************************************
   *                    TEST vec_scale  v3                *
   ********************************************************/
   printf("Scalo v3 di un fattore di 0.5...");
   vec_scale(v3, dim3, 0.5);
   printf(" done.\n");
   printf("v3: ");
   vec_print(v3, dim3);  
   printf("\n");

  /********************************************************
   *                    TEST vec_dot  v2°v3
   *
   ********************************************************/
   printf("Calcolo il prodotto scalare tra v2 e v3...");
   double dot = vec_dot(v2, v3, dim2);
   printf(" done.\n");
   printf("Il prodotto scalare tra v2 e v3 e': %lf\n\n", dot);

  /********************************************************
   *                    TEST vec_clone  v2                *
   ********************************************************/
   printf("Clono v2...");
   double *copy_v2 = vec_clone(v2, dim2);
   printf(" done.\n");
   printf("Copia v2: ");
   vec_print(copy_v2, dim2);  
   printf("\n\n");

  /********************************************************
  *                    TEST vec_positive_check  v2        *
  ********************************************************/
  printf("Controllo che tutti i numeri di v2 siano positivi...\n");
  printf( "%s\n", vec_positive_check(v2, dim2) ? "true: tutti i numeri sono positivi" : "false: almeno un numero è negativo" );
  
  //bool t = vec_clone(v2, dim2);
  //printf("Valore di t %d\n",t);
  free(copy_v2);
  free(v3);

  return 0;
}

void inizializzaArrayRandom(double v[], int dim, double max_value) {
  srand(3);
  for (int i=0;i<dim;i++){
    v[i]=rand() % 10;
  }
}

void vec_print(double v[], int dim){
	printf("[");
	for(int i = 1; i <= dim ;i++){
		printf("%.1lf_%d  ", *(v+i-1),i);
	}
	printf("]\n");
}

double* vec_sum(double v[],int dim){
	double somma = 0;
	double *ris = (double*) malloc(sizeof(double)*dim);
	for(int i = dim-1;i >0;i--){
		ris[i] = v[i] +somma;
		somma += v[i];
	}
	return ris;
}
double* vec_rec(double v1[],double v2[],int dim1,int dim2){
	double *ris = (double*) calloc(dim1,sizeof(double));
	for(int i = 0;i < dim1;i++){
		for(int j = 0; j<dim2;j++){
			if(v1[i] == v2[j]){ris[i] = v1[i];}
		}
	}
	return ris;
}
void vec_scale(double v[],int dim ,double d){
	int i = 0;
	while(i<dim){
		*(v+i) *= d;
		i++;
	}
}
double vec_dot(double src1[],double src2[],int dim){
	double prodotto_scalare = 1;
	for(int i = 0;i < dim;i++){
		prodotto_scalare += src1[i]*src2[i];
	}
	return prodotto_scalare;
}
double* vec_clone(double v[],int dim){
	double *clone = (double*) malloc(dim*sizeof(double));
	double *end = clone + dim*sizeof(double);
	while(clone != end){
		*clone = *v;
		v++;
		clone++;
	}
	clone = clone -dim*sizeof(double);
	return clone;
}

bool vec_positive_check(double v[],int dim){
	printf("ciao\n");
  double *end = v+dim*sizeof(double);
	while(v != end){
		printf("%.2lf\n",*v);
		if(*v <= 0){return  false;}
		v++;
	}
	return true;
}
