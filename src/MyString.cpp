#include <iostream>
#include <string>
#include "MyString.h"

/*
 * Method: MyString
 * Description: Constructor
 * Parameters:
 * - capacity: Capacidad del stack
 * Returns:
 * - Stack: Instancia de la clase Stack
 */
MyString::MyString(int capcity)
{
    this->cap = capcity;
    this->top = -1;
    this->stack = new std::string[capcity];
}

/*
 * Method: ~MyString
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
MyString::~MyString()
{
    delete[] this->stack;
}

/*
 * Method: push
 * Description: Metodo para agregar un string al stack
 * Parameters:
 * - string: String a agregar
 * Returns:
 * - void
 */
void MyString::push(const std::string &str)
{
    if (this->top == this->cap - 1)
    {
        std::string *aux = new std::string[this->cap * 2];
        for (int i = 0; i < this->cap; i++)
        {
            aux[i] = this->stack[i];
        }
        delete[] this->stack;
        this->stack = aux;
        this->cap *= 2;
    }
    this->top++;
    this->stack[this->top] = str;
}

/*
 * Method: isEmpty
 * Description: Metodo saber si el stack esta vacio
 * Parameters:
 * - void
 * Returns:
 * - void
 */
bool MyString::isEmpty()
{
    return this->top == -1;
}

/*
 * Method: printMyString
 * Description: Imprime stack en consola
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void MyString::printMyString()
{
    for (int i = 0; i <= this->top; i++)
    {
        std::cout << this->stack[i] << " ";
    }
    std::cout << std::endl;
}

/*
 * Method: contains
 * Description: Metodo para saber si un string específico está en el vector
 * Parameters:
 * - string: String a buscar
 * Returns:
 * - bool
 */
bool MyString::contains(const std::string &str)
{
    for (int i = 0; i <= this->top; i++)
    {
        if (this->stack[i] == str)
        {
            return true;
        }
    }
    return false;
}

/*
 * Method: get
 * Description: Metodo para obtener un string en una posición específica
 * Parameters:
 * - index: Indice del string a obtener
 * Returns:
 * - string
 */
std::string MyString::get(int index)
{
    if (index >= 0 && index <= this->top)
    {
        return this->stack[index];
    }
    else
    {
        std::cerr << "Index out of bounds." << std::endl;
        return "";
    }
}
