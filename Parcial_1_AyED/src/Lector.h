//
// Created by jerem on 27/4/2022.
//

#ifndef PROYECTO_LECTOR_H
#define PROYECTO_LECTOR_H


#include "Instruccion.h"
#include "Lista.h"

class Lector{
public:
    Lista<Instruccion>* lectura(); // lee el txt, luego crea  y retorna una lista de instrucciones
private:
    ifstream programa; // se utiliza para abrir y leer el txt
    string instrucciones; // las lineas que lee programa se copian a este string
};


#endif //PROYECTO_LECTOR_H
