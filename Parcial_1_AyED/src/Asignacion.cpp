//
// Created by jerem on 28/4/2022.
//

#include "Asignacion.h"
#include "Calculadora.h"
#include <string>

using namespace std;

int Asignacion::ejecutar(Lista<Variable*>* m){
    //cout << "Asignacion detectada, procesando" << endl;
    string nombrevariable;
    string delimitador = " = ";
    string aasignar;
    string posfijo;
    int resultado;
    nombrevariable = linea.substr(0,linea.find(delimitador));
    aasignar = linea.erase(0, linea.find(delimitador) + delimitador.length());
    aasignar += " ";
    Calculadora* calculadora = new Calculadora(aasignar);
    if(!Instruccion::isBooleana(aasignar)){
        posfijo = calculadora->infijoAPosfijo();
        resultado= calculadora->operarPosfijo(posfijo,m);
        setResultado(resultado,nombrevariable,m);
    }
    else{
        posfijo = calculadora->infijoAPosfijo();
        resultado= calculadora->operarPosfijoBooleano(posfijo,m);
        setResultado(resultado,nombrevariable,m);
    }
    return numinst+1;
}

void Asignacion::setResultado(int result,string nombrevar,Lista<Variable*>* mem){
    if(mem->cabeza()->getNombrevar() == nombrevar){
        mem->cabeza()->setValor(result);
        return;
    }
    else{
        setResultado(result,nombrevar,mem->resto());
    }
}


