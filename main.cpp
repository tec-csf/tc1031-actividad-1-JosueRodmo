#include "ordenamiento.h"
#include "tarea.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;



void Pruebas(vector<int> desordenados, int buscando){
    Ordenamiento <int> sorter (desordenados);
    cout << "Empieza tiempo de: Búsqueda secuencial" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    sorter.SS(buscando);
    auto finish = chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    std::cout << microseconds.count() << "µs\n";


    cout << "Empieza tiempo de: Búsqueda secuencial con movimiento en frente" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.SFS(buscando);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda secuencial con transposición" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.STS(buscando);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda secuencial con ordenamiento" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.SSS(buscando);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "Empieza tiempo de: Búsqueda binaria" << endl;
    start = std::chrono::high_resolution_clock::now();
    sorter.BS(buscando);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    cout << microseconds.count() << "µs\n";

    cout << "------------------------------"<< endl;
}

int main()
{
    srand(time(nullptr));
    int val[] = {14, 20, 36, 47, 68};

    DataGroup <int> datos(100000);
    for (int x : val){
        for (int i = 0; i < 10; i++)
        {
            cout << "Numero--------------:" << x <<"," << i +1<< endl;
            Pruebas(datos.data, x);
        }
    }  
    return 0;
}