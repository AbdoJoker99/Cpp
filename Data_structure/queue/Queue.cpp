// Author: abdo
#include <iostream>
using namespace std;

// Node class representing each element in the queue
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;  // Points to the front node
    Node* rear;   // Points to the rear node

public:
    // Constructor: initialize empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool is_empty() {
        return front == nullptr;
    }

    // Insert element at the rear
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (is_empty()) {
            front = rear = newNode;  // First element
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove and return element from the front
    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;  // Sentinel value for empty queue
        }

        int data = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;  // Queue became empty

        delete temp;
        return data;
    }

    // Search for a value, return index or -1 if not found
    int search(int data) {
        Node* current = front;
        int index = 0;
        while (current) {
            if (current->data == data) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    // Print all elements in the queue
    void print_queue() {
        Node* current = front;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Destructor: deallocates all nodes
    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }
};

// Main function to demonstrate queue functionality
int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Queue contents:\n";
    queue.print_queue();

    cout << "Dequeued: " << queue.dequeue() << endl;

    cout << "Search for 2: " << queue.search(2) << endl;

    cout << "Queue after dequeue:\n";
    queue.print_queue();

    return 0;
}
