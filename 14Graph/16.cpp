//Dijkstra's algorithm using a priority queue

//undirected graph:- unit distance :- shortest path
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
public:
    Graph(int);
    void addEdge(int, int, int);
    void printGraph();
    void shortesDistance(int);
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

void Graph::shortesDistance(int start)
{
    int size = adjList.size();
    vector<int> distance(size, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        for(auto &neighbor: adjList[currentNode])
        {
            int currNeighbor = neighbor.first;
            int currNeighborW = neighbor.second;

            int newDistance = currentDistance + currNeighborW;

            if(newDistance<distance[currNeighbor])
            {
                distance[currNeighbor] = newDistance;
                pq.push({newDistance, currNeighbor});
            }
        }
    }

    for(int i = 1; i<size; i++)
    {
        cout<<start<<"->"<<i<<":- "<<distance[i]<<endl;
    }

}

int main()
{
    Graph g(5);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 4, 20);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 2);
    g.shortesDistance(1);
    return 0;
}