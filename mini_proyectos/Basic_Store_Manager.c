#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define PRECIO_AGUA 1000
#define PRECIO_GASEOSA 1500
#define PRECIO_ALFAJOR 2000

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int leerEntero() {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Entrada invalida. Ingrese un numero: ");
        limpiarBuffer();
    }
    limpiarBuffer();
    return num;
}

int main() {

    int op, item, cantidad;
    int precio;

    int dineroTot = 0;
    int cantItems = 0;

    int agua = 0, gaseosa = 0, alfajor = 0;
    int rec_agua = 0, rec_gaseosa = 0, rec_alfajor = 0;

    int ventas = 0;
    int masVendido = 0;

    printf("========== KIOSCO DEL RECREO ==========\n");

    do {

        printf("\nSeleccione la operacion:\n");
        printf("1) Registrar venta\n");
        printf("2) Mostrar totales\n");
        printf("3) Consultar producto\n");
        printf("4) Finalizar\n\n");

        do {
            op = leerEntero();
            if (op < 1 || op > 4)
                printf("Debe ser un numero entre 1 y 4\n");
        } while (op < 1 || op > 4);

        switch (op) {

        case 1:

            printf("\nSeleccione el producto:\n");
            printf("1) Agua ($1000)\n");
            printf("2) Gaseosa ($1500)\n");
            printf("3) Alfajor ($2000)\n\n");

            do {
                item = leerEntero();
                if (item < 1 || item > 3)
                    printf("Debe ser un numero entre 1 y 3\n");
            } while (item < 1 || item > 3);

            printf("Cantidad vendida: ");
            do {
                cantidad = leerEntero();
                if (cantidad <= 0)
                    printf("Cantidad invalida\n");
            } while (cantidad <= 0);

            if (cantItems + cantidad > MAX_ITEMS) {
                printf("\nVenta rechazada! Limite de productos alcanzado.\n");
                break;
            }

            if (item == 1) {
                precio = PRECIO_AGUA;
                agua += cantidad;
                rec_agua += cantidad * precio;
            } else if (item == 2) {
                precio = PRECIO_GASEOSA;
                gaseosa += cantidad;
                rec_gaseosa += cantidad * precio;
            } else {
                precio = PRECIO_ALFAJOR;
                alfajor += cantidad;
                rec_alfajor += cantidad * precio;
            }

            dineroTot += cantidad * precio;
            cantItems += cantidad;
            ventas++;

            printf("\nVenta registrada!\n");
            break;

        case 2:

            printf("\n---- ESTADISTICAS DE VENTAS ----\n");
            printf("Agua vendidos: %d\n", agua);
            printf("Gaseosa vendidas: %d\n", gaseosa);
            printf("Alfajores vendidos: %d\n", alfajor);
            printf("Total items vendidos: %d\n", cantItems);
            printf("Dinero total recaudado: $%d\n", dineroTot);
            break;

        case 3:

            printf("\nSeleccione el producto:\n");
            printf("1) Agua\n2) Gaseosa\n3) Alfajor\n");

            do {
                item = leerEntero();
                if (item < 1 || item > 3)
                    printf("Debe ser un numero entre 1 y 3\n");
            } while (item < 1 || item > 3);

            printf("\n---- INFORMACION DEL PRODUCTO ----\n");

            if (item == 1) {
                printf("Producto: Agua\n");
                printf("Unidades vendidas: %d\n");
                printf("Recaudacion: $%d\n", rec_agua);
            } else if (item == 2) {
                printf("Producto: Gaseosa\n");
                printf("Unidades vendidas: %d\n", gaseosa);
                printf("Recaudacion: $%d\n", rec_gaseosa);
            } else {
                printf("Producto: Alfajor\n");
                printf("Unidades vendidas: %d\n", alfajor);
                printf("Recaudacion: $%d\n", rec_alfajor);
            }
            break;

        }

    } while (op != 4);

    if (agua > gaseosa && agua > alfajor)
        masVendido = 1;
    else if (gaseosa > agua && gaseosa > alfajor)
        masVendido = 2;
    else if (alfajor > agua && alfajor > gaseosa)
        masVendido = 3;
    else
        masVendido = 0;

    printf("\n>>>> RESUMEN FINAL <<<<\n");
    printf("Ventas registradas: %d\n", ventas);
    printf("Agua: $%d\n", rec_agua);
    printf("Gaseosa: $%d\n", rec_gaseosa);
    printf("Alfajor: $%d\n", rec_alfajor);

    printf("\nProducto mas vendido: ");
    if (masVendido == 1)
        printf("Agua (%d unidades)\n", agua);
    else if (masVendido == 2)
        printf("Gaseosa (%d unidades)\n", gaseosa);
    else if (masVendido == 3)
        printf("Alfajor (%d unidades)\n", alfajor);
    else
        printf("Empate\n");

    return 0;
}
