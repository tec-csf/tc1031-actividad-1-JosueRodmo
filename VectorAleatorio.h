#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class vectorAleatorio {
    public:
    vectorAleatorio (int);
    vector <T> numeros;
    T random();
};

template <typename T>
vectorAleatorio <T>:: vectorAleatorio(int size){
    for (int i = 0; i < size; i++){
        numeros.push_back(random());
    }
    cout << "Vector Terminado" << endl;
}


template <>
int vectorAleatorio <int> :: random(){
    return rand() % 1000;
}

template <typename T>
T vectorAleatorio <T> :: random(){
    return rand();
}

