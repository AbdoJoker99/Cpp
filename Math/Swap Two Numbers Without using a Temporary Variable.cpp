/*
 * C++ program to swap two numbers without using a temporary variable
 *
 * This program uses arithmetic operations to swap values.
 * Note: This method assumes no overflow occurs during addition.
 */

#include <iostream>
using namespace std;

class pro {
public:
    /* Function to swap values using arithmetic operations */
    void swap(int &a, int &b) {
        b = a + b;   // sum stored in b
        a = b - a;   // a becomes original b
        b = b - a;   // b becomes original a
    }
};

int main() {
    int a, b;
    pro s1;

    cout << "Enter two numbers to be swapped : ";
    cin >> a >> b;

    cout << "Values before swap :\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    s1.swap(a, b);

    cout << "The two numbers after swapping become :" << endl;
    cout << "Value of a : " << a << endl;
    cout << "Value of b : " << b << endl;

    return 0;
}
