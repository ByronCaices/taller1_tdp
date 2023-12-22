#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include "Car.h"

/*
 * Clase Stack:
 * Representa un stack
 * top: Tope del stack
 * cap: Capacidad del stack
 * stack: stack de autos
 */
class Stack
{
public:
    int top;     // Tope del stack
    int cap;     // Capacidad del stack
    Car **stack; // stack de autos

    Stack(int cap); // Contructor de un stack
    ~Stack();       // Destructor de un stack

    void push(Car *auto_);                                         // Metodo para agregar un auto al stack
    bool isEmpty();                                                // Metodo saber si el stack esta vacio
    bool contains(int id, int x, int y, int largo, int direccion); // Metodo para saber si un auto esta en el stack
    void replace(Car *newCar);                                     // Metodo para reemplazar un auto en el stack
    Car *searchById(int id);                                       // Metodo para buscar un auto por su id
    void printStack();                                             // Metodo mostrar el stack
};

#endif