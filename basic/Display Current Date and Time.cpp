/*
 * C++ Program to Print Current Date and Time
 */

#include <iostream>     // For standard I/O operations (cout)
#include <ctime>        // For time functions like time(), localtime()
#include <iomanip>      // For output formatting (setw, setfill)

using namespace std;

// Arrays holding string representations for months and weekdays
string month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

string day[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

int main() {
    time_t timer;               // Variable to hold system time in seconds
    tm* timeStruct;             // Pointer to structure holding date and time
    const int BASE_YEAR = 1900; // tm_year is years since 1900

    // Get current time in seconds since Epoch
    time(&timer);

    // Convert to local time
    timeStruct = localtime(&timer);

    // Display current date using arrays for weekday and month names
    cout << "Current date: " 
         << day[timeStruct->tm_wday] << " "
         << month[timeStruct->tm_mon] << " "
         << timeStruct->tm_mday << " "
         << (timeStruct->tm_year + BASE_YEAR) << endl;

    // Display current time in HH:MM:SS format
    cout << "Current time: " 
         << setw(2) << setfill('0') << timeStruct->tm_hour << " : "
         << setw(2) << setfill('0') << timeStruct->tm_min  << " : "
         << setw(2) << setfill('0') << timeStruct->tm_sec  << endl;

    return 0;
}
