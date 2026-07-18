class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
    bool dfs(const string& word, int i, TrieNode* node) {
        if (i == word.size()) return node->endOfWord;

        char c = word[i];
        if (c == '.') {
            for (TrieNode* child: node->children) {
                if (child && dfs(word, i+1, child)) 
                    return true;
            }
            return false;
        }
        else {
            TrieNode* child = node->children[c-'a'];
            return child && dfs(word, i+1, child);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            int i = c - 'a';
            if (!curr->children[i])
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
