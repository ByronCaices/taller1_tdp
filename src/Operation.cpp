#include "Operation.h"
#include "Car.h"

// Contructor de una operacion
Operation::Operation(int dir, int step)
{
    this->dir = dir;
    this->step = step;
}

// Contructor de una operacion
Operation::Operation()
{
    this->dir = -1;
    this->step = -1;
}

// Destructor de una operacion
Operation::~Operation()
{
}

// Funcion para mostrar una operacion
void Operation::printOperacion()
{
    std::cout << "Direccion: " << this->dir << " Paso: " << this->step << std::endl;
}

// Funcion para operar un auto
Car *Operation::operar(Car *car)
{
    int sumaX, sumaY = 0;
    // printf("auto: %d\n", car->id);

    if (car->dir == HORIZONTAL)
    {                       // Si el auto es horizontal
        sumaX = this->step; // Suma el paso a la posicion en x
        sumaY = 0;
    }
    else if (car->dir == VERTICAL)
    { // Si el auto es vertical
        sumaX = 0;
        sumaY = this->step; // Suma el paso a la posicion en y
    }

    Car *auxCar = new Car( // Crea un nuevo auto con la posicion actualizada
        car->id,
        car->columna + sumaX,
        car->fila + sumaY,
        car->largo,
        car->dir);

    return auxCar; // Retorna el auto actualizado
}