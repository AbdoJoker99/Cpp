// Author: abdo_joker

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements at front and back
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    cout << "Deque elements: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Access front and back
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    // Remove elements from both ends
    dq.pop_front();
    dq.pop_back();

    cout << "Deque after popping front and back: ";
    for (int val : dq) {
        cout << val << " ";
    }
    cout << endl;

    // Check if deque is empty
    if (dq.empty()) {
        cout << "Deque is empty.\n";
    } else {
        cout << "Deque size: " << dq.size() << endl;
    }

    return 0;
}
