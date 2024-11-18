#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"

/* dichiarazione delle f.ni prototipo */
void assegna_valore (int v[], int contatori[], int dim);

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
   inizializza_vettore(contatori, MAX - MIN + 2 ,0);
   dim = leggi_vettore(v, MAXARR);
   assegna_valore(v, contatori, dim);
  // stampa_vettore(contatori, MAX - MIN + 1);
   stampa_isto_vert(contatori,dim, MIN, MAX);
   return EXIT_SUCCESS;

}

void assegna_valore (int v[], int contatori[], int dim)
{
   for (int i = 0; i < dim; i++)
   {
      if (!(v[i]< MIN || v[i]> MAX))
      {
      contatori[v[i]]++;
      }
      else
      {
         printf(" il valore inseritonella cella %d non e' valido\n", i);
      }
            
      
   }
   
   
}

