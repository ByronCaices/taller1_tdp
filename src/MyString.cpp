#include <iostream>
#include <string>
#include "MyString.h"

// Constructor de un stack
MyString::MyString(int capcity)
{
    this->cap = capcity;
    this->top = -1;
    this->stack = new std::string[capcity];
}

// Destructor de un stack
MyString::~MyString()
{
    delete[] this->stack;
}

// Función para agregar un string al stack
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

// Función para saber si el stack está vacío
bool MyString::isEmpty()
{
    return this->top == -1;
}

// Función para mostrar el stack
void MyString::printVector()
{
    for (int i = 0; i <= this->top; i++)
    {
        std::cout << this->stack[i] << " ";
    }
    std::cout << std::endl;
}

// Función para saber si una cadena está en el vector
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

// Función para obtener un string en una posición específica
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
