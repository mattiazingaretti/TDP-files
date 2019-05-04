#include <stdlib.h>
#include <stdio.h>
#include "scl_functions.h"



float SCL_sum(TipoNodoSCL* head_ptr){
    if(head_ptr == NULL)
    {return 0;}
    else{return head_ptr->value + SCL_sum(head_ptr->next);}
}

void SCL_integral_aux(TipoNodoSCL* head_ptr, float sum_till_now) {
    if(head_ptr != NULL){
        if(sum_till_now != head_ptr->value){
            sum_till_now += head_ptr->value;
            head_ptr->value = sum_till_now;
        }
        SCL_integral_aux(head_ptr->next, sum_till_now);
    }
}

void SCL_integral(TipoNodoSCL* head_ptr){
    if(head_ptr != NULL){
        SCL_integral_aux(head_ptr , head_ptr->value);
    }
}

//Assumo che le due scl siano di uguale dimensione
float SCL_dot(TipoNodoSCL* head1_ptr, TipoNodoSCL* head2_ptr) {
    if(head1_ptr == NULL || head2_ptr == NULL){
        return 0;
    }else{ return head1_ptr->value*head2_ptr->value + SCL_dot(head1_ptr->next , head2_ptr->next);}

}

