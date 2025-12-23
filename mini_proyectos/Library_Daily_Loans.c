#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_RETIRO -1
#define SOCIOS 4
#define DAYS 7

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
            printf("Entrada invalida.\n");
        }

        limpiarBuffer();
    }

    return num;
}

int main() {

    int op;
    int aux_librosDia, aux_horaRetiro;

    int horaRetiro[SOCIOS] = {0};
    int librosDia[SOCIOS] = {0};
    int totLibros[SOCIOS] = {0};

    printf("========== BIBLIOTECA ==========\n\n");

    for (int i = 0; i < DAYS; i++) {

        printf("*** DIA %d ***\n\n", i + 1);

        printf("Seleccione una operacion:\n");
        printf("1) Ingresar datos\n");
        printf("0) Terminar el dia sin registros\n");

        do {
            op = leerEntero();

            if (op < 0 || op > 1) {
                printf("Opcion invalida.\n");
            }

        } while (op < 0 || op > 1);

        if (op == 1) {

            for (int s = 0; s < SOCIOS; s++) {

                librosDia[s] = 0;

                printf("\nSocio numero: %d\n", s + 1);
                printf("Cantidad de libros prestados (0-3): ");

                do {
                    aux_librosDia = leerEntero();

                    if (aux_librosDia < 0 || aux_librosDia > 3) {
                        printf("Debe ingresar un numero entre 0 y 3.\n");
                    }

                } while (aux_librosDia < 0 || aux_librosDia > 3);

                librosDia[s] = aux_librosDia;
                totLibros[s] += aux_librosDia;

                if (aux_librosDia > 0) {

                    printf("Horario de retiro (8-18): ");

                    do {
                        aux_horaRetiro = leerEntero();

                        if (aux_horaRetiro < 8 || aux_horaRetiro > 18) {
                            printf("Debe ingresar un horario entre las 8 y las 18.\n");
                        }

                    } while (aux_horaRetiro < 8 || aux_horaRetiro > 18);

                    horaRetiro[s] = aux_horaRetiro;
                    printf("Prestamo registrado!\n");

                } else {
                    horaRetiro[s] = SIN_RETIRO;
                    printf("No realizo prestamos.\n");
                }
            }

            /* Resumen del dia */
            printf("\n****\n");
            printf("DIA %d\n", i + 1);
            printf("****\n\n");

            for (int s = 0; s < SOCIOS; s++) {

                printf("Socio %d\n", s + 1);
                printf("Cantidad de libros prestados: %d\n", librosDia[s]);

                if (librosDia[s] > 0) {
                    printf("Horario de retiro: %d hs\n\n", horaRetiro[s]);
                } else {
                    printf("Sin prestamos\n\n");
                }
            }

        } else {

            printf("Sin registros.\n\n");
        }
    }

    printf("==== RESUMEN DE LA SEMANA ====\n\n");

    for (int s=0; s<SOCIOS; s++) {

        printf("El socio numero %d realizo un total de [%d] alquileres\n", s+1, totLibros[s]);

        if (totLibros[s] > 10) {

            printf("Se debe cobrar %d libros. Total a pagar: $%d\n\n", totLibros[s]-10, (totLibros[s]-10)*1000);

        }

    }

    int maxAlquileres = totLibros[0];
    int socioMax = 0;

        for (int s = 1; s < SOCIOS; s++) {

        if (totLibros[s] > maxAlquileres) {
        maxAlquileres = totLibros[s];
        socioMax = s;
        }
    }

    printf("=================================\n");
    printf("El socio que mas alquileres realizo fue el numero %d, con un total de %d alquileres\n\n", socioMax + 1, maxAlquileres);

    int totGeneral = 0;
    
    for (int s=0; s<SOCIOS; s++) {
        
        totGeneral += totLibros[s];
    }
    
    printf("Total acumulado de alquileres: %d\n", totGeneral);

    return 0;
}
