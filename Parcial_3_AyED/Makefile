src = ./src
out = ./out
bin = ./bin

$(bin)/main.out: $(out)/graph.o
	mkdir -p $(bin)
	g++ -o $(bin)/main.out $(out)/graph.o

$(out)/graph.o: $(src)/graph.cpp $(src)/Tree.hpp
	mkdir -p $(out)
	g++ -c -o $(out)/graph.o $(src)/graph.cpp

clean:
	rm -rf $(bin) $(out)