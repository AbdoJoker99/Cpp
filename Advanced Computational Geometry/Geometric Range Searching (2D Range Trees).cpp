#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

struct RangeTree2D {
    struct Node {
        int x;
        vector<int> yList;      // All y-values in subtree rooted at this node, sorted
        vector<Point> points;   // Actual (x,y) pairs in this subtree
        Node* left;
        Node* right;

        Node(int x_) : x(x_), left(nullptr), right(nullptr) {}
    };

    Node* root;

    RangeTree2D() : root(nullptr) {}

    // Helper to insert a point into the BST and build yList
    Node* insert(Node* node, Point pt) {
        if (!node) {
            Node* newNode = new Node(pt.first);
            newNode->points.push_back(pt);
            newNode->yList.push_back(pt.second);
            return newNode;
        }

        if (pt.first < node->x)
            node->left = insert(node->left, pt);
        else
            node->right = insert(node->right, pt);

        node->points.push_back(pt);
        node->yList.push_back(pt.second);
        return node;
    }

    void build() {
        buildRecursive(root);
    }

    void buildRecursive(Node* node) {
        if (!node) return;
        sort(node->yList.begin(), node->yList.end());
        buildRecursive(node->left);
        buildRecursive(node->right);
    }

    void insert(int x, int y) {
        root = insert(root, {x, y});
    }

    // Query helper: collects points with x in [xmin, xmax] and y in [ymin, ymax]
    void query(Node* node, int xmin, int xmax, int ymin, int ymax, vector<Point>& result) {
        if (!node) return;

        if (node->x >= xmin && node->x <= xmax) {
            // Search node->points for those within y-range using yList
            auto lo = lower_bound(node->yList.begin(), node->yList.end(), ymin);
            auto hi = upper_bound(node->yList.begin(), node->yList.end(), ymax);
            for (Point pt : node->points) {
                if (pt.first >= xmin && pt.first <= xmax &&
                    pt.second >= ymin && pt.second <= ymax) {
                    result.push_back(pt);
                }
            }
        }

        if (node->x > xmin)
            query(node->left, xmin, xmax, ymin, ymax, result);
        if (node->x < xmax)
            query(node->right, xmin, xmax, ymin, ymax, result);
    }

    vector<Point> query(int xmin, int xmax, int ymin, int ymax) {
        vector<Point> res;
        query(root, xmin, xmax, ymin, ymax, res);
        return res;
    }
};

int main() {
    RangeTree2D tree;

    // Insert points
    tree.insert(5, 5);
    tree.insert(2, 3);
    tree.insert(8, 7);
    tree.insert(6, 4);
    tree.insert(3, 6);
    tree.insert(7, 2);
    tree.insert(9, 8);

    // Build y-lists at each node after all insertions
    tree.build();

    // Perform a range query
    int xmin = 2, xmax = 7, ymin = 2, ymax = 6;
    vector<Point> results = tree.query(xmin, xmax, ymin, ymax);

    cout << "Points in range [x: " << xmin << " to " << xmax << "], [y: " << ymin << " to " << ymax << "]\n";
    for (auto [x, y] : results) {
        cout << "(" << x << ", " << y << ")\n";
    }

    return 0;
}
