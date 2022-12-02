//
// Created by jerem on 2/5/2022.
//

#ifndef PROYECTO_CALCULADORA_H
#define PROYECTO_CALCULADORA_H

#include <string>
#include "Pila.h"
#include "Variable.h"

using namespace std;

class Calculadora {
public:
    Calculadora(string); //Constructor, recibe exprecion infija como parametro
    string infijoAPosfijo ();//recibe expresion infija y la transforma a posfija
    bool isOperator(string);//verifica si un string es un operador
    int precedencia (string);//analiza precedencia de un operador dado
    int operarPosfijo(string,Lista<Variable*>*);//resuelve operacion aritmetica en posfijo
    int operarPosfijoBooleano(string,Lista<Variable*>*);//resuelve operacion booleana en posfijo
    void igual();
    void distinto();
    void mayor();
    void menor();
    void mayorIgual();
    void menorIgual();//Todos estos metodos evaluan expresiones booleanas, segun el operador,
                      // utilizando una pila
    void suma();
    void resta();
    void multiplicacion();
    void division(); // Estos hacen lo mismo, pero con expresiones arimeticas, segun el operador
    bool isNumero (string); //Analiza si un string corresponde a un numero
private:
    string infijo; //operacion en infijo
    Pila<string>* pila; // pila de strings que se utilzara para el pasaje de infijo a posfijo y
                        // para resolver las operaciones posfijas luego
};


#endif //PROYECTO_CALCULADORA_H
