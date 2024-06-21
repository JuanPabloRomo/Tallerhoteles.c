#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Implementación de la función buscarPorTamano
void buscarPorTamano(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char tamano[40];
    printf("Ingrese el tamaño de la habitación (simple/doble/triple): ");
    scanf("%s", tamano);

    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tamano) == 0) {
            *numHabitacion = i;
            printf("Habitación %s encontrada en el hotel %s con precio %.2f\n", habitaciones[i][0], habitaciones[i][2], precios[i]);
            return;
        }
    }
    printf("No se encontró ninguna habitación con el tamaño especificado.\n");
}

// Implementación de la función buscarHotel
void buscarHotel(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char nombreHotel[40];
    printf("Ingrese el nombre del hotel: ");
    scanf("%s", nombreHotel);

    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], nombreHotel) == 0) {
            *numHabitacion = i;
            printf("Habitación %s en el hotel %s encontrada con precio %.2f\n", habitaciones[i][0], nombreHotel, precios[i]);
            return;
        }
    }
    printf("No se encontró ninguna habitación en el hotel especificado.\n");
}

// Implementación de la función realizarReserva
void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], cedula) == 0) {
            for (int j = 0; j < 10; j++) {
                if (reservas[j][0] == -1) {
                    reservas[j][0] = numHabitacion;
                    reservas[j][1] = i;
                    reservas[j][2] = 0;  // Indicar que no está pagada
                    printf("Reserva realizada para el cliente %s en la habitación %s\n", clientes[i][0], habitaciones[numHabitacion][0]);
                    return;
                }
            }
            printf("No hay espacio para más reservas.\n");
            return;
        }
    }
    printf("No se encontró el cliente con la cédula especificada.\n");
}

// Implementación de la función buscarReservaPorCedula
void buscarReservaPorCedula(int *numReserva, char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese la cédula del cliente: ");
    scanf("%s", cedula);

    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] != -1 && strcmp(clientes[reservas[i][1]][1], cedula) == 0) {
            *numReserva = i;
            printf("Reserva %d encontrada para el cliente con cédula %s\n", i, cedula);
            return;
        }
    }
    printf("No se encontró ninguna reserva para la cédula especificada.\n");
}

// Implementación de la función imprimirReserva
void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    int numHabitacion = reservas[numReserva][0];
    printf("Reserva %d:\n", numReserva);
    printf("Habitación: %s\n", habitaciones[numHabitacion][0]);
    printf("Hotel: %s\n", habitaciones[numHabitacion][2]);
    printf("Precio: %.2f\n", precios[numHabitacion]);
}

// Implementación de la función pagarReserva
void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    reservas[numReserva][2] = 1; // Marcar como pagada
    int numHabitacion = reservas[numReserva][0];
    printf("Reserva %d pagada. Precio: %.2f\n", numReserva, precios[numHabitacion]);
}
