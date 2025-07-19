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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insert(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Print all nodes
    void print_list() {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Delete node by value
    void delete_value(int value) {
        if (!head) return;

        // If head needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Search node and return index, -1 if not found
    int search(int value) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList linked_list;
    linked_list.insert(1);
    linked_list.insert(2);
    linked_list.insert(3);

    cout << "Initial list:" << endl;
    linked_list.print_list();

    linked_list.delete_value(2);

    cout << "After deleting 2:" << endl;
    linked_list.print_list();

    int index = linked_list.search(3);
    cout << "Index of 3: " << index << endl;

    return 0;
}
