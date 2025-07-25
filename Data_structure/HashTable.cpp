// Author: abdo

#include <iostream>   // For input/output stream (cin, cout)
#include <list>       // For doubly-linked list container used in chaining
#include <vector>     // For dynamic array used to store hash table buckets
#include <string>     // For string class used as key and value
#include <utility>    // For std::pair used to store key-value pairs

using namespace std;

class HashTable {
private:
    static const int size = 10; // Number of buckets (fixed size)
    vector<list<pair<string, string>>> table; // Hash table using separate chaining

    // Hash function: maps key to index in table
    // Time Complexity: O(1) (average case)
    int hash_function(const string& key) {
        return static_cast<int>(hash<string>{}(key) % size);
    }

public:
    // Constructor
    // Time Complexity: O(1)
    HashTable() {
        table.resize(size);
    }

    // Insert or update key-value pair
    // Time Complexity: O(n/k) ≈ O(1) average case, O(n) worst case (if all keys hash to same bucket)
    void insert_hashtable(const string& key, const string& value) {
        int index = hash_function(key);
        for (auto& item : table[index]) {
            if (item.first == key) {
                item.second = value;
                cout << "Key-value pair updated\n";
                return;
            }
        }
        table[index].push_back(make_pair(key, value));
        cout << "Key-value pair inserted\n";
    }

    // Search for a value by key
    // Time Complexity: O(n/k) ≈ O(1) average case, O(n) worst case
    string hash_search(const string& key) {
        int index = hash_function(key);
        for (auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }
        return "Key not found";
    }

    // Delete a key from the hash table
    // Time Complexity: O(n/k) ≈ O(1) average case, O(n) worst case
    void delete_hash(const string& key) {
        int index = hash_function(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key deleted\n";
                return;
            }
        }
        cout << "Key not found, cannot delete\n";
    }

    // Clear the entire hash table
    // Time Complexity: O(k), where k = number of buckets
    void delete_hash_table() {
        table.clear();
        table.resize(size);
        cout << "Hash table deleted (cleared)\n";
    }
};

int main() {
    HashTable hash1;

    // Insertions
    hash1.insert_hashtable("name", "ahmed");
    hash1.insert_hashtable("id", "2023");
    hash1.insert_hashtable("department", "id");

    // Searches
    cout << "Search 'name': " << hash1.hash_search("name") << endl;
    cout << "Search 'id': " << hash1.hash_search("id") << endl;
    cout << "Search 'grade': " << hash1.hash_search("grade") << endl;

    // Delete key
    hash1.delete_hash("id");
    cout << "Search 'id' after deletion: " << hash1.hash_search("id") << endl;

    // Clear hash table
    hash1.delete_hash_table();

    return 0;
}
