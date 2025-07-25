// Author: abdo
#include <iostream>
using namespace std;

/*
 * Stack implemented using singly linked list.
 * Each Node contains an integer data and a pointer to the next node.
 *
 * Note: For production use, consider std::stack (LIFO container adapter)
 * which is usually implemented on top of std::deque or std::vector.
 */

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
    Node* top;  // Points to the top element of the stack

public:
    Stack() {
        top = nullptr;
    }

    /*
     * Check if the stack is empty.
     * Time Complexity: O(1)
     */
    bool is_empty() {
        return top == nullptr;
    }

    /*
     * Push an element onto the stack.
     * Time Complexity: O(1)
     */
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    /*
     * Pop the top element from the stack and return its value.
     * Prints an error message and returns -1 if stack is empty.
     * Time Complexity: O(1)
     */
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

    /*
     * Search for an element in the stack.
     * Returns the zero-based index from the top if found, else -1.
     * Time Complexity: O(n), n = number of elements in stack
     */
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

    /*
     * Print all elements in the stack from top to bottom.
     * Time Complexity: O(n)
     */
    void print_stack() {
        Node* current = top;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    /*
     * Destructor to free all allocated nodes and avoid memory leaks.
     * Time Complexity: O(n)
     */
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
