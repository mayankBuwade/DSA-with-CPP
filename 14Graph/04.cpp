//adjacency list
#include<iostream>
#include<vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
};

Graph::Graph(int numOfVertices)
{
    adjList.resize(numOfVertices+1);
}

void Graph::addEdge(int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void Graph::printGraph()
{
    for(int i = 1; i<adjList.size(); i++)
        {
            cout<<"Vertex "<<i<<":- ";
            for(int j = 0; j<adjList[i].size(); j++)
            {
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl;
        }
}

int main()
{
    system("cls");
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(2, 3);
    g.printGraph();
    return 0;
}