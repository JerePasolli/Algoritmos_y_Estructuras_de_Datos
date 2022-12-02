//
// Created by jerem on 27/4/2022.
//

#ifndef PROYECTO_DECLARACION_H
#define PROYECTO_DECLARACION_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Instruccion.h"
#include "Variable.h"

using namespace std;

class Declaracion : public Instruccion{
public:
    Declaracion(string l, int num) : Instruccion(l, num) {}; //Constructor, llama a clase
                                                            // padre para incializar atributos
    int ejecutar(Lista<Variable*>*); // ejecuta declaracion
};


#endif //PROYECTO_DECLARACION_H
