#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
	int src, dest, weight;
};

class Graph
{
public:
	int V, E;

	Edge *edge;
};

Graph *createGraph(int V, int E)
{
	Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

class subset
{
public:
	int parent;
	int rank;
};

int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

bool cmp(const Edge &p1, const Edge &p2)
{
	if (p1.weight < p2.weight)
	{
		return true;
	}
	else if (p1.weight == p2.weight)
	{
		return p1.src < p2.src;
	}
	else
	{
		return false;
	}
}

void KruskalMST(Graph *graph)
{
	int V = graph->V;
	Edge *result = (Edge *)malloc(sizeof(Edge) * V);
	int e = 0;
	int i = 0;

	for (int i = 0; i < graph->E; i++)
	{
		std::cout << "edge dest: " << graph->edge[i].dest << endl;
		std::cout << "edge src: " << graph->edge[i].src << endl;
		std::cout << "edge weight: " << graph->edge[i].weight << endl;
		cout << endl;
	}

	std::cout << sizeof(graph->edge[0]) << endl;

	//qsort(graph->edge, graph->E, sizeof(graph->edge[0]) ,myComp);
	sort(graph->edge, graph->edge + 14, cmp);

	cout << " sorted  " << endl;
	for (int i = 0; i < graph->E; i++)
	{
		std::cout << "edge dest : " << graph->edge[i].dest << endl;
		std::cout << "edge src : " << graph->edge[i].src << endl;
		std::cout << "edge weight : " << graph->edge[i].weight << endl;
		cout << endl;
	}

	subset *subsets = new subset[(V * sizeof(subset))];

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E)
	{
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	cout << "Following are the edges in the constructed "
			"MST\n";
	int minimumCost = 0;
	for (i = 0; i < e; ++i)
	{
		cout << result[i].src << " -- " << result[i].dest
			 << " == " << result[i].weight << endl;
		minimumCost = minimumCost + result[i].weight;
	}
	cout << "Minimum Cost Spanning Tree: " << minimumCost
		 << endl;
}

// Driver code
int main()
{
	int V = 9;	// Number of vertices in graph
	int E = 14; // Number of edges in graph
	Graph *graph = createGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 4;

	// add edge 0-7
	graph->edge[1].src = 0;
	graph->edge[1].dest = 7;
	graph->edge[1].weight = 8;

	// add edge 1-2
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 8;

	// add edge 1-7
	graph->edge[3].src = 1;
	graph->edge[3].dest = 7;
	graph->edge[3].weight = 11;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 7;

	//add edge 2-5
	graph->edge[5].src = 2;
	graph->edge[5].dest = 5;
	graph->edge[5].weight = 4;

	//add edge 2-8
	graph->edge[6].src = 2;
	graph->edge[6].dest = 8;
	graph->edge[6].weight = 2;

	//add edge 3-4
	graph->edge[7].src = 3;
	graph->edge[7].dest = 4;
	graph->edge[7].weight = 9;

	//add edge 3-5
	graph->edge[8].src = 3;
	graph->edge[8].dest = 5;
	graph->edge[8].weight = 14;

	//add edge 4-5
	graph->edge[9].src = 4;
	graph->edge[9].dest = 5;
	graph->edge[9].weight = 10;

	//add edge 5-6
	graph->edge[10].src = 5;
	graph->edge[10].dest = 6;
	graph->edge[10].weight = 2;

	//add edge 6-7
	graph->edge[11].src = 6;
	graph->edge[11].dest = 7;
	graph->edge[11].weight = 1;

	//add edge 6-8
	graph->edge[12].src = 6;
	graph->edge[12].dest = 8;
	graph->edge[12].weight = 6;

	//add edge 6-8
	graph->edge[13].src = 7;
	graph->edge[13].dest = 8;
	graph->edge[13].weight = 7;

	// Function call
	KruskalMST(graph);

	return 0;
}

// This code is contributed by rathbhupendra
