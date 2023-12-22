#include "State.h"
#include <sstream>

/*
 * Method: State
 * Description: Constructor
 * Parameters:
 * - cars: Stack de autos
 * - op: Operacion que se realizo para llegar a este estado
 * - padre: Padre de este estado
 * - movingCar: Auto que se esta moviendo en este estado
 * Returns:
 * - Instancia de la clase State
 */
State::State(Stack *cars, Operation *op, State *padre, Car *movingCar)
{
    this->cars = cars;
    this->op = op;
    this->padre = padre;
    this->movingCar = movingCar;
    this->heuristica = 0;
};

/*
 * Method: State
 * Description: Constructor
 * Parameters:
 * - cars: Stack de autos
 * - op: Operacion que se realizo para llegar a este estado
 * - idCar: Id del auto que se esta moviendo en este estado
 * Returns:
 * - Instancia de la clase State
 */
State::State(Stack *cars, Operation *op, int idCar)
{
    this->cars = cars;
    this->op = op;
    this->padre = nullptr;
    this->movingCar = nullptr;
    this->heuristica = 0;
};

// Destructor de un estado
/*
 * Method: ~State
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
State::~State(){

};

/*
 * Method: printState
 * Description: Metodo para mostrar un estado
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void State::printState()
{
    this->cars->printStack();
};

/*
 * Method: isSolution
 * Description: Metodo para verificar si un estado es solucion
 * Parameters:
 * - void
 * Returns:
 * - bool
 */
bool State::isSolution()
{
    // Busca el auto rojo en la posicion de salida
    bool p = this->cars->contains(1, 4, 2, 2, HORIZONTAL);
    if (p)
    {
        // Si el auto rojo esta en la posicion de salida, entonces es solucion
        return true;
    }
    else
    {
        // Si el auto rojo no esta en la posicion de salida, entonces no es solucion
        return false;
    }
};

/*
 * Method: toString
 * Description: Metodo para para convertir un estado a string
 * Parameters:
 * - void
 * Returns:
 * - string
 */
std::string State::toString() const
{
    std::stringstream sstream;
    for (int i = 0; i <= this->cars->top; i++)
    {
        const Car *car = this->cars->stack[i];
        sstream << car->id << " " << car->columna << " " << car->fila << " " << car->dir << " " << car->largo << std::endl;
    }
    return sstream.str();
};

/*
 * Method: getCars
 * Description: Metodo para obtener los autos de un estado
 * Parameters:
 * - void
 * Returns:
 * - stack de autos
 */
Stack *State::getCars() const
{
    return this->cars;
};

/*
 * Method: printSolution
 * Description: Metodo para mostrar la solucion final
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void State::printSolution()
{
    if (this->padre != nullptr)
    {
        State *padre = this->padre;
        padre->printSolution();
    }
    if (this->op != nullptr)
    {
        if (movingCar->dir == HORIZONTAL)
        {
            if (op->step > 0)
            {
                std::cout << "El auto " << movingCar->id << " se mueve a la derecha, " << abs(op->step) << " Pasos" << std::endl;
            }
            else if (op->step < 0)
            {
                std::cout << "El auto " << movingCar->id << " se mueve a la izquierda " << abs(op->step) << " Pasos" << std::endl;
            }
        }
        else if (movingCar->dir == VERTICAL)
        {
            if (op->step > 0)
            {
                std::cout << "El auto " << movingCar->id << " se mueve hacia abajo " << abs(op->step) << " Pasos" << std::endl;
            }
            else if (op->step < 0)
            {
                std::cout << "El auto " << movingCar->id << " se mueve hacia arriba " << abs(op->step) << " Pasos" << std::endl;
            }
        }
        else
        {
            std::cout << "Estado Inicial" << std::endl;
        }
    }
};
