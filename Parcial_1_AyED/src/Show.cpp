//
// Created by jerem on 28/4/2022.
//

#include "Show.h"
#include "Calculadora.h"
#include <string>


using namespace std;

bool Show::isNumero (string c){
    bool bandera = true;
    for(char x : c){
        if(x != ' '){
            if(x <= 48 || x >= 57) {
                bandera = false;
                break;
            }
        }
    }
    return bandera;
}

int Show::ejecutar(Lista<Variable*>* m) {
    //cout << "Show detectado, procesando" << endl;
    Lista<Variable*>* aux = new Lista<Variable*>();
    aux->concat(m);
    size_t pos = 0;
    string delimitador = " ";
    string analisis = linea + " ";
    string mostrar;
    string parte;
    while ((pos = analisis.find(delimitador)) != string::npos) {
        parte = analisis.substr(0, pos) + " ";
        if (parte != "SHOW "){
            mostrar += parte;
        }
        analisis.erase(0, pos + delimitador.length());
      }
    //string mostrar = "";
    /*for (auto x : linea){
        if(x==' '|| x== 'S'|| x== 'H'|| x== 'O'|| x== 'W')
            continue;
        else{
            mostrar = mostrar + x + " ";
        }

    }*/
    if (mostrar.size()== 2){ //significa que el valor a mostrar es una variable o numero
        if(isNumero(mostrar)){
            cout << mostrar << endl;
        }
        else {
            for(int i=1;i<=m->size();i++){
                if ((aux->cabeza()->getNombrevar()+ " ")==mostrar){
                    if(aux->cabeza()->getTipovar()== "bool"){
                        if(aux->cabeza()->getValor() == 1){
                            cout << "TRUE" << endl;
                            break;
                        }
                        else{
                            cout << "FALSE" << endl;
                            break;
                        }
                    }
                    else{
                        cout << aux->cabeza()->getValor() << endl;
                        break;
                    }
                }
                else{
                    aux = aux->resto();
                    continue;
                }
            }
        }
    }
    else { //significa que el valor a mostrar es una expresion aritmetica o booleana
        Calculadora * calc = new Calculadora(mostrar);
        string posfijo = calc->infijoAPosfijo();
        if (!Instruccion::isBooleana(mostrar)){
            cout << calc->operarPosfijo(posfijo,m) << endl;
        }
        else{
            cout << calc->operarPosfijoBooleano(posfijo,m) << endl;
        }
    }
    return numinst+1;
}