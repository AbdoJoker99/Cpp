// Binary → Decimal

// Binary → Gray Code

// Octal → Decimal

// Decimal → Binary

// Decimal → Hexadecimal

// Decimal → Octal

// Decimal → Any Base

// Hexadecimal → Decimal

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1; // 2^0
    reverse(binary.begin(), binary.end());
    for (char bit : binary) {
        if (bit == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Binary to Gray Code
string binaryToGray(string binary) {
    string gray = "";
    gray += binary[0]; // first bit is same

    for (int i = 1; i < binary.length(); i++) {
        gray += (binary[i - 1] == binary[i]) ? '0' : '1';
    }
    return gray;
}

// Octal to Decimal
int octalToDecimal(string octal) {
    int decimal = 0, base = 1;
    reverse(octal.begin(), octal.end());
    for (char digit : octal) {
        decimal += (digit - '0') * base;
        base *= 8;
    }
    return decimal;
}

// Decimal to Binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary == "" ? "0" : binary;
}

// Decimal to Hexadecimal
string decimalToHex(int decimal) {
    string hex = "";
    string hexChars = "0123456789ABCDEF";
    while (decimal > 0) {
        hex += hexChars[decimal % 16];
        decimal /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex == "" ? "0" : hex;
}

// Decimal to Octal
string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        octal += to_string(decimal % 8);
        decimal /= 8;
    }
    reverse(octal.begin(), octal.end());
    return octal == "" ? "0" : octal;
}

// Decimal to Any Base (2 to 36)
string decimalToAnyBase(int decimal, int base) {
    if (base < 2 || base > 36) return "Base out of range!";
    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    while (decimal > 0) {
        result += chars[decimal % base];
        decimal /= base;
    }
    reverse(result.begin(), result.end());
    return result == "" ? "0" : result;
}

// Hexadecimal to Decimal
int hexToDecimal(string hex) {
    int decimal = 0;
    int base = 1; // 16^0
    reverse(hex.begin(), hex.end());
    for (char c : hex) {
        if (isdigit(c)) {
            decimal += (c - '0') * base;
        } else {
            decimal += (toupper(c) - 'A' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}

// Main Menu
int main() {
    int choice;
    do {
        cout << "\n----- Number Conversion Menu -----\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Binary to Gray Code\n";
        cout << "3. Octal to Decimal\n";
        cout << "4. Decimal to Binary\n";
        cout << "5. Decimal to Hexadecimal\n";
        cout << "6. Decimal to Octal\n";
        cout << "7. Decimal to Any Base\n";
        cout << "8. Hexadecimal to Decimal\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        string input;
        int dec, base;

        switch (choice) {
        case 1:
            cout << "Enter binary number: ";
            cin >> input;
            cout << "Decimal: " << binaryToDecimal(input) << endl;
            break;
        case 2:
            cout << "Enter binary number: ";
            cin >> input;
            cout << "Gray Code: " << binaryToGray(input) << endl;
            break;
        case 3:
            cout << "Enter octal number: ";
            cin >> input;
            cout << "Decimal: " << octalToDecimal(input) << endl;
            break;
        case 4:
            cout << "Enter decimal number: ";
            cin >> dec;
            cout << "Binary: " << decimalToBinary(dec) << endl;
            break;
        case 5:
            cout << "Enter decimal number: ";
            cin >> dec;
            cout << "Hexadecimal: " << decimalToHex(dec) << endl;
            break;
        case 6:
            cout << "Enter decimal number: ";
            cin >> dec;
            cout << "Octal: " << decimalToOctal(dec) << endl;
            break;
        case 7:
            cout << "Enter decimal number: ";
            cin >> dec;
            cout << "Enter target base (2-36): ";
            cin >> base;
            cout << "Converted: " << decimalToAnyBase(dec, base) << endl;
            break;
        case 8:
            cout << "Enter hexadecimal number: ";
            cin >> input;
            cout << "Decimal: " << hexToDecimal(input) << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
