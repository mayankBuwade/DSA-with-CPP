//directed graph:- weight :- shortest distance:- topo sort

#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
    void topoSortUtil(vector<bool> &visited, int node, stack<int> &s);
public:
    Graph(int);
    void addEdge(int, int, int);
    void printGraph();
    void shortestPathDAC(int, int);
};

Graph::Graph(int numOfVertices)
{
    adjList.resize(numOfVertices+1);
}

void Graph::addEdge(int src, int dest, int weight)
{
    adjList[src].push_back(make_pair(dest, weight));
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

void Graph::topoSortUtil(vector<bool> &visited, int node, stack<int> &s)
{
    visited[node] = true;
    for(auto adjN : adjList[node])
    {
        if(!visited[adjN.first])
        {
            topoSortUtil(visited, adjN.first, s);
        }
    }
    s.push(node);
}

void Graph::shortestPathDAC(int src, int dest)
{
    int numVertices = adjList.size();
    vector<bool> visited(numVertices, false);
    stack<int> s;
    vector<int> dist(numVertices, INT_MAX);

    //applying topo sort
    for(int i = 1; i<numVertices; i++)
    {
        if(!visited[i]);
        {
            topoSortUtil(visited, i, s);
        }
    }

    //set distance of source 
    dist[src] = 0;

    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(dist[node] != INT_MAX)
        {
            cout<<node<<" ";
            for(auto adjV:adjList[node])
            {
                if(dist[node] + adjV.second < dist[adjV.first])
                {
                    dist[adjV.first] = dist[node] + adjV.second;
                }
            }
        }
    }

    //print shortest distance
    for(int i = 1; i<numVertices; i++)
    {
        cout<<"Source "<<src<<" current vertice "<<i<<" distance ";
        if(dist[i] == INT_MAX)
        {
            cout<<"Infinity";
        }
        else
        {
            cout<<dist[i];
        }
        cout<<endl;
    }
}

int main()
{
    system("cls");
    Graph g(5);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 5, 3);
    g.addEdge(5, 2, 1);
    g.addEdge(5, 3, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 7);
    g.shortestPathDAC(1, 4);
    return 0;
}