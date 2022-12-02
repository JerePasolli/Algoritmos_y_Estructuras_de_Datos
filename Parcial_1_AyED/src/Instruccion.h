//
// Created by jerem on 27/4/2022.
//

#ifndef PROYECTO_INSTRUCCION_H
#define PROYECTO_INSTRUCCION_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Variable.h"
#include "Lista.h"

using namespace std;

class Instruccion {
public:
    Instruccion(string ="" , int=0); //construye instruccion con la linea de texto y el numero de
                                     // instruccion correspondiente
    virtual int ejecutar(Lista<Variable*>*); // deriva a cada tipo de instruccion segun sea el caso,
                                             // y retorna la siguiente instruccion a ejecutar
    int getNuminst(){return numinst;}; //retorna el numero de instruccion
    bool isJump(); //verifica si la linea es un JUMP
    bool isDeclaracion(); //verifica si la linea es una Declaracion
    bool isShow(); //verifica si la linea es un SHOW
    bool isCondicional(); //verifica si la linea es un Condicional
    bool isAsignacion(); //verifica si la linea es una Asignacion
    bool isBooleana(string); //Verifica si un string dado corresponde a una expresion booleana
protected:
    int numinst;
    string linea;
};


#endif //PROYECTO_INSTRUCCION_H
