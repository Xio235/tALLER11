#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarPorTamano(int *numeroHabitacion, char cuartos[][3][40], double costos[]) {
    char dimension[40];
    int habitacionValida = 0;
   
    printf("Ingrese el tamaño de la habitación que desea buscar (simple/doble/triple): ");
    scanf("%39s", dimension);

    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(cuartos[i][1], dimension) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", cuartos[i][0], cuartos[i][1], cuartos[i][2], costos[i]);
            habitacionValida = 1;
        }
    }
    if (!habitacionValida) {
        printf("No se encontraron habitaciones de tamaño '%s'.\n", dimension);
        return;
    }
   
    printf("Elija la habitación que desea reservar: ");
    scanf("%d", numeroHabitacion);
    if (*numeroHabitacion < 1 || *numeroHabitacion > 9) {
        printf("Número de habitación no válido.\n");
        *numeroHabitacion = -1;
    }
}

void buscarHotel(int *numeroHabitacion, char cuartos[][3][40], double costos[]) {
    int hotelNumero;
    int habitacionValida = 0;
    const char *hoteles[] = {"Dan_Carlton", "Swissotel", "Sheraton"};
   
    printf("Elija el hotel que desea buscar:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, hoteles[i]);
    }
    printf("Ingrese el número del hotel: ");
    scanf("%d", &hotelNumero);
   
    if (hotelNumero < 1 || hotelNumero > 3) {
        printf("Número de hotel no válido.\n");
        return;
    }

    printf("#\t\tTamaño\t\tHotel\t\tPrecio\n");
    for (int i = 0; i < 9; i++) {
        if (strcmp(cuartos[i][2], hoteles[hotelNumero - 1]) == 0) {
            printf("%s\t\t%s\t\t%s\t\t%.2lf\n", cuartos[i][0], cuartos[i][1], cuartos[i][2], costos[i]);
            habitacionValida = 1;
        }
    }
    if (!habitacionValida) {
        printf("No se encontraron habitaciones en el hotel '%s'.\n", hoteles[hotelNumero - 1]);
        return;
    }
   
    printf("Elija la habitación que desea reservar: ");
    scanf("%d", numeroHabitacion);
    if (*numeroHabitacion < 1 || *numeroHabitacion > 9) {
        printf("Número de habitación no válido.\n");
        *numeroHabitacion = -1;
    }
}

void realizarReserva(int numeroHabitacion, char cuartos[][3][40], char huespedes[][2][40], int reservaciones[][4]) {
    int nuevoCliente = -1;
   
    if (numeroHabitacion == -1) {
        printf("Número de habitación no válido. Reserva no realizada.\n");
        return;
    }
   
    for (int i = 0; i < 5; i++) {
        if (huespedes[i][0][0] == '\0') {
            nuevoCliente = i;
            break;
        }
    }
    if (nuevoCliente == -1) {
        printf("No hay espacio para más clientes.\n");
        return;
    }

    if (reservaciones[numeroHabitacion - 1][1] != -1) {
        printf("La habitación %d ya está reservada.\n", numeroHabitacion);
        return;
    }

    printf("Ingrese el nombre del cliente: ");
    scanf("%39s", huespedes[nuevoCliente][0]);  
    printf("Ingrese la cédula del cliente: ");
    scanf("%39s", huespedes[nuevoCliente][1]);  

    for (int i = 0; i < 10; i++) {
        if (reservaciones[i][0] == -1) {
            reservaciones[i][0] = nuevoCliente;
            reservaciones[i][1] = numeroHabitacion - 1;
            reservaciones[i][2] = 0;
            reservaciones[i][3] = 0;
            printf("Reserva realizada correctamente.\n");
            return;
        }
    }

    printf("No hay espacio para más reservas.\n");
}

void buscarReservaPorCedula(int *numeroReserva, char huespedes[][2][40], int reservaciones[][4]) {
    char documento[40];
    printf("Ingrese la cédula que desea buscar la reserva: ");
    scanf("%39s", documento);
   
    for (int i = 0; i < 10; i++) {
        if ((reservaciones[i][0] != -1) && (strcmp(huespedes[reservaciones[i][0]][1], documento) == 0)) {
            *numeroReserva = i;
            return;
        }
    }
    *numeroReserva = -1;
}

void imprimirReserva(int numeroReserva, int reservaciones[][4], char cuartos[][3][40], double costos[], char huespedes[][2][40]) {
    if (numeroReserva != -1) {
        int clienteIndice = reservaciones[numeroReserva][0];
        int habitacionIndice = reservaciones[numeroReserva][1];
        char *nombreCliente = huespedes[clienteIndice][0];
        printf("Reserva %d: Cliente %s en Habitación %s (%s) de %s con precio %.2lf\n",
               numeroReserva + 1, nombreCliente, cuartos[habitacionIndice][0], cuartos[habitacionIndice][1],
               cuartos[habitacionIndice][2], costos[habitacionIndice]);
        if (reservaciones[numeroReserva][3] == 1) {
            printf("Estado: Pagada\n");
        } else {
            printf("Estado: No Pagada\n");
        }
    } else {
        printf("Reserva no encontrada.\n");
    }
}

void pagarReserva(int numeroReserva, int reservaciones[][4], char cuartos[][3][40], double costos[]) {
    if (numeroReserva != -1) {
        if (reservaciones[numeroReserva][3] == 1) {
            printf("La reserva ya está pagada.\n");
        } else {
            reservaciones[numeroReserva][3] = 1;
            printf("Reserva %d pagada.\n", numeroReserva + 1);
        }
    } else {
        printf("Reserva no encontrada.\n");
    }
}
