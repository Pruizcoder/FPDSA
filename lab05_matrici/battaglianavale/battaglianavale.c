#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//dimensioni input
#define MAX_INPUT 256
#define MAX_NAVE 20
#define MAX_COLONNA 3
#define MAX_RIGA 3
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
void piazza_navi(char campo[ALTEZZA][LARGHEZZA], char input[]);
int converti_navi(char *nave);
void piazza_verticale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione);
void piazza_orizzontale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione);
void inizializza_matrice(char matrice[ALTEZZA][LARGHEZZA]);
int main()
{
char campo[ALTEZZA][LARGHEZZA];
char input[MAX_INPUT];
inizializza_matrice(campo);
while (fgets(input, MAX_INPUT, stdin) != NULL)
{
piazza_navi(campo, input);
}
//fgets(input, MAX_INPUT, stdin);
stampa_martice(campo);

}

void piazza_navi(char campo[ALTEZZA][LARGHEZZA], char input[])
{   
    int riga = 0;
    while (input[riga] != '\n')
    {
        int i = 0;
        //leggi nave
        char nave_string[MAX_NAVE];
        int nave_int= 0;
        while (input[i] != ' ')
        {
            nave_string[i] = input[i];
            i++;
        }
        nave_string[i] = '\0';
        nave_int = converti_navi(nave_string);
        //salta spazio
        i++;
        //leggi colonna
        int j=0;
        char colonna_string[MAX_COLONNA];
        int colonna_int = 0;

        while (input[i] != ' ')
        {
            colonna_string[j] = input[i];
            i++;
            j++;
        }
        colonna_string[j] = '\0';
        colonna_int = atoi(colonna_string);
        //salta spazio
        i++;
        //leggi riga
        int k = 0;
        char riga_string[MAX_RIGA];
        int riga_int = 0;

        while (input[i] != ' ')
        {
            riga_string[k] = input[i];
            i++;
            k++;
        }
        riga_string[k] = '\0';
        riga_int = atoi(riga_string);
        //salta spazio
        i++;
        //leggi riga
        int l = 0;
        char orientamento_string[MAX_RIGA];
        orientamento_string[l] = input[i];

        switch (orientamento_string[l])
        {
        case 'O':
            piazza_orizzontale(colonna_int,riga_int, campo, nave_int);
            break;
        case 'V':
            piazza_verticale(colonna_int,riga_int, campo, nave_int);
            break;
        default:
            printf("orientamento sconosciuto: %c", orientamento_string[l]);
            exit(EXIT_FAILURE);
            break;
        }
    riga ++;
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
    if (strcmp(nave, "portaerei"))
    {
        return PTA;
    }
    else if (strcmp(nave, "cacciatorpediniere"))
    {
        return CTP;
    }
    else if (strcmp(nave, "incrociatore"))
    {
        return INC;
    }
    else if (strcmp(nave, "ricognitore"))
    {
        return RIC;
    }
    else
    {
        printf("tipo di nave sconosciuto: %s", nave);
        exit(EXIT_FAILURE);
    }
    
    
    
}

void piazza_verticale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione)
{
    for (int i = y; i < y + dimensione + 1; i++)
    {
        campo[i][x] = '*';
    }
    
}



void piazza_orizzontale(int x, int y, char campo[ALTEZZA][LARGHEZZA],int dimensione)
{
    for (int i = x; i < x + dimensione + 1; i++)
    {
        campo[y][i] = '*';
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