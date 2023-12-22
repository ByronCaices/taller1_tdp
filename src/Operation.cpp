#include "Operation.h"
#include "Car.h"

/*
 * Method: Operation
 * Description: Constructor
 * Parameters:
 * - dir: Direccion de la operacion
 * - step: Paso de la operacion
 * Returns:
 * - Operation: Instancia de la clase Operation
 */
Operation::Operation(int dir, int step)
{
    this->dir = dir;
    this->step = step;
}

/*
 * Method: Operation
 * Description: Constructor
 * Parameters:
 * - void
 * Returns:
 * - Operation: Instancia de la clase Operation
 */
Operation::Operation()
{
    this->dir = -1;
    this->step = -1;
}

/*
 * Method: ~Operation
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
Operation::~Operation()
{
}

/*
 * Method: printOperation
 * Description: metodo para mostrar una operacion
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void Operation::printOperation()
{
    std::cout << "Direccion: " << this->dir << " Paso: " << this->step << std::endl;
}

/*
 * Method: operate
 * Description: metodo para operar un auto
 * Parameters:
 * - car: Auto a operar
 * Returns:
 * - Car: Auto operado
 */
Car *Operation::operate(Car *car)
{
    int sumaX, sumaY = 0;

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

    return auxCar;
}