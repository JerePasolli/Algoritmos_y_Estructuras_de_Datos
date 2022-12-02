//
// Created by jerem on 28/4/2022.
//

#ifndef PROYECTO_ASIGNACION_H
#define PROYECTO_ASIGNACION_H

#include "Variable.h"
#include "Instruccion.h"

class Asignacion : public Instruccion{
public:
    Asignacion(string l, int num) : Instruccion(l, num) {};//Constructor, llama a clase
                                                           // padre para incializar atributos
    int ejecutar(Lista<Variable*>*); //asigna un numero, o una expresion, ya sea aritmetica
                                     //o booleana a una variable en la memoria
    void setResultado(int,string,Lista<Variable*>*);//se encargara se setear el resultado en
                                                    //la variable correcta de la memoria
};


#endif //PROYECTO_ASIGNACION_H
