// Author: abdo 

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric> // accumulate
#include <memory>
#include <cstring>

using namespace std;

#define pb push_back
#define pf push_front
#define ALL(x) (x).begin(), (x).end()
#define rALL(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'

// Recursive factorial
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Recursive Fibonacci
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative Fibonacci using vector
vector<int> fibonacci_iterative(int n) {
    vector<int> fib;
    if (n <= 0) return fib;
    fib.pb(0);
    if (n == 1) return fib;
    fib.pb(1);
    for (int i = 2; i < n; ++i) {
        fib.pb(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

int main() {
    FAST;

    // Factorial demo
    int num = 5;
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
