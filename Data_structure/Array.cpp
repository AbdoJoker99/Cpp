// Author: abdo
#include <iostream>
#include <vector>
#include <algorithm> // for reverse, max_element, min_element, swap
#include <climits>   // for INT_MAX, INT_MIN

using namespace std;

// ---------- Function: Print a subarray ----------
template <typename T>
void print_subarray(const vector<T>& v, size_t start, size_t end) {
    if (v.empty()) {
        cout << "Subarray: (vector is empty)\n";
        return;
    }
    if (start > end || end >= v.size()) {
        cout << "Invalid subarray range [" << start << ", " << end << "].\n";
        return;
    }

    cout << "Subarray [" << start << ".." << end << "]: ";
    for (size_t i = start; i <= end; ++i) {
        cout << v[i] << (i < end ? ' ' : '\n');
    }
}

// ---------- Function: Add two arrays element-wise ----------
vector<int> add_arrays(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
        cerr << "Error: Arrays must be of the same size to add.\n";
        return {};
    }
    vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        result[i] = a[i] + b[i];
    return result;
}

// ---------- Main Function ----------
int main() {
    vector<int> arr = {-1, 2, 3, 4, 5};               // signed integers
    vector<unsigned int> arr2 = {1, 2, 3, 4, 5};       // unsigned integers

    // Print original arrays
    cout << "Original arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    cout << "Original arr2 = ";
    for (unsigned int val : arr2) cout << val << " ";
    cout << "\n";

    // ---------- Reverse arr ----------
    reverse(arr.begin(), arr.end());
    cout << "\nReversed arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    // ---------- Append 200 to arr ----------
    arr.push_back(200);

    // ---------- Add arr + arr2 ----------
    vector<int> arr2_cast(arr2.begin(), arr2.end()); // convert unsigned to int
    vector<int> added = add_arrays(arr, arr2_cast);
    if (!added.empty()) {
        cout << "\nAdded arrays result = ";
        for (int val : added) cout << val << " ";
        cout << "\n";
    }

    // ---------- Swap arr and arr2_cast ----------
    cout << "\nBefore swap:\n";
    cout << "arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\narr2_cast = ";
    for (int val : arr2_cast) cout << val << " ";
    cout << "\n";

    swap(arr, arr2_cast); // std::swap

    cout << "\nAfter swap:\n";
    cout << "arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\narr2_cast = ";
    for (int val : arr2_cast) cout << val << " ";
    cout << "\n";

    return 0;
}
