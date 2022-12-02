//
// Created by jerem on 28/4/2022.
//

#ifndef PROYECTO_CONDICIONAL_H
#define PROYECTO_CONDICIONAL_H

#include <string>
#include "Instruccion.h"
#include "Lista.h"

using namespace std;

class Condicional : public Instruccion {
public:
    Condicional(string l, int num) : Instruccion(l, num) {};//Constructor, llama a clase
                                                            // padre para incializar atributos
    int ejecutar(Lista<Variable*>*);// analiza la expresion booleana luego del "IF". Si
                                    // es verdadera, ejecuta la instruccion luego del
                                    //"THEN", caso contrario no hace nada
};




#endif //PROYECTO_CONDICIONAL_H
