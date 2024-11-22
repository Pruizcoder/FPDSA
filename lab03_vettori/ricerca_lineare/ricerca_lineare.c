#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"

#define MIN 0
#define MAX 100



int main()
{
   int dim = MAX;
   int v[dim];
   int val = 0;
   int indirizzo = 0;
   printf ("inserisci il valore da cercare\n");
   scanf("%d", &val);
   leggi_vettore(v, MAX);
   indirizzo = ricerca_lineare( v, dim, MAX, MIN, val);
   if (indirizzo >= 0)
   {
   printf("il valore cercato [%d], si trova all' indirizzo n^%d", val, indirizzo);
   }
   else
   {
      printf("il valore cercato non e' presente nel vettore\n");
   }
   
   
   return EXIT_SUCCESS;
}
