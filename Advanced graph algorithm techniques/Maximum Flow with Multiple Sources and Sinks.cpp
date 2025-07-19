// Assume existing max-flow code; add super-source and super-sink
// Add edges from super-source to all sources, and from all sinks to super-sink

// Pseudocode:
// for each source s: addEdge(superSource, s, INF)
// for each sink t: addEdge(t, superSink, INF)
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> capacity; // Capacity matrix
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V), capacity(V, vector<int>(V, 0)), adj(V) {}

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u); // For residual graph
    }

    int bfs(int s, int t, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v] && capacity[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    if (v == t) return true; // Found path to sink
                    q.push(v);
                }
            }
        }
        return false; // No path found
    }

    int fordFulkerson(int s, int t) {
        vector<int> parent(V);
        int maxFlow = 0;

        while (bfs(s, t, parent)) {
            int pathFlow = INF;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v]);
            }

            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                capacity[u][v] -= pathFlow;
                capacity[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }
        return maxFlow;
    }
};
