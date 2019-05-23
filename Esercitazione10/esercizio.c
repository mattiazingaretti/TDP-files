#include "esercizio.h"

void cercaPerLivelli(TipoAlbero a, TipoInfoAlbero v , int l, int* ris){
	if(estVuoto(a)){ *ris = 0;}
	if(radice(a) == v){
		*ris = l ;
		return;
	}
	if(!estVuoto(sinistro(a))){
		cercaPerLivelli(sinistro(a), v , l+1, ris);
	}
	if(!estVuoto(destro(a))){
			cercaPerLivelli(destro(a), v , l+1, ris);
	}
}

int ricercaLivello(TipoAlbero a, TipoInfoAlbero v, int livello_corrente){
	int ris = 0;
	cercaPerLivelli(a, v, livello_corrente, &ris);
	return ris;
}


int verificaNodi(TipoAlbero a, int livello){
	if(estVuoto(a)){return 0;}
	if(livello%2 == 0 && radice(a)%2 == 0){
			return 1 + verificaNodi(sinistro(a), livello+1) + verificaNodi(destro(a), livello+1);
		}
	if(livello%2 != 0 && radice(a)%2 != 0){
			return 1 + verificaNodi(sinistro(a), livello+1) + verificaNodi(destro(a), livello+1);
		}
	else{
		return verificaNodi(sinistro(a), livello+1) + verificaNodi(destro(a), livello+1);
	}
}

int singleChildSum(TipoAlbero a){
	if(estVuoto(a)){return 0;}
	if(estVuoto(sinistro(a)) && !estVuoto(destro(a))){
		return radice(a) + singleChildSum(destro(a));
	}
	if(estVuoto(destro(a)) && !estVuoto(sinistro(a))){
		return radice(a) + singleChildSum(sinistro(a));
	}
	return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
}

TipoListaSCL * concatena(TipoListaSCL *l1, TipoListaSCL *l2){
	TipoListaSCL *ris = creaLista();
	//Purtroppo non hanno implementato un iteratore per le liste
	//Quindi scorro usando la scelta implementativa delle SCL sulle liste.
	if(l1 == NULL ){ return l2;}
	if(l2 == NULL ){ return l1;}
	TipoListaSCL *p = l1;
	while(p != NULL){
		ris = listPushBack(ris, p->value);
		p = p->next;
	}
	TipoListaSCL *p1 = l2;
	while(p1 != NULL){
		ris = listPushBack(ris, p1->value);
		p1 = p1->next;
	}
	printf("Concatenato \n");
	return ris;
}

TipoListaSCL * append(TipoListaSCL *l , TipoInfoAlbero i){
	if(lunghezzaLista(l) > 0){
		TipoListaSCL *ris = creaLista();
		ris = listPushBack(ris, i);
		return ris;
	}else{
		l = listPushBack(l , i);
		return l;
	}
}

TipoListaSCL* listaNodiFoglia(TipoAlbero a){
/*
DEBUG SULLA FUNZIONE CONCATENA
	TipoListaSCL *l1 = creaLista();
	TipoListaSCL *l3 = creaLista();
	l1 = listPushFront(l1, 6);
	l1 = listPushFront(l1, 5);
	l3 = listPushFront(l3, 8);
	l3 = listPushFront(l3, 7);
	TipoListaSCL *l4 = creaLista(); 
	l3 = concatena(concatena(l1, l3), l3);
	printList(l3);
*/
	if(estVuoto(a)){return NULL;}
	if(estVuoto(sinistro(a)) && estVuoto(destro(a))){
		TipoListaSCL *l = append(NULL, radice(a));
		return concatena( l, concatena( listaNodiFoglia(sinistro(a)), listaNodiFoglia(destro(a)) )   ) ;
	}
	return  concatena(listaNodiFoglia(sinistro(a)) , listaNodiFoglia(destro(a)));
}

Coda* codaNodiDueFigli(TipoAlbero a){
	// IMPLEMENTARE
	return NULL;
}

TipoListaSCL* listaPercorso(TipoAlbero a){
	// IMPLEMENTARE
	return NULL;
}







TipoAlbero albBinVuoto () {
	return 0;
}

TipoAlbero creaAlbBin( TipoInfoAlbero infoRadice, TipoAlbero sx, TipoAlbero dx ) {
	TipoAlbero a = ( TipoAlbero ) malloc ( sizeof (TipoNodoAlbero) ) ;
	a->info = infoRadice ;
	a->sinistro = sx ;
	a->destro = dx ;
	return a ;
}



