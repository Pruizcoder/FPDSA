#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//dimensioni input
#define MAX_NAVE 20
#define MAX_DIREZIONE 3
// dimensioni campo
#define LARGHEZZA 15
#define ALTEZZA 15

//dimensioni navi
#define PTA 5
#define CTP 4
#define INC 3
#define RIC 2

//funzioni prototipo
void stampa_martice(char matrice[ALTEZZA][LARGHEZZA]);
int converti_navi(char *nave);
void piazza_navi(char campo[LARGHEZZA][ALTEZZA], int x, int y, char *direzione, char *nave);
void piazza_verticale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione, char *nave);
void piazza_orizzontale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione, char *nave);
void inizializza_matrice(char matrice[ALTEZZA][LARGHEZZA]);
int main()
{
char campo[ALTEZZA][LARGHEZZA];

inizializza_matrice(campo);
char tipo_nave[MAX_NAVE];
int x = 0;
int y = 0;
char direzione[MAX_DIREZIONE];
while ((scanf ("%s %d %d %s", tipo_nave, &x, &y, direzione) != EOF))
{
    piazza_navi(campo, x,y,direzione, tipo_nave);

}
stampa_martice(campo);

}

void piazza_navi(char campo[LARGHEZZA][ALTEZZA], int x, int y, char *direzione, char *nave)
{   
int dimensione = 0;
dimensione = converti_navi(nave);
//printf("[%d] ", dimensione);



    if (direzione[0] == 'O')
    {
        piazza_orizzontale(x, y, campo, dimensione, nave);
    }
        
    else if (direzione[0] == 'V')
    {
        piazza_verticale(x, y, campo, dimensione, nave);
    }
    else
    {
        printf("orientamento sconosciuto: %c", direzione[0]);
        exit(EXIT_FAILURE);
    }
    
    
    
    

}



void stampa_martice(char matrice[ALTEZZA][LARGHEZZA])
{
for (int i = ALTEZZA-1; i >= 0; i--) {
        if (i < 10)
        {
        printf(" %d ", i);  
        }
        else
        {
        printf("%d ", i);  
        }
        
        
        for (int j = 0; j < LARGHEZZA; j++) {
            printf(" %c ", matrice[i][j]);  
        }
        printf("\n");
    }

    printf("   ");
    for (int j = 0; j < LARGHEZZA; j++) {
        if (j<10)
        {
        printf(" %d ", j);  
        }
        else
        {
        printf("%d ", j);  

        }
                
    }
    printf("\n");
}

int converti_navi(char *nave)
{
    //printf("\n%s\n", nave);
    if (strcmp(nave, "portaerei") == 0)
    {
        //printf("\npiazzo la nave portaerei di dimensione %d", PTA);

        return PTA;
    }
    else if (strcmp(nave, "cacciatorpediniere") == 0)
    {
        //printf("\npiazzo la nave cacciatorpediniere di dimensione %d", CTP);
        return CTP;
    }
    else if (strcmp(nave, "incrociatore") == 0)
    {
        //printf("\npiazzo la nave incrociatore di dimensione %d", INC);
        return INC;
    }
    else if (strcmp(nave, "ricognitore") == 0)
    {
        //printf("\npiazzo la nave ricognitore di dimensione %d", RIC);
        return RIC;
    }
    else
    {
        printf("tipo di nave sconosciuto: %s", nave);
        exit(EXIT_FAILURE);
    }
    
    
    
}

void piazza_verticale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione, char *nave)
{
    for (int i = y; i < y + dimensione; i++)
    {
        if (campo[i][x] == ' ')
        {
            campo[i][x] = '*';
        }
        else
        {
            printf("errore di caricamento della nave: %s %d %d V", nave, x,y);
            exit(EXIT_FAILURE);
        }
        
        
    }
    
}



void piazza_orizzontale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione, char *nave)
{
    for (int i = x; i < x + dimensione; i++)
    {
        if (campo[y][i] == ' ')
        {
        campo[y][i] = '*';
        }
        else
        {
            printf("errore di caricamento della nave: %s %d %d O", nave, x,y);
            exit(EXIT_FAILURE);
        }   
    }
}

void inizializza_matrice(char matrice[ALTEZZA][LARGHEZZA])
{
    for (int i = 0; i < ALTEZZA; i++)
    {
        for (int j = 0; j < LARGHEZZA; j++)
        {
            matrice[i][j] = ' ';
        }
        
    }
    
}