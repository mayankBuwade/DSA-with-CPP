//adjacency list:- weight
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
public:
    Graph(int);
    void addEdge(int, int, int);
    void printGraph();
};

Graph::Graph(int numOfVertices)
{
    adjList.resize(numOfVertices+1);
}

void Graph::addEdge(int src, int dest, int weight)
{
    adjList[src].push_back(make_pair(dest, weight));
    adjList[dest].push_back(make_pair(src, weight));
}

void Graph::printGraph()
{
    for(int i = 1; i<adjList.size(); i++)
        {
            cout<<"Vertex "<<i<<":- ";
            for(int j = 0; j<adjList[i].size(); j++)
            {
                cout<<"( "<<adjList[i][j].first<<", "<<adjList[i][j].second<<" ), ";
            }
            cout<<endl;
        }
}

int main()
{
    system("cls");
    Graph g(4);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(4, 1, 65);
    g.addEdge(4, 3, 90);
    g.addEdge(2, 3, 80);
    g.printGraph();
    return 0;
}