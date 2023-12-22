#include "../src/Car.h"

int main(){

    //creamos el auto rojo
    std::cout << "Creando auto rojo..." << std::endl;
    Car *Auto1 = new Car(1,0,2,2,0);

    //imprimimos el auto creado

    std::cout << "Auto Rojo "
    << "Id: " << Auto1->id << 
    " ,PosX: " << Auto1->columna <<
    " ,PosY: " << Auto1->fila << 
    " ,Largo: " << Auto1->largo << 
    " ,Direccion: " << Auto1->dir << std::endl;

    //creamos otro auto cualquiera

    std::cout << "Creando auto cualquiera..." << std::endl;
    Car *Auto2 = new Car(2,2,2,2,1);

    //imprimimos el auto creado

    std::cout << "Auto cualquiera "
    << "Id: " << Auto2->id <<
    " ,PosX: " << Auto2->columna <<
    " ,PosY: " << Auto2->fila <<
    " ,Largo: " << Auto2->largo <<
    " ,Direccion: " << Auto2->dir << std::endl;


}