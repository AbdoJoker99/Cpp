#include <iostream>
#include <vector>
using namespace std;

/*
 * Program to compute the prefix sum of an integer array.
 *
 * Prefix sum array at index i contains the sum of all elements
 * from arr[0] to arr[i].
 */

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Input array
    int n = arr.size();

    vector<int> prefix(n);  // Prefix sum array

    // Initialize first element of prefix sum array
    prefix[0] = arr[0];

    // Compute prefix sums for each element
    // Time Complexity: O(n) where n = size of arr
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Print prefix sum array
    cout << "Prefix Sum: ";
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }
    cout << endl;

    return 0;
}
