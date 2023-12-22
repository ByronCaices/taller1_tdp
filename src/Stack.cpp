#include <string>
#include "Stack.h"

/*
 * Method: Stack
 * Description: Constructor
 * Parameters:
 * - capacity: Capacidad del stack
 * Returns:
 * - Stack: Instancia de la clase Stack
 */
Stack::Stack(int capacity)
{
    this->cap = capacity;
    this->top = -1;
    this->stack = new Car *[capacity];
}

/*
 * Method: ~Stack
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
Stack::~Stack()
{
    delete[] this->stack;
};

/*
 * Method: push
 * Description: Metodo para agregar un auto al stack
 * Parameters:
 * - car: Auto a agregar
 * Returns:
 * - void
 */
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

/*
 * Method: isEmpty
 * Description: Metodo saber si el stack esta vacio
 * Parameters:
 * - void
 * Returns:
 * - void
 */
bool Stack::isEmpty()
{
    return this->top == -1;
};

/*
 * Method: printStack
 * Description: Imprime stack en consola
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void Stack::printStack()
{
    for (int i = 0; i <= this->top; i++)
    {
        std::cout << this->stack[i]->id << " " << this->stack[i]->columna << " " << this->stack[i]->fila << " " << this->stack[i]->dir << " " << this->stack[i]->largo << std::endl;
    }
    std::cout << std::endl;
};

/*
 * Method: contains
 * Description: Metodo para saber si un auto esta en el stack
 * Parameters:
 * - id: Id del auto
 * - x: Columna del auto
 * - y: Fila del auto
 * - largo: Largo del auto
 * - direccion: Direccion del auto
 * Returns:
 * - bool
 */
bool Stack::contains(int id, int x, int y, int largo, int direccion)
{

    if (this->stack[id - 1]->columna == x && this->stack[id - 1]->fila == y && this->stack[id - 1]->largo == largo && this->stack[id - 1]->dir == direccion)
    {
        return true;
    }
    return false;
};

/*
 * Method: replace
 * Description: Metodo para reemplazar un auto en el stack
 * Parameters:
 * - newCar: Nuevo auto
 * Returns:
 * - void
 */
void Stack::replace(Car *newCar)
{

    this->stack[newCar->id - 1] = newCar;
};

/*
 * Method: searchById
 * Description: Metodo para buscar un auto por su id
 * Parameters:
 * - id: Id del auto
 * Returns:
 * - Car: Auto
 */
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
