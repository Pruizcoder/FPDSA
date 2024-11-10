#include <stdio.h>
#include <stdlib.h>

long double calcolafattoriale(int n);

int main(){
   int n = 0;
   printf("inserisci il numero di cui vuoi calcolare il fattoriale\n");
   scanf("%d", &n);
   printf("%.0Lf\n", calcolafattoriale(n));

   return EXIT_SUCCESS;
}

long double calcolafattoriale(int n)
{
    long double fattoriale = 1;

   for (int i = 1; i < n+1; i++)
   {
      fattoriale = fattoriale * i;
      //printf("%d\n", fattoriale);
   }
   return fattoriale;
}