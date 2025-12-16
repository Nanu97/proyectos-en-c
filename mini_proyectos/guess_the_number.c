#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 5

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int leerEntero() {

    int num;
    int valido = 0;

    while (!valido) {

        printf("Ingrese un numero: ");

        if (scanf("%d", &num) == 1) {
            valido = 1;
        } else {
            printf("Entrada invalida. \n\n");
        }

        limpiarBuffer();
    }

    return num;
}

int main() {

    int secret_number, num;

    printf("-------- ADIVINA EL NUMERO SECRETO --------\n\n");
    printf("La computadora genera un numero aleatorio y tu objetivo es adivinarlo en un maximo de 5 intentos\n");

    srand(time(NULL));

    secret_number = 1 + rand() % 100;

    for (int i=0; i<MAX_INTENTOS; i++) {

        printf("\n==== Intento %d ====\n", i+1);

        do {

            num = leerEntero();

            if (num < 1 || num > 100) {

                printf("Debe ingresar un numero entre 1 y 100\n");

            }

        } while (num < 1 || num > 100);

        //Condicion para ganar
        if (num == secret_number) {
            printf("\nFELICIDADES! El numero secreto era [%d]\n", secret_number);
            return 0;
        }

        else if (num > secret_number) {

                if ((num - secret_number) > 10) {
                    printf("Mucho menor\n");
                } else {
                    printf("Menor\n");
                }

        } else if (num < secret_number) {

                if ((secret_number - num) > 10) {
                    printf("Mucho mayor\n");
                } else {
                    printf("Mayor\n");
                }
        }

    }

    //Si se agotan los intentos sin que el jugador adivine
    printf("\nPerdiste. El numero secreto era [%d]\n", secret_number);


    return 0;
}
