#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE 40 //numero massimo di date nel file di input date 
#define MAX_ORARIO 8 //numero massimo per la string orario
#define MAX_NOME 64 //64 caratteri dovrebbero bastare per scrivere nome e cognome
#define MAX_DISP 1000 //massimo per le disponibilità
struct data
{
   int giorno;
   int mese;
   int anno;
};

struct evento
{
   struct data data;
   char ora [MAX_ORARIO];

};
struct disponibilita
{
   char nome[MAX_NOME];
   struct evento evento;
};

void leggi_data(struct data *data, char data_s[]);
int leggi_disponibilita(struct disponibilita disp[], char nome_file[]);
int leggi_eventi(struct evento ev[], char nome_file[]);
void trova_eventi(struct evento disp[], struct evento ev[], int dim_ev, int dim_disp);

int main(int argc,char* argv[])
{
   struct evento eventi[MAX_DATE];
   struct disponibilita disp[MAX_DISP];
   int max_disp = 0, max_ev = 0;
   max_disp = leggi_disponibilita(disp, argv[2]);
   max_ev = leggi_eventi(eventi, argv[1]);

       for (int i = 0; i < max_disp; i++) {
        trova_eventi(&disp[i].evento, eventi, max_disp, max_ev);
    }

return EXIT_SUCCESS;
}

void leggi_data(struct data *data, char data_s[])
{  
   int i = 0, j= 0;
   char buffer[MAX_ORARIO];
while ((data_s[i] < '0')|| (data_s[i] > '9'))
   {
      buffer[j] = data_s[i];
      i++, j++;

   }
   buffer[j] = '\0';// termino la string
   data->giorno = atoi(buffer);
   j = 0;
while ((data_s[i] < '0')|| (data_s[i] > '9'))
   {
      buffer[j] = data_s[i];
      i++; j++;
   }
   buffer[j] = '\0';// termino la string
   data->mese = atoi(buffer);

   j = 0;
while ((data_s[i] < '0')|| (data_s[i] > '9'))
   {
      buffer[j] = data_s[i];
      i++; j++;
   }
   buffer[j] = '\0';// termino la string
   data->anno = atoi(buffer);
}

int leggi_disponibilita(struct disponibilita disp[], char nome_file[])
{
   FILE *fp = fopen(nome_file, "r");
   char nome[32];
   char cognome [32];
   char data[16];
   if (fp == NULL)
   {
      printf("il file %s non esiste", nome_file);
      exit(EXIT_FAILURE);
   }
   int i = 0;
   while (fscanf(fp, "%s %s %s %s", nome, cognome, data, disp[i].evento.ora))
   {
      i++;
      strcat(nome, cognome);
      strcpy(nome, disp->nome);
      leggi_data(&disp->evento.data, data);
      i++;
   }
   
fclose(fp);
return i;

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
   while (fscanf(fp, "%s %s", ev[i].ora, data))
   {
      leggi_data(&ev[i].data, data);
      i++;
   }
   
   fclose(fp);
   return i;
   
}

void trova_eventi(struct evento disp[], struct evento ev[], int dim_ev, int dim_disp)
{
   int max_disp = 0, prev_max = 0, id_max = 0;
   for (int i = 0; i < dim_ev; i++)
   {
      for (int j = 0; j < dim_disp; i++)
      {
         if ((disp[i].data.giorno == ev[j].data.giorno) && (disp[i].data.mese == ev[j].data.mese) && (disp[i].data.anno == ev[j].data.anno))
         {
            max_disp++;

         }
      }
      if (max_disp >prev_max)

      {
         prev_max = max_disp;
         id_max = i;
      }
      
      
   }printf("%d/%d/%d a %s : %d persone", ev[id_max].data.giorno, ev[id_max].data.mese, ev[id_max].data.giorno, ev[id_max].ora, prev_max);
   
   }