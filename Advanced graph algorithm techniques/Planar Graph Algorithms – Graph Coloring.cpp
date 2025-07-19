#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void greedyColoring(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> result(V, -1);
    result[0] = 0;

    for (int u = 1; u < V; u++) {
        vector<bool> used(V, false);
        for (int v : graph[u])
            if (result[v] != -1)
                used[result[v]] = true;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (!used[cr]) break;

        result[u] = cr;
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    greedyColoring(graph);
}
