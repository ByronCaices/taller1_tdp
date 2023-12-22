#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "Operacion.h"
#include "Stack.h"
#include "Estado.h"

class Tablero{
    public:
        Tablero(int Largo); // Constructor de un tablero
        ~Tablero(); // Destructor de un tablero
        Car* operarauto(Car* auto_); // Funcion para operar un auto 
        Estado* resolver(Estado* estadoinicial); // Funcion para resolver el problema 
        Stack* copiarVectorProfundamente(Stack* original); // Funcion para copiar un vector profundamente 
        void llenarTablero(Stack* autos); // Funcion para llenar el tablero con los autos del vector de autos
        void vaciarTablero(); // Funcion para vaciar el tablero
        void MostarTablero(); // Funcion para mostrar el tablero
        void setParedes(int** paredes); // Funcion para setear las paredes
        void mostrarParedes(); // Funcion para mostrar las paredes
        
    private:
        int Largo; // Largo del tablero
        int** tablero; // Tablero
        int** paredes; // Paredes
        Operacion operaciones[7]; // Operaciones   
};

#endif
