#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS 7
#define MAX_VEHICULOS 30

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

    int vehiculosDia;
    int ticket = 1007;
    int horas;
    char buffer[200];
    char patente[7] = "";
    char tipo;
    int totRecau = 0;
    int recaudacion[DAYS] = {0};
    int recauMotos[DAYS] = {0};
    int recauAutos[DAYS] = {0};
    int autosEstacionados[DAYS] = {0};
    int motosEstacionados[DAYS] = {0};
    int totAutos = 0;
    int totMotos = 0;

    printf("==========================\n");
    printf("CONTROL DE ESTACIONAMIENTO\n");
    printf("==========================\n");

    for (int i=0; i<DAYS; i++) {

        vehiculosDia = 0;
        recaudacion[i] = 0;
        recauAutos[i] = 0;
        recauMotos[i] = 0;
        autosEstacionados[i] = 0;
        motosEstacionados[i] = 0;

        printf("\n==== DIA %d ====\n", i+1);

        //Bucle que permite el ingreso de vehículos hasta que se ingrese 0.
        do {

        do {

            printf("\nIngrese las horas que permanecera estacionado (0-24): ");
            horas = leerEntero();

            if (horas<0 || horas>24) {
                printf("Opcion invalida.\n");
            }

        } while (horas<0 || horas>24);

        if (horas == 0) {
            break;
        }

        //Limpiamos la patente para evitar usar un valor anterior inválido.
        patente[0] = '\0';

        do {

            printf("Ingrese la patente (AAA000): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%6s", patente) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

            } while (strlen(patente) != 6);

            //Tarifas: Auto $1000 por hora || Moto $500 por hora.
            printf("Auto ('A' - 'a') o Moto ('M' - 'm'): ");

            do {

                scanf("%c", &tipo);
                limpiarBuffer();

                if (tipo != 'A' && tipo != 'a' && tipo != 'M' && tipo != 'm') {
                    printf("Opcion invalida.\n");
                }

            } while (tipo != 'A' && tipo != 'a' && tipo != 'M' && tipo != 'm');

            if (tipo == 'A' || tipo == 'a') {
                autosEstacionados[i]++;
                recauAutos[i] += 1000*horas;
                recaudacion[i] += 1000*horas;
                totRecau += 1000*horas;
            }

            if (tipo == 'M' || tipo == 'm') {
                motosEstacionados[i]++;
                recauMotos[i] += 500*horas;
                recaudacion[i] += 500*horas;
                totRecau += 500*horas;
            }

            vehiculosDia++;

            printf("\n* Numero de ticket: %d\n", ticket);
            printf("* Patente: %s\n", patente);
            printf("* Horas: %d\n", horas);
            printf("* Monto total recaudado este dia hasta el momento: $%d\n", recaudacion[i]);

            if (vehiculosDia == MAX_VEHICULOS) {
                printf("\nSe alcanzo el maximo de vehiculos del dia (%d).\n", MAX_VEHICULOS);
            }

            ticket++;

        } while (horas != 0 && vehiculosDia < MAX_VEHICULOS);

    printf("\n--- RESUMEN DEL DIA %d ---\n", i+1);

    printf("Recaudacion por motos: $%d\n", recauMotos[i]);
    printf("Recaudacion por autos: $%d\n", recauAutos[i]);
    printf("Cantidad de motos estacionadas: %d\n", motosEstacionados[i]);
    printf("Cantidad de autos estacionados: %d\n", autosEstacionados[i]);

    }

    printf("\n--- RECAUDACION DIARIA ---\n");

    for (int r=0; r<DAYS; r++) {

    printf("[DIA %d]: $%d\n", r+1, recaudacion[r]);

            }

    printf("\n--- RECAUDACION SEMANAL ---\n");
    printf("Total de ingresos: $%d\n", totRecau);

    printf("\n--- RESUMEN SEMANAL DE VEHICULOS ESTACIONADOS ---\n");

    for (int e=0; e<DAYS; e++) {

        printf("[DIA %d]", e+1);
        printf("Cantidad de autos: %d\n", autosEstacionados[e]);
        printf("Cantidad de motos: %d\n", motosEstacionados[e]);

    }

    for (int t=0; t<DAYS; t++) {

        totAutos += autosEstacionados[t];
        totMotos += motosEstacionados[t];

    }

        printf("Total de autos: %d\n", totAutos);
        printf("Total de motos: %d\n", totMotos);

    int mayorRecau = recaudacion[0];
    int diaMax = 1;

    for (int m=1; m<DAYS; m++) {

        if (recaudacion[m] > mayorRecau) {
            mayorRecau = recaudacion[m];
            diaMax = m+1;

        }

    }

    printf("\nEl dia de mayor recaudacion fue el dia %d\n", diaMax);

    return 0;
}
