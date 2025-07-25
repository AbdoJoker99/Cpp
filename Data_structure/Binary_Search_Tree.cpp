#include <iostream>
#include <vector>
using namespace std;

// Node of a BST
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Insert key into BST rooted at 'root'
    // Time Complexity: O(h) where h is tree height, average O(log n), worst O(n)
    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        // if key == root->key, no duplicates inserted
        return root;
    }

    // Search key in BST rooted at 'root'
    // Time Complexity: O(h)
    Node* search(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root;
        if (key < root->key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Find node with minimum key (leftmost leaf)
    // Time Complexity: O(h)
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete a node with given key from BST rooted at 'root'
    // Time Complexity: O(h)
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: get inorder successor (smallest in right subtree)
            Node* temp = minValueNode(root->right);

            // Copy inorder successor's content to this node
            root->key = temp->key;

            // Delete inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    // Inorder traversal: Left, Root, Right
    // Time Complexity: O(n)
    void inorderTraversal(Node* root, vector<int>& result) {
        if (root) {
            inorderTraversal(root->left, result);
            result.push_back(root->key);
            inorderTraversal(root->right, result);
        }
    }

    // Preorder traversal: Root, Left, Right
    // Time Complexity: O(n)
    void preorderTraversal(Node* root, vector<int>& result) {
        if (root) {
            result.push_back(root->key);
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }

    // Postorder traversal: Left, Right, Root
    // Time Complexity: O(n)
    void postorderTraversal(Node* root, vector<int>& result) {
        if (root) {
            postorderTraversal(root->left, result);
            postorderTraversal(root->right, result);
            result.push_back(root->key);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    vector<int> inorderTraversal() {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    vector<int> preorderTraversal() {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

    vector<int> postorderTraversal() {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};

// Utility function to print elements of vector
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    BinarySearchTree bst;
    int choice, key;

    while (true) {
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            bst.insert(key);
            cout << "Inserted " << key << endl;
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (bst.search(key))
                cout << "Key " << key << " found in the BST.\n";
            else
                cout << "Key " << key << " not found.\n";
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            bst.deleteKey(key);
            cout << "Deleted " << key << " (if it existed).\n";
            break;
        case 4:
            cout << "Inorder Traversal: ";
            printVector(bst.inorderTraversal());
            break;
        case 5:
            cout << "Preorder Traversal: ";
            printVector(bst.preorderTraversal());
            break;
        case 6:
            cout << "Postorder Traversal: ";
            printVector(bst.postorderTraversal());
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
