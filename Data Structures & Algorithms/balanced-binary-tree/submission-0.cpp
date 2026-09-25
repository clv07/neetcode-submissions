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
    bool isBalanced(TreeNode* root) {
       return height(root) != -1;
    }

private:
    int height(TreeNode* node) {
        if (!node) return 0;
        int left = height(node->left);      // left node is unbalanced
        if (left == -1) return -1;
        int right = height(node->right);    // right node is unbalanced
        if (right == -1) return -1;
        if (abs(left-right) > 1) return -1; // this node is unbalanced
        return 1 + max(left, right);
    }
};
