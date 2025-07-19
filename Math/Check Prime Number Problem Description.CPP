/*
 * C++ Program to Check Prime Numbers using Naive Approach
 */
 
#include <iostream>
#include <cmath>
 
int main()
{
    int num;
    std::cout << "Enter the number to be checked: ";
    std::cin >> num;
    if (num <= 1)
    {
        std::cout << "\n" << num << " is not prime";
        return 0;
    }
    bool isPrime = true;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        std::cout << "\n" << num << " is prime.";
    else
        std::cout << "\n" << num << " is not prime.";
    return 0;
}