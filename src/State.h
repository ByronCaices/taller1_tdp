#ifndef STATE_H
#define STATE_H
#include <iostream>
#include "Stack.h"
#include "Operacion.h"

class State
{
public:
    State(Stack *cars, Operacion *op, State *padre, Car *movingCar); // Constructor de un estado
    State(Stack *cars, Operacion *op, int idCar);                        // Constructor de un estado
    ~State();                                                              // Destructor de un estado
    void mostrarEstado();                                                  // Funcion para mostrar un estado
    bool esSolucion();                                                     // Funcion para verificar si un estado es solucion
    int CalcularHeuristica() const;                                        // Funcion para calcular la heuristica de un estado
    Stack *getAutos() const;                                               // Funcion para obtener los autos de un estado
    void mostrartablero();                                                 // Funcion para mostrar el tablero de un estado
    void mostrarsolucion();                                                // Funcion para mostrar la solucion de un estado

    // private:
    Stack *cars;    // Vector de autos
    Operacion *op;  // Operacion que se realizo para llegar a este estado
    State *padre;   // Padre de este estado
    Car *movingCar; // Auto que se esta moviendo en este estado
    int heuristica; // Costo acumulado de este estado
    // int heuristica; // Heuristica de este estado
    std::string toString() const; // Funcion para convertir un estado a string
};

#endif 