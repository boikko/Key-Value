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

    // List to maintain the order of usage for LRU eviction policy
    using ListIt = std::list<std::pair<std::string, std::string>>::iterator;
    std::list<std::pair<std::string, std::string>> items_list_;

    // Hash map for O(1) fast lookup pointing to list iterators
    std::unordered_map<std::string, ListIt> index_map_;
};
