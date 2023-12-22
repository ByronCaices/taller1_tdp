#include <ctime>
#include "Board.h"
#include "State.h"
#include "Heap.h"
#include "functionUtils.h"

using namespace std;

int main()
{

    clock_t tStart, tEnd;                               // variables para medir el tiempo
    string Archivoautos, Archivoparedes;                // variables para los nombres de los archivos
    cout << "Ingrese el nombre del archivo de autos: "; // pedimos el nombre del archivo de autos
    cin >> Archivoautos;
    cout << "Ingrese el nombre del archivo de paredes: "; // pedimos el nombre del archivo de paredes
    cin >> Archivoparedes;

    Stack autos = readFile("./testfiles/" + Archivoautos); // leemos los autos

    State *estado = new State(&autos, nullptr, 0); // creamos el estado inicial
    Board tablero(6);                              // creamos el tablero

    tablero.setWalls(paredes("./testfiles/" + Archivoparedes)); // leemos las paredes

    tStart = clock();      // iniciamos el reloj
    tablero.astar(estado); // resolvemos el tablero
    tEnd = clock();        // detenemos el reloj

    double time_taken = double(tEnd - tStart) / double(CLOCKS_PER_SEC);   // calculamos el tiempo
    cout << "Tiempo de ejecucion: " << time_taken << " segundos" << endl; // imprimimos el tiempo
    return 0;
}
