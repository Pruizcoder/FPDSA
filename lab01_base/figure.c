#include <stdio.h>
#include <stdlib.h>

void linea(int l);
void quadrato(int l);
void triangolo(int l);

int main() {
    char input = 0;
    char n = 0;

    // Ciclo per leggere la sequenza di input fino a newline
    while ((input = getchar()) != '\n') {
        n = getchar(); // Legge il numero successivo
        if (n < '1' || n > '9') { // Verifica validità del numero
            return EXIT_FAILURE;
        }
        int size = n - '0'; // Converte il carattere in un intero

        // Determina quale figura disegnare
        switch (input) {
            case 'Q':
            case 'q':
                quadrato(size);
                break;
            case 'L':
            case 'l':
                linea(size);
                break;
            case 'T':
            case 't':
                triangolo(size);
                break;
            default:
                return EXIT_FAILURE; // Carattere non valido
        }
        printf("\n"); // Separazione tra le figure
    }

    return EXIT_SUCCESS;
}

// Disegna una linea orizzontale
void linea(int l) {
    for (int i = 0; i < l; i++) {
        printf("*");
    }
}

// Disegna un quadrato
void quadrato(int l) {
    for (int i = 0; i < l; i++) {
        linea(l); // Usa la funzione linea per ogni riga del quadrato
        printf("\n");
    }
}

// Disegna un triangolo rettangolo isoscele
void triangolo(int l) {
    for (int i = 1; i <= l; i++) { // Parte da 1 per evitare una riga vuota iniziale
        linea(i); // Usa la funzione linea per ogni riga crescente
        printf("\n");
    }
}

