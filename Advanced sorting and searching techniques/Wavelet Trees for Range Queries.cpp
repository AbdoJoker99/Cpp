#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int size) : tree(size + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

    int range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5}; // 1-indexed
    FenwickTree ft(5);
    for (int i = 1; i <= 5; ++i) ft.update(i, arr[i]);

    cout << "Sum [2..4]: " << ft.range(2, 4) << endl;
}
