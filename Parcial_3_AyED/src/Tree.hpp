#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#define CANT 8

using namespace std;

class Node {
private:
	int city;
	bool visited[CANT];
	vector<Node*> child;
	vector<int> nodos;
public:
	Node(int ciudad, bool visitado[CANT], vector<int> n) { 
		city = ciudad;
		for (int i = 0; i < CANT; i++) visited[i] = visitado[i]; nodos = n;
	}
	int getCity() { return city; }
	void putChild(Node* n) { child.push_back(n); }
	bool isVisited(int n) { if (visited[n]) return true; return false; }
	bool* getVisited() { return visited; }
	void setVisited(int n) { visited[n] = true; }
	void setNodos(int i) { nodos.push_back(i); }
	vector<int> getNodos() { return nodos; }
};
#endif // !TREE_HPP





