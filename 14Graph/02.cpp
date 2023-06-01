//graph representations:- Adjacency Matrix
//with weight
#include<iostream>
#include<limits>

using namespace std;

class Graph {
private:
    int **matrix;
    int numVertices;
public:
    Graph(int);
    void addEdge(int, int, int);
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
            matrix[i][j] = INT_MAX;
        }
    }
}

void Graph::addEdge(int src, int dest, int weight)
{
    //undirected
    matrix[src][dest] = weight;
    matrix[dest][src] = weight;
}

void Graph::printGraph()
{
    for(int i = 1; i<numVertices+1; i++)
    {
        printf("Vertex:- %d:- ", i);
        for(int j = 1; j<numVertices+1; j++)
        {
            if(matrix[i][j] != INT_MAX)
            {
                cout<<"( "<<j<<", "<<matrix[i][j]<<" ), ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    system("cls");
    Graph g(5);
    g.addEdge(5, 1, 20);
    g.addEdge(5, 2, 30);
    g.addEdge(5, 3, 10);
    g.addEdge(1, 2, 90);
    g.addEdge(1, 3, 75);
    g.addEdge(4, 1, 15);
    g.printGraph();
    return 0;
}