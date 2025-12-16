#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 8

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

    int clave[3] = {0};
    int usuario[3] = {0};
    int aciertos = 0;
    int x;

    srand(time(NULL));

    printf("-------- COFRE DE LA CRIPTA (MASTERMIND 3x6) --------\n\n");
    printf("Te metiste en una cripta y encontraste un cofre. Para abrirlo tenes que adivinar una\n");
    printf("combinacion secreta de 3 digitos. El tiempo corre y te quedas sin aire.\n");
    printf("\nOBJETIVO: Descubrir la combinacion exacta (tres digitos entre 1 y 6) en 8 intentos.\n");

    for (int i=0; i<3; i++) {

        //Generación de clave aleatoria
        clave[i] = 1 + rand() % 6;

    }

    for (int i=0; i<MAX_INTENTOS; i++) {

        printf("\n==== Intento %d ====\n", i+1);

        for (int j=0; j<3; j++) {

        do {

            x = leerEntero();

            if (x < 1 || x > 6) {

                printf("Debes ingresar un numero entre 1 y 6. \n\n");

            } else {

            usuario[j] = x;

            }

        } while (x < 1 || x > 6);

    }

    aciertos = 0;

    for (int k=0; k<3; k++) {

        if (usuario[k] == clave[k]) {
            aciertos++;

        }

    }

    if (aciertos == 3) {

        //Ganaste!
        printf("\nCOFRE ABIERTO!\n");
        printf("La clave secreta era [%d] [%d] [%d]\n", clave[0], clave[1], clave[2]);
        return 0;

    } else {

        printf("\n----- RESUMEN DE RONDA -----\n\n");
        printf("Tu propuesta: [%d] [%d] [%d]\n", usuario[0], usuario[1], usuario[2]);
        printf("Cantidad de aciertos: %d\n", aciertos);
        printf("Te quedan %d intentos\n", MAX_INTENTOS - i - 1);

    }

}
        //Si se terminan los intentos y no pudo abrir el cofre
        printf("\nFallaste.\n");
        printf("La clave secreta era [%d] [%d] [%d]\n", clave[0], clave[1], clave[2]);

    return 0;
}
