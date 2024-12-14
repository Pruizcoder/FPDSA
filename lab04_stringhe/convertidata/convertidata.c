#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converti_data(char *in,char *out);
char * converti_mese(int mese);

#define MAXIN 16
#define MAXOUT 64
#define MAXANNO 5
#define MAXMESEGG 3
int main()
{
   char in[MAXIN];
   char out[MAXOUT];
   fgets(in, MAXIN, stdin);
   converti_data(in, out);
   puts(out);
}


void converti_data(char in[],char out[])
{
    int i = 0;
    char anno_string[MAXANNO];
    
    // Estrazione anno
    while (in[i] != '-') {
        anno_string[i] = in[i];
        i++;
    }
    anno_string[i] = '\0';  // Termina la stringa dell'anno
    int anno_int = atoi(anno_string);
    i++;  // Passa al carattere dopo il primo trattino
    
    // Estrazione mese
    char mese_string[MAXMESEGG];
    int j = 0;
    while (in[i] != '-') {
        mese_string[j] = in[i];
        i++;
        j++;
    }
    mese_string[j] = '\0';  // Termina la stringa del mese
    int mese_int = atoi(mese_string);
    i++;  // Passa al carattere dopo il secondo trattino
    
    // Estrazione giorno
    char giorno_string[MAXMESEGG];
    int k = 0;
    while (in[i] != '\0' && in[i] != '\n') {
        giorno_string[k] = in[i];
        i++;
        k++;
    }
    giorno_string[k] = '\0';  // Termina la stringa del giorno
    int giorno_int = atoi(giorno_string);
    

    // Formatta l'output
    sprintf(out, "%d %s dell'anno %s", giorno_int, converti_mese(mese_int), anno_string);
}

char * converti_mese(int mese)
{
   switch (mese)
   {
   case 1:
   return "gennaio";
      break;
   case 2:
   return "febbraio";
      break;
   case 3:
   return "marzo";
      break;
   case 4:
   return "aprile";
      break;
   case 5:
   return "maggio";
      break;
   case 6:
   return "giugno";
      break;
   case 7:
   return "luglio";
      break;
   case 8:
   return "agosto";
      break;
   case 9:
   return "settembre";
      break;
   case 10:
   return "ottobre";
      break;
   case 11:
   return "novembre";
      break;
   case 12:
   return "dicembre";
     break;   
   default:
   printf("gay");
   exit(EXIT_FAILURE);
      break;
   }
}



