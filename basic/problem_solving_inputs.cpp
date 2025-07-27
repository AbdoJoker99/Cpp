// Author: abdo
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    // ============ 1. Multiple Test Cases with Strings ============
    // Example input:
    // 3
    // apple
    // banana
    // orange
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
    }

    // ============ 2. Pairs of Integers ============
    // Example input:
    // 2
    // 5 6
    // 7 8
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
    }

    // ============ 3. Array of Integers ============
    // Example input:
    // 4
    // 1 2 3 4
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // ============ 4. Frequency Count of Characters ============
    // Example input:
    // hello world
    int freq[26] = {0};
    string s;
    cin.ignore(); // consume newline
    getline(cin, s);
    for (char c : s) {
        if (c >= 'a' && c <= 'z')
            freq[c - 'a']++;
    }

    // ============ 5. Read Line After Integer ============
    // Example input:
    // 1
    // Icosahedron
    cin >> n;
    cin.ignore();
    string polyhedronType;
    getline(cin, polyhedronType);

    // ============ 6. Another Array Input ============
    // Example input:
    // 3
    // 10 20 30
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    // ============ 7. Read Array and Then Two Integers ============
    // Example input:
    // 5
    // 1 2 3 4
    // 2 5
    cin >> n;
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> d[i];
    }
    int a1, b1;
    cin >> a1 >> b1;

    // ============ 8. Matrix Input and Find '1' ============
    // Example: (5x5 matrix, only one element is 1)
    // 0 0 0 0 0
    // 0 0 0 1 0
    // 0 0 0 0 0
    // 0 0 0 0 0
    // 0 0 0 0 0
    int matrix[5][5];
    int rowIdx = 0, colIdx = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                rowIdx = i;
                colIdx = j;
            }
        }
    }

    // ============ 9. Read Integers and a Line ============
    // Example:
    // 4
    // this is test
    int s1[4];
    for (int i = 0; i < 4; i++) {
        cin >> s1[i];
    }
    cin.ignore();
    getline(cin, s);

    // ============ 10. Unique Characters in a String ============
    // Input: abcab
    string username;
    cin >> username;
    set<char> distinctChars(username.begin(), username.end());

    // ============ 11. Grid Input (2D Characters) ============
    // Example input:
    // 3 4
    // ....
    // .S..
    // ....
    int m;
    cin >> n >> m;
    set<int> row, col;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    // ============ 12. Long Integer ============
    // Example: 1000000000000
    long long largeNum;
    cin >> largeNum;

    // ============ 13. Read Then Trim Line ============
    // Example:
    //  Hello, world!
    getline(cin, s); // read string
    // s = trim(s); // if trim function is available

    // ============ 14. String with Size ============
    // Example:
    // 2
    // 5
    // apple
    // 6
    // banana
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        cin.ignore();
        string str;
        getline(cin, str);
    }

    // ============ 15. Single Character ============
    // Example: A
    char ch;
    cin.get(ch);
    cin.ignore();

    // ============ 16. Vector of long long ============
    // Example:
    // 3
    // 1000000000 2000000000 3000000000
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        long long element;
        cin >> element;
        arr.push_back(element);
    }

    // ============ 17. Integer and String ============
    // Example:
    // 5 Hello
    cin >> n >> s;

    // ============ 18. Fixed Vector Input ============
    // Example: 1 2 3 4
    vector<int> e;
    vector<int> a4(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a4[i];
    }

    // ============ 19. String to Integer ============
    // Example: "123"
    getline(cin, s);
    n = stoi(s);

    // ============ 20. Sum from String ============
    // Example: 1+2+3
    getline(cin, s);
    stringstream ss(s);
    string token;
    vector<int> numbers;
    while (getline(ss, token, '+')) {
        numbers.push_back(stoi(token));
    }

    // ============ 21. Denomination Array ============
    vector<int> denominations = {100, 20, 10, 5, 1};

    // ============ 22. Parse Integers from Line ============
    // Example:
    // 10 20 30 40
    getline(cin, s);
    istringstream iss(s);
    vector<int> nums;
    int val;
    while (iss >> val) {
        nums.push_back(val);
    }

    // ============ 23. Two Arrays ============
    // Example:
    // 3
    // 1 2 3
    // 4 5 6
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    // ============ 24. Simple String ============
    // Example: codeforces
    string x;
    cin >> x;

    // ============ 25. Chess Coordinates Concept ============
    string list = "abcdefgh";
    string list_1 = "12345678";

    // ============ 26. Length and Convert to int ============
    // Example: "12345"
    string sn;
    cin >> sn;
    int len = sn.length();
    int num = stoi(sn);

    // ============ 27. Three Vectors ============
    // Example:
    // 3 2 1
    // 1 2
    // 3 4 5
    int k;
    cin >> n >> m >> k;
    vector<int> arr2(m), arr3(n);
    for (int i = 0; i < m; ++i) cin >> arr2[i];
    for (int i = 0; i < n; ++i) cin >> arr3[i];

    // ============ 28. Large Zero Vector ============
    vector<int> bigArray(1001, 0); // vector initialized to 0

    return 0;
}
