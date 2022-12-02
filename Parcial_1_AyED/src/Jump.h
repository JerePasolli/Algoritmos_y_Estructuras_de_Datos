//
// Created by jerem on 28/4/2022.
//

#ifndef PROYECTO_JUMP_H
#define PROYECTO_JUMP_H

#include "Instruccion.h"

class Jump : public Instruccion {
public:
    Jump(string l, int num) : Instruccion(l, num) {};
    int ejecutar(Lista<Variable*>*);// va a buscar el numero en la linea para retornarlo como int
};


#endif //PROYECTO_JUMP_H
