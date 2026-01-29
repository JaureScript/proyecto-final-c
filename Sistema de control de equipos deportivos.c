/* INTEGRASTE:
   -Juan Jaure / C.I:31.302.572
   -Blemncer carrion / C.I:30.498.849
   -Diego Benedetti / C.I:30.956.790
   -Deivys Paredes / C.I:30.956.510
   -Rayan Herrera /C.I:28.773.197
*/
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

void guardardatos(jugador lista[], int n) {
    FILE *file = fopen(ARCHIVO, "wb");
    if (file) {
        fwrite(lista, sizeof(jugador), n, file);
        fclose(file);
    } else {
        printf("Error al guardar en archivo.\n");
    }
}

int seachDorsal(jugador lista[], int n, int dorsal) {
    for (int i = 0; i < n; i++) {
        if (lista[i].dorsal == dorsal) return i;
    }
    return -1;
}

int sumarGol(jugador lista[], int n, int index) {
    if (index >= n) return 0;
    return lista[index].anotaciones + sumarGol(lista, n, index + 1);
}
