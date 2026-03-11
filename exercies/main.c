#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int main() {
    printf("===== Repo de ejercicios de nodos =====\n");

    Nodo* n1 = crearNodo(10);
    if (n1) printf("Nodo creado con dato: %d\n", n1->dato);

    int tam = 5;
    Nodo* arreglo = crearArregloNodos(tam);
    printf("Arreglo calloc: ");
    for(int i=0; i<tam; i++) printf("%d ", arreglo[i].dato);
    printf("\n");

    arreglo = agregarNodo(arreglo, &tam, 99);
    printf("Arreglo realloc: ");
    for(int i=0; i<tam; i++) printf("%d ", arreglo[i].dato);
    printf("\n");

    liberarNodos(arreglo, tam);
    liberarNodos(n1, 1);

    Nodo* inicio = construirTresNodos();
    
    printf("Total conexiones: %d\n", contarNodos(inicio));

    Nodo* desdeEntrada = crearNodosPorEntrada();

    return 0;
}
