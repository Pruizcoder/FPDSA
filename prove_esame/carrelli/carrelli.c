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
void bubbleSortDesc(struct scatola scatole[], int n);
void piazza_scatole(struct scatola scatole[], int n);


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
   leggi_file(file_input, scatole);
   int dimarr = sizeof(scatole) / sizeof(scatole[0]);
   bubbleSortDesc(scatole, dimarr);
   piazza_scatole(scatole, dimarr);
   

   return EXIT_SUCCESS;
 }

void leggi_file(FILE *fi, struct scatola scatole[])
{
   char buffer[16];
   int i= 0;
   while (fgets(buffer, sizeof(buffer), fi))
   {
      sscanf(buffer, "%s %f", scatole[i].id, &scatole[i].dim);
      i++;
   }
   
}


void bubbleSortDesc(struct scatola scatole[], int n)
{
   int i, j;
   struct scatola temp;
   
   for (i = 0; i < n-1; i++) {
      for (j = 0; j < n-i-1; j++) {
         if (scatole[j].dim < scatole[j+1].dim) {
            temp = scatole[j];
            scatole[j] = scatole[j+1];
            scatole[j+1] = temp;
         }
      }
   }
}

void piazza_scatole(struct scatola scatole[], int n)
{
   int i = 0;
   float spazio_rimanente = 1.5;
   while (scatole[i].caricata == false)
   {
      if (spazio_rimanente < scatole[i].dim)
      {
         printf("\n%d:", i+1);
         i = 0;
      }
      else
      {
         spazio_rimanente = spazio_rimanente + scatole[i].dim;
         printf("%s/", scatole[i].id); 
         scatole[i].caricata = true;
      }
      i++;
      
   }
   
}

