#include "Arbol.h"
#include <sstream>
#include <fstream>
#include "json.hpp"

bool isHoja(Nodo* n){
    if (n->izq == nullptr && n->der == nullptr)
        return true;
    else
        return false;
}

Nodo* anadirHijo(Nodo* nodo, std::string cadena)
{
    //añade a la izquierda
    if (nodo->izq == nullptr) {
        Nodo* nuevo = new Nodo{cadena, nullptr, nullptr};
        nodo->izq = nuevo;
        return nuevo;
    }

    //añade a la derecha del hijo izquierdo
    Nodo* temp = nodo->izq;
    while (temp->der != nullptr) {
        temp = temp->der;
    }
    Nodo* nuevo = new Nodo{cadena, nullptr, nullptr};
    temp->der = nuevo;
    return nuevo;
}

Nodo* buscarHijo(Nodo* nodo, std::string cadena)
{
    //verifica si el mismo nodo contiene la raiz
    if (nodo->dato == cadena) {
        return nodo;
    }
    //verifica si el nodo izquierdo contiene la cadena
    Nodo* temp = nodo->izq;
    if (temp != nullptr and temp->dato == cadena) {
        return temp;
    }
    // verifica si los nodos a la derecha del hijo izquierdo contienen el dato
    // retorna nullptr si no lo encuentra
    while (temp != nullptr and temp->dato != cadena) {
        temp = temp->der;
    }
    return temp;
}

Nodo* insertion_sort(Nodo* n, std::string criterio)
{
    //almaceno los nodos en el arreglo
    std::vector<Nodo*> vector{};
    Nodo* temp = n->izq;
    while (temp != nullptr) {
        vector.push_back(temp);
        temp = temp->der;
    }    
    //algoritmo de ordenamiento por inserción
    for(int i = 1; i <= vector.size() - 1; ++i) {
        int j = i;
        if(buscarHijo(vector.at(j),criterio)!=nullptr){//existe el criterio para ese laureado
            while (j > 0 && buscarHijo(vector.at(j-1),criterio)!=nullptr && buscarHijo(vector.at(j-1), criterio)->izq->dato > buscarHijo(vector.at(j), criterio)->izq->dato) {
                std::swap(vector.at(j), vector.at(j-1));
                --j;
            }
        }
        else{//buscar hijo retorna nullptr, no existe el criterio
            while(j > 0){
                std::swap(vector.at(j), vector.at(j-1));//lo manda al principio
                --j;
            }
        }
    }    
    for (int k = 0; k < vector.size() - 1; ++k) {
        vector.at(k)->der = vector.at(k+1) ;
    }
    vector.at(vector.size()-1)->der = nullptr;
    
    //devuelvo el puntero del primer nodo a la izquierda
    return vector.at(0);
}

void qs(Nodo* v[], int primero, int ultimo, std::string criterio){
    //algoritmo de ordenamiento quick_sort
    int i,j;
    Nodo* aux;
    Nodo* pivot;
    if(ultimo>primero){
        pivot = v[ultimo];
        i=primero-1; j=ultimo;
        for(;;){
            while(buscarHijo(v[++i],criterio)->izq->dato < buscarHijo(pivot,criterio)->izq->dato); //i reocorre de izq a derecha y guarda valor menor al pivot
            while(buscarHijo(v[--j],criterio)->izq->dato > buscarHijo(pivot,criterio)->izq->dato); //j reocorre de derecha a izq y guarda valor mayor al pivot
            if(i>=j)break;
            aux=v[i];v[i]=v[j];v[j]=aux; // swapeo v[i] con v[j]
        }// fin for
        aux=v[i];v[i]=v[ultimo];v[ultimo]=aux;//hago que quede el pivot en v[i], para luego aplicar el
        qs(v,primero,i-1,criterio); //aplico quicksort al lado izquierdo del pivot
        qs(v,i+1,ultimo,criterio); //aplico quicksort al lado derecho del pivot
    } //fin if
}

