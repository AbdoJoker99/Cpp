// File: output_formats.cpp
// Description: Demonstrates all output formatting styles using cout

#include <iostream>      // For cout
#include <iomanip>       // For formatting options like setw, setprecision, etc.

using namespace std;

int main() {
    // Basic Output
    cout << "=== Basic Output ===" << endl;
    cout << "Hello, world!" << endl;
    cout << "-------------------" << endl;

    // Escape Sequences
    cout << "\n=== Escape Sequences ===" << endl;
    cout << "Newline\\n\nTab\\t\tBackspace\\b\bEnd\n";
    cout << "Quote: \" and Backslash: \\" << endl;

    // Numbers and Precision
    double num = 123.456789;
    cout << "\n=== Fixed and Scientific Notation ===" << endl;
    cout << "Default: " << num << endl;
    cout << "Fixed: " << fixed << num << endl;
    cout << "Scientific: " << scientific << num << endl;

    cout << "\n=== Precision Control ===" << endl;
    cout << fixed << setprecision(2) << "2 decimal places: " << num << endl;
    cout << setprecision(5) << "5 decimal places: " << num << endl;

    // Width and Alignment
    int val = 42;
    cout << "\n=== setw (Field Width) ===" << endl;
    cout << "Default: [" << val << "]" << endl;
    cout << "setw(10): [" << setw(10) << val << "]" << endl;

    cout << "\n=== Alignment ===" << endl;
    cout << left << setw(10) << val << " <- left aligned" << endl;
    cout << right << setw(10) << val << " <- right aligned" << endl;
    cout << internal << setw(10) << -val << " <- internal" << endl;

    // Fill Characters
    cout << "\n=== setfill ===" << endl;
    cout << setfill('*') << setw(10) << val << endl;

    // Boolean Output
    cout << "\n=== Boolean Formatting ===" << endl;
    cout << boolalpha << true << " " << false << endl;
    cout << noboolalpha << true << " " << false << endl;

    // Base Formatting
    cout << "\n=== Number Base Formatting ===" << endl;
    cout << dec << val << " (decimal)" << endl;
    cout << hex << val << " (hexadecimal)" << endl;
    cout << oct << val << " (octal)" << endl;

    cout << "\n=== Show base and showpos ===" << endl;
    cout << showbase << showpos << hex << val << " (with base and + sign)" << endl;
    cout << noshowbase << noshowpos << dec;

    // Uppercase Output
    cout << "\n=== Uppercase Hex and Scientific ===" << endl;
    cout << uppercase << hex << val << endl;
    cout << scientific << 1234.56789 << endl;
    cout << nouppercase << dec; // Reset

    // Reset flags
    cout << "\n=== Resetting Flags ===" << endl;
    cout << resetiosflags(ios::showpos | ios::hex | ios::uppercase);
    cout << "Back to default: " << val << endl;

    // String Output
    cout << "\n=== String Output ===" << endl;
    string name = "C++ Formatting";
    cout << "Message: " << name << endl;

    // Character Output
    char letter = 'A';
    cout << "Character: " << letter << endl;

    // Table-style Output
    cout << "\n=== Table Format Example ===" << endl;
    cout << left << setw(12) << "Name"
         << setw(6) << "Age"
         << setw(10) << "Score" << endl;

    cout << setw(12) << "Alice"
         << setw(6) << 22
         << setw(10) << 89.5 << endl;

    cout << setw(12) << "Bob"
         << setw(6) << 30
         << setw(10) << 92.75 << endl;

    cout << setw(12) << "Charlie"
         << setw(6) << 25
         << setw(10) << 88.25 << endl;

    return 0;
}
