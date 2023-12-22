#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>
#include "Stack.h"
#include "Operacion.h"


class Estado{
    public:
        Estado(Stack *autos, Operacion *Op, Estado *padre, Car* automoviendose); // Constructor de un estado
        Estado(Stack *autos, Operacion *Op, int idAuto); // Constructor de un estado 
        ~Estado(); // Destructor de un estado
        void mostrarEstado(); // Funcion para mostrar un estado
        bool esSolucion(); // Funcion para verificar si un estado es solucion
        int CalcularHeuristica() const; // Funcion para calcular la heuristica de un estado
        Stack* getAutos() const; // Funcion para obtener los autos de un estado
        void mostrartablero(); // Funcion para mostrar el tablero de un estado
        void mostrarsolucion(); // Funcion para mostrar la solucion de un estado

        

    //private:
        Stack *autos; // Vector de autos
        Operacion *Op; // Operacion que se realizo para llegar a este estado
        Estado *padre;  // Padre de este estado
        Car* automoviendose; // Auto que se esta moviendo en este estado
        int heuristica; // Costo acumulado de este estado
        //int heuristica; // Heuristica de este estado    
        std::string toString() const; // Funcion para convertir un estado a string
};

#endif // ESTADO_H