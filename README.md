# SkipListKV - wri

## Overview

**SkipListKV** is a lightweight key-value storage system built using **Skip List** as the underlying data structure. It supports essential operations like **insertion, deletion, and lookup**, making it a simple yet efficient data store.

## Features

- **Skip List as the Core Structure**: Provides efficient insert, delete, and search operations.
- **C++ Template-Based Implementation**: Supports various key-value types using modern C++ templates.
- **STL-like Interface**: Designed for ease of use, similar to STL containers.
- **Custom Comparison Functions**: Supports user-defined comparison functions using **lambda expressions** or **functors**.
- **Iterator Support**: Allows easy traversal through stored elements.

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


