#pragma once

#include "tipo_nodo_scl.h"

/****************************
 * TipoNodoSCL
 *
 * nei seguenti esercizi verra' usata la struttura ListItem
 * contenuta nel file tipo_nodo_scl.h, riportata(commentata) di seguito
 **************************** */
/*
struct TipoNodoSCL {
    float value;
    struct TipoNodoSCL* next;
};
*/

/****************************
 * SCL_sum
 *
 * ritorna la somma, calcolata ricorsivamente, degli elementi della lista
 **************************** */
float SCL_sum(TipoNodoSCL* head_ptr);

/****************************
 * SCL_integral
 *
 * scrivere, ricorsivamente, in ogni elemento della lista la somma degli elementi precedenti
 **************************** */
void SCL_integral(TipoNodoSCL* head_ptr);

/****************************
 * SCL_dot
 *
 * ritorna il prodotto scalare, calcolato ricorsivamente, delle liste con puntatori
 * alla testa head1_ptr e head2_ptr
 **************************** */
float SCL_dot(TipoNodoSCL* head1_ptr, TipoNodoSCL* head2_ptr);

