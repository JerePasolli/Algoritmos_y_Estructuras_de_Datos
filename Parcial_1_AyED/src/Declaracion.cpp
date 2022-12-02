//
// Created by jerem on 27/4/2022.
//

#include "Declaracion.h"


int Declaracion::ejecutar(Lista<Variable*>* m){
    //cout << "Declaracion detectada, procesando" << endl;
    string tipovar = "";// INT BOOL
    string nombrevar;  // a b c
    for (auto x : linea){
        if(x=='I'||x=='N'||x=='T'||x=='B'||x=='O'||x=='L')
            tipovar = tipovar + x;
        else
            break;
    }

    for (auto x : linea){
        if(x==' '||x=='I'||x=='N'||x=='T'||x=='B'||x=='O'||x=='L')
            continue;
        else
            nombrevar = x;
    }

    if (tipovar == "INT"){
        Variable* v = new Variable ("int",nombrevar);
        m->add(v);
    }
    else if (tipovar == "BOOL"){
        Variable* v = new Variable ("bool",nombrevar);
        m->add(v);
    }
    return numinst+1;
}