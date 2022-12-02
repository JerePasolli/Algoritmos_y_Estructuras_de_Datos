src = ./src
out = ./out
bin = ./bin

$(bin)/main.out: $(out)/main.o $(out)/Asignacion.o $(out)/Calculadora.o $(out)/Condicional.o $(out)/Declaracion.o $(out)/Instruccion.o $(out)/Jump.o $(out)/Lector.o $(out)/Lista.o $(out)/Pila.o $(out)/Procesador.o $(out)/Show.o $(out)/Variable.o
	mkdir -p $(bin)
	g++ -o $(bin)/main.out $(out)/main.o $(out)/Asignacion.o $(out)/Calculadora.o $(out)/Condicional.o $(out)/Declaracion.o $(out)/Instruccion.o $(out)/Jump.o $(out)/Lector.o $(out)/Lista.o $(out)/Pila.o $(out)/Procesador.o $(out)/Show.o $(out)/Variable.o

$(out)/main.o: $(src)/main.cpp $(src)/Instruccion.h $(src)/Lector.h $(src)/Procesador.h $(src)/Lista.h
	mkdir -p $(out)
	g++ -c -o $(out)/main.o $(src)/main.cpp

$(out)/Asignacion.o: $(src)/Asignacion.cpp $(src)/Asignacion.h $(src)/Calculadora.h
	g++ -c -o $(out)/Asignacion.o $(src)/Asignacion.cpp

$(out)/Calculadora.o: $(src)/Calculadora.cpp $(src)/Calculadora.h $(src)/Pila.h
	g++ -c -o $(out)/Calculadora.o $(src)/Calculadora.cpp

$(out)/Condicional.o: $(src)/Condicional.cpp $(src)/Condicional.h $(src)/Calculadora.h
	g++ -c -o $(out)/Condicional.o $(src)/Condicional.cpp

$(out)/Declaracion.o: $(src)/Declaracion.cpp $(src)/Declaracion.h 
	g++ -c -o $(out)/Declaracion.o $(src)/Declaracion.cpp

$(out)/Instruccion.o: $(src)/Instruccion.cpp $(src)/Instruccion.h $(src)/Show.h $(src)/Jump.h $(src)/Asignacion.h $(src)/Declaracion.h $(src)/Condicional.h
	g++ -c -o $(out)/Instruccion.o $(src)/Instruccion.cpp

$(out)/Jump.o: $(src)/Jump.cpp $(src)/Jump.h 
	g++ -c -o $(out)/Jump.o $(src)/Jump.cpp

$(out)/Lector.o: $(src)/Lector.cpp $(src)/Lector.h
	g++ -c -o $(out)/Lector.o $(src)/Lector.cpp

$(out)/Lista.o: $(src)/Lista.cpp $(src)/Lista.h
	g++ -c -o $(out)/Lista.o $(src)/Lista.cpp

$(out)/Pila.o: $(src)/Pila.cpp $(src)/Pila.h
	g++ -c -o $(out)/Pila.o $(src)/Pila.cpp

$(out)/Procesador.o: $(src)/Procesador.cpp $(src)/Procesador.h
	g++ -c -o $(out)/Procesador.o $(src)/Procesador.cpp

$(out)/Show.o: $(src)/Show.cpp $(src)/Show.h $(src)/Calculadora.h
	g++ -c -o $(out)/Show.o $(src)/Show.cpp

$(out)/Variable.o: $(src)/Variable.cpp $(src)/Variable.h
	g++ -c -o $(out)/Variable.o $(src)/Variable.cpp

clean:
	rm -rf $(out) $(bin)