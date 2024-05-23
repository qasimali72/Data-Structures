/*

Count number of edges in an undirected graph

Input : Adjacency list representation of
        below graph.  
Output : 9



*/

// C++ program to count number of edge in
// undirected graph
#include<bits/stdc++.h>
using namespace std;

// Adjacency list representation of graph
class Graph
{
	int V ;
	list < int > *adj;
public :
	Graph( int V )
	{
		this->V = V ;
		adj = new list<int>[V];
	}
	void addEdge ( int u, int v ) ;
	int countEdges () ;
};

// add edge to graph
void Graph :: addEdge ( int u, int v )
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Returns count of edge in undirected graph
int Graph :: countEdges()
{
	int sum = 0;

	//traverse all vertex
	for (int i = 0 ; i < V ; i++)

		// add all edge that are linked to the
		// current vertex
		sum += adj[i].size();


	// The count of edge is always even because in
	// undirected graph every edge is connected
	// twice between two vertices
	return sum/2;
}

// driver program to check above function
int main()
{
	int V = 9 ;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1 );
	g.addEdge(0, 7 );
	g.addEdge(1, 2 );
	g.addEdge(1, 7 );
	g.addEdge(2, 3 );
	g.addEdge(2, 8 );
	g.addEdge(2, 5 );
	g.addEdge(3, 4 );
	g.addEdge(3, 5 );
	g.addEdge(4, 5 );
	g.addEdge(5, 6 );
	g.addEdge(6, 7 );
	g.addEdge(6, 8 );
	g.addEdge(7, 8 );

	cout << g.countEdges() << endl;

	return 0;
}

