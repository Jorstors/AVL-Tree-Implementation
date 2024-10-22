
# C++ AVL Tree Implementation  

This project is a custom implementation of an **AVL Tree** in C++, showcasing my proficiency in data structures, algorithm design, and memory management. The project is well-documented, with comments explaining the code to demonstrate expertise in balancing binary search trees, recursive algorithms, and writing clean, readable code.

---

## Project Structure  

The repository consists of the following files:  

- **main.cpp:** Contains the main driver function to test the AVL Tree implementation and validate various functionalities.  
- **AVLTree.hpp:** Header file containing the AVL Tree class definition, method declarations, and node structure.  
- **main.exe:** Compiled executable for testing the AVL Tree implementation on Windows platforms.  
---

## Features  

- **AVL Tree Class:** Implements a self-balancing binary search tree (BST) to ensure logarithmic time complexities for insertion, deletion, and lookups.  
- **Balancing Mechanism:** Automatically balances the tree with rotations (left, right, left-right, and right-left) to maintain height balance after insertions and deletions.  
- **Functional Methods:** Includes core AVL Tree operations such as:
  - `insert()`: Inserts a value while maintaining balance.
  - `remove()`: Deletes a value and re-balances the tree if necessary.
  - `search()`: Searches for a specific value within the tree.
  - `count()`: Returns the element count within the tree
  - `print()`: Traverses and prints the tree in sorted order.  
- **Extensive Comments:** The code includes comments that explain the purpose and functionality of each part, making it easier to understand and contribute to.  

---

## Technologies  

- **C++:** The core language used for implementing the AVL Tree and managing dynamic memory.  
- **Windows Executable:** The project includes a compiled executable (`main.exe`) to run the program on Windows platforms.  

---

## Setup and Compilation  

### Prerequisites  

- C++ compiler (e.g., GCC, Clang, or MSVC)  
- Windows (for the provided executable) or any platform with a C++ compiler  

### To Compile the Source Code:  

Clone the repository:  

```bash
git clone https://github.com/Jorstors/AVL-Tree-Implementation.git
```

Navigate to the project directory:  

```bash
cd AVL-Tree-Implementation
```

Compile the `main.cpp` file along with `AVLTree.hpp`:  

```bash
g++ main.cpp -o main
```

Run the executable (Linux/macOS):  

```bash
./main
```

Or, on Windows:  

```bash
main.exe
```

---

## Usage  

The program tests the AVL Tree by performing various operations, including insertions, deletions, and searches. The results are printed to the console to demonstrate the correctness and performance of the tree.

### Example Run  

The provided `main.cpp` file tests the following operations:  

- Inserting nodes and verifying the balance property.  
- Deleting nodes and ensuring the tree remains balanced.  
- Searching for specific values in the tree.  
- Printing the tree in in-order traversal to verify sorting.  
- Printing the height of the tree to validate balance.  

You can modify `main.cpp` to add custom tests as needed.  

---

## Comments and Documentation  

Each function is thoroughly documented with comments explaining the logic, balancing strategy, and how each method contributes to the overall functionality of the AVL Tree. This serves as a valuable learning tool for understanding self-balancing trees and recursive algorithms.

---

## Key Learning Areas  

- **Algorithm Design:** Gained experience with recursive algorithms for insertion, deletion, and rebalancing operations.  
- **Data Structures:** Deepened understanding of tree-based structures, including binary search trees and AVL balancing techniques.  
- **Memory Management:** Managed heap memory efficiently for dynamic node creation and deletion.  
- **Functionality:** Implemented core methods that ensure logarithmic time complexity for tree operations.  
- **Test Cases:** Developed and executed tests to validate the correctness and robustness of AVL Tree operations, ensuring reliable performance across a variety of scenarios.  
---

### License

This project is licensed under the ISC License:

Copyright (c) 2024, Justus Jones

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

---

Made by [Justus Jones](https://github.com/Jorstors)
