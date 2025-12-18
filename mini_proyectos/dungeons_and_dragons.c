#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    int dado, dano;
    int HP = 30;
    int A=0, B=0, C=0;

    srand(time(NULL));

    printf("---- CALABOZOS Y DRAGONES ----\n\n");

    for (int i=0; i<4; i++) {

        printf("==== Tirada %d: ====\n", i+1);
        printf("Presione ENTER para arrojar el dado\n");
        getchar();

        dado = 1 + rand() % 32;

        printf("Sacaste %d\n", dado);

        if (dado < 10) {

            A = 1;

        } else if (dado >= 20) {

            B = 1;

        } else {

            C = 1;

        }

        if (A == 1 && B == 1 && C == 1) {

            printf("RRROOOARGH... THUUUUM... Mataste al dragon blanco!!!\n");
            return 0;

        }

    dano = 1 + rand() % 10;
    HP -= dano;

    printf("\n>>>> RESUMEN DE RONDA <<<<\n");
    printf("El dragon te hizo %d de dano\n", dano);
    printf("Vida restante: %d\n\n", HP);

    }

    if (HP <= 0) {

        printf("El dragon te ha matado!\n");

    } else {

        printf("UFFF... Por poco. Lograste huir con %d de vida!\n", HP);

    }

    return 0;
}
