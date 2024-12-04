#include <stdio.h>
#include <stdlib.h>
//#include <lib_string.h>


void nome_abbreviato(char *s, char *t);




#define MAX 64




int main()
{
   char s[MAX];
   char t[MAX];
   //printf("inserisci cognome, nome:");
   fgets(t,MAX,stdin);
   nome_abbreviato(s,t);
   printf("%s", s);
   

   return EXIT_SUCCESS;

}

void nome_abbreviato(char *s, char *t) {
    int i = 0, j = 0;

    while (t[i] != ',' && t[i] != '\0') {
        i++;
    }

    if (t[i] == ',') {
        i++;
    }

    while (t[i] == ' ') {
        i++;
    }

    while (t[i] != '\0') {
        if (t[i] != ' ') {
            s[j++] = t[i];
            s[j++] = '.';
             s[j++] = ' ';
            while (t[i] != ' ' && t[i] != '\0') {
                i++;
            }
        } else {
            i++;
        }
    }


    i = 0;
    while (t[i] != ',' && t[i] != '\0') {
        s[j++] = t[i++];
    }

    s[j] = '\0';
}


