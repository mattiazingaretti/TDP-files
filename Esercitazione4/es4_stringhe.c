#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

char* copia(char s[], int N);

void seleziona_alcuni_char(char s[], int idxs[], int dim);

char* copia_con_eliminazione(char s1[], char s2[]);

char* inverti(char s[]);

void print_vocali(char s[]);

char* sostituisci_carattere(char s[], char c1, char c2);

bool minuscole_check(char s[]);

char* sostituisci_maiuscole(char s[]);

int main(void){

	int N = 7;
	int n = 5;
	char s[11] = "puntatore\0";
	 
	/********************************************************
    *              TEST copia                               *
    ********************************************************/
	//printf("Copio i primi %d valori della stringa s...\n", N);
	//char* char_copiato = copia(s, N);
	//printf("%s", char_copiato);
    //printf("\n\n");

	///********************************************************
    //*              TEST seleziona_alcuni_char               *
    //********************************************************/
    //printf("Stampo i valori con indici idxs della stringa s...\n");
	//int dims = 4;
	//int idxs[] = {1, 3, 5, 11};
	//seleziona_alcuni_char(s, idxs, dims);
    //printf("\n");
	
    ///********************************************************
    //*              TEST copia_con_eliminazione              *
    //********************************************************/
	//printf("Elimino dalla stringa s tutti i char non presenti in s2...\n");
	//char s2[] = "ptgar\0";
	//char* char_eliminato = copia_con_eliminazione(s, s2);
	//printf("%s", char_eliminato);
	//printf("\n\n");

	/********************************************************
    *              TEST inverti                             *
    ********************************************************/
	//printf("Inverto la stringa s...\n");
	//char* char_invertito = inverti(s);
	//printf	("%s", char_invertito);
	//printf("\n\n");

	/********************************************************
    *              TEST print_vocali                        *
    ********************************************************/
    //printf("Stampo le vocali contenute in s...\n");
	//print_vocali(s);
	//printf("\n\n");

	/********************************************************
    *              TEST sostituisci_carattere               *
    ********************************************************/
    //char c1 = 't';
	//char c2 = 'm';
    //printf("stostituisco in s il carattere %c con il carattere %c ...\n", c1, c2);
	//char* char_sostituito = sostituisci_carattere(s, c1, c2);
	//printf("%s", char_sostituito);
	//printf("\n\n");

	/********************************************************
    *              TEST sostituisci_carattere               *
    ********************************************************/
    //printf("controllo che tutti i caratteri siano minuscoli...\n");
	//printf( "%s\n", minuscole_check(s) ? "true: tutti i caratteri sono minuscoli" : "false: almeno un carattere è maiuscolo" );
	//printf("\n\n");

	/********************************************************
    *              TEST sostituisci_maiuscole               *
    ********************************************************/
	printf("Sostituisco le lettere maiuscole nella stringa s3...\n");
	char s3[39] = "cHE bEllA e rIlAssANTe lEZIonE dI TDp\0";
	char *char_maiuscolo = sostituisci_maiuscole(s3);
	printf("%s", char_maiuscolo);
	printf("\n");

	//free(char_copiato);	
	//free(char_eliminato);
	//free(char_invertito);
	//free(char_sostituito);	
	free(char_maiuscolo);
}

int length(char s[]){
	int length = 0;
	while(*s != '\0'){
		length++;
		s++;
	}
	return length;
}

char* copia(char s[], int N){
	char* ris = (char*) malloc(N);
	if(N < length(s)){
		char *end = s + N;
		while(s != end){
			*ris = *s;
			s++;
			ris++;
		}
	}else{
		ris = s;
	}
	return ris;
}

void seleziona_alcuni_char(char s[],int idxs[],int dim){
	int *i; 
	for(i = idxs; i < idxs +dim;i++){
		if(*i <strlen(s)-1){
			printf("Carattere all'indice %d: %c\n",*i,s[*i]);
		}
	}	
}
char* copia_con_eliminazione(char s1[ ], char s2[ ]){
	//printf("%s : %s\n",s1,s2);DEBUG
	char *ris = (char*)malloc(sizeof(	char)*strlen(s1)+1);
	bool entrato = false;
	for(int i = 0;i< strlen(s1);i++){
		 for(int j = 0;j<strlen(s2); j++){
			if(s1[i]  == s2[j]){
				ris[i] = s1[i];
				entrato = true;
			}
		}
		if(entrato == false){
			ris[i] = ' ';
		}else {entrato = false;}
	}
	return ris;
}

char* inverti(char s[]){
	char *inv = (char*)malloc(sizeof(char)*strlen(s)+1);
	for(int i = 0; i < strlen(s);i++){
		inv[i] = s[strlen(s)-i-1];
	}
	return inv;
}

void print_vocali(char s[]){
	char const* vocals = "aeiou";
	while(*s != '\0'){
		char *occ = strpbrk(s,vocals);
		if(occ != NULL )
		{
			printf("%c",*occ);
			s = occ;
		}	
		s++;
	}
}

char* sostituisci_carattere(char s[],char c1, char c2){
	char *ris = s;
	while(*ris != '\0'){
		char *occ = strchr(ris, c1);
		if(occ != NULL){
			ris = occ;
			*ris = c2;
		}
		ris++;
	}
	ris = s;
	return ris;
}

bool minuscole_check(char s[]){
	while(*s != '\0'){
		if(*s <97 || *s > 122){			
			return false;
		}
		s++;
	}
	return true;
}

char*  sostituisci_maiuscole(char s[]){
	char *ris = (char*)malloc(sizeof(char)*strlen(s));
	char *tokcpy = (char*)malloc(sizeof(char)*strlen(s));
	printf("%s\n",s);
	while(*s != '\0'){
		char *token = strtok(s, " ");
		if(token != NULL){
			while(*token !='\0'){
				if(*token >='A' && *token <='Z'){
					*token = *token -'A'+'a';
				}
				token++;
			}
			token = strtok(s," ");
			if(token[0] >= 'a' && token[0]<='z'){
					token[0] = token[0] -'a'+'A';
				}
			s = s +strlen(token);
			strcpy(tokcpy,token);
			strcat(tokcpy, " ");
			strcat(ris, tokcpy);
		}
		s++;
	}
	return ris;
}


