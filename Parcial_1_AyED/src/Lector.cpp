//
// Created by jerem on 27/4/2022.
//

#include "Lector.h"

Lista<Instruccion>* Lector::lectura(){
    Lista<Instruccion>* listainstrucciones = new Lista<Instruccion>();
    programa.open("C:\\Users\\jerem\\Documents\\Facultad\\Algoritmos y Estructuras de datos"
                  "\\Primer parcial\\Proyecto\\programa.txt",ios::in);
    if(programa.fail()){
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    int i = 1;
    while(!programa.eof()){
        getline(programa,instrucciones);
        Instruccion inst (instrucciones,i);
        listainstrucciones->add(inst);
        i++;
    }
    programa.close();
    return listainstrucciones;
}