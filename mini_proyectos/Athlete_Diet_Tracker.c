#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS 7
#define COMIDAS 4

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
    int diaMasCal = 0;
    int diaMenosCal = 0;
    int cal[COMIDAS] = {0};
    int calorias[DAYS] = {0};
    int totCalorias = 0;
    char buffer[200];
    char comida[COMIDAS][30]; /*El 1er array contiene 4 elementos (para guardar desayuno,
                              almuerzo, merienda y cena. El 2do array, es para ingresar el alimento*/

        printf("====================\n");
        printf("DIETA DEL DEPORTISTA\n");
        printf("====================\n");

        for (int i=0; i<DAYS; i++) {

        calorias[i] = 0;

        for (int j=0; j<COMIDAS; j++) {

            comida[j][0] = '\0';
            cal[j] = 0;

        }

        printf("\n**** DIA [%d] ****\n", i+1);

        int salirDia = 0;

        while (!salirDia) {

        printf("\n1) Ingresar alimentos (nombre y calorias)\n");
        printf("2) Finalizar el dia\n");
        printf("3) Mostrar el total de calorias consumidas este dia\n");
        printf("4) Mostrar el total de calorias de la semana hasta el momento\n");
        printf("5) Mostrar el dia con mayor consumo calorico hasta el momento\n\n");

        do {

        printf("Ingrese la operacion a realizar: ");
            op = leerEntero();

            if (op < 1 || op > 5) {
                printf("Opcion invalida.\n");
            }

        } while (op < 1 || op > 5);

        switch (op) {

        case 1:

        printf("\nDesayuno: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%29[^\n]", comida[0]) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

        printf("Calorias: ");

        do {

            cal[0] = leerEntero();
            if (cal[0] < 0) {
               printf("Cantidad invalida.\n");
               continue;
            }

        } while (cal[0] < 0);

        printf("\nAlmuerzo: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%29[^\n]", comida[1]) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

        printf("Calorias: ");

        do {

            cal[1] = leerEntero();
            if (cal[1] < 0) {
               printf("Cantidad invalida.\n");
               continue;
            }

        } while (cal[1] < 0);

        printf("\nMerienda: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%29[^\n]", comida[2]) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

        printf("Calorias: ");

        do {

            cal[2] = leerEntero();
            if (cal[2] < 0) {
               printf("Cantidad invalida.\n");
               continue;
            }

        } while (cal[2] < 0);

        printf("\nCena: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%29[^\n]", comida[3]) == 1) {
        } else {
            printf("Error: Entrada invalida.\n");
        }
    }

        printf("Calorias: ");

        do {

            cal[3] = leerEntero();
            if (cal[3] < 0) {
               printf("Cantidad invalida.\n");
               continue;
            }

        } while (cal[3] < 0);

        calorias[i] = 0;

        for (int c=0; c<COMIDAS; c++) {

            calorias[i] += cal[c];

        }

        totCalorias += calorias[i];

            break;

        case 2:
            printf("Terminando el dia...\n\n");
            printf("**** DIA [%d] ****\n", i+1);
            printf("Desayuno: [%s], [%d kcal]\n", comida[0], cal[0]);
            printf("Almuerzo: [%s], [%d kcal]\n", comida[1], cal[1]);
            printf("Merienda: [%s], [%d kcal]\n", comida[2], cal[2]);
            printf("Cena: [%s], [%d kcal]\n", comida[3], cal[3]);
            printf("Total calorias: [%d]\n", calorias[i]);
            salirDia = 1;
            break;

        case 3:

            printf("\nESTE DIA CONSUMISTE %d CALORIAS\n", calorias[i]);

            break;

        case 4:

            printf("\nLLEVAS UN TOTAL ACUMULADO DE %d CALORIAS\n", totCalorias);

            break;

        case 5:

            int maxCalorias = calorias[0];
            diaMasCal = 0;

            for (int m=1; m<=i; m++) {

                if (calorias[m] > maxCalorias) {
                    maxCalorias = calorias[m];
                    diaMasCal = m;
                }

            }

            printf("\nDia con MAYOR consumo de calorias: [%d]\n", diaMasCal+1);

            break;

        } //Fin del switch

    } //Fin del while

    } //Fin del bucle for

    printf("\n==== RESUMEN SEMANAL ====\n");

        int maxCal = calorias[0];
        int minCal = calorias[0];
        diaMasCal = 0;
        diaMenosCal = 0;

        for (int i = 1; i < DAYS; i++) {
            if (calorias[i] > maxCal) {
                maxCal = calorias[i];
                diaMasCal = i;
            }

            if (calorias[i] < minCal) {
                minCal = calorias[i];
                diaMenosCal = i;
            }
        }

    printf("\nDia con MAYOR consumo calorico: [%d]\n", diaMasCal+1);
    printf("Dia con MENOR consumo calorico: [%d]\n", diaMenosCal+1);

    float promedio = 0;
    int sumatoria = 0;

    for (int p=0; p<DAYS; p++) {

        sumatoria += calorias[p];
        promedio = (float) sumatoria / DAYS;

    }

    if (promedio > 3000) {

        printf("En promedio, el atleta consumio mas de 3000 calorias por dia.\n");

    }

    for (int p=0; p<DAYS; p++) {

        if (calorias[p] == 0) {
            printf("El dia [%d], el atleta no consumio calorias.\n", p+1);
        }

    }

    return 0;
}
