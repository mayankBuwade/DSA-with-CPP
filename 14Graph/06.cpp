//adjacency list
//BFS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    void BFS(int);
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

void Graph::BFS(int startVertex)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);
    while (!q.empty())
    {
        int currV = q.front();
        q.pop();
        cout<<currV<<" ";

        for(auto ele:adjList[currV])
        {
            if(!visited[ele])
            {
                q.push(ele);
                visited[ele] = true;
            }
        }

    }
    
}

int main()
{
    system("cls");
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(5, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 4);
    //g.printGraph();
    g.BFS(4);
    return 0;
}