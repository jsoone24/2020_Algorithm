#include <iostream>
#include <list>
#include <queue>
#include <set>
using namespace std;

#define INF 999999999

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
    set<pair<int, int>> setds;
    vector<int> dist(V, INF); //V 크기의 벡터만들고 INF로 초기화 한다는 뜻

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
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
    G.addEdge(0, 2, 25);
    G.addEdge(1, 3, 1);
    G.addEdge(1, 2, 22);
    G.addEdge(2, 1, 22);
    G.addEdge(2, 0, 25);
    G.addEdge(2, 4, 20);
    G.addEdge(3, 4, 4);
    G.addEdge(4, 3, 4);
    G.addEdge(4, 2, 20);

    G.shortestPath(0);

    return 0;
}