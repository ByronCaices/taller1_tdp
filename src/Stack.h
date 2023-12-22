#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Auto.h"
#include <sstream>

class Stack
{
public:
    Stack(int cap); // Contructor de un vector
    ~Stack();             // Destructor de un vector

    void push(Auto *auto_);                                        // Funcion para agregar un auto al vector
    bool isEmpty();                                                // Funcion saber si el vector esta vacio
    void printVector();                                            // Funcion mostrar el vector
    bool contains(int id, int x, int y, int largo, int direccion); // Funcion para saber si un auto esta en el vector
    Auto *buscarPorId(int id);                                     // Funcion para buscar un auto por su id
    void remplazar(Auto *newCar);                               // Funcion para remplazar un auto en el vector
                                                                   // private:
    int cap;                                                       // Capacidad del vector
    int top;                                                       // Tope del vector
    Auto **stack;                                                  // Vector de autos
};

#endif