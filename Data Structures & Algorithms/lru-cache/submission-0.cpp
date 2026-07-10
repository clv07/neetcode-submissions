class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    // helper functions to move node to the front of LRU cache if accessed
    void remove(Node* node) {
        // get previous and next node of node to be removed
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;  // update previous point to next node
        next->prev = prev;  // update next node point to previous
    }

    void insert(Node* node) {
        // get the node before right
        Node* prev = right->prev;
        
        // point previous and new node to each other
        prev->next = node;
        node->prev = prev;

        // point new node and right to each other
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();

        // create new pointers
        left = new Node(0, 0);
        right = new Node(0, 0);

        // point them to each other
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

};
