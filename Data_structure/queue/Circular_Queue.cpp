// Author: abdo
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int* queue;
    int front;
    int rear;

public:
    // Constructor
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add an element
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (front == -1) front = 0;  // First insertion
        rear = (rear + 1) % size;
        queue[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    // Remove and return an element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;  // Sentinel value
        }

        int temp = queue[front];

        // If only one element left
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        cout << "Dequeued: " << temp << endl;
        return temp;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.dequeue();
    cq.dequeue();

    return 0;
}
