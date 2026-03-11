#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

Nodo* crearNodo(int valor){
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    if(n){
        n->dato = valor;
        n->siguiente = NULL;
    }
    return n;
}

Nodo* crearArregloNodos(int n){
    Nodo* arreglo = (Nodo*)calloc(n, sizeof(Nodo));
    if(arreglo){
        for(int i = 0; i < n; i++) arreglo[i].dato = i;
    }
    return arreglo;
}

Nodo* agregarNodo(Nodo* arreglo, int* n, int valor){
    int nuevoTam = (*n) + 1;
    Nodo* temp = (Nodo*)realloc(arreglo, nuevoTam * sizeof(Nodo));
    if(temp){
        temp[*n].dato = valor;
        temp[*n].siguiente = NULL;
        *n = nuevoTam;
        return temp;
    }
    return arreglo;
}

void liberarNodos(Nodo* arreglo, int n){
    if(arreglo) free(arreglo);
}

Nodo* construirTresNodos(){
    Nodo* n1 = crearNodo(10);
    Nodo* n2 = crearNodo(20);
    Nodo* n3 = crearNodo(30);
    if(n1 && n2 && n3){
        n1->siguiente = n2;
        n2->siguiente = n3;
    }
    return n1;
}

int contarNodos(Nodo* inicio){
    int contador = 0;
    Nodo* actual = inicio;
    while(actual && actual->siguiente){
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

Nodo* crearNodosPorEntrada(){
    int n1_val, n2_val;
    printf("Introduce valor 1: "); scanf("%d", &n1_val);
    printf("Introduce valor 2: "); scanf("%d", &n2_val);
    Nodo* n1 = crearNodo(n1_val);
    Nodo* n2 = crearNodo(n2_val);
    if(n1) n1->siguiente = n2;
    return n1;
}
