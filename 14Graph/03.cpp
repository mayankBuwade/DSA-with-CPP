#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int numVertices;

public:
    Graph(int n) {
        this->numVertices = n;
        adjacencyMatrix.resize(numVertices+1, vector<int>(numVertices+1, INT_MAX));
        for (int i = 0; i < numVertices+1; ++i) {
            adjacencyMatrix[i][i] = 0;  // Initialize diagonal elements as 0 (self-loops)
        }
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight;
        // For an undirected graph, uncomment the following line
        adjacencyMatrix[destination][source] = weight;
    }

    void printGraph() {
        for(int i = 1; i<numVertices+1; i++)
        {
            printf("Vertex:- %d:- ", i);
            for(int j = 1; j<numVertices+1; j++)
            {
                if(adjacencyMatrix[i][j] != INT_MAX)
                {
                    cout<<"( "<<j<<", "<<adjacencyMatrix[i][j]<<" ), ";
                }
            }
            cout<<endl;
        }
    }
};

int main() {
    system("cls");
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 5, 1);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 5);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 5, 7);

    graph.printGraph();

    return 0;
}
