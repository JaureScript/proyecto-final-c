// blemncer carrion
//añadiendo [librerías y funciones]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "base_datos_equipos.dat"
#define MAX_JUGADORES 50

// 1. Definición de Estructuras
typedef struct {
    char nombre[50];
    char posicion[30];
    int dorsal;
    int anotaciones;
} Jugador;

// Prototipos de Funciones
// Esto le dice al compilador que las funciones existen más abajo.
void limpiarPantalla();
void limpiarBuffer();
void pausar();

//  Función Principal
int main() {
    Jugador lista[MAX_JUGADORES];
    int n = 0;
    int op;

    do {
        limpiarPantalla();
        printf("=== CONTROL DE EQUIPOS ===\n");
        printf("1. Registrar Jugador (Proximamente)\n");
        printf("5. Salir\n");
        printf("Seleccione: ");
        
        if (scanf("%d", &op) != 1) {
            limpiarBuffer();
            op = -1;
        } else {
            limpiarBuffer();
        }
    } while (op != 5);

    return 0;
}



void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausar() {
    printf("\nPresione ENTER para continuar...");
    getchar();
}
