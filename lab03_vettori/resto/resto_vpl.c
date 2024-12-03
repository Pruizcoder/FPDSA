#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void calcola_resto(int resto, int dim, int valori[], int output[]);
void stampa_resto(int v_a[],int v_b[], int dim);
void selection_sort_desc(int array[], int n);
int leggi_vettore (int v[], int dim_max);
void bubblesort_cres(int v[], int n);
void inizializza_vettore (int v[], int dim, int valore_iniziale);


int main()
{
   int valori[MAX];
   int output[MAX];
   int resto = 0;
   int dim = 0;
   dim = leggi_vettore(valori, MAX);
   inizializza_vettore(output,dim,0);
   selection_sort_desc(valori,dim);
   printf("inserisci il valore totale del resto: ");
   scanf("%d", &resto);
   calcola_resto(resto, dim, valori, output);
   printf("calcolo il resto...\n");
   stampa_resto(valori,output,dim);
   
   return EXIT_SUCCESS;

}

void calcola_resto(int resto, int dim, int valori[], int output[])
{
   for (int i = 0; i < dim; i++)
   {
      while (valori[i] <= resto)
      {
         resto = resto - valori[i];
         output[i]++;
      }
      
   }
   return;
}

void stampa_resto(int v_a[],int v_b[], int dim)
{
   for (int i = dim-1; i >= 0; i--)
   {
      printf("%d: %d\n", v_a[i], v_b[i]);
   }
   return;
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

int leggi_vettore (int v[], int dim_max)
{
   int i, dim;

   // leggi la dimensione
   printf ("inserisci il numero di valori da scrivere nel vettore: ");
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

void inizializza_vettore (int v[], int dim, int valore_iniziale)
{
for (int i = 0; i < dim-1; i++)
{
   v[i]= valore_iniziale;
}
}
