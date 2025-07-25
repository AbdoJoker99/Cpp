/*
 * C++ program to Display a given Number with its Digits Reversed
 *
 * The program reads an integer and reverses its digits.
 * For example, input 1234 → output 4321.
 */

#include <iostream>
using namespace std;

int main() {
    int val, temp, num = 0;

    cout << "Enter the number "
         << "(avoid entering numbers with leading zeroes) : ";
    cin >> val;

    temp = val;

    // Reverse the digits by extracting the last digit repeatedly
    // Time Complexity: O(d), where d = number of digits in val
    while (temp != 0) {
        num = num * 10 + temp % 10;  // Append last digit of temp to num
        temp = temp / 10;             // Remove last digit from temp
    }

    cout << "The given number " << val
         << " with its digits reversed is "
         << num << endl;

    return 0;
}
