#include "Operacion.h"
#include "Car.h"

//Contructor de una operacion
Operacion::Operacion(int direccion, int paso) {
    this->direccion = direccion;
    this->paso = paso;
}

//Contructor de una operacion
Operacion::Operacion() {
    this->direccion = -1;
    this->paso = -1;
}

//Destructor de una operacion
Operacion::~Operacion() {
}


// Funcion para mostrar una operacion
void Operacion::printOperacion() {
    std::cout << "Direccion: " << this->direccion << " Paso: " << this->paso << std::endl;
}

// Funcion para operar un auto
Car* Operacion::operar(Car* auto_) {
    //printf("auto: %d\n", auto_->id);
    int sumaX,sumaY = 0;

    if(auto_->dir == HORIZONTAL){ // Si el auto es horizontal
        sumaX = this->paso; // Suma el paso a la posicion en x
        sumaY = 0;
    }else if(auto_->dir == VERTICAL){ // Si el auto es vertical
        sumaX = 0;
        sumaY = this->paso; // Suma el paso a la posicion en y
    } 

    Car *autoAux = new Car( // Crea un nuevo auto con la posicion actualizada
        auto_->id,
        auto_->columna + sumaX,
        auto_->fila + sumaY,
        auto_->largo,
        auto_->dir);

    return autoAux; // Retorna el auto actualizado

}