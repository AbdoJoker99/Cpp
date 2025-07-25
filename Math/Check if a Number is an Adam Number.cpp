#include <iostream>
#include <cmath>  // For sqrt()
using namespace std;

/*
 * Adam Number Checker
 *
 * An Adam number is a number where:
 * reverse(square(num)) == square(reverse(num))
 *
 * For example, 12:
 * square(12) = 144, reverse(144) = 441
 * reverse(12) = 21, square(21) = 441
 * Since both are equal, 12 is an Adam number.
 *
 * This program checks whether a given number is an Adam number.
 */

int main() {
    int num, temp, r1, r2, sq, rev1 = 0, rev2 = 0;

    cout << "Enter a number : ";
    cin >> num;

    // Step 1: Calculate square of the number
    temp = num * num;

    // Step 2: Reverse the digits of square(num)
    // Time Complexity: O(d) where d = number of digits in num*num
    while (temp != 0) {
        r1 = temp % 10;
        rev1 = rev1 * 10 + r1;
        temp /= 10;
    }

    // Step 3: Calculate sqrt of reversed square
    sq = sqrt(rev1);

    // Step 4: Reverse the digits of sqrt(rev1)
    // Time Complexity: O(d), d = digits in sqrt(rev1)
    while (sq != 0) {
        r2 = sq % 10;
        rev2 = rev2 * 10 + r2;
        sq /= 10;
    }

    // Step 5: Check if reversed sqrt equals original number
    if (rev2 == num)
        cout << "\n" << num << " is an Adam number.";
    else
        cout << "\n" << num << " is not an Adam number.";

    return 0;
}
