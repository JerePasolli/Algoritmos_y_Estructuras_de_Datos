//
// Created by jerem on 27/4/2022.
//

#include "Procesador.h"

Procesador::Procesador(Lista<Instruccion>* inst) {
    instrucciones = inst;
    memoria = new Lista<Variable*>();
}

Instruccion Procesador::getInst (int num){ // retorna una instruccion dado el numero que se le pasa como argumento
    Lista<Instruccion>* aux;
    aux = instrucciones->copy();
    Instruccion retorno;
    for(int i=1;i<=instrucciones->size();i++){
        if (aux->esvacia())
            cout << "Error, no se encontro la instruccion en la lista" << endl;
        else if (aux->cabeza().getNuminst()==num){
            retorno = aux->cabeza();
            break;
        }
        else{
            aux = aux->resto();
            continue;
        }
    }
    return retorno;
}

void Procesador::procesar(){
    int i = 1;
    while (i<=instrucciones->size()){
        i = procesarLinea(getInst(i));//asigna siguiente linea a procesar
    }
    cout << "Fin del programa" << endl;
}

int Procesador::procesarLinea(Instruccion inst) {
   return inst.ejecutar(memoria);
}
