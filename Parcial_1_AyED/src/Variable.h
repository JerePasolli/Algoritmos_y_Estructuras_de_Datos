//
// Created by jerem on 28/4/2022.
//

#ifndef PROYECTO_VARIABLE_H
#define PROYECTO_VARIABLE_H

#include <iostream>
#include <string>
#include <utility>
#include <string>

using namespace std;

class Variable {
private:
    string tipovar; // puede ser "int" o "bool"
    string nombrevar; // es una letra de la a "a" la "z"
    int valor; // un int cualquiera
public:
    Variable (string tipo="",string nombre="", int val = 0){tipovar = tipo; nombrevar = nombre; valor = val;};
                                               //Constructor, inicializa los atributos
    string getNombrevar(){return nombrevar;}; //getters y setters
    int getValor(){ return valor;};
    string getTipovar(){return tipovar;};
    void setValor(int v){ valor = v;};
};


#endif //PROYECTO_VARIABLE_H
