#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>
using namespace std;

class Graph
{
    int V; // No. of vertices
    list<pair<int, int>> *adj;
    vector<set<int>> listSet;

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v, int w);
    list<pair<int, int>> slowKruskal(int V, list<pair<int, int>> *adj);
    void makeSet(int u);      //create a set {u}
    set<int> *find(int u);    //return the set that u is in
    void unify(int u, int v); //merge the set that u is in with the set that v is in.
};

void Graph::makeSet(int u)
{
    set<int> t;
    t.insert(u);
    listSet.push_back(t);
}

set<int> *Graph::find(int u)
{
    vector<set<int>>::iterator it;
    for (it = listSet.begin(); it != listSet.end(); it++)
    {
        set<int>::iterator iter;
        iter = (*it).find(u);
        if (iter != (*it).end())
            return &(*it);
    }
}

void Graph::unify(int u, int v)
{
    vector<set<int>>::iterator it, itU, itV;

    for (it = listSet.begin(); it != listSet.end(); it++)
    {
        set<int>::iterator iter;
        iter = (*it).find(u);
        if (iter != (*it).end())
            itU = it;

        iter = (*it).find(v);
        if (iter != (*it).end())
            itV = it;
    }

    for(set<int>::iterator iter = (*itV).begin();iter != (*itV).end();iter++)
        (*itU).insert((*iter));

    listSet.erase(itV);
}

list<pair<int, int>> Graph::slowKruskal(int V, list<pair<int, int>> *adj)
{
    list<pair<int, int>> MST;
    list<pair<int, int>>::iterator it;

    for (int i = 0; i < V; i++)
        makeSet(i);

    for (it = (*adj).begin(); it != (*adj).end(); it++)
    {
        int u = (*it).first, v = (*it).second;
        if (find(u) != find(v)) // if u and v are not in the same tree
        {
            MST.push_back(*it);
            unify(u, v); // merge u’s tree with v’s tree
        }
    }

    return MST;
}