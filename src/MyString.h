#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>

class MyString
{
public:
    // Constructor que inicializa el vector con una capacidad dada
    MyString(int capacidad);

    // Destructor que libera la memoria asignada al vector
    ~MyString();

    // Método para agregar un string al vector
    void push(const std::string &str);

    // Método para determinar si el vector está vacío
    bool isEmpty();

    // Método para imprimir todos los strings en el vector
    void printVector();

    // Método para verificar si un string específico está en el vector
    bool contains(const std::string &str);

    // Método para obtener un string en una posición específica
    std::string get(int index);

private:
    std::string *stack; // Puntero al array dinámico que contiene los strings
    int cap;            // Capacidad actual del vector
    int top;            // Índice del último elemento en el vector
};

#endif