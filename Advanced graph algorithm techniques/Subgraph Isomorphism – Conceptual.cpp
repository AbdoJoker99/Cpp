#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Check if submatrix of G formed by nodes in 'nodes' matches H
bool matches(const vector<vector<int>>& G, const vector<vector<int>>& H, const vector<int>& nodes) {
    int hSize = H.size();
    for (int i = 0; i < hSize; i++) {
        for (int j = 0; j < hSize; j++) {
            if (G[nodes[i]][nodes[j]] != H[i][j])
                return false;
        }
    }
    return true;
}

bool isSubgraph(const vector<vector<int>>& G, const vector<vector<int>>& H) {
    int gSize = G.size(), hSize = H.size();
    if (hSize > gSize) return false;

    vector<int> nodes(gSize);
    for (int i = 0; i < gSize; i++) nodes[i] = i;

    // Try all combinations of hSize nodes in G
    vector<bool> bitmask(gSize, false);
    fill(bitmask.begin(), bitmask.begin() + hSize, true);

    do {
        vector<int> subset;
        for (int i = 0; i < gSize; ++i)
            if (bitmask[i]) subset.push_back(i);

        if (matches(G, H, subset)) return true;

    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    return false;
}
int main() {
    vector<vector<int>> G = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    vector<vector<int>> H = {
        {0, 1},
        {1, 0}
    };

    if (isSubgraph(G, H)) {
        cout << "H is a subgraph of G." << endl;
    } else {
        cout << "H is not a subgraph of G." << endl;
    }

    return 0;
}