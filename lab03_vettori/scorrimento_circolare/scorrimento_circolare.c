#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"

#define MAX 100
int main(){
   int v[MAX];
   int dim = 0;
   dim = leggi_vettore(v,MAX);
   stampa_vettore(v, dim);
   scorrimento_lineare(v,dim);
   stampa_vettore(v, dim);
   return EXIT_SUCCESS;

}

