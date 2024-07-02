#include <stdio.h>
#include "funciones.h"

int main() {
    char huespedes[5][2][40] = {
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""}
    };

    char cuartos[9][3][40] = {
        {"1", "simple", "Dan_Carlton"},
        {"2", "doble", "Dan_Carlton"},
        {"3", "triple", "Dan_Carlton"},
        {"4", "simple", "Swissotel"},
        {"5", "doble", "Swissotel"},
        {"6", "triple", "Swissotel"},
        {"7", "simple", "Sheraton"},
        {"8", "doble", "Sheraton"},
        {"9", "triple", "Sheraton"}
    };

    double costos[9] = {90, 120, 160, 65, 100, 140, 85, 110, 150};

    int reservaciones[10][4] = {
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0}
    };

    cargarDatos(huespedes, reservaciones); // Cargar los datos al inicio

    int opcion, numeroHabitacion, numeroReserva;
    do {
        printf("\nEscoja una opcion:\n1. Buscar Habitacion\n2. Realizar reserva\n3. Ver reservas\n4. Pagar Reserva\n>> ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("1. Por tamaño\n2. Por Hotel\n>> ");
                scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        buscarPorTamano(&numeroHabitacion, cuartos, costos);
                        break;
                    case 2:
                        buscarHotel(&numeroHabitacion, cuartos, costos);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                realizarReserva(numeroHabitacion, cuartos, huespedes, reservaciones);
                break;
            case 3:
                buscarReservaPorCedula(&numeroReserva, huespedes, reservaciones);
                imprimirReserva(numeroReserva, reservaciones, cuartos, costos, huespedes);
                break;
            case 4:
                buscarReservaPorCedula(&numeroReserva, huespedes, reservaciones);
                pagarReserva(numeroReserva, reservaciones, cuartos, costos, huespedes);
                break;
            default:
                break;
        }
        printf("Desea elegir otra opcion\n1.Si\n2.No\n>>");
        scanf("%d", &opcion);
    } while (opcion == 1);

    guardarDatos(huespedes, reservaciones); // Guardar los datos al salir

    return 0;
}
