#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

struct Segment {
    Point p1, p2;
};

bool onSegment(Point p, Point q, Point r) {
    return q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
           q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second);
}

// 0 --> colinear
// 1 --> clockwise
// 2 --> counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; // p2 lies on p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; // q2 lies on p1q1
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; // p1 lies on p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; // q1 lies on p2q2

    return false;
}
