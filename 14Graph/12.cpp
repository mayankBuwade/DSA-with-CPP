//Topological Sort:- Kahn's algo
//it can also check if cycle is present in a graph or not
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


vector<int> Graph::topoSort()
{
    int size = adjList.size();
    vector<int> sortedList;
    queue<int> q;
    vector<int> inDegree(size, 0);
    for(int i = 1; i<size; i++)
    {
        for(auto adjN : adjList[i])
        {
            ++inDegree[adjN];
        }
    }

    for(int i = 1; i<size; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int currN = q.front();
        q.pop();
        sortedList.push_back(currN);
        for(auto adjN: adjList[currN])
        {
            --inDegree[adjN];
            if(inDegree[adjN] == 0)
            {
                q.push(adjN);
            }
        }
    }
    
    if(sortedList.size() != adjList.size() -1)
    {
        sortedList.clear();
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
    g.addEdge(3, 4);
    result = g.topoSort();
    if(result.size() == 0)
    {
        cout<<"cycle detected"<<endl;
    }
    else
    {
        for(int i = 0; i<result.size(); i++)
        {
            cout<<result[i]<<" ";
        }
    }
    
    return 0;
}
