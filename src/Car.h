#pragma once
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Operation.h"

#define VERTICAL 1
#define HORIZONTAL 0

class Car
{

public:
    Car(int id, int col, int fila, int largo, int dir);       // Constructor de un auto
    Car(const Car &copia);                                    // Constructor de copia de un auto
    ~Car();                                                   // Destructor de un auto
    Car *move(Operation *op, int **board, int **walls);       // Funcion para mover un auto
    bool verifyMove(int **board, Operation *op, int **walls); // Funcion para verificar si un auto puede moverse
                                                              // private:
    int id;                                                   // Identificador del auto
    int columna;                                              // Posicion en x del auto
    int fila;                                                 // Posicion en y del auto
    int largo;                                                // Largo del auto
    int dir;                                                  // Direccion del auto
};

#endif
