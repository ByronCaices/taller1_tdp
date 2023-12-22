#include <string>
#include "Stack.h"

// Contructor de un vector
Stack::Stack(int capacity)
{
    this->cap = capacity;
    this->top = -1;
    this->stack = new Car *[capacity];
}

// Destructor de un vector
Stack::~Stack()
{
    delete[] this->stack;
};

// Funcion para agregar un auto al vector
void Stack::push(Car *car)
{
    if (this->top == this->cap - 1)
    {
        Car **aux = new Car *[this->cap * 2];
        for (int i = 0; i < this->cap; i++)
        {
            aux[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = aux;
        this->cap *= 2;
    }
    this->top++;
    this->stack[this->top] = car;
};

// Funcion saber si el vector esta vacio
bool Stack::isEmpty()
{
    return this->top == -1;
};

// Funcion mostrar el vector
void Stack::printStack()
{
    for (int i = 0; i <= this->top; i++)
    {
        std::cout << this->stack[i]->id << " " << this->stack[i]->columna << " " << this->stack[i]->fila << " " << this->stack[i]->dir << " " << this->stack[i]->largo << std::endl;
    }
    std::cout << std::endl;
};

// Funcion para saber si un auto esta en el vector
bool Stack::contains(int id, int x, int y, int largo, int direccion)
{

    if (this->stack[id - 1]->columna == x && this->stack[id - 1]->fila == y && this->stack[id - 1]->largo == largo && this->stack[id - 1]->dir == direccion)
    {
        return true;
    }
    return false;
};

// Funcion para reemplazar un auto en el vector
void Stack::replace(Car *newCar)
{

    this->stack[newCar->id - 1] = newCar;
};

// Funcion para buscar un auto por su id
Car *Stack::searchById(int id)
{
    for (int i = 0; i <= this->top; i++)
    {
        if (this->stack[i]->id == id)
        {
            return this->stack[i];
        }
    }
    return NULL;
};

