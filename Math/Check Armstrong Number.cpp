/*
 * C++ Program to Check whether a given Number is Armstrong
 *
 * Armstrong number of order n is a number that is equal to
 * the sum of its own digits each raised to the power n.
 * 
 * This program specifically checks for 3-digit Armstrong numbers,
 * i.e., sum of cubes of digits equals the number itself.
 */

#include <iostream>
using namespace std;

int main() {
    int num, temp, rem, sum = 0;

    cout << "Enter number to be checked : ";
    cin >> num;

    temp = num;

    // Extract each digit and add cube of digit to sum
    // Time Complexity: O(d) where d = number of digits in num,
    // because each digit is processed once.
    // For 3-digit number, d=3 (constant time), but
    // this works for any length number.
    while (temp != 0) {
        rem = temp % 10;           // Extract last digit
        sum += rem * rem * rem;    // Add cube of digit to sum
        temp /= 10;                // Remove last digit
    }

    // Compare computed sum to original number
    if (sum == num)
        cout << "\n" << num << " is an Armstrong number.";
    else
        cout << "\n" << num << " is not an Armstrong number.";

    return 0;
}
