#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"

#define MAX 100



int main()
{
   int dim = MAX;
   int v[dim];
   int subv[dim];
   int val = 0;
   int ind_max=0 , ind_min =0;
   int indirizzo = 0;

   printf ("inserisci il valore da cercare\n");
   scanf("%d", &val);
   leggi_vettore(v, MAX);

   do
   {
      printf("inserisci l'indirizzo massimo del sottovettore\n");
      scanf("%d", &ind_max);
   } while (ind_max >= sizeof(v)/sizeof(v[0]));
   
   do
   {
      printf("inserisci l'indirizzo minimo del sottovettore\n");
      scanf("%d", &ind_min);

   } while (ind_min > ind_max);

   int subdim = ind_max - ind_min;
   crea_sottovettore(v,subv,subdim, ind_max,ind_min);
   indirizzo = ricerca_lineare( subv, subdim, val);





   if (indirizzo >= 0)
   {
   printf("il valore cercato [%d], si trova all' indirizzo n^%d\n", val, indirizzo);
   }
   else
   {
      printf("il valore cercato non e' presente nel vettore\n");
   }
   
   
   return EXIT_SUCCESS;
}

