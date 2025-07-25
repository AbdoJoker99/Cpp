// Author: abdo_joker

#include <iostream>   // For cin, cout
#include <deque>      // STL double-ended queue
using namespace std;

int main() {
    deque<int> dq; // Declare a deque of integers

    // -------- Insert elements --------
    dq.push_back(10);     // Insert at the back: [10]
    dq.push_front(20);    // Insert at the front: [20, 10]
    dq.push_back(30);     // [20, 10, 30]
    dq.push_front(40);    // [40, 20, 10, 30]

    cout << "Deque elements: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // -------- Access front and back --------
    cout << "Front: " << dq.front() << endl; // Should print 40
    cout << "Back: " << dq.back() << endl;   // Should print 30

    // -------- Remove elements --------
    dq.pop_front(); // Removes 40 → [20, 10, 30]
    dq.pop_back();  // Removes 30 → [20, 10]

    cout << "Deque after popping front and back: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // -------- Check if empty and get size --------
    if (dq.empty()) {
        cout << "Deque is empty.\n";
    } else {
        cout << "Deque size: " << dq.size() << endl;
    }

    return 0;
}
