// Author: Abdo_joker

// ---------- Include Required Libraries ----------
#include <iostream>     // Standard input/output
#include <string>       // std::string
#include <vector>       // std::vector
#include <sstream>      // std::stringstream for splitting and formatting strings
#include <regex>        // std::regex for pattern matching and replacements
#include <locale>       // For character classification
#include <cmath>        // Math functions (sin, cos, exp, log, etc.)
#include <algorithm>    // std::sort, std::transform, std::max, std::min
#include <numeric>      // std::accumulate, etc.
#include <iterator>     // std::istream_iterator, etc.

using namespace std;

int main() {
    // ---------- STRING FUNCTIONS ----------
    string str = "hello";

    // String formatting using stringstream
    stringstream ss;
    ss << "Hello, " << "world" << "!";
    string formattedString = ss.str();

    // Convert string to vector of characters
    vector<char> chars(str.begin(), str.end());

    // Create indented string with 4 leading spaces
    string indentedString = string(4, ' ') + str;

    // Join vector of words into a single comma-separated string
    vector<string> words = {"hello", "world", "java"};
    string joinedString;
    for (size_t i = 0; i < words.size(); ++i)
        joinedString += words[i] + (i < words.size() - 1 ? ", " : "");

    // Find last index of a character
    size_t lastIndexOf = str.find_last_of('l');

    // Get string length
    size_t len = str.length();

    // Regex match (exact match with pattern "h.llo")
    bool matches = regex_match("hello", regex("h.llo"));

    // Offset index example
    int offsetIndex = 0 + 2;

    // Case-sensitive comparison of substrings
    bool regionMatches = str.compare(0, 5, "HELLO", 0, 5) == 0;

    // Convert to uppercase and compare again
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    bool regionMatchesIgnoreCase = str.compare(0, 5, "HELLO", 0, 5) == 0;

    // Replace first match only
    string replaced = regex_replace("hello", regex("h"), "H", regex_constants::format_first_only);

    // Replace all occurrences of a character
    string replacedAll = regex_replace("hello", regex("l"), "L");

    // Split string by delimiter using stringstream
    string input = "hello,world,java";
    stringstream ss2(input);
    string token;
    vector<string> tokens;
    while (getline(ss2, token, ',')) tokens.push_back(token);

    // Check if string starts with substring
    bool startsWith = str.rfind("HE", 0) == 0;

    // Substring examples
    string substr1 = str.substr(2);     // From index 2 to end
    string substr2 = str.substr(2, 2);  // From index 2, length 2

    // Convert string to character array
    vector<char> chArr(str.begin(), str.end());

    // Convert string to uppercase
    string upper = "hello";
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    // Convert string to lowercase
    string lower = "HELLO";
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    // String with escape characters
    string translatedString = "hello\nworld";

    // ---------- MATH FUNCTIONS ----------
    double x = 0.5;

    double acos_val = acos(x);         // Arc cosine
    double asin_val = asin(x);         // Arc sine
    double atan_val = atan(1);         // Arc tangent
    double cbrt_val = cbrt(27);        // Cube root
    double ceil_val = ceil(3.7);       // Round up
    double cos_val = cos(M_PI / 2);    // Cosine
    double cosh_val = cosh(1);         // Hyperbolic cosine
    double exp_val = exp(1);           // e^1
    double expm1_val = expm1(1);       // e^x - 1
    double floor_val = floor(3.7);     // Round down

    int floorDiv = floor(17 / 5.0);    // Floor division
    int floorMod = 17 % 5;             // Modulo

    int exponent = log2(1024);         // Log base 2
    double hypot_val = hypot(3, 4);    // √(3² + 4²)
    double ieee_rem = remainder(17, 5); // IEEE remainder
    double log_val = log(M_E);         // Natural log
    double log10_val = log10(100);     // Log base 10
    double log1p_val = log1p(1);       // log(1 + x)

    double max_val = max(5, 10);       // Max
    double min_val = min(5, 10);       // Min

    double next_after = nextafter(1.0, 2.0);           // Next float toward 2.0
    double next_down = nextafter(1.0, -INFINITY);      // Next float down
    double next_up = nextafter(1.0, INFINITY);         // Next float up

    // ---------- ARRAY FUNCTIONS ----------
    vector<int> arr = {5, 2, 8, 3, 1};
    vector<int> list = {1, 2, 3};

    // Sort array
    sort(arr.begin(), arr.end());

    // Binary search for element (requires sorted array)
    bool found = binary_search(arr.begin(), arr.end(), 3);

    // Resize vector and fill new elements with 0
    vector<int> copyArr = {1, 2, 3};
    copyArr.resize(5, 0); // Now: {1, 2, 3, 0, 0}

    // Copy subrange of a vector
    vector<int> rangeCopy(arr.begin() + 1, arr.begin() + 3); // [2, 3]

    // Compare equality of vectors
    bool equals = (copyArr == vector<int>{1, 2, 3, 0, 0});

    // Fill vector with a constant value
    vector<int> filled(5, 5); // {5, 5, 5, 5, 5}

    // 2D matrix print
    vector<vector<int>> mat = {{1,2}, {3,4}};
    for (auto row : mat) {
        cout << "[ ";
        for (auto val : row) cout << val << " ";
        cout << "] ";
    }
    cout << endl;

    // Final sorted array print
    sort(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
