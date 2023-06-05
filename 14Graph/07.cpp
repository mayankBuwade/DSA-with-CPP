//adjacency list
//DFS
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    void DFS_R(int, vector<bool>&);
    void DFS_L(int, vector<bool>&);
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    void DFS(int);
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

void Graph::DFS_R(int currV, vector<bool> &visited)
{
    visited[currV] = true;
    cout<<currV<<" ";
    for(auto adjV: adjList[currV])
    {
        if(!visited[adjV])
        {
            DFS_R(adjV, visited);
        }
    }
}

void Graph::DFS_L(int currV, vector<bool> &visited )
{
    stack<int> s;
    visited[currV];
    s.push(currV);
    while(!s.empty())
    {
        currV = s.top();
        s.pop();
        cout<<currV<<" ";

        for(int neighbor:adjList[currV])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}


void Graph::DFS(int currV)
{
    vector<bool> visited(adjList.size(), false);
    //DFS_R(currV, visited);
    DFS_L(currV, visited);
}





int main()
{
    system("cls");
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 6);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.printGraph();
    g.DFS(5);
    return 0;
}