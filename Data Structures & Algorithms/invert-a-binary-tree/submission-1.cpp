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
    TreeNode* invertDFS(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode* left = invertDFS(root->left);
        TreeNode* right = invertDFS(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode* inverted = invertDFS(root);
        return inverted;
    }
};
