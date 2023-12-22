#include <iostream>
#include <string>
#include "MyString.h"

// Constructor de un vector
MyString::MyString(int capacidad) {
    this->capacidad = capacidad;
    this->tope = -1;
    this->vector = new std::string[capacidad];
}

// Destructor de un vector
MyString::~MyString() {
    delete[] this->vector;
}

// Función para agregar un string al vector
void MyString::push(const std::string& str){
    if(this->tope == this->capacidad - 1){
        std::string* aux = new std::string[this->capacidad * 2];
        for (int i = 0; i < this->capacidad; i++) {
            aux[i] = this->vector[i];
        }
        delete[] this->vector;
        this->vector = aux;
        this->capacidad *= 2;
    }
    this->tope++;
    this->vector[this->tope] = str;
}

// Función para saber si el vector está vacío
bool MyString::isEmpty(){
    return this->tope == -1;
}

// Función para mostrar el vector
void MyString::printVector(){
    for(int i = 0; i <= this->tope; i++){
        std::cout << this->vector[i] << " ";
    }
    std::cout << std::endl;
}

// Función para saber si una cadena está en el vector
bool MyString::contains(const std::string& str){
    for(int i = 0; i <= this->tope; i++){
        if(this->vector[i] == str){
            return true;
        }
    }
    return false;
}

// Función para obtener un string en una posición específica
std::string MyString::get(int index){
    if(index >= 0 && index <= this->tope){
        return this->vector[index];
    } else {
        std::cerr << "Index out of bounds." << std::endl;
        return "";
    }
}
