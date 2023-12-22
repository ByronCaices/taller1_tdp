#pragma once
#ifndef OPERACION_H
#define OPERACION_H

#define VERTICAL 1
#define HORIZONTAL 0
class Car;
class Operation
{
public:
    int dir;                            // Direccion de la operacion
    int step;                           // Paso de la operacion
    Operation(int dir, int step); // Contructor de una operacion
    Operation();                        // Contructor de una operacion
    ~Operation();                       // Destructor de una operacion
    void printOperacion();              // Funcion para mostrar una operacion
    Car *operar(Car *car);            // Funcion para operar un auto
};

#endif