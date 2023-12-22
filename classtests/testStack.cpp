#include "../src/Car.h"
#include "../src/Stack.h"

int main(){

    //creamos el vector
    Stack *vector = new Stack(10);

    //creamos los autos
    Car *auto1 = new Car(1,2,2,0,0);
    std::cout << "Auto creado:" << "AutoId: " << auto1->id << " ,PosX: " << auto1->columna << " ,PosY: " << auto1->fila << " ,Largo: " << auto1->largo << " ,Direccion: " << auto1->dir << std::endl;
    Car *auto2 = new Car(2,0,0,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto2->id << " ,PosX: " << auto2->columna << " ,PosY: " << auto2->fila << " ,Largo: " << auto2->largo << " ,Direccion: " << auto2->dir << std::endl;
    Car *auto3 = new Car(3,1,1,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto3->id << " ,PosX: " << auto3->columna << " ,PosY: " << auto3->fila << " ,Largo: " << auto3->largo << " ,Direccion: " << auto3->dir << std::endl;
    Car *auto4 = new Car(4,4,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto4->id << " ,PosX: " << auto4->columna << " ,PosY: " << auto4->fila << " ,Largo: " << auto4->largo << " ,Direccion: " << auto4->dir << std::endl;
    Car *auto5 = new Car(5,5,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto5->id << " ,PosX: " << auto5->columna << " ,PosY: " << auto5->fila << " ,Largo: " << auto5->largo << " ,Direccion: " << auto5->dir << std::endl;
    Car *auto6 = new Car(6,1,2,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto6->id << " ,PosX: " << auto6->columna << " ,PosY: " << auto6->fila << " ,Largo: " << auto6->largo << " ,Direccion: " << auto6->dir << std::endl;
    Car *auto7 = new Car(7,2,3,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto7->id << " ,PosX: " << auto7->columna << " ,PosY: " << auto7->fila << " ,Largo: " << auto7->largo << " ,Direccion: " << auto7->dir << std::endl;
    Car *auto8 = new Car(8,3,3,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto8->id << " ,PosX: " << auto8->columna << " ,PosY: " << auto8->fila << " ,Largo: " << auto8->largo << " ,Direccion: " << auto8->dir << std::endl;
    Car *auto9 = new Car(9,5,3,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto9->id << " ,PosX: " << auto9->columna << " ,PosY: " << auto9->fila << " ,Largo: " << auto9->largo << " ,Direccion: " << auto9->dir << std::endl;
    Car *auto10 = new Car(10,1,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto10->id << " ,PosX: " << auto10->columna << " ,PosY: " << auto10->fila << " ,Largo: " << auto10->largo << " ,Direccion: " << auto10->dir << std::endl;
    Car *auto11 = new Car(11,3,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto11->id << " ,PosX: " << auto11->columna << " ,PosY: " << auto11->fila << " ,Largo: " << auto11->largo << " ,Direccion: " << auto11->dir << std::endl;

    std::cout << "" << std::endl;

    //agregamos los autos al vector
    std::cout << "Agregando autos al vector..." << std::endl;
    vector->push(auto1);
    vector->push(auto2);
    vector->push(auto3);
    vector->push(auto4);
    vector->push(auto5);
    vector->push(auto6);
    vector->push(auto7);
    vector->push(auto8);
    vector->push(auto9);
    vector->push(auto10);
    vector->push(auto11);

    //imprimimos el vector
    std::cout << "Imprimiendo vector..." << std::endl;
    vector->printStack();

   

}