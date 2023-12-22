#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "State.h"
#include "Stack.h"
#include "Operation.h"

class Board
{
public:
    Board(int length); // Constructor de un tablero
    ~Board();          // Destructor de un tablero

    State *astar(State *initialState); // Funcion para resolver el problema
    Stack *copyStack(Stack *original); // Funcion para copiar un vector profundamente
    void fillBoard(Stack *cars);       // Funcion para llenar el tablero con los autos del vector de autos
    void emptyBoard();                 // Funcion para vaciar el tablero
    void setWalls(int **walls);        // Funcion para setear las paredes
    void printBoard();                 // Funcion para mostrar el tablero
    void printWalls();                 // Funcion para mostrar las paredes

private:
    int size;         // Largo del tablero
    int **board;      // Tablero
    int **walls;      // Paredes
    Operation ops[7]; // Operaciones
};

#endif
