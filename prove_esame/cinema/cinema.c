#include <stdio.h>
#include <stdlib.h>

#define DIM_ID 128 // dimensione del vettore ID
#define DIM_BUFFER 256 // dimesionde per il buffer delle stringhe
#define DIM_NOME 128 // dimensione del vettore per i nomi degli spettacoli

struct orario
{
   int ora;
   int minuti;
};

struct data
{
   int giorno;
   int mese;
   int anno;
};

struct sala
{
   int sala;
   int posti;
};

struct evento
{
   char id[DIM_ID];
   char spettacolo[DIM_BUFFER];
   struct data data;
   struct orario ora;
   struct sala sala;
};

// funzioni prototipo
int LeggiDati(char* file_name, struct evento ev[]);
void cercaPrenotazioni(struct evento proiezioni[], int n_proi, struct evento prenotazioni[], int n_pren);
void stampaProiezioni(struct evento proiezioni[], int n_proi);

int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      printf("errore, manca un file\n ");
      exit(EXIT_FAILURE);
   }
   struct evento proiezioni[200];
   struct evento prenotazioni[1000];
   int n_proi = LeggiDati(argv[1], proiezioni);
   int n_pren = LeggiDati(argv[2], prenotazioni);
   cercaPrenotazioni(proiezioni, n_proi, prenotazioni, n_pren);

   stampaProiezioni(proiezioni, n_proi);
   return EXIT_SUCCESS;
}



int LeggiDati(char* file_name, struct evento ev[]){
   FILE *fp = fopen(file_name, "r");
   if(fp == NULL)
   {
      printf("errore nell'apertura del file %s\n", file_name);
      exit(EXIT_FAILURE); // segnalo l'errore di apertura e termino il programma
   }
   char buffer[DIM_BUFFER]; //buffer di lettura
   int j; //variabile di conteggio delle righe
   j = 0;
   while (fgets(buffer, DIM_BUFFER, fp) != NULL)
   {
      int i;
      i = 0;
      int k;
      k = 0;
      while (buffer[i] != ' ') // fino allo spazio copia i caratteri nell' ID
      {
      ev[j].id[k] = buffer[i];
      i++;
      k++;
      }
      k++;
      ev[j].id[k] = '\0'; // termino la string
      i++; // salto lo spazio
      k = 0; // resetto la variabile ausiliaria
      i++; // salto le virgolette
      while (buffer[i] != '"') // fino alle virgolette
      {
         ev[j].spettacolo[k] = buffer[i];
         i++;
         k++;
      }
      k++;
      ev[j].spettacolo[k] = '\0'; // termino la string
      k = 0; // resetto k
      i++; // salto il secondo '"' 
      i++; //salto lo spazio
      char buffer2[DIM_BUFFER];
      while (buffer[i] != '\n')//fino a fine riga
     {
         buffer2[k] = buffer[i];
         i++;
         k++;
      } //salvo il resto della string in un altra string da processare

      buffer2[k] = '\0';
sscanf(buffer2, " %d/%d/%d %d:%d sala %d posti %d",
       &ev[j].data.giorno,
       &ev[j].data.mese,
       &ev[j].data.anno,
       &ev[j].ora.ora,
       &ev[j].ora.minuti,
       &ev[j].sala.sala,
       &ev[j].sala.posti);
      //printf("%d, %d\n", ev[j].ora.ora, ev[j].sala.posti);
      j++; // incremento il numero di righe
   }
   fclose(fp); // chiudo il file
   //printf("---\n");
   return j; // conosco il numero di righe
}

void cercaPrenotazioni(struct evento proiezioni[], int n_proi, struct evento prenotazioni[], int n_pren)
{
   for (int i = 0; i < n_proi; i++)
   {
      for (int j = 0; j < n_pren; j++)
      {
          // fai la comparazione tra tutti i parametri tranne id
         if (proiezioni[i].data.giorno == prenotazioni[j].data.giorno && proiezioni[i].data.mese == prenotazioni[j].data.mese && proiezioni[i].data.anno == prenotazioni[j].data.anno && proiezioni[i].ora.ora == prenotazioni[j].ora.ora && proiezioni[i].ora.minuti == prenotazioni[j].ora.minuti && proiezioni[i].sala.sala == prenotazioni[j].sala.sala)
         {
            proiezioni[i].sala.posti = proiezioni[i].sala.posti - prenotazioni[j].sala.posti;
         }
         
      }
      
   }
}

void stampaProiezioni(struct evento proiezioni[], int n_proi)
{
   for (int i = 0; i < n_proi; i++)
   {
      printf("%s, %d/%d/%d ore %d:%d, sala %d posti disponibili %d\n",proiezioni[i].spettacolo, proiezioni[i].data.giorno, proiezioni[i].data.mese, proiezioni[i].data.anno, proiezioni[i].ora.ora, proiezioni[i].ora.minuti, proiezioni[i].sala.sala, proiezioni[i].sala.posti);
   }
}

