#include "store.hpp"

KeyValueStore::KeyValueStore(size_t max_capacity) : max_capacity_(max_capacity) {}

void KeyValueStore::set(const std::string& key, const std::string& value) {
    // If key already exists, update its value and move to the front (most recent)
    auto it = index_map_.find(key);
    if (it != index_map_.end()) {
        it->second->second = value;
        items_list_.splice(items_list_.begin(), items_list_, it->second);
        return;
    }

    // If capacity is reached, evict the least recently used item (from the back)
    if (items_list_.size() >= max_capacity_) {
        auto& last_item = items_list_.back();
        index_map_.erase(last_item.first);
        items_list_.pop_back();
    }

    // Insert new item at the front of the list
    items_list_.emplace_front(key, value);
    index_map_[key] = items_list_.begin();
}

std::optional<std::string> KeyValueStore::get(const std::string& key) {
    auto it = index_map_.find(key);
    if (it == index_map_.end()) {
        return std::nullopt; // Key not found
    }

    // Update LRU priority: move accessed item to the front
    items_list_.splice(items_list_.begin(), items_list_, it->second);
    return it->second->second;
}

bool KeyValueStore::remove(const std::string& key) {
    auto it = index_map_.find(key);
    if (it == index_map_.end()) {
        return false;
    }

    items_list_.erase(it->second);
    index_map_.erase(it);
    return true;
}

void KeyValueStore::clear() {
    items_list_.clear();
    index_map_.clear();
}

size_t KeyValueStore::size() const {
    return items_list_.size();
}

size_t KeyValueStore::capacity() const {
    return max_capacity_;
}
