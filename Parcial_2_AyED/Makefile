src = ./src
out = ./out
bin = ./bin

$(bin)/main.out: $(out)/main.o $(out)/Arbol.o
	mkdir -p $(bin)
	g++ -o $(bin)/main.out $(out)/main.o $(out)/Arbol.o

$(out)/main.o: $(src)/main.cpp $(src)/Arbol.h
	mkdir -p $(out)
	g++ -c -o $(out)/main.o $(src)/main.cpp

$(out)/Arbol.o: $(src)/Arbol.cpp $(src)/Arbol.h $(src)/json.hpp
	g++ -c -o $(out)/Arbol.o $(src)/Arbol.cpp

clean:
	rm -rf $(out) $(bin)