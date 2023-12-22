#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include "Car.h"

class Stack
{
public:
    Stack(int cap); // Contructor de un vector
    ~Stack();       // Destructor de un vector

    void push(Car *auto_);                                         // Funcion para agregar un auto al vector
    bool isEmpty();                                                // Funcion saber si el vector esta vacio
    void printStack();                                             // Funcion mostrar el vector
    bool contains(int id, int x, int y, int largo, int direccion); // Funcion para saber si un auto esta en el vector
    Car *searchById(int id);                                       // Funcion para buscar un auto por su id
    void replace(Car *newCar);                                     // Funcion para remplazar un auto en el vector
                                                                   // private:
    int cap;                                                       // Capacidad del vector
    int top;                                                       // Tope del vector
    Car **stack;                                                   // Vector de autos
};

#endif