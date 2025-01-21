#include <stdio.h>
#include <stdlib.h>


struct lingue
{
   char lingua[3];
   char gennaio[10];
   char febbraio[10];
   char marzo[10];
   char aprile[10];
   char maggio[10];
   char giugno[10];
   char luglio[10];
   char agosto[10];
   char settembre[10];
   char ottobre[10];
   char novembre[10];
   char dicebre[10];
   };

struct data
{
   int giorno;
   int mese;
   int anno;
   };


struct persona
{
   char nome[20];
   char cognome[20];
   struct data data_nascita;
   struct lingue lingua_parlata;
};

int main()
{
   int nlingue;
    nlingue = 0;
   struct lingue lista_lingue;

}