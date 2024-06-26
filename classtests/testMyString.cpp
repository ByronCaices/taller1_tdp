#include <iostream>
#include <string>
#include "../src/State.h"
#include "../src/Stack.h"
#include "../src/MyString.h"

int main()
{

    // Creamos el vector de strings

    MyString *vector = new MyString(10);

    // Creamos un vector de autos

    Stack *autos = new Stack(10);

    // Creamos autos para ingresar al vector

    Car *auto1 = new Car(1, 2, 2, 2, HORIZONTAL);
    Car *auto2 = new Car(2, 2, 3, 2, HORIZONTAL);

    // los ingresamos al vector

    autos->push(auto1);
    autos->push(auto2);

    // Creamos algunos estados para agregar al vector

    State *estado1 = new State(autos, nullptr, nullptr, nullptr);

    State *estado2 = new State(autos, nullptr, nullptr, nullptr);

    State *estado3 = new State(autos, nullptr, nullptr, nullptr);

    // Los agregamos al vector

    vector->push(estado1->toString());
    vector->push(estado2->toString());
    vector->push(estado3->toString());

    // Mostramos el vector

    vector->printMyString();

    // el vector mostrará los estados pero como todos tienen los mismos autos, mostrará lo mismo.
}