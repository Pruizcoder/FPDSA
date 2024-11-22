#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void crea_sottovettore(int v[], int subv[],int subdim, int val_max, int val_min);

int ricerca_lineare(int v[], int dim, int val);

int leggi_vettore (int v[], int dim_max);

void stampa_vettore (int v[], int dim);

int main()
{
   int dim = MAX;
   int v[dim];
   int val = 0;
   int ind_max=0 , ind_min =0;
   int indirizzo = 0;

   leggi_vettore(v, MAX);
   printf ("inserisci il valore da cercare:");
   scanf("%d", &val);
   
   do
   {
      printf("inserisci l'indice del primo elemento del sottovettore in cui cercare:");
      scanf("%d", &ind_min);

   } while (ind_min >= sizeof(v)/sizeof(v[0]));

   do
   {
      printf("inserisci l'indice dell'ultimo elemento del sottovettore in cui cercare:");
      scanf("%d", &ind_max);
   } while (ind_max >= sizeof(v)/sizeof(v[0]));
   printf(" ricerca lineare...");
   int subdim = ind_max - ind_min + 1;
   int subv[subdim];
   crea_sottovettore(v,subv,subdim, ind_max,ind_min);
   //stampa_vettore(subv, subdim);
   indirizzo = ricerca_lineare( subv, subdim, val);





   if (indirizzo >= 0)
   {
   printf("\nv[%d]=%d", indirizzo, val);
   }
   else
   {
      printf("valore non trovato");
   }
   
   
   return EXIT_SUCCESS;
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



void crea_sottovettore(int v[], int subv[],int subdim, int val_max, int val_min)
{  
   int j=0;
   for (int i = val_min; i < val_max+1; i++)
   {

      //printf("%d\n", i);
      subv[j]= v[i];
      j++;   
   }
   
}


int ricerca_lineare(int v[], int dim, int val)
{
for (int i = 0; i < dim; i++)
{
   //printf("v[%d]= %d\n", i, v[i]);
   if (val == v[i])
   {

      return i;
   }
}
return -1;
}

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf (" inserisci il numero di valori da scrivere nel vettore: ");
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