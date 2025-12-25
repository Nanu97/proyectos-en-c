#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RIFAS 1000
#define DAYS 7
#define CANT_JUGADORES 4
#define PRECIO 200

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

    int pj, rifa;
    int recaudacion[DAYS] = {0};
    int totRecau = 0;
    int rifasVendidas[MAX_RIFAS] = {0};
    int ventas[CANT_JUGADORES] = {0};
    int comprador = 0;
    int ventasDia[CANT_JUGADORES] = {0};

    printf("==============\n");
    printf("VENTA DE RIFAS\n");
    printf("==============\n\n");

    for (int i=DAYS-1; i>=0; i--) {

        recaudacion[i] = 0;

        for (int j=0; j<CANT_JUGADORES; j++) {
            ventasDia[j] = 0;
        }

        do {

            printf("Ingrese el numero de jugador que vendio la rifa (1-4) o '0' para salir: ");
            pj = leerEntero();

            if (pj == 0) {
                break;   // sale del do-while del día
            }

            if (pj < 1 || pj > 4) {
                printf("Opcion invalida.\n");
                continue;  // vuelve a pedir jugador
            }

        int repetida;

            do {

                repetida = 0;

                printf("Numero de rifa que desea comprar (1-1000): ");
                rifa = leerEntero();

                if (rifa < 1 || rifa > 1000) {
                    printf("Opcion invalida.\n");
                    repetida = 1;
                    continue;
                }

                for (int r = 0; r < comprador; r++) {
                    if (rifasVendidas[r] == rifa) {
                        printf("Este numero ya fue comprado.\n");
                        repetida = 1;
                        break;
                    }
                }

            } while (repetida);

        rifasVendidas[comprador] = rifa;
        comprador++;
        ventasDia[pj-1]++;
        ventas[pj-1]++;
        recaudacion[i] += PRECIO;
        totRecau += PRECIO;

        printf("\n* Comprador numero %d\n", comprador);
        printf("* Numero de rifa: %d\n", rifa);
        printf("* Vendedor: Jugador nro. %d\n\n", pj);

        } while (pj != 0);

        printf("\nFaltan %d dias para viajar\n", i);
        printf("Dinero recaudado este dia: $%d\n", recaudacion[i]);

        for (int v=0; v<CANT_JUGADORES; v++) {

            printf("Ventas Jug. %d: %d\n", v+1, ventasDia[v]);

        }

        printf("\n");

    }

    printf("--- TOTAL DE VENTAS INDIVIDUALES ---\n");

    for (int v=0; v<CANT_JUGADORES; v++) {

            printf("Jugador nro %d: %d ventas\n", v+1, ventas[v]);

        }

    int maxVentas = ventas[0];
    int masVendio = 1;

    for (int m=1; m<CANT_JUGADORES; m++) {

        if (ventas[m] > maxVentas) {
            maxVentas = ventas[m];
            masVendio = m+1;
        }

    }

    printf("\nEl jugador que vendio MAYOR cantidad de rifas fue el nro [%d]\n", masVendio);

    printf("\n--- TOTAL RECAUDADO POR EL EQUIPO: $%d ---\n", totRecau);

    return 0;
}
