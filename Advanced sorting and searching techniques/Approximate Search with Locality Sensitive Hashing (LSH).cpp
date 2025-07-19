#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int hammingDistance(string a, string b) {
    int dist = 0;
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) dist++;
    return dist;
}

int main() {
    vector<string> dataset = {"10101", "11100", "10010", "01101"};
    string query = "10100";
    int threshold = 2;

    for (auto& s : dataset)
        if (hammingDistance(query, s) <= threshold)
            cout << "Approx match: " << s << endl;
}
