// Author: abdo
#include <iostream>
using namespace std;

/*
 * Simple singly linked list implementation.
 * Each Node stores an integer data and a pointer to the next node.
 *
 * Note: For production code, consider using std::forward_list from <forward_list>,
 * which is a singly linked list provided by STL.
 */

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

    /*
     * Insert a new node with given data at the end of the list.
     * Time Complexity: O(n), because we traverse the list to find the end.
     */
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

    /*
     * Print all elements in the linked list.
     * Time Complexity: O(n), where n is the number of nodes.
     */
    void print_list() {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    /*
     * Delete the first node that contains the specified value.
     * Time Complexity: O(n), we may need to traverse the whole list.
     */
    void delete_value(int value) {
        if (!head) return;

        // If the head node holds the value to be deleted
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

    /*
     * Search for the first node containing the specified value.
     * Returns the zero-based index of the node or -1 if not found.
     * Time Complexity: O(n), linear search.
     */
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

    /*
     * Destructor to free all nodes and avoid memory leaks.
     * Time Complexity: O(n), deletes all nodes.
     */
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

    // Insertions at the end of the list
    linked_list.insert(1);
    linked_list.insert(2);
    linked_list.insert(3);

    cout << "Initial list:" << endl;
    linked_list.print_list();

    // Delete first occurrence of value 2
    linked_list.delete_value(2);

    cout << "After deleting 2:" << endl;
    linked_list.print_list();

    // Search for the value 3
    int index = linked_list.search(3);
    cout << "Index of 3: " << index << endl;

    return 0;
}
