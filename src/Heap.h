#include <iostream>
#include "State.h"

using namespace std;

/*
 * Clase heap:
 * Representa un heap o cola de prioridad
 * heap: arreglo de punteros a State
 * size: cuantos hay almacenado en el heap
 * capacity: cuantos caben en el heap
 */
class Heap
{
public:
    State **heap; // Aqui es doble puntero porque es un arreglo de punteros a State
    int size;     // cuantos hay almacenado aqui
    int capacity; // cuantos caben aqui

    Heap(int capacity);      // Constructor de un heap
    ~Heap();                 // Destructor de un heap
    void push(State *state); // Funcion para insertar un estado en el heap
    State *pop();            // Funcion para obtener el estado con menor costo acumulado y heuristica
    bool isEmpty();          // Funcion para verificar si el heap esta vacio

    void swap(int i, int j);     // Funcion para intercambiar dos estados
    void bubbleUp(int index);    // desde abajo asegura que el padre sea menor que el hijo
    void heapify(int index);     // desde arriba asegura que el padre sea menor que el hijo
    bool contains(State *state); // Funcion para verificar si un estado esta en el heap
};