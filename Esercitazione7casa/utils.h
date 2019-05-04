#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "scl_functions.h"



void printList(TipoNodoSCL* l){
  if(l == NULL)
    return;
  TipoNodoSCL* aux=l;
  int pos=0;
  while(aux!=NULL){
    printf("pos: %d, info: %.1f\n", pos, aux->value);
    aux=aux->next;
    pos++;
  }
}

TipoNodoSCL* listPushFront(TipoNodoSCL* p0, int info){
  TipoNodoSCL* new_element=(TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
  new_element->next=p0;
  new_element->value=info;
  return new_element;
}

TipoNodoSCL* listPushBack(TipoNodoSCL* l, int value){
  TipoNodoSCL* new_element=(TipoNodoSCL*)malloc(sizeof(TipoNodoSCL));
  new_element->next=NULL;
  new_element->value=value;
  
  if (l==NULL){
    return new_element;
  }
  TipoNodoSCL* aux=l;
  while(aux->next!=NULL){
    aux=aux->next;
  }
  aux->next=new_element;
  return l;
}


TipoNodoSCL* copyList(TipoNodoSCL* list) {
  TipoNodoSCL* head = NULL;

  while(list){
    head = listPushBack(head, list->value);
    list = list->next;
  }
  return head;
}

TipoNodoSCL* createRandomList(int size){
  TipoNodoSCL* random_list = NULL;
  for(int i=0; i<size; ++i)
    random_list = listPushFront(random_list, rand()%20 - 10);
  return random_list;
}

int compareList(TipoNodoSCL* l1, TipoNodoSCL* l2){
  if(!l1 || !l2)
    return 0;
  while(l1 || l2) {
    if(!(l1 && l2))
      return 0;
    if(l1->value != l2->value)
      return 0;
    l1 = l1->next;
    l2 = l2->next;
  }
  return 1;
}

void freeList(TipoNodoSCL* list){
  if(!list)
    return;
  if(list->next)
    freeList(list->next);
  else
    free(list);
  return;
}

