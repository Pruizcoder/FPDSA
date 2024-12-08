#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int strcompare(char a[], char b[]);

int main()
{
   char t[MAX];
   char s[MAX];
   int res = 0;
   printf("inserisci la prima string\n");
   fgets(t,MAX,stdin);
   printf("inserisci la seconda string\n");
   fgets(s,MAX,stdin);
   res = strcompare(t,s);
   printf("%d", res);
   return EXIT_SUCCESS;
}



int strcompare(char a[], char b[]) {
    int i = 0;
    
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            return -1;
        } else if (a[i] > b[i]) {
            return 1;
        }
        i++;
    }
    
    if (a[i] == '\0' && b[i] == '\0') {
        return 0;
    } else if (a[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}
