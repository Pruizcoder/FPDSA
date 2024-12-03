#include <stdio.h>
#include <stdlib.h>

int leggi_vettore (int v[], int dim_max);
void scorrimento_lineare(int v[], int dim);
void stampa_vettore (int v[], int dim);
#define MAX 100
int main(){
   int v[MAX];
   int dim = 0;
   dim = leggi_vettore(v,MAX);
   scorrimento_lineare(v,dim);
   printf("applico lo scorrimento...\n");
   stampa_vettore(v, dim);
   return EXIT_SUCCESS;

}


void scorrimento_lineare(int v[], int dim)
{
   int temp = v[dim-1];
   for (int i = dim; i > 0; i--)
   {
      v[i]= v[i-1];
   }
   v[0]= temp;
}

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf ("inserisci il numero di valori da scrivere nel vettore:");
   scanf ("%d", &dim);

   if (dim > dim_max)
   {
      printf ("sono troppi, potranno essere inseriti %d elementi\n", dim_max);
      dim = dim_max;
   }

   // leggi gli elementi
   for (i = 0; i < dim; i++)
   {

      printf ("v[%d] = ", i);
      // printf ("v[%d] = ", i);
      scanf ("%d", &v[i]);
   }

   return dim;
}


void stampa_vettore (int v[], int dim)
{
   int i;

   // stampa gli elementi
   for (i = 0; i < dim; i++)
   {
      printf ("v[%d] = %d\n", i, v[i]);
   }

   return;
}