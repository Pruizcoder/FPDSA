#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void strinsert(char *t, char *s);


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



void strinsert(char *t, char *s) {
    int s_len = 0, t_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }
     if (s_len > 0 && s[s_len - 1] == '\n') {
        s[s_len - 1] = '\0'; 
        s_len--; 
    }
    while (t[t_len] != '\0') {
       t_len++;
   }
   for (int i = t_len; i >= 0; i--) {
       t[i + s_len] = t[i]; 
   }
   for (int i = 0; i < s_len; i++) {
       t[i] = s[i];
   }
}  
