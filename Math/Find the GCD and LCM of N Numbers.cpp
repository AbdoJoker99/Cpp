#include <iostream>
// <conio.h> and <stdlib.h> are not needed here, so omitted for portability
using namespace std;

/*
 * Function to calculate GCD (Greatest Common Divisor) using Euclidean Algorithm
 *
 * GCD of two numbers is the largest number that divides both without remainder.
 * This uses the efficient Euclidean algorithm.
 *
 * Time Complexity: O(log(min(x, y))) — very efficient.
 */
int gcd(int x, int y) {
    int r = 0, a, b;
    a = (x > y) ? x : y; // a is the greater number
    b = (x < y) ? x : y; // b is the smaller number

    r = b;
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

/*
 * Function to calculate LCM (Least Common Multiple)
 *
 * LCM of two numbers is the smallest positive number divisible by both.
 * This implementation uses a brute-force approach starting from the max of x,y.
 *
 * Time Complexity: O(k), where k depends on the size of LCM relative to inputs,
 * which can be inefficient for large numbers.
 */
int lcm(int x, int y) {
    int a;
    a = (x > y) ? x : y; // Start from the greater number

    while (true) {
        if (a % x == 0 && a % y == 0)
            return a;
        ++a;  // Increment until divisible by both
    }
}

int main(int argc, char **argv) {
    cout << "Enter the two numbers: ";
    int x, y;
    cin >> x >> y;

    cout << "The GCD of two numbers is: " << gcd(x, y) << endl;
    cout << "The LCM of two numbers is: " << lcm(x, y) << endl;

    return 0;
}
