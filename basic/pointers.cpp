// Author: abdo
#include <iostream>      // For standard input/output
#include <cstring>       // For strcpy in pointer to struct
using namespace std;

// Structure for demonstrating pointers with structs
struct Person {
    char name[50];
    int age;
};

// Class to demonstrate pointer to class
class Box {
public:
    int length;
    Box(int l) : length(l) {}
    void showLength() {
        cout << "Box Length = " << length << endl;
    }
};

// Function using pointer parameter (pass by address)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main function
int main() {
    cout << "===== BASIC POINTERS =====" << endl;
    int x = 10;
    int* ptr = &x; // Pointer initialization
    cout << "Value of x = " << x << endl;
    cout << "Address of x = " << &x << endl;
    cout << "Value of ptr = " << ptr << endl;
    cout << "Dereferenced value (*ptr) = " << *ptr << endl;

    cout << "\n===== POINTER ARITHMETIC =====" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;
    cout << "First element: " << *p << endl;
    p++;
    cout << "Second element: " << *p << endl;

    cout << "\n===== POINTERS AND FUNCTIONS =====" << endl;
    int a = 5, b = 9;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(&a, &b); // Passing addresses
    cout << "After swap:  a = " << a << ", b = " << b << endl;

    cout << "\n===== POINTER TO STRUCT =====" << endl;
    Person person;
    Person* pPerson = &person;
    strcpy(pPerson->name, "Alice");
    pPerson->age = 25;
    cout << "Name: " << pPerson->name << ", Age: " << pPerson->age << endl;

    cout << "\n===== POINTER TO POINTER =====" << endl;
    int y = 100;
    int* py = &y;
    int** ppy = &py;
    cout << "Value of y: " << **ppy << endl;

    cout << "\n===== DYNAMIC MEMORY ALLOCATION =====" << endl;
    int* dynArray = new int[3]; // Allocate array of 3 ints
    dynArray[0] = 1;
    dynArray[1] = 2;
    dynArray[2] = 3;
    for (int i = 0; i < 3; ++i)
        cout << "dynArray[" << i << "] = " << dynArray[i] << endl;
    delete[] dynArray; // Free memory

    cout << "\n===== POINTER TO CLASS =====" << endl;
    Box* boxPtr = new Box(15);
    boxPtr->showLength();
    delete boxPtr;

    cout << "\n===== VOID POINTER =====" << endl;
    void* vptr;
    int val = 42;
    vptr = &val;
    cout << "Void pointer pointing to int: " << *(int*)vptr << endl;

    cout << "\n===== CONST POINTERS =====" << endl;
    int z = 50;
    const int* ptr1 = &z;  // Pointer to const data
    int* const ptr2 = &z;  // Const pointer to data
    cout << "const int* ptr1 = " << *ptr1 << endl;
    cout << "int* const ptr2 = " << *ptr2 << endl;

    cout << "\n===== NULL & DANGLING POINTERS =====" << endl;
    int* nullPtr = nullptr;  // Null pointer
    cout << "Null pointer = " << nullPtr << endl;

    int* danglePtr = new int(99);
    delete danglePtr;
    // Now danglePtr is dangling (points to deallocated memory)
    danglePtr = nullptr; // Safe practice

    return 0;
}
