#include "../src/State.h"
#include "../src/Car.h"
#include "../src/Stack.h"

int main(){

    //creamos los autos
    Car *auto1 = new Car(1,2,2,0,0);
    Car *auto2 = new Car(2,0,0,2,1);
    Car *auto3 = new Car(3,1,1,2,0);
    Car *auto4 = new Car(4,4,1,2,1);
    Car *auto5 = new Car(5,5,1,2,1);
    
    //creamos el vector

    Stack *vector = new Stack(10);

    //agregamos los autos al vector

    vector->push(auto1);
    vector->push(auto2);
    vector->push(auto3);
    vector->push(auto4);
    vector->push(auto5);

    //creamos el estado

    State *estado = new State(vector,nullptr,nullptr,nullptr); // creamos un estado con el vector de autos creado anteriormente
    estado->heuristica = 5; // le asignamos una heuristica

    estado->printState(); // imprimimos el estado
    std::cout << "Heuristica: " << estado->heuristica << std::endl; // imprimimos la heuristica

    

}