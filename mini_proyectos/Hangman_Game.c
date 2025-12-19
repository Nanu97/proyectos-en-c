#include <stdio.h>
#include <string.h>

#define MAX_INTENTOS 6

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    char aux, op;
    char secret_word[] = "dragon";
    char progreso[] = "_ _ _ _ _ _";
    int underscore_count = strlen(secret_word);

    int vidas = MAX_INTENTOS;

    int used_count = 0;
    char used_letters[27] = "";

    printf("*********\n");
    printf("AHORCADO\n");
    printf("*********\n");

    // Bucle principal del juego
    while (vidas > 0) {

        printf("\n==== Vidas restantes: %d ====\n", vidas);
        printf("\nPalabra: %s\n\n", progreso);

        printf("Letras usadas: ");
        for (int k = 0; k < used_count; k++) {
            printf("%c ", used_letters[k]);
        }
        printf("\n");

        // Leer letra válida
        do {
            printf("Ingrese una letra (minuscula): ");
            scanf("%c", &aux);

            if (aux < 'a' || aux > 'z') {
                printf("\nEntrada invalida.\n\n");
            }

            limpiarBuffer();
            op = aux;

        } while (op < 'a' || op > 'z');

        // Guardar letra usada
        used_letters[used_count] = op;
        used_count++;
        used_letters[used_count] = '\0';

        // Verificar si acierta
        int acerto = 0;

        for (int j = 0; j < strlen(secret_word); j++) {
            if (secret_word[j] == op && progreso[2 * j] == '_') {
                progreso[2 * j] = op;
                underscore_count--;
                acerto = 1;
            }
        }

        // Si falla, pierde vida
        if (!acerto) {
            vidas--;
            printf("\nLa letra NO esta en la palabra.\n");
        }

        // Condición de victoria
        if (underscore_count == 0) {
            printf("\nADIVINASTE!\n");
            printf("La palabra secreta era: %s\n", secret_word);
            return 0;
        }
    }

    // Condición de derrota
    printf("\nPERDISTE!\n");
    printf("La palabra era: %s\n", secret_word);

    return 0;
}