bool estVuoto ( TipoAlbero a ) {
	return ( a == NULL );
}

TipoInfoAlbero radice ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
		return ERRORE_InfoAlbero;
	}
	else
		return a->info;
}

TipoAlbero sinistro ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
	return NULL;
	}
	else
		return a->sinistro ;
}

TipoAlbero destro ( TipoAlbero a ) {
	if ( a == NULL ) {
		printf ( " ERRORE accesso albero vuoto \n " );
		return NULL;
	}
	else
		return a->destro;
}

TipoListaSCL* creaLista(){
	return NULL;
}

int lunghezzaLista(TipoListaSCL* l){
	int lun = 0;
	if(l == NULL)
		return 0;
	lun = 1;
	TipoListaSCL* aux = l;
	while(aux->next != NULL){
		aux = aux->next;
		lun++;
	}
	return lun;
}

TipoListaSCL* listPushFront(TipoListaSCL* l, TipoInfoAlbero info){
	 TipoListaSCL* new_element = ( TipoListaSCL* ) malloc ( sizeof (TipoListaSCL) ) ;
	 new_element->next = l;
  	 new_element->value = info;
	 return new_element;
}

TipoListaSCL* listPushBack(TipoListaSCL* l, TipoInfoAlbero info){
	 TipoListaSCL* new_element = ( TipoListaSCL* ) malloc ( sizeof (TipoListaSCL) ) ;
	 new_element->value = info;
	 new_element->next = NULL;

	 if( l == NULL ){
		l = listPushFront(l, info);
		return l;
	 }

	 TipoListaSCL* aux = l;
	 while(aux->next != NULL)
	 	aux = aux->next;

	 aux->next = new_element;
	 return l;
}

void printList(TipoListaSCL* l){
  if(l == NULL)
    return;
  TipoListaSCL* aux = l;
  while(aux != NULL){
    printf(" %d ", aux->value);
    aux = aux->next;
  }
  return;
}









Coda* codaVuota() {
  Coda* r = (Coda*) malloc (sizeof(Coda));
  r->data = NULL; // Necessario per usare realloc
  r->size = 0;
  r->nelem = 0;
  return r;
}

bool estVuota(Coda* c) {
	if(c == NULL)
		return 0;		
	return (c->nelem==0);
}

void inCoda(Coda* c, TipoInfoAlbero e){
  c->nelem++;
  if (c->nelem > c->size){
    // Raddoppiamento dimensione array
    c -> size = 2 * c-> nelem;
    c -> data = (TipoInfoAlbero*) realloc(c->data,c->size*sizeof(TipoInfoAlbero));
  }
  c->data[c->nelem -1] = e;
}

void outCoda(Coda* c){
  if (c == NULL || c->nelem == 0){
    printf("ERRORE: input NULL o coda vuota");
    exit(1);
  }
  c->nelem--;
  if (c->nelem < c->size/2){
    // Dimezzamento array
    c->size /= 2;
    c->data = (TipoInfoAlbero*) realloc(c->data,c->size*sizeof(TipoInfoAlbero));
  }
  // Copia tutti gli elementi della coda nella componente precedente
  int i;
  for (i = 1; i <= c->nelem; i++){
    c->data[i-1]=c->data[i];
  }
}

void printInfo(TipoInfoAlbero e){
	printf("%d", e);
}

TipoInfoAlbero primo(Coda* c){
  if (c->nelem == 0){
    printf("ERRORE: coda vuota");
    exit(1);
  }
	return c->data[0];
}

IteratoreCoda* creaIteratoreCoda(Coda *c) {
    IteratoreCoda *it = (IteratoreCoda *)malloc(sizeof(IteratoreCoda));
    it->c = c;
    it->ptr = 0;
    return it;
}

bool hasNext(IteratoreCoda *it) {
    return it->ptr < it->c->nelem;
}

TipoInfoAlbero next(IteratoreCoda *it) {
    TipoInfoAlbero r = ERRORE_InfoAlbero;
    if (hasNext(it)) {
        r = it->c->data[it->ptr];
        it->ptr ++;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}


void printCoda(Coda* c){
  if(c == NULL)
  {
	printf(" coda non allocata\n");
	return;
  }
  IteratoreCoda* it = creaIteratoreCoda(c);
  while(hasNext(it)){
    printInfo(next(it));
    printf(" ");    
  }
  printf("\n");
}


