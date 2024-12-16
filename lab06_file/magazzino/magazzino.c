#include <stdio.h>
#include <stdlib.h>

#define MAX_ARTICOLO 100
#define MAX_FILENAME 32



struct articolo
{
   char nome[32];
   int q;
};

void leggi_file(FILE *fi, struct articolo articoli[]);


int main()
{
   FILE *file_input;
   char file_name[MAX_FILENAME];
   struct articolo articoli[MAX_ARTICOLO];

   printf("inserisci il nome del file:\n");
   scanf("%s", &file_name);
   if ((file_input = fopen(file_name, "r") )== NULL)
   {
     
      printf("errore nell' apertura del file %s\n", file_name);
      exit(EXIT_FAILURE);
   }

   leggi_file(file_input, articoli);

   printf("%s", articoli[0].nome);
   

   return EXIT_SUCCESS;
}


void leggi_file(FILE *fi, struct articolo articoli[])
{
   int i = 0;
   int j = 0;
   while (fgetc(fi)!= '\n')
   {
   
      while (fgetc(fi)!= '"');
      {
         articoli[i].nome[j] = fgetc((fi));
      }
   }
   
}