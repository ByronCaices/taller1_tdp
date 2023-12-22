#pragma once
#ifndef AUTO_H
#define AUTO_H
#include "Operacion.h"
#include <iostream>
#define HORIZONTAL 0
#define VERTICAL 1

class Car
{

public:
    Car(int id, int posX, int posY, int Largo, int Direccion);             // Constructor de un auto
    Car(const Car &copia);                                                 // Constructor de copia de un auto
    ~Car();                                                                // Destructor de un auto
    Car *mover(Operacion *op, int **tablero, int **paredes);               // Funcion para mover un auto
    bool verificarMovimiento(int **tablero, Operacion *op, int **paredes); // Funcion para verificar si un auto puede moverse
                                                                           // private:
    int id;                                                                // Identificador del auto
    int posX;                                                              // Posicion en x del auto
    int posY;                                                              // Posicion en y del auto
    int Largo;                                                             // Largo del auto
    int Direccion;                                                         // Direccion del auto
};

#endif
