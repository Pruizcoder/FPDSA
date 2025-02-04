
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
      for (int j = dim; j > 0; j--)
      {
         swap(&v[i],&v[j]);
      }
      
   }
   
}

void inizializza_vettore (int v[], int dim, int valore_iniziale)
{
for (int i = 0; i < dim-1; i++)
{
   v[i]= valore_iniziale;
}
}


void stampa_isto_vert(int v[], int dim, int val_min, int val_max)
{
   int max = trova_max(v, dim);
   for (int livello = max; livello > 0; livello--)
    {
        for (int i = 0; i < dim; i++)
        {
            if (v[i] >= livello)
            {
                printf(" * "); 
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n"); 
    }
   
   for (int i = val_min; i < val_max+1; i++)
      {
         printf("%2d ", i);
      }
      printf("\n");
}

int trova_max(int v[], int dim)
{
   int max = v[0]; 
   for (int i = 0; i < dim; i++)
   {
      if (max < v[i])
      {
         max = v[i];
      }
      
   }
   
   return max;
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


void scorrimento_lineare(int v[], int dim)
{
   for (int i = dim; i >= 0; i--)
   {
      v[i]= v[i-1];
   }
   
}

void selection_sort_desc(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (array[j] > array[max_idx]) {
                max_idx = j; 
            }
        }
        if (max_idx != i) {
            int temp = array[i];
            array[i] = array[max_idx];
            array[max_idx] = temp;
        }
    }
}
void bubblesort_cres(int v[], int n) {
int i,k;
int temp;
for(i = 0; i<n-1; i++) {
 for(k = 0; k<n-1-i; k++) {
         if(v[k] > v[k+1]) {
          temp = v[k];
          v[k] = v[k+1];
          v[k+1] = temp;
         }
 }
}
}
void bubblesort_decr(int v[], int n) {
int i,k;
int temp;
for(i = 0; i<n-1; i++) {
 for(k = 0; k<n-1-i; k++) {
         if(v[k] < v[k+1]) {
          temp = v[k];
          v[k] = v[k+1];
          v[k+1] = temp;
         }
 }
}
}