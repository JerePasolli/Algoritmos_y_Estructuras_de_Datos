#include <iostream>
#include "Arbol.h"

int main()
{
    int eleccion;
    int eleccion2;
    std::string ordenamiento;
    Arbol arbol;
    std::cout << "Elija como desea cargar los datos" << std::endl;
    std::cout << "Ingrese 1 para cargar datos" << std::endl;
    std::cout << "Ingrese 2 para cargar datos de manera ordenada" << std::endl;
    std::cin >> eleccion;
    if(eleccion == 1){
        std::cout << "Cargando datos..." << std::endl;
        arbol.leer("completo.json");
        std::cout << "Carga finalizada" << std::endl;
    }
    else{
        std::cout << "Ingrese el criterio de ordenamiento" << std::endl;
        std::cin >> ordenamiento;
        std::cout << "Cargando datos ordenadamente..." << std::endl;
        arbol.leerYordenar("completo.json",ordenamiento);
        //arbol.leer("completo.json");
        //arbol.ordenarIS(ordenamiento);
        std::cout << "Carga finalizada" << std::endl;
    }
    while(true){
        std::cout << "Seleccione como continuar" << std::endl;
        if(eleccion==1){
            std::cout << "Ingrese 1 para ordenar los datos por algun criterio" << std::endl;
            eleccion++;
        }
        else{
            std::cout << "Ingrese 1 para reordenar los datos por algun criterio" << std::endl;
        }
        std::cout << "Ingrese 2 para mostrar los datos" << std::endl;
        std::cout << "Ingrese 3 para finalizar ejecucion" << std::endl;
        std::cin >> eleccion2;
        if(eleccion2 == 1){
            std::cout << "Ingrese el criterio" << std::endl;
            std::cin >> ordenamiento;
            std::cout << "Ordenando..." << std::endl;
            arbol.ordenarIS(ordenamiento);
            std::cout << "Ordenamiento finalizado" << std::endl;

        }
        else if (eleccion2==2){
            arbol.preorder();
        }
        else{
            break;
        }
    }
}
