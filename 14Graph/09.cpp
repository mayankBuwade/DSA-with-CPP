//check cycle undirected:- DFS

#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    bool dfsDetectCycleHelper(int, vector<bool>&);
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
    stack<pair<int, int>> s;
    s.push({src, -1});
    while (!s.empty())
    {
        int node = s.top().first;
        int parent = s.top().second;
        s.pop();
        for(auto adjN:adjList[node])
        {
            if(adjN != parent && !visited[adjN])
            {
                s.push({adjN, node});
                visited[adjN] = true;
            }
            else if(adjN != parent && visited[adjN])
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
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    cout<<g.haveCycle(1);
    return 0;
}