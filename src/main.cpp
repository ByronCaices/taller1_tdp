#include <ctime>
#include "Board.h"
#include "State.h"
#include "Heap.h"
#include "functionUtils.h"

using namespace std;

int main()
{
    string opt = "y";

    while (opt == "y" || opt == "Y")
    {
        system("clear");
        
        clock_t timeStart, timeEnd; // variables para medir el tiempo
        string carFile, wallFile;   // variables para los nombres de los archivos

        cout << "\n##### RUSH HOUR SOLVER #####" << endl;
        cout << "\nAntes de ingresar nombres de los archivos, asegurese de que esten en la carpeta testfiles\n"
             << endl;

        cout << "\t1. Ingrese el nombre del archivo de autos: "; 
        cin >> carFile;
        cout << "\t2. Ingrese el nombre del archivo de paredes: "; 
        cin >> wallFile;

        Stack autos = readFile("./testfiles/" + carFile); 

        State *estado = new State(&autos, nullptr, 0); // creamos el estado inicial
        Board board(6);                                // creamos el tablero

        board.setWalls(paredes("./testfiles/" + wallFile)); // leemos las paredes

        timeStart = clock(); // iniciamos el reloj
        board.astar(estado); // resolvemos el tablero
        timeEnd = clock();   // detenemos el reloj

        double time_taken = double(timeEnd - timeStart) / double(CLOCKS_PER_SEC); // calculamos el tiempo
        cout << "Tiempo de ejecucion: " << time_taken << " segundos" << endl;     // imprimimos el tiempo

        cout << "\nProbar con otro programa? y/n: "; // pedimos el nombre del archivo de autos
        cin >> opt;
    }
    cout << "\n##### FIN DEL PROGRAMA #####\n"
         << endl;
    return 0;
}
