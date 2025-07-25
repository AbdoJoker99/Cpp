// Author: Abdo
#include <iostream>     // For standard input/output
#include <fstream>      // For file input/output streams (ifstream, ofstream, fstream)
#include <string>       // For std::string and related operations
#include <vector>       // (Optional) For using vectors if needed
#include <cstdlib>      // For rand() and srand()
#include <ctime>        // For seeding rand() with time(0)

using namespace std;

int main() {
    string filename = "example.txt";
    string text;

    // 1. Read and display file contents
    cout << "\n--- Reading from file ---\n";
    ifstream readFile(filename); // Open file for reading
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close(); // Always close files after use
    } else {
        cout << "Unable to open file for reading.\n";
    }

    // Clear input buffer if needed
    cin.ignore();

    // 2. Append text to file
    cout << "\nEnter the text to append: ";
    getline(cin, text);

    ofstream appendFile(filename, ios::app); // Open file in append mode
    if (appendFile.is_open()) {
        appendFile << text << "\n";
        appendFile.close();
    } else {
        cout << "Error opening file for appending.\n";
    }

    // 3. Overwrite file with new text
    cout << "\nEnter the text to write (overwrite): ";
    getline(cin, text);

    ofstream writeFile(filename); // Open file in truncate (default) mode
    if (writeFile.is_open()) {
        writeFile << text;
        writeFile.close();
    } else {
        cout << "Error opening file for writing.\n";
    }

    // 4. Append again after overwrite
    cout << "\nEnter the text to append again: ";
    getline(cin, text);

    appendFile.open(filename, ios::app);
    if (appendFile.is_open()) {
        appendFile << text << "\n";
        appendFile.close();
    } else {
        cout << "Error opening file for appending.\n";
    }

    // 5. Insert text at a random position
    cout << "\nEnter the text to insert at random position: ";
    getline(cin, text);

    fstream rwFile(filename, ios::in); // Open file for reading
    if (rwFile.is_open()) {
        string content((istreambuf_iterator<char>(rwFile)), istreambuf_iterator<char>());
        rwFile.close();

        // Generate random insert position
        srand(time(0)); // Seed once with current time
        int position = rand() % (content.length() + 1);
        content.insert(position, text);

        // Overwrite file with new content
        ofstream finalWrite(filename);
        if (finalWrite.is_open()) {
            finalWrite << content;
            finalWrite.close();
        } else {
            cout << "Error writing updated content.\n";
        }
    } else {
        cout << "Error opening file for read/write.\n";
    }

    // 6. Read from another file (e.g., 'siddhartha.txt')
    cout << "\n--- Reading lines from siddhartha.txt ---\n";
    ifstream fileObject("siddhartha.txt");
    if (fileObject.is_open()) {
        string line;
        while (getline(fileObject, line)) {
            cout << line << endl;
        }
        fileObject.close();
    } else {
        cout << "Unable to open siddhartha.txt.\n";
    }

    // 7. Write to journal.txt (overwrite mode)
    ofstream journalWrite("journal.txt");
    if (journalWrite.is_open()) {
        journalWrite << "I love programming.";
        journalWrite.close();
    } else {
        cout << "Unable to write to journal.txt.\n";
    }

    // 8. Append to journal.txt
    ofstream journalAppend("journal.txt", ios::app);
    if (journalAppend.is_open()) {
        journalAppend << "\nI love making games.";
        journalAppend.close();
    } else {
        cout << "Unable to append to journal.txt.\n";
    }

    return 0;
}
