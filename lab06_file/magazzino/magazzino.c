#include <stdio.h>
#include <stdlib.h>


#define MAX_ARTICOLO 100
#define MAX_FILENAME 32
#define MAX_NOME 64  

struct articolo {
    char nome[MAX_NOME];
    int q;
};

void leggi_file(FILE *fi, struct articolo articoli[], int *n_articoli);
void stampa_articoli(struct articolo articoli[], int n_articoli);

int main() {
    FILE *file_input;
    char file_name[MAX_FILENAME];
    struct articolo articoli[MAX_ARTICOLO];
    int n_articoli = 0;

    printf("inserisci il nome del file magazzino:\n");
    scanf("%s", file_name);

    file_input = fopen(file_name, "r");
    if (file_input == NULL) {
        printf("errore nell'apertura del file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    leggi_file(file_input, articoli, &n_articoli);

    fclose(file_input);

    stampa_articoli(articoli, n_articoli);

    return EXIT_SUCCESS;
}

void leggi_file(FILE *fi, struct articolo articoli[], int *n_articoli) {
    char buffer[MAX_NOME + 32];
    char nome[MAX_NOME];
    int q;

    while (fgets(buffer, sizeof(buffer), fi) != NULL) {
        if (sscanf(buffer, " \"%[^\"]\" %d", nome, &q) == 2) {
            strncpy(articoli[*n_articoli].nome, nome, MAX_NOME);
            articoli[*n_articoli].nome[MAX_NOME - 1] = '\0'; 
            articoli[*n_articoli].q = q;

            (*n_articoli)++;
        }
    }
}

void stampa_articoli(struct articolo articoli[], int n_articoli) {
    for (int i = 0; i < n_articoli; i++) {
        printf("\"%s\" : %d\n", articoli[i].nome, articoli[i].q);
    }
}
