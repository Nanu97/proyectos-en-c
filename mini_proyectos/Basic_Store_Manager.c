#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int leerEntero() {

    int num;
    int valido = 0;

    while (!valido) {

        printf("Ingrese un numero: ");

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

    int op, item, cantidad, aux;
    int dineroTot=0, cantItems=0;
    int agua=0, gaseosa=0, alfajor=0;
    int rec_agua=0, rec_gaseosa=0, rec_alfajor=0;
    int clientes=0;
    int masVendido=0;

    printf("========== KIOSCO DEL RECREO ==========\n");

    do {

    printf("\nSeleccione la operacion a realizar:\n");
    printf("1)Registrar venta\n2)Mostrar totales\n3)Mostrar item\n4)Finalizar\n\n");

    do {

    op = leerEntero();

    if (op < 1 || op > 4) {
    printf("Debe ser un numero entre 1 y 4\n");
    }

    } while (op < 1 || op > 4);

    switch (op) {

    case 1:

        printf("Seleccione el producto que desea registrar:\n");
        printf("1) Agua($1000)\n2) Gaseosa($1500)\n3) Alfajor($2000)\n\n");

        do {

        item = leerEntero();

        if (item < 1 || item > 3) {

            printf("Debe ser un numero entre 1 y 3\n");

        }

        } while (item < 1 || item > 3);

        switch (item) {

    case 1:

        printf("Cantidad de botellas de agua vendidas:\n\n");

        do {

            aux = 0;
            cantidad = leerEntero();

            if (cantidad <= 0) {

                printf("Cantidad invalida.\n");
            }

        } while (cantidad <= 0);

        if ((cantItems + cantidad) > MAX_ITEMS) {

            printf("Venta rechazada! Limite de productos alcanzado.\n");
        } else {

        printf("Venta registrada!\n");
        agua += cantidad;
        aux += cantidad * 1000;
        rec_agua += aux;
        clientes++;
        }

        break;

    case 2:

        printf("Cantidad de gaseosas vendidas:\n\n");

        do {

            aux = 0;
            cantidad = leerEntero();

            if (cantidad <= 0) {

                printf("Cantidad invalida.\n");
            }

        } while (cantidad <= 0);

        if ((cantItems + cantidad) > MAX_ITEMS) {

            printf("Venta rechazada! Limite de productos alcanzado.\n");
        } else {

        printf("Venta registrada!\n");
        gaseosa += cantidad;
        aux += cantidad * 1500;
        rec_gaseosa += aux;
        clientes++;
        }

        break;

    case 3:

        printf("Cantidad de alfajores vendidos:\n\n");

        do {

            aux = 0;
            cantidad = leerEntero();

            if (cantidad <= 0) {

                printf("Cantidad invalida.\n");
            }

        } while (cantidad <= 0);

        if ((cantItems + cantidad) > MAX_ITEMS) {

            printf("Venta rechazada! Limite de productos alcanzado.\n");
        } else {

        printf("Venta registrada!\n");
        alfajor += cantidad;
        aux += cantidad * 2000;
        rec_alfajor += aux;
        clientes++;
        }

        break;

    default:

        printf("Opcion invalida.\n");

        break;

        }

        dineroTot += aux;
        cantItems += cantidad;

        if (cantItems > MAX_ITEMS) {
            cantItems -= cantidad;
        }

        break;

    case 2:

        printf("---- CANTIDADES VENDIDAS POR PRODUCTO ----\n\n");
        printf("Agua: %d\nGaseosa: %d\nAlfajor: %d\n", agua, gaseosa, alfajor);
        printf("Dinero total recaudado: $%d\n", dineroTot);
        printf("Total de items vendidos: %d\n", cantItems);

        break;

        case 3:

    printf("Seleccione el producto que desea consultar:\n");
    printf("1) Agua\n2) Gaseosa\n3) Alfajor\n");

    do {
        item = leerEntero();

        if (item < 1 || item > 3) {
            printf("Debe ser un numero entre 1 y 3\n");
        }

    } while (item < 1 || item > 3);

    printf("\n---- INFORMACION DEL PRODUCTO ----\n");

    switch (item) {

    case 1:
        printf("Producto: Agua\n");
        printf("Unidades vendidas: %d\n", agua);
        printf("Recaudacion total: $%d\n", rec_agua);
        break;

    case 2:
        printf("Producto: Gaseosa\n");
        printf("Unidades vendidas: %d\n", gaseosa);
        printf("Recaudacion total: $%d\n", rec_gaseosa);
        break;

    case 3:
        printf("Producto: Alfajor\n");
        printf("Unidades vendidas: %d\n", alfajor);
        printf("Recaudacion total: $%d\n", rec_alfajor);
        break;
    }

        break;

    default:

        break;
    }

    } while (op != 4);

    if (agua > gaseosa && agua > alfajor) {

        masVendido = 1;
    } else if (gaseosa > agua && gaseosa > alfajor) {

        masVendido = 2;
    } else if (alfajor > agua && alfajor > gaseosa) {

        masVendido = 3;
    } else {

        masVendido = 0;
    }

    printf("\n>>>> RESUMEN FINAL <<<<\n\n");
    printf("Clientes recibidos: %d\n\n", clientes);
    printf(" ------ RECAUDACIONES POR PRODUCTO ------\n");
    printf("Agua: $%d\n", rec_agua);
    printf("Gaseosa: $%d\n", rec_gaseosa);
    printf("Alfajor: $%d\n", rec_alfajor);
    printf("\nProducto mas vendido:\n");

    switch (masVendido) {

    case 1:
        printf("Agua con %d undidades vendidas\n", agua);
    break;

    case 2:
        printf("Gaseosa con %d unidades vendidas\n", gaseosa);
    break;

    case 3:
        printf("Alfajor con %d unidades vendidas\n", alfajor);
    break;

    default:
        printf("Tenemos un empate!\n");
    break;
    }

    return 0;
}