Nodo* quick_sort (Nodo* n,std::string criterio){
    //almaceno los nodos en el arreglo
    Nodo* temp = n->izq;
    int contador = 0;
    int contador2=0;
    while (temp != nullptr) {
        if(buscarHijo(temp,criterio)!=nullptr)
            contador++;
        else
            contador2++;
        temp = temp->der;
    }
    temp = n->izq;
    Nodo* v[contador];
    Nodo* v2[contador2];
    int i = 0;
    int f = 0;
    while(temp!=nullptr){
        if(buscarHijo(temp,criterio) != nullptr){
            v[i] = temp;
            i++;
        }
        else{
            v2[f] = temp;
            f++;
        }
        temp = temp->der;
    }

    qs(v,0,contador-1, criterio);

    for (int z = 0; z < contador2; z++) {
        v2[z]->der = v2[z+1] ;
    }
    for (int k = 0; k < contador; k++) {
        v[k]->der = v[k+1] ;
    }
    v2[contador2-1]->der = v[0];
    v[contador-1]->der = nullptr;
    //devuelvo el puntero del primer nodo a la izquierda
    return v2[0];

}

bool Arbol::isRaiz(Nodo* n){
    if (n==raiz)
        return true;
    else
        return false;
}

void Arbol::rid(Nodo* root)
{
    if (root != nullptr) {
        if (isRaiz(root)){
            std::cout << "\n" << root->dato <<":" << "\n\n";
        }
        else if(isHoja(root)){
            std::cout << root->dato << "\n\n";
        }
        else{
            std::cout << root->dato <<": ";
        }
        rid(root->izq);
        rid(root->der);
    }
}

void Arbol::leer(std::string archivo)
{
    std::ifstream iss{archivo}; //abre el archivo json
    nlohmann::ordered_json jf = nlohmann::ordered_json::parse(iss).flatten(); //almacena en el objeto jf 
    for (auto elem : jf.items()) { 
        if(elem.value().empty()){
            insertarDir(elem.key(), "null");
        }
        else{
            insertarDir(elem.key(), elem.value());//key es todo antes del :, value seria la hoja que quedara
        }
    }
}



void Arbol::insertarDir(std::string dir, std::string obj)
{
    dir.erase(0,1);
    std::istringstream input2{dir}; // elimina el "/" inicial para evitar que se cuenten cadenas vacias

    Nodo* temp = raiz;
    for (std::string line; std::getline(input2, line, '/'); ) {
        //std::cout << line << '\n';
        if (raiz == nullptr) {
            raiz = new Nodo{line, nullptr, nullptr};
            temp = raiz;
        } else {
            if (buscarHijo(temp,line) == nullptr) {
                temp = anadirHijo(temp, line);
            } else {
                temp = buscarHijo(temp,line);
            }
        }


    }
    anadirHijo(temp, obj);
}



void Arbol::ordenarIS(std::string criterio)
{
    raiz->izq = insertion_sort(raiz, criterio);
}

void Arbol::ordenarQS (std::string criterio){
    raiz->izq = quick_sort (raiz,criterio);
}

void Arbol::leerYordenar(std::string archivo , std::string criterio){
    std::ifstream iss{archivo}; //abre el archivo json
    nlohmann::ordered_json jf = nlohmann::ordered_json::parse(iss).flatten(); //almacena en el objeto jf
    for (auto elem : jf.items()) {
        if (elem.key().find(criterio) != std::string::npos) {
            bandera = true;
        }
        if(elem.value().empty()){
            insertarDir(elem.key(), "null");
        }
        else{
            insertarDir(elem.key(), elem.value());//key es todo antes del :, value seria la hoja que quedara
        }
        if(bandera){
            if(contador!=0){
                this->ordenarIS(criterio);
            }
            bandera = false;
            contador++;
        }
    }
}

void Arbol::printBT(const std::string& prefix, const Nodo* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "'--" );

        // print the value of the node
        std::cout << node->dato << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->izq, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->der, false);
    }
}

void Arbol::printBT(const Nodo* node)
{
    printBT("", node, false);
}

void Arbol::verArbol2()
{
    printBT(raiz);
}


void Arbol::preorder()
{
    rid(raiz);
}


