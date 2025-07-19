#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) count[num]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; ++i)
        while (count[i]--) arr[idx++] = i;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr, 8);
    for (int num : arr) cout << num << " ";
}
