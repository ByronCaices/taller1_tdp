#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "Stack.h"
#include "Operation.h"

/*
 * Clase State:
 * Representa un estado
 * cars: Stack de autos
 * op: Operacion que se realizo para llegar a este estado
 * padre: Padre de este estado
 * movingCar: Auto que se esta moviendo en este estado
 * heuristica: Costo acumulado de este estado
 */
class State
{
public:
    Stack *cars;    // Stack de autos
    Operation *op;  // Operacion que se realizo para llegar a este estado
    State *padre;   // Padre de este estado
    Car *movingCar; // Auto que se esta moviendo en este estado
    int heuristica; // Costo acumulado de este estado

    State(Stack *cars, Operation *op, State *padre, Car *movingCar); // Constructor de un estado
    State(Stack *cars, Operation *op, int idCar);                    // Constructor de un estado
    ~State();                                                        // Destructor de un estado

    Stack *getCars() const;     // Metodo para obtener los autos de un estado
    bool isSolution();          // Metodo para verificar si un estado es solucion
    int calcHeuristica() const; // Metodo para calcular la heuristica de un estado

    std::string toString() const; // Metodo para convertir un estado a string
    void printState();            // Metodo para mostrar un estado
    void printBoard();            // Metodo para mostrar el tablero de un estado
    void printSolution();         // Metodo para mostrar la solucion de un estado
};

#endif