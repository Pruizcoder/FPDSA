// I Leggere il file inerente alle proposte e caricarlo in una struttura in memoria

// II Per ogni proposta individuare il numero di prenotazioni leggendo il file relativo alle prenotazioni

// III Calcolare e stampare quale data proposta ha il numero maggiore di prenotazioni

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE 40
#define MAX_STRING_DIM 64
struct data
{
   int giorno;
   int mese;
   int anno;
};

struct proposta
{
   struct data data;
   char quando[16];
   int n_persone;
};

int caricaDate(struct proposta DateDisponibili[], FILE *fp_disponibilita, int max_dim);
void leggi_file_presenze(FILE *fp_presenze, struct proposta DateDisponibili[], int nDateDisponibili);
struct proposta estrai_dati(char s[]);
int cerca_data(struct proposta DateDisponibili[], struct proposta presenze, int nDateDisponibili);
void stampa_presenze(struct proposta ev[], int max_ev);

int main(int argc, char *argv[])
{
   FILE *fp_disponibilita;
   FILE *fp_presenze;
   // controlla argc
   /*if (argc != 3)
   {
       printf("errore, manca un file ");
       exit(EXIT_FAILURE);
   }*/
   // apri i file
   if ((fp_disponibilita = fopen(/*argv[1]*/ "date_00.txt", "r")) == NULL)
   {
      printf("errore di apertura del file");
      exit(EXIT_FAILURE);
   }

   if ((fp_presenze = fopen(/*argv[2]*/ "disponibilita_00.txt", "r")) == NULL)
   {
      printf("errore di apertura del file ");
      exit(EXIT_FAILURE);
   }

   struct proposta DateDisponibili[MAX_DATE]; // L'array rappresentante il numero di date disponibili

   int nDateDisponibili = caricaDate(DateDisponibili, fp_disponibilita, MAX_DATE); // per soddisfare il punto I

   leggi_file_presenze(fp_presenze, DateDisponibili, nDateDisponibili);
   // stampa_presenze(DateDisponibili, nDateDisponibili); //stampa il file delle date, per verificarne la lettura corretta
   // chiudi i file
   fclose(fp_disponibilita);
   fclose(fp_presenze);

   return EXIT_SUCCESS;
}

int caricaDate(struct proposta DateDisponibili[], FILE *fp_disponibilita, int n_max)
{
   int i = 0;
   while ((fscanf(fp_disponibilita, "%s %d%*c%d%*c%d", DateDisponibili[i].quando, &DateDisponibili[i].data.giorno, &DateDisponibili[i].data.mese, &DateDisponibili[i].data.anno)) != EOF && i < n_max)
   {
      DateDisponibili[i].n_persone = 0;
      i++;
   }
   return i;
}

void leggi_file_presenze(FILE *fp_presenze, struct proposta DateDisponibili[], int nDateDisponibili)
{
   /*DateDisponibili contiene tutti gli eventi possibili,
    devo creare una struct locale temporanea che prende in
    input una presenza e la confronta temporaneamente, senza salvarla
   */
   char s[MAX_STRING_DIM];

   int i = 0;
   while (fgets(s, MAX_STRING_DIM, fp_presenze) != NULL)
   {
      // printf("%s\n",s);
      struct proposta presenza;

      presenza = estrai_dati(s);
      printf("giorno:%d, mese:%d, anno:%d, quando:%s\n", presenza.data.giorno, presenza.data.mese, presenza.data.anno, presenza.quando);

      /*for (int j = 0;j < nDateDisponibili; j++)
      {
       int indice =  cerca_data( DateDisponibili, presenza, i);
       if (indice != -1)
       {
          DateDisponibili[indice].n_persone++;
       }
      }*/

      i++;
   }
}

struct proposta estrai_dati(char s[])
{
   struct proposta art;
   int i;
   int j;
   char t[MAX_STRING_DIM];
   i = 0;
   j = 0;
   while (s[i] != ':')
   {
      i++;
   } //
   i = i + 2; // salto i due punti e gli spazi
              // estrai il giorno
   while (s[i] != '/')
   {
      printf("\ncarattere:%c\n", s[i]);
      t[j] = s[i];
      j++;
      i++;
   }
   j++;
   t[j] = '\0';
   art.data.giorno = atoi(t); // converte il giorno in int
   j = 0;
   i++;

   while ((s[i] < '0') || (s[i] > '9'))
   // estrai il mese
   {
      t[j] = s[i];
      j++;
   }
   t[j] = '\0';
   art.data.mese = atoi(t);
   j = 0;
   i++; // mi posiziono dopo /

   // estrai anno
   while ((s[i] < '0') || (s[i] > '9'))
   {
      t[j] = s[i];
      j++;
      i++;
   }
   t[j] = '\0';
   art.data.anno = atoi(t);
   j = 0;
   i++;
   // estrai quando
   for (; s[i] != '\n'; i++)
   {
      art.quando[j] = s[i];
      j++;
      i++;
   }
   j++;
   art.quando[j] = '\0';
   return art;
}

int cerca_data(struct proposta DateDisponibili[], struct proposta presenze, int nDateDisponibili)
{
   for (int i = 0; i < nDateDisponibili; i++)
   {
      if (DateDisponibili[i].data.giorno == presenze.data.giorno && DateDisponibili[i].data.mese == presenze.data.mese && DateDisponibili[i].data.anno == presenze.data.anno && !(strcmp(DateDisponibili[i].quando, presenze.quando)) == 0)
         return i;
   }
   return -1; // Pasto e data non trovati
}

void stampa_presenze(struct proposta ev[], int max_ev)
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
      if (ev[i].n_persone > max_presenze)
      {
         max_presenze = ev[i].n_persone;
      }
   }

   // Stampa tutti gli eventi con il massimo numero di presenze
   for (int i = 0; i < max_ev; i++)
   {
      if (ev[i].n_persone == max_presenze)
      {
         printf("%d/%d/%d a %s: %d persone\n",
                ev[i].data.giorno,
                ev[i].data.mese,
                ev[i].data.anno,
                ev[i].quando,
                ev[i].n_persone);
      }
   }
}
