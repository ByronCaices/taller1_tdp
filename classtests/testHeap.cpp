#include "../src/Heap.h"

int main()
{
    Stack *autos = new Stack(10);

    //Creamos autos cualquieras
    autos->push(new Car(1, 4, 2, 2, HORIZONTAL));
    autos->push(new Car(2, 0, 0, 2, VERTICAL));
    autos->push(new Car(3, 0, 3, 2, VERTICAL));
    autos->push(new Car(4, 1, 0, 2, HORIZONTAL));
    autos->push(new Car(5, 1, 3, 2, HORIZONTAL));
    autos->push(new Car(6, 3, 0, 2, VERTICAL));
    autos->push(new Car(7, 3, 3, 2, VERTICAL));
    autos->push(new Car(8, 4, 0, 2, HORIZONTAL));
    autos->push(new Car(9, 4, 3, 2, HORIZONTAL));

    //Creamos el estado inicial

    State *inicial = new State(autos, nullptr, 0);
    inicial->printState();
    inicial->heuristica = 4; //ingresamos cualquier valor a su heuristica

    //Creamos el estado 1
    State *estado1 = new State(autos, nullptr, 0);
    estado1->printState();
    estado1->heuristica = 8;

    //Creamos el estado 2
    State *estado2 = new State(autos, nullptr, 0);
    estado2->printState();
    estado2->heuristica = 5;

    //Creamos el estado 3
    State *estado3 = new State(autos, nullptr, 0);
    estado3->printState();
    estado3->heuristica = 32;

    //Creamos el estado 4
    State *estado4 = new State(autos, nullptr, 0);
    estado4->printState();
    estado4->heuristica = 3;

    //Creamos la cola de prioridad
    Heap colaPrioridad(10);

    //Agregamos los estados a la cola de prioridad

    colaPrioridad.push(inicial);
    colaPrioridad.push(estado1);
    colaPrioridad.push(estado2);
    colaPrioridad.push(estado3);
    colaPrioridad.push(estado4);

    //Mostramos la cola de prioridad
    //voy obteniendo los estados de la cola de prioridad y los muestro del mejor al peor estado dado su heuristica, es decir, el estado con menor heuristica es el mejor estado.
    cout << "Cola de prioridad" << endl;
    while (!colaPrioridad.isEmpty())
    {
        State *estado = colaPrioridad.pop();
        cout << estado->heuristica << endl;
    }
    

    return 0;
}