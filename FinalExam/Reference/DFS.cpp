#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct node
{
    bool visited = false;
    int startTime, finishTime;
    vector<node *> neighbors;
};

class Graph
{
    int V; // No. of vertices
    set<node *> visited;

public:
    vector<node *> linkedList;
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    int DFS(node *w, int currentTime);
};

int Graph::DFS(node *w, int currentTime)
{
    w->startTime = currentTime;
    w->visited = true;
    printf("node: %p, startTime %d\n", w, w->startTime);
    ++currentTime;

    vector<node *>::iterator i;
    for (i = w->neighbors.begin(); i != w->neighbors.end(); i++)
    {
        if ((*i)->visited == false)
        {
            currentTime = DFS(*i, currentTime);
            ++currentTime;
        }
    }
    w->finishTime = currentTime;
    printf("node: %p, finishTime %d\n", w, w->finishTime);
    return currentTime;
}

Graph::Graph(int V)
{
    for (int i = 0; i < V; i++)
    {
        node *temp = new node;
        linkedList.push_back(temp);
    }
}

void Graph::addEdge(int u, int v)
{
    linkedList[u]->neighbors.push_back(linkedList[v]);
    linkedList[v]->neighbors.push_back(linkedList[u]);
}

int main()
{
    Graph G = Graph(5);
    G.addEdge(1, 2);
    G.addEdge(0, 4);
    G.addEdge(4, 2);
    G.addEdge(2, 3);
    G.DFS(G.linkedList[0], 0);

    return 0;
}