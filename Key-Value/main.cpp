#include <iostream>
#include "store.hpp"

int main() {
    //create a storage with a maximum capacity of 3 elements to test LRU.
    KeyValueStore kv(3);

    std::cout << "=== Test KV Store ===" << std::endl;

    kv.set("node_1", "temperature_22C");
    kv.set("node_2", "humidity_45%");
    kv.set("node_3", "status_active");

    //verify the retrieval of an existing key.
    auto val = kv.get("node_1");
    if (val) {
        std::cout << "Get node_1: " << *val << std::endl;
    }

    //Adding the 4th element. Since the limit is 3, "node_2" must be evicted (as the least recently used).
    std::cout << "\nAdding node_4 (exceeding capacity)..." << std::endl;
    kv.set("node_4", "battery_98%");

    if (kv.get("node_2")) {
        std::cout << "node_2 exists" << std::endl;
    }
    else {
        std::cout << "node_2 successfully evicted (LRU works!)" << std::endl;
    }

    if (kv.get("node_4")) {
        std::cout << "Get node_4: " << *kv.get("node_4") << std::endl;
    }

    return 0;
}
