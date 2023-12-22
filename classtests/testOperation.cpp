#include "../src/Car.h"
#include "../src/Operation.h"
#include <iostream>

int main(){
    //creamos el auto rojo
    Car *Auto1 = new Car(1,0,2,2,0);

    //imprimimos el auto rojo antes de la operacion

    std::cout << "\nAuto Rojo antes de la operacion:  "
    << "Id: " << Auto1->id << 
    "\nPosX: " << Auto1->columna <<
    "\nPosY: " << Auto1->fila << 
    "\nLargo: " << Auto1->largo << 
    "\nDireccion: " << Auto1->dir << std::endl;
 
    //creamos la operacion de mover el auto rojo hacia la derecha (sumarle 1)
    Operation *op = new Operation(0,1);

    //Realizamos la operacion
    Car *AutoRojoMovido = op->operate(Auto1);

    //imprimimos el auto rojo despues de la operacion
    std::cout << "\nAuto Rojo despues de la operacion: "
    << "\nId: " << AutoRojoMovido->id <<
    "\nPosX: " << AutoRojoMovido->columna <<
    "\nPosY: " << AutoRojoMovido->fila <<
    "\nLargo: " << AutoRojoMovido->largo <<
    "\nDireccion: " << AutoRojoMovido->dir << std::endl;


    //creamos un auto cualquiera en vertical
    Car *Auto2 = new Car(2,2,2,2,1);

    //imprimimos el auto cualquiera antes de la operacion
    std::cout << "\nAuto cualquiera antes de la operacion:  "
    << "Id: " << Auto2->id <<
    "\nPosX: " << Auto2->columna <<
    "\nPosY: " << Auto2->fila <<
    "\nLargo: " << Auto2->largo <<
    "\nDireccion: " << Auto2->dir << std::endl;

    //creamos la operacion de mover el auto cualquiera hacia arriba(restarle 1)
    Operation *op2 = new Operation(0,-1);

    //Realizamos la operacion
    Car *AutoCualquieraMovido = op2->operate(Auto2);

    //imprimimos el auto cualquiera despues de la operacion
    std::cout << "\nAuto cualquiera despues de la operacion:  "
    << "Id: " << AutoCualquieraMovido->id <<
    "\nPosX: " << AutoCualquieraMovido->columna <<
    "\nPosY: " << AutoCualquieraMovido->fila <<
    "\nLargo: " << AutoCualquieraMovido->largo <<
    "\nDireccion: " << AutoCualquieraMovido->dir << std::endl;


    return 0;


}