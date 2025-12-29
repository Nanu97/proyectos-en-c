#include <stdio.h>
#include <ctype.h>

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

int mostrarMenu() {

    int opcion;

    printf("\n1) Ingresar pedido\n");
    printf("2) Mostrar dia con mayores ventas\n");
    printf("3) Mostrar total de ventas del dia actual\n");
    printf("4) Contador semanal de cervezas\n");
    printf("5) Finalizar dia\n");
    printf("\nElija una opcion: ");

    do {
        opcion = leerEntero();

        if ((opcion < 1 || opcion > 5) && opcion != 99) {
            printf("Opcion invalida. Intente nuevamente: ");
        }

    } while ((opcion < 1 || opcion > 5) && opcion != 99);

    return opcion;
}

int elegirProducto() {

    int order;

    printf("\n1) Mesa de pool ($%d)\n", PRECIO_POOL);
    printf("2) Cerveza ($%d)\n", PRECIO_CERVEZA);
    printf("3) Rocola ($%d)\n", PRECIO_ROCOLA);
    printf("4) Llamarada Moe (trago de autor, $%d)\n", PRECIO_LM);
    printf("\nSu pedido: ");

    do {

        order = leerEntero();

            if (order < 1 || order > 4) {
                printf("Opcion invalida.\n");
            }

        } while (order < 1 || order > 4);

    return order;
}

char pedirCliente() {

    char who;

    printf("\nQuien pidio la cerveza:\n");
    printf("H) Homero\n");
    printf("B) Barney\n");
    printf("U) Otra persona\n");
    printf("Opcion: ");

    do {
        scanf(" %c", &who);
        limpiarBuffer();

        if (who != 'H' && who != 'h' &&
            who != 'B' && who != 'b' &&
            who != 'U' && who != 'u') {

            printf("Opcion invalida. Reintente: ");
        }

    } while (who != 'H' && who != 'h' &&
             who != 'B' && who != 'b' &&
             who != 'U' && who != 'u');

    return toupper(who);
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
    int stock_pool, totPool = 0, recauPool = 0;
    int stock_beer, totBeer = 0, recauBeer = 0;
    int stock_rocola, totRoc = 0, recauRoc = 0;
    int stock_lm, totLM = 0, recauLM = 0;

    printf("***** LA TABERNA DE MOE *****\n");

    for (int i=0; i<DAYS; i++) {

            homeroDia = 0;

            //Reinicio de stock diario.
            stock_pool = 50;
            stock_beer = 100;
            stock_rocola = 50;
            stock_lm = 20;

            printf("\nDia %d\n", i+1);
            printf("======\n");

            int salirDia = 0;

            //Mostrar menú hasta que el usuario elija salir (opcion 5).
            while (!salirDia) {

                op = mostrarMenu();

                //Opcion oculta.
                if (op == 99) {
                    printf("Dia cerrado por emergencia\n\n");
                    break;
                }

        switch (op) {

        case 1:

            pedido = elegirProducto();

            switch (pedido) {

            case 1:

                if (stock_pool <= 0) {
                    printf("Producto agotado.\n");
                    break;
                }

                    recauDia[i] += PRECIO_POOL;
                    totRecau += PRECIO_POOL;
                    stock_pool--;
                    ventas[i]++;
                    totVentas++;
                    totPool++;
                    recauPool += PRECIO_POOL;

                break;

            case 2:

                if (stock_beer <= 0) {
                    printf("Producto agotado.\n");
                    break;
                }

                who = pedirCliente();

                int precioCerveza = PRECIO_CERVEZA;

                stock_beer--;
                ventas[i]++;
                totVentas++;
                totBeer++;

                if (who == 'B') {
                    barney++;
                    recauBarney  += PRECIO_CERVEZA;

                }

                else if (who == 'H') {
                    homero++;
                    homeroDia++;

                    if (homeroDia == 4) {
                        precioCerveza = 0;
                        printf("Beneficio cliente frecuente: 4ta cerveza GRATIS!\n");
                    }
                }

                else {
                    unknown++;
                }

                recauDia[i] += precioCerveza;
                totRecau += precioCerveza;
                recauBeer += precioCerveza;

                break;

            case 3:

                if (stock_rocola <= 0) {
                    printf("Producto agotado.\n");
                    break;
                }

                    recauDia[i] += PRECIO_ROCOLA;
                    totRecau += PRECIO_ROCOLA;
                    stock_rocola--;
                    ventas[i]++;
                    totVentas++;
                    totRoc++;
                    recauRoc += PRECIO_ROCOLA;

                break;

            case 4:

                if (stock_lm <= 0) {
                    printf("Producto agotado.\n");
                    break;
                }

                    recauDia[i] += PRECIO_LM;
                    totRecau += PRECIO_LM;
                    stock_lm--;
                    ventas[i]++;
                    totVentas++;
                    totLM++;
                    recauLM += PRECIO_LM;

                break;

            } //Fin del switch interno

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
    printf("Total recaudado: $%d\n\n", totRecau);
    printf("--- RECAUDACION POR PRODUCTO ---\n\n");
    printf("Pool: $%d\n", recauPool);
    printf("Cerveza: $%d\n", recauBeer);
    printf("Rocola: $%d\n", recauRoc);
    printf("Llamarada Moe: $%d\n\n", recauLM);

    //Estadística especial.
    printf("* Recaudacion por cervezas vendidas a Barney: %d\n\n", recauBarney);
    printf("--- CONTADOR SEMANAL DE VENTAS Y PORCENTAJE RESPECTO AL TOTAL ---\n");
    if (totVentas == 0) {
        printf("No se registraron ventas en la semana.\n");
    }
    else {
    printf("Pool: %d (%.2f%%) | Cerveza: %d (%.2f%%) | Rocola: %d (%.2f%%) | Llamarada Moe: %d (%.2f%%)\n",
           totPool, ((float)totPool * 100) / totVentas,
           totBeer, ((float)totBeer * 100) / totVentas,
           totRoc, ((float)totRoc * 100) / totVentas,
           totLM, ((float)totLM * 100) / totVentas);
        }

    return 0;
}
