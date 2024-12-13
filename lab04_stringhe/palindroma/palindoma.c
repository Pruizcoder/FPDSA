#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int frase_palindroma(char s[]);

int is_alfanumerico(char c);

char to_lower(char c);

int main()
{
char s[MAX];
int res = 0;
fgets(s,MAX, stdin);
res = frase_palindroma(s);
if (res == 0)
{
   printf("non palindroma");
}
else if (res == 1)
{
   printf("palindroma");
}

}


int frase_palindroma(char s[]) {
    int inizio = 0;
    int fine = 0;

    while (s[fine] != '\0') {
        fine++;
    }
    fine--; 

    while (inizio < fine) {
        if (!is_alfanumerico(s[inizio])) {
            inizio++;
        } else if (!is_alfanumerico(s[fine])) {
            fine--;
        } else {
            if (to_lower(s[inizio]) != to_lower(s[fine])) {
                return 0;  
            }
            inizio++;
            fine--;
        }
    }

    return 1;  
}


int is_alfanumerico(char c) {
    return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') );
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c; 
}