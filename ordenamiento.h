#include <vector>
#include <iostream>
using namespace std;

template <class kind>
class Ordenamiento {
    public:
    vector <kind> elements;
    Ordenamiento(vector <kind>);

    int SS(kind);
    int SFS(kind);
    int STS(kind);
    int SSS(kind);
    int BS(kind);
};
template <class kind>
Ordenamiento<kind>::Ordenamiento(vector <kind> elements)
{
    this -> elements = elements;
}


template <class kind>
int Ordenamiento <kind> ::SS(kind valor){

    for (int i = 0; i <= elements.size(); i++){
        if (elements[i] == valor){
            return i;
        }

    }
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::SFS(kind valor){

    for (int i = 0; i <= elements.size(); i++){
        if (elements[i] == valor){
            swap(elements[i], elements[0]);
            return i;
        }

    }
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::STS(kind valor){

    for (int i = 0; i <= elements.size(); i++){
        if (elements[i] == valor){
            if(i == 0){
                return i;
            }
            swap(elements[i], elements[i-1]);
            return i;
        }

    }
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::SSS(kind valor){

    for (int i = 0 ; i <= elements.size()-2 ; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
        for (int j = i+1 ; j <= elements.size()-1 ; j++){
            if (elements[i] > elements[j]){ 
                swap(elements[i], elements[j]);
            } 
            if (elements[i] == valor){
                return i;
            }
        }
    return -1;
}

template <class kind>
int Ordenamiento <kind> ::BS(kind valor){
    int central, bajo, alto, valorCentral;
    bajo = 0;
    alto = elements.size()-1;
    while (bajo <= alto) {
        central = (bajo + alto)/2;
        valorCentral =  elements[central];
        if (valor == valorCentral)
            return central;
        else if (valor < valorCentral)
            alto = central -1;
        else
            bajo = central + 1;
    }
    return -1;
}