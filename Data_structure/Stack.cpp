// Author: abdo
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool is_empty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return -1; // sentinel value
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int search(int data) {
        Node* current = top;
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

    void print_stack() {
        Node* current = top;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack contents:\n";
    stack.print_stack();

    cout << "Search for 2: " << stack.search(2) << endl;

    cout << "Pop: " << stack.pop() << endl;

    cout << "Stack after pop:\n";
    stack.print_stack();

    return 0;
}
