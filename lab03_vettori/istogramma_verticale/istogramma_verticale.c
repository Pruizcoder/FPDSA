#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"

/* dichiarazione delle f.ni prototipo */
int leggi_vettore (int v[], int dim_max);
void stampa_vettore (int v[], int dim);

/* dichiarazione delle costanti */
#define MAXARR 100 // massimo numero nell' array
/* massimo e minimo dei valori inseribili */
#define MAX 20
#define MIN 0 

int main()
{
   int contatori[MAX - MIN + 1];
   int v[MAXARR];
   int dim = 0;

   inizializza_vettore(v,MAXARR,0);
   inizializza_vettore(contatori,MAXARR,1);
   dim = leggi_vettore(v, MAXARR);
   stampa_vettore(contatori, MAX - MIN +1);

   return EXIT_SUCCESS;

}
