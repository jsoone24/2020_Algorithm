#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int V; // No. of vertices
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w);
    void BFS(int s);
};

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // Create a queue for BFS
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    for (int i = 0; i < V; i++)
    {
        list<int> t;
        adj.push_back(t);
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int main()
{
    Graph G = Graph(7);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(2, 5);
    G.addEdge(3, 4);
    G.addEdge(3, 6);
    G.addEdge(4, 3);
    G.addEdge(4, 2);
    G.addEdge(4, 6);
    G.addEdge(5, 2);
    G.addEdge(5, 6);
    G.addEdge(6, 3);
    G.addEdge(6, 4);
    G.addEdge(6, 5);

    G.BFS(0);

    return 0;
}