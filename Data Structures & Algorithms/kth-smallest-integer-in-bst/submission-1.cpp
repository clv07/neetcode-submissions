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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0, count = 0;
        inorder(root, k, res, count);
        return res;
    }

    void inorder(TreeNode* node, int& k, int& res, int& count) {
        if (!node) return;
        inorder(node->left, k, res, count);
        count++;
        if (count == k) {
            res = node->val;
            return;
        }
        if (count > k) return;
        inorder(node->right, k, res, count);
    }
};
