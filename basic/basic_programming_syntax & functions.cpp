// Standard Libraries
#include <iostream>     // For standard input and output (cin, cout)
#include <string>       // For using the 'string' class and related operations

using namespace std;

// 1. Function with no parameters and no return value
void sayHello() {
    cout << "Hello from function with no parameters and no return value." << endl;
}

// 2. Function with parameters and no return value
void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
}

// 3. Function with no parameters but with return value
int getNumber() {
    int n;
    cout << "Enter a number to return: ";
    cin >> n;
    return n;
}

// 4. Function with parameters and return value
int add(int a, int b) {
    return a + b;
}

// 5. Complex: Check if a number is prime and return sum of numbers up to n
// Time Complexity: O(n)
int isPrimeAndSum(int n) {
    if (n <= 1) return -1;

    // Check for primality (O(√n))
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return -1;  // Not prime
    }

    // Sum all numbers from 1 to n
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// 6. Complex: Reverse an array in-place
// Time Complexity: O(n)
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// 7. Complex: Recursive factorial
// Time Complexity: O(n), Space Complexity: O(n) due to recursion
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 8. Complex: Check if a word is a palindrome
// Time Complexity: O(n)
bool isPalindrome(string word) {
    int left = 0, right = word.length() - 1;
    while (left < right) {
        if (word[left] != word[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// 9. Complex: Print multiplication table up to n
// Time Complexity: O(n^2)
void generateMultiplicationTable(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

// 10. Complex: Find the maximum element in an array
// Time Complexity: O(n)
int findMaxInArray(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// ========== MAIN FUNCTION ==========
int main() {
    int num;

    // Input a number
    cout << "Enter a number: ";
    cin >> num;

    // 1. If-else statement
    if (num > 0) {
        cout << "The number is positive." << endl;
    } else if (num < 0) {
        cout << "The number is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }

    // 2. For loop: print 1 to 5
    cout << "\nFor loop: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // 3. While loop: countdown from input number
    cout << "\nWhile loop: ";
    int count = num;
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;

    // 4. Do-while loop: print 0 to 4
    cout << "\nDo-While loop: ";
    int x = 0;
    do {
        cout << x << " ";
        x++;
    } while (x < 5);
    cout << endl;

    // 5. Switch statement: day selection
    int day;
    cout << "\nEnter a number (1-3) for day: ";
    cin >> day;
    switch (day) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        default: cout << "Other day" << endl;
    }

    // ========== FUNCTION DEMONSTRATIONS ==========

    cout << "\nFunction Demonstrations:\n";

    // Function 1: No parameter, no return
    sayHello();

    // Function 2: Parameter, no return
    greet("Abdo");

    // Function 3: No parameter, with return
    int value = getNumber();
    cout << "Returned number: " << value << endl;

    // Function 4: Parameters and return
    int result = add(10, 20);
    cout << "Sum of 10 and 20 is: " << result << endl;

    // Function 5: Prime check and sum
    int complexResult = isPrimeAndSum(num);
    if (complexResult != -1) {
        cout << "The number is prime. Sum = " << complexResult << endl;
    } else {
        cout << "The number is not prime." << endl;
    }

    // Function 6: Reverse array
    int myArray[5] = {1, 2, 3, 4, 5};
    reverseArray(myArray, 5);
    cout << "Reversed array: ";
    for (int i = 0; i < 5; i++) cout << myArray[i] << " ";
    cout << endl;

    // Function 7: Factorial
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    // Function 8: Palindrome checker
    string word;
    cout << "Enter a word to check palindrome: ";
    cin >> word;
    if (isPalindrome(word))
        cout << word << " is a palindrome." << endl;
    else
        cout << word << " is NOT a palindrome." << endl;

    // Function 9: Multiplication table
    cout << "\nMultiplication Table up to " << num << ":\n";
    generateMultiplicationTable(num);

    // Function 10: Find max in array
    int arr[6] = {12, 43, 21, 89, 3, 55};
    int maxVal = findMaxInArray(arr, 6);
    cout << "Maximum in array: " << maxVal << endl;

    return 0;
}
