#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocaInt();

void inizializzaInt(int* i1, int* i2, int matricola);

void printInt(int *i1, int *i2);

int MCD(int i1, int i2);

int mcm(int i1, int i2);

void convTemperatura(int t, char c);

void* conversioneTemperatura(int* t, char c);

void printConversione(void* temperatura);

void soluzioneSistemaLineare(int i1, int i2);

void differenzaPuntatori(int *i1, int *i2);

void fibonacci(int N);



int main(int argc, char **argv) {
  int *i1 = allocaInt();
  int *i2 = allocaInt();
  printf("\n");

  /********************************************************
   *              TEST inizializzaArrayRandom             *
   ********************************************************/
  printf("Inizializzo i due interi con numeri random...");
  inizializzaInt(i1, i2, 18081988);
  printf(" done.\n\n");

  /********************************************************
   *                    TEST vec_print     v1             *
   ********************************************************/
  printf("i1, i2: ");
  printInt(i1, i2);
  printf("\n\n");

  /********************************************************
   *                    TEST MCD e mcm                    *
   ********************************************************/
  printf("calcolo il MCD...\n");
  int mcd = MCD(*i1, *i2);
  printf("il MCD è %d\n\n", mcd);

  printf("calcolo il mcm...\n");
  int res = mcm(*i1, *i2);
  printf("il mcm è %d\n\n", res);

  /********************************************************
   *                    TEST conversioneTemperatura       *
   ********************************************************/
  printf("test conversioneTemperatura...\n");
  convTemperatura(*i1, 'C');
  void* temperatura = conversioneTemperatura(i1, 'C');
  printConversione(temperatura);
  free(temperatura);
  printf("\n");

  /********************************************************
   *                    TEST soluzione sistema lineare    *
   ********************************************************/
  //printf("Calcolo la soluzione del sistema lineare...");
  //soluzioneSistemaLineare(*i1, *i2);
  //printf("\n");

  /********************************************************
   *                    TEST scambia puntatori            *
   ********************************************************/
  //printf("Cambio del valore puntato da i2...\n");
  //differenzaPuntatori(i1, i2);
  //printf("i2 : %d\n\n", *i2);


  /********************************************************
   *                    TEST fibonacci                    *
   ********************************************************/
  //printf("Calcolo dei primi %d numeri della serie di Fibonacci ...", *i1);
  //fibonacci(*i1);
  //printf("\n");  

  free(i1);
  free(i2);

  return 0;
}

int* allocaInt(){
	int *p = (int *) malloc(sizeof(int));
	return p;
}

void inizializzaInt(int* i1, int* i2, int matricola){
  //srand(matricola); // decommentare per avere sempre gli stessi due numeri (utile per debug)
  srand(time(0)); // decommentare per avere numeri diversi ad ogni esecuzione
  *i1=rand() % 20;
  *i2=rand() % 20;
}

void printInt(int *i1, int *i2){
  printf("Primo valore puntato %d :\n", *i1);
  printf("Secondo valore puntato %d :\n", *i2);
}

int MCD(int i1, int i2){
   int r;
    while(i2 != 0) //Algoritmo Euclide
    {
         r = i1 % i2;
         i1 = i2; 
         i2 = r; 
    }
    return i1; 
}

int mcm(int i1, int i2){
  return (int) (i1*i2)/MCD(i1, i2);
}

void convTemperatura(int t, char c){
	int kelvin, celsius ,farenait;
	switch(c){
		case  'K':{
			celsius =(int) t -273.15;
			farenait = (int)(t-273.15)*9/5+32;
			printf("celsius %d farenait %d\n", celsius, farenait);
			break;
		}case 'C':{
			kelvin = (int)t + 273.15;
			farenait = (int)t*(9/5)+32;
			printf("Kelvun %d : farenait %d\n", kelvin, farenait);
			break;
		}case 'F':{
			celsius = (int)(t -32)*5/9;
			kelvin = (int) celsius + 273.15;
			printf("celsius %d farenait %d:\n", celsius, farenait);
			break;
		}
  }
}

void* conversioneTemperatura(int* t, char c){
	void *ris = malloc(2*sizeof(int) + 2*sizeof(char));
	int *t1 = (int*)ris ;
	int *t2 = (int*)ris +1*sizeof(int);
	char *v1 = (char*)ris +2*sizeof(int)+ 1*sizeof(char);
	char *v2 = (char*) ris + 2*sizeof(int)+ 2*sizeof(char);
	switch(c){
		case  'K':{
			*t1 =(int) *t -273.15;
			*t2 = (int)(*t-273.15)*9/5+32;
			*v1 = 'C';
			*v2 = 'F';
			break;
		}case 'C':{
			*t1 = (int)*t + 273.15;
			*t2 = (int)*t*(9/5)+32;		
			*v1 = 'K';
			*v2 = 'F';
			break;
		}case 'F':{
			*t1 = (int)(*t -32)*5/9;
			*t2 = (int) *t1 + 273.15;
			*v1 = 'C';
			*v2 = 'K';
			break;
		}
  }
  return ris; 
}

void printConversione(void* temperatura){
	
	printf("Valori temperatura 1 %d \n", *((int*)temperatura));
	printf("Valori temperatura 2 %d \n", *((int*)temperatura+sizeof(int)));
	printf("Tipo 1 %c \n", *((char*)temperatura+ 2*sizeof(int)+sizeof(char)));
	printf("Tipo 2 %c \n", *((char*)temperatura+2*sizeof(int)+2*sizeof(char)));
}

void soluzioneSistemaLineare(int i1, int i2){
	
}

void differenzaPuntatori(int *i1, int *i2){
  // completare
}

void fibonacci(int N){
  // completare
  printf("\n");
}
