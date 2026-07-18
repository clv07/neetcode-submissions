class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool endOfWord = false;
};


class PrefixTree {
    TrieNode* root;

    TrieNode* find(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) return nullptr;
            curr = curr->children[i];
        }
        return curr;
    }
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr)
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = find(word);
        return node != nullptr && node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};
