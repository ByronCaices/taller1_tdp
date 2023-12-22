#include "State.h"
#include <sstream>

// Contructor de un estado
State::State(Stack *cars, Operation *op, State *padre, Car *movingCar)
{
    this->cars = cars;
    this->op = op;
    this->padre = padre;
    this->movingCar = movingCar;
    this->heuristica = 0;
};

// Contructor de un estado
State::State(Stack *cars, Operation *op, int idCar)
{
    this->cars = cars;
    this->op = op;
    this->padre = nullptr;
    this->movingCar = nullptr;
    this->heuristica = 0;
    // this->heuristica = CalcularHeuristica();
};

// Destructor de un estado
State::~State(){

};

// Funcion para mostrar un estado
void State::mostrarEstado()
{
    this->cars->printVector();
};

// Funcion para verificar si un estado es solucion

bool State::esSolucion()
{
    bool p = this->cars->contains(1, 4, 2, 2, HORIZONTAL); // Busca el auto rojo en la posicion de salida
    if (p)
    {
        return true; // Si el auto rojo esta en la posicion de salida, entonces es solucion
    }
    else
    {
        return false; // Si el auto rojo no esta en la posicion de salida, entonces no es solucion
    }
};

// Funcion para convertir un estado a string
std::string State::toString() const
{
    std::stringstream ss;
    for (int i = 0; i <= this->cars->top; i++)
    {
        const Car *auto_ = this->cars->stack[i];
        ss << auto_->id << " " << auto_->columna << " " << auto_->fila << " " << auto_->dir << " " << auto_->largo << std::endl;
    }
    return ss.str();
};

// Funcion para obtener los autos de un estado
Stack *State::getAutos() const
{
    return this->cars;
};

// Funcion para mostrar la solucion final
void State::mostrarsolucion()
{
    if (this->padre != nullptr)
    {
        State *padre = this->padre;
        padre->mostrarsolucion();
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
