#include "../src/Car.h"

int main(){

    Car *Auto1 = new Car(1,0,2,2,0);
    //imprimimos el auto creado
    std::cout << "Auto Rojo "
    << "\nId: \t" << Auto1->id << 
    "\nCol: \t" << Auto1->columna <<
    "\nFila: \t" << Auto1->fila << 
    "\nLargo: \t" << Auto1->largo << 
    "\nDir: \t" << Auto1->dir << std::endl;
}