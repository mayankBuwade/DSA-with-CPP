//check cycle directed
//DFS
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    bool dfsCheckCycle(vector<bool> &, vector<bool> &, int );
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    bool haveCycle(int);
};

Graph::Graph(int numOfVertices)
{
    adjList.resize(numOfVertices+1);
}

void Graph::addEdge(int src, int dest)
{
    adjList[src].push_back(dest);
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


bool Graph::dfsCheckCycle( vector<bool> &visited,  vector<bool>& pathFollowed, int node)
{
    visited[node] = true;
    pathFollowed[node] = true;
    for(auto adjN:adjList[node])
    {
        if(!visited[adjN] && dfsCheckCycle(visited, pathFollowed, adjN))
        {
            return true;
        }
        else if(pathFollowed[adjN])
        {
            return true;
        }
    }
    pathFollowed[node] = false;
    return false;
}

bool Graph::haveCycle(int src)
{
    int size = adjList.size();
    vector<bool> visited(size, false);
    vector<bool> pathFollowed(size, false);
    return dfsCheckCycle(visited, pathFollowed, src);
}



int main()
{
    system("cls");
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(3, 1);

    cout<<g.haveCycle(2);
    return 0;
}