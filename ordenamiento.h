#include <vector>
#include <iostream>
using namespace std;

template <class C>
class Busqueda {
    public:
    vector <C> elementos;
    Busqueda(vector <C>);

    int SS(C);
    int SFS(C);
    int STS(C);
    int SSS(C);
    int BS(C);
};

template <class C>
Busqueda<C>::Busqueda(vector <C> elementos)
{
    this -> elementos = elementos;
}


template <class C>
int Busqueda <C> ::SS(C valor){

    for (int i = 0; i <= elementos.size(); i++){
        if (elementos[i] == valor){
            return i;
        }

    }
    return -1;
}

template <class C>
int Busqueda <C> ::SFS(C valor){

    for (int i = 0; i <= elementos.size(); i++){
        if (elementos[i] == valor){
            swap(elementos[i], elementos[0]);
            return i;
        }

    }
    return -1;
}

template <class C>
int Busqueda <C> ::STS(C valor){

    for (int i = 0; i <= elementos.size(); i++){
        if (elementos[i] == valor){
            if(i == 0){
                return i;
            }
            swap(elementos[i], elementos[i-1]);
            return i;
        }

    }
    return -1;
}

template <class C>
int Busqueda <C> ::SSS(C valor){

    for (int i = 0 ; i <= elementos.size()-2 ; i++)
        for (int j = i+1 ; j <= elementos.size()-1 ; j++){
            if (elementos[i] > elementos[j]){ 
                swap(elementos[i], elementos[j]);
            } 
            if (elementos[i] == valor){
                return i;
            }
        }
    return -1;
}

template <class C>
int Busqueda <C> ::BS(C valor){
    int central, bajo, alto, valorCentral;
    bajo = 0;
    alto = elementos.size()-1;
    while (bajo <= alto) {
        central = (bajo + alto)/2;
        valorCentral =  elementos[central];
        if (valor == valorCentral)
            return central;
        else if (valor < valorCentral)
            alto = central -1;
        else
            bajo = central + 1;
    }
    return -1;
}