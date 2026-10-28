class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    int m, n;
    vector<vector<bool>> visited;
    vector<string> res;

    vector<vector<int>> dirs = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build trie dictionary
        TrieNode* root = new TrieNode();
        for (const string &w: words) {
            TrieNode* node = root;
            for (const char &c: w) {
                int i = c - 'a';
                if (!node->children[i])
                    node->children[i] = new TrieNode();
                node = node->children[i];
            }
            node->word = w; 
        }

        // DFS
        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);
        
        return res;

    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) return;
        
        TrieNode* next = node->children[board[r][c] - 'a'];
        if(!next) return;

        if (!next->word.empty()) {
            res.push_back(next->word);
            next->word = "";
        }

        visited[r][c] = true;
        for (vector<int>& d: dirs) {
            dfs(board, r + d[0], c + d[1], next);     
        }
        visited[r][c] = false;
    }

};
