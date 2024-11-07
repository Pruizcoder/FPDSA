#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592
#define D 1.028
#define G 9.81

float calcola_volume_sfera(float raggio);
float calcola_spinta(float volume);

int main()
{
   float raggio = 0;
   printf("inserisci il raggio della sfera \n");
   scanf("%f", &raggio);
   printf("%f",calcola_spinta(calcola_volume_sfera(raggio)));
   return EXIT_SUCCESS;
}

float calcola_volume_sfera(float raggio)
{
   float volume = 0;
   volume = (4/(double) 3)* PI * (raggio * raggio * raggio);
   return volume;

}

float calcola_spinta(float volume)
{
   float spinta;

   spinta = D * G * volume;
   return spinta;
}