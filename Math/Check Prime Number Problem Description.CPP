/*
 * C++ Program to Check Prime Numbers using Naive Approach
 *
 * This program checks whether a given number is prime by
 * testing divisibility from 2 up to sqrt(num).
 */

#include <iostream>
#include <cmath>  // For sqrt()

int main() {
    int num;
    std::cout << "Enter the number to be checked: ";
    std::cin >> num;

    // Numbers less than or equal to 1 are not prime by definition
    if (num <= 1) {
        std::cout << "\n" << num << " is not prime";
        return 0;
    }

    bool isPrime = true;

    // Check divisors from 2 to sqrt(num)
    // Time Complexity: O(√n) because we only check up to sqrt(num).
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;  // Early exit if divisor found
        }
    }

    if (isPrime)
        std::cout << "\n" << num << " is prime.";
    else
        std::cout << "\n" << num << " is not prime.";

    return 0;
}
