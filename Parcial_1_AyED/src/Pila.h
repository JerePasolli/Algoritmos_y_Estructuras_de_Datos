//
// Created by jerem on 27/4/2022.
//

#ifndef PROYECTO_PILACARACTERES_H
#define PROYECTO_PILACARACTERES_H

#include "Lista.h"

using namespace std;


template <class T> class Pila: public Lista<T>{
public:
    Pila(){Lista<T>();};
    void apilar(T d){this->add(d);};
    T tope(void){return this->cabeza();};
    void desapilar(void){this->borrar();};
};



#endif //PROYECTO_PILACARACTERES_H
