#include <stdio.h>

#define MAX_DIM 10  
void stampa_matrice(int matrice[MAX_DIM][MAX_DIM], int n);
void ruota_matrice(int matrice[MAX_DIM][MAX_DIM], int n);
int main() {
    int matrice[MAX_DIM][MAX_DIM];
    int n, i, j;

    printf("dimensione della matrice (quadrata max 10x10): ");
    scanf("%d", &n);

    //printf("Inserisci gli elementi della matrice:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }


    ruota_matrice(matrice, n);

    printf("\n");
    stampa_matrice(matrice, n);

    return 0;
}


void ruota_matrice(int matrice[MAX_DIM][MAX_DIM], int n)
{
    int i, j;
    int rotata[MAX_DIM][MAX_DIM];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            rotata[j][n - 1 - i] = matrice[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrice[i][j] = rotata[i][j];
        }
    }
}

void stampa_matrice(int matrice[MAX_DIM][MAX_DIM], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6d", matrice[i][j]);
        }
        printf("\n");
    }
}

