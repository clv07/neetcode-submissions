class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> hashmap;

public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        auto it = hashmap.find(key);
        if (it == hashmap.end()) return -1; // key not exist in cache
        auto node = it->second; // list iterator
        cache.splice(cache.begin(), cache, node); // move node to the front of cache
        return node->second; // return node value
    }   
    
    void put(int key, int value) {
        auto it = hashmap.find(key);
        if (it != hashmap.end()) { // key is in cache
            auto node = it->second;
            cache.splice(cache.begin(), cache, node); // move node to the front of cache
            node->second = value; // update value
            return;
        }
        if ((int)cache.size() == cap) { // cache is full, evict the LRU node
            hashmap.erase(cache.back().first); // remove key from hashmap
            cache.pop_back();   // remove key from cache
        } 
        cache.emplace_front(key, value);
        hashmap[key] = cache.begin();
    }
};
