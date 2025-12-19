#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    int hours = -1, minutes = -1, seconds = -1;
    int seconds_to_advance = -1;

    printf("***** TIME SHIFT CLOCK SIMULATOR *****\n\n");

    while (hours<0 || hours>23) {
        printf("Ingrese hora (0-23): ");
        scanf("%d", &hours);
        limpiarBuffer();
        }

    while (minutes<0 || minutes>59) {
        printf("Ingrese minuto (0-59): ");
        scanf("%d", &minutes);
        limpiarBuffer();
        }

    while (seconds<0 || seconds>59) {
        printf("Ingrese segundo (0-59): ");
        scanf("%d", &seconds);
        limpiarBuffer();
        }

    printf("\nHorario inicial -- %02d:%02d:%02d\n", hours, minutes, seconds);

    //MIN: 1s - MAX: 86400s (1 dia entero)
    while (seconds_to_advance<1 || seconds_to_advance>86400) {
        printf("Ingrese cuanto tiempo que desea avanzar (en segundos)\n");
        scanf("%d", &seconds_to_advance);
        limpiarBuffer();
    }

    for (int i=0; i<seconds_to_advance; i++) {

    //Avanzar un segundo
    seconds++;

    if (seconds == 60) {
        seconds = 0;
        minutes++;
    }

    if (minutes == 60) {
        minutes = 0;
        hours++;
    }

    if (hours == 24) {
        hours = 0;
    }

    }

    printf("\nHorario actual -- %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
