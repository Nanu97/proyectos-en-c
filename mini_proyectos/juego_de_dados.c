#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARAS_DADO 6

int main() {

    int dado1, dado2;

    srand(time(NULL));

    printf("-------- JUEGO DE LANZAMIENTO DE DADOS --------\n");
    printf("REGLAS:\n-Se gana si en ambos dados sale el mismo numero\n");
    printf("-Se pierde cuando sumando lo que salio en ambos dados da un numero impar\n");
    printf("-En cualquier otro caso se repite la tirada\n");

    do {

    printf("\nPresione ENTER para lanzar los dados\n");
    getchar();

    dado1 = 1 + rand() % CARAS_DADO;
    dado2 = 1 + rand() % CARAS_DADO;

    printf("Sacaste %d y %d\n", dado1, dado2);

    //Condicion para ganar
    if (dado1 == dado2) {
        printf("GANASTE!\nSacaste numeros iguales\n");
        return 0;

        //Condicion de derrota
    } else if ((dado1 + dado2) % 2 == 1) {
        printf("PERDISTE!\nMala suerte... la suma de los dados da como resultado un numero impar\n");
        return 0;
    } else {
        printf("Se repite la tirada\n");
    }

    } while ((dado1 + dado2) % 2 == 0);

    return 0;
}
