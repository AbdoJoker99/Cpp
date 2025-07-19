#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num); // Ensure the number is positive

    while (num > 0) {
        sum += num % 10; // Get the last digit
        num /= 10;       // Remove the last digit
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
