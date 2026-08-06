/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> old2new;
        return dfs(node, old2new);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& old2new) {
        if (!node) return nullptr;
        if (old2new.count(node)) return old2new[node]; // cut cycle

        Node* copy = new Node(node->val);
        old2new[node] = copy;

        copy->neighbors.reserve(node->neighbors.size());
        for (Node* n: node->neighbors)
            copy->neighbors.push_back(dfs(n, old2new));
        
        return copy;
    }
};
