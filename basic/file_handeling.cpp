// Author: abdo
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {
    string filename = "example.txt";
    string text;

    // 1. Read and display file contents
    cout << "\n--- Reading from file ---\n";
    ifstream readFile(filename);
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }

    // 2. Append text to file
    cout << "\nEnter the text to append: ";
    getline(cin, text);

    ofstream appendFile(filename, ios::app);
    if (appendFile.is_open()) {
        appendFile << text << "\n";
        appendFile.close();
    }

    // 3. Overwrite file with new text
    cout << "\nEnter the text to write (overwrite): ";
    getline(cin, text);

    ofstream writeFile(filename);
    if (writeFile.is_open()) {
        writeFile << text;
        writeFile.close();
    }

    // 4. Append again after overwrite
    cout << "\nEnter the text to append again: ";
    getline(cin, text);

    appendFile.open(filename, ios::app);
    if (appendFile.is_open()) {
        appendFile << text << "\n";
        appendFile.close();
    }

    // 5. Insert text at a random position
    cout << "\nEnter the text to insert at random position: ";
    getline(cin, text);

    // Read full file into a string
    fstream rwFile(filename, ios::in | ios::out);
    if (rwFile.is_open()) {
        string content((istreambuf_iterator<char>(rwFile)), istreambuf_iterator<char>());
        rwFile.close();

        // Get random position
        srand(time(0));
        int position = rand() % (content.length() + 1);
        content.insert(position, text);

        // Write updated content back
        ofstream finalWrite(filename);
        finalWrite << content;
        finalWrite.close();
    } else {
        cout << "Error opening file for read/write." << endl;
    }

    // 6. Read all lines from another file (like 'siddhartha.txt')
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

    // 7. Writing to journal.txt
    ofstream journalWrite("journal.txt");
    if (journalWrite.is_open()) {
        journalWrite << "I love programming.";
        journalWrite.close();
    }

    // 8. Appending to journal.txt
    ofstream journalAppend("journal.txt", ios::app);
    if (journalAppend.is_open()) {
        journalAppend << "\nI love making games.";
        journalAppend.close();
    }

    return 0;
}
