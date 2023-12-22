#include "Heap.h"

/*
 * Method: Heap
 * Description: Constructor
 * Parameters:
 * - capacity: Capacidad del heap
 * Returns:
 * - Heap: Instancia de la clase Heap
 */
Heap::Heap(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->heap = new State *[capacity];
}

/*
 * Method: ~Heap
 * Description: Destructor
 * Parameters:
 * - void
 * Returns:
 * - void
 */
Heap::~Heap()
{
    for (int i = 0; i < this->size; i++)
    {
        delete this->heap[i];
    }
    delete[] this->heap;
}

/*
 * Method: swap
 * Description: metodo para intercambiar dos estados
 * Parameters:
 * - i: indice del primer estado
 * - j: indice del segundo estado
 * Returns:
 * - void
 */
void Heap::swap(int i, int j)
{
    State *temp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = temp;
}

/*
 * Method: pop
 * Description: metodo para obtener el estado con menor costo acumulado y heuristica
 * Parameters:
 * - void
 * Returns:
 * - State: estado con menor costo acumulado y heuristica
 */
State *Heap::pop()
{
    if (isEmpty())
    { // Ojo retorna nulo si esta vacio
        return nullptr;
    }
    State *state = this->heap[0];               // tomo la raiz
    this->heap[0] = this->heap[this->size - 1]; // pongo el ultimo en la raiz
    this->size--;                               // reduzco el size
    this->heapify(0);                           // burbujea hacia abajo intercambiando con el menor de los hijos
    return state;
}

/*
 * Method: heapify
 * Description: metodo para burbuajear hacia abajo intercambiando con el menor de los hijos
 * Parameters:
 * - index: indice del estado
 * Returns:
 * - void
 */
void Heap::heapify(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left < this->size && (this->heap[left]->heuristica) < (this->heap[smallest]->heuristica))
    {
        smallest = left;
    }
    if (right < this->size && (this->heap[right]->heuristica) < (this->heap[smallest]->heuristica))
    {
        smallest = right;
    }
    if (smallest != index)
    {
        this->swap(index, smallest); // smallest va ser el hijo menor de ambos
        this->heapify(smallest);
    }
}

/*
 * Method: push
 * Description: metodo para insertar un estado en el heap
 * Parameters:
 * - state: estado a insertar
 * Returns:
 * - void
 */
void Heap::push(State *state)
{
    if (this->size == this->capacity)
    {
        State **temp = new State *[this->capacity * 2];
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->heap[i];
        }
        delete[] this->heap;
        this->heap = temp;
        this->capacity *= 2;
    }
    this->heap[this->size] = state; // lo pongo al final
    this->bubbleUp(this->size);     // burbujea hacia arriba intercambiando con el padre
    this->size++;                   // aumento el size
}

/*
 * Method: bubbleUp
 * Description: metodo para burbuajear hacia arriba intercambiando con el padre
 * Parameters:
 * - index: indice del estado
 * Returns:
 * - void
 */
void Heap::bubbleUp(int index)
{
    int parent = (index - 1) / 2;
    if (parent >= 0 && (this->heap[index]->heuristica) < (this->heap[parent]->heuristica))
    {
        this->swap(index, parent); // caso que no se cumple padre < hijo
        this->bubbleUp(parent);
    }
}

/*
 * Method: isEmpty
 * Description: metodo para verificar si el heap esta vacio
 * Parameters:
 * - void
 * Returns:
 * - bool
 */
bool Heap::isEmpty()
{
    return this->size == 0;
}

/*
 * Method: contains
 * Description: metodo para verificar si el heap contiene un estado
 * Parameters:
 * - state: estado a verificar
 * Returns:
 * - bool
 */
bool Heap::contains(State *state)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->heap[i]->toString() == state->toString())
        {
            return true;
        }
    }
    return false;
}