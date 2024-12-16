#include <stdio.h>


#define MAX_DIM 10

void riempi_spirale(int matrice[MAX_DIM][MAX_DIM], int N);
void stampa_matrice(int matrice[MAX_DIM][MAX_DIM], int N);
int main() {
    int matrice[MAX_DIM][MAX_DIM];
    int N;

    printf("dimensione della matrice (quadrata max 10x10): ");
    scanf("%d", &N);

    if (N < 1 || N > MAX_DIM) {
        printf("Errore: la dimensione deve essere tra 1 e 10.\n");
        return 1;
    }

    riempi_spirale(matrice, N);

    stampa_matrice(matrice, N);

    return 0;
}
void riempi_spirale(int matrice[MAX_DIM][MAX_DIM], int N) {
    int val = 0; 
    int inizio_riga = 0, fine_riga = N - 1;
    int inizio_col = 0, fine_col = N - 1;

    while (val < N * N) {
        for (int i = inizio_col; i <= fine_col; i++) {
            matrice[inizio_riga][i] = val++;
        }
        inizio_riga++;

        for (int i = inizio_riga; i <= fine_riga; i++) {
            matrice[i][fine_col] = val++;
        }
        fine_col--;

        if (inizio_riga <= fine_riga) {
            for (int i = fine_col; i >= inizio_col; i--) {
                matrice[fine_riga][i] = val++;
            }
            fine_riga--;
        }

        if (inizio_col <= fine_col) {
            for (int i = fine_riga; i >= inizio_riga; i--) {
                matrice[i][inizio_col] = val++;
            }
            inizio_col++;
        }
    }
}

void stampa_matrice(int matrice[MAX_DIM][MAX_DIM], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", matrice[i][j]);
        }
        printf("\n");
    }
}

