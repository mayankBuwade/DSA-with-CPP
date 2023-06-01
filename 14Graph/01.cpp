//graph representations:- Adjacency Matrix
#include<iostream>

using namespace std;

class Graph {
private:
    int **matrix;
    int numVertices;
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    matrix = new int*[numVertices+1];
    for(int i = 0; i<numVertices+1; i++)
    {
        matrix[i] = new int[numVertices+1];
    }
    for(int i = 0; i<numVertices+1; i++)
    {
        for(int j = 0; j<numVertices+1; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int src, int dest)
{
    //undirected
    matrix[src][dest] = 1;
    matrix[dest][src] = 1;
}

void Graph::printGraph()
{
    for(int i = 1; i<numVertices+1; i++)
    {
        printf("Vertex:- %d:- ", i);
        for(int j = 1; j<numVertices+1; j++)
        {
            if(matrix[i][j] != 0)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    system("cls");
    Graph g(5);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.printGraph();
    return 0;
}