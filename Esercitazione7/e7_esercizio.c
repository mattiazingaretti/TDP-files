#include "e7_esercizio.h"
#include "strutture.h"

float* Mat_diagonale(Mat* m){
    float *v = (float*)malloc(2*sizeof(float));
    if(m->rows != m->cols){ return v; }
    else{
        v[0] = 0;
        v[1] = 1;
        for(int i = 0; i < m->rows; i++)
        {
            for(int j= 0; j< m->cols; j++){
                if( j == i){
                    v[0] += m->row_ptrs[i][j] ;
                    v[1] *= m->row_ptrs[i][j];
                }
            }
        }
    }
    return v;
}

Mat* Mat_sottoFinestre(Mat* m, int k){
    Mat* mat = (Mat*) malloc(sizeof(Mat));

    //Se k maggiori di dimensioni alloca matrice nulla e ritornala
    if(k > m->rows || k > m->cols){
        mat->rows = m->rows;
        mat->cols = m->cols;
        mat->row_ptrs = (float**)malloc(sizeof(float*)*mat->rows);
        for(int i = 0; i < mat->rows; i++){
                mat->row_ptrs[i] = (float*)calloc(mat->cols,sizeof(float));
        }
        return mat;
    }else{
        mat->rows = m->rows -k +1;
        mat->cols = m->cols -k+1;
        mat->row_ptrs = (float**)malloc(sizeof(float*)*mat->rows);
        for(int i = 0; i < mat->rows ;i++){
            mat->row_ptrs[i] = (float*)malloc(sizeof(float)*mat->cols);
            for(int j = 0; j< mat->cols; j++){
                mat->row_ptrs[i][j] = 1;//Inizializzo a elemento neutro prodotto.
                for(int l = 0; l<k; l++){
                    for(int t =0; t<k; t++){
                        mat->row_ptrs[i][j] *= m->row_ptrs[i + l][j+t];//Tanto è gia inizializzato...
                    }
                }
            }
        }

        return mat;
    }
}

void doShit(TipoNodoSCL *s, char ch1, char ch2,int * vec){
    if(s == NULL)
    {
        return;
        printf("Scl vuota\n");
    }
     else{
            if(s->value == ch1)
                {
                    vec[0] += 1;
                    doShit(s->next, ch1, ch2, vec);
                }
            else if(s->value == ch2)
                    {
                        vec[1] += 1;
                        doShit(s->next , ch1, ch2, vec);
                    }
            else {doShit(s->next , ch1, ch2, vec);}
    }
}


int* conta_2chars(TipoNodoSCL *s, char ch1, char ch2){
		int* vec = (int*)calloc(2,sizeof(int));
        doShit(s, ch1, ch2, vec);
        return vec;
}

float doShit2(float *v , int n , float target){
    if(*(v+1) != *(v+n-1))
    {
        printf("Ricorsione\n");
        return *(v+1)+ doShit2(v+1, n , target);
    }else return *v;
}

void vec_sommaEndTo(float* v, int n, float target){
    if(*v != *(v+n-1) )
    {
        if( *v == target)
        {
            printf("ricorsione\n");
            *v = doShit2(v, n , target);
        }
    }
}












