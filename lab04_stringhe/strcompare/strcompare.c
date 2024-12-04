#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void strcompare(char *t, char *s);

int main()
{
   char t[MAX];
   char s[MAX];
   printf("inserisci la prima string\n");
   fgets(t,MAX,stdin);
   printf("inserisci la seconda string\n");
   fgets(s,MAX,stdin);
   strinsert(t,s);
   printf("%s", t);
   
   return EXIT_SUCCESS;
}



void strcompare(char *t, char *s) {
    
}  
