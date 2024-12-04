#include <stdio.h>
#include <stdlib.h>

#define MAX 32


void concatenate(char *t, char *s);

int main()
{
   char t[MAX];
   char s[MAX];
   printf("inserisci la prima string\n");
   fgets(t,MAX,stdin);
   printf("inserisci la seconda string\n");
   fgets(s,MAX,stdin);
   concatenate(t,s);
   printf("%s", t);
   
   return EXIT_SUCCESS;
}

void concatenate(char *t, char *s) {
    while (*t != '\0') {
        t++;
    }
   t--;
    while (*s != '\0') {
        *t = *s; 
        t++;
        s++;
    }

    *t = '\0';
}