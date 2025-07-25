// Author: abdo

// --- Standard Libraries Used --- //
#include <iostream>           // For input/output stream operations (cin, cout)
#include <vector>             // For using dynamic array (vector)
#include <algorithm>         // For sort() and max()
#include <unordered_map>     // For frequency map to calculate mode
#include <cmath>             // For sqrt() used in standard deviation

using namespace std;

// Function to calculate Mean
// Time Complexity: O(n)
double calculateMean(const vector<int>& data) {
    double sum = 0;
    for (int num : data) sum += num;
    return sum / data.size();
}

// Function to calculate Median
// Time Complexity: O(n log n) due to sorting
double calculateMedian(vector<int> data) {
    sort(data.begin(), data.end()); // Sort the data
    int n = data.size();
    if (n % 2 == 0)
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    else
        return data[n / 2];
}

// Function to calculate Mode
// Time Complexity: O(n) average case using unordered_map
vector<int> calculateMode(const vector<int>& data) {
    unordered_map<int, int> freq; // Stores frequency of each number
    int maxFreq = 0;
    for (int num : data) {
        freq[num]++;
        maxFreq = max(maxFreq, freq[num]);
    }

    vector<int> modes;
    for (auto& pair : freq) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }

    // If all values are unique, return no mode
    if (modes.size() == data.size()) return {};

    return modes;
}

// Function to calculate Variance
// Time Complexity: O(n)
double calculateVariance(const vector<int>& data, double mean) {
    double variance = 0;
    for (int num : data) {
        variance += (num - mean) * (num - mean);
    }
    return variance / data.size(); // For sample variance, use (variance / (n - 1))
}

// Function to calculate Standard Deviation
// Time Complexity: O(1)
double calculateStdDev(double variance) {
    return sqrt(variance); // std::sqrt from <cmath>
}

int main() {
    // Sample data
    vector<int> data = {1, 2, 2, 3, 4, 4, 4, 5, 6};

    cout << "Data: ";
    for (int num : data) cout << num << " ";
    cout << "\n";

    // Calculate statistical values
    double mean = calculateMean(data);
    double median = calculateMedian(data);
    vector<int> mode = calculateMode(data);
    double variance = calculateVariance(data, mean);
    double stdDev = calculateStdDev(variance);

    // Output results
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;

    cout << "Mode: ";
    if (mode.empty())
        cout << "No mode (all elements occur once)." << endl;
    else {
        for (int m : mode) cout << m << " ";
        cout << endl;
    }

    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stdDev << endl;

    return 0;
}
