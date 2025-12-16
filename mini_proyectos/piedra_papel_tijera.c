#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    char buffer[200];
    char usuario[20] = "";
    int user_wins=0, cpu_wins=0, empates=0;
    int cpu, jugada;

    srand(time(NULL));

    printf("-------- PIEDRA, PAPEL O TIJERA --------\n\n");

    while (strcmp(usuario, "F") != 0 && strcmp(usuario, "f") != 0) {

    do {

    printf("Ingrese su eleccion: 'piedra', 'papel' o 'tijera'. Presione 'F' para salir del juego\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%19s", usuario) == 1) {
            printf("Eleccion usuario: %s\n", usuario);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

    if (strcmp(usuario, "piedra") != 0 &&
        strcmp(usuario, "papel") != 0 &&
        strcmp(usuario, "tijera") != 0 &&
        strcmp(usuario, "F") != 0 &&
        strcmp(usuario, "f") != 0) {

        printf("Eleccion invalida.\n\n");

        }

    } while (strcmp(usuario, "piedra") != 0 &&
        strcmp(usuario, "papel") != 0 &&
        strcmp(usuario, "tijera") != 0 &&
        strcmp(usuario, "F") != 0 &&
        strcmp(usuario, "f") != 0);

        if (strcmp(usuario, "F") == 0 || strcmp(usuario, "f") == 0) {
            break;
        }

        jugada = 0;

        if (strcmp(usuario, "piedra") == 0) {
            jugada = 1;
        } else
        if (strcmp(usuario, "papel") == 0) {
            jugada = 2;
        } else
        if (strcmp(usuario, "tijera") == 0) {
            jugada = 3;
        }

        cpu = 1 + rand() % 3;

        printf("Eleccion computadora: ");
        if (cpu == 1) {
            printf("Piedra\n");
        } else if (cpu == 2) {
            printf("Papel\n");
        } else {
            printf("Tijera\n");
        }

        if (jugada == cpu) {
            printf("EMPATE!\n");
            empates++;
        }
        else if (
            (jugada == 1 && cpu == 3) ||
            (jugada == 2 && cpu == 1) ||
            (jugada == 3 && cpu == 2)
        ) {
            printf("Ganador: USUARIO\n");
            user_wins++;
        }
        else {
            printf("Ganador: COMPUTADORA\n");
            cpu_wins++;
        }

    }

    printf("\n==== RESUMEN DE LA PARTIDA ====\n\n");
    printf("Victorias del usuario: %d\n", user_wins);
    printf("Victorias de la computadora: %d\n", cpu_wins);
    printf("Cantidad de empates: %d\n", empates);

    if (user_wins > cpu_wins) {
        printf("Ganador final: USUARIO\n");
    } else
    if (cpu_wins > user_wins) {
        printf("Ganador final: COMPUTADORA\n");
    } else {
        printf("EMPATE!\n");
    }

    return 0;
}
