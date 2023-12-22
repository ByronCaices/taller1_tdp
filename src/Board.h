#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "State.h"
#include "Stack.h"
#include "Operation.h"

/*
 * Clase Board:
 * Representa un tablero de juego
 * size: Largo del tablero
 * board: puntero a un puntero de enteros que representa el tablero
 * walls: puntero a un puntero de enteros que representa las paredes
 * ops: arreglo de operaciones
 */
class Board
{
private:
    int size;         // Largo del tablero
    int **board;      // Tablero
    int **walls;      // Paredes
    Operation ops[7]; // Operaciones

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
};

#endif
