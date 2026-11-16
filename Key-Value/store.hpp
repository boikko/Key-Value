#pragma once

#include <string>
#include <unordered_map>
#include <list>
#include <optional>
#include <cstddef>

class KeyValueStore {
public:
    explicit KeyValueStore(size_t max_capacity = 100);

    void set(const std::string& key, const std::string& value);
    std::optional<std::string> get(const std::string& key);
    bool remove(const std::string& key);
    void clear();

    size_t size() const;
    size_t capacity() const;

private:
    size_t max_capacity_;

    // Список для збереження порядку використання (LRU)
    using ListIt = std::list<std::pair<std::string, std::string>>::iterator;
    std::list<std::pair<std::string, std::string>> items_list_;

    // Хеш-таблиця для швидкого доступу O(1) за ітератором списку
    std::unordered_map<std::string, ListIt> index_map_;
};