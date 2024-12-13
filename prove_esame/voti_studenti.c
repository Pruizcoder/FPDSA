#include <stdio.h>
#include <stdlib.h>

#define MAXSTUD 100
#define MAXVOTI 50

struct data
{
 int giorno;
 int mese;
 int anno;
};



struct verifica
{
   struct data data_verifica;
   int voto;  
};


struct studente
{
char nome[32];
char cognome[32];
struct verifica verifiche[50];
int n_verifiche;
};



int main()
{
   FILE *file_di_input, *file_di_output;
   char nome_file_di_input[32];
   char nome_file_di_output[32];


   if ((file_di_input = fopen(nome_file_di_input, "r"))== NULL)
   {
      printf("errore nell' apertura del file %s\n", nome_file_di_input);
      exit(EXIT_FAILURE);
   }
   
if ((file_di_output = fopen(nome_file_di_output, "w"))== NULL)
   {
      printf("errore nella creazione del file %s\n", nome_file_di_output);
      exit(EXIT_FAILURE);
   }



   return 0;
}



void leggi_file (FILE *fi, FILE *fo)
{
   int i =0;
   while (fgetc(fi) != '.')
   {
      while (fgetc(fi)!= ',')
      {

      }
      
   }
   

}