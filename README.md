# SkipListKV - wri

## Overview

This project implements a **Skiplist** as the underlying data structure. Skiplist is a randomized data structure that allows fast search, insertion, and deletion operations, which is often used as an alternative to balanced trees.

## Description

The **Skiplist** works by introducing a probabilistic element to the data structure, which helps achieve logarithmic time complexity for search operations. Interestingly, when looking at a visual representation of a skiplist, you might notice that it somewhat resembles a Binary Search Tree (BST) when viewed from a certain angle. You can dive deeper into the concept of skiplist from the [OI Wiki](https://oi-wiki.org/data-structures/skiplist/) for more detailed understanding.

## Key Features

- **Skiplist as the core data structure**: A modern approach to data storage and retrieval.
- **C++ Template Programming**: Implemented using C++ templates to allow for generic data types and custom comparison functions.
- **Supports STL-like Usage**: Designed similarly to C++ Standard Template Library (STL) containers.
- **Iterator Traversal**: Utilizes iterators for traversing elements in the skiplist.
- **Internal Class Structure**: The data structure is designed using nested classes. For example, `set<int>::iterator` is an inner class of the `set<int>` container.

## Installation & Usage

### Prerequisites

- **C++17 or later**
- **A C++ compiler** (GCC, Clang, MSVC, etc.)

### Build Instructions

```sh
# Clone the repository
git clone https://github.com/yourusername/SkipListKV.git
cd SkipListKV

# Compile (example using g++)
g++ -std=c++17 -o skiplist main.cpp
```

### Example Usage

```cpp
#include "SkipList.h"
#include <iostream>

int main() {
    //use lambda
    auto cmp = [](const string& a, const string& b) {return a.length() < b.length(); };
    skip_list < string, int, decltype(cmp)> list(cmp);
    list.insert("aab", 1321);
    list.insert("hello", 54342);
    list.insert("world", 544);
    for (auto it = list.begin(); it != list.end(); it++) {
        cout << it->key << " " << it->value << endl;
    }
}
```
![Screenshot 2025-03-16 114033](https://github.com/user-attachments/assets/c057d026-bf1d-4364-b5d2-93e15bed08fb)

## API Overview

```cpp
void insert(const KeyType& key, const ValueType& value); // Insert a key-value pair
void erase(const KeyType& key); // Remove a key
ValueType find(const KeyType& key); // Retrieve value by key
bool contains(const KeyType& key); // Check if key exists
```

## Custom Comparators

You can use **lambda expressions** or **functors** to customize key comparison:

```cpp
SkipList<int, std::string, std::greater<int>> kv_store; // Custom comparator (descending order)
```

## License

This project is licensed under the **MIT License**.

## Contributing

Feel free to submit issues and pull requests to improve the project!


