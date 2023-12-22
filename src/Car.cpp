#include "Car.h"

/*
 * Method: Car
 * Description: Constructor de un auto
 * Parameters:
 * - id: Identificador del auto
 * - col: Posicion en x del auto
 * - fila: Posicion en y del auto
 * - largo: Largo del auto
 * - dir: Direccion del auto
 * Returns:
 * - Instancia de la clase Car
 */
Car::Car(int id, int col, int fila, int largo, int dir)
{
    this->id = id;
    this->columna = col;
    this->fila = fila;
    this->dir = dir;
    this->largo = largo;
}

/*
 * Method: ~Car
 * Description: Destructor de un auto
 * Parameters:
 * - void
 * Returns:
 * - void
 */
Car::~Car()
{
}

/*
 * Method: ~Car
 * Description: Clonador de un auto
 * Parameters:
 * - copia: Auto a copiar
 * Returns:
 * - Instancia de la clase Car
 */
Car::Car(const Car &copia)
{
    this->id = copia.id;
    this->columna = copia.columna;
    this->fila = copia.fila;
    this->dir = copia.dir;
    this->largo = copia.largo;
}

/*
 * Method: move
 * Description: Funcion para mover un auto
 * Parameters:
 * - op: Operacion a realizar
 * - board: Tablero de juego
 * - walls: Paredes del tablero
 * Returns:
 * - Auto movido
 */
Car *Car::move(Operation *op, int **board, int **walls)
{
    Car *copia;
    if (verifyMove(board, op, walls))
    {
        copia = op->operate(this);
        return copia;
    }
    else
    {
        copia = nullptr;
    }
    return nullptr;
}

/*
 * Method: verifyMove
 * Description: Metodo para verificar si un auto puede moverse
 * Parameters:
 * - board: Tablero de juego
 * - op: Operacion a realizar
 * - walls: Paredes del tablero
 * Returns:
 * - bool
 */
bool Car::verifyMove(int **board, Operation *op, int **walls)
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

    // Se calcula la cantidad de pasos que se mueve
    pasosx = abs(llegada_x - inicio_x);
    pasosy = abs(llegada_y - inicio_y);

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
