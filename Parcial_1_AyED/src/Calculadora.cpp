//
// Created by jerem on 2/5/2022.
//

#include "Calculadora.h"
#include "Pila.h"

Calculadora::Calculadora(string exp) {
    infijo = exp;
    pila = new Pila<string>();
}

string Calculadora::infijoAPosfijo() {
    string posfijo;
    string delimitador = " ";
    string operador;
    size_t pos = 0;
    string parte;
    while ((pos = infijo.find(delimitador)) != string::npos) {
        parte = infijo.substr(0, pos) + " ";
        if(isOperator(parte)){
            while(!pila->esvacia() && (operador = pila->tope()) != "( " &&
                  precedencia(parte) <= precedencia(operador)){
                posfijo += operador;
                pila->desapilar();
            }
            pila->apilar(parte);
        }
        else if (parte=="( "){
            pila->apilar(parte);
        }
        else if (parte==") "){
            while((operador = pila->tope()) != "( "){
                posfijo += operador;
                pila->desapilar();
            }
            pila->desapilar();
        }
        else{
            posfijo += parte;
        }
        infijo.erase(0, pos + delimitador.length());
    }
    while(!pila->esvacia()){
        posfijo += pila->tope();
        pila->desapilar();
    }
    return posfijo;
}

bool Calculadora::isOperator(string c){
    string simbolos = "+ - * / == != < > >= <=";
    return (simbolos.find(c) != string::npos);
}


int Calculadora::precedencia(string c) {
    return (c=="+"||c=="-") ? 1 :
           (c=="*"||c=="/") ? 2: 0;
}

int Calculadora::operarPosfijo (string posfijo, Lista<Variable*>* mem){
    string delimitador = " ";
    string operador;
    size_t pos = 0;
    string parte;
    while ((pos = posfijo.find(delimitador)) != string::npos) {
        parte = posfijo.substr(0, pos);
        if (!isOperator(parte)) {
            Lista<Variable*> *aux = new Lista<Variable*>();
            aux->concat(mem);
            if (!isNumero(parte)) {
                for (int i = 1; i <= mem->size(); i++) {
                    if (aux->cabeza()->getNombrevar() == parte) {
                        pila->apilar(to_string(aux->cabeza()->getValor()));
                        delete (aux);
                        break;
                    } else
                        aux = aux->resto();
                }
            }
            else {
                pila->apilar(parte);
            }
        }
        else if (parte == "+")
            suma();
        else if (parte == "-")
            resta();
        else if (parte == "*")
            multiplicacion();
        else if (parte == "/")
            division();
        posfijo.erase(0, pos + delimitador.length());
    }
    return stoi(pila->tope());
}

int Calculadora::operarPosfijoBooleano(string posfijo, Lista<Variable *> *mem) {
    string delimitador = " ";
    string operador;
    size_t pos = 0;
    string parte;

    while ((pos = posfijo.find(delimitador)) != string::npos) {
        parte = posfijo.substr(0, pos);
        if (!isOperator(parte)) {
            Lista<Variable*> *aux = new Lista<Variable*>();
            aux->concat(mem);
            if (!isNumero(parte)) {
                for (int i = 1; i <= mem->size(); i++) {
                    if (aux->cabeza()->getNombrevar() == parte) {
                        pila->apilar(to_string(aux->cabeza()->getValor()));
                        delete (aux);
                        break;
                    } else
                        aux = aux->resto();
                }
            }
            else {
                pila->apilar(parte);
            }
        }
        else if (parte == "==")
            igual();
        else if (parte == "!=")
            distinto();
        else if (parte == "<"){
            mayor();
        }

        else if (parte == ">")
            menor();
        else if (parte == "<=")
            mayorIgual();
        else if (parte == ">=")
            menorIgual();
        posfijo.erase(0, pos + delimitador.length());
    }
    return stoi(pila->tope());
}
void Calculadora::igual(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(a==b){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::distinto(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(a!=b){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::mayor(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(b<a){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::menor(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(b>a){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::mayorIgual(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(b<=a){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::menorIgual(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    if(b>=a){
        pila->apilar(to_string(1));//true
    }
    else{
        pila->apilar(to_string(0));//false
    }
}

void Calculadora::suma(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    pila->apilar(to_string(a+b));
}

void Calculadora::resta(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    pila->apilar(to_string(b-a));
}

void Calculadora::multiplicacion(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    pila->apilar(to_string(a*b));
}

void Calculadora::division(){
    int a = stoi(pila->tope());
    pila->desapilar();
    int b = stoi(pila->tope());
    pila->desapilar();
    pila->apilar(to_string(b/a));
}

bool Calculadora::isNumero (string c){
    bool bandera = true;
    for(char x : c){
        if(x != ' '){
            if(x < 48 || x > 57) {
                bandera = false;
                break;
            }
        }
    }
    return bandera;
}


