// Author: abdo 

#include <iostream>
#include <vector>
using namespace std;

// Fast IO macros for competitive programming style
#define pb push_back
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'

// Recursive factorial function
// Time Complexity: O(n)
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Recursive Fibonacci function
// Exponential time complexity: O(2^n), inefficient for large n
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative Fibonacci using a vector to store sequence
// Time Complexity: O(n)
vector<int> fibonacci_iterative(int n) {
    vector<int> fib;
    if (n <= 0) return fib;  // Return empty for non-positive input
    fib.pb(0);              // First Fibonacci number
    if (n == 1) return fib; // If only one term requested, return

    fib.pb(1);              // Second Fibonacci number
    for (int i = 2; i < n; ++i) {
        fib.pb(fib[i - 1] + fib[i - 2]); // Sum of previous two numbers
    }
    return fib;
}

int main() {
    FAST;  // Enable fast IO

    int num = 5;

    // Factorial demo
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    // Fibonacci recursive demo
    cout << "Fibonacci (recursive) at position " << num << " is: " << fibonacci_recursive(num) << endl;

    // Fibonacci iterative demo
    cout << "Fibonacci sequence (iterative) up to " << num << " terms: ";
    vector<int> fib_seq = fibonacci_iterative(num);
    for (int val : fib_seq) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
