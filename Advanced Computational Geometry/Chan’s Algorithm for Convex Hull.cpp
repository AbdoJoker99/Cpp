#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;

int orientation(Point a, Point b, Point c) {
    int val = (b.second - a.second) * (c.first - b.first) -
              (b.first - a.first) * (c.second - b.second);
    return val == 0 ? 0 : (val > 0 ? 1 : 2); // colinear/clockwise/counterclockwise
}

vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size();
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());

    vector<Point> hull;
    for (int i = 0; i < 2; i++) {
        int start = hull.size();
        for (auto p : pts) {
            while (hull.size() >= start + 2 &&
                   orientation(hull[hull.size() - 2], hull.back(), p) != 2)
                hull.pop_back();
            hull.push_back(p);
        }
        reverse(pts.begin(), pts.end());
        hull.pop_back();
    }
    return hull;
}
int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {1, 0}, {0, 1}, {2, 0}, {0, 2}};
    vector<Point> hull = convexHull(points);

    cout << "Convex Hull Points:\n";
    for (auto p : hull) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    return 0;
}