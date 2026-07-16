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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i=0; i < size - 1; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            TreeNode* target = q.front();
            q.pop();
            res.push_back(target->val);
            if (target->left) q.push(target->left);
            if (target->right) q.push(target->right);
        }
        return res;
    }
};
