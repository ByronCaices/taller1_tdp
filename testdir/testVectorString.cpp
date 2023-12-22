#include <iostream>
#include <string>
#include "../src/Estado.h"
#include "../src/Stack.h"
#include "../src/MyString.h"

int main(){

    //Creamos el vector de strings

    MyString *vector = new MyString(10);

    //Creamos un vector de autos

    Stack *autos = new Stack(10);

    //Creamos autos para ingresar al vector

    Auto *auto1 = new Auto(1, 2, 2, 2, HORIZONTAL);
    Auto *auto2 = new Auto(2, 2, 3, 2, HORIZONTAL);

    //los ingresamos al vector

    autos->push(auto1);
    autos->push(auto2);

    //Creamos algunos estados para agregar al vector

    Estado *estado1 = new Estado(autos, nullptr, nullptr, nullptr);

    Estado *estado2 = new Estado(autos, nullptr, nullptr, nullptr);

    Estado *estado3 = new Estado(autos, nullptr, nullptr, nullptr);

    //Los agregamos al vector

    vector->push(estado1->toString());
    vector->push(estado2->toString());
    vector->push(estado3->toString());

    //Mostramos el vector

    vector->printVector();

    //el vector mostrará los estados pero como todos tienen los mismos autos, mostrará lo mismo.



}