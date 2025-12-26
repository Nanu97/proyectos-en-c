#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTOS 4
#define RONDAS 5
#define VICTORIAS_PARA_GANAR 3

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    char elemento[ELEMENTOS][10] = {"Fuego", "Agua", "Tierra", "Aire"};

    int spell, cpu;

    int userWins, cpuWins, ties;
    int userDuels = 0, cpuDuels = 0, tieDuels = 0;

    srand(time(NULL));

    printf("===================================\n");
    printf("DUELISTA VIRTUAL LA LEYENDA DE AANG\n");
    printf("===================================\n\n");
    printf("--- REGLAS ---\n");
    printf("* Tierra vence a agua\n");
    printf("* Agua vence a fuego\n");
    printf("* Fuego vence a aire\n");
    printf("* Aire vence a tierra\n\n");

    /* PARTIDA */
    while (userDuels < VICTORIAS_PARA_GANAR &&
           cpuDuels  < VICTORIAS_PARA_GANAR) {

        userWins = 0;
        cpuWins = 0;
        ties = 0;

        int ronda = 0;

        printf("=== NUEVO DUELO ===\n\n");

        /* DUELO */
        while (ronda < RONDAS &&
               userWins < VICTORIAS_PARA_GANAR &&
               cpuWins  < VICTORIAS_PARA_GANAR) {

            ronda++;

            printf("RONDA %d\n", ronda);
            printf("Presione ENTER para lanzar un hechizo\n");
            getchar();

            spell = rand() % ELEMENTOS;
            cpu   = rand() % ELEMENTOS;

            printf("Lanzaste: %s\n", elemento[spell]);
            printf("La computadora respondio con: %s\n", elemento[cpu]);

            if (spell == cpu) {
                ties++;
                printf("Empate!\n\n");
            }
            else if (
                (spell == 0 && cpu == 3) ||  // Fuego > Aire
                (spell == 1 && cpu == 0) ||  // Agua > Fuego
                (spell == 2 && cpu == 1) ||  // Tierra > Agua
                (spell == 3 && cpu == 2)     // Aire > Tierra
            ) {
                userWins++;
                printf("Gana el usuario (%d - %d)\n\n", userWins, cpuWins);
            }
            else {
                cpuWins++;
                printf("Gana la computadora (%d - %d)\n\n", userWins, cpuWins);
            }
        }

        /* RESULTADO DEL DUELO */
        printf("Resultado del duelo:\n");
        printf("Usuario: %d | CPU: %d | Empates: %d\n",
               userWins, cpuWins, ties);

        if (userWins > cpuWins) {
            userDuels++;
            printf(">>> Usuario gana el duelo <<<\n\n");
        }
        else if (cpuWins > userWins) {
            cpuDuels++;
            printf(">>> Computadora gana el duelo <<<\n\n");
        }
        else {
            tieDuels++;
            printf(">>> Duelo empatado <<<\n\n");
        }

        printf("Marcador de duelos\n");
        printf("Usuario: %d | CPU: %d | Empates: %d\n\n",
               userDuels, cpuDuels, tieDuels);
    }

    /* FIN DE PARTIDA */
    if (userDuels == VICTORIAS_PARA_GANAR) {
        printf("EL USUARIO GANO LA PARTIDA\n");
    } else {
        printf("LA COMPUTADORA GANO LA PARTIDA\n");
    }

    return 0;
}
