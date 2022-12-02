#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <vector>


struct Nodo
{
    std::string dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* anadirHijo(Nodo*, std::string);
Nodo* buscarHijo(Nodo*, std::string);
bool isHoja(Nodo*);



class Arbol //arbol m-ario
{
private:
    Nodo* raiz;
    int contador;
    bool bandera;
    void printBT(const std::string& prefix, const Nodo* node, bool isLeft);
    void printBT(const Nodo* node);
    void rid(Nodo*);

public:
    Arbol(){raiz= nullptr;/*aux=nullptr*/;contador=0;};
    void leer(std::string);
    void insertarDir(std::string, std::string);
    void ordenarIS(std::string);
    void ordenarQS(std::string);
    void leerYordenar(std::string, std::string);
    void verArbol2();
    void preorder();
    bool isRaiz(Nodo*);
};

#endif
