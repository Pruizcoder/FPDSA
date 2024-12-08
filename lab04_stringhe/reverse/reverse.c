#include <stdio.h>
#include <stdlib.h>

#define MAX 64
void rev(char* s);

int main()
{
   char s[MAX];
   fgets(s,MAX,stdin);
   rev(s);
   printf("%s", s);
   return EXIT_SUCCESS;
}


void rev(char* s) {
    int lunghezza = 0;
    while (s[lunghezza] != '\0') {
        lunghezza++;
    }
    if (s[lunghezza - 1] == '\n') {
        s[lunghezza - 1] = '\0';
    }

    int l = 0;
    int r = 0;
    char t;

    while (s[r] != '\0') {
        while (s[r] == ' ' && s[r] != '\0') {
            r++;
        }
        
        l = r;
        while (s[l] != ' ' && s[l] != '\0') {
            l++;
        }

        int fine_parola = l - 1;
        while (r < fine_parola) {
            t = s[r];
            s[r] = s[fine_parola];
            s[fine_parola] = t;
            r++;
            fine_parola--;
        }

        r = l;
    }
}