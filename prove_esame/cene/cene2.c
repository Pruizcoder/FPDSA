#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE 40   // numero massimo di date nel file di input date
#define MAX_ORARIO 16 // numero massimo per la string orario
struct data
{
   int giorno;
   int mese;
   int anno;
};

struct evento
{
   struct data data;
   char ora[MAX_ORARIO];
   int presenze;
};

void leggi_data(struct data *data, char data_s[]);
void leggi_disponibilita(struct evento ev[], char nome_file[], int max_ev);
int leggi_eventi(struct evento ev[], char nome_file[]);
void stampa_presenze(struct evento ev[], int max_ev);

int main(int argc, char *argv[])
{
   int max_ev = 0;
   struct evento eventi[MAX_DATE];

   max_ev = leggi_eventi(eventi, argv[1]);
   leggi_disponibilita(eventi, argv[2], max_ev);
   stampa_presenze(eventi, max_ev);

   return EXIT_SUCCESS;
}

void leggi_disponibilita(struct evento ev[], char nome_file[], int max_ev)
{
   FILE *fp = fopen(nome_file, "r");
   if (fp == NULL)
   {
      printf("il file %s non esiste", nome_file);
      exit(EXIT_FAILURE);
   }

   while (fgetc(fp) != EOF)
   {

      struct evento datat;
      fscanf(fp, "%*[^:]: %d/%d/%d %s", &datat.data.giorno, &datat.data.mese, &datat.data.anno, datat.ora);
      // printf("%d-%d-%d-%s\n", datat.data.giorno,datat.data.mese,datat.data.anno,datat.ora );  printf di debug
      // printf("-%d-%d-%d-\n", datat.giorno, datat.mese, datat.anno);
      for (int k = 0; k < max_ev; k++)
      {
         if (ev[k].data.giorno == datat.data.giorno &&
             ev[k].data.mese == datat.data.mese &&
             ev[k].data.anno == datat.data.anno &&
             strcmp(ev[k].ora, datat.ora) == 0)
         {
            ev[k].presenze++;
         }
      }
      while (fgetc(fp) != '\n')
      {
      }
   }
   fclose(fp);
}

void leggi_data(struct data *data, char data_s[])
{
   sscanf(data_s, "%d/%d/%d", &data->giorno, &data->mese, &data->anno);
}

int leggi_eventi(struct evento ev[], char nome_file[])
{
   char data[10];
   FILE *fp = fopen(nome_file, "r");
   if (fp == NULL)
   {
      printf("il file %s non esiste", nome_file);
      exit(EXIT_FAILURE);
   }
   int i = 0;
   while (fscanf(fp, "%s %s", ev[i].ora, data) != EOF)
   {
      ev[i].presenze = 0;
      leggi_data(&ev[i].data, data);
      i++;
   }

   fclose(fp);
   return i;
}

void stampa_presenze(struct evento ev[], int max_ev)
{
   if (max_ev == 0)
   {
      printf("Nessun evento disponibile.\n");
      return;
   }

   // Trova il massimo numero di presenze
   int max_presenze = 0;
   for (int i = 0; i < max_ev; i++)
   {
      if (ev[i].presenze > max_presenze)
      {
         max_presenze = ev[i].presenze;
      }
   }

   // Stampa tutti gli eventi con il massimo numero di presenze
   for (int i = 0; i < max_ev; i++)
   {
      if (ev[i].presenze == max_presenze)
      {
         printf("%d/%d/%d a %s: %d persone\n",
                ev[i].data.giorno,
                ev[i].data.mese,
                ev[i].data.anno,
                ev[i].ora,
                ev[i].presenze);
      }
   }
}