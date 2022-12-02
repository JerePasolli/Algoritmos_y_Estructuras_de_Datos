//
// Created by jerem on 28/4/2022.
//

#include "Jump.h"


int Jump::ejecutar(Lista<Variable*>* m) {
    //cout << "Jump detectado, procesando" << endl;
    string palabra = "";
    for (auto x : linea){
        if(x==' '||x=='J'||x=='U'||x=='M'||x=='P') // quita la palabra SHOW y el espacio para quedarme con el numero
            continue;
        else
            palabra = palabra + x; // esto sera el numero al cual saltar
    }
    return stoi(palabra); //retorna el numero, que indica a que instruccion se debe saltar
}