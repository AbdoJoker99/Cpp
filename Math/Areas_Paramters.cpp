#include <iostream>  // For input/output streams (cout, cin)
#include <cmath>     // For math functions like sqrt() and tan()

using namespace std;

// ================================
// Triangle - using 3 sides (Heron's formula)
// Time Complexity: O(1) constant time calculation,
// as it involves only arithmetic operations and sqrt.
// Space Complexity: O(1) no extra memory allocation.
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0; // semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Perimeter is a simple sum of sides
// Time Complexity: O(1)
// Space Complexity: O(1)
double trianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

// ================================
// Rectangle Area = length * width
// Time Complexity: O(1)
// Space Complexity: O(1)
double rectangleArea(double length, double width) {
    return length * width;
}

// Perimeter = 2 * (length + width)
// Time Complexity: O(1)
// Space Complexity: O(1)
double rectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

// ================================
// Square Area = side^2
// Time Complexity: O(1)
// Space Complexity: O(1)
double squareArea(double side) {
    return side * side;
}

// Perimeter = 4 * side
// Time Complexity: O(1)
// Space Complexity: O(1)
double squarePerimeter(double side) {
    return 4 * side;
}

// ================================
// Parallelogram Area = base * height
// Time Complexity: O(1)
// Space Complexity: O(1)
double parallelogramArea(double base, double height) {
    return base * height;
}

// Perimeter = 2 * (base + side)
// Time Complexity: O(1)
// Space Complexity: O(1)
double parallelogramPerimeter(double base, double side) {
    return 2 * (base + side);
}

// ================================
// Trapezoid Area = ((a + b)/2) * height
// Time Complexity: O(1)
// Space Complexity: O(1)
double trapezoidArea(double a, double b, double height) {
    return ((a + b) / 2.0) * height;
}

// Perimeter = sum of all sides
// Time Complexity: O(1)
// Space Complexity: O(1)
double trapezoidPerimeter(double a, double b, double c, double d) {
    return a + b + c + d;
}

// ================================
// Regular Polygon
// Area = (n * s^2) / (4 * tan(pi / n))
// Perimeter = n * s
// Note: tan() uses radians, M_PI from <cmath> is π constant
// Time Complexity: O(1), involves basic arithmetic and trig functions
// Space Complexity: O(1)
double regularPolygonArea(int n, double side) {
    return (n * side * side) / (4.0 * tan(M_PI / n));
}

double regularPolygonPerimeter(int n, double side) {
    return n * side;
}

// ================================

int main() {
    cout << "Polygon Area and Perimeter Calculator\n";

    // Example usage with constant values - all computations are O(1)

    // Triangle
    double a = 3, b = 4, c = 5;
    cout << "\nTriangle (sides 3,4,5):\n";
    cout << "Area = " << triangleArea(a, b, c) << "\n";
    cout << "Perimeter = " << trianglePerimeter(a, b, c) << "\n";

    // Rectangle
    double length = 5, width = 10;
    cout << "\nRectangle (length 5, width 10):\n";
    cout << "Area = " << rectangleArea(length, width) << "\n";
    cout << "Perimeter = " << rectanglePerimeter(length, width) << "\n";

    // Square
    double side = 4;
    cout << "\nSquare (side 4):\n";
    cout << "Area = " << squareArea(side) << "\n";
    cout << "Perimeter = " << squarePerimeter(side) << "\n";

    // Parallelogram
    double base = 6, height = 3, sideLength = 5;
    cout << "\nParallelogram (base 6, height 3, side 5):\n";
    cout << "Area = " << parallelogramArea(base, height) << "\n";
    cout << "Perimeter = " << parallelogramPerimeter(base, sideLength) << "\n";

    // Trapezoid
    double side1 = 4, side2 = 6, side3 = 3, side4 = 5, trapHeight = 4;
    cout << "\nTrapezoid (sides 4,6,3,5 height 4):\n";
    cout << "Area = " << trapezoidArea(side1, side2, trapHeight) << "\n";
    cout << "Perimeter = " << trapezoidPerimeter(side1, side2, side3, side4) << "\n";

    // Regular Polygon (hexagon)
    int n = 6;
    double regularSide = 2;
    cout << "\nRegular Hexagon (side 2):\n";
    cout << "Area = " << regularPolygonArea(n, regularSide) << "\n";
    cout << "Perimeter = " << regularPolygonPerimeter(n, regularSide) << "\n";

    return 0;
}
