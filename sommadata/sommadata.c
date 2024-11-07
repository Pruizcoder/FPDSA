#include <stdio.h>
#include <stdlib.h>
int checkdate (int giorno, int mese, int anno);


int bisestile (int anno);


int giorni_del_mese (int mese, int anno);
int aggiungigiorni(int g,int m,int a,int totgiorni);

int main ()
{
   //variablili di conteggio
   int totgiorni = 0;
   //varaibili di input
   int g = 0;
   int  m = 0;
   int  a = 0;
   printf ("Inserire la data (g m a): \n");
   scanf ("%d %d %d", &g, &m, &a);
   printf("inserire il numero di giorni da modificare\n");
   scanf("%d",&totgiorni);
   if (checkdate (g, m, a))
   {
      printf ("valida");
   }
   else
   {
      printf ("non valida\n");
      return EXIT_FAILURE;
   }
   aggiungigiorni(totgiorni);


}
int aggiungigiorni(int g,int m,int a,int totgiorni)
{




}

int giorni_del_mese (int mese, int anno)
{
   switch (mese)
   {
   case 4:
   case 6:
   case 9:
   case 11:
      return 30;
      break;
   case 2:
      if (bisestile (anno))
            return 29;  
         else
            return 28;
   default:
      return 31;
      break;
   }
}