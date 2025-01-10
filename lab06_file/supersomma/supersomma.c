#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_FILENAME 32
#define MAX_N 2048

void supersomma (char a[], char b[], char c[]);
void leggi_file(FILE *fi);

int main()
{
   FILE *file_somma;
   char file_name[MAX_FILENAME];
   printf("nome del file di input:");
   scanf("%s", file_name);
   
   file_somma = fopen(file_name, "r");
   if (file_somma == NULL)
   {
    printf("errore nell' apertura del file: %s", file_name);
    exit(EXIT_FAILURE);
   }
   

   leggi_file(file_somma);

   fclose(file_somma);


   

}

void supersomma(char a[], char b[], char c[])
{
   int i_a, i_b, i_c, riporto, risultato_somma;

   i_a = strlen(a) - 1;
   i_b = strlen(b) - 1;

   i_c = (i_a > i_b) ? i_a : i_b;

   c[i_c + 1] = '\0';

   riporto = 0;

   while (!(i_a < 0 && i_b < 0))
   {
      if (i_a >= 0 && i_b >= 0)
      {
         risultato_somma = (a[i_a] - '0') + (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';
         riporto = risultato_somma / 10;
      }
      else if (i_a >= 0 && i_b < 0)
      {
         risultato_somma = (a[i_a] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';
         riporto = risultato_somma / 10;
      }
      else
      {
         risultato_somma = (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';
         riporto = risultato_somma / 10;
      }

      i_a--;
      i_b--;
      i_c--;
   }

   if (riporto > 0)
   {
      for (int i = strlen(c); i >= 0; i--)
      {
         c[i + 1] = c[i]; 
      }
      c[0] = riporto + '0'; 
   }
}


void leggi_file(FILE *fi)
{
   char n1[MAX_N];
   char n2[MAX_N];
   char ris[MAX_N];
   char buffer[MAX_N+32];
   while (fgets(buffer, sizeof(buffer),fi))
   {   
   sscanf(buffer,"%s + %s",n1,n2);
   supersomma(n1,n2,ris);
   printf("%s + %s = %s\n", n1, n2 ,ris);
   }
   
}
