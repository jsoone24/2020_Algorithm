#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<list<int>> adj;
    void DFS(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

void Graph::DFS(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited, Stack);

    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFS(i, visited, Stack);
        }
    }

    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
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
    Graph G = Graph(6);
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(0, 4);
    G.addEdge(0, 5);
    G.addEdge(0, 3);
    G.addEdge(4, 1);
    G.addEdge(4, 2);

    G.topologicalSort();

    return 0;
}