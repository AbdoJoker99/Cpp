#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int start, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{2, 1}, {3, 7}};
    adj[2] = {{4, 3}};
    adj[3] = {{4, 1}};

    vector<int> dist(n, INF);
    dijkstra(0, adj, dist);

    for (int i = 0; i < n; i++)
        cout << "Dist to " << i << ": " << dist[i] << endl;
}
