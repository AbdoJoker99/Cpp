#include <iostream>
using namespace std;

/*
 * Program to check whether a given number is a Perfect Number
 *
 * A perfect number is a positive integer that is equal to the sum
 * of its proper positive divisors (excluding itself).
 * For example, 6 is perfect because 1 + 2 + 3 = 6.
 */

int main() {
    int i, num, div, sum = 0;

    cout << "Enter the number to be checked : ";
    cin >> num;

    // Loop through all numbers from 1 to num-1 to find divisors
    // Time Complexity: O(n), where n = num
    for (i = 1; i < num; i++) {
        div = num % i;
        if (div == 0) {
            sum += i;  // Add divisor to sum
        }
    }

    // Check if sum of divisors equals the original number
    if (sum == num)
        cout << "\n" << num << " is a perfect number.";
    else
        cout << "\n" << num << " is not a perfect number.";

    return 0;
}
