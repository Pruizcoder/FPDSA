/*
Si scriva un programma che, usando un’apposita funzione dedicata alla lettura e al controllo di un dato inserito da tastiera, legga una sequenza di numeri compresi tra due valori (un minimo e un massimo passati come argomenti) e ne calcoli la media.

Se l’utente inserisce un numero non compreso nell’intervallo, il programma deve segnalare l’errore e chiedere di nuovo l’inserimento.

SUGGERIMENTO: riutilizzando parte del codice scritto per la precedente esercitazione di laboratorio, si scriva la funzione di lettura del numero che controlli la validità del numero inserito e, se non valido, ne chieda di nuovo l’inserimento.

ATTENZIONE: per questo esercizio non è prevista l'esecuzione automatica in VPL. È sufficiente la consegna del programma dopo averne verificato il funzionamento sul proprio computer.



*/
#include <stdio.h>
#include <stdlib.h>

#define MIN 0
#define MAX 100
#define END -1

void inputdata(int *val);

void media(float *x);



int main()
{
   float val;
   media(&val);
   printf("la media e': %f\n", val);
   return EXIT_SUCCESS;

}

void inputdata(int *x)
{
   int input;
   do
   {

      printf("inserire un valore compreso tra %d e %d (inclusi), inserisci -1 per terminare\n", MIN, MAX);
      scanf("%d", &input);
   } while (!((input >= MIN) && (input <= MAX) || (input == END)));
   printf("dato accettato\n");
   *x = input;
   
}

void media(float *x)
{
   int sommatot = 0;
   int contatore = 0;
   int i=0;
   do
   {
      //printf("i ha il valore di %d dentro il while prima dell' input\n", i);
      inputdata(&i);
      //printf("i ha il valore di %d dentro il while\n", i);
      if (i != END)
      {
      sommatot = sommatot + i;
      contatore++;
      }
      
   }while (i != END);
   
   *x = (float)sommatot / (float)contatore;
}