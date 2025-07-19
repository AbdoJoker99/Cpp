#include <iostream>
#include <cmath>

using namespace std;

// Triangle - using 3 sides (Heron's formula)
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double trianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

// Rectangle
double rectangleArea(double length, double width) {
    return length * width;
}

double rectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Square
double squareArea(double side) {
    return side * side;
}

double squarePerimeter(double side) {
    return 4 * side;
}

// Parallelogram
double parallelogramArea(double base, double height) {
    return base * height;
}

double parallelogramPerimeter(double base, double side) {
    return 2 * (base + side);
}

// Trapezoid
double trapezoidArea(double a, double b, double height) {
    return ((a + b) / 2.0) * height;
}

double trapezoidPerimeter(double a, double b, double c, double d) {
    return a + b + c + d;
}

// Regular Polygon (all sides and angles equal)
// Area = (n * s^2) / (4 * tan(pi/n))
// Perimeter = n * s
double regularPolygonArea(int n, double side) {
    return (n * side * side) / (4.0 * tan(M_PI / n));
}

double regularPolygonPerimeter(int n, double side) {
    return n * side;
}

int main() {
    cout << "Polygon Area and Perimeter Calculator\n";

    // Example usage:

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
