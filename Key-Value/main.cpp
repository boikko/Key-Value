#include <iostream>
#include "store.hpp"

int main() {
    // Створюємо сховище максимум на 3 елементи для перевірки LRU
    KeyValueStore kv(3);

    std::cout << "=== Test KV Store ===" << std::endl;

    kv.set("node_1", "temperature_22C");
    kv.set("node_2", "humidity_45%");
    kv.set("node_3", "status_active");

    // Перевіримо отримання існуючого ключа
    auto val = kv.get("node_1");
    if (val) {
        std::cout << "Get node_1: " << *val << std::endl;
    }

    // Додаємо 4-й елемент. Оскільки ліміт 3, "node_2" має бути витіснений (як найдавніше використаний)
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