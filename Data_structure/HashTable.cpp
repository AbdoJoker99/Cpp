// Author: abdo
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <utility> // for pair
using namespace std;

class HashTable {
private:
    static const int size = 10;
    vector<list<pair<string, string>>> table;

    // Simple hash function using std::hash and modulo table size
    int hash_function(const string& key) {
        return static_cast<int>(hash<string>{}(key) % size);
    }

public:
    HashTable() {
        table.resize(size);
    }

    void insert_hashtable(const string& key, const string& value) {
        int index = hash_function(key);
        // Check if key exists, update if found
        for (auto& item : table[index]) {
            if (item.first == key) {
                item.second = value;
                cout << "Key-value pair updated\n";
                return;
            }
        }
        // Else insert new pair
        table[index].push_back(make_pair(key, value));
        cout << "Key-value pair inserted\n";
    }

    string hash_search(const string& key) {
        int index = hash_function(key);
        for (auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }
        return "Key not found";
    }

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
