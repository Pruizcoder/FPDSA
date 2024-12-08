#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void inverti_parole(char *frase);
void swap (char *ptr_a, char *ptr_b);

int main()
{
   char s[MAX];
   printf("inserisci la string\n");
   fgets(s,MAX,stdin);
   printf("%s", s);
   return EXIT_SUCCESS;
}

void inverti_parole(char *frase) {
int i = 0;
while (frase[i] != '\0') {
        i++;
    }
for (int j = 0; j < i/2; j++)
{
    for (int k = i; k >i/2 ; k--)
    {
        swap(&frase[j], &frase[j]);
    }
    
}

}


void swap (char *ptr_a, char *ptr_b)
{
   char t;

   t = *ptr_a;
   *ptr_a = *ptr_b;
   *ptr_b = t;

   return;
}
