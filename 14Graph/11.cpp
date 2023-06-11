//Topological Sort:- DFS
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    void dfsHelperTopoSort(int node, vector<bool> &visited, stack<int> &order);

public:
    Graph(int);
    void addEdge(int, int);
    void printGraph();
    vector<int> topoSort();
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

void Graph::dfsHelperTopoSort(int node, vector<bool> &visited, stack<int> &order)
{
    visited[node] = true;
    for(auto adjN : adjList[node])
    {
        if(!visited[adjN])
        {
            dfsHelperTopoSort(adjN, visited, order);
        }
    }
    order.push(node);
}

vector<int> Graph::topoSort()
{
    int size = adjList.size();
    vector<bool> visited(size, false);
    vector<int> sortedList;
    stack<int> order;
    for(int i = 1; i<size; i++ )
    {
        if(!visited[i])
        {
            dfsHelperTopoSort(i, visited, order);
        }
    }

    while(!order.empty())
    {
        sortedList.push_back(order.top());
        order.pop();
    }

    return sortedList;

}


int main()
{
    system("cls");
    Graph g(6);
    vector<int> result;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    result = g.topoSort();
    for(int i = 0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
