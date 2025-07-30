#include <iostream>     // For standard I/O
#include <iomanip>      // For setprecision, fixed, scientific
using namespace std;

int main() {
    // 1. Floating-point variables with different precision levels
    float       f = 1.0f / 3.0f;         // float ~ 7 digits precision
    double      d = 1.0 / 3.0;           // double ~ 15-16 digits precision
    long double ld = 1.0L / 3.0L;        // long double ~ 18-21+ digits (platform-dependent)

    // 2. Display default precision
    cout << "Default precision:\n";
    cout << "float:       " << f << endl;
    cout << "double:      " << d << endl;
    cout << "long double: " << ld << endl << endl;

    // 3. Set precision using setprecision (affects total number of significant digits by default)
    cout << "Using setprecision(10):\n";
    cout << "float:       " << setprecision(10) << f << endl;
    cout << "double:      " << setprecision(10) << d << endl;
    cout << "long double: " << setprecision(10) << ld << endl << endl;

    // 4. Fixed format with precision (number of digits after decimal point)
    cout << fixed;
    cout << "Using fixed and setprecision(10):\n";
    cout << "float:       " << setprecision(10) << f << endl;
    cout << "double:      " << setprecision(10) << d << endl;
    cout << "long double: " << setprecision(10) << ld << endl << endl;

    // 5. Scientific format with precision
    cout << scientific;
    cout << "Using scientific and setprecision(10):\n";
    cout << "float:       " << setprecision(10) << f << endl;
    cout << "double:      " << setprecision(10) << d << endl;
    cout << "long double: " << setprecision(10) << ld << endl << endl;

    // 6. Arithmetic precision impact
    float sumF = 0.0f;
    double sumD = 0.0;
    long double sumLD = 0.0L;

    for (int i = 0; i < 1000000; ++i) {
        sumF  += 1.0f / 1000000.0f;
        sumD  += 1.0 / 1000000.0;
        sumLD += 1.0L / 1000000.0L;
    }

    cout << fixed;
    cout << "Summing 1.0 / 1,000,000 one million times:\n";
    cout << "float sum:       " << setprecision(10) << sumF << endl;
    cout << "double sum:      " << setprecision(10) << sumD << endl;
    cout << "long double sum: " << setprecision(10) << sumLD << endl;

    return 0;
}
