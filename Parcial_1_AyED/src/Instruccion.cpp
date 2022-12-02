//
// Created by jerem on 27/4/2022.
//

#include "Instruccion.h"
#include "Show.h"
#include "Jump.h"
#include "Asignacion.h"
#include "Declaracion.h"
#include "Condicional.h"
#include <string>

using namespace std;

Instruccion::Instruccion(string l, int num) {
    linea = l;
    numinst = num;

}

bool Instruccion::isBooleana (string expresion) {
    bool bandera = false;
    for(char x : expresion){
        if(x != ' '){
            if(x == 60 || x == 61 || x == 62 || x == 33) {
                bandera = true;
                break;
            }
        }
    }
    if (bandera){
        return true;
    }
    else{
        return false;
    }
}

bool Instruccion::isJump(){
    string palabra = "";
    for (auto x : linea){
        if(x==' ')
            break;
        else
            palabra = palabra + x;
    }
    if (palabra == "JUMP")
        return true;
    else
        return false;
}

bool Instruccion::isDeclaracion(){
    string palabra = "";
    for (auto x : linea){
        if(x==' ')
            break;
        else
            palabra = palabra + x;
    }
    if (palabra == "INT" || palabra == "BOOL")
        return true;
    else
        return false;
}

bool Instruccion::isShow(){
    string palabra = "";
    for (auto x : linea){
        if(x==' ')
            break;
        else
            palabra = palabra + x;
    }
    if (palabra == "SHOW")
        return true;
    else
        return false;
}

bool Instruccion::isAsignacion() {
    string palabra = "";
    for (auto x : linea){
        if(x==' ')
            break;
        else
            palabra = palabra + x;
    }
    if (palabra != "INT" && palabra != "BOOL" && palabra != "JUMP" && palabra != "SHOW" &&
    palabra != "IF" && palabra.size()==1)
        return true;
    else
        return false;
}

bool Instruccion::isCondicional(){
    string palabra = "";
    for (auto x : linea){
        if(x==' ')
            break;
        else
            palabra = palabra + x;
    }
    if (palabra == "IF")
        return true;
    else
        return false;
}

int Instruccion::ejecutar(Lista<Variable*>* mem){
    int siginstruccion;
    if (this->isJump()){
        Jump* jump = new Jump(linea, numinst);
        siginstruccion = jump->ejecutar(mem);
    }

    else if (this->isAsignacion()){
        Asignacion* asignacion = new Asignacion(linea,numinst);
        siginstruccion = asignacion->ejecutar(mem);
    }
    else if (this->isCondicional()){
        Condicional* condicional = new Condicional(linea, numinst);
        siginstruccion = condicional->ejecutar(mem);
        delete(condicional);
    }
    else if (this->isDeclaracion()){
        Declaracion* declaracion = new Declaracion(linea,numinst);
        siginstruccion = declaracion->ejecutar(mem);
    }
    else if (this->isShow()){
        Show* show = new Show(linea,numinst);
        siginstruccion = show->ejecutar(mem);
    }
    else{
        cout << "Instruccion invalida en la linea " << numinst << endl;
        exit(1);
    }
    return siginstruccion;
}


