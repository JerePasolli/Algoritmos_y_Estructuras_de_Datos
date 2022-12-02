//
// Created by jerem on 27/4/2022.
//

#include "Lector.h"

Lista<Instruccion>* Lector::lectura(){
    Lista<Instruccion>* listainstrucciones = new Lista<Instruccion>();
    programa.open("Direccion al archivo aqui",ios::in);
    if(programa.fail()){
        cout << "Error al abrir el archivo, recuerde que se debe ingresar a mano la direccion del archivo que se "
        << "desea leer en la funcion programa.open() de la clase Lector" << endl;
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