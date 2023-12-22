#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Operation.h"
#include "Stack.h"
#include "State.h"

class Board
{
public:
    Board(int length);                                 // Constructor de un tablero
    ~Board();                                          // Destructor de un tablero
    Car *operarauto(Car *car);                         // Funcion para operar un auto
    State *resolver(State *initialState);              // Funcion para resolver el problema
    Stack *copiarVectorProfundamente(Stack *original); // Funcion para copiar un vector profundamente
    void llenarTablero(Stack *cars);                   // Funcion para llenar el tablero con los autos del vector de autos
    void vaciarTablero();                              // Funcion para vaciar el tablero
    void MostarTablero();                              // Funcion para mostrar el tablero
    void setParedes(int **walls);                      // Funcion para setear las paredes
    void mostrarParedes();                             // Funcion para mostrar las paredes

private:
    int size;         // Largo del tablero
    int **board;      // Tablero
    int **walls;      // Paredes
    Operation ops[7]; // Operaciones
};

#endif
