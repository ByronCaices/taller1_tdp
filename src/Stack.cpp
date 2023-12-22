#include "Stack.h"
#include <string>

// Contructor de un vector
Stack::Stack(int capacity)
{
    this->cap = capacity;
    this->top = -1;
    this->stack = new Auto *[capacity];
}

// Destructor de un vector
Stack::~Stack()
{
    delete[] this->stack;
};

// Funcion para agregar un auto al vector
void Stack::push(Auto *car)
{
    if (this->top == this->cap - 1)
    {
        Auto **aux = new Auto *[this->cap * 2];
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
void Stack::printVector()
{
    for (int i = 0; i <= this->top; i++)
    {
        std::cout << this->stack[i]->id << " " << this->stack[i]->posX << " " << this->stack[i]->posY << " " << this->stack[i]->Direccion << " " << this->stack[i]->Largo << std::endl;
    }
    std::cout << std::endl;
};

// Funcion para saber si un auto esta en el vector
bool Stack::contains(int id, int x, int y, int largo, int direccion)
{

    if (this->stack[id - 1]->posX == x && this->stack[id - 1]->posY == y && this->stack[id - 1]->Largo == largo && this->stack[id - 1]->Direccion == direccion)
    {
        return true;
    }
    return false;
};

// Funcion para buscar un auto por su id
Auto *Stack::buscarPorId(int id)
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

// Funcion para reemplazar un auto en el vector
void Stack::remplazar(Auto *autoNuevo)
{

    this->stack[autoNuevo->id - 1] = autoNuevo;

    /* for(int i = 0; i <= this->tope; i++){
        if(this->vector[i]->id == autoNuevo->id){
            this->vector[i] = autoNuevo;
        }
    } */
};
