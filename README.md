# 🚀 Embedded Key-Value Store in C++

A lightweight, high-performance in-memory key-value storage engine written in modern C++ (C++17), specifically engineered with embedded systems constraints in mind (fixed memory capacity and strict LRU eviction policy).

## 📌 Features
- **$O(1)$ Time Complexity:** Instant lookup, insertion, and deletion operations utilizing a hybrid structure of `std::unordered_map` and a doubly-linked list (`std::list`).
- **LRU Eviction Policy:** Automatically discards the least recently used records when capacity limits are met, preventing memory overflows in resource-constrained environments.
- **Modern C++ Architecture:** Built leveraging RAII principles, smart memory management, and `std::optional`.
- **Zero Heavy Dependencies:** Written purely using standard STL components, making it highly portable and lightweight.

---

## 🛠️ Project Structure
```text
Key-Value/
├── include/
│   └── store.hpp      # Core storage engine interface and LRU logic
├── src/
│   ├── store.cpp      # Implementation of storage methods
│   └── main.cpp       # CLI demonstration and test suite
└── CMakeLists.txt     # CMake build configuration
```

##⚙️ How to Build & Run
You can build this project using any standard CMake-compatible toolchain:

# Clone the repository
```bash
git clone [https://github.com/boikko/Key-Value.git](https://github.com/boikko/Key-Value.git)
cd Key-Value

# Create a build directory
mkdir build && cd build

# Configure and compile
cmake ..
cmake --build .

# Run the executable
./Debug/Key-Value.exe   # (or Linux equivalent)
```

##👨‍💻 Author
Developed by Oleh Boiko as a practical embedded systems C++ pet project.
