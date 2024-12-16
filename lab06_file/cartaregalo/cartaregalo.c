#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    double larghezza;
    double lunghezza;
    double altezza;
    char stato[10]; 
} Scatola;

double calcola_superficie(double larghezza, double lunghezza, double altezza);
double calcola_carta(const char *nome_file);
int main() {
    char nome_file[100];

    printf("nome del file dei regali: ");
    scanf("%s", nome_file);

    double carta_necessaria = calcola_carta(nome_file);

    printf("servono %.6f metri quadrati di carta da regalo\n", carta_necessaria);

    return 0;
}


double calcola_superficie(double larghezza, double lunghezza, double altezza)
{
    return 2 * (larghezza * lunghezza + larghezza * altezza + lunghezza * altezza);
}

double calcola_carta(const char *nome_file)
{
    FILE *file = fopen(nome_file, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        exit(1);
    }

    double superficie_totale = 0;
    Scatola scatola;

    while (fscanf(file, "%s %lf %lf %lf %s", scatola.nome, &scatola.larghezza, &scatola.lunghezza, &scatola.altezza, scatola.stato) != EOF) {
        if (strcmp(scatola.stato, "grezza") == 0) {
            double superficie = calcola_superficie(scatola.larghezza, scatola.lunghezza, scatola.altezza);
            superficie_totale += superficie * 1.15;  
        }
    }

    fclose(file);

    return superficie_totale / 10000.0;
}
