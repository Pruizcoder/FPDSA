#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID 16//impongo 16 caratteri per la dichiarazione dell'ID
#define MAX_DESC 128 //impongo 128 caratteri per la descirzione
#define MAX_NOME 32  //impongo 32 carratteri per il nome degli acquirenti
#define MAX_ARTICOLI 100 //impongo 100 articoli massimo all' asta(richiesto dal testo)
#define MAX_OFFERTE 1000 // impongo un numero alto di offerte

struct articolo
{
   char id[MAX_ID];
   char descrizione[MAX_DESC];
   int prezzo;
};
struct offerta
{
   char id[MAX_ID];
   char nome[MAX_NOME];
   int valore;
};

int leggi_file_articoli(FILE* fp,struct articolo articoli[])
{
   int i = 0;
   while (fscanf(fp,"%s %s %d", articoli[i].id,articoli[i].descrizione,&articoli[i].prezzo ) != EOF)
   {
      i++;
   }
   return i;
}

int leggi_file_offerte(FILE* fp,struct offerta offerte[])
{
   int i = 0;
   while (fscanf(fp,"%s %s %d", offerte[i].id,offerte[i].nome,&offerte[i].valore ) != EOF)
   {
      i++;
   }
   return i;
}


void trova_vincente(struct articolo articoli[], struct offerta offerte[], int dim_articoli, int dim_offerte)
{
   char vincente[MAX_NOME];
   for (int i = 0; i < dim_articoli; i++)
   {
      for (int  j = 0; j < dim_offerte; j++)
      {
         if (offerte[j].valore > articoli[i].prezzo)
         {
            articoli[i].prezzo = offerte[j].valore;
            strcpy(vincente, offerte[j].nome);
            
         }
         
      }
      printf("%s ha vinto l'asta n. %s di %s con un' offerta di %d", vincente,articoli[i].id, articoli[i].descrizione, articoli[i].prezzo);        
      i++;
   }
   
}

int main (int argc, char *argv[])
{
   struct articolo articoli[MAX_ARTICOLI];
   int dimarticoli = 0;
   struct offerta offerte[MAX_OFFERTE];
   int dimofferte = 0;
   FILE* file_articoli;
   FILE* file_offerte;
   file_articoli= fopen(argv[1], "r");
   file_offerte = fopen(argv[2], "r");
   if (file_articoli == NULL || file_offerte == NULL)
   {
      printf("errore nell' apertura dei file\n");
      exit(EXIT_FAILURE);
   }
   
   leggi_file_articoli(file_articoli, articoli);
   leggi_file_offerte(file_offerte, offerte);
   fclose(file_articoli);
   fclose(file_offerte);

   trova_vincente(articoli, offerte, dimarticoli, dimofferte);
   return EXIT_SUCCESS;


}
