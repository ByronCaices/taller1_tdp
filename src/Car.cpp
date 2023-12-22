#include "Car.h"
#include "Operation.h"

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
Car *Car::mover(Operation *op, int **board, int **walls)
{
    Car *copia;
    if (verificarMovimiento(board, op, walls))
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
bool Car::verificarMovimiento(int **board, Operation *op, int **walls)
{
    int llegada_x, llegada_y, inicio_x, inicio_y, pasosx, pasosy;

    // Se calcula la posicion de llegada
    if (this->dir == HORIZONTAL)
    { // Si el auto esta en horizontal
        if (op->step > 0)
        {
            inicio_x = this->columna + this->largo;
            llegada_x = this->columna + this->largo - 1 + op->step;
            llegada_y = this->fila;
        }
        else if (op->step < 0)
        {
            inicio_x = this->columna - 1;
            llegada_x = this->columna + op->step;
            llegada_y = this->fila;
        }
    }
    else if (this->dir == VERTICAL)
    { // Si el auto esta en vertical
        if (op->step > 0)
        {
            inicio_y = this->fila + this->largo;
            llegada_x = this->columna;
            llegada_y = this->fila + this->largo - 1 + op->step;
        }
        else if (op->step < 0)
        {
            inicio_y = this->fila - 1;
            llegada_x = this->columna;
            llegada_y = this->fila + op->step;
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
        if (op->step > 0)
        {
            for (int i = 0; i <= pasosx; i++)
            { // Se verifica que no haya autos en el camino
                if ((board[llegada_y][llegada_x - i] != 0) || (walls[llegada_y][llegada_x - i] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
        else if (op->step < 0)
        {
            for (int i = 0; i <= pasosx; i++)
            { // Se verifica que no haya autos en el camino
                if ((board[llegada_y][llegada_x + i] != 0) || (walls[llegada_y][llegada_x + i] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }
    else if (this->dir == VERTICAL)
    { // Si el auto esta en vertical
        if (op->step > 0)
        {
            for (int i = 0; i <= pasosy; i++)
            { // Se verifica que no haya autos en el camino
                if ((board[llegada_y - i][llegada_x] != 0) || (walls[llegada_y - i][llegada_x] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
        else if (op->step < 0)
        {
            for (int i = 0; i <= pasosy; i++)
            { // Se verifica que no haya autos en el camino
                if ((board[llegada_y + i][llegada_x] != 0) || (walls[llegada_y + i][llegada_x] == 1))
                { // Si hay un auto o una pared
                    return false;
                }
            }
        }
    }

    if (walls[llegada_y][llegada_x] == 1)
    { // Si hay una pared
        return false;
    }

    if (board[llegada_y][llegada_x] == 0) // Si no hay un auto
        return true;
    else
        return false;
}
