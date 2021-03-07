#include <iostream>
using namespace std;

#define INF 9999

class Graph
{
    int V;

public:
    int **dist;
    Graph(int V);
    void addEdge(int u, int v, int w);
    void floydWarshall(int **dist);
};

void Graph::floydWarshall(int **dist)
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    dist = new int *[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
}

void Graph::addEdge(int u, int v, int w)
{
    dist[u][v] = w;
}

int main()
{
    Graph G = Graph(4);
    G.addEdge(0, 1, 2);
    G.addEdge(0, 2, 5);
    G.addEdge(1, 0, 1);
    G.addEdge(1, 2, 2);
    G.addEdge(2, 3, -2);

    G.floydWarshall(G.dist);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++)
            printf("%d\t", G.dist[i][j]);
        printf("\n");
    }

    return 0;
}