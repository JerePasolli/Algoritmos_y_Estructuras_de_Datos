cmake_minimum_required(VERSION 3.21)
project(Proyecto)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto main.cpp Instruccion.cpp Instruccion.h Procesador.cpp Procesador.h Lector.cpp Lector.h Pila.cpp Pila.h Declaracion.cpp Declaracion.h Variable.cpp Variable.h Show.cpp Show.h Asignacion.cpp Asignacion.h Jump.cpp Jump.h Condicional.cpp Condicional.h Calculadora.cpp Calculadora.h Lista.cpp Lista.h)
