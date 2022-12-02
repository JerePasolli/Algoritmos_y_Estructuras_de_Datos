//
// Created by jerem on 28/4/2022.
//

#ifndef PROYECTO_SHOW_H
#define PROYECTO_SHOW_H

#include "Instruccion.h"

class Show : public Instruccion {
public:
    Show(string l, int num) : Instruccion(l, num) {};//Constructor, llama a clase
                                                     // padre para incializar atributos
    int ejecutar(Lista<Variable*>*); // hara una impresion de lo que haya luego de
                                     // la palabra SHOW en la linea
    bool isNumero(string); //identifica si se desea mostrar simplemente un numero
};


#endif //PROYECTO_SHOW_H
