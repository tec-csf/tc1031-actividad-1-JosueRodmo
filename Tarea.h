#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

template <typename item>

class DataGroup {
    public:
    DataGroup (int);
    vector <item> data; //atributo
    vector <item> createVector(int); //nombre
    item random();
};

template <typename item>
DataGroup <item>:: DataGroup(int size){
    data.reserve(size);
    cout << "Creating Vector" << endl;
    for (int i = 0; i < size; i++){
        data.push_back(random());
        // this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "Vector Created" << endl;
}


template <>
int DataGroup <int> :: random(){
    return rand() % 100 +1;
}

template <typename item>
item DataGroup <item> :: random(){
    return rand();
}

