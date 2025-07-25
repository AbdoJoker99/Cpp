#include <iostream>
#include <vector>
using namespace std;

/*
 * Program to compute the suffix sum of an integer array.
 *
 * Suffix sum array at index i contains the sum of all elements
 * from arr[i] to the end of the array.
 */

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Input array
    int n = arr.size();

    vector<int> suffix(n);  // Suffix sum array

    // Initialize last element of suffix sum array
    suffix[n - 1] = arr[n - 1];

    // Compute suffix sums moving from right to left
    // Time Complexity: O(n) where n = size of arr
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + arr[i];
    }

    // Print suffix sum array
    cout << "Suffix Sum: ";
    for (int i = 0; i < n; i++) {
        cout << suffix[i] << " ";
    }
    cout << endl;

    return 0;
}
