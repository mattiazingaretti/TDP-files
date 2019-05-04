#include "utils.h"
#include "scl_functions.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char** argv){

  printf("*****************\n SCL\n*****************\n");
  printf("\nRandom SCL list created: \n");
  int list_size = 3;
  TipoNodoSCL* list = createRandomList(list_size);
  printList(list);


  printf("\nTest of SCL_sum\n");
  float list_sum = SCL_sum(list);
  printf("computed list sum: %.1f\n",list_sum);


  printf("\nTest of SCL_integral\n");
  TipoNodoSCL* list_integrated = copyList(list);
  SCL_integral(list_integrated);
  printf("computed integrated list\n");
  printList(list_integrated);


  printf("\nTest of SCL_dot\n");
  float list_dot_product = SCL_dot(list, list_integrated);
  printf("computed list dot product: %.1f\n",list_dot_product);

  freeList(list);
  freeList(list_integrated);


  return 0;
}

