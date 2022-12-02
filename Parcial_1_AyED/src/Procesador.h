//
// Created by jerem on 27/4/2022.
//

#ifndef PROYECTO_PROCESADOR_H
#define PROYECTO_PROCESADOR_H

#include "Instruccion.h"
#include "Variable.h"
#include "Lista.h"

class Procesador {
public:
    Procesador (Lista<Instruccion>*); //constructor, recibe lista de instrucciones que genero el lector
    Instruccion getInst (int); // busca en la lista y retorna la instruccion correspondiente al
                               // numero de instruccion que se pasa como parametro
    void procesar(); // metodo principal, se encarga de procesar todas las instrucciones del texto
    int procesarLinea(Instruccion); // procesa solo una instruccion especifica

private:
    Lista<Instruccion>* instrucciones; // lista de instrucciones
    Lista<Variable*>* memoria; // lista donde se guardaran y asignaran variables luego
};


#endif //PROYECTO_PROCESADOR_H
