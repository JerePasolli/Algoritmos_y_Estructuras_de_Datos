#include "Tree.hpp"
#define INF 9000
#include <queue>

using namespace std;

void bfs(int first, int graph[CANT][CANT]);
bool isHamiltoniano(Node prueba, int graph[8][8]);
pair<vector<int>, int>optimo;

void presupuesto(vector<int> recorrido, int graph[8][8]) {
    int presupuesto = 0;

    for (int i = 0; i < 7; i++) {
        presupuesto += graph[recorrido[i]][recorrido[i + 1]];
    }
    presupuesto += graph[recorrido[7]][0];

    if (optimo.second == 0 || presupuesto < optimo.second) {
        optimo.first = recorrido;
        optimo.second = presupuesto;
    }

    cout << "El presupuesto de ir por ese recorrido es: " << presupuesto << endl << endl;

}

/*void verCiclos(vector<int> arr, int grafo[8][8]) {
    for (int i = 0; i < 8; i++) {
        if (i == 7) {
            if (grafo[arr.at(i)][0] == INF) cout << "\n--------------------------------------------" << endl;
        }
        else {
            if (grafo[arr.at(i)][arr.at(i + 1)] == INF) cout << "\n--------------------------------------------" << endl;
        }
    }
}*/

string indexCities[CANT] = { "Madrid", "Roma", "Paris", "Amsterdan", "Zurich",
                                "Berlin", "Varsovia", "Viena" };

void bfs(int first, int graph[CANT][CANT]) {
    int contador = 0;
	queue<Node*> toVisit;
    bool visitado[CANT] = {1, 0, 0, 0, 0, 0, 0, 0};
    vector<int> nodos;
    nodos.push_back(first);
    Node* node = new Node(first, visitado, nodos);
    toVisit.push(node);

    while (!toVisit.empty()) {
        node = toVisit.front(); toVisit.pop();
        for (int i = 0; i < CANT; i++) {

            if (graph[node->getCity()][i] != INF && !node->isVisited(i)) {
                nodos = node->getNodos();
                nodos.push_back(i);
                Node* aux = new Node(i, node->getVisited(), nodos);
                if (isHamiltoniano(*aux, graph)) {
                    cout << indexCities[aux->getCity()] << " es hamiltoniano" << endl;
                    aux->setVisited(i);
                    node->putChild(aux);
                    toVisit.push(aux);
                }
                else {
                    cout << indexCities[aux->getCity()] << " NO es hamiltoniano--------------" << endl;
                }
            }
            else if(i == 0 && graph[node->getCity()][i] != INF) {
                int cont = 0;
                for (int j = 0; j < CANT; j++) {
                    if (node->getVisited()[j]) {
                        cont++;
                    }
                }
                if (cont == 8) {
                    contador++;
                    cout << "Encontre ciclo hamiltoneano en ";
                    for (int r = 0; r < CANT; r++) { cout << indexCities[node->getNodos().at(r)] << " - "; }
                   // verCiclos(node->getNodos(), graph);
                    cout <<"Madrid"<< endl;
                    cout << "Ciclo numero " << contador << endl;

                    presupuesto(node->getNodos(), graph);
                }
            }
        }
    }
}

bool isHamiltoniano(Node prueba, int graph[8][8]) {
    queue<Node*> toVisit;
    Node* node;
    vector<int> nodos;
    toVisit.push(&prueba);
    prueba.setVisited(prueba.getCity());

    while (!toVisit.empty()) {
        node = toVisit.front(); toVisit.pop();
        for (int i = 0; i < CANT; i++) {

            if (graph[node->getCity()][i] != INF && !node->isVisited(i)) {
                nodos = node->getNodos();
                nodos.push_back(i);
                Node* aux = new Node(i, node->getVisited(), nodos);
                aux->setVisited(i);
                node->putChild(aux);
                toVisit.push(aux);
            }
            else if (node->isVisited(i) && i==0) {
                int cont = 0;
                for (int j = 0; j < CANT; j++) {
                    if (node->getVisited()[j]) {
                        cont++;
                    }
                }
                if (cont == 8) return true;
            }
        }
    }
    return false;
}

int main() {
    int grafo[CANT][CANT] = { INF, INF, 210, INF, 300, INF, 350, 320,
                         INF, INF, 350, INF, 150, INF, 280, 250,
                         210, 350, INF, 100, INF, 120, INF, INF,
                         INF, INF, 100, INF, 200, 60, INF, INF,
                         300, 150, INF, 200, INF, 120, INF, 240,
                         INF, INF, 120, 60, 120, INF, 60, 80,
                         350, 280, INF, INF, INF, 60, INF, 60,
                         320, 250, INF, INF, 240, 80, 60, INF };

    

    bfs(0, grafo);
    cout << "\n\n\nEl recorrido optimo es ";
    for (int i = 0; i < CANT; i++) {
        cout << indexCities[optimo.first[i]] << " - ";
    }
    cout << "Madrid\nCon un costo de " << optimo.second << endl;


}