#include "../src/Car.h"
#include "../src/Stack.h"

using namespace std;

int main(){

    //creamos el vector
    Stack *vector = new Stack(10);

    //creamos los autos
    Car *auto1 = new Car(1,2,2,0,0);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto1->id << 
    "\nPosX: " << auto1->columna << 
    "\nPosY: " << auto1->fila << 
    "\nLargo: " << auto1->largo << 
    "\nDireccion: " << auto1->dir << endl;

    Car *auto2 = new Car(2,0,0,2,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto2->id << 
    "\nPosX: " << auto2->columna << 
    "\nPosY: " << auto2->fila << 
    "\nLargo: " << auto2->largo << 
    "\nDireccion: " << auto2->dir << endl;
    
    Car *auto3 = new Car(3,1,1,2,0);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto3->id << 
    "\nPosX: " << auto3->columna << 
    "\nPosY: " << auto3->fila << 
    "\nLargo: " << auto3->largo << 
    "\nDireccion: " << auto3->dir << endl;
    
    Car *auto4 = new Car(4,4,1,2,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto4->id << 
    "\nPosX: " << auto4->columna << 
    "\nPosY: " << auto4->fila << 
    "\nLargo: " << auto4->largo << 
    "\nDireccion: " << auto4->dir << endl;

    Car *auto5 = new Car(5,5,1,2,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto5->id << 
    "\nPosX: " << auto5->columna << 
    "\nPosY: " << auto5->fila << 
    "\nLargo: " << auto5->largo << 
    "\nDireccion: " << auto5->dir << endl;
    
    Car *auto6 = new Car(6,1,2,3,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto6->id << 
    "\nPosX: " << auto6->columna << 
    "\nPosY: " << auto6->fila << 
    "\nLargo: " << auto6->largo << 
    "\nDireccion: " << auto6->dir << endl;
    
    Car *auto7 = new Car(7,2,3,2,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto7->id << 
    "\nPosX: " << auto7->columna << 
    "\nPosY: " << auto7->fila << 
    "\nLargo: " << auto7->largo << 
    "\nDireccion: " << auto7->dir << endl;
    
    Car *auto8 = new Car(8,3,3,2,0);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto8->id << 
    "\nPosX: " << auto8->columna << 
    "\nPosY: " << auto8->fila << 
    "\nLargo: " << auto8->largo << 
    "\nDireccion: " << auto8->dir << endl;
    
    Car *auto9 = new Car(9,5,3,3,1);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto9->id << 
    "\nPosX: " << auto9->columna << 
    "\nPosY: " << auto9->fila << 
    "\nLargo: " << auto9->largo << 
    "\nDireccion: " << auto9->dir << endl;
    
    Car *auto10 = new Car(10,1,5,2,0);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto10->id << 
    "\nPosX: " << auto10->columna << 
    "\nPosY: " << auto10->fila << 
    "\nLargo: " << auto10->largo << 
    "\nDireccion: " << auto10->dir << endl;
    
    Car *auto11 = new Car(11,3,5,2,0);
    cout << "\nAuto creado:" << 
    "AutoId: " << auto11->id << 
    "\nPosX: " << auto11->columna << 
    "\nPosY: " << auto11->fila << 
    "\nLargo: " << auto11->largo << 
    "\nDireccion: " << auto11->dir << endl;

    cout << "" << endl;

    //agregamos los autos al vector
    cout << "Agregando autos al vector..." << endl;
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
    cout << "Imprimiendo vector..." << endl;
    vector->printStack();

}