
// Author: Abdo_joker
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <locale>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    // ---------- String Functions ----------
    string str = "hello";

    stringstream ss;
    ss << "Hello, " << "world" << "!";
    string formattedString = ss.str();

    vector<char> chars(str.begin(), str.end());

    string indentedString = string(4, ' ') + str;

    vector<string> words = {"hello", "world", "java"};
    string joinedString;
    for (size_t i = 0; i < words.size(); ++i)
        joinedString += words[i] + (i < words.size() - 1 ? ", " : "");

    size_t lastIndexOf = str.find_last_of('l');
    size_t len = str.length();

    bool matches = regex_match("hello", regex("h.llo"));

    int offsetIndex = 0 + 2;

    bool regionMatches = str.compare(0, 5, "HELLO", 0, 5) == 0;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    bool regionMatchesIgnoreCase = str.compare(0, 5, "HELLO", 0, 5) == 0;

    string replaced = regex_replace("hello", regex("h"), "H", regex_constants::format_first_only);
    string replacedAll = regex_replace("hello", regex("l"), "L");

    string input = "hello,world,java";
    stringstream ss2(input);
    string token;
    vector<string> tokens;
    while (getline(ss2, token, ',')) tokens.push_back(token);

    bool startsWith = str.rfind("HE", 0) == 0;
    string substr1 = str.substr(2);
    string substr2 = str.substr(2, 2);
    vector<char> chArr(str.begin(), str.end());

    string upper = "hello";
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

    string lower = "HELLO";
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    string translatedString = "hello\nworld";

    // ---------- Math Functions ----------
    double x = 0.5;

    double acos_val = acos(x);
    double asin_val = asin(x);
    double atan_val = atan(1);
    double cbrt_val = cbrt(27);
    double ceil_val = ceil(3.7);
    double cos_val = cos(M_PI / 2);
    double cosh_val = cosh(1);
    double exp_val = exp(1);
    double expm1_val = expm1(1);
    double floor_val = floor(3.7);

    int floorDiv = floor(17 / 5.0);
    int floorMod = 17 % 5;

    int exponent = log2(1024);
    double hypot_val = hypot(3, 4);
    double ieee_rem = remainder(17, 5);
    double log_val = log(M_E);
    double log10_val = log10(100);
    double log1p_val = log1p(1);

    double max_val = max(5, 10);
    double min_val = min(5, 10);

    double next_after = nextafter(1.0, 2.0);
    double next_down = nextafter(1.0, -INFINITY);
    double next_up = nextafter(1.0, INFINITY);

    // ---------- Array Functions ----------
    vector<int> arr = {5, 2, 8, 3, 1};
    vector<int> list = {1, 2, 3};

    sort(arr.begin(), arr.end());
    bool found = binary_search(arr.begin(), arr.end(), 3);

    vector<int> copyArr = {1, 2, 3};
    copyArr.resize(5, 0);

    vector<int> rangeCopy(arr.begin() + 1, arr.begin() + 3);
    bool equals = (copyArr == vector<int>{1, 2, 3, 0, 0});

    vector<int> filled(5, 5);

    vector<vector<int>> mat = {{1,2}, {3,4}};
    for (auto row : mat) {
        cout << "[ ";
        for (auto val : row) cout << val << " ";
        cout << "]";
    }

    sort(arr.begin(), arr.end());
    for (int x : arr) cout << x << " ";

    return 0;
}
