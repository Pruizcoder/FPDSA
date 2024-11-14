
#include <stdio.h>
#include <stdlib.h>
#include "vett_lib.h"
#include "utility.h"

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf ("leggi_vettore: quanti elementi vuoi inserire? ");
   scanf ("%d", &dim);

   if (dim > dim_max)
   {
      printf ("sono troppi, potranno essere inseriti %d elementi\n", dim_max);
      dim = dim_max;
   }

   // leggi gli elementi
   for (i = 0; i < dim; i++)
   {
      printf ("inserisci l'elemento di indice %d: ", i);
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

void inverti_vettore (int v[], int dim)
{
   for (int i = 0; i < dim; i++)
   {
      for (int j = dim; j > 0; j++)
      {
         swap(&v[i],&v[j]);
      }
      
   }
   
}

void inizializza_vettore (int v[], int dim, int valore_iniziale)
{
for (int i = 0; i < dim; i++)
{
   v[i]= valore_iniziale;
}
}