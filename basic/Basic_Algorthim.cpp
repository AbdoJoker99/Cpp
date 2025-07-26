// Standard C++ Libraries
#include <iostream>     // For input and output stream (cin, cout)
#include <string>       // For using std::string
#include <vector>       // For using std::vector (dynamic arrays)
#include <algorithm>    // For algorithms like sort, max, min, etc. (not used directly here)
#include <numeric>      // For numeric operations like accumulate (not used here)
#include <cmath>        // For math functions like pow, sqrt, etc. (not used here)
#include <set>          // For std::set (not used in this code but good for unique sorted elements)
#include <map>          // For key-value pairs (std::map)
#include <iterator>     // For iterator operations (like back_inserter)
#include <sstream>      // For string stream operations (string to int, etc.)
#include <bitset>       // For binary representation of numbers

using namespace std;

// Bubble Sort
// Time Complexity: O(n^2) average and worst-case, O(n) best-case (if already sorted)
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
// Time Complexity: O(n^2) in all cases
void selection_sort(vector<int>& arr) {
    int size = arr.size();
    for (int s = 0; s < size; s++) {
        int min_idx = s;
        for (int i = s + 1; i < size; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
        }
        swap(arr[s], arr[min_idx]);
    }
}

// Insertion Sort
// Time Complexity: O(n^2) average and worst-case, O(n) best-case (if already sorted)
void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int a = arr[i];
        int j = i - 1;
        while (j >= 0 && a < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = a;
    }
}

// Quick Sort (Recursive version)
// Time Complexity: O(n log n) average case, O(n^2) worst-case (rare if pivot is bad)
vector<int> quick_sort(vector<int> arr) {
    if (arr.size() <= 1) return arr;

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) middle.push_back(x);
        else right.push_back(x);
    }

    vector<int> sorted_left = quick_sort(left);
    vector<int> sorted_right = quick_sort(right);

    // Concatenating results
    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
    return sorted_left;
}

// Binary Search (Requires sorted array)
// Time Complexity: O(log n)
int binary_search(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        //Avoids overflow using (r - l) instead of l + r.
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Linear Search
// Time Complexity: O(n)
int linear_search(const vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Main function to demonstrate sorting and searching
int main() {
    // Bubble Sort
    vector<int> arr1 = {2, 1, 10, 23};
    bubble_sort(arr1);
    cout << "Bubble sorted: ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    // Selection Sort
    vector<int> arr2 = {7, 2, 1, 6};
    selection_sort(arr2);
    cout << "Selection sorted: ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    // Insertion Sort
    vector<int> arr3 = {7, 2, 1, 6};
    insertion_sort(arr3);
    cout << "Insertion sorted: ";
    for (int i : arr3) cout << i << " ";
    cout << endl;

    // Quick Sort
    vector<int> arr4 = {3, 6, 8, 10, 1, 2, 1};
    vector<int> sorted_arr = quick_sort(arr4);
    cout << "Quick sorted: ";
    for (int i : sorted_arr) cout << i << " ";
    cout << endl;

    // Searching
    vector<int> arr5 = {2, 3, 4, 10, 40}; // must be sorted for binary search
    int x = 10;

    // Binary Search
    int result1 = binary_search(arr5, x);
    if (result1 != -1)
        cout << "Element found at index (binary search): " << result1 << endl;
    else
        cout << "Element not found (binary search)" << endl;

    // Linear Search
    int result2 = linear_search(arr5, x);
    if (result2 != -1)
        cout << "Element found at index (linear search): " << result2 << endl;
    else
        cout << "Element not found (linear search)" << endl;

    return 0;
}
