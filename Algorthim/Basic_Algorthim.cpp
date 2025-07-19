// Python to C++ Code Equivalents

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <map>
#include <iterator>
#include <sstream>
#include <bitset>

using namespace std;

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

    sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
    return sorted_left;
}

int binary_search(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int linear_search(const vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    // Sorting examples
    vector<int> arr1 = {2, 1, 10, 23};
    bubble_sort(arr1);
    cout << "Bubble sorted: ";
    for (int i : arr1) cout << i << " ";
    cout << endl;

    vector<int> arr2 = {7, 2, 1, 6};
    selection_sort(arr2);
    cout << "Selection sorted: ";
    for (int i : arr2) cout << i << " ";
    cout << endl;

    vector<int> arr3 = {7, 2, 1, 6};
    insertion_sort(arr3);
    cout << "Insertion sorted: ";
    for (int i : arr3) cout << i << " ";
    cout << endl;

    vector<int> arr4 = {3, 6, 8, 10, 1, 2, 1};
    vector<int> sorted_arr = quick_sort(arr4);
    cout << "Quick sorted: ";
    for (int i : sorted_arr) cout << i << " ";
    cout << endl;

    // Searching examples
    vector<int> arr5 = {2, 3, 4, 10, 40};
    int x = 10;

    int result1 = binary_search(arr5, x);
    if (result1 != -1)
        cout << "Element found at index (binary search): " << result1 << endl;
    else
        cout << "Element not found (binary search)" << endl;

    int result2 = linear_search(arr5, x);
    if (result2 != -1)
        cout << "Element found at index (linear search): " << result2 << endl;
    else
        cout << "Element not found (linear search)" << endl;

    return 0;
}
