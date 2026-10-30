/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }

private:
    void dfs(TreeNode* node, string& s) {
        if (!node) {
            s += "N,"; // denote nullptr
            return;
        }
        s += to_string(node->val) + ','; // denote node
        
        // pre-order
        dfs(node->left, s);
        dfs(node->right, s);
    }

    TreeNode* build(const string& data, int& i) {
        string token;
        while (data[i] != ',') token += data[i++];
        i++; // skip the comma

        // deserialize
        if (token == "N") return nullptr; 
        TreeNode* node = new TreeNode(stoi(token));

        // pre-order
        node->left = build(data, i);
        node->right = build(data, i);

        return node;
    }
};
