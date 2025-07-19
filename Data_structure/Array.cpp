// Author: abdo
#include <iostream>
#include <vector>
#include <algorithm> // for reverse, max_element, min_element
#include <climits>   // for INT_MAX, INT_MIN

using namespace std;

int main() {
    // Declare and initialize vector with negative numbers
    vector<int> arr = {-1, 2, 3, 4, 5};
    cout << "arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    // Access element at index 2
    cout << "arr[2] = " << arr[2] << "\n";

    // Find index of element = 2
    auto it = find(arr.begin(), arr.end(), 2);
    if (it != arr.end())
        cout << "Index of 2 = " << distance(arr.begin(), it) << "\n";
    else
        cout << "2 not found in array\n";

    // Unsigned int array (cannot contain negative numbers)
    vector<unsigned int> arr2 = {1, 2, 3, 4, 5};
    cout << "arr2 = ";
    for (unsigned int val : arr2) cout << val << " ";
    cout << "\n";

    // Creation using for loop
    cout << "\nPrint elements in arr:\n";
    for (int i : arr) cout << i << " ";
    cout << "\n";

    cout << "\nPrint index and element:\n";
    for (int i = 0; i < arr.size(); i++)
        cout << i << ": " << arr[i] << "\n";

    // buffer_info equivalent (pointer + size)
    cout << "\nBuffer info:\n";
    cout << "arr address = " << &arr[0] << ", size = " << arr.size() << "\n";
    cout << "arr2 address = " << &arr2[0] << ", size = " << arr2.size() << "\n";

    // Reverse
    reverse(arr.begin(), arr.end());
    cout << "\nReversed arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    // Append
    arr.push_back(200);
    cout << "\nAfter append arr = ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    // Length
    cout << "\nLength of arr = " << arr.size() << "\n";

    // Max and Min
    cout << "Max = " << *max_element(arr.begin(), arr.end()) << "\n";
    cout << "Min = " << *min_element(arr.begin(), arr.end()) << "\n";

    return 0;
}
