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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // main intuition:
        // when p and q fall opposite side of a node, that node is their LCA

        // both p and q smaller than current node (LCA in left subtree)
        if (p->val < root->val && q->val < root->val) 
            return lowestCommonAncestor(root->left, p, q);
        
        // both p and q larger than current node (LCA in right subtree)
        if (p->val > root->val && q->val > root->val) 
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }

};
