#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_OPCIONES 5

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

    int op, voto, masVotado;
    char ganador[20] = "";
    char opciones[CANT_OPCIONES][20] = {
    "Boca","River","Independiente","Racing","San Lorenzo"};

    int votos[CANT_OPCIONES] = {0};

    printf("********************\n");
    printf("SISTEMA DE VOTACION\n");
    printf("********************\n\n");

    do {

    printf("1) Votar\n2) Mostrar resultados\n3) Mostrar opcion mas votada\n4) Salir\n");

    do {

        op = leerEntero();

        if (op < 1 || op > 4) {
            printf("Opcion invalida\n");
        }

    } while (op < 1 || op > 4);

    switch (op) {

case 1:
    printf("\n---- Lista de candidatos ----\n1) Boca\n2) River\n3) Independiente\n4) Racing\n5) San Lorenzo\n");

    do {

        voto = leerEntero();

        if (voto < 1 || voto > CANT_OPCIONES) {
            printf("Opcion invalida\n");
        }

    } while (voto < 1 || voto > CANT_OPCIONES);

    votos[voto - 1]++;
    printf("Voto registrado!\n\n");

    break;

case 2:

    printf("\n==== RESULTADOS PARCIALES ====\n\n");

    for (int i=0; i<CANT_OPCIONES; i++) {

            printf("%s: %d votos\n", opciones[i], votos[i]);

            }

            break;

case 3:

    masVotado = votos[0];
    strcpy(ganador, opciones[0]);

    for (int i = 1; i < CANT_OPCIONES; i++) {
        if (votos[i] > masVotado) {
            masVotado = votos[i];
            strcpy(ganador, opciones[i]);
        }
    }

    if (masVotado == 0) {

        printf("\nAun no se han registrado votos!\n\n");
    } else {

    printf("\nEl club mas votado es: %s (%d votos)\n\n", ganador, masVotado);

    break;

        }

    }

} while (op != 4);

    printf("\n==== RESULTADOS FINALES ====\n\n");

    for (int i=0; i<CANT_OPCIONES; i++) {

        printf("%s: %d votos\n", opciones[i], votos[i]);

    }

    return 0;
}
