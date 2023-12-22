#include <iostream>
#include <stdlib.h>
#include "Car.h"
#include "MyString.h"
#include "State.h"
#include "Board.h"
#include "Heap.h"
#include "Stack.h"

#define VERTICAL 1
#define HORIZONTAL 0

using namespace std;

/*
 * Method: Board
 * Description: Constructor
 * Parameters:
 * - int length: Largo del tablero
 * Returns:
 * - Board: Tablero
 */
Board::Board(int length)
{
    this->size = length;
    this->board = new int *[length];
    for (int i = 0; i < length; ++i)
    {
        this->board[i] = new int[length];
    }
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            this->board[i][j] = 0;
        }
    }

    // Creamos las operaciones disponibles para mover los autos
    this->ops[0] = Operation(0, 1);
    this->ops[1] = Operation(0, -1);
    this->ops[2] = Operation(0, 2);
    this->ops[3] = Operation(0, -2);
    this->ops[4] = Operation(0, 3);
    this->ops[5] = Operation(0, -3);
    this->ops[6] = Operation(0, 4);
    this->ops[7] = Operation(0, -4);
}

/*
 * Method: ~Board
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
Board::~Board()
{
    for (int i = 0; i < this->size; ++i)
    {
        delete[] this->board[i];
    }
    delete[] this->board;
}

/*
    * Method: astar
    * Description: Funcion para resolver el problema con el algoritmo A*. El metodo recibe un estado inicial y devuelve un estado final
    mientras la cola de prioridad no este vacia, se saca el estado con menor costo acumulado (dado la heuristica) y se agregan los estados
    hijos a la cola de prioridad. Si el estado actual es solucion, se devuelve este estado. Si la cola de prioridad se vacia y no se encontro
    solucion, se devuelve nullptr (no se encontro solucion)
    * Parameters:
    * - State *inicial: Estado inicial
    * Returns:
    * - State: Estado final
*/
State *Board::astar(State *inicial)
{

    inicial->heuristica = 0;
    Heap priorityQueue(1000);
    priorityQueue.push(inicial);
    
    // llenamos el tablero con los autos del estado inicial
    this->fillBoard(inicial->getCars()); 
    cout << "\t-> Estado Inicial:" << endl;
    
    // imprimimos el Vector de autos del estado inicial
    inicial->getCars()->printStack(); 

    // imprimimos el tablero y paredes
    cout << "\t-> Tablero Inicial:" << endl;
    this->printBoard(); 
    cout << "\t-> Paredes del tablero:" << endl;
    this->printWalls(); 
    
    cout << "\t<<< Buscando solucion... >>>" << endl;
    // creamos un string para guardar los estados visitados como string
    MyString *visitedStates = new MyString(1000); 

    while (!priorityQueue.isEmpty())            
    {
        State *actual = priorityQueue.pop(); // saco el estado con menor costo 

        visitedStates->push(actual->toString()); // agregamos el estado a los estados visitados

        this->fillBoard(actual->getCars()); // llenamos el tablero con los autos del estado actual

        if (actual->isSolution())           // si el estado actual es solucion
        {
            cout << "\t<<< ¡Solucion encontrada! >>>\n" << endl;
            cout << "\t-> Estado Final:" << endl;
            actual->printState(); // imprimimos el estado
            cout << "\t-> Tablero Final:" << endl;
            this->printBoard(); // imprimimos el tablero
            cout << "<<< Movimientos realizados: " << actual->heuristica << endl;
            actual->printSolution(); // imprimimos la solucion
            State *aux = new State(*actual);
            return aux;
        }

        Stack *autos = actual->getCars(); // obtenemos el Vector de autos del estado actual

        for (int i = 0; i <= autos->top; i++) // por cada auto en el Vector de autos
        {

            Car *clonedCar = autos->stack[i]; 

            for (int j = 0; j < 8; j++) 
            {
                // Copiar el Vector de autos

                Car *newCar = clonedCar->move(&this->ops[j], this->board, this->walls); // movemos el auto con la operacion

                if (newCar != nullptr) // si el auto se pudo mover
                {
                    if (newCar->columna < 0 || newCar->columna > 5 || newCar->fila < 0 || newCar->fila > 5) // verificacion adicional de que el auto no se salga del tablero
                    {
                        continue; // si el auto se sale del tablero, no se hace nada
                    }
                    else
                    {
                        Stack *carsCopy = copyStack(autos); // copiamos el Vector de autos
                        carsCopy->replace(newCar);          // reemplazamos el auto en el Vector de autos

                        State *newState = new State(carsCopy, &this->ops[j], actual, newCar); // creamos un nuevo estado con el Vector de autos copiado
                        
                        if (priorityQueue.contains(newState) || visitedStates->contains(newState->toString()))
                        {             // si la cola de prioridad ya contiene el estado 
                            continue; // se continua
                        }
                        newState->heuristica = actual->heuristica + 1; // aumentamos el costo acumulado
                        priorityQueue.push(newState);                  // agregamos el nuevo estado a la cola de prioridad
                    }
                }
            }
        }
    }
    cout << "No se encontro solucion" << endl; // si la cola de prioridad se vacia y no se encontro solucion
    return nullptr;
};

