/*
 * C++ Program to Generate Sequence of Ulam Numbers
 */
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int uterm1 = 1, uterm2 = 2, num = 0;
    vector<int> v;
 
    v.push_back(1);
    num++;
    v.push_back(2);
    num++;
    for (int i = 3; i <= 100; i++)
    {
        int count = 0;
        for (int j = 0; j < num; j++)
        {
             for (int k = j + 1; k < num; k++)
             {
                 if (v[j] + v[k] == i)
               	     count++; 
             }
        }
        if (count == 1){
            v.push_back(i);
            num++;
        }
    }
    cout << "The sequence of ulam numbers is as follows : " << endl;
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << '\t';  
    cout << endl;
}
