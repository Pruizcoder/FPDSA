#include <stdio.h>
#include <stdlib.h>
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/vett_lib.h"
#include "/home/pruiz/uni/esercizi/FPDSA/FPDSA/librerie/utility.h"
#define MAX 20

void calcola_resto(int resto, int dim, int valori[], int output[]);
void stampa_resto(int v_a[],int v_b[], int dim);


int main()
{
   int valori[MAX];
   int output[MAX];
   int resto = 0;
   int dim = 0;
   dim = leggi_vettore(valori, MAX);
   selection_sort_desc(valori,dim);
   //stampa_vettore(valori, dim);
   printf("inserisci il valore totale del resto: ");
   scanf("%d", &resto);
   calcola_resto(resto, dim, valori, output);
   printf("\ncalcolando il resto...\n");
   stampa_resto(valori,output,dim);
   
   return EXIT_SUCCESS;

}

void calcola_resto(int resto, int dim, int valori[], int output[])
{
   for (int i = 0; i < dim; i++)
   {
      while (valori[i]< resto)
      {
         resto = resto - valori[i];
         output[i]++;
      }
      
   }
   
}


void stampa_resto(int v_a[],int v_b[], int dim)
{
   for (int i = 0; i < dim; i++)
   {
      printf("%d: %d\n", v_a[i], v_b[i]);
   }
   
}

