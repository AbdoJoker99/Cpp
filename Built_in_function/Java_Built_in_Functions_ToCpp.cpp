// Author: Abdo_joker

// ---------- Include Required Libraries ----------
#include <iostream>     // Input/output stream
#include <string>       // For std::string
#include <vector>       // For std::vector
#include <sstream>      // For stringstream (string formatting/splitting)
#include <regex>        // For regular expressions
#include <locale>       // For character classification
#include <cmath>        // For math functions
#include <algorithm>    // For sort, transform, min, max
#include <numeric>      // For accumulate, etc.
#include <iterator>     // For iterators

using namespace std;

int main() {
    // ---------- STRING FUNCTIONS ----------
    string str = "hello";
    cout << "Original string: " << str << endl;

    // Format string using stringstream
    stringstream ss;
    ss << "Hello, " << "world" << "!";
    string formattedString = ss.str();
    cout << "Formatted string: " << formattedString << endl;

    // Convert string to vector of characters
    vector<char> chars(str.begin(), str.end());
    cout << "Vector of characters: ";
    for (char c : chars) cout << c << " ";
    cout << endl;

    // Add 4 leading spaces (indentation)
    string indentedString = string(4, ' ') + str;
    cout << "Indented string: " << indentedString << endl;

    // Join vector of strings with comma
    vector<string> words = {"hello", "world", "java"};
    string joinedString;
    for (size_t i = 0; i < words.size(); ++i)
        joinedString += words[i] + (i < words.size() - 1 ? ", " : "");
    cout << "Joined string: " << joinedString << endl;

    // Get last index of character 'l'
    size_t lastIndexOf = str.find_last_of('l');
    cout << "Last index of 'l': " << lastIndexOf << endl;

    // Get length of string
    size_t len = str.length();
    cout << "Length of string: " << len << endl;

    // Check regex match: pattern "h.llo"
    bool matches = regex_match("hello", regex("h.llo"));
    cout << "Regex match for 'h.llo': " << matches << endl;

    // Offset index demonstration
    int offsetIndex = 0 + 2;
    cout << "Offset index example: " << offsetIndex << endl;

    // Compare substrings (case-sensitive)
    bool regionMatches = str.compare(0, 5, "HELLO", 0, 5) == 0;
    cout << "Case-sensitive comparison: " << regionMatches << endl;

    // Convert to uppercase then compare again
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase string: " << str << endl;
    bool regionMatchesIgnoreCase = str.compare(0, 5, "HELLO", 0, 5) == 0;
    cout << "Case-insensitive comparison: " << regionMatchesIgnoreCase << endl;

    // Replace only first occurrence of 'h'
    string replaced = regex_replace("hello", regex("h"), "H", regex_constants::format_first_only);
    cout << "Replaced first 'h': " << replaced << endl;

    // Replace all occurrences of 'l'
    string replacedAll = regex_replace("hello", regex("l"), "L");
    cout << "Replaced all 'l': " << replacedAll << endl;

    // Split string by delimiter (',')
    string input = "hello,world,java";
    stringstream ss2(input);
    string token;
    vector<string> tokens;
    while (getline(ss2, token, ',')) tokens.push_back(token);
    cout << "Tokens: ";
    for (const auto& t : tokens) cout << t << " ";
    cout << endl;

    // Check if string starts with "HE"
    bool startsWith = str.rfind("HE", 0) == 0;
    cout << "Starts with 'HE': " << startsWith << endl;

    // Substring from index 2 to end
    string substr1 = str.substr(2);
    cout << "Substring from index 2: " << substr1 << endl;

    // Substring from index 2, length 2
    string substr2 = str.substr(2, 2);
    cout << "Substring from index 2, length 2: " << substr2 << endl;

    // Convert string to character array (again)
    vector<char> chArr(str.begin(), str.end());
    cout << "Character array from string: ";
    for (char c : chArr) cout << c << " ";
    cout << endl;

    // Convert to uppercase using transform
    string upper = "hello";
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << "Upper: " << upper << endl;

    // Convert to lowercase
    string lower = "HELLO";
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Lower: " << lower << endl;

    // Example string with newline escape
    string translatedString = "hello\nworld";
    cout << "Translated string with escape: " << translatedString << endl;

    // ---------- MATH FUNCTIONS ----------
    double x = 0.5;

    // Trigonometric and logarithmic functions
    cout << "acos(0.5): " << acos(x) << endl;
    cout << "asin(0.5): " << asin(x) << endl;
    cout << "atan(1): " << atan(1) << endl;
    cout << "cbrt(27): " << cbrt(27) << endl;
    cout << "ceil(3.7): " << ceil(3.7) << endl;
    cout << "cos(pi/2): " << cos(M_PI / 2) << endl;
    cout << "cosh(1): " << cosh(1) << endl;
    cout << "exp(1): " << exp(1) << endl;
    cout << "expm1(1): " << expm1(1) << endl;
    cout << "floor(3.7): " << floor(3.7) << endl;

    // Floor division and modulo
    int floorDiv = floor(17 / 5.0);
    int floorMod = 17 % 5;
    cout << "Floor division: " << floorDiv << endl;
    cout << "Floor mod: " << floorMod << endl;

    // Logarithmic functions
    cout << "log2(1024): " << log2(1024) << endl;
    cout << "hypot(3, 4): " << hypot(3, 4) << endl;
    cout << "remainder(17, 5): " << remainder(17, 5) << endl;
    cout << "log(e): " << log(M_E) << endl;
    cout << "log10(100): " << log10(100) << endl;
    cout << "log1p(1): " << log1p(1) << endl;

    // Min, max, next floating-point values
    cout << "max(5, 10): " << max(5, 10) << endl;
    cout << "min(5, 10): " << min(5, 10) << endl;
    cout << "nextafter(1.0, 2.0): " << nextafter(1.0, 2.0) << endl;
    cout << "nextafter(1.0, -inf): " << nextafter(1.0, -INFINITY) << endl;
    cout << "nextafter(1.0, +inf): " << nextafter(1.0, INFINITY) << endl;

    // ---------- ARRAY FUNCTIONS ----------
    vector<int> arr = {5, 2, 8, 3, 1};
    vector<int> list = {1, 2, 3};

    // Sort array
    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    // Binary search (works on sorted array)
    bool found = binary_search(arr.begin(), arr.end(), 3);
    cout << "Found 3 in array: " << found << endl;

    // Resize vector and fill with 0
    vector<int> copyArr = {1, 2, 3};
    copyArr.resize(5, 0);
    cout << "Resized array: ";
    for (int i : copyArr) cout << i << " ";
    cout << endl;

    // Copy subrange of array
    vector<int> rangeCopy(arr.begin() + 1, arr.begin() + 3);
    cout << "Range copy [1:3]: ";
    for (int i : rangeCopy) cout << i << " ";
    cout << endl;

    // Compare vectors for equality
    bool equals = (copyArr == vector<int>{1, 2, 3, 0, 0});
    cout << "Copy array equals target: " << equals << endl;

    // Fill vector with constant value
    vector<int> filled(5, 5);
    cout << "Filled vector with 5s: ";
    for (int i : filled) cout << i << " ";
    cout << endl;

    // 2D matrix print
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    cout << "2D Matrix:" << endl;
    for (auto row : mat) {
        cout << "[ ";
        for (auto val : row) cout << val << " ";
        cout << "]" << endl;
    }

    // Final sorted array print
    cout << "Final sorted array: ";
    sort(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
