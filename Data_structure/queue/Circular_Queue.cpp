// Author: abdo
#include <iostream>
using namespace std;

// Define a CircularQueue class
class CircularQueue {
private:
    int size;    // Maximum size of the queue
    int* queue;  // Dynamic array to hold elements
    int front;   // Index of front element
    int rear;    // Index of last element

public:
    // Constructor: initializes queue of given size
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;  // -1 indicates empty queue
        rear = -1;
    }

    // Destructor: releases allocated memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Returns true if queue is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Returns true if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add an item to the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        // First insertion
        if (front == -1) front = 0;

        // Circular increment of rear
        rear = (rear + 1) % size;
        queue[rear] = item;

        cout << "Enqueued: " << item << endl;
    }

    // Remove and return the front item from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;  // Sentinel value for error
        }

        int temp = queue[front];

        // Reset front and rear if last element is being removed
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Circular increment of front
            front = (front + 1) % size;
        }

        cout << "Dequeued: " << temp << endl;
        return temp;
    }
};

// Demonstration
int main() {
    CircularQueue cq(5);  // Create a queue with capacity 5

    cq.enqueue(10);  // Insert 10
    cq.enqueue(20);  // Insert 20
    cq.enqueue(30);  // Insert 30

    cq.dequeue();    // Remove front (10)
    cq.dequeue();    // Remove front (20)

    return 0;
}
