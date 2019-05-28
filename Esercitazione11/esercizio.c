#include "esercizio.h"

void scambiaSCL(TipoLista* l){
  if(emptyLista(*l)){
    return ;
  }else{
    if((*l)->next != NULL){
      if((*l)->info > (*l)->next->info){
        TipoInfoLista v = (*l)->info;
        (*l)->info = (*l)->next->info;
        (*l)->next->info = v; 
      }
    }
    scambiaSCL(&((*l)->next));
  }
  return;
}

void faiCose(TipoAlbero *a , int *l, Insieme *ris){
  if(*a == NULL){return ;}
  if(*l == 0){
    if( (*a)->sinistro == NULL && (*a)->destro == NULL ){
      printf("Entrato primo\n");
      if(!membro(ris, (*a)->info)){
          inserisci(ris, (*a)->info);
        }
    }
    if((*a)->sinistro != NULL && (*a)->destro != NULL){
        printf("entrato seconfo\n");
        if(!membro(ris, (*a)->info)){
          inserisci(ris, (*a)->info);
        }
    }
    
  }else{
    faiCose(&(*a)->sinistro, l-1, ris);
  faiCose(&(*a)->destro , l-1, ris);
  return;
  }
  
}

Insieme* nodiNormali(TipoAlbero a, int l){
  Insieme *ris = insiemeVuoto();
  StampaAlbero("Albero a1\n", a);
  faiCose(&a, &l, ris);
  return ris;
}

void normalizza(TipoAlbero* a){
  // Da implementare
  return;
}

TipoAlbero normalizzaFunzionale(TipoAlbero a){
  // Da implementare
  return NULL;
}

void tagliaFoglie(TipoAlbero* a){
  // Da implementare
  return;
}

TipoAlbero tagliaFoglieFunzionale(TipoAlbero a){
  // Da implementare
  return NULL;
  }
