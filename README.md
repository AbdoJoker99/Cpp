# 📘 C++ Data Structures and Algorithms Library

A comprehensive collection of **basic data structures**, **mathematical utilities**, and **sorting/searching algorithms** implemented in C++. Ideal for beginners, students, and interview preparation.

---

## 📚 Contents

### ✅ Data Structures

- [x] Arrays  
- [x] Stack (Array-based & Linked List-based)  
- [x] Queue  
  - Linear Queue  
  - Circular Queue  
  - Double-ended Queue  
- [x] Singly Linked List  
- [x] Doubly Linked List  
- [x] Hash Table (basic implementation)  
- [x] Binary Search Tree (BST)  

### 🔢 Mathematical Programs

- Area & Perimeter of:
  - Triangle
  - Rectangle
  - Square
  - Parallelogram
  - Trapezoid
- Factorial (Iterative & Recursive)
- Fibonacci Sequence
- GCD (Greatest Common Divisor)
- LCM (Least Common Multiple)

### ⚙️ Algorithms

#### Sorting Algorithms

- Quick Sort  
- Merge Sort  
- Insertion Sort  
- Bubble Sort  

#### Searching Algorithms

- Linear Search  
- Binary Search  

### 🧰 Other Features

- Built-in C++ Standard Library Functions (`<algorithm>`, `<cmath>`, `<string>`, etc.)  
- File Handling (read/write to text files)  

---

## 🚀 Getting Started

### 🔧 Requirements

- C++17 or above  
- C++ compiler (e.g. `g++`, `clang++`, `MSVC`)  

### 📥 Installation

Clone the repository:

```bash
git clone https://github.com/AbdoJoker99/Cpp
```

### 🛠️ Installing MSYS2 and GCC (Windows)

1. Download MSYS2 from [https://www.msys2.org](https://www.msys2.org)  
2. Install and open the MSYS2 terminal  
3. Update the package database and core system packages:

    ```bash
    pacman -Syu
    ```

    > 🔁 Restart the terminal when prompted, then continue:

    ```bash
    pacman -Su
    ```

4. **Install GCC and Build Tools:**

    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc
    ```

5. **[Recommended Fix] GPG Key Issue (if package installation fails):**

    If you encounter an error related to invalid or missing GPG keys when installing packages, run:

    ```bash
    pacman -S gnupg
    ```

    Then initialize the keyring with:

    ```bash
    pacman-key --init
    pacman-key --populate msys2
    ```

6. Use the **MSYS2 MinGW UCRT 64-bit** terminal to compile your code:

    ```bash
    g++ -std=c++17 -o program your_code.cpp
    ./program
    ```

---

## 👥 Contributors

Thanks to the following amazing people for contributing:

| Name | GitHub |
|------|--------|
| Abdo | [@AbdoJoker99](https://github.com/AbdoJoker99) |

---

## 🛠️ Tools

### Web Extensions

- [CF Analytics](https://chrome.google.com/webstore/detail/cf-analytics/extension-id) – Codeforces contest data analytics  
- [CF-Predictor](https://chrome.google.com/webstore/detail/cf-predictor/extension-id) – Predict problem difficulty on Codeforces  
- [Carrot](https://chrome.google.com/webstore/detail/carrot/extension-id) – Competitive programming helper  
- [WebChatGPT: ChatGPT with internet access](https://chrome.google.com/webstore/detail/webchatgpt-chatgpt-with-inte/extension-id) – Extend ChatGPT with live web data  

### VS Code Extensions

- [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) – Run code snippets quickly  
- [Competitive Programming Helper (CPH)](https://marketplace.visualstudio.com/items?itemName=competitive-programming-helper.cph) – Manage contests and solutions  

---

## 📚 Resources

- [GeeksforGeeks – DSA](https://www.geeksforgeeks.org/data-structures/)  
- [Sanfoundry – 1000+ C++ Programs](https://www.sanfoundry.com/cpp-programs/)  

---

## 🧪 Practice Platforms

Sharpen your skills on these coding platforms:

- [LeetCode](https://leetcode.com/) – Popular for interviews and competitive prep  
- [Codeforces](https://codeforces.com/) – Competitive programming contests  
- [HackerRank](https://www.hackerrank.com/domains/tutorials/10-days-of-cpp) – C++ and DSA practice tracks  

---

## 📄 License

This project is licensed under the **Apache License**.  
See the [LICENSE](LICENSE) file for more information.

---


