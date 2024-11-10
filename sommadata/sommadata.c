//librerie
#include <stdio.h>
#include <stdlib.h>



//funzioni prototipo
int checkdate (int giorno, int mese, int anno);
int bisestile (int anno);
int giorni_del_mese (int mese, int anno);
void aggiungigiorni(int *g,int *m,int *a,int *aggiorni);


//main
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
   //input data con controllo in loop
   if (checkdate (g, m, a))
   {
   //input giorni
   printf("inserire il numero di giorni da modificare\n");
   scanf("%d",&totgiorni);

   //calcolo delle tarantelle
   aggiungigiorni(&g, &m, &a, &totgiorni);
   }
   else
   {
      printf("non corretta");
      return EXIT_FAILURE;
   }
   
   

}



//funzione per aggiungere i giorni
void aggiungigiorni(int *g,int *m,int *a,int *aggiorni)
{
   int giorniavanzati = 0;
   giorniavanzati = *aggiorni;
do
{
   if (((*m == 12) && (*g == 31))||((*m == 12) && (giorniavanzati-31 >0)) )
   {
     *g = 0;
     *m = 1;
     ++*a;
     giorniavanzati = giorniavanzati -31;
   
   }
   if (giorniavanzati <= (giorni_del_mese(*m, *a)- *g))
   {
      *g = *g + giorniavanzati;
      //printf di debug
      //printf("%d\n", *g); 
      giorniavanzati = 0;
   }
   else
   {

      //giorni da mettere nel mese dopo
      int giorni_m_p = 0;
      giorni_m_p = *aggiorni - (*aggiorni - (giorni_del_mese(*m, *a)- *g));
      *g = 0;
      ++*m;
      giorniavanzati = giorniavanzati - giorni_m_p;

      
   }
   
   
} while ((giorniavanzati > 0));

//output

printf("%d.%d.%d", *g, *m, *a);
}



//verifica che la data sia vera secondo il calendario gregoriano
int checkdate (int giorno, int mese, int anno)
{   
   if (anno > 1582)
   {
      
      if ((mese >= 1) && (mese <= 12))
      {
      
         if ((giorno > 0) && (giorno <= giorni_del_mese (mese, anno)))
         {
            return 1;
         }
      }
   }
   return 0;
}



//funzione che restituisce i giorni del mese corripettivo, tiene in conto anche gli anni bisestili
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



//verifica la bisestilità dell' anno
int bisestile (int anno)
{
   return ((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0); 
}