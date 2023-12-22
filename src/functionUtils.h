#ifndef FUNCTIONUTILS_H
#define FUNCTIONUTILS_H

#include <fstream> // para trabajar con archivos
#include <string>  // para tener objetos de arreglos de char de largo autoincrementable
#include <sstream> // para trabajar con streams de strings
#include "Stack.h"

using namespace std;

Stack readFile(string carsFile)
{
    int x, y, largo, dir;
    int **data = new int *[18]; // 18 es el maximo de autos. 3 por fila (de largo 2) x 6 filas
    ifstream file(carsFile);    // es un stream de "FileInput" desde un archivo.
    string line;                // es un objeto que representa un arreglo de char que es auto ajustable.
    int count = 0;              // cuenta la cantidad de autos (uno por linea)
    Stack open(18);             // 18 es el maximo de autos. 3 por fila (de largo 2) x 6 filas
    int FirsId = 1;             // id del auto actual
    while (getline(file, line))
    { // lee una linea del archivo y la guarda en "line". Si no hay mas lineas, sale del while(retorna false).
        count++;
        stringstream charStream;                      // es un stream de "StringInput" desde un string.
        charStream << line;                           // guarda el string en el stream
        charStream >> y >> x >> largo >> dir;         // lee los datos del stream y los guarda en las variables. Notar que como es un input stream se usa la operacion inversa a <<, que es >>. Automaticamente lee el tipo de dato de cada variable.
                                                      // cout << "x: "<< x << " y: " << y << " largo: " << largo << " dir: " << dir << endl; // imprimimos de vuelta todo. Aqui deben crear sus objetos de auto, y guardarlos en en State.
        open.push(new Car(FirsId, x, y, largo, dir)); // guardamos el auto en el Vector
        FirsId++;                                     // aumentamos el id
    }
    file.close(); // cerramos el archivo
    cout << "Cantidad de autos: " << count << endl
         << endl; // imprimimos la cantidad de autos
    return open;
}

int **paredes(string wallsFile)
{ // funcion para leer las paredes
    // ahora leemos las paredes
    ifstream file(wallsFile); // Abrimos el archivo
    if (!file.is_open())
    {
        cout << "No se pudo abrir el archivo de paredes." << endl;
        return nullptr;
    }
    int **walls = new int *[6]; // Asignación dinámica para la matriz 6x6
    for (int i = 0; i < 6; i++)
    {
        walls[i] = new int[6];
        for (int j = 0; j < 6; j++)
        {
            walls[i][j] = 0; // inicializamos todo en 0
        }
    }
    string line;
    int x, y;
    while (getline(file, line))
    {
        stringstream charStream(line);
        charStream >> y >> x; // leemos las coordenadas de la pared de manera inversa para representarla correctamente en la matriz
        walls[y][x] = 1;      // guardamos la pared en la matriz
    }
    file.close();
    return walls; // retornamos la matriz
}

#endif