#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NOME 8
#define L_CARRELLO 1.5
#define MAX_SCATOLE 1000
#define MAX_FILE_NAME 32
struct scatola
{
   bool caricata;
   char id[MAX_NOME];
   float dim;
};


void leggi_file(FILE *fi, struct scatola scatole[]);


int main()
 {
   FILE *file_input;
   char file_name[MAX_FILE_NAME];
   struct scatola scatole[MAX_SCATOLE];
   
   printf("inserisci il nome del file:");
   scanf("%s", file_name);

   file_input = fopen(file_name, "r");
   if (file_input == NULL)
   {
      printf("errore nell'apertura del file %s", file_name);
      exit(EXIT_FAILURE);
   }
   
   return EXIT_SUCCESS;
 }

void leggi_file(FILE *fi, struct scatola scatole[])
{
   
}
