// Author: Abdo

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <map>
#include <iterator>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    // ----------- STRING OPERATIONS -----------
    string name = "world";
    string formatted = "Hello, " + name + "!";
    cout << "Formatted string: " << formatted << endl;

    string s = "hello";
    string sub = s.substr(0, 5);
    cout << "Substring: " << sub << endl;

    s.append(8 - s.size(), ' ');
    cout << "Right-padded: '" << s << "'" << endl;

    // Join vector of words using ostringstream
    vector<string> words = {"hello", "world", "java"};
    ostringstream joined;
    for (size_t i = 0; i < words.size(); ++i) {
        joined << words[i];
        if (i != words.size() - 1) joined << ", ";
    }
    string joined_str = joined.str();
    cout << "Joined string: " << joined_str << endl;

    int last_index = s.rfind("l");
    cout << "Last index of 'l': " << last_index << endl;

    int len = s.length();
    cout << "Length of string: " << len << endl;

    string replaced = s;
    replace(replaced.begin(), replaced.end(), 'h', 'H');
    cout << "Replaced 'h' with 'H': " << replaced << endl;

    // Split using lambda
    auto split = [](const string &str, char delim) -> vector<string> {
        vector<string> result;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) result.push_back(token);
        return result;
    };
    vector<string> splitted = split("a,b,c", ',');
    cout << "Splitted: ";
    for (const string &x : splitted) cout << x << " ";
    cout << endl;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "Uppercase: " << s << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << "Lowercase: " << s << endl;

    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;

    // ----------- MATH FUNCTIONS -----------
    cout << "acos(0.5): " << acos(0.5) << endl;
    cout << "asin(0.5): " << asin(0.5) << endl;
    cout << "atan(1): " << atan(1) << endl;
    cout << "Cube root of 27: " << pow(27, 1.0/3) << endl;
    cout << "ceil(3.7): " << ceil(3.7) << endl;
    cout << "cosh(1): " << cosh(1) << endl;
    cout << "exp(1): " << exp(1) << endl;
    cout << "expm1(1): " << expm1(1) << endl;
    cout << "floor(3.7): " << floor(3.7) << endl;
    cout << "trunc(3.7): " << trunc(3.7) << endl;
    cout << "fmod(17, 5): " << fmod(17, 5) << endl;
    cout << "log(e): " << log(M_E) << endl;
    cout << "log10(100): " << log10(100) << endl;
    cout << "log1p(1): " << log1p(1) << endl;
    cout << "max(5, 10): " << max(5, 10) << endl;
    cout << "min(5, 10): " << min(5, 10) << endl;
    cout << "nextafter(1, 2): " << nextafter(1, 2) << endl;
    cout << "copysign(1, -1): " << copysign(1, -1) << endl;

    // ----------- ARRAY & LIST OPERATIONS -----------
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> new_arr(arr.begin() + 1, arr.begin() + 3);
    cout << "Sliced array (1 to 3): ";
    for (int x : new_arr) cout << x << " ";
    cout << endl;

    bool equal = arr == vector<int>{1, 2, 3, 4, 5};
    cout << "Arrays equal: " << equal << endl;

    vector<int> filled(5, 5);
    cout << "Filled with 5s: ";
    for (int x : filled) cout << x << " ";
    cout << endl;

    sort(arr.begin(), arr.end());
    cout << "Sorted ascending: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sort(arr.rbegin(), arr.rend());
    cout << "Sorted descending: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // ----------- STRING UTILITIES -----------
    string txt = "     banana     ";
    txt.erase(txt.find_last_not_of(" ") + 1); // Trim right
    txt.erase(0, txt.find_first_not_of(" ")); // Trim left
    cout << "Trimmed: '" << txt << "'" << endl;

    string txt2 = "....banana....";
    txt2.erase(0, txt2.find_first_not_of(".,grt"));
    txt2.erase(txt2.find_last_not_of(".,grt") + 1);
    cout << "Trimmed (.,grt): '" << txt2 << "'" << endl;

    bool starts = txt.rfind("banana", 0) == 0;
    bool ends = txt.substr(txt.size() - 1) == "a";
    cout << "Starts with 'banana': " << starts << endl;
    cout << "Ends with 'a': " << ends << endl;

    int found = txt.find("banana");
    int not_found = txt.find("q");
    cout << "Found index of 'banana': " << found << endl;
    cout << "Not found index: " << not_found << endl;

    bool islower = all_of(txt.begin(), txt.end(), ::islower);
    bool isupper = all_of(txt.begin(), txt.end(), ::isupper);
    bool isalpha = all_of(txt.begin(), txt.end(), ::isalpha);
    cout << "All lowercase: " << islower << endl;
    cout << "All uppercase: " << isupper << endl;
    cout << "All alphabetic: " << isalpha << endl;

    // ----------- SET OPERATIONS -----------
    set<string> fruits = {"apple", "banana"};
    fruits.insert("orange");
    cout << "Fruits set: ";
    for (const auto &f : fruits) cout << f << " ";
    cout << endl;

    set<string> x = {"apple"};
    set<string> y = {"google"};

    bool disjoint = true;
    for (const auto& el : x)
        if (y.count(el)) { disjoint = false; break; }
    cout << "Disjoint sets: " << disjoint << endl;

    set<string> union_set;
    set_union(x.begin(), x.end(), y.begin(), y.end(), inserter(union_set, union_set.begin()));
    cout << "Union of sets: ";
    for (const auto &item : union_set) cout << item << " ";
    cout << endl;

    // ----------- BINARY, OCTAL, HEX REPRESENTATION -----------
    bitset<8> bin(36);
    cout << "Binary of 36: " << bin << endl;
    cout << "Octal of 12: " << oct << 12 << endl;
    cout << "Hex of 255: " << hex << 255 << endl;

    // ----------- CHAR TO INT (ord) -----------
    int val = int('h');
    cout << "ASCII of 'h': " << val << endl;

    // ----------- SUM FUNCTION -----------
    vector<int> a_vec = {1, 2, 3, 4, 5};
    int total = accumulate(a_vec.begin(), a_vec.end(), 0);
    cout << "Sum of vector: " << total << endl;

    return 0;
}
