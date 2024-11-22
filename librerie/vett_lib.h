#ifndef VETT_LIB_H
#define VETT_LIB_H

int leggi_vettore (int v[], int dim_max);
void stampa_vettore (int v[], int dim);
void inverti_vettore (int v[], int dim);
void leggi_sequenza_e_aggiorna_i_contatori (int contatori[], int val_min, int val_max);
void inizializza_vettore (int v[], int dim, int valore_iniziale);
void stampa_istogramma_orizzontale (int v[], int dim);
void disegna_linea (int lunghezza);
void stampa_isto_vert(int v[], int dim, int val_min, int val_max);
int trova_max(int v[], int dim);
int ricerca_lineare(int v[], int dim, int val);
void crea_sottovettore(int v[], int subv[],int subdim, int val_max, int val_min);

#endif 