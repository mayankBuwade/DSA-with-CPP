//undirected graph:- unit distance :- shortest path
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    vector<int> shortestPath(int src, int dest);
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
                cout<<adjList[i][j]<<", ";
            }
            cout<<endl;
        }
}

vector<int> Graph::shortestPath(int src, int dest)
{
    int totalVertices = adjList.size();
    vector<bool> visited(totalVertices, false);
    vector<int> distance(totalVertices, INT_MAX);
    vector<int> parent(totalVertices, -1);
    queue<int> q;
    q.push(src);
    distance[src] = 0;
    visited[src] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(node == dest)
        {
            vector<int> path;
            while(node != -1)
            {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for(auto adjN:adjList[node])
        {
            if(!visited[adjN])
            {
                q.push(adjN);
                visited[adjN] = true;
                parent[adjN] = node;
                distance[adjN] = distance[node] + 1;
            }
        }

    }

    return {};

}


int main()
{
    system("cls");
    Graph g(5);
    vector<int> path;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    path = g.shortestPath(4, 1);

    for(auto node:path)
    {
        cout<<node<<" ";
    }

    return 0;
}