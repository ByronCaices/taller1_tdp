#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>

/* 
    * Clase MyString:
    * Descripcion: Clase que representa un string
    * string: String a agregar
    * cap: Capacidad actual del vector
    * top: Índice del último elemento en el vector
*/
class MyString
{
private:
    std::string *stack; 
    int cap;            
    int top;            

public:
    MyString(int capacidad);               // Constructor que inicializa el vector con una capacidad dada
    ~MyString();                           // Destructor que libera la memoria asignada al vector
    void push(const std::string &str);     // Método para agregar un string al vector
    bool isEmpty();                        // Método para determinar si el vector está vacío
    void printMyString();                  // Método para imprimir todos los strings en el vector
    bool contains(const std::string &str); // Método para verificar si un string específico está en el vector
    std::string get(int index);            // Método para obtener un string en una posición específica
};

#endif