#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INTENTOS 4

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    char buffer[200];
    char dir[20];
    char dirTesoro[20];
    char dirPozo[20];
    int tesoro, pozo;

    srand(time(NULL));

    printf("-------- AVENTURA EN EL BOSQUE --------\n\n");
    printf("Tu decides que camino elegir. Ganaras si hayas el tesoro antes de hallar el pozo de la muerte!\n");
    printf("Tienes un maximo de %d intentos\n", MAX_INTENTOS);

    do {

    tesoro = 1 + rand() % 5;
    pozo = 1 + rand() % 5;

    } while (tesoro == pozo);

    switch (tesoro) {
case 1:
    strcpy(dirTesoro, "norte");
    break;
case 2:
    strcpy(dirTesoro, "este");
    break;
case 3:
    strcpy(dirTesoro, "oeste");
    break;
case 4:
    strcpy(dirTesoro, "noreste");
    break;
case 5:
    strcpy(dirTesoro, "noroeste");
    break;
}

    switch (pozo) {
case 1:
    strcpy(dirPozo, "norte");
    break;
case 2:
    strcpy(dirPozo, "este");
    break;
case 3:
    strcpy(dirPozo, "oeste");
    break;
case 4:
    strcpy(dirPozo, "noreste");
    break;
case 5:
    strcpy(dirPozo, "noroeste");
    break;
}

    for (int i=0; i<MAX_INTENTOS; i++) {

            printf("\n==== Intento %d ====\n", i+1);

    do {

    printf("\nEscoja una direccion: [norte]-[este]-[oeste]-[noreste]-[noroeste]\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%19s", dir) == 1) {
            printf("Direccion: %s\n", dir);
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

    if (strcmp(dir, "norte") != 0 &&
        strcmp(dir, "este") != 0 &&
        strcmp(dir, "oeste") != 0 &&
        strcmp(dir, "noreste") != 0 &&
        strcmp(dir, "noroeste") != 0) {

        printf("Eleccion invalida.\n\n");

        }

    } while (
             strcmp(dir, "norte") != 0 &&
             strcmp(dir, "este") != 0 &&
             strcmp(dir, "oeste") != 0 &&
             strcmp(dir, "noreste") != 0 &&
             strcmp(dir, "noroeste") != 0);

        //Condicion de victoria
     if (strcmp(dir, dirTesoro) == 0) {
        printf("Encontraste el TESORO!\n");
        return 0;

        //Condicion de derrota
     } else if (strcmp(dir, dirPozo) == 0) {
        printf("Caiste al POZO de la muerte!\n");
        return 0;
     } else {
        printf("Este camino parece seguro... por ahora.\n");
     }

    }

    //Si no encontro el tesoro pero tampoco cayo en el pozo
    printf("Te quedaste encerrado en el bosque.\n\n");
    printf("El tesoro se encontraba en la direccion: [%s]\n", dirTesoro);
    printf("El pozo se encontraba en la direccion: [%s]\n", dirPozo);

    return 0;
}
