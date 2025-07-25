#include <iostream>
using namespace std;

/*
 * Program to convert hours into minutes and seconds.
 *
 * The user inputs hours as a floating-point number.
 * The program converts hours to minutes by multiplying by 60,
 * then converts minutes to seconds by multiplying by 60 again.
 */

int main() {
    float hrs, min, sec = 0;

    cout << "Enter hours : ";
    cin >> hrs;

    // Convert hours to minutes
    min = hrs * 60;

    // Convert minutes to seconds
    sec = min * 60;

    cout << "\n" << hrs << " hours = " << min << " minutes = " << sec << " seconds";

    return 0;
}
