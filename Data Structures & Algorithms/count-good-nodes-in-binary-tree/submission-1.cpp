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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }

private:
    void dfs(TreeNode* node, int maxVal, int& count) {
        if (!node) return;
        if (node->val >= maxVal) count++; // good nodes
        maxVal = max(maxVal, node->val);
        dfs(node->left, maxVal, count);
        dfs(node->right, maxVal, count);
    }
};
