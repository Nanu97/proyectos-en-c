#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS 7
#define PRECIO_POOL 5000
#define PRECIO_CERVEZA 3000
#define PRECIO_ROCOLA 1000
#define PRECIO_LM 10000

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

    int op, pedido;
    char who;
    int recauDia[DAYS] = {0};
    int ventas[DAYS] = {0};
    int totRecau = 0;
    int totVentas = 0;
    int homero = 0;
    int homeroDia = 0;
    int barney = 0;
    int unknown = 0;
    int recauBarney = 0;

    printf("***** LA TABERNA DE MOE *****\n");

    for (int i=0; i<DAYS; i++) {

            homeroDia = 0;

            printf("\nDia %d\n", i+1);
            printf("======\n");

            int salirDia = 0;

            //Mostrar menú hasta que el usuario elija salir (opcion 5).
            while (!salirDia) {

                //MENÚ
                printf("\n1) Ingresar pedido\n");
                printf("2) Mostrar dia con mayores ventas\n");
                printf("3) Mostrar total de ventas del dia actual\n");
                printf("4) Contador semanal de cervezas\n");
                printf("5) Finalizar dia\n");
                printf("\nElija una opcion: ");

            do {

                op = leerEntero();

                if (op < 1 || op > 5) {
                    printf("Opcion invalida.\n");
                }

            } while (op < 1 || op > 5);

        switch (op) {

        case 1:

            printf("\n1) Mesa de pool ($%d)\n", PRECIO_POOL);
            printf("2) Cerveza ($%d)\n", PRECIO_CERVEZA);
            printf("3) Rocola ($%d)\n", PRECIO_ROCOLA);
            printf("4) Llamarada Moe (trago de autor, $%d)\n", PRECIO_LM);
            printf("\nSu pedido: ");

            do {

                pedido = leerEntero();

                if (pedido < 1 || pedido > 4) {
                    printf("Opcion invalida.\n");
                }

            } while (pedido < 1 || pedido > 4);

            switch (pedido) {

            case 1:

                recauDia[i] += PRECIO_POOL;
                totRecau += PRECIO_POOL;

                break;

            case 2:

                printf("\nQuien pidio la cerveza:\n");
                printf("Homero --> Ingresar 'H'\n");
                printf("Barney --> Ingresar 'B'\n");
                printf("Otra persona --> Ingresar 'U'\n");

                do {

                    //Se deja un espacio para saltear basura y leer la letra real.
                    scanf(" %c", &who);
                    limpiarBuffer();

                    if (who != 'B' && who != 'b' && who != 'H' && who != 'h'
                        && who != 'U' && who != 'u') {
                            printf("Opcion invalida.\n");
                            continue;
                        }

                } while (who != 'B' && who != 'b' && who != 'H' && who != 'h'
                         && who != 'U' && who != 'u');

                recauDia[i] += PRECIO_CERVEZA;
                totRecau += PRECIO_CERVEZA;

                if (who == 'B' || who == 'b') {
                    barney++;
                    recauBarney  += PRECIO_CERVEZA;

                }

                else if (who == 'H' || who == 'h') {
                    homero++;
                    homeroDia++;
                }

                else {
                    unknown++;
                }

                break;

            case 3:

                recauDia[i] += PRECIO_ROCOLA;
                totRecau += PRECIO_ROCOLA;

                break;

            case 4:

                recauDia[i] += PRECIO_LM;
                totRecau += PRECIO_LM;

                break;

            } //Fin del switch interno

            ventas[i]++;
            totVentas++;

            break;

        case 2:

            int maxVentas = ventas[0];
            int maxDia = 1;

            for (int m=0; m<=i; m++) {

                if (ventas[m] > maxVentas) {
                    maxVentas = ventas[m];
                    maxDia = m+1;
                }

            }

            printf("Dia con MAYOR cantidad de ventas: [** DIA %d **]\n", maxDia);

            break;

        case 3:

            printf("Este dia lleva un total de %d ventas.\n", ventas[i]);

            break;

        case 4:

            printf("\n--- REGISTRO DE CERVEZAS ---\n\n");

            printf("Barney: %d | Homero: %d | Desconocidos: %d\n", barney, homero, unknown);

            break;

        case 5:
            if (homeroDia > 0) {
            printf("Terminando el dia...\n");
            salirDia = 1;
            }

            else {
                printf("\nDENEGADO: El dia no puede terminar sin que Homero pida una cerveza!\n");
            }
            break;

            } //Fin del switch

        } //Fin del while !salirDia

        printf("--- RESUMEN DEL DIA ---\n\n");

        printf("Total de ventas: %d\n", ventas[i]);
        printf("Dinero recaudado: $%d\n", recauDia[i]);
        printf("Cervezas pedidas por Homero: %d\n", homeroDia);
        printf("Ventas de la semana hasta el momento: %d\n", totVentas);

    } //Fin del bucle for

    printf("\n*** RESUMEN SEMANAL ***\n");
    printf("========================\n\n");

    int masVentas = ventas[0];
    int diaMasVentas = 1;

    for (int i=1; i<DAYS; i++) {

        if (ventas[i] > masVentas) {
            masVentas = ventas[i];
            diaMasVentas = i+1;
        }

    }

    int menosVentas = ventas[0];
    int diaMenosVentas = 1;

    for (int i=0; i<DAYS; i++) {

        if (ventas[i] < menosVentas) {
            menosVentas = ventas[i];
            diaMenosVentas = i+1;
        }

    }

    printf("Dia de MAYORES ventas: [DIA %d]\n", diaMasVentas);
    printf("Dia de MENORES ventas: [DIA %d]\n", diaMenosVentas);
    printf("Total recaudado: $%d\n", totRecau);
    printf("Recaudacion por cervezas vendidas a Barney: %d\n", recauBarney);

    return 0;
}
