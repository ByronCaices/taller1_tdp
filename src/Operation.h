#pragma once
#ifndef OPERATION_H
#define OPERATION_H

#define VERTICAL 1
#define HORIZONTAL 0
class Car;
class Operation
{
public:
    int dir;                      // Direccion de la operacion
    int step;                     // Paso de la operacion
    Operation(int dir, int step); // Contructor de una operacion
    Operation();                  // Contructor de una operacion
    ~Operation();                 // Destructor de una operacion
    void printOperacion();        // Funcion para mostrar una operacion
    Car *operate(Car *car);       // Funcion para operar un auto
};

#endif