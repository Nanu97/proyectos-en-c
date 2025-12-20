#include <stdio.h>
#include <stdlib.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int leerEntero() {

    int num;
    int valido = 0;

    while (!valido) {

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

    int op, base, porcentaje;
    float resultado;

    printf("==========================\n");
    printf("CALCULADORA DE PORCENTAJES\n");
    printf("==========================\n\n");

    do {

        printf("1 - Calcular porcentaje de un numero\n");
        printf("2 - Calcular aumento porcentual\n");
        printf("3 - Calcular descuento porcentual\n");
        printf("0 - Salir\n");

        do {

            printf("Ingrese la operacion a realizar:\n");
            op = leerEntero();

            if (op < 0 || op > 3) {
                printf("Opcion invalida. Debe ingresar un numero entre 0 y 3.\n\n");
            }


        } while (op < 0 || op > 3);

        switch (op) {

    case 1:
        printf("\nIngrese el numero base: ");
        base = leerEntero();
        printf("Ingrese el porcentaje: ");
        porcentaje = leerEntero();

        resultado = base * porcentaje / 100.0;

        printf("\nEl %d por ciento de %d es: %.2f\n\n", porcentaje, base, resultado);
        printf("Presione ENTER para continuar...\n");
        getchar();
        break;

    case 2:
        printf("\nIngrese el valor original: ");
        base = leerEntero();
        printf("Ingrese el porcentaje de aumento: ");
        porcentaje = leerEntero();

        resultado = base * (1 + porcentaje / 100.0);

        printf("\nEl valor final con aumento es: %.2f\n\n", resultado);
        printf("Presione ENTER para continuar...\n");
        getchar();
        break;

    case 3:
        printf("\nIngrese el valor original: ");
        base = leerEntero();
        printf("Ingrese el porcentaje de descuento: ");
        porcentaje = leerEntero();

        resultado = base * (1 - porcentaje / 100.0);

        printf("\nEl valor final con descuento es: %.2f\n\n", resultado);
        printf("Presione ENTER para continuar...\n");
        getchar();
        break;

    case 0:
        break;

    default:
        printf("Error.\n");
        break;

        }

    } while (op != 0);

    printf("Gracias por usar la calculadora de porcentajes.\n");

    return 0;
}