/*
 * Method: copyStack
 * Description: metodo para copiar un Vector de autos
 * Parameters:
 * - Stack *original: Vector de autos a copiar
 * Returns:
 * - Stack: Vector de autos copiado
 */
Stack *Board::copyStack(Stack *original) // copia el Vector de autos
{
    Stack *stackCopy = new Stack(original->cap);
    for (int i = 0; i <= original->top; i++)
    {
        Car *originalCar = original->stack[i];
        Car *copiedCar = new Car(*originalCar);
        stackCopy->push(copiedCar);
    }
    return stackCopy;
}

/*
 * Method: fillBoard
 * Description: metodo para llenar el tablero con los autos del stack de autos
 * Parameters:
 * - Stack *autos: Vector de autos
 * Returns:
 * - void
 */
void Board::fillBoard(Stack *autos)
{

    for (int i = 0; i < this->size; i++) // llenamos el tablero con ceros
    {
        for (int j = 0; j < this->size; j++)
        {
            this->board[i][j] = 0;
        }
    }

    for (int i = 0; i <= autos->top; i++) // llenamos el tablero con los autos del Vector de autos
    {
        Car *car = autos->stack[i];
        int x = car->columna;
        int y = car->fila;
        int largo = car->largo;
        int direccion = car->dir;

        if (direccion == HORIZONTAL)
        {
            for (int j = 0; j < largo; j++)
            {
                this->board[y][x + j] = car->id; // esto sirve para mostrar el tablero correctamente
            }
        }
        else if (direccion == VERTICAL)
        {
            for (int j = 0; j < largo; j++)
            {
                this->board[y + j][x] = car->id; // esto sirve para mostrar el tablero correctamente
            }
        }
    }
}

/*
 * Method: emptyBoard
 * Description: Metodo para vaciar el tablero
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void Board::emptyBoard()
{
    for (int i = 0; i < this->size; i++) // llenamos el tablero con ceros
    {
        for (int j = 0; j < this->size; j++)
        {
            board[i][j] = 0;
        }
    }
}

/*
 * Method:  printBoard
 * Description: Metodo para mostrar el tablero
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void Board::printBoard()
{
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            cout << this->board[i][j] << " "; // mostramos el tablero
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * Method: setWalls
 * Description: Metodo para setear las paredes del tablero
 * Parameters:
 * - Matriz paredes: Puntero a un puntero de enteros que representa las paredes
 * Returns:
 * - void
 */
void Board::setWalls(int **paredes)
{
    this->walls = paredes;
}

/*
 * Method: printWalls
 * Description: Metodo para mostrar las paredes del tablero
 * Parameters:
 * - void
 * Returns:
 * - void
 */
void Board::printWalls()
{
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            cout << this->walls[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}