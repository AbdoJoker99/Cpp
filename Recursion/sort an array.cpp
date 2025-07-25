#include <iostream>
#include <vector>
using namespace std;

// Recursively insert `val` into the sorted vector `arr`
void insertSorted(vector<int> &arr, int val) {
    // Base case: If empty or last element <= val, just append
    if (arr.empty() || arr.back() <= val) {
        arr.push_back(val);
        return;
    }
    // Otherwise, pop the last element, recurse, then push it back
    int temp = arr.back();
    arr.pop_back();
    insertSorted(arr, val);
    arr.push_back(temp);
}

// Recursively sort the vector using insertion sort logic
void sortRecursive(vector<int> &arr) {
    if (arr.size() <= 1) return;  // Base case: empty or single element vector

    int temp = arr.back();
    arr.pop_back();
    sortRecursive(arr);
    insertSorted(arr, temp);
}

// Recursive function to separate even and odd numbers from `input`
// evens and odds vectors are populated accordingly
void sortEvenOddRecursive(const vector<int> &input, vector<int> &evens, vector<int> &odds, int index = 0) {
    if (index >= input.size()) return;

    if (input[index] % 2 == 0)
        evens.push_back(input[index]);
    else
        odds.push_back(input[index]);

    sortEvenOddRecursive(input, evens, odds, index + 1);
}

int main() {
    vector<int> input = {3, 1, 2, 4, 7, 6};

    vector<int> evens, odds;

    // Separate even and odd numbers recursively
    sortEvenOddRecursive(input, evens, odds);

    // Sort even and odd vectors recursively
    sortRecursive(evens);
    sortRecursive(odds);

    // Merge even numbers first, then odd numbers
    vector<int> result = evens;
    result.insert(result.end(), odds.begin(), odds.end());

    // Print the merged sorted array
    cout << "Sorted (Even then Odd): ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
