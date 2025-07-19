#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
const int V = 4;

void floydWarshall(vector<vector<int>>& dist) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);

    for (auto row : graph) {
        for (auto val : row)
            cout << (val == INF ? "INF" : to_string(val)) << " ";
        cout << endl;
    }
    return 0;
}
