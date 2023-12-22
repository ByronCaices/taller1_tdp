#pragma once
#ifndef OPERATION_H
#define OPERATION_H

#define VERTICAL 1
#define HORIZONTAL 0

class Car; // Declaracion de la clase Car para reconocerla

/*
 * Clase Operation:
 * Representa una operacion que se puede realizar sobre un auto
 * dir: direccion de la operacion
 * step: paso de la operacion
 */
class Operation
{
public:
    int dir;  // Direccion de la operacion
    int step; // Paso de la operacion

    Operation(int dir, int step); // Contructor de una operacion
    Operation();                  // Contructor de una operacion
    ~Operation();                 // Destructor de una operacion

    void printOperation();  // Funcion para mostrar una operacion
    Car *operate(Car *car); // Funcion para operar un auto
};

#endif