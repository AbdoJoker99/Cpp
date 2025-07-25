// Author: Abdo

#include <iostream>     // Standard I/O (cin, cout)
#include <string>       // std::string operations
#include <vector>       // std::vector (dynamic arrays)
#include <algorithm>    // Algorithms like sort, transform, reverse
#include <numeric>      // accumulate (like Python's sum)
#include <cmath>        // Math functions (sqrt, pow, exp, etc.)
#include <set>          // std::set for unique collection
#include <map>          // std::map for key-value pairs
#include <iterator>     // std::inserter and iterators
#include <sstream>      // stringstream, ostringstream for formatting/splitting
#include <bitset>       // Binary representation

using namespace std;

int main() {
    // ----------- STRING OPERATIONS -----------
    string name = "world";
    string formatted = "Hello, " + name + "!"; // Equivalent to f"Hello, {name}"

    string s = "hello";
    string sub = s.substr(0, 5); // Slice

    s.append(8 - s.size(), ' '); // Right pad with spaces to length 8

    // Join equivalent using ostringstream
    vector<string> words = {"hello", "world", "java"};
    ostringstream joined;
    for (size_t i = 0; i < words.size(); ++i) {
        joined << words[i];
        if (i != words.size() - 1) joined << ", ";
    }
    string joined_str = joined.str();

    int last_index = s.rfind("l"); // str.rfind
    int len = s.length();

    // Replace 'h' with 'H'
    string replaced = s;
    replace(replaced.begin(), replaced.end(), 'h', 'H');

    // Lambda for split() like Python
    auto split = [](const string &str, char delim) -> vector<string> {
        vector<string> result;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) result.push_back(token);
        return result;
    };
    vector<string> splitted = split("a,b,c", ',');

    // Convert to upper and lower
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Reverse string
    reverse(s.begin(), s.end());

    // ----------- MATH FUNCTIONS -----------
    double a = acos(0.5);              // arccos
    double b = asin(0.5);              // arcsin
    double c = atan(1);                // arctan
    double d = pow(27, 1.0/3);         // Cube root
    double e = ceil(3.7);              // ceil
    double f = cosh(1);                // cosh
    double g = exp(1);                 // e^x
    double h = expm1(1);               // e^x - 1
    double i = floor(3.7);             // floor
    double j = trunc(3.7);             // truncate
    double k = fmod(17, 5);            // remainder
    double l = log(M_E);               // ln(e)
    double m = log10(100);             // log base 10
    double n = log1p(1);               // log(1 + x)
    double max_val = max(5, 10);       // max()
    double min_val = min(5, 10);       // min()
    double next = nextafter(1, 2);     // next representable value toward 2
    double signed_val = copysign(1, -1); // copy sign from -1 to 1

    // ----------- ARRAY & LIST OPERATIONS -----------
    vector<int> arr = {1, 2, 3, 4, 5};

    // Slice equivalent
    vector<int> new_arr(arr.begin() + 1, arr.begin() + 3);

    // Check equality
    bool equal = arr == vector<int>{1, 2, 3, 4, 5};

    // Fill vector with a constant
    vector<int> filled(5, 5); // [5, 5, 5, 5, 5]

    // Sort ascending and descending
    sort(arr.begin(), arr.end());     // Ascending
    sort(arr.rbegin(), arr.rend());   // Descending

    // ----------- STRING UTILITIES -----------
    string txt = "     banana     ";

    // Trim right
    txt.erase(txt.find_last_not_of(" ") + 1);
    // Trim left
    txt.erase(0, txt.find_first_not_of(" "));

    string txt2 = "....banana....";
    txt2.erase(0, txt2.find_first_not_of(".,grt"));
    txt2.erase(txt2.find_last_not_of(".,grt") + 1);

    // Startswith and Endswith
    bool starts = txt.rfind("banana", 0) == 0;  // Like str.startswith()
    bool ends = txt.substr(txt.size() - 1) == "a"; // Like str.endswith("a")

    // Find and not found
    int found = txt.find("banana");
    int not_found = txt.find("q");

    // islower, isupper, isalpha
    bool islower = all_of(txt.begin(), txt.end(), ::islower);
    bool isupper = all_of(txt.begin(), txt.end(), ::isupper);
    bool isalpha = all_of(txt.begin(), txt.end(), ::isalpha);

    // ----------- SET OPERATIONS -----------
    set<string> fruits = {"apple", "banana"};
    fruits.insert("orange");

    set<string> x = {"apple"};
    set<string> y = {"google"};

    // Disjoint check
    bool disjoint = true;
    for (const auto& el : x)
        if (y.count(el)) { disjoint = false; break; }

    // Set union
    set<string> union_set;
    set_union(x.begin(), x.end(), y.begin(), y.end(), inserter(union_set, union_set.begin()));

    // ----------- BINARY, OCTAL, HEX REPRESENTATION -----------
    bitset<8> bin(36); // Print 36 in binary
    cout << bin << endl;

    cout << oct << 12 << endl;   // Octal
    cout << hex << 255 << endl; // Hexadecimal

    // ----------- CHAR TO INT (ord) -----------
    int val = int('h'); // ord('h')

    // ----------- SUM FUNCTION -----------
    vector<int> a_vec = {1, 2, 3, 4, 5};
    int total = accumulate(a_vec.begin(), a_vec.end(), 0); // Python's sum()

    return 0;
}
