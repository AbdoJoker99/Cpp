// Author: abdo
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (is_empty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return -1;  // Sentinel value for empty queue
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return data;
    }

    int search(int data) {
        Node* current = front;
        int index = 0;
        while (current) {
            if (current->data == data) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    void print_queue() {
        Node* current = front;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    ~Queue() {
        while (!is_empty()) {
            dequeue();
        }
    }
};

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
