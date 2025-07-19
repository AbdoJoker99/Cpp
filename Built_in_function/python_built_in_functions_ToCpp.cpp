// Python to C++ Code Equivalents

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

    string s = "hello";
    string sub = s.substr(0, 5);

    s.append(8 - s.size(), ' '); // Padding

    vector<string> words = {"hello", "world", "java"};
    ostringstream joined;
    for (size_t i = 0; i < words.size(); ++i) {
        joined << words[i];
        if (i != words.size() - 1) joined << ", ";
    }
    string joined_str = joined.str();

    int last_index = s.rfind("l");
    int len = s.length();

    string replaced = s;
    replace(replaced.begin(), replaced.end(), 'h', 'H');

    auto split = [](const string &str, char delim) -> vector<string> {
        vector<string> result;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) result.push_back(token);
        return result;
    };
    vector<string> splitted = split("a,b,c", ',');

    transform(s.begin(), s.end(), s.begin(), ::toupper); // To Upper
    transform(s.begin(), s.end(), s.begin(), ::tolower); // To Lower

    reverse(s.begin(), s.end());

    // ----------- MATH FUNCTIONS -----------
    double a = acos(0.5);
    double b = asin(0.5);
    double c = atan(1);
    double d = pow(27, 1.0/3);
    double e = ceil(3.7);
    double f = cosh(1);
    double g = exp(1);
    double h = expm1(1);
    double i = floor(3.7);
    double j = trunc(3.7);
    double k = fmod(17, 5);
    double l = log(M_E);
    double m = log10(100);
    double n = log1p(1);
    double max_val = max(5, 10);
    double min_val = min(5, 10);
    double next = nextafter(1, 2);
    double signed_val = copysign(1, -1);

    // ----------- ARRAY & LIST OPERATIONS -----------
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> new_arr(arr.begin() + 1, arr.begin() + 3);
    bool equal = arr == vector<int>{1, 2, 3, 4, 5};
    vector<int> filled(5, 5);
    sort(arr.begin(), arr.end());
    sort(arr.rbegin(), arr.rend());

    // ----------- STRING UTILITIES -----------
    string txt = "     banana     ";
    txt.erase(txt.find_last_not_of(" ") + 1);
    txt.erase(0, txt.find_first_not_of(" "));

    string txt2 = "....banana....";
    txt2.erase(0, txt2.find_first_not_of(".,grt"));
    txt2.erase(txt2.find_last_not_of(".,grt") + 1);

    bool starts = txt.rfind("banana", 0) == 0;
    bool ends = txt.substr(txt.size() - 1) == "a";

    int found = txt.find("banana");
    int not_found = txt.find("q");

    bool islower = all_of(txt.begin(), txt.end(), ::islower);
    bool isupper = all_of(txt.begin(), txt.end(), ::isupper);
    bool isalpha = all_of(txt.begin(), txt.end(), ::isalpha);

    // ----------- SET OPERATIONS -----------
    set<string> fruits = {"apple", "banana"};
    fruits.insert("orange");

    set<string> x = {"apple"};
    set<string> y = {"google"};
    bool disjoint = true;
    for (const auto& el : x)
        if (y.count(el)) { disjoint = false; break; }

    set<string> union_set;
    set_union(x.begin(), x.end(), y.begin(), y.end(), inserter(union_set, union_set.begin()));

    // ----------- BINARY, OCTAL, HEX -----------
    bitset<8> bin(36);
    cout << oct << 12 << endl;
    cout << hex << 255 << endl;

    // ----------- CHAR/ORD -----------
    int val = int('h');

    // ----------- SUM -----------
    vector<int> a_vec = {1, 2, 3, 4, 5};
    int total = accumulate(a_vec.begin(), a_vec.end(), 0);

    return 0;
}
