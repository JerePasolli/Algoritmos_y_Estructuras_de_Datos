//
// Created by jerem on 28/4/2022.
//

#include "Condicional.h"
#include "Calculadora.h"

int Condicional::ejecutar(Lista<Variable*>* m){
   //cout << "Condicional detectado, procesando" << endl;
   string expbool = "";
   string instruccion = "";
   string condicional = linea + " ";
   int contador = 0;
   string delimitador = " ";
   size_t pos = 0;
   string parte;
   int siginstruccion;
   while ((pos = condicional.find(delimitador)) != string::npos) {
       parte = condicional.substr(0, pos) + " ";
       if (parte == "IF "){}
       else if (parte == "THEN "){contador++;}
       else if (contador == 0){//exp booleana a analizar
           expbool+=parte;
       }
       else{//instruccion
           instruccion+=parte;
       }
       condicional.erase(0, pos + delimitador.length());
   }
    Calculadora* calcucondicional = new Calculadora(expbool);
    string posfijo = calcucondicional->infijoAPosfijo();
    int resultadobool = calcucondicional->operarPosfijoBooleano(posfijo,m);
    if (resultadobool == 1){
        Instruccion instajecutar (instruccion,numinst);
        siginstruccion = instajecutar.ejecutar(m);
    }
    else{
        siginstruccion = numinst+1;
    }
    return siginstruccion;
}