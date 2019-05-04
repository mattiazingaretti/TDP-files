#include "e6_correttore.h"

int main(int argc, char **argv) {
		
	printf("\n");

	//inizializza parametri stringhe
	char s[10] = "ASsfQg\0";
	char s_sol[10] = "ASsfQg\0";

	//calcolo lunghezza
	int value_sol = _lunghezza(s);
	int value = lunghezza(s);
	printf("La stringa è lunga: %d\n", value);
	printf("soluzione: %d\n\n", value_sol);

	//check carattere
	char ch = 'z';
	int index_sol = _char_in_posizione(s,ch);
	int index = char_in_posizione(s,ch);
	( index >= 0 ) ? printf("il carattere %c è presente in indice %d\n", ch, index) : printf("il carattere %c non è presente\n", ch);
	printf("soluzione: ");
	( index_sol >= 0 ) ? printf("il carattere %c è presente in indice %d\n\n", ch, index_sol) : printf("il carattere %c non è presente\n\n", ch);

	//check maiuscole
	bool check_minuscole_sol = _tuttiMinuscoli(s);
	bool check_minuscole = tuttiMinuscoli(s);
	check_minuscole ? printf("sono tutte minuscole\n") : printf("C'è almeno un carattere maiuscolo\n");
	printf("soluzione: ");
	check_minuscole_sol ? printf("sono tutte minuscole\n\n") : printf("C'è almeno un carattere maiuscolo\n\n");

	//converti maiuscole-minuscole
	_converti(s_sol);
	converti(s);
	printf("stringa convertita in caratteri minuscoli: %s\n", s);
	printf("soluzione: %s\n\n", s_sol);

	int vec_size = 10;
	float vec[10] = {3.1, -2.3, 5.8, 1.4, -0.3, 4.1, 9.1, -3.7, 2.9, -4.9};
	float vec_sol[10] = {3.1, -2.3, 5.8, 1.4, -0.3, 4.1, 9.1, -3.7, 2.9, -4.9};
	_vec_integral(vec_sol, 10);
	vec_integral(vec, 10);
	vec_print(vec, vec_size);
	printf("soluzione: ");
	vec_print(vec_sol, vec_size);
	printf("\n");

	int vecs_size = 5;
	float vec1[5] = {5.7, 2.3, -3.6, 8.1, -0.1};
	float vec2[5] = {-5.2, 1.3, -2.1, 1.2, 0.1};
	float vec_dot_result_sol = _vec_dot(vec1, vec2, vecs_size);
	float vec_dot_result = vec_dot(vec1, vec2, vecs_size);
	printf("il risultato del prodotto scalare è: %f\n", vec_dot_result);
	printf("soluzione: ");
	printf("%f\n\n", vec_dot_result_sol);

	char s_par[12] = "()ar[Z}az{\0";
	int num_parentesi_sol = _contaParentesi(s_par);
	int num_parentesi = contaParentesi(s_par);
	printf("ci sono %d parentesi \n", num_parentesi);
	printf("soluzione :");
	printf("%d \n\n", num_parentesi_sol);
		
	char dest[20] = "TDP è\0";
	char dest_sol[20] = "TDP è\0";
	char src[20] = " interessante\0";
	_concatenate(dest_sol, src);
	concatenate(dest, src);
	printf("stringa concatenata: %s\n", dest);
	printf("soluzione: ");
	printf("%s\n\n", dest_sol);

	float prodotto_res_sol = _prodotto(vec1, vecs_size);
	float prodotto_res = prodotto(vec1, vecs_size);
	printf("il prodotto è: %f\n", prodotto_res);
	printf("soluzione: ");
	printf(" %f\n\n", prodotto_res_sol);

	return 0;
}