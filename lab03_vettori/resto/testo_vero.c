#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void valori_resto(int n, int valori[]);
int resto_in_monete(int resto, int n, int valori[], int numeromonete[]);
int main()
{
  int n=0;
  int resto = 0;
  
  printf("inserisci il numero di valori da scrivere nel vettore ");
  scanf("%d", &n);

  int valori[n];
  int numeromonete[n];

  valori_resto(n, valori);
  
  printf("inserisci il valore totale del resto: ");
  scanf("%d", &resto);
  
  printf("calcolo il resto...\n");

  resto_in_monete(resto, n, valori, numeromonete);
  
  
     for (int j = 0; j < n; j++) 
      {
        printf("%d: %d\n", valori[j], numeromonete[j]);
      }

  
return EXIT_SUCCESS;
}

void valori_resto(int n, int valori[])
{
    
      int valore=0;

      for(int i=0; i < n; i++)
      { 
      
      scanf("%d", &valore);

      valori[i] = valore;
      }

      for (int j = 0; j < n; j++) 
      {
        printf("v[%d] = ", j);
      }
 
}

int resto_in_monete(int resto, int n, int valori[], int numeromonete[])
{
    
    int m;
    int q;
    int i = 1;
    do
    {
    
      m = valori[n-i];
      q = floor(resto/m);
      resto = resto - (q * m);
      numeromonete[n-i] = q; 
      i++;
    } while (resto>0);
    
    while(i<=n)
    {
      numeromonete[n-i]=0;
      i++;
    }


 return *numeromonete;   
}
