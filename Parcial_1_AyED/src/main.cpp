#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Instruccion.h"
#include "Lector.h"
#include "Procesador.h"
#include "Lista.h"

using namespace std;


int main(){
    Lector* lector = new Lector (); // crea un lector
    Lista<Instruccion>* listainst = lector->lectura(); // crea lista de instrucciones con retorno del lector
    Procesador* procesador = new Procesador (listainst); // crea procesador y le pasa la lista de instrucciones
    procesador->procesar(); // comienza a procesar el texto
    return 0;
}