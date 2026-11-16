# In-Memory LRU Key-Value Store

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A lightweight, fast in-memory Key-Value storage engine written in modern C++ (C++17) featuring an **LRU (Least Recently Used)** cache eviction policy.

## Features

- **$O(1)$ Time Complexity** for `get`, `set`, and `remove` operations.
- **Automatic LRU Eviction:** Automatically removes the least recently accessed items when the maximum capacity is reached.
- **Zero External Dependencies:** Built purely using the C++ Standard Library (`std::unordered_map`, `std::list`, `std::optional`).
- **Clean & Safe API:** Uses `std::optional` for safe key lookups without throwing exceptions on cache misses.

## How It Works

To achieve constant-time performance across all core operations, the store combines two standard data structures:
1. **`std::list`**: A doubly linked list that maintains items in order of usage (most recently used at the front, least recently used at the back). Moving an element to the front on access takes $O(1)$ time via `std::list::splice`.
2. **`std::unordered_map`**: A hash map storing keys mapped directly to list iterators, enabling $O(1)$ lookups and deletions.

## Getting Started

### Prerequisites
- A C++ compiler with **C++17** support (GCC 7+, Clang 5+, or MSVC 2017+).

### Build and Run

Clone the repository and compile the project using `g++`:

```bash
git clone https://github.com/boikko/Key-Value.git
cd Key-Value
g++ -std=c++17 -O2 Key-Value/main.cpp Key-Value/store.cpp -o kv_store
./kv_store
```

## Usage Example

```cpp
#include <iostream>
#include "store.hpp"

int main() {
    // Initialize store with a capacity of 3 items
    KeyValueStore kv(3);

    kv.set("node_1", "temperature_22C");
    kv.set("node_2", "humidity_45%");
    kv.set("node_3", "status_active");

    // Accessing "node_1" marks it as recently used
    if (auto val = kv.get("node_1")) {
        std::cout << "node_1: " << *val << std::endl;
    }

    // Exceeding capacity evicts "node_2" (the least recently used item)
    kv.set("node_4", "battery_98%");

    if (!kv.get("node_2")) {
        std::cout << "node_2 was evicted." << std::endl;
    }

    return 0;
}
```

## API Reference

| Method | Complexity | Description |
| :--- | :---: | :--- |
| `KeyValueStore(size_t max_capacity = 100)` | $O(1)$ | Initializes the store with a specified maximum capacity. |
| `void set(const std::string& key, const std::string& value)` | $O(1)$ | Inserts a new key-value pair or updates an existing key, marking it as recently used. |
| `std::optional<std::string> get(const std::string& key)` | $O(1)$ | Retrieves the value for a key (or `std::nullopt` if missing) and updates its LRU priority. |
| `bool remove(const std::string& key)` | $O(1)$ | Removes a key from the store. Returns `true` if the key existed. |
| `void clear()` | $O(N)$ | Removes all items from the store. |
| `size_t size() const` | $O(1)$ | Returns the current number of stored items. |
| `size_t capacity() const` | $O(1)$ | Returns the maximum capacity of the store. |

## Project Structure

```text
├── Key-Value/
│   ├── Key-Value.vcxproj
│   ├── Key-Value.vcxproj.filters
│   ├── main.cpp       # Usage example and basic LRU eviction test
│   ├── store.cpp      # Implementation of LRU logic and storage methods
│   └── store.hpp      # KeyValueStore class declaration
├── Key-Value.sln      # Visual Studio solution file
└── README.md
```
##👨‍💻 Author
Developed by Oleh Boiko as a practical embedded systems C++ pet project.
