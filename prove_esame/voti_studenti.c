#include <stdio.h>
#include <stdlib.h>




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
}
;