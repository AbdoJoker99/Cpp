/*
 * C++ program to swap two numbers without using a temporary variable
 */
#include<iostream>
using namespace std;
class pro
{
public:
     /* Function for swapping the values */
     void swap(int &a, int &b)
    {
         b = a + b;
         a = b - a;
         b = b - a;
    }
};
int main()
{
    int a, b;
    pro s1;
    cout << "Enter two numbers to be swapped : ";
    cin >> a >> b;
    cout<<"Values before swap :\n";
    cout<<"a = "<<a;
    cout<<endl;
    cout<<"b = "<<b;
    s1.swap(a, b);
    cout<<endl;
    cout << "The two numbers after swapping become :" << endl;
    cout << "Value of a : " << a << endl;
    cout << "Value of b : " << b << endl;
}