#include "Ordenamiento.h"
#include "VectorAleatorio.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdio.h>

using namespace std;

void Pruebas(vector<int> numeros, int valor){
    Busqueda <int> buscador(numeros);
    auto start = std::chrono::high_resolution_clock::now();
    buscador.SS(valor);
    auto finish = chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    printf("%.80s %i ms \n", "Tiempo de: Búsqueda Secuencial: ", microseconds.count());

    start = std::chrono::high_resolution_clock::now();
    buscador.SFS(valor);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    printf("%.80s %i ms \n", "Tiempo de: Búsqueda secuencial con movimiento en frente: ", microseconds.count());

    start = std::chrono::high_resolution_clock::now();
    buscador.STS(valor);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    printf("%.80s %i ms \n", "Tiempo de: Búsqueda secuencial con transposición: ", microseconds.count());

    start = std::chrono::high_resolution_clock::now();
    buscador.SSS(valor);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    printf("%.80s %i ms \n", "Tiempo de: Búsqueda secuencial con Busqueda: ", microseconds.count());

    start = std::chrono::high_resolution_clock::now();
    buscador.BS(valor);
    finish = chrono::high_resolution_clock::now();
    microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    printf("%.80s %i ms \n", "Tiempo de: Búsqueda binario: ", microseconds.count());
    cout << endl;
}

int main()
{
    srand(time(nullptr));
    int val[] = {14, 20, 36, 47, 68};

    vectorAleatorio <int> numeros(100000);
    for (int j = 0; j < 5; j++){
        for (int i = 0; i < 10; i++)
        {
            cout << "Número: " << val[j] <<", Prueba: " << i + 1 << endl;
            Pruebas(numeros.numeros, val[j]);
        }
    }  
    return 0;
}