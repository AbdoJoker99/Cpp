/*
 * C++ Program to Generate Sequence of Ulam Numbers
 *
 * Ulam numbers start with 1 and 2.
 * Each subsequent Ulam number is the smallest integer
 * that can be expressed uniquely as the sum of two distinct earlier Ulam numbers.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int uterm1 = 1, uterm2 = 2, num = 0;
    vector<int> v;

    // Initialize with first two Ulam numbers
    v.push_back(1);
    num++;
    v.push_back(2);
    num++;

    // Generate Ulam numbers up to 100
    for (int i = 3; i <= 100; i++) {
        int count = 0;

        // Check all pairs (j,k) in existing Ulam numbers to see
        // if their sum equals i, and count how many such pairs exist.
        // Time Complexity: O(num^2) for each i.
        for (int j = 0; j < num; j++) {
            for (int k = j + 1; k < num; k++) {
                if (v[j] + v[k] == i)
                    count++;
                if (count > 1) // Early break if more than one pair found
                    break;
            }
            if (count > 1)
                break;
        }

        // If exactly one pair sums to i, it's an Ulam number
        if (count == 1) {
            v.push_back(i);
            num++;
        }
    }

    // Output the generated Ulam sequence
    cout << "The sequence of Ulam numbers is as follows : " << endl;
    for (const int& val : v)
        cout << val << '\t';
    cout << endl;

    return 0;
}
