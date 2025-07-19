#include<iostream>
using namespace std;
int main ()
{
    float hrs, min, sec = 0;
    cout << "Enter hours : ";
    cin >> hrs;
    min = hrs * 60;
    sec = min * 60;
    cout << "\n" << hrs << " hours = " << min << " minutes = " << sec << " seconds";
    return 0;
}