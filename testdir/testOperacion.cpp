#include "../src/Car.h"
#include "../src/Operation.h"
#include <iostream>

int main(){
    //creamos el auto rojo
    Car *Auto1 = new Car(1,0,2,2,0);

    //imprimimos el auto rojo antes de la operacion

    std::cout << "Auto Rojo antes de la operacion:  "
    << "Id: " << Auto1->id << 
    " ,PosX: " << Auto1->columna <<
    " ,PosY: " << Auto1->fila << 
    " ,Largo: " << Auto1->largo << 
    " ,Direccion: " << Auto1->dir << std::endl;
 
    //creamos la operacion de mover el auto rojo hacia la derecha (sumarle 1)
    Operation *op = new Operation(0,1);

    //Realizamos la operacion
    Car *AutoRojoMovido = op->operar(Auto1);

    //imprimimos el auto rojo despues de la operacion
    std::cout << "Auto Rojo despues de la operacion: "
    << "Id: " << AutoRojoMovido->id <<
    " ,PosX: " << AutoRojoMovido->columna <<
    " ,PosY: " << AutoRojoMovido->fila <<
    " ,Largo: " << AutoRojoMovido->largo <<
    " ,Direccion: " << AutoRojoMovido->dir << std::endl;


    //creamos un auto cualquiera en vertical
    Car *Auto2 = new Car(2,2,2,2,1);

    //imprimimos el auto cualquiera antes de la operacion
    std::cout << "Auto cualquiera antes de la operacion:  "
    << "Id: " << Auto2->id <<
    " ,PosX: " << Auto2->columna <<
    " ,PosY: " << Auto2->fila <<
    " ,Largo: " << Auto2->largo <<
    " ,Direccion: " << Auto2->dir << std::endl;

    //creamos la operacion de mover el auto cualquiera hacia arriba(restarle 1)
    Operation *op2 = new Operation(0,-1);

    //Realizamos la operacion
    Car *AutoCualquieraMovido = op2->operar(Auto2);

    //imprimimos el auto cualquiera despues de la operacion
    std::cout << "Auto cualquiera despues de la operacion:  "
    << "Id: " << AutoCualquieraMovido->id <<
    " ,PosX: " << AutoCualquieraMovido->columna <<
    " ,PosY: " << AutoCualquieraMovido->fila <<
    " ,Largo: " << AutoCualquieraMovido->largo <<
    " ,Direccion: " << AutoCualquieraMovido->dir << std::endl;


    return 0;


}