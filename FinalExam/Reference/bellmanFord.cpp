#include <iostream>
#include <list>
#include <queue>
#include <set>
using namespace std;

#define INF 999

class Graph
{
    int V;
    vector<list<pair<int, int>>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};

void Graph::shortestPath(int src)
{
    vector<int> dist(V, INF);
    // Insert source itself in Set and initialize its distance as 0.
    dist[src] = 0;

    for (int k = 0; k < V; k++)
        printf("%d\t", dist[k]);
    printf("\n");

    for (int u = 0; u < V-2; u++)
    {
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[u] != INF && dist[v] > dist[u] + weight)
                dist[v] = dist[u] + weight;
        }
        for (int k = 0; k < V; k++)
            printf("%d\t", dist[k]);
        printf("\n");
    }

    for (int u = 0; u < V; u++)
    {
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[u] != INF && dist[v] > dist[u] + weight)
            {
                printf("NEGATIVE CYCLE\n");
                return;
            }
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++)
    {
        list<pair<int, int>> t;
        adj.push_back(t);
    }
}

void Graph::addEdge(int u, int v, int w)
{
    pair<int, int> t;
    t.first = v;
    t.second = w;
    adj[u].push_back(t);
}

int main()
{
    Graph G = Graph(5);
    G.addEdge(0, 1, 1);
    G.addEdge(0, 2, -4);
    G.addEdge(1, 0, 1);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 3);
    G.addEdge(2, 0, -4);
    G.addEdge(2, 1, 2);
    G.addEdge(2, 3, 8);
    G.addEdge(3, 1, 3);
    G.addEdge(3, 2, 8);
    G.addEdge(3, 4, 9);
    G.addEdge(4, 3, 9);

    G.shortestPath(0);

    return 0;
}