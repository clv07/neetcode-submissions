class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        // 1. initialized map for all characters
        for (const string &w: words) {
            for (char c: w) {
                adj[c];
                inDegree[c] = 0;
            }
        }

        // 2. build the edges
        int m = words.size();
        for (int i = 1; i < m; i++) {
            const string& str1 = words[i-1];
            const string& str2 = words[i];
            int size = min(str1.size(), str2.size());
            int j = 0;

            // find the first character difference in adjacent words
            while(j < size && str1[j] == str2[j]) j++;

            if (j < size) {
                char a = str1[j], b = str2[j];
                if (!adj[a].count(b)) { // add a new edge if have not
                    adj[a].insert(b);
                    inDegree[b]++;
                }
            }
            else if (str1.size() > str2.size())
                return "";
        }

        // 3. Kahn's algorithm to build result
        queue<char> q;
        for (auto& [c, deg]: inDegree) 
            if(deg == 0) q.push(c);
        
        string res;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;

            for (char next: adj[c]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }

        if (res.size() < inDegree.size()) return ""; // any character never placed is stuck in a cycle
        return res;
    }
};
