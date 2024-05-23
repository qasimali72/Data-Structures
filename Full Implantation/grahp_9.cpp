/*

Convert undirected connected graph to strongly connected directed graph
Input: N = 5, Edges[][] = { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 1, 4 }, { 2, 3 }, { 3, 4 } } 
Output: 
0->1 
2->0 
4->1 
3->4 
2->3 
1->2 



*/



#include <bits/stdc++.h>
using namespace std;

// To store the assigned Edges
vector<pair<int, int> > ans;

// Flag variable to check Bridges
int flag = 1;

// Function to implement DFS Traversal
int dfs(vector<int> adj[],
		int* order, int* bridge_detect,
		bool* mark, int v, int l)
{

	// Mark the current node as visited
	mark[v] = 1;

	// Update the order of node v
	order[v] = order[l] + 1;

	// Update the bridge_detect for node v
	bridge_detect[v] = order[v];

	// Traverse the adjacency list of
	// Node v
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i];

		// Ignores if same edge is traversed
		if (u == l) {
			continue;
		}

		// Ignores the edge u --> v as
		// v --> u is already processed
		if (order[v] < order[u]) {
			continue;
		}

		// Finds a back Edges, cycle present
		if (mark[u]) {

			// Update the bridge_detect[v]
			bridge_detect[v]
				= min(order[u],
					bridge_detect[v]);
		}

		// Else DFS traversal for current
		// node in the adjacency list
		else {

			dfs(adj, order, bridge_detect,
				mark, u, v);
		}

		// Update the bridge_detect[v]
		bridge_detect[v]
			= min(bridge_detect[u],
				bridge_detect[v]);

		// Store the current directed Edge
		ans.push_back(make_pair(v, u));
	}

	// Condition for Bridges
	if (bridge_detect[v] == order[v]
		&& l != 0) {
		flag = 0;
	}

	// Return flag
	return flag;
}

// Function to print the direction
// of edges to make graph SCCs
void convert(vector<int> adj[], int n)
{

	// Arrays to store the visited,
	// bridge_detect and order of
	// Nodes
	int order[n] = { 0 };
	int bridge_detect[n] = { 0 };
	bool mark[n];

	// Initialise marks[] as false
	memset(mark, false, sizeof(mark));

	// DFS Traversal from vertex 1
	int flag = dfs(adj, order,
				bridge_detect,
				mark, 1, 0);

	// If flag is zero, then Bridge
	// is present in the graph
	if (flag == 0) {
		cout << "-1";
	}

	// Else print the direction of
	// Edges assigned
	else {
		for (auto& it : ans) {
			cout << it.first << "->"
				<< it.second << '\n';
		}
	}
}

// Function to create graph
void createGraph(int Edges[][2],
				vector<int> adj[],
				int M)
{

	// Traverse the Edges
	for (int i = 0; i < M; i++) {

		int u = Edges[i][0];
		int v = Edges[i][1];

		// Push the edges in an
		// adjacency list
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

// Driver Code
int main()
{
	// N vertices and M Edges
	int N = 5, M = 6;
	int Edges[M][2]
		= { { 0, 1 }, { 0, 2 },
			{ 1, 2 }, { 1, 4 },
			{ 2, 3 }, { 3, 4 } };

	// To create Adjacency List
	vector<int> adj[N];

	// Create an undirected graph
	createGraph(Edges, adj, M);

	// Function Call
	convert(adj, N);
	return 0;
}

