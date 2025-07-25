/*
 * C++ program to check if given integer is even or odd
 *
 * The program reads an integer from user input,
 * then determines if it is even or odd using the modulus operator (%).
 */

#include <iostream>
using namespace std;

int main() {
    int number, remainder;

    cout << "Enter the number : ";
    cin >> number;

    // Compute remainder when divided by 2
    remainder = number % 2;

    // If remainder is 0, number is even; otherwise odd
    if (remainder == 0)
        cout << number << " is an even integer " << endl;
    else
        cout << number << " is an odd integer " << endl;

    return 0;
}
