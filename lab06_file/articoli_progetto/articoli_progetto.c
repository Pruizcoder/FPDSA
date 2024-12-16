#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICOLO 100
#define MAX_FILENAME 32
#define MAX_NOME 64  

struct articolo {
    char nome[MAX_NOME];
    int q;
};

void leggi_file(FILE *fi, struct articolo articoli[], int *n_articoli);
void stampa_articoli(struct articolo articoli[], int n_articoli);
void controlla_articoli(struct articolo articoli_magazzino[], int n_articoli_magazzino, 
                        struct articolo articoli_progetto[], int n_articoli_progetto);

int main() {
    FILE *file_input_magazzino, * file_input_progetto;
    char file_name_magazzino[MAX_FILENAME];
    char file_name_progetto[MAX_FILENAME];
    struct articolo articoli_magazzino[MAX_ARTICOLO];
    struct articolo articoli_progetto[MAX_ARTICOLO];

    int n_articoli_magazzino = 0;
    int n_articoli_progetto = 0;


    printf("nome del file magazzino:");
    scanf("%s", file_name_magazzino);

    file_input_magazzino = fopen(file_name_magazzino, "r");
    if (file_input_magazzino == NULL) {
        printf("errore nell'apertura del file %s\n", file_name_magazzino);
        exit(EXIT_FAILURE);
    }

   printf("nome del file progetto:\n");
    scanf("%s", file_name_progetto);


    file_input_progetto = fopen(file_name_progetto, "r");
    if (file_input_progetto == NULL) {
        printf("errore nell'apertura del file %s\n", file_name_progetto);
        exit(EXIT_FAILURE);
    }


    leggi_file(file_input_magazzino, articoli_magazzino, &n_articoli_magazzino);
    leggi_file(file_input_progetto, articoli_progetto, &n_articoli_progetto);

    fclose(file_input_magazzino);
    fclose(file_input_progetto);

    //printf("magazzino:\n");
    //stampa_articoli(articoli_magazzino, n_articoli_magazzino);
    //printf("progetto:\n");
    //stampa_articoli(articoli_progetto, n_articoli_progetto);


   controlla_articoli(articoli_magazzino, n_articoli_magazzino, articoli_progetto, n_articoli_progetto);



    return EXIT_SUCCESS;
}


void controlla_articoli(struct articolo articoli_magazzino[], int n_articoli_magazzino, 
                        struct articolo articoli_progetto[], int n_articoli_progetto) {
    for (int i = 0; i < n_articoli_progetto; i++) {
        int trovato = 0;
        for (int j = 0; j < n_articoli_magazzino; j++) {
            if (strcmp(articoli_progetto[i].nome, articoli_magazzino[j].nome) == 0) {
                trovato = 1;
                if (articoli_magazzino[j].q < articoli_progetto[i].q) {
                    printf("%s: %d\n", articoli_progetto[i].nome, articoli_progetto[i].q - articoli_magazzino[j].q);
                }
                break;
            }
        }
        
        if (!trovato) {
            printf("%s: %d\n", articoli_progetto[i].nome, articoli_progetto[i].q);
        }
    }
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
