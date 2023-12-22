#include "../src/Car.h"
#include "../src/Stack.h"

int main(){

    //creamos el vector
    Stack *vector = new Stack(10);

    //creamos los autos
    Car *auto1 = new Car(1,2,2,0,0);
    std::cout << "Auto creado:" << "AutoId: " << auto1->id << " ,PosX: " << auto1->posX << " ,PosY: " << auto1->posY << " ,Largo: " << auto1->Largo << " ,Direccion: " << auto1->Direccion << std::endl;
    Car *auto2 = new Car(2,0,0,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto2->id << " ,PosX: " << auto2->posX << " ,PosY: " << auto2->posY << " ,Largo: " << auto2->Largo << " ,Direccion: " << auto2->Direccion << std::endl;
    Car *auto3 = new Car(3,1,1,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto3->id << " ,PosX: " << auto3->posX << " ,PosY: " << auto3->posY << " ,Largo: " << auto3->Largo << " ,Direccion: " << auto3->Direccion << std::endl;
    Car *auto4 = new Car(4,4,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto4->id << " ,PosX: " << auto4->posX << " ,PosY: " << auto4->posY << " ,Largo: " << auto4->Largo << " ,Direccion: " << auto4->Direccion << std::endl;
    Car *auto5 = new Car(5,5,1,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto5->id << " ,PosX: " << auto5->posX << " ,PosY: " << auto5->posY << " ,Largo: " << auto5->Largo << " ,Direccion: " << auto5->Direccion << std::endl;
    Car *auto6 = new Car(6,1,2,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto6->id << " ,PosX: " << auto6->posX << " ,PosY: " << auto6->posY << " ,Largo: " << auto6->Largo << " ,Direccion: " << auto6->Direccion << std::endl;
    Car *auto7 = new Car(7,2,3,2,1);
    std::cout << "Auto creado:" << "AutoId: " << auto7->id << " ,PosX: " << auto7->posX << " ,PosY: " << auto7->posY << " ,Largo: " << auto7->Largo << " ,Direccion: " << auto7->Direccion << std::endl;
    Car *auto8 = new Car(8,3,3,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto8->id << " ,PosX: " << auto8->posX << " ,PosY: " << auto8->posY << " ,Largo: " << auto8->Largo << " ,Direccion: " << auto8->Direccion << std::endl;
    Car *auto9 = new Car(9,5,3,3,1);
    std::cout << "Auto creado:" << "AutoId: " << auto9->id << " ,PosX: " << auto9->posX << " ,PosY: " << auto9->posY << " ,Largo: " << auto9->Largo << " ,Direccion: " << auto9->Direccion << std::endl;
    Car *auto10 = new Car(10,1,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto10->id << " ,PosX: " << auto10->posX << " ,PosY: " << auto10->posY << " ,Largo: " << auto10->Largo << " ,Direccion: " << auto10->Direccion << std::endl;
    Car *auto11 = new Car(11,3,5,2,0);
    std::cout << "Auto creado:" << "AutoId: " << auto11->id << " ,PosX: " << auto11->posX << " ,PosY: " << auto11->posY << " ,Largo: " << auto11->Largo << " ,Direccion: " << auto11->Direccion << std::endl;

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
    vector->printVector();

   

}