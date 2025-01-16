#include <stdio.h>
#include <stdlib.h>

#define MAX_COD_LEN 8
#define MAX_BOX_LEN 1.5
#define MAX_N_BOX 1000

struct scatola
{
   char cod[MAX_COD_LEN + 1];
   double l;
   int utilizzata;
};

int leggi_file(FILE *fp, struct scatola scatole[MAX_N_BOX]);
void ordina_carrelli(struct scatola scatole[MAX_N_BOX], int n_scatole);
int cerca_scatola(struct scatola scatole[MAX_N_BOX], int n_scatole, double lunghezza_rimasta);


int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("argomenti non validi!\n");
      exit(EXIT_FAILURE);
   }

   FILE *fp;
   fp = fopen(argv[1], "r");

   if (fp == NULL)
   {
      printf("errore nell'apertura del file!\n");
      exit(EXIT_FAILURE);
   }

   struct scatola scatole[MAX_N_BOX];
   int n_scatole;

   n_scatole = leggi_file(fp, scatole);


   ordina_carrelli(scatole, n_scatole);

   return EXIT_SUCCESS;
}

int leggi_file(FILE *fp, struct scatola scatole[MAX_N_BOX])
{
   int i;
   i = 0;

   while (fscanf(fp, "%s %lf", scatole[i].cod, &scatole[i].l) != EOF)
   {
      scatole[i].utilizzata = 0;
      i++;
   }

   return i;
}

void ordina_carrelli(struct scatola scatole[MAX_N_BOX], int n_scatole)
{
   double lunghezza_rimasta;
   int index, n_carrello;
   int scatole_utilizzate;
   scatole_utilizzate = 0;
   n_carrello = 1;

   while (scatole_utilizzate < n_scatole && n_carrello < 50)
   {
      lunghezza_rimasta = MAX_BOX_LEN;
      printf("%d:/", n_carrello);

      while ((index = cerca_scatola(scatole, n_scatole, lunghezza_rimasta)) != -1)
      {
         scatole[index].utilizzata = 1;
         lunghezza_rimasta -= scatole[index].l;
         scatole_utilizzate++;
         printf("%s/", scatole[index].cod);
      }
      printf("\n");
      n_carrello++;
   }

   return;
}

int cerca_scatola(struct scatola scatole[MAX_N_BOX], int n_scatole, double lunghezza_rimasta)
{
    int i, indice_max = -1;
    double max_length = 0.0;

    for (i = 0; i < n_scatole; i++)
    {
        if (!scatole[i].utilizzata && scatole[i].l <= lunghezza_rimasta && scatole[i].l > max_length)
        {
            max_length = scatole[i].l;
            indice_max = i;
        }
    }

    // Se non è stata trovata nessuna scatola, cerca una scatola di lunghezza 0
    if (indice_max == -1)
    {
        for (i = 0; i < n_scatole; i++)
        {
            if (!scatole[i].utilizzata && scatole[i].l == 0)
            {
                indice_max = i;
                break;
            }
        }
    }

    return indice_max;
}
