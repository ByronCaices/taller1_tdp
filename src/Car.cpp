#include "Operacion.h"
#include "Car.h"

// Contructor de un auto
Car::Car(int id, int col, int fila, int largo, int dir)
{
    this->id = id;
    this->columna = col;
    this->fila = fila;
    this->dir = dir;
    this->largo = largo;
}

// Destructor de un auto
Car::~Car()
{
}

// Constructor de copia de un auto
Car::Car(const Car &copia)
{
    this->id = copia.id;
    this->columna = copia.columna;
    this->fila = copia.fila;
    this->dir = copia.dir;
    this->largo = copia.largo;
}

// Funcion para mover un auto
Car *Car::mover(Operacion *op, int **tablero, int **paredes)
{
    Car *copia;
    if (verificarMovimiento(tablero, op, paredes))
    {
        copia = op->operar(this);
        return copia;
    }
    else
    {
        copia = nullptr;
    }
    return nullptr;
}

// Funcion para verificar si un auto puede moverse
bool Car::verificarMovimiento(int **tablero, Operacion *op, int **paredes)
{
    int llegada_x, llegada_y, inicio_x, inicio_y, pasosx, pasosy;

    // Se calcula la posicion de llegada
    if (this->dir == HORIZONTAL)
    { // Si el auto esta en horizontal
        if (op->paso > 0)
        {
            inicio_x = this->columna + this->largo;
            llegada_x = this->columna + this->largo - 1 + op->paso;
            llegada_y = this->fila;
        }
        else if (op->paso < 0)
        {
            inicio_x = this->columna - 1;
            llegada_x = this->columna + op->paso;
            llegada_y = this->fila;
        }
    }
    else if (this->dir == VERTICAL)
    { // Si el auto esta en vertical
        if (op->paso > 0)
        {
            inicio_y = this->fila + this->largo;
            llegada_x = this->columna;
            llegada_y = this->fila + this->largo - 1 + op->paso;
        }
        else if (op->paso < 0)
        {
            inicio_y = this->fila - 1;
            llegada_x = this->columna;
            llegada_y = this->fila + op->paso;
        }
    }

    if (llegada_x < 0 || llegada_y < 0 || llegada_x > 5 || llegada_y > 5)
    { // Si se sale del tablero
        return false;
    }

    pasosx = abs(llegada_x - inicio_x); // Se calcula la cantidad de pasos que se mueve
    pasosy = abs(llegada_y - inicio_y); // Se calcula la cantidad de pasos que se mueve

    if (this->dir == HORIZONTAL)
    { // Si el auto esta en horizontal
        if (op->paso > 0)
        {
            for (int i = 0; i <= pasosx; i++)
            { // Se verifica que no haya autos en el camino
                if ((tablero[llegada_y][llegada_x - i] != 0) || (paredes[llegada_y][llegada_x - i] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
        else if (op->paso < 0)
        {
            for (int i = 0; i <= pasosx; i++)
            { // Se verifica que no haya autos en el camino
                if ((tablero[llegada_y][llegada_x + i] != 0) || (paredes[llegada_y][llegada_x + i] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }
    else if (this->dir == VERTICAL)
    { // Si el auto esta en vertical
        if (op->paso > 0)
        {
            for (int i = 0; i <= pasosy; i++)
            { // Se verifica que no haya autos en el camino
                if ((tablero[llegada_y - i][llegada_x] != 0) || (paredes[llegada_y - i][llegada_x] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
        else if (op->paso < 0)
        {
            for (int i = 0; i <= pasosy; i++)
            { // Se verifica que no haya autos en el camino
                if ((tablero[llegada_y + i][llegada_x] != 0) || (paredes[llegada_y + i][llegada_x] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }

    if (paredes[llegada_y][llegada_x] == 1)
    { // Si hay una pared
        return false;
    }

    if (tablero[llegada_y][llegada_x] == 0) // Si no hay un auto
        return true;
    else
        return false;
}
