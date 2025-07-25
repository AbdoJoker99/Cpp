#include <iostream>
using namespace std;

/*
 * Function to compute the sum of digits of an integer.
 * Handles both positive and negative inputs by converting
 * the number to its absolute value.
 *
 * Time Complexity: O(d), where d = number of digits in the input number.
 */
int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num);  // Convert negative to positive to handle all cases

    // Extract each digit and add to sum
    while (num > 0) {
        sum += num % 10;  // Get the last digit
        num /= 10;        // Remove the last digit
    }

    return sum;
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    int result = sumOfDigits(number);
    cout << "Sum of digits = " << result << endl;

    return 0;
}
