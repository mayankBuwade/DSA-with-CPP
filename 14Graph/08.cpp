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
    bool haveCycle(int);
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



bool Graph::haveCycle(int src)
{
    int size = adjList.size();
    vector<bool> visited(size, false);
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = true;
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto ele:adjList[node])
        {
            if(ele != parent && !visited[ele])
            {
                q.push({ele, node});
                visited[ele] = true;
            }
            else if(ele != parent && visited[ele])
            {
                return true;
            }
        }
    }
    return false;
}



int main()
{
    system("cls");
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    cout<<g.haveCycle(1);
    return 0;
}